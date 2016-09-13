classdef OBJOpacityMask < AUXPipeReadWrite
    % [OBJECT] OPACITY MASK
    % *** meant to be inherited by BITMAP BRUSH ***
    
    % INHERITANCE:
    % OBJOpacityMask < AUXPipeReadWrite < handle
    
    
    %------------------------------------------%
    % 25.4.2016 - Jarrod, wrote class
    
    %# Opacity Mask Key
    properties (...
            SetAccess = private,...
            AbortSet  = true)
        bKey@uint16 scalar    = 0;
        bValid@logical scalar = false;
    end
    
    %# Track Current State (Opcaity Mask)
    properties (...
            AbortSet  = true,...
            SetAccess = private)
        %bEnabled@logical scalar   = false;    % enabled/visible
        %bProtected@logical scaler = false;    % protected from 'all' actions
    end
    
    
    %# constructor
    methods (Static)
        function this = OBJOpacityMask
        end
    end
    
    methods (Access = protected)
        %# create particle stimulus
        function mLoadOpacityMask(this, filename)
            % [kk 11 filename] load an opacity mask for the bitmap brush
            % from the specified image file.
            % *** loads Alpha dimension of image only ***
            % Applies this to the Bitmap Brush Image
            % Thus, the Opacity Mask needs to be a PNG
            
            % check filename
            validFiles = {'.png'};
            try
                [~,~,ext] = fileparts(filename);
                isValid = any(validatestring(ext,validFiles)); %#ok<NASGU>
            catch ME
                error(ME.message);
            end
            % make sure file exists
            if ~exist(filename,'file'), error('Image file does not exist.'); end;
            
            % create
            success = this.mWriteCommand(this.oKey,...
                [uint8(11), uint8(filename), uint8(0)]); % 0 = endl;
            % try to fetch stimulus key
            this.mFetchOpacityMaskKey(success, filename); % pass filename as ObjectString
        end
        
        %# set visibility of opacity mask
        function mSetOpacityMaskVisible(this, value)
            % [kk 10 e] enable (e=1) or disable (e=0) opacity mask
            this.mWriteCommand(this.bKey, [10, value]);
        end
        
        %# set opacity mask position (relative to center of image)
        function mSetOpacityMaskPosition(this, value)
            % [kk 13 x y] move opacity mask relative to bitmap brush
            % (x and y are single precision floats)
            this.mWriteCommand(this.bKey, [1, value]);
        end
    end
    
    methods (...
            Sealed = true,...
            Access = protected)
        %# destroy opacity mask
        function mRemoveOpacityMask(this)
            % [kk 10] remove (destroy) opacity mask (not deferrable)
            this.mWriteCommand(this.bKey, 10);
        end
    end
    
    methods
        %# delete 
        function delete(this)
            % do not try to delete if object is invalid 
            if this.bKey 
                this.mRemoveOpacityMask;
            end
        end
    end
    
    methods (Access = private)
        %# fetch stimulus reference key
        % add more error handling
        function mFetchOpacityMaskKey(this, createSuccess, objectString)
            % *** generalize this to fetch key with error handling ***
            if createSuccess % get object key
                bKey = this.mReadKey;   %#ok<*PROP>
                % has the object been created successfully
                this.bValid = bKey~=uint16(0);
                this.bKey   = bKey;
                
                if ~this.bValid
                    disp(['FAILED to get Key for stimulus: ', objectString]);
                end
            else
                disp(['FAILED to Create stimulus: ', objectString]);
            end
        end
    end
end

