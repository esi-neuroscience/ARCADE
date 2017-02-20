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
            hPipe = calllib('kernel32', 'CreateFileA', ...
                uint8('\\.\pipe\StimServerPipe'), ...
                GENERIC_READ_WRITE, ...
                0, ...  % no sharing
                [], ...
                3, ...  % OPEN_EXISTING
                0, ...
                []);
        end
    end
    
    methods
        function delete(this)
             calllib('kernel32', 'CloseHandle', this.hPipe);
        end
    end
    
end

