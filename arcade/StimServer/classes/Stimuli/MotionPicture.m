classdef MotionPicture < Stimulus
    % MOTIONPICTURE - Class for image sequence stimuli to be passed to the
    %   StimServer.
    %
    % PROPERTIES
    % -----------
    %   filename : filename of image sequence (read-only)
    %   size     : [x y] video frame size (pixel) (read-only)
    %   nFrames  : number of video frames in file (read-only)
    %   alpha    : 8-bit alpha transparency value between 0 (transparent) and 255 (opaque)
    %   angle    : rotation angle of image (degree), 0=horizontal, 90=vertical        
    %   screenFramesPerVideoFrame : 
    %              >1 = integer number of screen frames a video frame is repeated for
    %               0 = no frame advancement
    %   endEventName : name of event triggered after movie ends
    %
    %
    % USAGE
    % -----
    %   images = MotionPicture(filename);
    %
    % Supported filetypes are multi-frame TIFF and GIF. Video files (AVI,
    % MP4, ...) can be converted to multi-frame TIFF files using the
    % convert_fideo_for_StimServer function. File size is strongly limited
    % by the available video RAM. Too large files will result in erratic
    % playback.
    % 
    % By default each video frame will be shown for one screen frame. For
    % slower playback use the screenFramesPerVideoFrame property.
    %
    % THIS IS AN ALPHA VERSION INTENDED FOR TESTING! DO NOT USE FOR 
    % IMPORTANT EXPERIMENTS.
    %
    % See also Stimulus, Animation, convert_video_for_StimServer
    
    properties ( SetAccess = immutable )
        filename % full filename of image sequence
        size % frame size in pixel (x y)
        nFrames % number of video frames
    end
    
    properties ( SetAccess = public, GetAccess = public )
        alpha = 255; % alpha transparency value between 0 (transparent) and 255 (opaque)
        angle = 0; % angle in degrees of image, 0=horizontal, 90=vertical
        % >1: integer number of screen frames a video frame is repeated for
        %  0: no frame advancement
        screenFramesPerVideoFrame = 1;
        endEventName = 'MovieDone';
    end
    
    methods
        function obj = MotionPicture(filename)
            warning('The MotionPicure stimulus is for testing purposes only')
            % MotionPicture(filename);
            assert(exist(filename, 'file') == 2, 'Picture %s file not found', filename)
            [~,~,ext] = fileparts(filename);
            validExts = {'.gif', '.tif', '.tiff'};
            validatestring(ext, validExts);                        
            
            StimServer.Command(0, uint8([24 filename 0]));
            obj = obj@Stimulus();
            obj.filename = filename;
            fileInfo = imfinfo(filename);
            obj.size = [fileInfo(1).Width fileInfo(1).Height];
            obj.nFrames = length(fileInfo);
            obj.endEventName = obj.endEventName;
        end
                
        function set.alpha(obj, alpha)
            assert(alpha>=0 && alpha <=255, 'Picture alpha value must between 0 (transparent) and 255 (opaque)')
            StimServer.Command(obj.key, uint8([1 alpha]));
            obj.alpha = alpha;
        end
        
        function set.angle(obj, angle)
            assert(angle>=0 && angle <360, 'Picture angle must between 0 and 360 (counter-clockwise)')
            StimServer.Command(obj.key, ...
                uint8([4 typecast(single(angle), 'uint8')]));
            obj.angle = angle;
        end
        
        function set_frame(obj, frame)
            % Set current frame 
            if frame > obj.nFrames
                error('Desired frame (%d) is larger than the number of frames (%d)', ...
                    frame, obj.nFrames)
            end
            StimServer.Command(obj.key, ...
                uint8([6 typecast(uint32(frame-1), 'uint8')]));
        end
        
        function set.screenFramesPerVideoFrame(obj, fraction)            
            StimServer.Command(obj.key, ...
                uint8([9 typecast(uint16(fraction), 'uint8')]));
            obj.screenFramesPerVideoFrame = fraction;
        end
        
        function set.endEventName(obj, name)
             StimServer.Command(obj.key, ...
                 uint8([10 name 0]));
            obj.endEventName = name;
        end
        
    end
end