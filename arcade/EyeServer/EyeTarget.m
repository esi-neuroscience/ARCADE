classdef (Abstract) EyeTarget < hgsetget
    %UNTITLED2 Summary of this class goes here
    %   Detailed explanation goes here
    
    properties ( SetAccess = private, GetAccess = public, Hidden = true, Transient = true )
        key
    end
    
    properties ( Dependent = true )
        position % Position in pixel relative to screen center
    end
    
    properties
    end
    
    methods
        function obj = EyeTarget
            Key = EyeLinkServer.ReadAck();
            assert(Key>0, 'Could not create target.')
            obj.key = Key;
        end
        
        function set.position(obj, value)
            assert(numel(value)==2, 'Position must be 2-element vector')
            x = value(1);
            y = value(2);
            EyeLinkServer.Command(obj.key, ...
                [3 typecast(single([x y]), 'uint8')]);
        end
        
        function delete(obj)
            if ~isequal(obj.key, 0)
                EyeLinkServer.Command(obj.key, 0);
            end
        end       
    end

end

