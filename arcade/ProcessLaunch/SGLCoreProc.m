classdef (Sealed) SGLCoreProc < SPCServerProc
    % [SINGELTON] CORE PROCESS
    % runs user script
    % handles timing
    % launches other server processes
    
    % INHERITANCE:
    %   SGLCoreProc < ...
    %       SPCServerProc < handle
    
    % INHERITED PROPERTIES:
    %   FPATH % filepath manager object
    
    
    %------------------------------------------%
    %  2.5.2016 - Jarrod, wrote class
    % 16.5.2016 - Jarrod, 
    % - debugged class 
    
    methods (Static)
        function this = launch
            persistent thisObj
            if isempty(thisObj) || ~isvalid(thisObj)
                thisObj = SGLCoreProc;
            end
            this = thisObj;
        end
    end
    
    methods (...
            Access = private,...
            Hidden = true)
        %# constructor
        function this = SGLCoreProc
            % create diary
            this.mCreateProcessDiary('Core');
            % print header
            this.mPrintErrorLogHeader('Core');
            % seed randomnumber generator
            this.mInitilazeRandomNumberGenerator;
            % ensure command line is writtent to txt file
            this.mFlushDiary;
        end
    end
    
    
    methods
        %# run core process
        function mRunServer(this)
            % move to tasks folder
            cd(this.FPATH.pathTaskDirectory);
            
            % launch Main Screen
            MSgui = MainScreen.launch;
            
            if ~ishghandle(MSgui.hfig)
                delete(MSgui)
                fclose('all')
                return    
            end
            
                        
            cfg = MSgui.cfg; % get cfg file
            cfg.taskFile = MSgui.taskFile;
            
            % close main screen
            delete(MSgui);
            drawnow()
            
            this.mWriteToDiary('Starting Reward Server', true);
            rewServer   = SGLRewardServer.launch;
            
            this.mWriteToDiary('Starting Event Server', true);
            evtFile = fullfile(cfg.filepaths.Behaviour, [cfg.Subject '_' today() '_' cfg.Experiment '_' cfg.Session '.evt']);
            eventServer = SGLEventMarkerServer.launch(evtFile);
            
            % Create TrialData pipe
            SGLTrialDataPipe.Create();
            
            % launch ControlScreen process
            this.mWriteToDiary('Starting ControlScreen', true)
            controlScreenReadyEvt = IPCEvent('controlScreenReady');
            controlScreenReadyEvt.CreateEvent();            
            controlScreenProcess = this.mLaunchServer('ControlScreen'); 
            
            % launch EyeServer process
            this.mWriteToDiary('Starting EyeServer', true)
            eyeServerReadyEvt = IPCEvent('eyeServerReadyEvt');
            eyeServerReadyEvt.CreateEvent();            
            eyeProcess = this.mLaunchServer('EyeServer');
            
            % launch StimServer process
            this.mWriteToDiary('Starting StimServer', true)
            stimServerProcess = processManager('id', 'StimServer', ...
                'command', 'StimServer.exe', ...
                'printStdout', false, ...
                'printStderr', false);
            
            
            
            this.mWriteToDiary('Waiting for processes', true)
            controlScreenReadyEvt.waitForTrigger(20000);
%             eyeServerReadyEvt.waitForTrigger(20000);
                      
                       
            % connect to StimServer            
            StimServer.Connect();
            
            % Run session
            startEvent = IPCEvent('startControlScreenLoop');
            startEvent.OpenEvent();
            startEvent.trigger();
                        
            this.mWriteToDiary('Starting Session', true);
            this.mRunSession(cfg);
            
            
            

            
            %----------------------------------------%
            
            % delete objects
            this.mWriteToDiary('Closing', true);
            
            delete(rewServer);
            delete(eventServer);

            % quit eye server
            stopEyeServerEvt = IPCEvent('StopEyeServer');
            stopEyeServerEvt.OpenEvent();
            stopEyeServerEvt.trigger();
            eyeProcess.stop()
            
            % quit control screen
            stopControlScreenEvt = IPCEvent('StopControlScreen');
            stopControlScreenEvt.OpenEvent();
            stopControlScreenEvt.trigger()           
            controlScreenProcess.stop()
            
            % quit stim server
            StimServer.delete()
            stimServerProcess.stop()
            
            % close TrialData pipe
            SGLTrialDataPipe.delete()

            fclose('all'); % close all open files
        end
    end
    
    methods (Access = protected)
        %# launch server process
        function process = mLaunchServer(this,xServ)
            
            % are we in debug mode?
            debugPoints = dbstatus();            
            isInDebugMode = any(arrayfun(@(x) strcmp(debugPoints.cond, 'error'), ...
                debugPoints));
            
            % create filepath to call
            launchFunc = fullfile(this.FPATH.pathProcessLaunch, ...
                sprintf('run%s.m',xServ));
            
            if ~isInDebugMode
                launchCmd = sprintf('matlab -automation -wait -r "run(''%s'')"', ...
                    launchFunc);
            else
                launchCmd = sprintf('matlab -wait -r "dbstop if error; run(''%s'')"', ...
                    launchFunc);
            end
                        
            % launch process
            process = processManager('id', xServ, ...
                'command', launchCmd, ...
                'printStdout', false, ...
                'printStderr', false);

        end


        
        %# RUN user's Session
        function mRunSession(this,cfg)
            % move to user's working directory
            cd(fileparts(cfg.taskFile));
            
            % ***TODO: check if server is available***
            java.lang.Thread.sleep(15); % 15ms pause
            % Launch Behavioural Data Store
            BHVstore = SGLBehaviouralStore.launch(cfg);
            % Launch a Session
            SESSArc  = SGLSessionArc.launch;
            % Start Session
            this.mWriteToDiary('Starting Session', true)
            SESSArc.mStart;
            
            %----------------------------------------%
            % close behavioural file
            BHVstore.mCloseFile;
            % convert file
            BHVstore.mESIRead;
            
            %----------------------------------------%
            % leaving session
            this.mWriteToDiary('Quitting session', true);

            delete(BHVstore);
            delete(SESSArc);
            
            clear VARIABLES
        end
        
    end
    
end

