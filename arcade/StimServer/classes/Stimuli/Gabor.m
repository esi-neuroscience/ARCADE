classdef Gabor < PixelShader
    % GABOR - Class for a (drifting) grating with a Gaussian mask. 
    % Pixel shader file:
    % ARCADE/arcade/StimServer/classes/stimfiles/pixelShader/Gabor.fx
    
    properties ( Transient = true )
        color1 = [255 255 255]; % [r g b alpha]
        color2 = [0 0 0]; % [r g b alpha]
        maskRotation = 0; % angle of gaussian mask in degree
        spatialPeriod = 25; % px / cycle
        direction = 0;  % drift direction in degree: 0=rightward, 90=upward, ...
        smoothing = 2; % 2 = sinusoidal grating, 10 = square wave grating
        phaseOffset = 0; % phase offset in deg
        maskWidth = 50; % x-std of gaussian mask in px
        maskHeight = 50; % y-std of gaussian mask in px
        temporalFrequency = 1; % cycles / s
    end
    
    properties ( Access = private, Transient = true )
        frameRate = [];
    end
    
    methods
        function obj = Gabor()
            % file for this stimulus
            gratfxFile = 'Gabor.fx';
            filename = fullfile(...
                fileparts(mfilename('fullpath')), gratfxFile);
            obj = obj@PixelShader(filename);
            
            % set defaults
            obj.color1 = obj.color1;
            obj.color2 = obj.color2;
            obj.maskRotation = obj.maskRotation;
            obj.spatialPeriod = obj.spatialPeriod;
            obj.direction = obj.direction;
            obj.smoothing = obj.smoothing;
            obj.phaseOffset = obj.phaseOffset;
            obj.maskWidth = obj.maskWidth;
            obj.maskHeight = obj.maskHeight;            
            obj.frameRate = StimServer.GetFrameRate();
            obj.temporalFrequency = obj.temporalFrequency;

        end
        
        function set.color1(obj, rgb)
            obj.setColor(1, [rgb 255])
            obj.color1 = rgb;
        end
        
        function set.color2(obj, rgb)
            obj.setColor(2, [rgb 255])
            obj.color2 = rgb;
        end
        function set.maskWidth(obj, width)
            obj.setParameter(1, width)
            obj.maskWidth = width;
        end
        function set.maskHeight(obj, height)
            obj.setParameter(2, height)
            obj.maskHeight = height;
        end
        
        function set.maskRotation(obj, rotation)
            obj.setParameter(3, rotation)
            obj.maskRotation = rotation;
        end
        
        function set.spatialPeriod(obj, ppc)
            obj.setParameter(4, ppc)
            obj.spatialPeriod = ppc;
        end
        
        function set.direction(obj, direction)
            obj.setParameter(5, direction)
            obj.direction = direction;
        end
        
        function set.smoothing(obj, smoothing)
            obj.setParameter(6, smoothing)
            obj.smoothing = smoothing;
        end
        
        function set.phaseOffset(obj, offset)
            obj.setParameter(7, offset)
            obj.phaseOffset = offset;
        end

        function set.temporalFrequency(obj, speed)
            obj.animationIncrement = speed/obj.frameRate;
            obj.temporalFrequency = speed;
        end
    end
end