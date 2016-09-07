classdef OBJBitmapBrush < OBJImage & OBJOpacityMask
    % [OBJECT] BITMAP BRUSH
    
    % DESCRIPTION:
    % "Bitmap Brush Objects" (introduced in version 1.1.2.0) provide a way 
    % to apply "Opacity Masks" to images. There are different modes 
    % depending on the size of the components involved.
    % If the width and height of the opacity mask are smaller than the 
    % respective dimensions of the bitmap brush, a centered rectangular part 
    % of the bitmap brush with the size of the opacity mask is used for the 
    % operation. You may shift the rectangle relative to the bitmap brush. 
    % This is the preferred mode of operation. If the width and height of 
    % the opacity mask are greater than the respective dimensions of the 
    % bitmap brush used, a centered subset of the same size as the target 
    % is used as the mask. Making the opacity mask sufficiently large 
    % (twice the size of the bitmap brush) allows the mask to be shifted 
    % relative to the target. You can replace an opacity mask by simply 
    % loading a new one. Bitmap brushes without an attached opacity mask 
    % render like normal pictures (but more expensive).

    % Inheritance...
    % OBJBitmapBrush < ...
    %   OBJImage < SPCObject < AUXPipeReadWrite < handle
    %   OBJOpacityMask < AUXPipeReadWrite < handle
    

    %------------------------------------------%
    % 25.4.2016 - Jarrod, wrote class 


    %# constructor
    methods (Static)
        function this = OBJBitmapBrush
        end
    end

    
    methods (Access = protected)
        %# Create Bitmap Brush Object
        % Image file, Opacity mask (image) file
        function mCreateObject(this, filename, opacitymask) %** overload OBJImage method **
            % [00 14 filename] create a bitmap brush from the specified image file.
            % filename    -> image file name 
            % opacitymask -> opacity mask filename (only load alpha)
            
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
            
            % create bitmap brush stimulus
            success = this.mWriteCommand(0,...
                [uint8(14), uint8(filename), uint8(0)]); % 0 = endl;
            % try to fetch stimulus key
            this.mFetchObjectKey(success, filename); % pass filename as ObjectString 
            
            % load opacity mask 
            this.mLoadOpacityMask(opacitymask);
        end
        
        %# replace
        %function mReplaceObject(this, filename)
            % [00 15 kk filename] create or replace with a bitmap brush from the 
            % specified image file.
        %end
    end
    
    %# edit destructor 
    methods
        %# redefine delete method
        function delete(this)
            delete@OBJOpacityMask(this);  % call super class delete
            delete@OBJImage(this);        % call super class delete
        end
    end
    
end

