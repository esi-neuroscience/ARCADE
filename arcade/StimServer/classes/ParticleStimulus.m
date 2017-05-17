classdef ParticleStimulus < Stimulus
    
    
    properties ( Transient = true )
        
        particleDiameter = 3; % px
        particleColor = [255 255 255];
        particleAlpha = 255;
        particleSpeed = 0.01; % px per frame
        particleDirection = 0;
        maskRadius = 0;
        phase = 0;
        
    end
    
    properties ( SetAccess = immutable )
        width
        height
        filename
    end
    
    methods
        
        function obj = ParticleStimulus(filename, width, height)
            assert(exist(filename, 'file') == 2, 'Particle file %s not found', filename)
            StimServer.Command(0, ...
                [uint8(8), typecast(uint16([width height]),'uint8'), ...
                uint8(filename), uint8(0)]);
            obj = obj@Stimulus();
            obj.width = width;
            obj.height = height;
            obj.filename = filename;
            obj.particleDiameter = obj.particleDiameter;
            obj.particleDirection = obj.particleDirection;
            obj.particleSpeed = obj.particleSpeed;
            obj.particleColor = obj.particleColor;
            obj.particleAlpha = obj.particleAlpha;
        end
        
        function set.particleSpeed(obj, speed)
            StimServer.Command(obj.key, [uint8(2), typecast(single(speed),'uint8')]);
            obj.particleSpeed = speed;
        end
        
        function set.particleDiameter(obj, diameter)
            assert(diameter > 2, 'Particle diameter must be > 2 px')
            StimServer.Command(obj.key, [uint8([1,1]), typecast(uint16(diameter),'uint8')]);
            obj.particleDiameter = diameter;
        end
        
        function set.particleDirection(obj, direction)
            StimServer.Command(obj.key, [uint8(4), typecast(single(direction),'uint8')]);
            obj.particleDirection = direction;
        end
        
        function set.particleAlpha(obj, alpha)
            StimServer.Command(obj.key, [5, obj.particleColor, alpha]);
            obj.particleAlpha = alpha;
        end
        
        function set.maskRadius(obj, radius)
            
            % [kk 1 2 value] set patch radius (0 ... 1.42 single float) for particle stimulus.
            % A value of 0 switches back to the unpatched (rectangular) mode.
            % A value of 1 produces a circle patch with a radius equal to the 1/2 width of the rectangle patch
            % A value of sqrt(2) produces the original rectangle patch
            % because the radius is equal to the euclidean sum of the 1/2 width and 1/2 height
            StimServer.Command(obj.key, [uint8([1,2]), typecast(single(radius),'uint8')]);
            obj.maskRadius = radius;
        end
        
        function set.particleColor(obj, rgb)
            StimServer.Command(obj.key, [5, rgb, obj.particleAlpha]);
            obj.particleColor = rgb;
        end
        
        function set.phase(obj, value)
            % [kk 6 value] set animated shift value (single float).
            % *this value is signed*
            % 0   -> initial dot position
            % 0.5 -> 1/2 radius in direction
            % 1.0 -> radius in direction
            % 2.0 -> full cycle rotation (equivalent to ~0)
            StimServer.Command(obj.key, [uint8(6), typecast(single(value),'uint8')]);
            obj.phase = value;
        end
        
        
    end
    
    
end