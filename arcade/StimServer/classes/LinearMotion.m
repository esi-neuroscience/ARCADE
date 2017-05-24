classdef LinearMotion < Animation
    % Class for linear motion of a stimulus along a polygon.
    %
    % Usage
    % -----
    %   a = LinearMotion(speed, coordinates)
    %     
    %  
    % Example
    % -------
    %   a = LinearMotion(200, [0 0 200 200]);
    %   c = Circle;
    %   c.animation = a;
    %   c.visible = true;
    %     
    % See also Animation, Stimulus
    
    properties ( SetAccess = immutable, Transient = true )       
       velocity = []; % px / s for 120 Hz refresh rate
    end
    
    properties ( Transient = true )
       vertices = []; % vector of positions ([x1 y1 x2 y2 ...])
    end
    
    methods
        function obj = LinearMotion(velocity, vertices)
            StimServer.Command(0, uint8([132 typecast(uint16(velocity),'uint8')]));
            obj = obj@Animation();
            obj.velocity = velocity;            
            obj.vertices = vertices;
        end
    
        function set.vertices(obj, vv)
            StimServer.Command(obj.key, [uint8(11), typecast(int16(vv),'uint8')])
            obj.vertices = vv;
        end
        
    end
    
    
end