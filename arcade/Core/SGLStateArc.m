classdef (Sealed) SGLStateArc < handle
    % [SINGELTON] StateArc
    % - handles the movement from one state to another
    % - holds a vector of states,
    %   which, together, represent the possible states that make up a trial
    % - the StateArc is blind to the next state,
    %   as well as all possible state trajectories
    % - StateArc relies on the return value from each state to determine
    %   what the next state is    
      
    
    properties (AbortSet = true)
        states = []; % vector of states
        initialState
    end
    
    properties (Dependent = true, GetAccess = public)
        eventNames
        stateNames
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
        %# constructor
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
            % initialize event listeneres
            if ~isempty(obj.eventNames)
                MultipleEvents.Init(obj.eventNames);
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




