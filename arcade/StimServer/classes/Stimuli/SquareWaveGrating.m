classdef SquareWaveGrating < PixelShader
    % GRATING - Class for drifting square-wave gratings with a circular mask
    % Pixel shader file:
    % ARCADE/arcade/StimServer/classes/stimfiles/pixelShader/SquareWaveGrating.fx
    
    properties ( Transient = true )
        color1 = [255 255 255 255]; % [r g b alpha]
        color2 = [0 0 0 255]; % [r g b alpha]        
        spatialPeriod = 25; % px / cycle        
        direction = 0;  % drift direction in degree
        smoothing = 1; % width of anti-aliasing window
        phaseShift = 0; % pixels
        % horizontal radius of circular mask in px for direction = 0
        radius = 100; 
        temporalFrequency = 1; % cycles / s
    end
    
    properties ( Transient = true, Dependent = true, Hidden = true )
        spatialFrequency % wrongly named legacy property
    end
    
    properties ( Access = private, Transient = true )
        frameRate = [];
    end
    
    methods
        function obj = SquareWaveGrating()
            % file for this stimulus
            gratfxFile = 'SquareWaveGrating.fx';
            filename = fullfile(...
                fileparts(mfilename('fullpath')), gratfxFile);
            obj = obj@PixelShader(filename);
            
            % set defaults
            obj.color1 = obj.color1;
            obj.color2 = obj.color2;            
            obj.spatialPeriod = obj.spatialPeriod;
            obj.direction = obj.direction;
            obj.smoothing = obj.smoothing;
            obj.phaseShift = obj.phaseShift;
            obj.radius = obj.radius;                        
            obj.frameRate = StimServer.GetFrameRate();
            obj.temporalFrequency = obj.temporalFrequency;

        end
        
        function set.color1(obj, rgbw)
            if numel(rgbw) == 3
                rgbw = [rgbw 255];
            end
            obj.setColor(1, rgbw)
            obj.color1 = rgbw;
        end
        
        function set.color2(obj, rgbw)
            if numel(rgbw) == 3
                rgbw = [rgbw 255];
            end
            obj.setColor(2, rgbw)
            obj.color2 = rgbw;
        end
        function set.radius(obj, width)
            obj.setParameter(1, width)
            obj.radius = width;
             if ~(min([obj.shaderHeight,obj.shaderWidth]) >= 2*width)
                obj.shaderHeight = 2*width;
                obj.shaderWidth = 2*width;
            end
        end

        
        function set.spatialFrequency(obj, ppc)
            warning('The Grating property spatialFrequency has been renamed to spatialPeriod. Please use spatialPeriod instead.')
            obj.spatialPeriod = ppc;
        end
        
        function value = get.spatialFrequency(obj)
            value = obj.spatialPeriod;
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
        
        function set.phaseShift(obj, px)
            obj.setParameter(7, px)
            obj.phaseShift = px;
        end


        function set.temporalFrequency(obj, cyclesPerSecond)
            obj.animationIncrement = cyclesPerSecond*obj.spatialPeriod/obj.frameRate;
            obj.temporalFrequency = cyclesPerSecond;
        end
    end
end