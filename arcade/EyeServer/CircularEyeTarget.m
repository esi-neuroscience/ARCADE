classdef CircularEyeTarget < EyeTarget
    %UNTITLED Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        x
        y
        radius
        name
    end
    
    methods
        function obj = CircularEyeTarget(x, y, r, name)
            EyeLinkServer.Command(0, uint8([1 typecast(single([x y r]), 'uint8') name 0]));
            obj = obj@EyeTarget();
        end
    end
    
end

