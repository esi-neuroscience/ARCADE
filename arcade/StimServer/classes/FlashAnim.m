classdef FlashAnim < Animation
    % FLASHANIM - Class for displaying a stimulus for a given number of frames.
    %
    % Usage
    % -----
    %   a = FlashAnim(nFrames)
    %     
    %  
    % Example
    % -------
    %   a = FlashAnim(2);
    %   c = Circle;
    %   c.animation = a;
    %   c.visible = true;
    %     
    % See also Animation, Stimulus
    
    properties ( Transient = true )
       nFrames = 0; % number of frames
    end
    
    methods
        function obj = FlashAnim(nFrames)
            StimServer.Command(0, uint8([138 typecast(uint16(nFrames),'uint8')]));
            obj = obj@Animation();
        end
        
        function set.nFrames(obj, nF)
            StimServer.Command(obj.key, [uint8(2), typecast(uint16(nF),'uint8')])
            obj.nFrames = nF;
        end

    end
    
    
end