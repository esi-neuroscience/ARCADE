classdef AUXGUIMethods < handle
    % AUXILLARY 
    % - holds methods general to GUIs 
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    methods (Static)
        function this = AUXGUIMethods
        end
    end
    
    methods (...
            Sealed = true,...
            Static = true)
        %# SET GUI DATA 
        % input = data structure
        % *overwrite field if it already exists
        % otherwise, add to existing structure
        function setGUIdata(hfig,data)
            
            % is there data
            if isempty(data), return; end;
            
            % get current gui data
            gdata = guidata(hfig);
            % add new data 
            for f = fieldnames(data)'
                gdata.(f{1}) = data.(f{1}); % overwrite if exists  
            end
            % store in figure
            guidata(hfig,gdata);
        end
        
        function setUserData(obj,data)
            % check input data
            % get current data
            % add new data
            if isempty(data), return; end;
            gdata = get(obj,'UserData');
            
            
            
        end
        
    end
    
    
    methods (...
            Sealed = true,...
            Static = true,...
            Access = private)
        %# create data structure by combining structs 
        function gdata = createDataStruct(data,gdata)
 
            % get fieldnames of input struct
            % add to gdata struct,
            % ** overwrites if fieldname exits in gdata already **
            for f = fieldnames(data)'
                gdata.(f{1}) = data.(f{1}); 
            end
        end
    end
    
    
    
    
end














