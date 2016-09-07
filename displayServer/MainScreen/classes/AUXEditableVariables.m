classdef AUXEditableVariables < handle
    % [AUXILLARY] EDITABLE VARIABLES
    
    
    % + convert cellmat to struct
    % + convert struct to cellmat
    % + error check: (cell edit callback)
    % + check input varname
    % + check input editable variable 
    % + //store index in userdata (selection callback)
    
    
    % NOTE: not all functions here are used (cleanup) 
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    %# constructor 
    methods (Static)
        function this = AUXEditableVariables
        end
    end

    methods (Access = protected)
        function mSetEdVarCfg(this,cellmat)
            % every tome the CellEdit is called
            % - get the complete rows
            % - create a structure
            % - set the cfg
            
            [newCellmat,completeRows] = this.mFindCompleteRows(cellmat);
            if any(completeRows)
                % set cfg structure
                strct = this.mCellmat2Struct(newCellmat);
                this.cfg.EditableVariables = strct; % set cfg
            end
        end
    end
    
    
    methods (...
            Static = true,...
            Access = protected)
        %# convert structure to cellmat
        %--------------------------------%
        % used to convert a structure into
        % a cellmatrix that is used to set
        % the data field of the uitable
        %--------------------------------%
        function cellmat = mStruct2Cellmat(strct)
            % 'VariableName', 'Value', 'Class'
            ncols = 3;                      % number of columns
            
            evNames = fieldnames(strct);    % get fieldnames
            nrows   = length(evNames);      % number of fields
            cellmat = AUXEditableVariables.mEmptyCell(nrows,ncols); 
            %cellmat = cell(nrows,ncols);    % empty cellmat
            
            for k = 1:nrows
                fname = evNames{k};
                value = strct.(fname);
                
                % determine type
                evClass = {'Numeric', 'Logical', 'Text'};
                evType  = [isnumeric(value), islogical(value), ischar(value)];
                
                % if Numeric or Logical convert from string to
                if any(strcmp(evClass(evType),{'Numeric', 'Logical'}))
                    value = num2str(value);
                end
                
                cellmat{k,1} = fname;            % 'VariableName'
                cellmat{k,2} = value;            % 'Value'
                cellmat{k,3} = evClass{evType};  % 'Class'
            end
        end
        
        %# cellmat to struct
        %--------------------------------%
        % used to convert ia cellmat
        % into a struct which is stored
        % in the cfg
        %--------------------------------%
        function strct = mCellmat2Struct(cellmat)
            tclass = cellmat(:,3);
            values = cellmat(:,2);
            fields = cellmat(:,1);
            
            % convert value [v] to class [c]
            cnvtValues = @(v,c) AUXEditableVariables.mConvert2Typeclass(v,c);
            
            % convert values
            cvalue = cellfun(@(v,c) cnvtValues(v,c), values, tclass,'unif',0);
            
            strct = cell2struct(cvalue,fields,1);
        end
        
        %--------------------------------%
        %       ERROR CHECKING:
        %--------------------------------%
        %# check if editable vars are appropriately specified 
        function validVars = mCheckEditableVariableStruct(evStruct)
            %-----------------------------------------%
            % INPUT: struct
            % Check Editable Variables (EV):
            % - Length: an EV should not be longer than 1
            %   unless it is a string
            % - Class: must be one of char, logical, or numeric 
            % validClasses = {'Numeric', 'Logical', 'Text'};
            %-----------------------------------------%
            
            % input variable length
            varLength = structfun(@length,evStruct);
            
            % must be one of these
            varNumbr = structfun(@isnumeric,evStruct);
            varLogic = structfun(@islogical,evStruct);
            varChar  = structfun(@ischar,   evStruct);
            
            % test for conditions 
            validVars = (...
                (varNumbr | varLogic | varChar)...
                & (varLength == 1 | varChar));
        end
        
        %**********************************************
        %# [UITABLE] Cell Edit Editable Variables callback
        function mCellEditEdVarCallback(hObj,evtData)
            %----------------------------------%
            % check input:
            % if the edit renders the cell empty
            % -> replace with previous input
            % otherwise use the appropriate check variable function
            % if the input is not valid
            % -> replace with previous input
            %----------------------------------%
            flag_revert2previous = false;
            
            prevData = evtData.PreviousData; % previous input (single value)
            newData  = evtData.NewData;      % new input (single value)
            
            % get index of change
            indx = evtData.Indices; % [row col]
            
            if isempty(newData)
                % if nothing is entered replace with old
                flag_revert2previous = true;
            else
                % check type -> user inputs
                % **multiple inputs
                switch indx(2) % handle multiple inputs 
                    case 1
                        % var name [true if valid, false if not]
                        % flip truth for flag [revert if ~valid]
                        flag_revert2previous = ~AUXEditableVariables.mCheckValidVariableName({newData});
                    case {2, 3}
                        % value
                        currData  = get(hObj,'data'); % current [incl. modified value] data
                        
                        value     = currData{indx(:,1),2}; % column 2 = value
                        typeclass = currData{indx(:,1),3}; % column 3 = type class
                        
                        % if both not empty
                        % the moment the typeclass can't be empty
                        % but I might change this
                        % *only checks if both are not empty
                        % *currently no check if type class set 
                        % perhaps think of implementing a warning instead
                        if all([~isempty(value),~isempty(typeclass)])
                            % returns true if valid, 
                            % if ~valid, flag true
                            flag_revert2previous = ~AUXEditableVariables.mCheckValidVariable(value,typeclass);
                        end
                    otherwise
                        % should not happen ever
                end % end of switch
            end
            
            % input error, revert to previous
            if flag_revert2previous
                %AUXEditableVariables.revert2previous(hObj,indx,prevData);
                % if nothing is entered replace with old
                currData = get(hObj,'data'); % current [modified] data
                currData(indx(:,1),indx(:,2)) = {prevData};
             
                % revert to previous data
                set(hObj,'data',currData);
            end
            
            %getPropfunc = get(hObj,'getPropertyFcn');
            
            %getPropfunc(get(hObj,'data'));
        end

        %# ERROR CHECK: is valid field name
        function result = mCheckValidVariableName(varName)
            
            %varName = {'kdhjdh','1081','1jhfjhf','k','jhsjhs9','h#kjsk','kjs ,'};
            
            n = length(varName);
            result = true(n,1);
            
            S = [];
            for k = 1:n
                try
                    S.(varName{k}) = [];
                catch
                    disp('error');
                    result(k) = false;
                end
            end
        end
        
        %# ERROR CHECKING: is input valid type
        function result = mCheckValidVariable(value,typeclass)
            % use convert to specific type function 
            % returns a nan if there is an error
            % if ~nan = valid, else invalid
            result = ~isnan(AUXEditableVariables.mConvert2Typeclass(value,typeclass));
        end
        %--------------------------------%
        
        
        %# Convert value to a specific type
        function out = mConvert2Typeclass(value,typeclass)
            %--------------------------------%
            % convert a given [value] (single value)
            % into the desiered output [typeclass]
            % if error(s), return Nan(s)
            %--------------------------------%
            
            % input type class
            validClasses = {'Numeric', 'Logical', 'Text'};
            valueType    = [isnumeric(value), islogical(value), ischar(value)];
            
            % ____check if type is valid____ %
            if  ~any(strcmp(typeclass,validClasses)) || ~any(valueType)
                % value or type to convert to is unrecognized
                out = nan(1);
                return;
            elseif strcmp(typeclass,validClasses) == valueType %#ok<BDSCI>
                % value is already desired type
                out = value;
                return
            end
            
            % ______ convert value to -> ______ %
            if xor(isnumeric(value), islogical(value))
                % Logical/Numeric -> Text (and not already char)
                % Logical         -> Numeric
                % Numeric         -> Logical
                
                switch typeclass
                    case 'Text'
                        out = num2str(value);
                    case 'Logical'
                        out = logical(value);
                    case 'Numeric'
                        out = double(value);
                end
            elseif ischar(value) && any(strcmp(typeclass, {'Numeric', 'Logical'}))
                % Text -> Logical/Numeric
                try
                    out = eval(value);
                    % catch cases where the text is converted
                    % to a double instead of logical
                    if strcmp(typeclass,'Logical')
                        out = logical(out);
                    end
                catch
                    % error converting to Numeric/Logical
                    out = nan(1);
                end
            end
        end

        
        %# resize the table width
        % depends on the number of rows
        % subtracts or adds pixels to the 1st column
        function mAdjustTableWidth(hTbl,mxRows,new,prev)
            % resize the width of the 1st column [varName]
            %colWidth = {156,75,85};
            %colWidth = {140,75,85};
            %hObj = AUXEditableVariables.getObjectHandle;
            
            % the scroll bar requires 16 pixels
            scrollWidth = 16;
            
            % parsimoniously adjust
            colWidth    = get(hTbl,'ColumnWidth');
            newColWidth = colWidth;
            
            if new>mxRows && prev<=mxRows
                % reduce column width to allow for scroll bar
                scrollWidth = -scrollWidth;
            elseif new<=mxRows && prev>mxRows
                % increase row width to fill whole table
                %scrollWidth = scrollWidth;
            else
                %scrollWidth = 0;
                return; % do nothing
            end
            newColWidth{1} = colWidth{1}+scrollWidth;
            set(hTbl,'ColumnWidth',newColWidth);
            
        end

        %# set selected indicies callback 
        %function set
        %{
        %# get UITABLE handle 
        % - if in callback, use callback figure
        % - else try current figure
        function hObj = getObjectHandle
            % try finding figure of callback object 
            hObj = findobj(gcbf,'Tag','tbl_EditableVars');
            if isempty(hObj)
                % if empty, try current figure
                hObj = findobj(gcf,'Tag','tbl_EditableVars');
            end
        end
        %}
        %# create an empty cell 
        function newcell = mEmptyCell(varargin)
            % necessary because Matlab sucks!
            newcell = arrayfun(@(x) '',cell(varargin{:}),'unif',0);
        end
        
        %# find complete rows in cellmat
        function [newCellmat,completeRows] = mFindCompleteRows(cellmat)
            % find rows with all values entered
            notEmpty     = ~cellfun(@isempty,cellmat);
            completeRows = all(notEmpty,2);
            newCellmat   = cellmat(completeRows,:);
        end
        
        
        
    end % end of methods 

end


