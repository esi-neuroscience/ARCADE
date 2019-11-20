classdef EyeServer < ServerInterface
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
    
    
    properties ( Constant, GetAccess = public, Hidden = true )
        pipeName = '\pipe\EyeServerPipe'
        doneEventName = 'EyeServerDone'
    end
    
    methods 
        function obj = EyeServer()           
            error(['EyeServer interface cannot be instantiated. Use its ' ...
                'static methods for communication with the EyeServer.'])
        end                
    end
    
    methods ( Static, Access = protected )
        function out = SetGetHandle(value)
            persistent hPipeEyeServer;
            if nargin == 1
                hPipeEyeServer = value;
            end
            if isempty(hPipeEyeServer)
                hPipeEyeServer = libpointer;
            end
            out = hPipeEyeServer;
        end
    end
        
    methods ( Static, Access = public )       
        
        function Connect()
            hPipe =  EyeServer.SetGetHandle();
            if ~hPipe.isNull()
                warning('EyeServer:Connect:failed', ...
                    'EyeServer connection was already established.');
                return
            end
            hPipe = ServerInterface.Connect(EyeServer.pipeName);
            EyeServer.SetGetHandle(hPipe);
        end
        
        function Disconnect()
            hPipe =  EyeServer.SetGetHandle;
            try
                ServerInterface.Disconnect(hPipe);
            catch me
                EyeServer.SetGetHandle([]);
                rethrow(me)
            end
            EyeServer.SetGetHandle([]);
        end        
        
        function isConnected = GetConnectionStatus()
            % Retreive connection status with EyeServer
            hPipe = EyeServer.SetGetHandle;
            isConnected = ~hPipe.isNull();
        end
        
        function delete()
            if EyeServer.GetConnectionStatus
                EyeServer.Disconnect();
            end
            clear EyeServer.SetGetHandle
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
        
        function Message(message)
            EyeServer.Command(0, uint8([0 4 message 0]));
        end
        
    end
    
    methods ( Static, Hidden=true )
        
        function Write(cmdMessage)
            hPipe = EyeServer.SetGetHandle;
            ServerInterface.Write(hPipe, cmdMessage)
        end
        
        function Command(key, bytearr)
            EyeServer.Write([typecast(uint16(key), 'uint8') uint8(bytearr)]);
        end
        
        function key = ReadAck()
            hPipe = EyeServer.SetGetHandle;
            key = ServerInterface.ReadAck(hPipe);
        end
    end
end

