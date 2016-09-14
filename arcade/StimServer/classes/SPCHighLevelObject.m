classdef SPCHighLevelObject < AUXInputParser
    % [SUPERCLASS]
    
    % define how an HLO should look 
    
    % INHERITANCE:
    %   SPCHighLevelObject < ...
    %       AUXInputParser < handle

    % PROPERTIES: 
    %   + parserObj     % parser object
    %   + paramStruct   % parser results 
    %   + usingDefaults % cell of strings
    
    % METHODS: 
    %   + mParseInput
    %   + mAddParameterToExistingParser
    %   + mStructToInputParser
    
    %------------------------------------------%
    % 20.4.2016 - Jarrod, wrote class 
    
    % Public 
    methods (Abstract = true)
        createStimulus(this, varargin);
        setParameter(this, param, value);
    end
    
    % "private"
    methods (...
            Abstract = true,...
            Access   = protected)
        % define parameters (structs) for input validation
        mCreateInputParser(this)
    end
end
