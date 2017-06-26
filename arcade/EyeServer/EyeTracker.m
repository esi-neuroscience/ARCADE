classdef EyeTracker < handle
    % Checks if current eye position matches a position and triggers events
    properties
        name
        center = [0 0];
        tolerance
        verbose = true;
    end
    
    properties ( GetAccess = public, SetAccess = private )
        isInside = -1
        enterEvent
        leaveEvent
    end
    
    methods
        
        function obj = EyeTracker(name, position, radius)
            obj.name = name;
            obj.center = position;
            obj.tolerance = radius;
            obj.enterEvent = IPCEvent([name 'In'], true);
            obj.enterEvent.reset();
            obj.leaveEvent = IPCEvent([name 'Out'], true);   
            obj.leaveEvent.reset();
        end
        
        function checkEye(obj, position)
            wasInside = obj.isInside;
            obj.isInside = sqrt(sum((position(:)'-obj.center).^2)) < obj.tolerance;
            if (wasInside == -1 && obj.isInside) || (~wasInside && obj.isInside)
                obj.enterEvent.trigger();
                obj.leaveEvent.reset();
                if obj.verbose
                   msg = sprintf('Entered %s', obj.name);
                   logmessage(msg)
               end
            elseif (wasInside == -1 && ~obj.isInside) || (wasInside && ~obj.isInside)
                obj.leaveEvent.trigger();
                obj.enterEvent.reset();
                if obj.verbose
                   msg = sprintf('Exited %s', obj.name);
                   logmessage(msg)
               end
            end
        end

        function delete(obj)
            obj.enterEvent.reset();
            obj.enterEvent.delete();
            obj.leaveEvent.reset();
            obj.leaveEvent.delete();
        end
    end
    
    
end