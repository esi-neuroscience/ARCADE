classdef CircularEyeTarget < EyeTarget
    %UNTITLED Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        
        
        radius
        name
    end
    
    methods
        function obj = CircularEyeTarget(x, y, r, name)
            EyeServer.Command(0, uint8([1 typecast(single([x y r]), 'uint8') name 0]));
            obj = obj@EyeTarget();
            obj.position = [x y];            
            obj.radius = r;
            obj.name = name;
        end
        
        function SetSize(obj,Radius)
            EyeServer.Command(obj.key, uint8([4, typecast(single(Radius), 'uint8')]));
            obj.radius = Radius;
        end

    end
    
end

