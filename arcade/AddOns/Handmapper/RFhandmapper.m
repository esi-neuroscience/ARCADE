classdef RFhandmapper < handle
    % RFhandmapper - Class for mapping receptive fields by manually moving/
    % flashing stimuli. Rewards monkeys at fixed intervals for maintaining fixation
    %
    % USAGE
    % -----
    %   RFhandmapper({reward, fixPoint, customStim})
    %
    % INPUT (optional)
    % -----------------
    %   reward         : reward duration in ms, default=80
    %   fixPoint       : function handle specifying custom fixation point stimulus
    %   customStim     : class handle specifying custom Handmap stimulus
    %                    inbuilt stimuli = grating (default), rectangle, gammatron, image
    %
    
    % To do:    Zoom slider to resize stimuli. Issue: each stimulus type has differently named size property
    
    
    properties
        %stimuli
        stim = {@HandmapGrating,...
            @HandmapRectangle,...
            @HandmapGammatron,...
            @HandmapImage}% cell array of class handles
        currstim
        stimpos = [200,-200]
        custom
        flash = 0 %frames, 0 means no flash
        background = [127, 127, 127]
        ppd
        
        % other handmapper objects
        gui
        eye
        
        % processes
        EyeServer = 'Eyelink' %'Eyelink' 'NationalInstruments' 'Test'
        stimServerProcess
        daqServerProcess
        eyeServerProcess
        stopEvent
    end

    properties ( Constant, Hidden=true )
        %screen parameters
        screenX = 1680 %pix
        screenY = 1050 %pix
        screenDiag = 51 %cm
        screenDist = 81 %cm
    end
    
    methods
        function obj = RFhandmapper(reward, fixPoint, customStim)
            
            % setup
            if ~exist('reward', 'var')
                reward = [];
            end
            if ~exist('fixPoint','var')
                fixPoint = [];
            end
            if ~exist('customStim','var')
                customStim = {};
            end
            
            if iscell(customStim)
                obj.custom = customStim;
            else
                error('customStim must be a cell array')
            end
            
            % connect processes
            obj.stopEvent = IPCEvent('StopRFhandmapper');
            
            obj.connectStimServer();
            obj.connectNidaqServer();
            obj.connectEyeServer();

            % setup eye tracking
            obj.calc_ppd();
            obj.eye = RFhandmapperEye(obj,reward,fixPoint);
            
            % make gui
            obj.gui = RFhandmapperGUI(obj,obj.eye);
            
            % start displaying
            obj.currstim = obj.stim{1};
            obj.start();
            
            % close
            obj.delete();
            
        end
        
        function connectStimServer(obj)
            % Connect to StimServer or start it if it's not running
            tWait = tic;
            success = false;
            while ~success && toc(tWait) < 10
                try
                    StimServer.Connect();
                    success = true;
                catch me
                    % start StimServer
                    if isempty(obj.stimServerProcess)
                        cmd = fullfile(arcaderoot, 'arcade', 'StimServer', 'StimServer.exe');
                        obj.stimServerProcess = processManager('command', cmd);
                    end
                end
                pause(0.5);
            end
            if ~success
                rethrow(me)
            end
            
        end
        
        function connectNidaqServer(obj)
            % Connect to NidaqServer or start it if it's not running
            tWait = tic;
            success = false;
            while ~success && toc(tWait) < 10
                try
                    DaqServer.Connect();
                    success = true;
                catch me
                    % start DaqServer
                    if isempty(obj.daqServerProcess)
                        cmd = fullfile(arcaderoot, 'arcade', 'DaqServer', 'NidaqServer.exe');
                        obj.daqServerProcess = processManager('command', cmd);
                    end
                end
                pause(0.5);
            end
            if ~success
                rethrow(me)
            end
        end
        
        function connectEyeServer(obj)
            % Connect to EyeServer or start it if it's not running
            tWait = tic;
            success = false;
            while ~success && toc(tWait) < 10
                try
                    result = eyeServerReadyEvt.waitForTrigger(20000);
                    assert(result==1, 'Wait for EyeServer failed')
                    
                    % connect to EyeServer
                    SGLEyeServerPipe.Open();
                    success = true;
                catch me
                    if isempty(obj.eyeServerProcess)
                        cmd = fullfile(arcaderoot, 'arcade', 'EyeServer', ['EyeServer.bat ' obj.EyeServer]);
                        eyeServerReadyEvt = IPCEvent('EyeServerReady', false);
                        obj.eyeServerProcess = processManager('id', 'EyeServer', ...
                            'command', cmd, ...
                            'printStdout', false, ...
                            'printStderr', false);
                    end
                end
                pause(0.5);
            end
            if ~success
                rethrow(me)
            end
        end

        function ppd = calc_ppd(obj)

            % Calculate pixels per degree
            diagpix = sqrt((obj.screenX^2) + (obj.screenY^2));
            viewdeg = 2*atan2(obj.screenDiag/2, obj.screenDist)*180/pi;
            ppd = diagpix/viewdeg;
            obj.ppd = ppd;

        end
        
        %% set properties
        
        function set.currstim(obj, stim)
            % any updating of currstim will also change the buttons
            try
                % will crash on first set
                isOn = cellfun(@(x)get(x, 'visible'),obj.currstim.stim);
                obj.currstim.hide();
            end
            obj.currstim = stim;
            
            if obj.flash > 0
                anim = Flicker(obj.flash,obj.flash);
                obj.currstim.add_animation(anim);
            else
                obj.currstim.rm_animation();
            end
            
            obj.currstim.show();
            obj.currstim.position(obj.stimpos);
            if exist('isOn','var')
                if isOn(1)
                    obj.currstim.visible();
                else
                    obj.currstim.invisible();
                end
            end
        end
        
        function set.stimpos(obj, stimpos)
            obj.currstim.position(stimpos);
            obj.stimpos = stimpos;
            % Display
            set(obj.gui.hStimpos, 'String', ...
                sprintf('%.1f,%.1f', obj.stimpos./obj.ppd))
        end
        
        function set.background(obj, background)
            obj.background = background;
            backgroundColor(background);
            
            for iBox = 1:length(obj.gui.hBackground)
                set(obj.gui.hBackground(iBox),'String',background(iBox));
            end
            
        end
        
        %% functions
        
        function make_stim_buttons(obj,hFig,pos)
            
            cellfun(@(x)assert(isa(x,'function_handle'),...
                'Stimulus input is not a function handle'), obj.stim);
            
            for iStim = 1:length(obj.custom)
                tmp = obj.custom{iStim};
                if ~isempty(tmp)
                    assert(isa(tmp, 'function_handle'),...
                        'customStim input is not a function handle');
                    obj.stim = [obj.stim, {tmp}];
                end
            end
            
            tmp = cellfun(@(x)x(obj,hFig,pos), obj.stim, 'uniformoutput', 0);
            obj.stim = tmp;
            
        end
        
        function delete(obj)
            
            StimServer.Disconnect();
            delete(obj.stimServerProcess);
            
            DaqServer.Disconnect();
            delete(obj.daqServerProcess);
            
            SGLEyeServerPipe.Close();
            stopEvent = IPCEvent('StopEyeServer');
            stopEvent.trigger();
            delete(obj.eyeServerProcess);
            
            delete(obj.currstim)
            cellfun(@(x) delete(x), obj.stim)
            
            delete(timerfind)
            
            obj.stopEvent.trigger();
            delete(obj.stopEvent);
        end
        
        function start(obj)
            
            % background flash?
            
            % make gui active
            set(obj.gui.fig, 'Visible', 'On');
            
            rewTimer = obj.eye.make_reward_timer();
            
            % main loop
            while ~obj.stopEvent.wasTriggered
                pause(0.05)
                try
                    obj.eye.waitfor_eye();
                catch me
                    stop(rewTimer)
                    delete(obj.gui)
                    rethrow(me)
                end
                
            end
            
            stop(rewTimer)
        end
    end
end