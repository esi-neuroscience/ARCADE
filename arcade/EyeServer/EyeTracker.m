classdef EyeTracker < handle
    % Checks if current eye position matches a position and triggers events
    properties
        name
        center = [0 0];
        tolerance
    end
    
    properties ( GetAccess = public, SetAccess = private )
        isInside = false;
        enterEvent
        leaveEvent
    end
    
    methods
        
        function obj = EyeTracker(name, position, radius)
            obj.name = name;
            obj.center = position;
            obj.tolerance = radius;
            obj.enterEvent = IPCEvent([name 'Enter'], false);
            obj.leaveEvent = IPCEvent([name 'Leave'], false);                        
        end
        
        function checkEye(obj, position)
            wasInside = obj.isInside;
            obj.isInside = sqrt(sum((position(:)'-obj.center).^2)) < obj.tolerance;
            if ~wasInside && obj.isInside
               obj.enterEvent.trigger(); 
               fprintf('Enter %s\n', obj.name)
            elseif wasInside && ~obj.isInside
                obj.leaveEvent.trigger(); 
                fprintf('Leave %s\n', obj.name)
            end                        
        end
        
    end
    
    
end