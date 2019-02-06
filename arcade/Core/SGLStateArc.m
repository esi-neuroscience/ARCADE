classdef (Sealed) SGLStateArc < handle
    % SGLStateArc - Singleton class for state machine managing the trial flow
    %
    % Starting from the intitial state tateArc alwasy moves to the state that
    % is returned when a state is run. The StateArc stops when a state returns
    % 'final' as next state.
    % 
    % See also State
    
    properties (AbortSet = false)
        states = []; % vector of states
        initialState % name of initial state
    end
    
    properties (Dependent = true, GetAccess = public)
        eventNames % cell vector of all event names referenced in states
        stateNames % cell vector of all state names 
    end
    
    methods (Static)
        function obj = launch
            persistent objObj
            if isempty(objObj) || ~isvalid(objObj)
                objObj = SGLStateArc;
            end
            obj = objObj;
        end
    end
    
    methods (Access = private)        
        function obj = SGLStateArc
            
        end
    end
    
    methods
        function set.states(obj, states)                  
            stateNames = {states.name};
            referencedStates = unique([[states.nextStateAfterEvent] ...
                {states.nextStateAfterTimeout}]);
            missingStates = ~(ismember(referencedStates, stateNames) | ...
                strcmp(referencedStates, 'final'));
            if any(missingStates)
                fprintf('Not all referenced states are defined. Missing states: ')
                fprintf('%s ', referencedStates{missingStates})
                fprintf('\n')
                error('Incomplete state system')
            end            
            if ~ismember('final', referencedStates) && all(isinf([states.maxRepetitions]))
                error('No end point for state system defined.')
            end
            obj.states = states;   
            if ~isempty(unique([obj.states.waitEvents]))
                MultipleEvents.Init(obj.eventNames);
            end  
        end
        
        function stateNames = get.stateNames(obj)
            if ~isempty(obj.states)
                stateNames = {obj.states.name};
            else
                stateNames = [];
            end
        end
        
        function eventNames = get.eventNames(obj)
            if ~isempty(obj.states)
                eventNames = unique([obj.states.waitEvents]);
            else
                eventNames = [];
            end
        end
                
        
        function mRunTrial(obj)              
            if isempty(obj.states)
                return
            end
            nextState = obj.initialState;                        
            while ~strcmp(nextState, 'final')
                currentState = obj.states(strcmp(nextState, obj.stateNames));
                nextState = currentState.run();                
            end                
        
        end
        
        function delete(obj)   
            MultipleEvents.delete();
        end
    end
   
end




