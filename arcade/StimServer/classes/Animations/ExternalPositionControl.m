classdef ExternalPositionControl < Animation
    % EXTERNALPOSITIONCONTROL - Class for controlling stimulus position
    % by reading coordinates from a shared memory region.
    % 
    % Common use case of this animation are gaze-contingent display of stimuli
    % and manual mapping of receptive fields. It's possible to set an offset
    % in pixels
    %  
    % USAGE
    % -----
    %   anim = ExternalPositionControl(sharedMemoryName)
    % 
    % 
    % EXAMPLE
    % -------
    %   
    %   stim = Circle();
    %   stim.visible = True;
    %   anim = ExternalPositionControl('EyePosition');
    %   stim.play_animation(anim);
    %   
    %   
    % See also Animation, Stimulus
    
    methods
        function obj = ExternalPositionControl(sharedMemName)
            StimServer.Command(0, uint8([140 sharedMemName 0]))
            obj = obj@Animation();
        end
    
        function setOffset(obj, offset)
            % 
            StimServer.Command(obj.key, [uint8(3), typecast(single(offset),'uint8')])
        end
    end

end