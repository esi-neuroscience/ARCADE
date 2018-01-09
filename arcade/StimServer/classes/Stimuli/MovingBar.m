classdef MovingBar ( Sealed )< Rectangle
    % MOVINGBAR - Helper class for a moving bar
    %
    %
    % Usage
    % -----
    %
    %   bar = MovingBar(speed, distance);
    %   bar.play_animation()
    %
    % Example
    % -------
    %   bar = MovingBar(500, 500)
    %   bar.startPosition = [300 -300];
    %   bar.direction = 45;
    %   bar.color = [0 255 128];
    %   bar.width = 10;
    %   bar.play_animation();
    %
    % See also Stimulus, Rectangle, Animation
    
    properties ( Transient = true )
        direction = 0 % traveling direction of bar in degrees
        travelDistance = 500; % distance of travel
        startPosition = [0 0]; % starting position of bar sweep
        % linkedOrientationDirection - boolean flag
        % If true, bar will be orthogonal to motion direction
        linkedOrientationDirection = true;
        barAnimation
    end
    
    
    
    methods
        function obj = MovingBar(speed, distance)
            obj = obj@Rectangle;
            obj.height = 200;
            obj.width = 5;
            
            vertices = obj.calc_vertices(obj.startPosition, ...
                obj.direction, distance);
            obj.barAnimation = LinearMotion(speed, vertices);
            obj.barAnimation.terminalAction = '00001001';
            obj.travelDistance = distance;
            
        end
        
        function set.startPosition(obj, position)
            obj.barAnimation.vertices = obj.calc_vertices(position, ...
                obj.direction, obj.travelDistance);
            obj.startPosition = position;
            obj.position = position;
        end
        
        
        function set.direction(obj, direction)
            obj.barAnimation.vertices = obj.calc_vertices(obj.startPosition, ...
                direction, obj.travelDistance);
            obj.direction = direction;
            if obj.linkedOrientationDirection
                obj.angle = direction;
            end
        end
        
        function set.travelDistance(obj, travelDistance)
            obj.barAnimation.vertices = obj.calc_vertices(obj.startPosition, ...
                obj.direction, travelDistance);
            obj.travelDistance = travelDistance;
        end
        
        function play_animation(obj, varargin)
            if nargin > 1
                warning('StimServer:MovingBarAnimationInputArgument', ...
                    'MovingBar cannot play other animations than its own MovingBar.barAnimation. Input animation is ignored')
            end
            play_animation@Rectangle(obj, obj.barAnimation);
            obj.visible = true;
        end
                
        
        function delete(obj)
            
        end
        
    end
    
    methods ( Static, Hidden=true)
        function vv = calc_vertices(position, direction, distance)
            newX = cosd(direction)*distance + position(1);
            newY = sind(direction)*distance + position(2);
            vv = [position(1) position(2) newX newY];
        end
    end
    
    
end