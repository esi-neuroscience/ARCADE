classdef State < handle
    
    properties ( SetAccess = public, GetAccess = public )
        name@char % name of this state
        waitEvents = {}; % cell array of names of events to wait for
        waitForAllEvents = false;
        nextStateAfterEvent = {};
        nextStateAfterTimeout@char
        onEntry = {};
        onExit = {};        
        duration = 0;
        maxRepetitions = Inf;
    end
    properties ( GetAccess = public, SetAccess = private)
        runNumber = 0;
    end
    
    properties ( Access = private, Constant = true )
        WAIT_TIMEOUT = uint32(hex2dec('00000102'));
        WAIT_FAILED  = uint32(hex2dec('FFFFFFFF'));
    end
    
    methods ( Access = public )
        function obj = State(name)
            obj.name = name;
        end
        
        function nextState = run(obj)
            if numel(obj.nextStateAfterEvent)~=numel(obj.waitEvents) && ~obj.waitForAllEvents
                error('Mismatch between number of events (%d) and next states (%d)', ...
                    numel(obj.waitEvents), numel(obj.nextStateAfterEvent) );
            end
                        
            obj.runNumber = obj.runNumber+1;
            obj.evalFunctions(obj.onEntry)            
            
            if ~isempty(obj.waitEvents)
                result = MultipleEvents.WaitFor(...
                    obj.waitEvents, ...
                    obj.waitForAllEvents, ...
                    obj.duration);
                assert(result ~= State.WAIT_FAILED, ...
                    'Wait for events failed. Were all events initialized?')
            else
                java.lang.Thread.sleep(obj.duration);
            end
                        
            if obj.runNumber >= obj.maxRepetitions
                nextState = 'final';
            elseif result == State.WAIT_TIMEOUT
                nextState = obj.nextStateAfterTimeout;
            else
                nextState = obj.nextStateAfterEvent{result};
            end
            
            obj.evalFunctions(obj.onExit)
            
        end
    end
    methods        
        function set.waitEvents(obj, names)
            if ischar(names)
                names = {names};
            end
            assert(State.isCellArrayOfChars(names), 'waitEvents must be cell array of event names')
            obj.waitEvents = names;
        end        
        function set.onEntry(obj, funcs)
            if State.isCellArrayOfFuncs(funcs)
                obj.onEntry = funcs;
            else
                error('Entry functions must be a cell array of function handles')
            end
        end
        function set.onExit(obj, funcs)
            if State.isCellArrayOfFuncs(funcs)
                obj.onExit = funcs;
            else
                error('Exit functions must be a cell array of function handles')
            end
        end
        function set.nextStateAfterEvent(obj, stateNames)
            if ischar(stateNames)
                stateNames = {stateNames};
            end
            assert(State.isCellArrayOfChars(stateNames));
            obj.nextStateAfterEvent = stateNames;
        end    
    end
    
    methods ( Static, Hidden=true, Access=private )
        function evalFunctions(fHandles)
            if ~isempty(fHandles)
                for iFunc = numel(fHandles)
                    fHandles{k}();
                end
            end
        end
        function value = isCellArrayOfFuncs(funcs)
            value = false;
            if iscell(funcs)
                value = all(cellfun(@(f) isa(f, 'function_handle'), funcs));
            end
        end
        function value = isCellArrayOfChars(charCellArray)
            value = false;
            if iscell(charCellArray)
                value = all(cellfun(@ischar, charCellArray));
            end
        end
    end
end
