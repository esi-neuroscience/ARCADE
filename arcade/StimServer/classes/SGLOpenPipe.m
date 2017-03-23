classdef (Sealed) SGLOpenPipe < handle
    % [SINGLETON CLASS] OpenPipe
    %   - open pipe 
    %   - maintain a copy of pipe handle 
    %     that can be fetched 
    
    properties (...
            AbortSet  = true,...
            SetAccess = immutable)
        hPipe    % pipe handle
    end
    
    methods (Static)
        function this = fetch
            persistent thisObj
            if isempty(thisObj) || ~isvalid(thisObj)
                thisObj = SGLOpenPipe;
            end
            this = thisObj;
        end
    end
    
    methods (Access = private)
        function this = SGLOpenPipe
            this.hPipe = this.mOpenPipe;
        end
    end

    methods (...
            Static = true,...
            Access = private)
        %# Open Pipe
        function hPipe = mOpenPipe
            
            if ~libisloaded('kernel32'); loadlibrary('kernel32', @win_kernel32); end;
            % GENERIC_WRITE = uint32(hex2dec('40000000'));
            GENERIC_READ_WRITE = uint32(hex2dec('C0000000'));
            pipeName = uint8(['\\.\pipe\StimServerPipe' 0]);
            hPipe = calllib('kernel32', 'CreateFileA', ...
                pipeName, ...
                GENERIC_READ_WRITE, ...
                uint32(0), ...  % no sharing
                [], ...
                uint32(3), ...  % OPEN_EXISTING
                uint32(0), ...
                []);
                     
            % set as a nowait message pipe
            PIPE_MODE = uint32(hex2dec('00000003')); % message | nowait
            result = calllib('kernel32', 'SetNamedPipeHandleState',...
                hPipe,...
                PIPE_MODE,...
                [],... % lpMaxCollectionCount
                []);   % lpCollectDataTimeout
               
            if ~result
                error('StimServer:mOpenPipe', ...
                    'Unable to set pipe mode for StimServerPipe');
            end
            
            % check successful creation
            [result, flags, outSize, inSize, ~] = MSNamedPipe.mGetNamedPipeInfo(hPipe);
            if ~(result > 0) || flags ~= 4 || outSize ~= 8 || inSize~= 128
                error('StimServer:mOpenPipe', 'StimServerPipe creation failed')
            end

        end
    end
    
    methods
        function delete(this)
             success = calllib('kernel32', 'CloseHandle', this.hPipe);
             if success == 0 
                warning('Could not close handle of \\.\pipe\StimServerPipe')
            end
        end
    end
    
end

