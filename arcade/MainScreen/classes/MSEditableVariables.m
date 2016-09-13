classdef MSEditableVariables < AUXEditableVariables
    % [MAIN SCREEN] EDITABLE VARIABLES
    
    
    % INHERITANCE: 
    %   MSEditableVariables < AUXEditableVariables < handle
    
    
    % METHODS: MSEditableVariables
    % + mInitEditableVariables(this)
    % + mAddNewEdVarCallback(this,~,~,hTbl)
    % + mRemoveEdVarCallback(this,~,~,hTbl)
    % + mClearEdVarCallback(this,~,~,hTbl)

    
    % 1/2 ms to get the
    % Elapsed time is 0.000644 seconds.
    % Elapsed time is 0.000682 seconds.
    % Elapsed time is 0.000675 seconds.
    
    %# Main GUI Editable Variable 
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote initial class
    % 2.3.2015, - Jarrod, 
    %    - editted the button callback to fixed a bug in the gui
    % 21.4.2016 - Jarrod, added some documentation/notes

    
    properties (Access = private)
        % number of variable rows 
        maxVarRows = 6; % >maxVarRows resize column
    end
    
    methods (Static)
        function this = MSEditableVariables
        end
    end
    
    methods 
        %# init Editable Variables 
        function mInitEditableVariables(this)

            % handle to Editable Variable Table
            hTbl = findobj(this.hfig,'Tag','cfg_EditableVariables');

            % Set Cell Selection Callback
            %set(hTbl,'CellSelectionCallback',@(hObj,evt) set(hObj,'UserData',evt.Indices));
            % set Cell Edit Callback
            %set(hTbl,'CellEditCallback',@(hObj,evt) this.cellEditEdVarCallback(hObj,evt));
            
            
            % set button callbacks
%             hEdVarButtons = findobj(this.hfig,{'Tag'},...
%                 {...
%                 'btn_AddNewEditVar';...
%                 'btn_RemoveEditVar';...
%                 'btn_ClearEditVars'});
            
            findButton = @(tag) findobj(this.hfig,'Tag',tag);

            % add an editable variable 
            set(findButton('btn_AddNewEditVar'),...
                'Callback',@(hObj,evt) this.mAddNewEdVarCallback(hObj,evt,hTbl));
            % remove selected editable variable
            set(findButton('btn_RemoveEditVar'),...
                'Callback',@(hObj,evt) this.mRemoveEdVarCallback(hObj,evt,hTbl));
            % clear all 
            set(findButton('btn_ClearEditVars'),...
                'Callback',@(hObj,evt) this.mClearEdVarCallback(hObj,evt,hTbl));
  
            % load
        end
    end
    
    methods (Sealed = true)
        %---------------------------------------------%
        %# [UIBUTTON] Add New Editable Variable
        function mAddNewEdVarCallback(this,~,~,hTbl)
            %hObj = AUXEditableVariables.getObjectHandle;

            % get object data
            objData = get(hTbl,'data');
            
            nRows   = size(objData,1);  % current number of rows 
            newRows = nRows+1;          % add a row
            % create new empty data
            %newData = cell(nRows+1,3);
            newData = AUXEditableVariables.mEmptyCell(nRows+1,3);
            
            if ~isempty(objData)
                % if previous was not empty add it back 
                newData(1:end-1,:) = objData;
            end
            % set new data
            set(hTbl,'data',newData);
            
            % check if nvars > maxVariables
            % table handle, max rows, new, prev
            AUXEditableVariables.mAdjustTableWidth(hTbl,this.maxVarRows,newRows,nRows)
        end
        
        %# [UIBUTTON] Remove Selected Editable Variable(s)
        function mRemoveEdVarCallback(this,~,~,hTbl)
            %hObj = AUXEditableVariables.getObjectHandle;
            
            % get selected, and object data
            %objData = get(hTbl,{'UserData','data'});
            indices = get(hTbl,'selectedIndices');
            objData = get(hTbl,'data');
            
            if isempty(indices), return; end; % cannot remove if no indices are selected
            
            nRows = size(objData,1); % current number of rows in data
            
            if ~isempty(objData)
                selectedRows = indices(:,1);         % get selected rows
                
                newRows = nRows - length(selectedRows); % number of new rows 
                
                if newRows<1
                    newData = AUXEditableVariables.mEmptyCell(1,3);
                    %newData = cell(1,3);
                else
                    % remove selected rows
                    newData = objData;
                    newData(selectedRows,:) = [];
                end
                
                % set new data
                set(hTbl,'data',newData);

                % check if nvars > maxVariables
                % table handle, max rows, new, prev
                AUXEditableVariables.mAdjustTableWidth(hTbl,this.maxVarRows,newRows,nRows)
            end
        end
        
        %# Clear All Editable Variables
        function mClearEdVarCallback(this,~,~,hTbl)
            
            nRows   = size(get(hTbl,'data'),1);  % current number of rows 
            newRows = 0;                         % remove all rows 
            newData = AUXEditableVariables.mEmptyCell(1,3);
            set(hTbl,'data',newData);

            % table handle, max rows, new, prev
            AUXEditableVariables.mAdjustTableWidth(hTbl,this.maxVarRows,newRows,nRows);
        end
        
        
        %# [UIBUTTON] Load 
        
        
        %---------------------------------------------%
  
        
    end
    
    
end






