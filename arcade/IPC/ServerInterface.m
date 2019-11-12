classdef ( Abstract ) ServerInterface < handle
    
    
    properties ( Constant, GetAccess = public, Hidden = true, Abstract )
        doneEventName
        pipeName
    end
    
    methods ( Abstract, Static, Access=protected )
        handle = SetGetHandle(value)
    end
    
    methods ( Abstract, Static, Access=public) 
        isConnected = GetConnectionStatus()
    end
    
    
    methods ( Static, Access=public )
        
        function hPipe = Connect(pipeName)
            % Connect to pipe for issueing commands
            if ~libisloaded('kernel32')
                loadlibrary('kernel32', @win_kernel32);
            end
            
            server = '.';
            
            GENERIC_READ_WRITE = uint32(hex2dec('C0000000'));
            
            % https://docs.microsoft.com/en-us/windows/win32/api/fileapi/nf-fileapi-createfilea
            hPipe = calllib('kernel32', 'CreateFileA', ...
                uint8(['\\' server pipeName]), ...
                GENERIC_READ_WRITE, ...
                0, ...  % no sharing
                [], ...
                3, ...  % OPEN_EXISTING
                0, ...
                []);
            assert(~hPipe.isNull(), ...
                ['Cannot connect to pipe. Is the server running ?']);
            pause(0.2)
            result = calllib('kernel32', 'GetNamedPipeInfo', ...
                hPipe, ...
                [], ...
                [], ...
                [], ...
                []);
            if ~isequal(result, 0)
                ConstructorResult = calllib('kernel32', 'GetLastError');
                if ~isequal(ConstructorResult, 0)
                    disp(ConstructorResult)
                end
                error('ARCADE:ServerInterface:Connect:failed', ...
                    'Can''t connect to pipe. Is the server running?');
            end
            
            
        end
        
        function Disconnect(hPipe)
            % Disconnect from pipe
            result = calllib('kernel32', 'CloseHandle', hPipe);
            if isequal(result, 0)
                warning('Could not close pipe handle')
            end
        end
        
    end
    
    methods ( Static, Access = public, Hidden = true )
        function key = ReadAck(hPipe)
            if hPipe.isNull
                error('No connection to server');
            end
            key = uint16(0);
            nRead = uint32(0);
            [result, ~, key, nRead] = ...
                calllib('kernel32', 'ReadFile', ...
                hPipe, ...
                key, ...
                2, ...
                nRead, ...
                []);
            assert(nRead == 2, 'Could not read stimulus key from pipe');
        end
    end
    
    methods ( Static, Access=public, Hidden=true )
        
        function Write(hPipe, cmdMessage)
            if hPipe.isNull
                error('No connection to server');
            end
            
            nWritten = uint32(0);
            [result, ~, cmdMessage, nWritten] = ...
                calllib('kernel32', 'WriteFile', ...
                hPipe, ...
                cmdMessage, ...
                length(cmdMessage), ...
                nWritten, ...
                []);
            if isequal(result, 0)
                result = calllib('kernel32', 'GetLastError');
                assert(false, 'Could not write message to pipe');
            end
            assert(nWritten == length(cmdMessage), 'Could not write message to pipe');
        end
        
        function Command(hPipe, key, bytearr)
            ServerInterface.Write(hPipe, [typecast(uint16(key), 'uint8') uint8(bytearr)]);
        end
        
        function result = read1single(hPipe)
            if hPipe.isNull
                error('No connection to server');
            end
            result = single(0);
            nRead = uint32(0);
            [~, ~, result, nRead] = ...
                calllib('kernel32', 'ReadFile', ...
                hPipe, ...
                result, ...
                4, ...
                nRead, ...
                []);
            assert(nRead == 4, 'Could not read 4 bytes from pipe');
        end
        
        function pos = read2single(hPipe)
            if hPipe.isNull
                error('No connection to server');
            end
            pos = uint64(0);
            nRead = uint32(0);
            [~, ~, pos, nRead] = ...
                calllib('kernel32', 'ReadFile', ...
                hPipe, ...
                pos, ...
                8, ...
                nRead, ...
                []);
            assert(nRead == 8, 'Could not read 8 bytes from pipe');
            pos = typecast(pos, 'single');
        end
    end
end