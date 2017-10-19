classdef LinearRange < Animation
    % LINEARRANGE - Animation changing a scalar stimulus property linearily
    %
    % USAGE
    % -----
    %     a = LinearMotion(startValue, endValue, duration, mode)
    %
    % INPUT
    % -----
    %   startValue : value of parameter at beginning of animation
    %   endValue   : value of parameter at end of animation
    %   duration   : duration of animation in s
    %   mode       : integer parameter indicating the which stimulus parameter should change
    %       Pictures: mode=1 for alpha value
    %       PixelShader: mode=shader parameter number
    %           (see .fx or .m file of stimulus for mapping)
    %
    % EXAMPLE
    % -------
    %     g = Gaussian
    %     g.sdx = 100;
    %     g.angle = 45;
    %     g.color = [128 255 0];
    %     g.position = [100 50];
    %     g.visible = true
    %     a = LinearRange(0.1, 100, 2, 1)
    %     g.play_animation(a);
    %
    % See also Animation, Stimulus
    
    methods
        function obj = LinearRange(varargin)
            StimServer.Command(0, uint8([136 ...
                typecast(single(varargin{1}), 'uint8') ... start value
                typecast(single(varargin{2}), 'uint8') ... end value
                typecast(single(varargin{3}), 'uint8') ... duration/s
                varargin{4}]));                           % mode
            obj = obj@Animation();
        end
    end
    
end

