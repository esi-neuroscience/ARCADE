classdef AUXInputParser < handle
    % [AUXILLARY]
    
    % PURPOSE: 
    %   - create parser
    %   - add property to parser
    
    %------------------------------------------%
    % 19.4.2016 - Jarrod, wrote function
    % 26.4.2016 - Jarrod, 
    %  - added the method: mAddRequiredToExistingParser()
    %    ** not fully implemented **
    
    properties (...
            AbortSet  = true,...
            SetAccess = private)
        parserObj     % parser object
        paramStruct   % parser results 
        usingDefaults % cell of strings 
        %paramRequired % required parameters 
    end

    %# constructor
    methods (Static)
        function this = AUXInputParser
        end
    end
    
    methods (...
            Sealed = true,...
            Access = protected)
        %# parse input 
        % idea here would be to add in some 
        % memory of changes to the inputs
        function mParseInput(this, varargin)
            % to use requireds this would have to be modified 
            parse(this.parserObj, varargin{:});          % parse inputs
            this.paramStruct   = this.parserObj.Results; % set the params
            this.usingDefaults = this.parserObj.UsingDefaults;
        end
        
        %# add parameter to existing parser object
        function mAddParameterToExistingParser(this, funcName, defStruct, valStruct)
            this.mStructToInputParser(funcName, defStruct, valStruct, this.parserObj);
        end
        
        %# add required input 
        function mAddRequiredToExistingParser(this, reqString, reqValid)
            % required are not input with matched strong/values pairs
            % but they do require a reference string
            % because order is important, they are added one at a time
            % to ensure the order
            if ~isempty(reqValid)
                addRequired(this.parserObj, reqString, reqValid);
            else
                addRequired(this.parserObj, reqString);
            end
            % add the field to the required structure 
            this.paramRequired.(reqString) = [];
        end

        %# take struct input and create an Input Parser 
        % 1. creates input parser if it does not exist 
        % 2. add parameters to an existing parser
        function mStructToInputParser(this, funcName, defStruct, valStruct, varargin)
            
            % create instance of parser
            if isempty(varargin) 
                p = inputParser; 
            else
                p = varargin{1};
            end
            % add a function name for the error string
            if ~isempty(funcName), p.FunctionName = funcName; end;
            % catch no input, or only funcName input
            if ~isempty(defStruct)
                % name-value pairs
                paramNames = fieldnames(defStruct);
                paramValid = false(length(paramNames),1);
                if ~isempty(valStruct)
                    % flag params that have a validate method
                    paramValid = ismember(paramNames, fieldnames(valStruct));
                end
                
                % add parameters
                for k = 1:length(paramNames)
                    pString = paramNames{k};
                    default = defStruct.(pString);
                    if paramValid(k)
                        checkInput = valStruct.(pString);
                        addParameter(p, pString, default, checkInput);
                    else
                        addParameter(p, pString, default);
                    end
                end
            end
            this.parserObj = p;
        end
    end
end

