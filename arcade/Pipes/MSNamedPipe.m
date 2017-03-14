classdef MSNamedPipe < handle 
    % [MICROSOFT]
    
    
    % + mCreateNamedPipeA        [SERVER]
    % + mCreateFileA             [CLIENT]
    % + mSetNamedPipeHandleState [CLIENT]
    % + MCloseHandle

    
    %---------------------------------------------%
    % Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes

    methods (Static)
        %# constructor
        function this = MSNamedPipe
            if ~libisloaded('kernel32'); loadlibrary('kernel32', @win_kernel32); end;
        end
    end

    methods (...
            Static = true,...
            Sealed = true)
        %---------------------------------------------%
        %                    SERVER
        %---------------------------------------------%
        function hPIPE = mCreateNamedPipeA(pNAME,pACCESS,pPIPE_MODE,pBUFFER)
            
            % pNAME = '\\.\pipe\ControlScreenPipe'
            % READ/WRITE ACCESS
            switch pACCESS
                case 'PIPE_ACCESS_INBOUND'
                    % PIPE_ACCESS_INBOUND = uint32(hex2dec('00000001')); % read only
                    ACCESS = uint32(hex2dec('00000001')); % read only
                case 'PIPE_ACCESS_OUTBOUND'
                    % PIPE_ACCESS_OUTBOUND = uint32(hex2dec('00000002')); % write only
                    ACCESS = uint32(hex2dec('00000002')); % write only
                case 'PIPE_ACCESS_DUPLEX'
                    % GENERIC_READ_WRITE = uint32(hex2dec('C0000000')); % both
                    ACCESS = uint32(hex2dec('00000003')); % both
                case 'FILE_FLAG_FIRST_PIPE_INSTANCE'
                    % ACCESS = uint32(hex2dec('00080000'));
            end
            
            switch pPIPE_MODE
                case {'PIPE_TYPE_BYTE', 'PIPE_READMODE_BYTE'}
                    % PIPE_TYPE_BYTE = uint32(hex2dec('00000000'));
                    PIPE_MODE = uint32(hex2dec('00000000'));
                case 'PIPE_TYPE_MESSAGE'
                    %PIPE_TYPE_MESSAGE = uint32(hex2dec('00000004'));
                    PIPE_MODE = uint32(hex2dec('00000004'));
                 case 'PIPE_READMODE_MESSAGE'
                    %PIPE_READMODE_MESSAGE= uint32(hex2dec('00000002'));
                    PIPE_MODE = uint32(hex2dec('00000002'));   
                case 'PIPE_NOWAIT'
                    %PIPE_NOWAIT = uint32(hex2dec('00000001'));
                    PIPE_MODE = uint32(hex2dec('00000001'));
                case {...
                        'PIPE_NOWAIT | PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE'}
                    PIPE_MODE = uint32(hex2dec('00000007'));
            end
            
            hPIPE = calllib('kernel32', 'CreateNamedPipeA', ...
                uint8(pNAME), ...
                ACCESS, ...
                PIPE_MODE, ...  %
                1, ...          % max instances
                pBUFFER(1),...  % out buffer
                pBUFFER(2),...  % in buffer
                0, ...          % timeout ms (50ms)
                []);
        end
        
        %# ConnectNamedPipe function
        % Enables a named pipe server process to wait for a client process
        % to connect to an instance of a named pipe. A client process 
        % connects by calling either the CreateFile or CallNamedPipe function.
        function success = mConnectNamedPipe(hPIPE)
            % If the function succeeds, the return value is nonzero.
            success = calllib('kernel32', 'ConnectNamedPipe',hPIPE,[]); 
        end
        
        %---------------------------------------------%
        %                    CLIENT
        %---------------------------------------------%
        %# 
        function hPIPE = mCreateFileA(pNAME,pACCESS)
            % pNAME = '\\.\pipe\ControlScreenPipe'
            % READ/WRITE ACCESS
            switch pACCESS
                case 'GENERIC_READ'
                    %GENERIC_READ = uint32(hex2dec('80000000')); % read only
                    ACCESS = uint32(hex2dec('80000000')); % read only
                case 'GENERIC_WRITE'
                    % GENERIC_WRITE = uint32(hex2dec('40000000')); % write only
                    ACCESS = uint32(hex2dec('40000000')); % write only
                case 'GENERIC_READ_WRITE'
                    % GENERIC_READ_WRITE = uint32(hex2dec('C0000000')); % both
                    ACCESS = uint32(hex2dec('C0000000')); % both
            end

            hPIPE = calllib('kernel32', 'CreateFileA', ...
                uint8(pNAME), ...
                ACCESS, ...
                0, ...  % no sharing
                [], ...
                3, ...  % OPEN_EXISTING
                0, ...
                []);
        end
        
        %# 
        function result = mSetNamedPipeHandleState(hPIPE,pPIPE_MODE)
            switch pPIPE_MODE
                case 'PIPE_READMODE_MESSAGE'
                    %PIPE_READMODE_MESSAGE = uint32(hex2dec('00000002'));
                    PIPE_MODE = uint32(hex2dec('00000002'));
                case 'PIPE_NOWAIT'
                    %PIPE_NOWAIT = uint32(hex2dec('00000001'));
                    PIPE_MODE = uint32(hex2dec('00000001'));
                case {...
                        'PIPE_NOWAIT | PIPE_READMODE_MESSAGE',...
                        'PIPE_READMODE_MESSAGE | PIPE_NOWAIT'}
                    PIPE_MODE = uint32(hex2dec('00000003'));
                    
            end
            
            result = calllib('kernel32', 'SetNamedPipeHandleState',...
                hPIPE,...
                PIPE_MODE,...
                [],... % lpMaxCollectionCount
                []);   % lpCollectDataTimeout
        end
        
        %# WaitNamedPipe function
        % Waits until either a time-out interval elapses or an instance 
        % of the specified named pipe is available for connection
        function success = mWaitNamedPipeA(pipeName,timeout) % timeout [ms]
            timeout = uint64(timeout); % ulong
            success = calllib('kernel32', 'WaitNamedPipeA', uint8(pipeName), timeout);
        end
        %---------------------------------------------%
        %                   READ/WRITE
        %---------------------------------------------%
        %# write 
        function success = mWriteFile(hPIPE,pBYTE_STREAM)
            
            BYTE_STREAM  = uint8(pBYTE_STREAM); % is unit8
            nBYTES       = length(BYTE_STREAM); % length of stream/message
            nWRITTEN     = uint32(0);           % number of bytes written
            
            [result, ~, BYTE_STREAM, nWRITTEN] = ...
                calllib('kernel32', 'WriteFile', ...
                hPIPE, ...
                BYTE_STREAM, ...
                nBYTES, ...
                nWRITTEN, ...
                []); %#ok<*ASGLU>
            % report success or fail & result
            success = nWRITTEN == nBYTES;
        end
        
        %# read 
        function byte_stream = mReadFile(hPIPE,nBYTES)
            byte_stream = uint8(zeros(1,nBYTES)); % create a buffer
            nREAD       = uint32(0);              % number of bytes read
            
            [result, ~, byte_stream, nREAD] = ...
                calllib('kernel32', 'ReadFile', ...
                hPIPE, ...
                byte_stream, ...
                nBYTES, ...
                nREAD, ...
                []); %
            
            % truncate if necessary 
            byte_stream = byte_stream(1:nREAD); % 1:0 = empty matrix
            
        end
        
        function mPrintLastErrorMessage
            
            
        end
        
        
        
        % GetLastError function
        function MSG_ID = mGetLastError
            MSG_ID = uint64(0); %#ok<NASGU>
            MSG_ID = calllib('kernel32', 'GetLastError'); 
        end
        
        function err = FormatMessageA(MSG_ID)
            FLAGS   = uint32(hex2dec('00001000')); %FORMAT_MESSAGE_FROM_SYSTEM
            buffer  = char(zeros(256,1));
            nBuffer = length(buffer);
            buffer = calllib('kernel32', 'FormatMessageA',...
                FLAGS,...
                [],...
                MSG_ID,...
                0,... % language id
                buffer,...
                nBuffer,...
                [])
        end
        
        %# DisconnectNamedPipe function
        % Disconnects the server end of a named pipe 
        % instance from a client process.
        function success = mDisconnectNamedPipe(hPIPE)
            % If the function succeeds, the return value is nonzero.
            success = calllib('kernel32', 'DisconnectNamedPipe',hPIPE); 
        end
        
        %# close pipe 
        function mCloseHandle(hPIPE)
           calllib('kernel32', 'CloseHandle',hPIPE); 
        end
        
    end
end

%EnumDisplaySettings
%ChangeDisplaySettings
% DeviceCapabilities
% GetNamedPipeClientProcessId function
% PeekNamedPipe
             


%FORMAT_MESSAGE_FROM_SYSTEM





