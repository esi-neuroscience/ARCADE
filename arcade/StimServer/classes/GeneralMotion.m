classdef GeneralMotion < Animation
    
    properties ( SetAccess = immutable )
       filename = [];
    end
    
    methods
        function obj = GeneralMotion(filename)
            StimServer.Command(0, uint8([130 filename]))
            obj = obj@Animation();
            obj.filename = filename;            
        end
        
    end
    
    
end