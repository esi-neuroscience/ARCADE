classdef PictureWithGaussianPatch < PixelShadedPicture
    
    properties
        patchPosition = [0 0]; % position of patch relative to picture center in px
        patchAmplitude = 1; % amplitude of contrast decrement (0-1)
        patchSigma = 100; % standard deviation of patch in px
    end
    
    
    methods
        function obj = PictureWithGaussianPatch(filename)
            shaderFile = fullfile(arcaderoot, 'arcade', 'StimServer', ...
                'classes', 'stimfiles', 'pixelShader', 'PSPGaussianPatch.fx');
            obj = obj@PixelShadedPicture(filename, shaderFile);
            obj.patchPosition = obj.patchPosition;
            obj.patchAmplitude = obj.patchAmplitude;
            obj.patchSigma = obj.patchSigma;
        end
        
        
        function set.patchPosition(obj, position)
            obj.setParameter(1, position(1));
            obj.setParameter(2, position(2));                        
            obj.patchPosition = position;
        end
        
        function set.patchAmplitude(obj, amplitude)
            obj.setParameter(3, amplitude);
            obj.patchAmplitude = amplitude;
        end
        
        function set.patchSigma(obj, sigma)
            obj.setParameter(4, sigma);
            obj.patchSigma = sigma;
        end        
    end
    
    
end
