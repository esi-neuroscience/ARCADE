classdef Flash < Animation
    % Flash - Class for displaying a stimulus for a given number of frames.
    %
    % Usage
    % -----
    %   a = Flash(nFrames)
    %     
    %  
    % Example
    % -------
    %   a = Flash(2);
    %   c = Circle;
    %   c.play_animation(a);
    %   c.visible = true;
    %     
    % See also Animation, Stimulus
    
    properties ( Transient = true )
       nFrames = 2; % number of frames
    end
    
    methods
        function obj = Flash(nFrames)
            if nargin == 0
                nFrames = 2;
            end
            StimServer.Command(0, uint8([138 typecast(uint16(nFrames),'uint8')]));
            obj = obj@Animation();
            obj.nFrames = nFrames;
        end
        
        function set.nFrames(obj, nF)
            StimServer.Command(obj.key, [uint8(2), typecast(uint16(nF),'uint8')])
            obj.nFrames = nF;
        end

    end
    
    
end