classdef LinearMotion < Animation
    
    properties ( SetAccess = immutable, Transient = true )       
       velocity = []; % px / s
    end
    
    properties ( Transient = true )
       vertices = []; 
    end
    
    methods
        function obj = LinearMotion(velocity, vertices)
            StimServer.Command(0, uint8([132 typecast(uint16(velocity),'uint8')]));
            obj = obj@Animation();
            obj.velocity = velocity;            
            obj.vertices = vertices;
        end
    
        function set.vertices(obj, vv)
            StimServer.Command(obj.key, [uint8(11), typecast(int16(vv),'uint8')])
            obj.vertices = vv;
        end
        
    end
    
    
end