classdef (Sealed) SGLEyeServerProc < SPCServerProc
    % [SINGELTON] EYE SERVER PROCESS 
    
    % INHERITANCE:
    %   SGLEyeServerProc < ...
    %       SPCServerProc < handle
    
    % INHERITED PROPERTIES:
    %   FPATH % filepath manager object
    
    
    %------------------------------------------%
    % 29.4.2016 - Jarrod, wrote class

    methods (Static)
        function this = launch
            persistent thisObj
            if isempty(thisObj) || ~isvalid(thisObj)
                thisObj = SGLEyeServerProc;
            end
            this = thisObj;
        end
    end
    
    methods (...
            Access = private,...
            Hidden = true)
        %# constructor
        function this = SGLEyeServerProc
            % create diary 
            this.mCreateProcessDiary('EyeServer');
            % always print header 
            this.mPrintErrorLogHeader('Eye Server');
            % ensure command line is writtent to txt file 
            this.mFlushDiary; 
        end
    end
    
    
    methods
        function mRunServer(this)
            % Create Pipes 
            CorePipe = SGLEyeServerCorePipe.launch;   % instance of Eye-Core Pipe
            CorePipe.mOpenServer;                     % connect as server
            this.mWriteToDiary('Opened Core Pipe ', true);
            
            CntlPipe = SGLEyeServerCntlPipe.launch;   % instance of Eye-ControlScreen Pipe
            CntlPipe.mOpenServer;                     % connect as server
            this.mWriteToDiary('Opened Control Screen Pipe ', true);

            % launch eye server 
            EyelinkServer = SGLEyeServer.launch;

            %----------------------------%
            this.mWriteToDiary('Waiting for Start Commmand', true);
            flag_runProc = true;  % quit_proc
            while flag_runProc
                
                [msg, byte_msg] = CorePipe.mReadMessageKey;
                
                switch char(msg)
                    case 'start_eye'
                        flag_runProc = this.mRunPollEyeSignalLoop(CorePipe,CntlPipe,EyelinkServer);
                    case 'quit_proc'
                        flag_runProc = false;
                    case ''
                        % no message in pipe
                    otherwise
                        % ignore message
                end
                % slow poll rate 
                java.lang.Thread.sleep(1); % 1ms
            end
            
            %---------------------------%
            this.mWriteToDiary('Quit process command', false);
            this.mWriteToDiary('Cleaning up', true);
            
            % setup better disconnect
            delete(CorePipe);
            delete(CntlPipe);
            delete(EyelinkServer);
        end
    end
    
    methods (Access = private)

        %# poll eye signal loop
        % 1. fetch eye data 
        % 2. check for commands 
        % 2. respond to command
        function flag = mRunPollEyeSignalLoop(this, CorePipe, CntlPipe, EyelinkServer)
            % hold copy of:
            %   CorePipe 
            %   CntlPipe
            %   EyelinkServer
            this.mWriteToDiary('Polling Eye Signal Started', false);

            while 1 % enter poll loop
                
                % fetch eye signal 
                eye_pos = EyelinkServer.mFetchEyePosition;

                %---------------------------%
                %     listen to Core
                %---------------------------%
                [core_msg, byte_msg] = CorePipe.mReadMessageKey;
                
                switch char(core_msg)
                    case 'request_eye'
                        success = CorePipe.mWriteEyeData(eye_pos); %#ok<*NASGU>
                    case 'stop_eye'
                        flag = true;
                        break;
                    case 'quit_proc'
                        flag = false; % leave
                        break;
                    case ''
                        % no message in pipe
                    otherwise
                        % ignore message
                end
                
                %---------------------------%
                %  listen to ControlScreen
                %---------------------------%
                [cntl_msg, byte_msg]  = CntlPipe.mReadMessageKey;
                
                switch char(cntl_msg)
                    case 'request_eye'
                        success = CntlPipe.mWriteEyeData(eye_pos);
                    case ''
                        % no message in pipe
                    otherwise
                        % do nothing
                end
                
                %drawnow;
                % slow poll rate
                java.lang.Thread.sleep(1); % 1ms
                
            end % end of while
            this.mWriteToDiary('Stopped Polling Eye Signal', false);  
        end
        
    end
    
end

