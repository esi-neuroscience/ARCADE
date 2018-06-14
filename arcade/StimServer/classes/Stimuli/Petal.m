classdef Petal < Stimulus
    % PETAL - Class for petal stimuli
    %
    % Petal-like shape based on two circles and a quadratic Bezier curve
    % connecting the circles.
    %
    %
    %                         _______
    %                        /       \
    %         _____         /         \
    %        /     \_______/           |
    %        |  r    __q____     R     |
    %        \______/       \          /
    %                        \________/
    %            ------ d ------
    %
    % See also Stimulus
    
    properties ( SetAccess = public, GetAccess = public, Transient = true )
        r = 25; % radius of medial circle in px
        R = 100; % radius of lateral circle in px
        d = 250; % distance between circles
        % position of middle point of Bezier curve (normalized to distance
        % of circles). Default = golden ratio ~ 0.382
        q = 2-(1+sqrt(5))/2; 
        drawMode = 1; % 1=face only, 2=edge only, 3=face and edge
        lineWidth = 2; % width of outline in px
        angle = 0; % counter-clockise rotation of rectangle in degrees, 0=horizontal
        faceColor = [255 255 255 255]; % 24-bit [r g b alpha] value with alpha
        lineColor = [0 0 0 255]; %  24-bit [r g b] value with alpha
    end
    
    methods
        function obj = Petal
            StimServer.Command(0, uint8(26));
            obj = obj@Stimulus();                        
            obj.angle = obj.angle;
            obj.faceColor = obj.faceColor;
            obj.lineColor = obj.lineColor;
            obj.q = obj.q;
            
        end
        
        function set.r(obj, r)
            obj.check_params(r, obj.R, obj.q, obj.d)    
            StimServer.Command(obj.key, [uint8([1 1]), typecast(single(r),'uint8')]);
            obj.r = r;
        end
        
        function set.R(obj, R)
            obj.check_params(obj.r, R, obj.q, obj.d)    
            StimServer.Command(obj.key, [uint8([1 2]), typecast(single(R),'uint8')]);
            obj.R = R;
        end
        
        function set.d(obj, d)
            obj.check_params(obj.r, obj.R, obj.q, d)    
            StimServer.Command(obj.key, [uint8([1 3]), typecast(single(d),'uint8')]);
            obj.d = d;
        end
        
        function set.q(obj, q)
            obj.check_params(obj.r, obj.R, q, obj.d)    
            StimServer.Command(obj.key, [uint8([1 4]), typecast(single(q),'uint8')]);
            obj.q = q;
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
    
    methods ( Static = true, Access = private )
        function check_params(r,R,q,d)            
            if ~ ((d * q > r) && ((1-q) * d > R))
                error('Invalid parameters. Parameters must adhere to d*q>r && (1-q)*d > R')
            end
        end
    end
        
    
    
end