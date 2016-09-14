classdef AUXPropertyManager < hgsetget
    % [AUXILLARY] PROPERTYMANAGER
    % - sets properties of subclass 
    % - accepts input as struct or cell {'name',value} pairs
    
    % 2014a and earlier -> hgsetget
    % 2014b and later   -> matlab.mixin.SetGet
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    
    methods(Static = true)
        function this = AUXPropertyManager
        end
    end
   % Hidden = true,...
    methods (...
            Access = protected,...
            Sealed = true)
        function mSetProperties(this,props)
            % input can be: struct, or 'name', value pairs
            % note: passing in a struct seems to be slightly faster
            if mod(numel(props),2) == 0
                pn = props(1:2:end-1);
                pv = props(2:2:end);
            else
                if isstruct(props{1}) && numel(props) == 1
                    pn = fieldnames(props{1})';
                    pv = struct2cell(props{1})';
                else
                    error('Input must be a struct, or (''name'', value) pairs.');
                end
            end
            set(this,pn,pv);
        end
    end
end

