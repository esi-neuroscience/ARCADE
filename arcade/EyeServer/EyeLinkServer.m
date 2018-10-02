classdef EyeLinkServer < handle
    % EYELINKSERVER - Class for communicating with EyeLinkServer
    
    properties (Constant, Access = private, Hidden = true)
        this = EyeLinkServer
    end
    
    properties (Access = private, Transient = true, Hidden = true)
        hPipe = libpointer;
        isConnected = false;
    end
    
    methods (Access = protected, Hidden=true)
        function obj = EyeLinkServer()
            %            mlock;
        end
    end
    
    methods (Static)        
        function Connect(varargin)
            % Connect to EyeLinkServer
            obj = EyeLinkServer.this;
            if ~obj.hPipe.isNull()
                warning('EyeLinkServer:Connect:failed', ...
                    'EyeLinkServer connection was already established.');
                return;
            end;
            if ~libisloaded('kernel32')
                loadlibrary('kernel32', @win_kernel32);
            end;
            if isequal(nargin, 0); 
                server='.'; 
                pipeName='\pipe\EyeServerPipe';
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
                error('EyeLinkServer:Constructor:failed', ...
                    'Can''t connect to EyeLinkServer''s pipe. Is the server running ?');
            end
            obj.isConnected = true;
        end
        
        function Disconnect()
            % Disconnect from EyeLinkServer
            temp = EyeLinkServer.this;
            if temp.isConnected
                assert(~isequal(0, calllib('kernel32', 'CloseHandle', temp.hPipe)));
                temp.hPipe = libpointer;
                temp.isConnected = false;
            end
        end
        
        function isConnected = GetConnectionStatus()
            % Retreive connection status with EyeLinkServer
            temp = EyeLinkServer.this;
            isConnected = temp.isConnected;
        end
        
        function delete()
            EyeLinkServer.Disconnect();
            munlock;
            clear EyeLinkServer;
        end
        
        function SetScreenSize(width, height)
            EyeLinkServer.Command(0, uint8([0 1 typecast(uint16([width height]), 'uint8')]));
        end
        
        function Start(varargin)
            if isequal(nargin(), 0)
                EyeLinkServer.Command(0, uint8([0 2]));
            else
                EyeLinkServer.Command(0, uint8([0 2 varargin{1} 0]));
            end
        end
        
        function Transform(varargin)
		% Transform()					remove transformation
		% Transform([x0 y0 x1 y1])		coefficients for linear transformation
		% Transform([x0 y0 x1 y1 x2 y2])coefficients for quadratic transformation
            if isequal(nargin(), 0)
                EyeLinkServer.Command(0, uint8([0 3]));
            else
                EyeLinkServer.Command(0, uint8([0 3 typecast(single(varargin{1}),'uint8')]));
            end
        end
        
        function Stop()
            EyeLinkServer.Command(0, uint8([0 0]));
        end
                
    end
    
    methods (Static, Hidden=true)
        
        function Write(cmdMessage)
            if isNull(EyeLinkServer.this.hPipe)
                error('EyeLinkServer:Unconnected', ...
                    'No connection to EyeLinkServer.');
            end
            nWritten = uint32(0);
            [result, ~, cmdMessage, nWritten] = ...
                calllib('kernel32', 'WriteFile', ...
                EyeLinkServer.this.hPipe, ...
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
        
        function Command(key, bytearr)
            EyeLinkServer.Write([typecast(uint16(key), 'uint8') uint8(bytearr)]);
        end
        
        function key = ReadAck()
            key = uint16(0);
            nRead = uint32(0);
            [result, ~, key, nRead] = ...
                calllib('kernel32', 'ReadFile', ...
                EyeLinkServer.this.hPipe, ...
                key, ...
                2, ...
                nRead, ...
                []);
            assert(nRead == 2, 'Could not read target key from EyeLinkServer pipe');
        end
    end
end

