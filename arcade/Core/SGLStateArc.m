classdef (Sealed) SGLStateArc < handle
    % Singleton class for the state machine that holds and runs the states.
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
        end
        
        function stateNames = get.stateNames(obj)
            stateNames = {obj.states.name};
        end
        
        function eventNames = get.eventNames(obj)
            eventNames = unique([obj.states.waitEvents]);
        end
                
        
        function mRunTrial(obj)                                    
            nextState = obj.initialState;
                        
            while ~strcmp(nextState, 'final')                
                currentState = obj.states(strcmp(nextState, obj.stateNames));
                nextState = currentState.run();                
            end                
        
        end
        
        function delete(obj)   
            
        end
    end
   
end




