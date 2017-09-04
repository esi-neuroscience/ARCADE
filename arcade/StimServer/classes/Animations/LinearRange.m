classdef LinearRange < Animation
    % subclass of Animation changing a value linearily 
    %
        
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

