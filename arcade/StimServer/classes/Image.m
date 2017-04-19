classdef Image < Stimulus
    
    properties ( SetAccess = immutable )
        filename
    end
    
    properties ( SetAccess = public, GetAccess = public )
        alpha = 255;
        angle = 0;
    end            
    methods
        function obj = Image(filename)      
            assert(exist(filename, 'file') == 2, 'Image %s file not found', filename)
            StimServer.Command(0, uint8([2 filename 0]));
            obj = obj@Stimulus();
            obj.filename = filename;
        end
        
        function set.alpha(obj, alpha)
            assert(alpha>=0 && alpha <=255, 'Image alpha value must between 0 (transparent) and 255 (opaque)')
            StimServer.Command(obj.key, uint8([1 alpha]));
            obj.alpha = alpha;
        end
                
        function set.angle(obj, angle)
            assert(angle>=0 && angle <360, 'Image angle must between 0 and 360 (counter-clockwise)')
            StimServer.Command(obj.key, ...
                uint8([4 typecast(single(angle), 'uint8')]));
            obj.angle = angle;
        end        
        
    end
end