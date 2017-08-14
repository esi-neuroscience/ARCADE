classdef Rectangle < Stimulus
    % RECTANGLE - Class for rectangular stimuli
    % 
    % See also Stimulus

    properties ( SetAccess = public, GetAccess = public, Transient = true )
        width = 11; % width of rectangle in px for angle=0
        height = 21; % height of rectangle in px for angle=0
        angle = 0; % counter-clockise rotation of rectangle in degrees, 0=horizontal
        color = [255 255 255]; % 24-bit [r g b] value
        alpha = 255; % alpha transparency, 0=transparent, 255=opaque
    end       
        
    methods
        function obj = Rectangle            
            StimServer.Command(0, uint8(20));
            obj = obj@Stimulus();

            % set defaults
            obj.width = obj.width;
            obj.height = obj.height;
            obj.angle = obj.angle;
            obj.color = obj.color;
            obj.alpha = obj.alpha;
            
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
        
        function delete(obj)            
        end
        
    end

    
end