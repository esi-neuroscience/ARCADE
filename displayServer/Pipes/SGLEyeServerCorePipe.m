classdef (Sealed) SGLEyeServerCorePipe < AUXEyeServer
    % [SINGLETON]
    

    %---------------------------------------------%
    % UKNOWN - Jarrod, wrote class
    
    properties
        hPipe      = [];      % pipe handle
        pipeBuffer = [14 14]; % [out, in] relative to server
        pipeName   = '\\.\pipe\EyeServerCorePipe';
    end
    
    methods (Static)
        function this = launch
            persistent thisObj
            if isempty(thisObj) || ~isvalid(thisObj)
                thisObj = SGLEyeServerCorePipe;
            end
            this = thisObj;
        end
    end
    
    methods (Access = private)
        function this = SGLEyeServerCorePipe
        end
    end
    

end

