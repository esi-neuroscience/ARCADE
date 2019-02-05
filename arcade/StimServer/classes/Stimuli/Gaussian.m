classdef Gaussian < PixelShader
    % GAUSSIAN < PixelShader < Stimulus - Gaussian patch for ARCADE
    %
    % Shader file: <a href="matlab:edit('Gaussian.fx')">SquareWaveGrating.fx</a>
    %
    % PROPERTIES
    % -----------
    %   color : 24-bit color [r g b]
    %   angle : counter-clockwise rotation of patch (degree);  0=horizontal, 90=vertical
    %   sdx   : standard deviation in x-direction (pixel) for angle=0
    %   sdy   : standard deviation in y-direction (pixel) for angle=0
    %
    % Note: The width and height of the PixelShader always at least 5*max(sdx, sdy).
    %
    % For more information, see <a href="matlab:doc('arcade')">the ARCADE guide</a> and the superclasses.
    %
    % See also PixelShader, Stimulus


    properties ( Transient = true )
        color = [255 255 255]; % color as 24-bit [r g b] value
        angle = 0; % rotation in degrees, 0=horizontal, 90=vertical
        sdx = 5; % standard deviation in x-direction in pixels
        sdy = 5; % standard deviation in y-direction in pixels
    end

    methods
        function obj = Gaussian()
            % file for this stimulus
            gratfxFile = 'Gaussian.fx';
            filename = fullfile(...
                fileparts(mfilename('fullpath')), gratfxFile);
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