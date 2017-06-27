classdef Grating < PixelShader
    % GRATING - Class for a (drifting) grating with a circular mask. 
    % Pixel shader file:
    % ARCADE/arcade/StimServer/classes/stimfiles/pixelShader/MaskedGrating.fx
    
    properties ( Transient = true )
        color1 = [255 255 255 255]; % [r g b alpha]
        color2 = [0 0 0 255]; % [r g b alpha]
        maskRotation = 0; % angle of circular mask in degree
        spatialFrequency = 25; % px / cycle
        direction = 0;  % drift direction in degree
        smoothing = 2; % 2 = sinusoidal grating, 10 = square wave grating
        phaseShift = 0;
        maskWidth = 200; % width of circular mask in px
        maskHeight = 200; % height of circular mask in px
        temporalFrequency = 1; % cycles / s
    end
    
    properties ( Access = private, Transient = true )
        frameRate = [];
    end
    
    methods
        function obj = Grating()
            % file for this stimulus
            gratfxFile = 'MaskedGrating.fx';
            filename = fullfile(...
                fileparts(mfilename('fullpath')),'stimfiles','pixelShader', gratfxFile);
            obj = obj@PixelShader(filename);
            
            % set defaults
            obj.color1 = obj.color1;
            obj.color2 = obj.color2;
            obj.maskRotation = obj.maskRotation;
            obj.spatialFrequency = obj.spatialFrequency;
            obj.direction = obj.direction;
            obj.smoothing = obj.smoothing;
            obj.phaseShift = obj.phaseShift;
            obj.maskWidth = obj.maskWidth;
            obj.maskHeight = obj.maskHeight;
            
            obj.frameRate = StimServer.GetFrameRate();
            obj.temporalFrequency = obj.temporalFrequency;

        end
        
        function set.color1(obj, rgbw)
            obj.setColor(1, rgbw)
            obj.color1 = rgbw;
        end
        
        function set.color2(obj, rgbw)
            obj.setColor(2, rgbw)
            obj.color2 = rgbw;
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
        
        function set.spatialFrequency(obj, ppc)
            obj.setParameter(4, ppc)
            obj.spatialFrequency = ppc;
        end
        
        function set.direction(obj, direction)
            obj.setParameter(5, direction)
            obj.direction = direction;
        end
        
        function set.smoothing(obj, smoothing)
            obj.setParameter(6, smoothing)
            obj.smoothing = smoothing;
        end
        
        function set.temporalFrequency(obj, speed)
            obj.animationIncrement = speed/obj.frameRate;
            obj.temporalFrequency = speed;
        end
    end
end