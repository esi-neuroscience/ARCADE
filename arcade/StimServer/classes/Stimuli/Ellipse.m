classdef Ellipse < Stimulus
    % ELLIPSE - Class for elliptic stimuli
    % 
    % See also Stimulus

    properties ( SetAccess = public, GetAccess = public, Transient = true )
        width = 100; % width of ellipse in px for angle=0
        height = 100; % height of ellipse in px for angle=0
        angle = 0; % counter-clockise rotation of ellipse in degrees, 0=horizontal
        drawMode = 1; % 1=face only, 2=edge only, 3=face and edge
        lineWidth = 2; % width of outline in px
        faceColor = [255 255 255 255]; % 24-bit [r g b alpha] value with alpha
        lineColor = [0 0 0 255]; %  24-bit [r g b] value with alpha
    end       
        
    methods
        function obj = Ellipse            
            StimServer.Command(0, uint8(28));
            obj = obj@Stimulus();

            % set defaults
            obj.width = obj.width;
            obj.height = obj.height;
            obj.angle = obj.angle;
            obj.drawMode = obj.drawMode;
            obj.lineWidth = obj.lineWidth;
            obj.faceColor = obj.faceColor;
            obj.lineColor = obj.lineColor;
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
        
        function set.drawMode(obj, mode)
            StimServer.Command(obj.key, uint8([6 mode]));
            obj.drawMode = mode;
        end
        
        function set.lineWidth(obj, width)
            StimServer.Command(obj.key, [uint8(10), typecast(single(width),'uint8')]);
            obj.lineWidth = width;
        end
        
        function set.faceColor(obj, color)
            if numel(color) == 3
                color = [color 255];
            end
            StimServer.Command(obj.key, [5, color]);
            obj.faceColor = color;
        end
        
        function set.lineColor(obj, color)
            if numel(color) == 3
                color = [color 255];
            end
            StimServer.Command(obj.key, [9, color]);
            obj.lineColor = color;
        end                
        
        function delete(obj)            
        end
        
    end

    
end