classdef Grating < PixelShader
    % GRATING < PixelShader < Stimulus - Sine gratings for ARCADE
    %
    % Shader file: <a href="matlab:edit('Grating.fx')">MaskedGrating.fx</a>
    %
    % PROPERTIES
    % -----------
    %    
    %  color1            : 24-bit color [r g b alpha]/[r g b]
    %  color2            : 24-bit color [r g b alpha]/[r g b]
    %  spatialPeriod     : (pixel per cycle)
    %  direction         : drift direction in degree (counter-clockwise): 0=->
    %  smoothing         : 2=sinusoidal grating, 10 > ~square wave grating
    %  phaseShift        : phase offset (degree)     
    %  radius            : radius of circular mask (pixel)
    %  temporalFrequency : drift speed (cycles per second)
    %  maskWidth         : horizontal radius of circular mask (pixel) for 
    %                      direction = 0
    %  maskHeight        : vertical radius of circular mask in (pixel) for 
    %                      direction = 0
    % 
    % For more information, see <a href="matlab:doc('arcade')">the ARCADE guide</a>.
    % 
    % See also PixelShader, Stimulus
    
    properties ( Transient = true )
        color1 = [255 255 255 255]; % [r g b alpha]
        color2 = [0 0 0 255]; % [r g b alpha]
        maskRotation = 0; % angle of circular mask in degree
        spatialPeriod = 25; % px / cycle        
        direction = 0;  % drift direction in degree
        smoothing = 2; % 2 = sinusoidal grating, 10 = square wave grating
        phaseShift = 0;
        % horizontal radius of circular mask in px for direction = 0
        maskWidth = 100; 
        % vertical radius of circular mask in px for direction = 0
        maskHeight = 100; 
        temporalFrequency = 1; % cycles / s
    end
    
    properties ( Transient = true, Dependent = true, Hidden = true )
        spatialFrequency % wrongly named legacy property
    end
    
    properties ( Access = private, Transient = true )
        frameRate = [];
    end
    
    methods
        function obj = Grating()
            % file for this stimulus
            gratfxFile = 'MaskedGrating.fx';
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
            obj.phaseShift = obj.phaseShift;
            obj.maskWidth = obj.maskWidth;
            obj.maskHeight = obj.maskHeight;
            
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
        function set.maskWidth(obj, width)
            obj.setParameter(1, width)
            obj.maskWidth = width;
             if ~(min([obj.shaderHeight,obj.shaderWidth]) >= 2*width)
                obj.shaderHeight = 2*width;
                obj.shaderWidth = 2*width;
            end
        end
        function set.maskHeight(obj, height)
            obj.setParameter(2, height)
            obj.maskHeight = height;
            if ~(min([obj.shaderHeight,obj.shaderWidth]) >= 2*height)
                obj.shaderHeight = 2*height;
                obj.shaderWidth = 2*height;
            end
        end
        
        function set.maskRotation(obj, rotation)
            obj.setParameter(3, rotation)
            obj.maskRotation = rotation;
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
        
        function set.temporalFrequency(obj, speed)
            obj.animationIncrement = speed/obj.frameRate;
            obj.temporalFrequency = speed;
        end
    end
end