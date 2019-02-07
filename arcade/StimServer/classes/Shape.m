classdef (Abstract) Shape < Stimulus
    % SHAPE < Stimulus - Abstract intermediate class for shape stimuli for ARCADE
    %
    % All ARCADE stimuli that are drawn as shapes with an outline and/or face
    % have the following properties :
    %
    % PROPERTIES
    % -----------
    %    drawMode  : integer mode for outline/face drawing: 
    %                1=face only, 2=edge only, 3=face and edge
    %    lineWidth : width of outline (pixel)
    %    angle     : counter-clockise rotation angle (degree), 0=horizontal
    %    faceColor : 24-bit [r g b] value
    %    faceAlpha : 8-bit alpha value, 0=transparent, 255=opaque
    %    lineColor : 24-bit [r g b] value
    %    lineAlpha : 8-bit alpha value, 0=transparent, 255=opaque
    %
    % For more information, see <a href="matlab:doc('arcade')">the ARCADE guide</a> and the  superclasses.
    %
    % See also Shape, Stimulus
    
    
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