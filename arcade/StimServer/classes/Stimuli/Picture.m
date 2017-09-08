classdef Picture < Stimulus
    % PICTURE - Class for image stimuli to be passed to the StimServer.
    %
    % Usage
    % -----
    %   img = Picture(filename);
    %
    % See also Stimulus, Animation
    
    properties ( SetAccess = immutable )
        filename % full filename of image
    end
    
    properties ( SetAccess = public, GetAccess = public )
        alpha = 255; % alpha transparency value between 0 (transparent) and 255 (opaque)
        angle = 0; % angle in degrees of image, 0=horizontal, 90=vertical
    end
    methods
        function obj = Picture(filename)
            % img = Picture(filename);
            assert(exist(filename, 'file') == 2, 'Picture %s file not found', filename)
            [~,~,ext] = fileparts(filename);
            validExts = {'.png', '.bmp', '.jpeg', '.jpg'};
            validatestring(ext, validExts);                        
            
            StimServer.Command(0, uint8([2 filename 0]));
            obj = obj@Stimulus();
            obj.filename = filename;
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
        
    end
end