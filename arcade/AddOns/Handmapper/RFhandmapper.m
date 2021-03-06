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
    %   screenDist     : distance of monkey from screen (cm), default=81
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
        stimServerProcess
        daqServerProcess
        eyeServerProcess
        stopEvent
    end

    properties ( Hidden=true )
        %screen parameters
        screenX = 1680 %pix
        screenY = 1050 %pix
        screenDiag = 51 %cm
        screenDist = 81 %cm
    end
    
    methods
        function obj = RFhandmapper(screenDist, reward, fixPoint, customStim)
            run(fullfile(fileparts(mfilename('fullpath')), '..', '..', 'add_arcade_to_path.m'))
            
            % setup
            if exist('screenDist', 'var') && ~isempty(screenDist)
                obj.screenDist = screenDist;
            end
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
            obj.stopEvent = IPCEvent('StopRFhandmapper', true); % once triggered stays true forever

            obj.connectProcesses();

            % setup eye tracking
            obj.calc_ppd();
            obj.eye = RFhandmapperEye(obj,reward,fixPoint);
            
            % make gui
            obj.gui = RFhandmapperGUI(obj,obj.eye);
            
            % start displaying
            obj.currstim = obj.stim{1};
            
            try
                obj.start();
            catch ME
                obj.delete();
                rethrow(ME)
            end
            
            % close
            obj.delete();
            
        end

        function connectProcesses(obj)
            
            cfg = ArcadeConfig();
            cfg.EyeServer = 'EyelinkServer.exe';
            cfg.DaqServer = 'NidaqServer.exe';
            cfg.StimServer = 'StimServer.exe';
            cfg.ControlScreen = ''; % place holder for launch_processes

            procs = launch_processes(cfg);
            
            
            obj.eyeServerProcess = procs{1};
            obj.daqServerProcess = procs{2};
            obj.stimServerProcess = procs{3};

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
            
            delete(obj.currstim)
            cellfun(@(x) delete(x), obj.stim)
            
            StimServer.Disconnect();
            delete(obj.stimServerProcess);
            
            DaqServer.Disconnect();
            delete(obj.daqServerProcess);
            
			EyeServer.Stop();
            EyeServer.Disconnect();
            %EyeServer.delete();
            delete(obj.eyeServerProcess);
            
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