classdef Gaussian < PixelShader
    % Class for a (drifting) Gaussian 
    % ARCADE/arcade/StimServer/classes/stimfiles/pixelShader/Gaussian.fx
    % 
    % Size of pixel shader is always at least 5*max(sdx, sdy).
    %
    properties ( Transient = true )
        color = [255 255 255]; % [r g b]        
        angle = 0; % degrees
        sdx = 5; % standard deviation in x-direction in pixels
        sdy = 5; % standard deviation in y-direction in pixels
    end
        
    methods
        function obj = Gaussian()
            % file for this stimulus
            gratfxFile = 'Gaussian.fx';
            filename = fullfile(...
                fileparts(mfilename('fullpath')),'stimfiles','pixelShader', gratfxFile);
            obj = obj@PixelShader(filename);
            
            % set defaults
            obj.color = obj.color;
            obj.sdx = obj.sdx;
            obj.sdy = obj.sdy;            

        end
        
        function set.color(obj, rgb)
            obj.setColor(1, [rgb 255])
            obj.color = rgb;
        end

        function set.sdx(obj, sdx)
            if 5*max([sdx obj.sdy]) > min([obj.shaderWidth, obj.shaderHeight])
                obj.shaderWidth = 5*max([sdx obj.sdy]);
                obj.shaderHeight = 5*max([sdx obj.sdy]);
            end
            obj.setParameter(1, sdx) 
            obj.sdx = sdx;
        end

        function set.sdy(obj, sdy);
            if 5*max([sdy obj.sdx]) > min([obj.shaderWidth, obj.shaderHeight])
                obj.shaderWidth = 5*max([sdy obj.sdx]);
                obj.shaderHeight = 5*max([sdy obj.sdx]);
            end
            obj.setParameter(2, sdy) 
            obj.sdy = sdy;
        end
        
        function set.angle(obj, rotation)
            obj.setParameter(3, rotation)
            obj.angle = rotation;
        end            
     
    end
end