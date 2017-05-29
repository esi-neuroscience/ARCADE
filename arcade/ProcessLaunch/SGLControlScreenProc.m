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
            
            readyEvent = IPCEvent('controlScreenReady');
            readyEvent.OpenEvent();
            readyEvent.trigger();
            
            
            SGLTrialDataPipe.Open();
            this.mWriteToDiary('Opened Core Pipe', true);
            
            %----------------------------%
            this.mWriteToDiary('Waiting for start commmand', true);
            startEvent = IPCEvent('startControlScreenLoop');
            startEvent.CreateEvent();
            
            wasTriggered = startEvent.waitForTrigger(30000);
            if ~wasTriggered
                error('Did not receive start command')
            end
            
            
            this.mRunControlScreenLoop;
            drawnow; % flush events
            java.lang.Thread.sleep(1);
            
            
            %---------------------------%
            this.mWriteToDiary('Quit process command', false);
            this.mWriteToDiary('Cleaning up', true);
            
            % setup better disconnect
            delete(CorePipe);
            
        end
    end
    
    methods (Access = private)
        
        %# poll eye signal loop
        % 1. fetch eye data
        % 2. check for commands
        % 2. respond to command
        function flag = mRunControlScreenLoop(this)
            
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
            
            eyeClient = EyeClient;
            stopControlScreenEvt = IPCEvent('StopControlScreen');
            stopControlScreenEvt.CreateEvent();
            pauseCoreEvt = IPCEvent('PauseCoreRequested');
            pauseCoreEvt.OpenEvent();
            while ~stopControlScreenEvt.wasTriggered()
                
                if CntlScreen.keyPressed
                    switch CntlScreen.userRequest
                        case 'pause_request'
                            pauseCoreEvt.trigger()
                    end
                    CntlScreen.keyPressed = false;
                end
                
                % update eye position
                eye_pos = eyeClient.eyePosition;
                PltEyePos.mUpdate(eye_pos);
                drawnow('expose');
                
                
                % check for trial data from Core
                trialData = SGLTrialDataPipe.ReadTrialData();
                
                if ~isempty(trialData)
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
                    flag = false;
                    drawnow; % flush events
                end
                
                java.lang.Thread.sleep(10); % pause a bit
            end
            this.mWriteToDiary('Exiting loop', true);
            
            delete(PltEyePos);
            delete(CntlScreen);
            delete(ShrdDataPool);
        end
        
    end
    
end

