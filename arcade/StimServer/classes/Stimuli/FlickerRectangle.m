classdef FlickerRectangle < PixelShader
    % GAMMATRON - Class for annular gratings.
    % ARCADE/arcade/StimServer/classes/stimfiles/pixelShader/Gammatron.fx

    properties  ( Access = public, Transient = true )
        period = 2; % frames
        color1 = [0 0 0 255]; % [r g b alpha]
        color2 = [255 255 255 255]; % [r g b alpha]
    end

    properties ( GetAccess = private, Transient = true, SetAccess = immutable )
        frameRate = [];
    end

    methods
        function obj = FlickerRectangle()

            fxFile = 'FlickerRectangle.fx';
            filename = fullfile(fileparts(mfilename('fullpath')), fxFile);
            obj = obj@PixelShader(filename);
            obj.frameRate = StimServer.GetFrameRate();

            obj.period = obj.period;
            obj.color1 = obj.color1;
            obj.color2 = obj.color2;
            obj.shaderWidth = 500;
            obj.shaderHeight = 500;

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


        function set.period(obj, T)
            obj.setParameter(1, T);
            obj.period = T;
        end


    end
end
