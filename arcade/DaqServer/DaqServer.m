classdef DaqServer < handle
    % DAQSERVER - Class for communicating with DaqServer
    
    properties (Constant, Access = private, Hidden = true)
        this = DaqServer
    end
    
    properties (Access = private, Transient = true, Hidden = true)
        hPipe = libpointer;
        isConnected = false;
    end
    
    methods (Access = protected, Hidden=true)
        function obj = DaqServer()
            %            mlock;
        end
    end
    
    methods (Static)        
        function Connect(varargin)
            % Connect to DaqServer
            obj = DaqServer.this;
            if ~obj.hPipe.isNull()
                warning('DaqServer:Connect:failed', ...
                    'DaqServer connection was already established.');
                return;
            end;
            if ~libisloaded('kernel32')
                loadlibrary('kernel32', @win_kernel32);
            end;
            if isequal(nargin, 0); 
                server='.'; 
                pipeName='\pipe\NidaqServerPipe';
            else                 
                server = varargin{1}; 
                pipeName = varargin{2}; 
            end;

            GENERIC_READ_WRITE = uint32(hex2dec('C0000000'));
            obj.hPipe = calllib('kernel32', 'CreateFileA', ...
                uint8(['\\' server pipeName 0]), ...
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
                error('DaqServer:Constructor:failed', ...
                    'Can''t connect to DaqServer''s pipe. Is the server running ?');
            end
            obj.isConnected = true;
        end
        
        function Disconnect()
            % Disconnect from DaqServer
            temp = DaqServer.this;
            if temp.isConnected
                assert(~isequal(0, calllib('kernel32', 'CloseHandle', temp.hPipe)));
                temp.hPipe = libpointer;
                temp.isConnected = false;
            end
        end
        
        function isConnected = GetConnectionStatus()
            % Retreive connection status with DaqServer
            temp = DaqServer.this;
            isConnected = temp.isConnected;
        end
        
        function delete()
            DaqServer.Disconnect();
            munlock;
            clear DaqServer;
        end
        
        function AddLine(lineNumber, varargin)
            % Track status of digital input lines
            %   AddLine(lineNumber, pulseEventName)
            %   AddLine(lineNumber, onEventName, offEventName)
            switch nargin
                case 2
                    DaqServer.Write(uint8([1 lineNumber varargin{1} 0]));
                case 3
                    DaqServer.Write(uint8([2 lineNumber varargin{1} 0 varargin{2} 0]));
                otherwise
                    error('DaqServer:AddLine', ...
                        'Bad number of arguments in call to DaqServer.AddLine.');
            end
        end
        
        function Start()
            % Start tracking of digital input lines defined with AddLine
            DaqServer.Write(uint8(3));
        end
        
        function SetRewardTime(timems)
            % Set reward duration for event-triggered (manual) reward in ms
            DaqServer.Write(uint8([4 typecast(uint16(timems), 'uint8')]));
        end
        
        function Reward(times)
            % Send reward duration times in ms
            DaqServer.Write(uint8([5 typecast(uint16(times), 'uint8')]));
        end
        
        function EventMarker(markerCode)
            % Send eventmarker code to DaqServer
            DaqServer.Write(uint8([6 typecast(uint16(markerCode), 'uint8')]));
        end
        
        function SetRewardCode(code)
            % Set the event marker code for manual reward
            DaqServer.Write(uint8([7 typecast(uint16(code), 'uint8')]));
        end
        
        function totalTime = GetTotalRewardTime()
            % Retreive reward time since last retreival
            DaqServer.Write(uint8(8));
            totalTime = uint32(0);
            nRead = uint32(0);
            [result, ~, totalTime, nRead] = ...
                calllib('kernel32', 'ReadFile', ...
                DaqServer.this.hPipe, ...
                totalTime, ...
                4, ...
                nRead, ...
                []);
            assert(nRead == 4, 'Could not read total reward time from DaqServer pipe');
        end
    end
    
    methods (Static, Hidden=true)
        
        function Write(cmdMessage)
            if isNull(DaqServer.this.hPipe)
                error('DaqServer:Unconnected', ...
                    'No connection to DaqServer.');
            end
            nWritten = uint32(0);
            [result, ~, cmdMessage, nWritten] = ...
                calllib('kernel32', 'WriteFile', ...
                DaqServer.this.hPipe, ...
                cmdMessage, ...
                length(cmdMessage), ...
                nWritten, ...
                []);
            if isequal(result, 0)
                result = calllib('kernel32', 'GetLastError');
                assert(false);
            end
            assert(nWritten == length(cmdMessage));
        end
    end
end

