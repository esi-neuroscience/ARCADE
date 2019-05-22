classdef EyeServer < handle
    % EYESERVER - MATLAB interface for communication with the EyeServer
    %             process
    % 
    % The EyeServer process handles acquisition of the eye position and
    % signals <a href="https://docs.microsoft.com/en-us/windows/desktop/Sync/event-objects">Named Events</a> when the eye enters/leaves user-defined regions on
    % the screen. Communication between the Core process and the EyeServer 
    % happens via a <a href="https://docs.microsoft.com/en-us/windows/desktop/ipc/named-pipes">Named Pipe</a>, for which this MATLAB class provides an interface.
    %
    % Currently only one EyeServer is implemented (EyeLinkServer.exe), which 
    % supports Eyelink 1000/2000 devices. A different EyeServer should
    % set up the same Named Pipe and respond to the commands implemented in
    % this class. 
    %
    % The methods listed below are not meant for the user during session
    % runtime. Instead, the corresponding functions in the UserFunctions
    % folder should be used (see help UserFunctions).
    %
    %
    % METHODS (static)
    % ----------------
    %  Connect() : Open pipe to the EyeServer for sending commands
    %  Disconnect() : Disconnect from pipe to EyeServer
    %  GetConnectionStatus() : Returns true for connect
    %  Start(filename) : Start recording and store data in filename.  
    %                    For the EyeLinkServer this filename refers to the 
    %                    Eyelink PC's filesystem.
    %  Stop(filename) : Stop recording and copy data to local filename
    %  Transform(varargin) : apply a transform to the eye position signal
    %       Transform()					remove transformation
	%       Transform([x0 y0 x1 y1])	linear transformation
    %	    Transform([x0 y0 x1 y1 x2 y2]) quadratic transformation
    %
    % See also trackeye, EyeTarget, IPCEvent
    
    properties (Constant, Access = private, Hidden = true)
        this = EyeServer
    end
    
    properties (Access = private, Transient = true, Hidden = true)
        hPipe = libpointer;        
    end
    
    properties ( Constant, GetAccess = public, Hidden = true )
        doneEventName = 'EyeServerDone'
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
            end
            if ~libisloaded('kernel32')
                loadlibrary('kernel32', @win_kernel32);
            end
            pipeName='\pipe\EyeServerPipe';
            if isequal(nargin, 0)
                server='.'; 
            else                 
                server = varargin{1}; 
                pipeName = varargin{2}; 
            end

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
                    disp(ConstructorResult)
                end
                error('EyeServer:Connect:failed', ...
                    'Can''t connect to EyeServer''s pipe. Is the server running ?');
            end
            
        end
        
        function Disconnect()
            % Disconnect from EyeServer
            temp = EyeServer.this;
            if EyeServer.GetConnectionStatus()
                assert(~isequal(0, calllib('kernel32', 'CloseHandle', temp.hPipe)));
                temp.hPipe = libpointer;                
            end
        end
        
        function isConnected = GetConnectionStatus()
            % Retreive connection status with EyeServer
            obj = EyeServer.this;
            isConnected = ~obj.hPipe.isNull();
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

