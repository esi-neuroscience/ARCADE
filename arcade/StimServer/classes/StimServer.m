classdef (Sealed = true) StimServer < ServerInterface
    % STIMSERVER - MATLAB interface for communication with StimServer.exe
    %
    % The StimServer process displays visual stimuli on screen.
    % Visual stimuli are controlled by sending commands via a
    % <a href="https://docs.microsoft.com/en-us/windows/desktop/ipc/named-pipes">Named Pipe</a>, for which this MATLAB class provides an interface.
    %
    % USAGE
    % -----
    % StimServer.exe must be started before using this class. The Connect method
    % must be called before any other commands can be sent. The methods
    % listed below are not meant for the user during session
    % runtime. Instead, Stimulus classes (see help Stimuli) and the
    % corresponding functions in the UserFunctions folder should be used (see help UserFunctions).
    %
    % METHODS (static)
    % ----------------
    %  Connect() : Open pipe to StimServer.exe for sending commands
    %  Defer(deferred) : Enable (deferred=1) or disable (deferred=0)
    %                    grouping of following commands
    %  Disconnect() : Disconnect from StimServer.exe
    %  GetConnectionStatus() : Returns status of StimServer pipe connection.
    %  GetFrameRate() : Returns current frame rate of StimServer screen
    %  PDmode(mode) : Change mode of photo diode. 0=off, 1=on, 2=toggle, 3=flicker
    %  PDposition(pos) : Change position of photo diode. 0=upper left, 1=lower left
    %  PDshow(shown) : Enable (shown=1) or disable (shown=0) photo diode
    %  SetBackgroundColor(color) : Set the full screen background color (24-bit RGB)
    %  SetDefaultDrawColor(color) : Set the default draw color of Symbols and Shapes
    %  SetDefaultFinalAction(mask) : Set default terminal action for Animations
    %  ShowAll(visible) : Make all stimuli visible (1) or invisible (0).
    %                     This doesn't update the Stimulus MATLAB objects.
    %
    % For more information, see the accompanying StimServer documentation
    % (StimServer.pdf) and <a href="matlab:doc('arcade')">the ARCADE guide</a>.
    %
    % See also Stimulus, backgroundColor, win_kernel32, groupStimuli,
    %          photodiode,
    
    
    properties ( Constant, GetAccess = public, Hidden = true )
        doneEventName = 'StimServerDone'
        pipeName = '\pipe\StimServerPipe'
    end
    
    methods (Access = private, Hidden=true)
        function obj = StimServer()
            
        end
    end
    
    methods ( Static, Access = protected )
        function out = SetGetHandle(value)
            persistent hPipeStimServer;
            if nargin == 1
                hPipeStimServer = value;
            end
            if isempty(hPipeStimServer)
                hPipeStimServer = libpointer;
            end
            out = hPipeStimServer;
        end
    end
    
    
    methods (Static)
        
        function Connect()
            hPipe =  StimServer.SetGetHandle();
            if ~hPipe.isNull()
                warning('StimServer:Connect:failed', ...
                    'StimServer connection was already established.');
                return
            end
            hPipe = ServerInterface.Connect(StimServer.pipeName);
            StimServer.SetGetHandle(hPipe);
        end
        
        function Disconnect()
            hPipe =  StimServer.SetGetHandle;
            try
                ServerInterface.Disconnect(hPipe);
            catch me
                StimServer.SetGetHandle([]);
                rethrow(me)
            end
            StimServer.SetGetHandle([]);
        end
        
        function isConnected = GetConnectionStatus()
            % Retreive connection status with server
            hPipe = StimServer.SetGetHandle;
            isConnected = ~hPipe.isNull();
        end
        
        function delete()
            StimServer.Disconnect();
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
        
        function PDposition(pos)
            % Change position of photo diode. 0=upper left, 1=lower left
            StimServer.Command(0, uint8([16 3 pos]));
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
        
        
        function waitResult = waitUntilDone(timeout)
            waitResult = IPCEvent.wait_for_event(StimServer.doneEventName, timeout);
        end
    end
    
    methods (Static, Hidden=true)
        
        function Write(cmdMessage)
            hPipe = StimServer.SetGetHandle;
            ServerInterface.Write(hPipe, cmdMessage)
        end
        
        function Command(key, bytearr)
            StimServer.Write([typecast(uint16(key), 'uint8') uint8(bytearr)]);
        end
        
        function key = ReadAck()
            hPipe = StimServer.SetGetHandle;
            key = ServerInterface.ReadAck(hPipe);
        end
        
        function result = read1single()
            hPipe = StimServer.SetGetHandle;
            result = ServerInterface.read1single(hPipe);
        end
        
        function pos = read2single()
             hPipe = StimServer.SetGetHandle;
             pos = ServerInterface.read2single(hPipe);
        end
        
    end
    
end

