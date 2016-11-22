classdef HLOFilledDot < OBJSymbol & SPCHighLevelObject
    % [HIGH LEVEL OBJECT]
    
    
    % INHERITANCE:
    % HLOFilledDot <  ...
    %   OBJSymbol < SPCObject < AUXPipeReadWrite < handle
    %   SPCHighLevelObject < AUXInputParser < handle
    
    % PROPERTIES: 
    %   + parserObj     % parser object
    %   + paramStruct   % parser results 
    %   + usingDefaults % cell of strings
    
    % METHODS: 
    %   + mParseInput
    %   + mAddParameterToExistingParser
    %   + mStructToInputParser
    
    % ABSTRACT METHODS: [SPCHighLevelObject]
    %   + createStimulus(this, varargin)
    %   + setParameter(this, param, value)
    %   + mCreateInputParser(this)
    
    %------------------------------------------%
    % 19.4.2016 - Jarrod, wrote class 
    % 21.4.2016 - Jarrod, Tested and debugged

    %# constructor
    methods (Static)
        function this = HLOFilledDot
            this.mCreateInputParser; % create input parser
        end
    end
    
    
    % inherited Public methods
    methods 
        %# create stimulus object
        function createStimulus(this, varargin)
            % parse input params
            this.mParseInput(varargin{:});

            % set parameters
            % always set all parameters
            obj     = this.paramStruct;
            useDefs = this.usingDefaults;
            
            % create object in StimServer
            % mCreateObject(this, symType, symSize)
            this.mCreateObject(1, obj.diameter);

            % set position
            if ~any(strcmp('position', useDefs))
                this.mSetPosition(obj.position);
            end
            
            % set dot color
            if ~any(strcmp('color', useDefs))
                this.mSetColor(obj.color);
            end
        end
        
        %# user accessible function
        function setParameter(this, param, value)
            switch param
                case 'visible'
                    this.visible(value);
                case 'position'
                    this.mSetPosition(value);
                case {'color'}
                    this.mSetColor(value);
                case {'diameter'}
                    this.mSetDiameter(value);
                otherwise
                    error(['Unknown parameter: ', param]);
            end
        end
    end

    %#
    methods (Access = protected)
        % input validation
        function mCreateInputParser(this)
            %---------------------------------------%
            %           create defaults
            def =  [];
            def.position           = [0,0];               % [x,y] position
            def.diameter           = 6;                   % >=1
            def.color              = [255,255,255,255];   % [r,g,b,w] [0..255]
            
            val =  [];
            val.position        = @(x) isnumeric(x) && isrow(x) && length(x)==2;
            val.diameter        = @(x) isnumeric(x) && isscalar(x) && (x >= 1);
            val.color           = @(x) isnumeric(x) && isrow(x) && length(x)==4 && all(x>=0 & x<=255);
            
            funcName = 'createObject(''FilledDot'',params)';
            this.mStructToInputParser(funcName, def, val);
        end
    end
end

