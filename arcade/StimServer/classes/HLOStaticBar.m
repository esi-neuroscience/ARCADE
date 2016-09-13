classdef HLOStaticBar < OBJRectangle & SPCHighLevelObject
    % [HIGH LEVEL OBJECT]
    
    
    % INHERITANCE:
    % HLOStaticBar < ...
    %   OBJRectangle < SPCObject < AUXPipeReadWrite < handle
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

    %# constructor
    methods (Static)
        function this = HLOStaticBar
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
            this.mCreateObject;
            
            %setParams = fieldnames(obj);
            setParams = {...
                'position', 'color',...
                'widthHeight', 'orientation'};
            for ki = 1:length(setParams)
                if ~any(strcmp(setParams{ki},useDefs))
                    this.setParameter(setParams{ki}, obj.(setParams{ki}));
                end
            end
        end
        
        %# user accessible function
        function setParameter(this, param, value)
            switch param
                case 'visible'
                    this.visible(value);
                case {'position','barPosition'}
                    this.mSetPosition(value);
                case {'color','barColor'}
                    this.mSetColor(value);
                case {'widthHeight','barWidthHeight'}
                    this.mSetWidthHeight(value);
                case {'orientation','barOrientation'}
                    this.mSetOrientation(value);
                otherwise
                    error(['Unknown parameter: ', param]);
            end
        end
    end

    %# "private" methods
    methods  (Access = protected)
        % input validation
        function mCreateInputParser(this)
            %---------------------------------------%
            %           create defaults
            def =  [];
            def.position      = [0,0];             % [x,y] position 
            def.widthHeight   = [11,21];           % pixels >=1
            def.orientation   = 0;                 % degrees 
            def.color         = [255,255,255,255]; % rgbw 

            val =  [];
            val.position      = @(x) isnumeric(x) && isrow(x) && length(x)==2;
            val.widthHeight   = @(x) isnumeric(x) && isrow(x) && length(x)==2 && all(x>=1);
            val.orientation   = @(x) isnumeric(x) && isscalar(x);
            val.color         = @(x) isnumeric(x) && isrow(x) && length(x)==4 && all(x>=0 & x<=255);
 
            funcName = 'createObject(''StaticBar'',params)';
            this.mStructToInputParser(funcName, def, val);
        end
    end
end

