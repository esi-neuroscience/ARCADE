classdef Rectangle < Stimulus
    
    
    properties ( SetAccess = public, GetAccess = public )
        width = 11;
        height = 21;
        angle = 0;
        color = [255 255 255];
        alpha = 255;
    end       
        
    methods
        function obj = Rectangle            
            StimServer.Command(0, uint8(20));
            obj = obj@Stimulus();
            
        end
        
        function set.angle(obj, angle)
            StimServer.Command(obj.key, [uint8(4), typecast(single(angle),'uint8')]);
            obj.angle = angle;
        end
        
        function set.width(obj, width)
            StimServer.Command(obj.key, [uint8([1,1]), typecast(uint16([width, obj.height]),'uint8')]);
            obj.width = width;
        end
        
        function set.height(obj, height)
            StimServer.Command(obj.key, [uint8([1,1]), typecast(uint16([obj.width, height]),'uint8')]);
            obj.height = height;
        end
        
        function set.color(obj, color)
            StimServer.Command(obj.key, [5, color, obj.alpha]);
            obj.color = color;
        end
        
        function set.alpha(obj, alpha)
            StimServer.Command(obj.key, [5, obj.color, alpha]);
            obj.alpha = alpha;
        end
        
    end

    
end