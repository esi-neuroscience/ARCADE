classdef State < handle
    % STATE - Class for experimental states
    %     
    % When run, a State instance waits for specified system events and
    % returns the name of the next state that is associated for the events
    % that occured during or before the wait.
    % 
    % A state can have entry and exit functions, which are run irrespective
    % of the wait outcome. 
    %
    % See also trackeye, SGLStateArc, IPCEvent, function_handle, anondemo
    %     
     
    properties ( SetAccess = public, GetAccess = public )
        name@char % name of this state
        waitEvents = {}; % cell array of event names to wait for
        waitForAllEvents = false; % flag whether to wait for all events
        nextStateAfterEvent = {}; % cell aray of next state names corresponding to events in waitEvents
        nextStateAfterTimeout@char = 'final'; % name of next state after timeout
        onEntry = {}; % cell array of anonymous functions to be executed during state entry
        onExit = {}; % cell array of anonymous functions to be executed during state exit
        duration = 0; % tiemout for wait in ms
        maxRepetitions = Inf; % number of maximal iterations of state
    end
    properties ( GetAccess = public, SetAccess = private)
        runNumber = 0; % number of iterations within current state arc
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
            % Execute entry functions, wait for events/timeout and call
            % exit functions
                        
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
                result = State.WAIT_TIMEOUT;
            end
                        
            if obj.runNumber >= obj.maxRepetitions
                nextState = 'final';
            elseif result == State.WAIT_TIMEOUT
                nextState = obj.nextStateAfterTimeout;
            elseif result >= 1
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
                for iFunc = 1:numel(fHandles)
                    fHandles{iFunc}();
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
