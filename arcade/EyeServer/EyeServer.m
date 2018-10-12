classdef EyeServer < handle
    % EyeServer - Class for communicating with EyeServer
    
    properties (Constant, Access = private, Hidden = true)
        this = EyeServer
    end
    
    properties (Access = private, Transient = true, Hidden = true)
        hPipe = libpointer;
        isConnected = false;
    end
    
    methods (Access = protected, Hidden=true)
        function obj = EyeServer()
            %            mlock;
        end
    end
    
    methods (Static)        
        function Connect(varargin)
            % Connect to EyeServer
            obj = EyeServer.this;
            if ~obj.hPipe.isNull()
                warning('EyeServer:Connect:failed', ...
                    'EyeServer connection was already established.');
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
                error('EyeServer:Constructor:failed', ...
                    'Can''t connect to EyeServer''s pipe. Is the server running ?');
            end
            obj.isConnected = true;
        end
        
        function Disconnect()
            % Disconnect from EyeServer
            temp = EyeServer.this;
            if temp.isConnected
                assert(~isequal(0, calllib('kernel32', 'CloseHandle', temp.hPipe)));
                temp.hPipe = libpointer;
                temp.isConnected = false;
            end
        end
        
        function isConnected = GetConnectionStatus()
            % Retreive connection status with EyeServer
            temp = EyeServer.this;
            isConnected = temp.isConnected;
        end
        
        function delete()
            EyeServer.Disconnect();
            munlock;
            clear EyeServer;
        end
        
        function SetScreenSize(width, height)
            EyeServer.Command(0, uint8([0 1 typecast(uint16([width height]), 'uint8')]));
        end
        
        function Start(varargin)
            if isequal(nargin(), 0)
                EyeServer.Command(0, uint8([0 2]));
            else
                EyeServer.Command(0, uint8([0 2 varargin{1} 0]));
            end
        end
        
        function Transform(varargin)
		% Transform()					remove transformation
		% Transform([x0 y0 x1 y1])		coefficients for linear transformation
		% Transform([x0 y0 x1 y1 x2 y2])coefficients for quadratic transformation
            if isequal(nargin(), 0)
                EyeServer.Command(0, uint8([0 3]));
            else
                EyeServer.Command(0, uint8([0 3 typecast(single(varargin{1}),'uint8')]));
            end
        end
        
        function Stop(varargin)
            if isequal(nargin(), 0)
                EyeServer.Command(0, uint8([0 0]));
            else
                EyeServer.Command(0, uint8([0 0 varargin{1} 0]));
            end
        end
                
    end
    
    methods (Static, Hidden=true)
        
        function Write(cmdMessage)
            if isNull(EyeServer.this.hPipe)
                error('EyeServer:Unconnected', ...
                    'No connection to EyeServer.');
            end
            nWritten = uint32(0);
            [result, ~, cmdMessage, nWritten] = ...
                calllib('kernel32', 'WriteFile', ...
                EyeServer.this.hPipe, ...
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
            EyeServer.Write([typecast(uint16(key), 'uint8') uint8(bytearr)]);
        end
        
        function key = ReadAck()
            key = uint16(0);
            nRead = uint32(0);
            [result, ~, key, nRead] = ...
                calllib('kernel32', 'ReadFile', ...
                EyeServer.this.hPipe, ...
                key, ...
                2, ...
                nRead, ...
                []);
            assert(nRead == 2, 'Could not read target key from EyeServer pipe');
        end
    end
end

