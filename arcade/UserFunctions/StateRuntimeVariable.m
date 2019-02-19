classdef StateRuntimeVariable < handle
    % STATERUNTIMEVARIABLE - Class for storing data generated at runtime of
    % the ARCADE State machine
    %
    %   runtimeVar = StateRuntimeVariable(intialValue)
    %
    % In MATLAB, assignments (e.g., a = 2) are not possible in anonymous
    % functions such as the onEntry and onExit functions of the State class.
    % To provide a means for storing or retreiving data at runtime of a State
    % this class holds data and provides set_value and get_value functions. 
    % These can then be called during the onEntry and onExit functions.
    %
    % METHODS
    % -------
    %     get_value()  : returns current variable value
    %     set_value(v) : set variable value to v
    %
    % PROPERTIES
    % ----------
    %     value : value of the variable
    %
    %
    % EXAMPLE 1
    % ---------
    % In order to make reward dependent on reaction tim,e a
    % StateRuntimeVariable can be used to store the reaction time and to
    % retreive later when the reward should be delivered.
    %     
    % reactionTime = StateRuntimeVariable(nan);
    % x = State('x'); 
    % x.duration = randi(1000)
    % x.onExit = {@() reactionTime.set_value(x.elapsedTime)};    
    % y = State('y');
    % y.onEntry = {@() reward(200*exp(-reactionTime.get_value()))};
    % 
    %
    % 
    % EXAMPLE 2
    % ---------
    % The following example will use the actual duration of the state x as
    % duration of the state y by modifying the duration of state y when it is
    % entered:
    % 
    %  stateDuration = StateRuntimeVariable(nan);
    %  x = State('x');
    %  x.duration = 1000;
    %  x.onExit = {@() stateDuration.set_value(x.elapsedTime)};
    % 
    %  y = State('y');
    %  y.onEntry = {@() y.set_duration(stateDuration.value)};
    %
    % See also State, SGLStateArc


    
    properties ( Dependent = true )
       value         
    end

    properties ( Access = private )
        value_
    end

    methods
        
        function obj = StateRuntimeVariable(intialValue)
            if nargin == 1
                obj.value = intialValue;
            end
        end
        
        function v = get_value(obj) 
           v = obj.value();
        end
        function set_value(obj, v) 
           obj.value_ = v;
        end
        function v = get.value(obj)
            v = obj.value_;
        end
        function set.value(obj,v)
            obj.value_ = v;
        end         
    end 
end
