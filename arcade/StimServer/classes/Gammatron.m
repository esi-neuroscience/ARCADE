% classdef Gammatron < PixelShader


fxFile = 'Gammatron.fx';
filename = fullfile(...
    fileparts(mfilename('fullpath')),'stimfiles','pixelShader', fxFile);

obj = PixelShader(filename);
obj.setParameter(1, 500); % sf
obj.setParameter(2, 2); % tf
obj.setParameter(3, 1); % direction
obj.setParameter(4, 0.8); % direction
obj.shaderWidth = 400;
obj.shaderHeight = 400;
obj.visible = true;
