classdef Gammatron < PixelShader
    % GAMMATRON - Class for annular gratings.
    % ARCADE/arcade/StimServer/classes/stimfiles/pixelShader/Gammatron.fx
    
    properties  ( Access = public, Transient = true )
        temporalFrequency = 1; % cycles per second;
        spatialPeriod = 50; % pixel per cycle
        direction = 1; % -1=inward, 1=outward;
        color1 = [0 0 0 255]; % [r g b alpha]
        color2 = [255 255 255 255]; % [r g b alpha]
        radius = 250; % pixels
    end
    
    properties ( GetAccess = private, Transient = true, SetAccess = immutable )
        frameRate = [];
    end        
    
    methods
        function obj = Gammatron()
            
            fxFile = 'Gammatron.fx';
            filename = fullfile(...
                fileparts(mfilename('fullpath')),'stimfiles','pixelShader', fxFile);
            obj = obj@PixelShader(filename);
            obj.frameRate = StimServer.GetFrameRate();
            
            obj.temporalFrequency = obj.temporalFrequency;
            obj.spatialPeriod = obj.spatialPeriod;
            obj.radius = obj.radius;
            obj.color1 = obj.color1;
            obj.color2 = obj.color2;
            obj.direction = obj.direction;
            
        end
        
        function set.color1(obj, rgbw)
            obj.setColor(1, rgbw)
            obj.color1 = rgbw;
        end
        
        function set.color2(obj, rgbw)
            obj.setColor(2, rgbw)
            obj.color2 = rgbw;
        end
        
        function set.radius(obj, radius)
            obj.shaderWidth = radius;
            obj.shaderHeight = radius;
        end
        
        function set.temporalFrequency(obj, tf)
            framesPerCycle = 1/tf*obj.frameRate;
            obj.setParameter(2, framesPerCycle);
            obj.temporalFrequency =  tf;
        end
        
        function set.spatialPeriod(obj, sp)
            obj.setParameter(1, sp);
            obj.spatialPeriod = sp;
        end
        
        function set.direction(obj, direction)
            if direction == 1 || direction == -1
                obj.setParameter(3, direction);
                obj.direction = direction;
            else
                error('Invalid direction; %g. Gammatron direction must be 1 (outward) or -1 (inward)', direction)
            end
        end
        
    end        
end