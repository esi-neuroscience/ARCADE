classdef EyeTracker < handle
    % Checks if current eye position matches a position and triggers events
    properties
        name
        center = [0 0];
        tolerance
    end
    
    properties ( Access = private )
        isInside = false;
        enterEvent
        leaveEvent
    end
    
    methods
        
        function obj = EyeTracker(name, position, radius)
            obj.name = name;
            obj.center = position;
            obj.tolerance = radius;
            obj.enterEvent = IPCEvent([name 'Enter']);
            obj.enterEvent.CreateEvent();
            obj.leaveEvent = IPCEvent([name 'Leave']);
            obj.leaveEvent.CreateEvent();
            
        end
        
        function checkEye(obj, position)
            wasInside = obj.isInside;
            obj.isInside = sqrt((position(:)'-obj.center).^2) < radius;
            if ~wasInside && obj.isInside
               obj.enterEvent.trigger(); 
            elseif wasInside && ~obj.isInside
                obj.leaveEvent.trigger(); 
            end                        
        end
        
    end
    
    
end