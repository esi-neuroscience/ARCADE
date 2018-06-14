classdef Flicker < Animation
    % Flash - Class for displaying a stimulus for a given number of frames.
    %
    % Usage
    % -----
    %   a = Flicker(nOnFrames, nOffFrames)
    %     
    %  
    % Example
    % -------
    %   a = Flicker(2, 2);
    %   c = Circle;
    %   c.play_animation(a);
    %   c.visible = true;
    %     
    % See also Animation, Stimulus
    
    properties ( Transient = true )
       nOnFrames = 1; % number of frames the stimulus is visible
       nOffFrames = 1; % number of frames the stimulus is invisible
    end
    
    methods
        function obj = Flicker(nOnFrames, nOffFrames)
            if nargin == 0
                nOnFrames = 1;
                nOffFrames = 1;
            end
            StimServer.Command(0, uint8([138 typecast(uint16([nOnFrames nOffFrames]),'uint8')]));
            obj = obj@Animation();
            obj.nOnFrames = nOnFrames;
            obj.nOffFrames = nOffFrames;
        end
        
        function SetFrames(obj, nOn, nOff)
            StimServer.Command(obj.key, [uint8(2), typecast(uint16([nOn nOff]),'uint8')])
            obj.nOnFrames = nOn;
            obj.nOffFrames = nOn;
        end

    end
    
    
end