classdef (Sealed = true) StimServer < handle
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
    
    properties (Constant, Access = private, Hidden = true)
        this = StimServer
    end
    
    properties ( Constant, GetAccess = public, Hidden = true )
        doneEventName = 'StimServerDone'
    end

    properties (Access = private, Transient = true, Hidden = true)
        hPipe = libpointer;
    end
    
    methods (Access = private, Hidden=true)
        function obj = StimServer()
            % mlock;
        end
    end
    
    methods (Static)
        
        function Connect(varargin)
            % Connect to StimServer.exe pipe for issueing commands
            obj = StimServer.this;
            if ~obj.hPipe.isNull()
                return;
            end
            if ~libisloaded('kernel32')
                loadlibrary('kernel32', @win_kernel32);
            end
  
            if isequal(nargin, 0)
                server='.'; 
            else 
                server = varargin{1}; 
            end

            GENERIC_READ_WRITE = uint32(hex2dec('C0000000'));
            obj.hPipe = calllib('kernel32', 'CreateFileA', ...
                uint8(['\\' server '\pipe\StimServerPipe']), ...
                GENERIC_READ_WRITE, ...
                0, ...  % no sharing
                [], ...
                3, ...  % OPEN_EXISTING
                0, ...
                []);
            assert(~obj.hPipe.isNull(), ...
                'Can''t connect to StimServer''s pipe. Is the server running ?');                           
        end
        
        function Disconnect()
            % Disconnect from StimServer.exe pipe
            temp = StimServer.this;
            assert(~isequal(0, calllib('kernel32', 'CloseHandle', temp.hPipe)));
            temp.hPipe = libpointer;
            %             disp('Disconnected from StimServer pipe');
        end
        
        function delete()
            StimServer.Disconnect();
            munlock;
            clear StimServer;
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

        function isConnected = GetConnectionStatus()
            % Retreive connection status with StimServer
            obj = StimServer.this;
            isConnected = ~obj.hPipe.isNull();
        end

        function waitResult = waitUntilDone(timeout)
            waitResult = IPCEvent.wait_for_event(StimServer.doneEventName, timeout);
        end
    end
    
    methods (Static, Hidden=true)
        
        function Write(cmdMessage)
            nWritten = uint32(0);
            [result, ~, cmdMessage, nWritten] = ...
                calllib('kernel32', 'WriteFile', ...
                StimServer.this.hPipe, ...
                cmdMessage, ...
                length(cmdMessage), ...
                nWritten, ...
                []);
            if isequal(result, 0)
                result = calllib('kernel32', 'GetLastError');
                assert(false);
            end
            assert(nWritten == length(cmdMessage), 'Could not write message to StimServer pipe');
        end
        
        function Command(key, bytearr)
            StimServer.Write([typecast(uint16(key), 'uint8') uint8(bytearr)]);
        end
        
        function key = ReadAck()
            key = uint16(0);
            nRead = uint32(0);
            [result, ~, key, nRead] = ...
                calllib('kernel32', 'ReadFile', ...
                StimServer.this.hPipe, ...
                key, ...
                2, ...
                nRead, ...
                []);
            assert(nRead == 2, 'Could not read stimulus key from StimServer pipe');
        end
        
        function result = read1single()
            result = single(0);
            nRead = uint32(0);
            [~, ~, result, nRead] = ...
                calllib('kernel32', 'ReadFile', ...
                StimServer.this.hPipe, ...
                result, ...
                4, ...
                nRead, ...
                []);
            assert(nRead == 4, 'Could not read position from StimServer pipe');
%            result = typecast(result, 'single');
        end
        
        function pos = read2single()
            pos = uint64(0);
            nRead = uint32(0);
            [~, ~, pos, nRead] = ...
                calllib('kernel32', 'ReadFile', ...
                StimServer.this.hPipe, ...
                pos, ...
                8, ...
                nRead, ...
                []);
            assert(nRead == 8, 'Could not read position from StimServer pipe');
            pos = typecast(pos, 'single');
        end
        
    end
    
end

