classdef HLOBitmapBrush < OBJBitmapBrush & SPCHighLevelObject
    % [HIGH LEVEL OBJECT] BITEMAP BRUSH 
    
    
    % INHERITANCE:
    % HLOBitmapBrush < ...
    %   OBJBitmapBrush < ...
    %       OBJImage < SPCObject < AUXPipeReadWrite < handle
    %       OBJOpacityMask < AUXPipeReadWrite < handle
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
    % 25.4.2016 - Jarrod, wrote class 

    %# constructor
    methods (Static)
        function this = HLOBitmapBrush
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
            if isempty(obj.imageFile) || isempty(obj.maskFile)
                error('Both the image and mask files are required input');
            end
            
            % create object in StimServer
            this.mCreateObject(obj.imageFile, obj.maskFile);
            
            % if enable mask on load 
            if obj.enableMaskOnLoad
                this.setParameter('maskVisible', true);
            end
            
            %setParams = fieldnames(obj);
            setParams = {'imagePosition','imageAlpha','imageAngle','maskPosition'};
            for ki = 1:length(setParams)
                if ~any(strcmp(setParams{ki},useDefs))
                    this.setParameter(setParams{ki}, obj.(setParams{ki}));
                end
            end
        end
        
        %# user accessible function
        function setParameter(this, param, value)
            switch param
                case 'visible'                      % image
                    this.visible(value);
                case {'position','imagePosition'}   % image
                    this.mSetPosition(value);
                case {'alpha','imageAlpha'}         % image
                    this.mSetImageAlpha(value);
                case {'angle','imageAngle'}         % image
                    this.mSetImageAngle(value);
                case 'maskVisible'                  % opacity mask 
                    this.mSetOpacityMaskVisible(value);
                case 'maskPosition'                 % opacity mask 
                    this.mSetOpacityMaskPosition(value);
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
            def.position         = [0,0];     % [x,y]     position 
            def.imageFile        = '';        % [string] no default image *required input* 
            def.imageAlpha       = 255;       % [0...255] global alpha 
            def.imageAngle       = 0;         % [degrees] float 
            % opacity mask 
            def.maskFile          = '';        % [string] no default mask *required input* 
            def.maskPosition     = [0,0];     % [x,y] relative to image position 
            def.enableMaskOnLoad = true;      % [logical] enable mask after it is loaded 

            validImageFiles = {'.png','.jpeg','.jpg','.bmp','.tiff','.tif'};
            fGetExt         = @(fpath) fpath(find(fpath == '.', 1, 'last'):end);
            validMaskFiles  = {'.png'}; % file types with alpha dimensions

            val =  [];
            val.position         = @(x) isnumeric(x) && isrow(x) && length(x)==2;
            val.imageFile        = @(x) ischar(x) && exist(x,'file')==2 && any(strcmpi(fGetExt(x),validImageFiles)); 
            val.imageAlpha       = @(x) isnumeric(x) && isscalar(x) && (x>=0 && x<=255); 
            val.imageAngle       = @(x) isnumeric(x) && isscalar(x);
            % opacity mask 
            val.maskFile         = @(x) ischar(x) && exist(x,'file')==2 && any(strcmpi(fGetExt(x),validMaskFiles)); 
            val.maskPosition     = @(x) isnumeric(x) && isrow(x) && length(x)==2;
            val.enableMaskOnLoad = @(x) (isnumeric(x) || islogical(x)) && isscalar(x);
            
            funcName = 'createObject(''BitmapBrush'',params)';
            this.mStructToInputParser(funcName, def, val);
        end
    end
end
