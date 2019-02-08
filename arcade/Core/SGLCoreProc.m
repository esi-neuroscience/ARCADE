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
                        
            processes = launch_processes(cfg);
            
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
            end
            
            % quit control screen
            IPCEvent.set_event('ControlScreenDone')
            
            % quit stim server
            StimServer.delete()            
            
            % quit DaqServer
            if ~strcmp(cfg.DaqServer, 'None')
                DaqServer.delete();                
            end
            
            % kill subprocesses
            cellfun(@(x) x.stop(), processes)
            
            % close TrialData pipe
            SGLTrialDataPipe.delete()
            
            fclose('all'); % close all open files
        end
    end
    
    methods (Access = protected)
              
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

