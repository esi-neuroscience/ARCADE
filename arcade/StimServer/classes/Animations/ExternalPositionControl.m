classdef ExternalPositionControl < Animation
    % EXTERNALPOSITIONCONTROL - Class for controlling stimulus position
    % by reading coordinates from a shared memory region.
    % 
    % See also Animation, Stimulus
    
    methods
        function obj = ExternalPositionControl(sharedMemName)
            StimServer.Command(0, uint8([140 sharedMemName 0]))
            obj = obj@Animation();
        end
    
        function setOffset(obj, offset)
            StimServer.Command(obj.key, [uint8(3), typecast(single(offset),'uint8')])
        end
    end

end