classdef OBJImage < SPCObject
    % [OBJECT] IMAGE

    % Inheritance...
    % OBJImage < ...
    %   SPCObject < AUXPipeReadWrite < handle

    %------------------------------------------%
    % 25.4.2016 - Jarrod, wrote class 

    
    %# constructor
    methods (Static)
        function this = OBJImage
        end
    end

    methods (Access = protected)
        %# Create Image Object
        function mCreateObject(this, filename)
            %[00 2 filename] create a picture stimulus from the specied image file.
            
            % check filename
            validFiles = {'.png','.jpeg','.jpg','.bmp','.tiff','.tif'};
            try
                [~,~,ext] = fileparts(filename);
                isValid = any(validatestring(ext,validFiles)); %#ok<NASGU>
            catch ME
                error(ME.message);
            end
            % make sure file exists 
            if ~exist(filename,'file'), error('Image file does not exist.'); end;
            
            % create image stimulus
            success = this.mWriteCommand(0,...
                [uint8(2), uint8(filename), uint8(0)]); % 0 = endl;
            % try to fetch stimulus key
            this.mFetchObjectKey(success, filename); % pass filename as ObjectString 
            
        end
        
        %# replace
        %function mReplaceObject(this, filename)
            %[00 3 kk filename] create or replace with a picture stimulus from the specied image file.
        %end
        
        %# set image alpha 
        function mSetImageAlpha(this, value)
            %[kk 1 a] set global alpha value for image (a = 0:255)
            this.mWriteCommand(this.oKey, [1, value]); 
        end
        
        %# set image orientation
        function mSetImageAngle(this, value)
            % [kk 4 alpha] set orientation of picture. Alpha is a single float specifying the angle in degrees.
            this.mWriteCommand(this.oKey, [uint8(4), typecast(single(value),'uint8')]); 
            
        end
        
        %# set image rotation (rotate each frame)
        function mAnimateImageRotation(this, value)
            % [kk 2 i] set increment value for picture rotation to i (i = -128 ... 127)
            this.mWriteCommand(this.oKey, [uint8(2), int8(value)]); 
        end
    end
end

