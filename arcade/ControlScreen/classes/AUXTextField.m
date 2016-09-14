classdef AUXTextField %< handle
    % [AUXILLARY] TEXT FIELD (STATIC)
    % Takes in Numeric data, and txt handles
    % converts to string
    % method to append a string/char
    
    % SUBCLASSES 
    % AXS [AXS] AUXILLARY STATIC - not inherited 
    % HELPER METHODS 
    
    % there might be an issue here between 2014a/b
    % using the set method 
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    methods (Static = true)
        function this = AUXTextField
        end
    end
    
    methods (...
            Static = true,...
            Sealed = true)

        %# UPDATE WITH APPEND STRING/CHAR
        function mUpdateAppendString(txt_handle,value,appstr)
            strtxt = textscan(int2str(value),'%s'); 
            strtxt = strcat(strtxt{1},{appstr}); % e.g., '%'
            set(txt_handle,{'String'},strtxt);
        end
        
        %# UPDATE TEXT FIELD
        function mUpdateTextField(txt_handle,value)
            % need to get a better match up of handles to values 
            %value = randi([1,100],1,5);
            %get(txt_handle,{'Tag'})
            strtxt = textscan(num2str(value),'%s'); 
            %set(cell2mat(txt_handle),{'String'},strtxt{1}); 
            set(txt_handle,{'String'},strtxt{1}); 
        end
        
        %# CLEAR TEXT FIELD
        function mResetString(txt_handle)
            set(txt_handle,{'String'},{[]});
        end
        
    end
    
end


    
