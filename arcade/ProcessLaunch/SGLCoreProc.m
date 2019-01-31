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
                fclose('all');
                return
            end
            
            
            cfg = MSgui.cfg; % get cfg file
            cfg.taskFile = MSgui.taskFile;
            
            % close main screen
            delete(MSgui);
            drawnow()
                                    
            evtFile = fullfile(cfg.filepaths.Behaviour, [cfg.Subject '_' today() '_' cfg.Experiment '_' cfg.Session '.evt']);
            eventServer = SGLEventMarkerServer.launch(evtFile);
            
            % Create TrialData pipe
            SGLTrialDataPipe.Create();
            
            % launch ControlScreen process
            logmessage('Starting ControlScreen')
            controlScreenReadyEvt = IPCEvent('controlScreenReady');
            controlScreenProcess = this.mLaunchServer('ControlScreen');
            
            % launch EyeServer process
            switch cfg.EyeServer
                case 'BinaryEyelink'
                    logmessage('Starting EyeServer')
                    eyeProcess = processManager('id', 'EyeServer', ...
                        'command', fullfile(arcaderoot, 'arcade', ...
                            'EyeServer', 'EyeServer.bat'), ...
                        'printStdout', false, ...
                        'printStderr', false);
                otherwise
                    error('Unsupported EyeServer type')
            end                                    
            
            % launch DaqServer process
            if ~strcmp(cfg.DaqServer, 'None')
                logmessage('Starting DaqServer')
                daqProcess = processManager('id', 'DaqServer', ...
                    'command', fullfile(arcaderoot, 'arcade', 'DaqServer', 'NidaqServer.exe'), ...
                    'printStdout', false, ...
                    'printStderr', false);
            end

            % launch StimServer process
            logmessage('Starting StimServer')
            stimServerProcess = processManager('id', 'StimServer', ...
                'command', fullfile(arcaderoot, 'arcade', 'StimServer', 'StimServer.exe'), ...
                'printStdout', false, ...
                'printStderr', false);
            
            
            
            % Wait for EyeServer and ControlScreen
            logmessage('Waiting for processes')
            %             if ~strcmp(cfg.EyeServer, 'None')
            %                 result = eyeServerReadyEvt.waitForTrigger(20000);
            %                 assert(result==1, 'Wait for EyeServer failed')
            %             end
            result = controlScreenReadyEvt.waitForTrigger(20000);
            assert(result==1, 'Wait for ControlScreen failed')
            
            
            
            % connect to StimServer
            StimServer.Connect();
            
            % connect to DaqServer
            if ~strcmp(cfg.DaqServer, 'None')
                DaqServer.Connect();
            end
            
            
            % connect to EyeServer
            if ~strcmp(cfg.EyeServer, 'None')
                EyeServer.Connect();
                EyeServer.Start([datestr(now,'mmddHHMM') '.edf'])
            end
            
            % Run session
            startEvent = IPCEvent('startControlScreenLoop');
            startEvent.trigger();
            
            logmessage('Starting Session');
            this.mRunSession(cfg);
            
            
            
            
            
            %----------------------------------------%
            
            % delete objects
            logmessage('Closing');
            
            delete(eventServer);
            
            % quit eye server
            if ~strcmp(cfg.EyeServer, 'None')
                eyeFile =  fullfile(cfg.filepaths.Behaviour, ...
                    [cfg.Subject '_' today() '_' cfg.Experiment '_' cfg.Session '.edf']);
                EyeServer.Stop(eyeFile)
                waitForFileEvt = IPCEvent('EyeServerDone');
                logmessage('Waiting for eye data transfer')
                result = waitForFileEvt.waitForTrigger(300000);
                if ~result
                    warning('Could not transfer eye data')
                end
                eyeProcess.stop()
            end
            
            % quit control screen
            stopControlScreenEvt = IPCEvent('StopControlScreen');
            stopControlScreenEvt.trigger()
            controlScreenProcess.stop()
            
            % quit stim server
            StimServer.delete()
            stimServerProcess.stop()
            
            % quit DaqServer
            if ~strcmp(cfg.DaqServer, 'None')
                DaqServer.delete();
                daqProcess.stop();
            end
            
            
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
            logmessage('Starting Session')
            SESSArc.mStart;
            
            %----------------------------------------%
            % close behavioural file
            BHVstore.mCloseFile;
            % convert file
            BHVstore.mESIRead;
            
            %----------------------------------------%
            % leaving session
            logmessage('Quitting session');
            
            delete(BHVstore);
            delete(SESSArc);
            
            clear VARIABLES
        end
        
    end
    
end

