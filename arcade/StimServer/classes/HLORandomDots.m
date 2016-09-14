classdef HLORandomDots < OBJParticleStimulus & SPCHighLevelObject
    % [HIGH LEVEL OBJECT]
    
    % validateattributes
    % validatestring
    % inputParser

    % deletes file when done
    
    
    % INHERITANCE:
    % HLORandomDots <  ...
    %   OBJParticleStimulus < SPCObject < AUXPipeReadWrite < handle
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
    %                  To Do
    % animation value
    % this.mSetAnimationValue(this, value)
    
    %------------------------------------------%
    % 16.4.2016 - Jarrod, wrote class 
    % 21.4.2016 - Jarrod, Tested and debugged

    properties (...
            AbortSet  = true,...
            SetAccess = private)
        objParticleFile   % filepath for random dots
        objWidthHeight    % size of object created
    end

    %# constructor
    methods (Static)
        function this = HLORandomDots
            this.mCreateInputParser; % create input parser
        end
    end
    
    %# redefine delete method 
    methods
        function delete(this)
            %disp('delete file...');
            delete(this.objParticleFile);
            delete@OBJParticleStimulus(this); % call super class delete
        end
    end
    
    % inherited Public methods
    methods (Sealed = true)
       %# create stimulus object
        function createStimulus(this, varargin)
            % parse input params
            this.mParseInput(varargin{:});
            
            % fetch parameters 
            obj     = this.paramStruct;
            useDefs = this.usingDefaults;
            
            % calculate size of stimulus
            this.objWidthHeight = ones(1,2) * obj.maskDiameter;
            
            % create stimulus position file 
            this.mCreateParticleFile;
            % create object in StimServer
            this.mCreateObject(this.objWidthHeight, this.objParticleFile);
            
            % --- set parameters --- %
            % set position
            if ~any(strcmp('position', useDefs)),    this.mSetPosition(obj.position); end;
            % set dot color
            if ~any(strcmp('dotColor', useDefs)),    this.mSetColor(obj.dotColor); end;
            % set dot size
            if ~any(strcmp('dotDiameter', useDefs)), this.mSetDiameter(obj.dotDiameter); end;
            
            % set velocity
            if ~any(strcmp('dotPixelsPerFrame', useDefs))
                % velocity is normalize to the radius of the object
                % thus the multiplication by 2
                this.mSetVelocity(2*obj.dotPixelsPerFrame/this.objWidthHeight(1));
            end
            
            % set direction
            if ~any(strcmp('dotDirection', useDefs))
                % velocity is normalize to the radius of the object
                this.mSetDirection(obj.dotDirection);
            end
            
            % set mask
            switch obj.maskType
                case 'circle'
                    % normalized to the raidus
                    % account for the diamter of the dots
                    % because they are drawn as long at the center pixel is
                    % within the mask, thus the radius extends beyond
                    normedMaskSize = (obj.maskDiameter - obj.dotDiameter)/this.objWidthHeight(1);
                    this.mMaskCircle(normedMaskSize);
                    %this.mMaskCircle(0.5);
                case 'gaussian'
                    % not coded yet
            end
            
        end
        
        %# user accessible function
        function setParameter(this, param, value)
            % add in error checking?
            % IDEA: properties are function handles
            % this function calls the appropriate function 
            % using the property name, and passing the input 
            %p = inputParser; 
            %p.KeepUnmatched = true;
 
            switch param
                case 'visible'
                    this.visible(value);
                case 'position'
                    this.mSetPosition(value);
                case {'color','dotColor'}
                    this.mSetColor(value);
                case {'pixelsPerFrame','dotPixelsPerFrame','PixelsPerFrame'}
                    % normalized by the radius 
                    this.mSetVelocity(2*value/this.objWidthHeight(1))
                case {'direction','dotDirection'}
                    this.mSetDirection(value);
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
            def.position           = [0,0];     % [x,y] position             (signed floats)
            def.dotDiameter        = 4;         % pixels 
            def.dotColor           = [255,255,255,255];
            def.dotPixelsPerFrame  = 0;         % velocity -> pixelsPerFrame (signed float) 
            def.dotDirection       = 0;         % degrees                    (signed float)
            def.dotCoherence       = 1.0;       % value between [0,1]
            def.coherenceType      = 'angle';   % 'ratio','angle' [string]
            def.dotNumber          = 100;       %                   [must be an integer >0]
            def.maskType           = 'circle';  % 'square','circle' [string]
            def.maskDiameter       = 200;       % pixels            [must be an integer >0]
            
            %      create validation structure
            validatePosInteger = @(x) isnumeric(x) && isscalar(x) && (x >= 1); % dot/mask diameter, dotNumber
            validateSignScalar = @(x) isnumeric(x) && isscalar(x);             % velocity, direction
            
            val =  [];
            val.position           = @(x) isnumeric(x) && isrow(x) && length(x)==2;
            val.dotNumber          = validatePosInteger;
            val.dotDiameter        = validatePosInteger;
            val.dotColor           = @(x) isnumeric(x) && isrow(x) && length(x)==4 && all(x>=0 & x<=255);
            val.dotPixelsPerFrame  = validateSignScalar;
            val.dotDirection       = validateSignScalar;
            val.dotCoherence       = @(x) isnumeric(x) && isscalar(x) && (x >= 0 && x <=1);
            val.coherenceType      = @(x) any(validatestring(x,{'ratio','angle'}));
            val.maskType           = @(x) any(validatestring(x,{'square','circle','gaussian'}));
            val.maskDiameter       = validatePosInteger;
            
            funcName = 'createObject(''RandomDots'',params)';
            this.mStructToInputParser(funcName, def, val);
            %---------------------------------------%
        end
    end
    
    methods (Access = private)
        %# create stimulus file
        function mCreateParticleFile(this)
            randFileString       = [smGenerateRandomString(8),'.part']; % random file string
            this.objParticleFile = fullfile(this.partFileDir,'tmp',randFileString);
            
            % generate random positions
            obj = this.paramStruct;% parameter struct
            
            N = obj.dotNumber;
            R = obj.dotCoherence;
            
            theta = 0; % mean phase angle
            switch obj.coherenceType
                case 'ratio'
                    phi = (rand(N,1) > R) .* (rand(N,1)*360-180); % implies theta = 0
                case 'angle'
                    phi = smGenerateRandomPhaseAngles(R, N, theta, 'degrees');
            end
            
            % write file
            NumericBinaryFile(this.objParticleFile,...
                cat(1, rand(2,N,'single')*2-1, single(phi)'));
        end
    end 
end
