classdef (Abstract) Shape < Stimulus
    % SHAPE - Abstract helper class for shape stimuli with colors and
    % outlines and angles.
    %
    %
    % See also Stimulus, Rectangle, Ellipse, Petal
    
    
    properties ( Access = public, Transient = true )
        
        drawMode = 1; % 1=face only, 2=edge only, 3=face and edge
        lineWidth = 2; % width of outline in px
        angle = 0; % counter-clockise rotation of rectangle in degrees, 0=horizontal
        faceColor = [255 255 255]; % 24-bit [r g b] value
        lineColor = [255 255 255]; %  24-bit [r g b] value
        
    end
    
    properties ( Dependent = true )
        faceAlpha  % alpha value of face, 0=transparent, 255=opaque
        lineAlpha  % alpha value of outline, 0=transparent, 255=opaque
    end
    
    properties ( Access = protected )
        faceAlpha_ = 255;
        lineAlpha_ = 255;
    end
    
    
    methods
        
        function obj = Shape()
            obj = obj@Stimulus();
            
        end
        
        function set.angle(obj, angle)
            StimServer.Command(obj.key, [uint8(4), typecast(single(angle),'uint8')]);
            obj.angle = angle;
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
            color = obj.handle_color_input(color, obj.faceAlpha);
            StimServer.Command(obj.key, [5, color]);
            obj.faceColor = color(1:3);
            obj.faceAlpha_ = color(4);
        end
        
        function alpha = get.faceAlpha(obj)
            alpha = obj.faceAlpha_;
        end
        
        function set.faceAlpha(obj, alpha)
            obj.faceAlpha_ = alpha;
            StimServer.Command(obj.key, [5, obj.faceColor alpha]);
        end
        
        function set.lineColor(obj, color)
            color = obj.handle_color_input(color, obj.lineAlpha);
            StimServer.Command(obj.key, [9, color]);
            obj.lineColor = color(1:3);
            obj.lineAlpha_ = color(4);
        end
        
        function set.lineAlpha(obj, alpha)
            StimServer.Command(obj.key, [9, obj.lineColor alpha]);
            obj.lineAlpha_ = alpha;
        end
        
        function alpha = get.lineAlpha(obj)
            alpha = obj.lineAlpha_;
        end
                
    end
    
end