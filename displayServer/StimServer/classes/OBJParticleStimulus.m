classdef OBJParticleStimulus < SPCObject
    % [OBJECT] PARTICLE
    
    
    % INHERITANCE:
    %   OBJParticleStimulus < ...
    %       SPCObject < AUXPipeReadWrite < handle
    
    % create
    % replace
    % visible
    % protect
    % remove
    % delete
    % setPosition
    % setVelocity
    % setDirection 
    % setColor
    % setAnimationValue
    % maskGaussian
    % maskCircle

    % Inheritance...
    % OBJParticleStimulus < ...
    %   SPCObject < AUXPipeReadWrite < handle
      

    %------------------------------------------%
    %                  To Do
    % function mReplaceObject()   
    % function mMaskGaussian(this, value)
    
    %------------------------------------------%
    % 12.4.2016 - Jarrod, wrote class
    % 21.4.2016 - Jarrod, Tested and debugged
    
    properties (...
            AbortSet  = true,...
            SetAccess = private)
        partFileDir % filepath for particle files
    end
    
    %# constructor
    methods (Static)
        function this = OBJParticleStimulus
            % set filepath for particle files
            this.partFileDir = fullfile(...
                fileparts(mfilename('fullpath')),'stimfiles','particleShader');
        end
    end

    methods (Access = protected)
        %# create particle stimulus 
        % basic input error checking 
        function mCreateObject(this, WidthHeight, filename)
            % [00 8 w h filename] create a particle stimulus (size w x h pixels) from the specified file.
            % w and h are uint16. For example Matlab code to create a coordinate file
            % Note: The ability to set w and h independently is intended for future expansions
            % to rectangular stimuli. The current implementation is designed for stimuli with
            % a square layout, i.e. w and h should be equal.
            
            %filename = 'H:\projects\DisplayServer_2.2\displayServer\Version_2.2\StimServer\classes\blah.part';
            
            % check filename
            validFiles = {'.part'};
            try
                [~,~,ext] = fileparts(filename);
                isValid = any(validatestring(ext,validFiles)); %#ok<NASGU>
            catch ME
                error(ME.message);
            end
            
            % create particle stimulus
            success = this.mWriteCommand(0,...
                [uint8(8), typecast(uint16(WidthHeight),'uint8'), uint8(filename), uint8(0)]); % 0 = endl;
            % try to fetch stimulus key
            this.mFetchObjectKey(success, filename); % pass filename as ObjectString           
        end

        %function mReplace()   
        % [00 9 w h kk filename] create or replace with a particle stimulus from the specified file.
        %end
        
        %# set dot diameter in pixels 
        function mSetDiameter(this, size_pixels)
            %[kk 1 1 value] set particle diameter (uint16 - initial value is 4)
            % value is passed as an integer, pixels -> diameter
            % the dots are anti-alised and thus they will have a thin dark edge 
            % if the dot is positioned exactly on a pixel (e.g. [0,0], then
            % even dot diameters are recommended, otherwise odd dot
            % diameters are recommended 
            this.mWriteCommand(this.oKey, [uint8([1,1]), typecast(uint16(size_pixels),'uint8')]);
        end
        
        %# set dot color 
        function mSetColor(this, rgbw)
            % [kk 5 r g b w] set components (uint8, 0...255) for color of particles. 
            % The initial color is inherited from the "default draw color".
            this.mWriteCommand(this.oKey, [5, rgbw]); % includes alpha (w)
        end
        
        % set the dot velocity (signed)
        function mSetVelocity(this, value)
            % [kk 2 velocity] set velocity (single float) for particles. 
            % The velocity is expressed as (normalized by radius) coordinate increment per frame.
            % value = 2*pixelsPerFrame/RectanglePatchSize
            % value is passed as single float, and signed values change the direction 180 degrees
            this.mWriteCommand(this.oKey, [uint8(2), typecast(single(value),'uint8')]);
        end
        
        %# set the direction the dots travel 
        function mSetDirection(this, value)
            % [kk 4 angle] set angle (degrees as single float) of particle movement. 
            % If each particle has it's own angle (see section 2.1 on page 2) 
            % this value is added to each of them.
            % **In general the position of a particle is not preserved when
            % the angle is changed.**
            % default direction is 0 degrees
            this.mWriteCommand(this.oKey, [uint8(4), typecast(single(value),'uint8')]);
        end
       
        %# set the animation value
        function mSetAnimationValue(this, value)
            % [kk 6 value] set animated shift value (single float).
            % *this value is signed*
            % 0   -> initial dot position
            % 0.5 -> 1/2 radius in direction
            % 1.0 -> radius in direction
            % 2.0 -> full cycle rotation (equivalent to ~0)
            this.mWriteCommand(this.oKey, [uint8(6), typecast(single(value),'uint8')]);
        end
        
        %# set hard circle mask 
        function mMaskCircle(this, value)
            % [kk 1 2 value] set patch radius (0 ... 1.42 single float) for particle stimulus.
            % A value of 0 switches back to the unpatched (rectangular) mode.
            % A value of 1 produces a circle patch with a radius equal to the 1/2 width of the rectangle patch
            % A value of sqrt(2) produces the original rectangle patch
            % because the radius is equal to the euclidean sum of the 1/2 width and 1/2 height
            this.mWriteCommand(this.oKey, [uint8([1,2]), typecast(single(value),'uint8')]);
        end
        
        %# set gaussian mask 
        %function mMaskGaussian(this, value)
            % [kk 1 3 value] set Gaussian patch (single float) for particle stimulus.
            % A value of 0 disables the Gaussian patch.
            % For details see section 2.1.1 on page 2.
        %end
    end
    
end

