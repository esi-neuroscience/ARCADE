classdef OBJRectangle < SPCObject
    % [OBJECT] RECTANGLE

    
    % INHERITANCE:
    % OBJRectangle < ...
    %   SPCObject < AUXPipeReadWrite < handle
    
    
    %------------------------------------------%
    % 18.4.2016 - Jarrod, wrote class 


    %# constructor
    methods (Static)
        function this = OBJRectangle
        end
    end
    
    
    methods (Access = protected)
        %# create particle stimulus
        function mCreateObject(this)
            % [00 20] create a rectangle (bar) stimulus. 
            % The initial color is inherited from the "default draw color".
            success = this.mWriteCommand(this.oKey, uint8(20));
            % try to fetch stimulus key
            this.mFetchObjectKey(success, 'Rectangle'); % object string
        end
        
        % **** no replace function in StimServer **** 
        % function mReplaceStimulus(this)
        % end
        
        %# set symbol diameter in pixels
        function mSetWidthHeight(this, size_pixels)
            %[kk 1 1 width height] set rectangle size (uint16s). Initial size is 11×21 pixels.
            this.mWriteCommand(this.oKey, [uint8([1,1]), typecast(uint16(size_pixels),'uint8')]);
        end
        
        %# set orientation 
        function mSetOrientation(this, degrees)
            % [kk 4 alpha] set orientation of rectangle. 
            % Alpha is a single float specifying the angle in degrees.
            this.mWriteCommand(this.oKey, [uint8(4), typecast(single(degrees),'uint8')]);
        end
        
        %# set symbol color
        function mSetColor(this, rgbw)
            % [kk 5 r g b w] set components (uint8, 0...255) for color of object. 
            % The initial color is inherited from the "default draw color"
            % **This command is not yet implemented for outlined circles**
            this.mWriteCommand(this.oKey, [5, rgbw]); % includes alpha (w)
        end
        
    end
    
end

