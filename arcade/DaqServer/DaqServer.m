classdef DaqServer < ServerInterface
    % DAQSERVER - MATLAB interface for communication with DaqServer process
    %
    % The DaqServer process handles digital input and output, i.e.
    % eventmarkers, reward, levers, etc. The communication between the Core
    % process and the DaqServer happens via a <a href="https://docs.microsoft.com/en-us/windows/desktop/ipc/named-pipes">Named Pipe</a>,
    % for which this MATLAB class provides an interface.
    %
    % Currently only one DaqServer is implemented (NidaqServer.exe), which
    % supports National Instruments devices (see the accompanying
    % NidaqServer.pdf documentation). A different DaqServer should
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
    %  Connect() : Open pipe to the DaqServer for sending commands
    %  Disconnect() : Disconnect from pipe to DaqServer
    %  AddLine(lineNumber, varargin) :
    %        Watch status of digital input line for either pulses
    %               AddLine(lineNumber, pulseEventName)
    %        or on/off states
    %               AddLine(lineNumber, onEventName, offEventName)
    %        The function trackdigitalinput provides a convenient wrapper
    %        for using this functionality.
    %   Start() : Start tracking of digital input lines defined with AddLine
    %   SetRewardTime() : Set reward duration (ms) for manual reward
    %   Reward(duration) : Set reward line to on for specified duration (ms)
    %   EventMarker(code) : Send out an eventmarker code
    %   SetRewardCode(code) : Set the event marker code sent out with a manual reward
    %   GetTotalRewardTime() : Retreive reward duration since last
    %                          retreival. Calling this method resets the
    %                          counter in the NidaqServer.
    %
    % See also eventmarker, reward, setManualRewardDuration,
    %          totalRewardTime, trackdigitalinput
    
    
    properties ( Constant, GetAccess = public, Hidden = true )
        doneEventName = 'DaqServerDone'
        pipeName= '\pipe\NidaqServerPipe';
    end
    
    methods ( Static, Access = protected )
        
        function out = SetGetHandle(value)
            persistent hPipeDaqServer;
            if nargin == 1
                hPipeDaqServer = value;
            end
            if isempty(hPipeDaqServer)
                hPipeDaqServer = libpointer;
            end
            out = hPipeDaqServer;
        end
    end
    
    methods ( Static, Access=public )
        
        function Connect()
            hPipe =  DaqServer.SetGetHandle();
            if ~hPipe.isNull()
                warning('DaqServer:Connect:failed', ...
                    'DaqServer connection was already established.');
                return
            end
            hPipe = ServerInterface.Connect(DaqServer.pipeName);
            DaqServer.SetGetHandle(hPipe);
        end
        
        function Disconnect()
            hPipe = DaqServer.SetGetHandle();
            try
                ServerInterface.Disconnect(hPipe);
            catch me
                DaqServer.SetGetHandle([]);
                rethrow(me)
            end
            DaqServer.SetGetHandle([]);
        end
        
        function isConnected = GetConnectionStatus()
            % Retreive connection status with DaqServer
            hPipe = DaqServer.SetGetHandle;
            isConnected = ~hPipe.isNull();
        end
        
        function delete()
            DaqServer.Disconnect();
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
            event = IPCEvent(DaqServer.doneEventName);
            event.reset();
            DaqServer.Write(uint8(3));
            event.waitForTrigger(1000);
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
            ServerInterface.Write(DaqServer.SetGetHandle, uint8(8));
            totalTime = read1single(hPipe);
           
        end
    end
    
    methods ( Static, Hidden=true )
        
        function Write(cmdMessage)
            hPipe = DaqServer.SetGetHandle;
            ServerInterface.Write(hPipe, cmdMessage)
        end
        
    end
    
end


