classdef Stimulus < handle
    
    properties ( SetAccess = public, GetAccess = public )
        position = [0 0];
        visible = false;
    end
    
    properties ( SetAccess = immutable, GetAccess = public, Hidden = false )
        key
    end
        
    methods
        function obj = Stimulus                        
            Key = StimServer.ReadAck();
            assert(Key>0, 'Could not create stimulus')
            obj.key = Key;                        
        end
                
        function set.visible(obj, visible)
            StimServer.Command(obj.key, ...
                int8([0 visible])); 
            obj.visible = visible;
        end
        
        function set.position(obj, value)
            assert(numel(value)==2, 'Position must be 2-element vector')
            x = value(1);
            y = value(2);
            StimServer.Command(obj.key, ...
                [uint8(3) typecast(single([x y]), 'uint8')]);
            obj.position = value;
        end                
        
        function delete(obj)
            if ~isequal(obj.key, 0)
                StimServer.Command(obj.key, int8(0));
            end
        end
    end
end