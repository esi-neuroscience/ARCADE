classdef PixelShader < Stimulus
            
    properties ( SetAccess = immutable )
        filename
    end
    
    properties ( SetAccess = public, GetAccess = public )
        shaderWidth = 1000;
        shaderHeight = 1000;
        animationIncrement = 1;
        animationPhase = 0;
    end
    
    methods
        function obj = PixelShader(filename)
            assert(exist(filename, 'file') == 2, 'Shader file %s not found', filename)
            StimServer.Command(0, [uint8(4), uint8(filename), uint8(0)]); % 0 = endl;
            obj = obj@Stimulus();
            obj.filename = filename;
            obj.shaderWidth = obj.shaderWidth;
            obj.shaderHeight = obj.shaderHeight;
            obj.animationIncrement = 1;
            
        end
        
        function set.shaderWidth(obj, shaderWidth)
            StimServer.Command(obj.key, [9 typecast(uint16([shaderWidth obj.shaderHeight]), 'uint8')])
            obj.shaderWidth = shaderWidth;
        end
        function set.shaderHeight(obj, shaderHeight)
            StimServer.Command(obj.key, [9 typecast(uint16([obj.shaderWidth shaderHeight]), 'uint8')])
            obj.shaderHeight = shaderHeight;
        end
        
        function set.animationIncrement(obj, increment)
            StimServer.Command(obj.key, [uint8(2), typecast(single(increment), 'uint8')]);
            obj.animationIncrement = increment;
        end
        
        function set.animationPhase(obj, phase)
             StimServer.Command(obj.key, [uint8(6), typecast(single(phase),'uint8')]);
             obj.animationPhase = phase;
        end
        
        
    end
    
    methods ( Access = public )
        
        function setColor(obj, idx, rgbw)
            StimServer.Command(obj.key, [5, idx, rgbw]);
        end
        
        function setParameter(obj, idx, value)
            StimServer.Command(obj.key, [uint8(1), uint8(idx), typecast(single(value), 'uint8')]);
        end
        

    end
    
    
end

