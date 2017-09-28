classdef (Sealed = true) NidaqServer < handle
    
    properties (Constant, Access = private, Hidden = true)
        this = NidaqServer
    end
    
    properties (Access = private, Transient = true, Hidden = true)
        hPipe = libpointer;
        isConnected = false;
    end
    
    methods (Access = private, Hidden=true)
        function obj = NidaqServer()
%            mlock;
        end
    end
    
    methods (Static)
        
        function Connect(varargin)
            obj = NidaqServer.this;
            if ~obj.hPipe.isNull()
                warning('NidaqServer:Connect:failed', ...
                    'NidaqServer connection was already established.');
                return;
            end;
            if ~libisloaded('kernel32')
                loadlibrary('kernel32', @win_kernel32);
            end;
            if isequal(nargin, 0); server='.'; else server = varargin{1}; end;
            GENERIC_READ_WRITE = uint32(hex2dec('C0000000'));
           obj.hPipe = calllib('kernel32', 'CreateFileA', ...
                uint8(['\\' server '\pipe\NidaqServerPipe' 0]), ...
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
                error('NidaqServer:Constructor:failed', ...
                    'Can''t connect to NidaqServer''s pipe. Is the server running ?');
            end
            obj.isConnected = true;
            disp('Connected to pipe');
        end
        
        function Disconnect()
            temp = NidaqServer.this;
            assert(~isequal(0, calllib('kernel32', 'CloseHandle', temp.hPipe)));
            temp.hPipe = libpointer;
            disp('Disconnected from pipe');
            temp.isConnected = false;
        end
        
        function isConnected = GetConnectionStatus()
            temp = NidaqServer.this;
            isConnected = temp.isConnected;
        end
        
        function delete()
            NidaqServer.Disconnect();
            munlock;
            clear NidaqServer;
        end
        
        function AddLine(lineNumber, varargin)
            % AddLine(lineNumber, pulseEventName)
            % AddLine(lineNumber, onEventName, offEventName)
            switch nargin
                case 2
                    NidaqServer.Write(uint8([1 lineNumber varargin{1} 0]));
                case 3
                    NidaqServer.Write(uint8([2 lineNumber varargin{1} 0 varargin{2} 0]));
                otherwise
                    error('NidaqServer:AddLine', ...
                        'Bad number of arguments in call to NidaqServer.AddLine.');
            end
        end
        
        function Start()
            NidaqServer.Write(uint8(3));
        end
        
        function SetRewardTime(timems)
            NidaqServer.Write(uint8([4 typecast(uint16(timems), 'uint8')]));
        end
        
        function Reward(times)
            NidaqServer.Write(uint8([5 typecast(uint16(times), 'uint8')]));
        end
        
        function EventMarker(markerCode)
            NidaqServer.Write(uint8([6 typecast(uint16(markerCode), 'uint8')]));
        end

	   % set the event marker code for manual reward 
        function SetRewardCode(code)
            NidaqServer.Write(uint8([7 typecast(uint16(code), 'uint8')]));
        end
        
    end
    
    methods (Static, Hidden=true)
        
        function Write(cmdMessage)
            if isNull(NidaqServer.this.hPipe)
                error('NidaqServer:Unconnected', ...
                    'No connection to NidaqServer.');
            end
            nWritten = uint32(0);
            [result, ~, cmdMessage, nWritten] = ...
                calllib('kernel32', 'WriteFile', ...
                NidaqServer.this.hPipe, ...
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

