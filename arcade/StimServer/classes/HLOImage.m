classdef HLOImage < OBJImage & SPCHighLevelObject
    % [HIGH LEVEL OBJECT] IMAGE 
    
    
    % INHERITANCE:
    % HLOImage < ...
    %   OBJImage < SPCObject < AUXPipeReadWrite < handle
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
    % 26.4.2016 - Jarrod, wrote class 

    %# constructor
    methods (Static)
        function this = HLOImage
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
            
            % check if image file exists 
            if isempty(obj.imageFile)
                error('Image file is required input');
            end
            
            % create object in StimServer
            this.mCreateObject(obj.imageFile);
            
            %setParams = fieldnames(obj);
<<<<<<< master
            setParams = {'imagePosition','imageAlpha','imageAngle'};
=======
            setParams = {'position','alpha','angle'};
>>>>>>> local
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
                case {'position','imagePosition'}
                    this.mSetPosition(value);
                case 'alpha'
                    this.mSetImageAlpha(value);
                case 'angle'
                    this.mSetImageAngle(value);
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
            def.position     = [0,0];     % [x,y]     position 
            def.imageFile    = '';        % [string] no default image *required input* 
            def.alpha   = 255;       % [0...255] global alpha 
            def.angle   = 0;         % [degrees] float 
            
            validFiles = {'.png','.jpeg','.jpg','.bmp','.tiff','.tif'};
            fGetExt    = @(fpath) fpath(find(fpath == '.', 1, 'last'):end);

            val =  [];
            val.position    = @(x) isnumeric(x) && isrow(x) && length(x)==2;
            val.imageFile   = @(x) ischar(x) && exist(x,'file')==2 && any(strcmpi(fGetExt(x),validFiles)); 
            val.alpha  = @(x) isnumeric(x) && isscalar(x) && (x>=0 && x<=255); 
            val.angle  = @(x) isnumeric(x) && isscalar(x);
            
            funcName = 'createObject(''Image'',params)';
            this.mStructToInputParser(funcName, def, val);
        end
    end
end

