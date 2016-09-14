classdef HLOMaskedGrating < OBJPixelShader & SPCHighLevelObject
    % [HIGH LEVEL OBJECT]
    
    
    % INHERITANCE:
    % HLOMaskedGrating < ...
    %   OBJPixelShader < SPCObject < AUXPipeReadWrite < handle
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
    
    % TO DO:
    % - grating patch size
    % - ellipse vs circlular patch, separate fx files?
    
    %------------------------------------------%
    % 19.4.2016 - Jarrod, wrote class
    % 21.4.2016 - Jarrod, Tested and debugged

    properties (...
            AbortSet  = true,...
            SetAccess = private)
        fxFile     % file to use 
    end
    
    %# constructor
    methods (Static)
        function this = HLOMaskedGrating
            this.mCreateInputParser; % create input parser

            gratfxFile = 'Grating_maskLT1000p.fx'; % file for this stimulus 
            this.fxFile = fullfile(...
                fileparts(mfilename('fullpath')),'stimfiles','pixelShader', gratfxFile);
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
            obj = this.paramStruct;
            
            % create object in StimServer
            this.mCreateObject(this.fxFile);
            
            % set mask 
            for ki = 1:length(obj.maskRadii)
                this.mSetOptionalParameter(ki, obj.maskRadii(ki));
            end
            
            % set initial phase 
            this.mSetOptionalParameter(7, obj.phaseShift); 
            
            % set parameters
            initParams = {...
                'position', 'maskRotation', ...
                'pixelsPerCycle','pixelsPerFrame',...
                'direction', 'smoothing',...
                'color0','color1'};
            for ki = 1:length(initParams)
                this.setParameter(initParams{ki}, obj.(initParams{ki}));
            end
        end

        %# user accessible function
        function setParameter(this, param, value)
            % switch statement
            paramStrings = {...
                'maskRotation',...
                'pixelsPerCycle',...
                'direction',...
                'smoothing',...
                'phaseShift'};

            switch param
                case 'visible'
                    this.visible(value);
                case 'position'
                    this.mSetPosition(value);
                case {'color0','color1'}
                    idx = str2double(param(end))+1;
                    this.mSetColor(idx,value); 
                case 'pixelsPerFrame'
                    this.mSetAnimationIncrement(value);  
                case paramStrings
                    idx = find(strcmp(param,paramStrings))+2;
                    this.mSetOptionalParameter(idx, value); 
                otherwise
                    error(['Unknown parameter: ', param]);
            end
             
        end
    end
    %# sealed/private methods
    methods (Access = protected)
        % input validation
        function mCreateInputParser(this)
            %---------------------------------------%
            %           create defaults
            def =  [];
            def.position       = [0,0];             % [x,y] position
            def.color0         = [  0,  0,  0,255]; % [r,g,b,w] [0...255] color when sinewave is 0 
            def.color1         = [255,255,255,255]; % [r,g,b,w] [0...255] color when sinewave is 1
            def.pixelsPerCycle = 20;                % [>=1] pixels per cycle of grating 
            def.direction      = 0;                 % direction of movement (orthogonal to orientation)
            def.pixelsPerFrame = 0;                 % each frame shift by N pixels
            def.phaseShift     = 0;                 % grating degrees
            def.smoothing      = 2;                 % sinewave == 2, values greater tend to squarewave ~10 
            def.maskRadii      = 100;               % circle mask [x,y] elliptical 
            def.maskRotation   = 0;                 % degrees

             
            validateColor  = @(x) isnumeric(x) && isrow(x) && length(x)==4 && all(x>=0 & x<=255);
            validateScalar = @(x) isnumeric(x) && length(x)==1;
            
            val =  [];
            val.position       = @(x) isnumeric(x) && isrow(x) && length(x)==2;
            val.color0         = validateColor;
            val.color1         = validateColor;
            val.pixelsPerCycle = @(x) isnumeric(x) && length(x)==1 && x>=1;
            val.direction      = validateScalar;
            val.pixelsPerFrame = validateScalar;
            val.phaseShift     = validateScalar;
            val.smoothing      = @(x) isnumeric(x) && length(x)==1 && (x>=2 && x<=100); % 10 is probably enough
            val.maskRadii      = @(x) isnumeric(x) && any(length(x)==[1,2]) && all(x>0);
            val.maskRotation   = validateScalar;

            
            funcName = 'createObject(''MaskedGrating'',params)';
            this.mStructToInputParser(funcName, def, val);
        end
    end
end

