classdef (Abstract) EyeTarget < hgsetget
    %UNTITLED2 Summary of this class goes here
    %   Detailed explanation goes here
    
    properties ( SetAccess = private, GetAccess = public, Hidden = true, Transient = true )
        key
    end
    
    properties 
        position % Position in pixel relative to screen center
    end
    
    properties
    end
    
    methods
        function obj = EyeTarget
            Key = EyeServer.ReadAck();
            assert(Key>0, 'Could not create target.')
            obj.key = Key;
		  EyeServer.Command(obj.key, 1);	% force "Out" events on blinks
        end
        
% not implemented yet
%        function set.position(obj, value)
%            assert(numel(value)==2, 'Position must be 2-element vector')
%            x = value(1);
%            y = value(2);
%            EyeServer.Command(obj.key, ...
%                [3 typecast(single([x y]), 'uint8')]);
%            obj.position = value;
%        end
        
        function delete(obj)
            if ~isequal(obj.key, 0)
                EyeServer.Command(obj.key, 0);
            end
        end
        
        function SetFlags(flagBits)
            EyeServer.Command(obj.key, uint8([3 flagBits]));
        end
    end

end

