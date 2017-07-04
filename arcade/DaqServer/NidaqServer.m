classdef (Sealed = true) NidaqServer < handle
    
    properties (Constant, Access = private, Hidden = true)
        this = NidaqServer
    end
    
    properties (Access = private, Transient = true, Hidden = true)
        hPipe = libpointer;
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
            disp('Connected to pipe');
        end
        
        function Disconnect()
            temp = NidaqServer.this;
            assert(~isequal(0, calllib('kernel32', 'CloseHandle', temp.hPipe)));
            temp.hPipe = libpointer;
            disp('Disconnected from pipe');
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
                    error(NidaqServer:AddLine, ...
                        'Bad number of arguments in call to NidaqServer.AddLine.');
            end
        end
        
        function Start()
            NidaqServer.Write(uint8(3));
        end
    end
    
    methods (Static, Hidden=true)
        
        function Write(cmdMessage)
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

