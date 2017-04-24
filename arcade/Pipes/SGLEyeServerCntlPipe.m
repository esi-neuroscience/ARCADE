classdef (Sealed) SGLEyeServerCntlPipe < AUXEyeServer
    % [SINGLETON]
    % - hold name and buffer size for this pipe 
    
    % AUXEyeServer  < MSMessagePipe & KEYEyeServer
    % MSMessagePipe < MSNamedPipe < handle 
    % KEYEyeServer  < handle 

    %---------------------------------------------%
    % Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    properties
        hPipe      =[];        % pipe handle
        pipeBuffer = [14 14]; % [out, in] relative to server
        pipeName   = '\\.\pipe\EyeServerCntlPipe';
    end
    
    methods (Static)
        function this = launch
            persistent thisObj
            if isempty(thisObj) || ~isvalid(thisObj)
                thisObj = SGLEyeServerCntlPipe;
            end
            this = thisObj;
        end
    end
    
    methods (Access = private)
        function this = SGLEyeServerCntlPipe
        end
    end
    
end

