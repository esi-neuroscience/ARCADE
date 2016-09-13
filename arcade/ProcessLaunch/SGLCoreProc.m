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
            this.mPrintErrorLogHeader('Core Process');
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
            
            if ishghandle(MSgui.hfig)
                %# LAUNCH RewardServer
                rewServer   = SGLRewardServer.launch;
                %# trigger events server
                eventServer = SGLEventMarkerServer.launch;
            end
            
            % Launch Matlab processes for these servers
            this.mLaunchServer('EyeServer');
            this.mLaunchServer('ControlScreen');
            % connet to servers
            EyeSerPipe  = this.mConnectToServer('EyeServer');
            CntlSrnPipe = this.mConnectToServer('ControlScreen');
            
            %----------------------------------------%
            % start polling eye signal
            success = EyeSerPipe.mWriteCommandMessage('start_eye');
            
            while ishghandle(MSgui.hfig)
                cfg = MSgui.cfg; % get cfg file
                cfg.taskFile = MSgui.taskFile;
                
                % Run session
                success = CntlSrnPipe.mWriteCommandMessage('start'); %#ok<*NASGU>
                this.mWriteToDiary('Starting Session', true);
                this.mRunSession(cfg);
                
                success = CntlSrnPipe.mWriteCommandMessage('stop');
                % Enter wait for user mode
                MSgui.mWaitForUserAction;
            end
            
            %----------------------------------------%
            
            % quit ControlScreen, and EyeServer
            success = CntlSrnPipe.mWriteCommandMessage('quit_proc');
            success = EyeSerPipe.mWriteCommandMessage('quit_proc');
            
            % delete objects
            this.mWriteToDiary('Closing', true);
            
            delete(CntlSrnPipe);
            delete(EyeSerPipe);
            delete(rewServer);
            delete(eventServer);

            delete(MSgui);
            fclose('all'); % close all open files
        end
    end
    
    methods (Access = protected)
        %# launch server process
        function mLaunchServer(this,xServ)
            % create filepath to call
            runProcDir = fullfile(this.FPATH.pathProcessLaunch,sprintf('run%s.m',xServ));
            % launch process
            eval(sprintf('!matlab -automation -r "run(''%s'')" &', runProcDir));
        end

        %# connect to server
        % 1. create pipe object
        % 2. wait for server to open pipe
        % 3. connect as client
        function thisServer = mConnectToServer(this, xServ)
            switch xServ
                case 'EyeServer'
                    thisServer = SGLEyeServerCorePipe.launch;
                case 'ControlScreen'
                    thisServer = SGLCoreCntlPipe.launch;
            end
            % wait to see Eye Server has made pipe available
            available = thisServer.mWaitForServerAvailable(10);
            while ~available
                available = thisServer.mWaitForServerAvailable(10);
            end
            thisServer.mOpenClient;  % connect as client
            this.mWriteToDiary([xServ,' is Running'], true);
        end
        
        %# RUN user's Session
        function mRunSession(this,cfg)
            % move to user's working directory
            cd(fileparts(cfg.taskFile));
            
            % Launch StimServer
            StimServer = SGLStimServer.launch;
            % ***TODO: check if server is available***
            java.lang.Thread.sleep(15); % 15ms pause
            % Launch Behavioural Data Store
            BHVstore = SGLBehaviouralStore.launch(cfg);
            % Launch a Session
            SESSArc  = SGLSessionArc.launch;
            % Start Session
            SESSArc.mStart;
            
            %----------------------------------------%
            % close behavioural file
            BHVstore.mCloseFile;
            % convert file
            BHVstore.mESIRead;
            
            %----------------------------------------%
            % leaving session
            this.mWriteToDiary('Quitting session', true);

            delete(StimServer);
            delete(BHVstore);
            delete(SESSArc);
            
            clear VARIABLES
        end
        
    end
    
end

