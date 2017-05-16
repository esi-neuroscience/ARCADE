classdef Grating < PixelShader
    
    properties ( Transient = true )
        color1 = [255 255 255 255];
        color2 = [0 0 0 255];
        maskRotation = 0;
        pixelsPerCycle = 25;
        direction = 0;
        smoothing = 2;
        phaseShift = 0;
        maskWidth = 200;
        maskHeight = 200;
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
            obj.pixelsPerCycle = obj.pixelsPerCycle;
            obj.direction = obj.direction;
            obj.smoothing = obj.smoothing;
            obj.phaseShift = obj.phaseShift;
            obj.maskWidth = obj.maskWidth;
            obj.maskHeight = obj.maskHeight;
            
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
                        
        function set.pixelsPerCycle(obj, ppc)
            obj.setParameter(4, ppc)
            obj.pixelsPerCycle = ppc;
        end
        
        function set.direction(obj, direction)
            obj.setParameter(5, direction)
            obj.direction = direction;
        end            
        
        function set.smoothing(obj, smoothing)
            obj.setParameter(6, smoothing)
            obj.smoothing = smoothing;
        end          
    end    
end