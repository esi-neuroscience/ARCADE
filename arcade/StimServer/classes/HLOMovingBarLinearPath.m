classdef HLOMovingBarLinearPath < HLOStaticBar & AMNLinearMotionPath
    % [HIGH LEVEL OBJECT]
    
    % specific implementation of moving bar...
    % computes 2 verticies -> [start, end]
    %   based on..
    %       orientation of the bar (orthogonal)
    %       half travel distance
    %       centered (mid-point) on the bar position
    
    % straight linear path 
    
    % inherits from Animation 
    % inherits from StaticBar
    
    % INHERITANCE:
    % HLOMovingBarLinearPath < ...
    %   HLOStaticBar < OBJRectangle < SPCObject < AUXPipeReadWrite < handle
    %   HLOStaticBar < SPCHighLevelObject < AUXInputParser < handle
    %   AMNLinearMotionPath < SPCAnimation < AUXPipeReadWrite
    
    % PROPERTIES: 
    %   + parserObj     % parser object
    %   + paramStruct   % parser results 
    %   + usingDefaults % cell of strings
    
    % METHODS: 
    %   + mParseInput
    %   + mAddParameterToExistingParser
    %   + mStructToInputParser
    %   + createStimulus(this, varargin)
    %   + setParameter(this, param, value)
    %   + mCreateAnimation
    %   + mSetVerticies
    %   + 
    
    % direction of movement
    % does not change, when changing the orientation
    % of the bar
    
    %------------------------------------------%
    % 20.4.2016 - Jarrod, wrote class
    % 21.4.2016 - Jarrod, Tested and debugged
    
    methods (Static)
        %# constructor
        function this = HLOMovingBarLinearPath
            % call superclass constructor 
             this = this@HLOStaticBar;            % creates input parser 
             %this = this@AMNLinearMotionPath;
             this.mAddAddParametersToInputParser; % add adittional params
        end
    end

    methods
        %# redefine delete method
        function delete(this)
            % unattach animation 
            this.mAttachAnimation(this.oKey, 0);
            delete@HLOStaticBar(this);        % call super class delete
            delete@AMNLinearMotionPath(this); % call super class delete
        end
    end
    
    methods
        %# create animation + stimulus object
        function createStimulus(this, varargin)
            % call superclass method
            % create bar stimulus 
            createStimulus@HLOStaticBar(this,varargin{:}); 

            % get parameters 
            obj = this.paramStruct;
           
            % StimServer wants pixels/sec (assumes 120Hz refresh)
            velocity = obj.pixelsPerFrame*120; 
            this.mCreateAnimation(velocity);
            
            % compute the bitmask for the terminal action 
            bitmask = this.mComputeTerminalActionBitMask(obj);
            this.mSetTerminalAction(bitmask); % set terminal action 
            
            % set verticies 
            verticies = this.mComputePathVerticies(obj);
            this.mSetVerticies(verticies);
            
            % attach animation to stimulus object 
            this.mAttachAnimation(this.oKey, 1);
        end
    end
    
    methods (...
            Static = true,...
            Access = private)
        %# compute the bitmask for the terminal action 
        function value = mComputeTerminalActionBitMask(obj)
            bitmask = false(1,8);
            bitmask(1) = obj.disableStim;
            bitmask(3) = obj.togglePD;
            bitmask(5) = obj.repeatPath;

            value = sum(bitmask .* 2.^(0:7));
        end
        
        %# compute verticies 
        function verticies = mComputePathVerticies(obj)
            % use orientation as the direction of movemenent 
            vectorLength  = obj.halfTravelPixels;
            moveDirection = obj.orientation*pi/180 * ones(1,2) + [pi,0];
            midPosition   = obj.position; 
            
            %x = [cos([1;2]),sin([3;4])]
            %x(:)'
            
            % [x1,y1,x2,y2,...]
            vertMatrix = vectorLength*[cos(moveDirection); sin(moveDirection)];
            verticies = bsxfun(@plus, vertMatrix, midPosition');
            verticies = verticies(:)';
        end
    end
   
    methods (Access = private)
        %# add parameter for the animation vertex 
        function mAddAddParametersToInputParser(this)
            %---------------------------------------%
            %           create defaults
            def =  [];
            %def.pathVerticies = [-100,0; 100,0];     % [x,y] verticies 
            def.halfTravelPixels   = 200;             % pixels           (must be an integer >=1)
            def.pixelsPerFrame     = 2;               % pixels per frame (must be an integer >=0)
            def.togglePD           = true;            % bool
            def.disableStim        = true;            % bool
            def.repeatPath         = false;           % bool

            % minimum of 2 vertices, max of 31
            % must have x,y for each vertex 
            %validateColumnVectors = @(x) all((size(x,1)*ones(1,2) - [2,31])>=0) && size(x,2)==2;
            validateLogicalScalar = @(x) (isnumeric(x) || islogical(x)) && isscalar(x);   
            
            val =  [];
            %val.verticies     = @(x) isnumeric(x) && validateColumnVectors(x);
            val.halfTravelPixels   = @(x) isnumeric(x) && isscalar(x) && x>=1;  
            val.pixelsPerFrame     = @(x) isnumeric(x) && isscalar(x) && x>=0;                  
            val.togglePD           = @(x) validateLogicalScalar(x);            
            val.disableStim        = @(x) validateLogicalScalar(x); 
            val.repeatPath         = @(x) validateLogicalScalar(x); 
            
            funcName = 'createObject(''MovingBar'',params)';
            this.mAddParameterToExistingParser(funcName, def, val);
        end
    end
end

