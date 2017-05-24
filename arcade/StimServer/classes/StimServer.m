classdef (Sealed = true) StimServer < handle
    % Matlab interface for communication with StimServer.exe via a named pipe.
    %
    % StimServer.exe must be started before using this class.
    % Commands and stimuli can be passed after StimServer.Connect() was called.
    %
    % See also Stimulus
    
    properties (Constant, Access = private, Hidden = true)
        this = StimServer
    end
    
    properties (Access = private, Transient = true, Hidden = true)
        hPipe = libpointer;
    end
    
    methods (Access = private, Hidden=true)
        function obj = StimServer()
            mlock;
        end
    end
    
    methods (Static)
        
        function Connect(varargin)
            % Connect to StimServer.exe pipe for issueing commands
            obj = StimServer.this;
            if ~obj.hPipe.isNull()
                %                 warning('StimServer:Connect:failed', ...
                %                     'StimServer connection was already established.');
                return;
            end;
            if ~libisloaded('kernel32')
                loadlibrary('kernel32', @win_kernel32);
            end;
            %             [result] = ...
            %                 calllib('kernel32', 'GetNamedPipeInfo', ...
            %                 obj.hPipe, ...
            %                 [], ...
            %                 [], ...
            %                 [], ...
            %                 []);
            %             if isequal(result, 0)
            if isequal(nargin, 0); server='.'; else server = varargin{1}; end;
            GENERIC_READ_WRITE = uint32(hex2dec('C0000000'));
            obj.hPipe = calllib('kernel32', 'CreateFileA', ...
                uint8(['\\' server '\pipe\StimServerPipe']), ...
                GENERIC_READ_WRITE, ...
                0, ...  % no sharing
                [], ...
                3, ...  % OPEN_EXISTING
                0, ...
                []);
            assert(~obj.hPipe.isNull());
            result = calllib('kernel32', 'GetNamedPipeInfo', ...
                obj.hPipe, ...
                [], ...
                [], ...
                [], ...
                []);
            if isequal(result, 0)
                obj.hPipe = libpointer;
                ConstructorResult = calllib('kernel32', 'GetLastError');
                if ~isequal(ConstructorResult, 0)
                    ConstructorResult
                end
                error('StimServer:Constructor:failed', ...
                    'Can''t connect to StimServer''s pipe. Is the server running ?');
            end
            %             disp('Connected to StimServer pipe');
        end
        
        function Disconnect()
            % Disconnect from StimServer.exe pipe
            temp = StimServer.this;
            assert(~isequal(0, calllib('kernel32', 'CloseHandle', temp.hPipe)));
            temp.hPipe = libpointer;
            %             disp('Disconnected from StimServer pipe');
        end
        
        function delete()
            StimServer.Disconnect();
            munlock;
            clear StimServer;
        end
        
        function SetBackgroundColor(color)
            % Set the full screen background color (24-bit RGB)
            StimServer.Command(0, uint8([0 color]));
        end
        
        function SetDefaultDrawColor(color)
            % Set the default draw color of Symbols and Rectangle
            StimServer.Command(0, uint8([1 5 color]));
        end
        
        function PDshow(shown)
            % Enable (shown=1) or disable (shown=0) photo diode
            StimServer.Command(0, uint8([0 shown]));
        end
        
        function PDmode(lit)
            % Change mode of photo diode. 0=off, 1=on, 2=toggle, 3=flicker
            StimServer.Command(0, uint8([16 lit]));
        end
        
        function Defer(deferred)
            % Enable (1) or disable (0) grouping of following commands
            StimServer.Command(0, uint8([1 deferred]));
        end
        
        function RemoveAll()
            % Remove all stimuli
            StimServer.Command(0, uint8(0));
        end
        
        function ShowAll(visible)
            % Make all stimuli visible (1) or invisible (0)
            StimServer.Command(0, uint8([0 0 visible]));
        end
        
        function SetDefaultFinalAction(mask)
            StimServer.Command(0, uint8([1 3 mask]));
        end
        
        function frameRate = GetFrameRate
            StimServer.Command(0, uint8([1 8]));
            frameRate = StimServer.read1single();
        end
        
    end
    
    methods (Static, Hidden=true)
        
        function Write(cmdMessage)
            nWritten = uint32(0);
            [result, ~, cmdMessage, nWritten] = ...
                calllib('kernel32', 'WriteFile', ...
                StimServer.this.hPipe, ...
                cmdMessage, ...
                length(cmdMessage), ...
                nWritten, ...
                []);
            if isequal(result, 0)
                result = calllib('kernel32', 'GetLastError');
                assert(false);
            end
            assert(nWritten == length(cmdMessage), 'Could not write message to StimServer pipe');
        end
        
        function Command(key, bytearr)
            StimServer.Write([typecast(uint16(key), 'uint8') uint8(bytearr)]);
        end
        
        function key = ReadAck()
            key = uint16(0);
            nRead = uint32(0);
            [result, ~, key, nRead] = ...
                calllib('kernel32', 'ReadFile', ...
                StimServer.this.hPipe, ...
                key, ...
                2, ...
                nRead, ...
                []);
            assert(nRead == 2, 'Could not read stimulus key from StimServer pipe');
        end
        
        function result = read1single()
            result = single(0);
            nRead = uint32(0);
            [~, ~, result, nRead] = ...
                calllib('kernel32', 'ReadFile', ...
                StimServer.this.hPipe, ...
                result, ...
                4, ...
                nRead, ...
                []);
            assert(nRead == 4, 'Could not read position from StimServer pipe');
%            result = typecast(result, 'single');
        end
        
        function pos = read2single()
            pos = uint64(0);
            nRead = uint32(0);
            [~, ~, pos, nRead] = ...
                calllib('kernel32', 'ReadFile', ...
                StimServer.this.hPipe, ...
                pos, ...
                8, ...
                nRead, ...
                []);
            assert(nRead == 8, 'Could not read position from StimServer pipe');
            pos = typecast(pos, 'single');
        end
        
    end
    
end

