classdef DaqServer < handle
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
    %   SetRewardTime(time) : Set reward duration (ms) for manual reward
    %   SetPulseTime(line, time) : Set pulse duration (ms) for a line
    %   Reward(duration) : Set reward line to on for specified duration (ms)
    %   EventMarker(code) : Send out an eventmarker code
    %   SetRewardCode(code) : Set the event marker code sent out with a manual reward
    %   GetTotalRewardTime() : Retreive reward duration since last
    %                          retreival. Calling this method resets the
    %                          counter in the NidaqServer.
    %   OutPulseLine(lineNumber, name) : define a line to output a pulse
    %                                    when the "name" event is signaled
    %
    % See also eventmarker, reward, setManualRewardDuration,
    %          totalRewardTime, trackdigitalinput
    
    properties (Constant, Access = private, Hidden = true)
        this = DaqServer
    end
    
    properties (Access = private, Transient = true, Hidden = true)
        hPipe = libpointer;
        isConnected = false;
    end
    
    properties ( Constant, GetAccess = public, Hidden = true )
        doneEventName = 'DaqServerDone'
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
            end
            if ~libisloaded('kernel32')
                loadlibrary('kernel32', @win_kernel32);
            end
            if isequal(nargin, 0)
                server='.'; 
                pipeName='\pipe\NidaqServerPipe';
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
            event = IPCEvent('DaqServerDone');
            event.reset();
            DaqServer.Write(uint8(3));
            event.waitForTrigger(1000);
        end
        
        function SetRewardTime(timems)
            % Set reward duration for event-triggered (manual) reward in ms
            DaqServer.Write(uint8([4 typecast(uint16(timems), 'uint8')]));
        end
        
        function SetPulseTime(line, timems)
            % Set pulse duration for event-triggered pulse line  in ms
            DaqServer.Write(uint8([4 line typecast(uint16(timems), 'uint8')]));
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
            % Retrieve reward time since last retrieval
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
        
        function OutPulseLine(lineNumber, name)
            % Define line for output pulses
            %   OutPulseLine(lineNumber, pulseEventName)
            DaqServer.Write(uint8([9 lineNumber name 0]));
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

