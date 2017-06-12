classdef PixelShadedPicture < Stimulus
    
    properties ( SetAccess = immutable, GetAccess = public, Transient = true )
        pictureFile
        shaderFile        
    end
    
    properties ( Access = public, Transient = true )
        animationIncrement = 1; % value to be added to phase variable in shader with each frame
        animationPhase = 0; % manually set phase variable in shader
    end
    
    methods
        
        function obj = PixelShadedPicture(pictureFile, shaderFile)
            assert(exist(pictureFile, 'file') == 2, 'Picture file %s not found', pictureFile)
            assert(exist(shaderFile, 'file') == 2, 'Shader file %s not found', shaderFile)
            pic = Picture(pictureFile);
            StimServer.Command(0, [uint8(18), typecast(uint16(pic.key), 'uint8') uint8([shaderFile 0])]);
            obj = obj@Stimulus();
            pic.delete();
            obj.shaderFile = shaderFile;
            obj.pictureFile = pictureFile;
            obj.animationIncrement = obj.animationIncrement;
            obj.animationPhase = obj.animationPhase;
        end
        
        function set.animationIncrement(obj, increment)
            StimServer.Command(obj.key, [uint8(2), typecast(single(increment), 'uint8')]);
            obj.animationIncrement = increment;
        end
        
        function set.animationPhase(obj, phase)
            StimServer.Command(obj.key, [uint8(6), typecast(single(phase),'uint8')]);
            obj.animationPhase = phase;
        end
        
        function setParameter(obj, idx, value)
            StimServer.Command(obj.key, [uint8(1), uint8(idx), typecast(single(value), 'uint8')]);
        end
    end
    
end
