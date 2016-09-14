classdef (Sealed) SGLControlScreenProc < SPCServerProc
    % [SINGELTON] CONTROLSCREEN PROCESS
    
    % INHERITANCE:
    %   SGLControlScreenProc < ...
    %       SPCServerProc < handle
    
    % INHERITED PROPERTIES:
    %   FPATH % filepath manager object
    
    
    %------------------------------------------%
    % 29.4.2016 - Jarrod, wrote class
    % 16.5.2016 - Jarrod, 
    %   - debugged class 
    
    methods (Static)
        function this = launch
            persistent thisObj
            if isempty(thisObj) || ~isvalid(thisObj)
                thisObj = SGLControlScreenProc;
            end
            this = thisObj;
        end
    end
    
    methods (...
            Access = private,...
            Hidden = true)
        %# constructor
        function this = SGLControlScreenProc
            % create diary
            this.mCreateProcessDiary('ControlScreen');
            % always print header
            this.mPrintErrorLogHeader('Control Screen');
            % ensure command line is writtent to txt file 
            this.mFlushDiary;
        end
    end
    
    
    methods 
        function mRunServer(this)
            %     CREATE PIPES
            %---------------------------%
            % Connect to two open pipes
            % 1. connect to core to recieve commands and trial data
            % 2. connect to eye server to request/receive eye data
            
            CorePipe = SGLCoreCntlPipe.launch;      % instance of Core-ControlScreen Pipe
            CorePipe.mOpenServer;                   % connect as server
            this.mWriteToDiary('Opened Core Pipe', true);
            % *creating this pipe informs Core that this process has launched
            
            EyePipe  = SGLEyeServerCntlPipe.launch; % instance of EyeServer Pipe
            EyePipe.mOpenClient;                    % connect as client
            this.mWriteToDiary('Opened Eyelink Pipe', true);

            %----------------------------%
            this.mWriteToDiary('Waiting for Start Commmand', true);
            flag_runProc = true;  % quit_proc
            while flag_runProc
                
                [msg, byte_msg] = CorePipe.mReadMessageKey; %#ok<*NASGU>
                
                switch char(msg)
                    case 'start'
                        this.mWriteToDiary('Start Control Screen', true);
                        flag_runProc = this.mRunControlScreenLoop(CorePipe,EyePipe);
                    case 'quit_proc'
                        flag_runProc = false;
                    case ''
                        % no message in pipe
                    otherwise
                        % ignore message
                end
                drawnow; % flush events
                java.lang.Thread.sleep(1);
            end
            
            %---------------------------%
            this.mWriteToDiary('Quit process command', false);
            this.mWriteToDiary('Cleaning up', true);

            % setup better disconnect
            delete(CorePipe);
            delete(EyePipe);
        end
    end
    
    methods (Access = private)
        
        %# poll eye signal loop
        % 1. fetch eye data
        % 2. check for commands
        % 2. respond to command
        function flag = mRunControlScreenLoop(this,CorePipe, EyePipe)
            
            %---------------------------%
            % 1. Launch Control Screen Gui
            % 2. Create Eye Plot
            % 3. Create Shared Data Pool
            
            % Launch/Initialize ControlScreen
            CntlScreen = ControlScreen.launch;
            % + obj.mUpdateControlDisplay(task, data) ['update', trlMetrics]
            
            % launch Eye Plot
            PltEyePos = SGLEyePosition.launch(CntlScreen.hfig);
            
            % Launch SharedDataPool
            ShrdDataPool = SGLSharedDataPool.launch(CntlScreen.hfig);
            % + obj.mUpdateTrialData(trialData)        -> message stream
            % + trlMetrics = obj.mComputeTrialMetrics  -> after data has been set
            
            %---------------------------%
            %set(0, 'currentfigure', CntlScreen.hfig);
            
            guiperf = zeros(1,2); % [WriteTime, UpdateTime]

            %CntlScreen.mForceFocus;
            this.mWriteToDiary('Entering loop', true);
            
            while 1
                % ----- Pause Requested ------%
                if CntlScreen.keyPressed
                    % ensure it is sent
                    success = false;
                    while ~success % pause/quit
                        success = CorePipe.mWriteCommandMessage(CntlScreen.userRequest);
                    end
                    CntlScreen.keyPressed = false;
                end
                
                % ------ Request Eye ------ %
                eye_pos = EyePipe.mRequestEyeData;
                if ~isempty(eye_pos)
                    PltEyePos.mUpdate(eye_pos);
                    drawnow('expose');
                end
                
                % ------ Check Core  ------ %
                [core_msg, byte_msg] = CorePipe.mReadMessageKey;
                
                switch char(core_msg)
                    case 'trial_data'
                        %CntlScreen.mForceForward;
                        %java.lang.Thread.sleep(1); % pause a bit
                        %CntlScreen.mForceFocus;
                        % force as current figure each trial
                        %set(0, 'currentfigure', CntlScreen.hfig);
                        % convert from byte message
                        trialData = CorePipe.mIOTrialData('Read', byte_msg(3:end));
                        
                        %
                        %disp(['this trial: ', num2str(trialData)]);
                        
                        % update trial data store
                        ShrdDataPool.mUpdateTrialData(trialData);
                        
                        % compute trial metrics
                        trlMetrics = ShrdDataPool.mComputeTrialMetrics;
                        trlMetrics.guiperf = guiperf; % add gui performance
                        
                        % update control screen
                        t = tic;
                        CntlScreen.mUpdateControlDisplay('update', trlMetrics);
                        drawnow('expose'); % just update graphics
                        
                        % get the gui update time
                        guiperf(1) = trialData(7);% write BHV time
                        guiperf(2) = round(toc(t)*1000);
                        
                    case 'stop'
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
                
                drawnow; % flush events 
                java.lang.Thread.sleep(1); % pause a bit
            end
            this.mWriteToDiary('Exiting loop', true);
            
            delete(PltEyePos);
            delete(CntlScreen);
            delete(ShrdDataPool);
        end
        
    end
   
end

