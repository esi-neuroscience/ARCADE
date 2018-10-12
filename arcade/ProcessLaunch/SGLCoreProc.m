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
            
            
            this.mWriteToDiary('Starting Event Server', true);
            evtFile = fullfile(cfg.filepaths.Behaviour, [cfg.Subject '_' today() '_' cfg.Experiment '_' cfg.Session '.evt']);
            eventServer = SGLEventMarkerServer.launch(evtFile);
            
            % Create TrialData pipe
            SGLTrialDataPipe.Create();
            
            % launch ControlScreen process
            this.mWriteToDiary('Starting ControlScreen', true)
            controlScreenReadyEvt = IPCEvent('controlScreenReady');
            controlScreenProcess = this.mLaunchServer('ControlScreen'); 
            
            % launch EyeServer process            
            if ~strcmp(cfg.EyeServer, 'None')
                this.mWriteToDiary('Starting EyeServer', true)
                eyeProcess = processManager('id', 'EyeServer', ...
                    'command', fullfile(arcaderoot, 'arcade', 'EyeServer', ['EyeServer.bat ' cfg.EyeServer]), ...
                    'printStdout', false, ...
                    'printStderr', false);
            end
            % eyeProcess = this.mLaunchServer('EyeServer');
            
            % launch StimServer process
            this.mWriteToDiary('Starting StimServer', true)
            stimServerProcess = processManager('id', 'StimServer', ...
                'command', fullfile(arcaderoot, 'arcade', 'StimServer', 'StimServer.exe'), ...
                'printStdout', false, ...
                'printStderr', false);

            % launch DaqServer process
            if ~strcmp(cfg.DaqServer, 'None')
                this.mWriteToDiary('Starting DaqServer', true)                
                daqProcess = processManager('id', 'DaqServer', ...
                    'command', fullfile(arcaderoot, 'arcade', 'DaqServer', 'NidaqServer.exe'), ...
                    'printStdout', false, ...
                    'printStderr', false);
            end
            
            
            % Wait for EyeServer and ControlScreen
            this.mWriteToDiary('Waiting for processes', true)
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
                        
            this.mWriteToDiary('Starting Session', true);
            this.mRunSession(cfg);
            
            
            

            
            %----------------------------------------%
            
            % delete objects
            this.mWriteToDiary('Closing', true);
            
            delete(eventServer);

            % quit eye server
            if ~strcmp(cfg.EyeServer, 'None')
                eyeFile =  fullfile(cfg.filepaths.Behaviour, ...
                    [cfg.Subject '_' today() '_' cfg.Experiment '_' cfg.Session '.edf']);
                EyeServer.Stop(eyeFile)
                % eyeProcess.stop()
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
                launchCmd = ['C:\Program Files\MATLAB\R2014a\bin\' sprintf('matlab -automation -wait -r "run(''%s'')"', ...
                    launchFunc)];
            else
                launchCmd = ['C:\Program Files\MATLAB\R2014a\bin\' sprintf('matlab -wait -r "dbstop if error; run(''%s'')"', ...
                    launchFunc)];
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
            % this.mWriteToDiary('Starting Session', true)
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

