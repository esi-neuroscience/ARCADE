classdef Stimulus < hgsetget % will be matlab.mixin.SetGet after 2014b
    
    properties ( SetAccess = public, GetAccess = public )        
        visible = false;
        protected = false;
        position = [0 0];
        animation = [];
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
            StimServer.Command(obj.key, [0 visible]); 
            obj.visible = visible;
        end
        
        function set.position(obj, value)
            assert(numel(value)==2, 'Position must be 2-element vector')
            x = value(1);
            y = value(2);
            StimServer.Command(obj.key, ...
                [3 typecast(single([x y]), 'uint8')]);
            obj.position = value;
        end      
        
        function set.protected(obj, value)
           error('Not implemented yet') 
        end
        
        
        function set.animation(obj, animation)            
            if ~isempty(animation)
                StimServer.Command(animation.key, ...
                    [0 1 typecast(uint16(obj.key), 'uint8')])              
            elseif isempty(animation) && ~isempty(obj.animation)
                StimServer.Command(obj.animation.key, ...
                    [0 0 typecast(uint16(obj.key), 'uint8')])                
            end
            obj.animation = animation;
            
        end
        
        function delete(obj)
            if ~isequal(obj.key, 0)
                StimServer.Command(obj.key, 0);
            end
        end
    end
end