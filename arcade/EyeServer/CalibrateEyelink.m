classdef CalibrateEyelink < handle
    % CALIBRATEEYELINK - Class for calibrating Eyelink systems using
    % StimServer and NidaqServer
    %
    % USAGE
    % -----
    %   CalibrateEyelink({reward, stimDefinition})
    %
    % INPUT (optional)
    % -----------------
    %   reward         : reward duration in ms, default=80
    %   stimDefinition : handle of function returning cell array of
    %                    stimuli to be used for mapping.
    %                    default=@CalibrateStimulusGaussian
    %
    % CalibrateEyelink will open a figure showing the position of the next
    % calibration target and relaying keyboard presses (without modifiers
    % like Ctrl, Alt, ...) to the Eyelink system (Press F1 on the Eyelink PC
    % to see all possible hotkeys). Useful hotkeys for calibration area
    %
    %   C              : start calibration mode
    %   V              : start validation mode
    %   ENTER          : Accept Fixation and give 1x reward
    %   BACKSPACE      : Repeat previous calibration
    %   ESC            : (first point) Exit to Camera Setup
    %                    (following points) Restart calibration
    %
    % Note: all eyelink settings are read from the Eyelink system, i.e., all
    % parameters have to be configured in the .ini files there.
    
    properties
        fig
        ax
        dot
        eyelinkConfig
        stim
        rewardDuration
        currentTargetPosition
        rewardedPositions
    end
    
    properties ( Constant, Access = private, Hidden=true )
        IN_TARGET_MODE=8
        KB_PRESS = 10; % Eyelink.h
        specialKeysNames = {'return', 'space', 'pageup', 'pagedown', 'escape', ...
            'leftarrow', 'rightarrow', 'uparrow', 'downarrow', ...
            'backspace'}
        specialKeysValues = {hex2dec('000D'), 32, hex2dec('4900'), hex2dec('5100'), hex2dec('001B'), ...
            hex2dec('4B00'), hex2dec('4D00'), hex2dec('4800'), hex2dec('5000'), ...
            hex2dec('008')};
    end
    
    properties ( GetAccess=private, SetAccess=immutable )
        stimServerProcess
        daqServerProcess
        stopEvent
        stimHandle
    end
    
    methods
        function obj = CalibrateEyelink(rewardDuration, stim)
            if ~Eyelink('IsConnected')
                assert(Eyelink('Initialize') == 0, 'Eyelink: could not initialize')
            end
            
            obj.eyelinkConfig = EyelinkConfig;
            obj.eyelinkConfig.read_config_from_tracker();
            
            
            obj.fig = figure('Color', 'w', 'WindowStyle', 'normal', ...
                'MenuBar', 'None', 'Name', 'CalibrateEyelink', 'NumberTitle', 'off');
            set(obj.fig, 'WindowKeyPressFcn', @obj.onKeyPress, ...
                'CloseRequestFcn', @obj.onClose)
            
            obj.ax = axes('SortMethod','childorder', ...
                'XLim', obj.eyelinkConfig.screen_pixel_coords([1 3]), ...
                'YLim', obj.eyelinkConfig.screen_pixel_coords([4 2]) ...
                );
            box(obj.ax, 'on')
            
            obj.dot = line('XData', 0,'YData', 0,...
                'Marker','o','color','k', 'MarkerSize', 40);
            
            title({'Hotkeys (this window must be in focus; hit F1 on Eyelink PC for overview)', ...
                'ENTER=forward, BACKSPACE=backward, ESC=exit/restart, R=reward, S=visibility'}, ...
                'FontWeight', 'bold')
            
            % Start and connect to StimServer
            obj.stimServerProcess = obj.start_server('StimServer');
            
            % Start and connect to DaqServer
            obj.daqServerProcess = obj.start_server('DaqServer');
            
            if ~exist('stim', 'var')
                obj.stim = CalibrationStimulusGaussian();
                obj.stimHandle = @CalibrationStimulusGaussian;
            else
                if isa(stim, 'function_handle')
                    obj.stimHandle = stim;
                    obj.stim = stim();                    
                else
                    error('Stimulus definition must be a function handle')
                end
            end
            
            
            obj.stopEvent = IPCEvent('StopEyelinkCalibration');
            if ~exist('rewardDuration', 'var')
                rewardDuration = 80;
            end
            obj.rewardDuration = rewardDuration;
                        
            obj.start();
                        
            
            if nargout == 0
                clear obj
            end
            
            
        end
        
        function start(obj)
            
            if ~Eyelink('IsConnected')
                assert(Eyelink('Initialize') == 0, 'Eyelink: could not initialize')
            end
            Eyelink('StartSetup');
            Eyelink('WaitForModeReady', 500);
            Eyelink('SendKeyButton', double('c'), 0, obj.KB_PRESS)
            Eyelink('WaitForModeReady', 500)            
            
              
            previousIndex = 1;
            currentPosition = [];
            previousMode = [];          
            
            while ~obj.stopEvent.wasTriggered %&& (Eyelink('CurrentMode') == 10)
                
                % change visibility when mode changes
                currentMode = Eyelink('CurrentMode');
                if ~isequal(previousMode, currentMode)
                    if currentMode == 10
                        for iStimulus = 1:length(obj.stim)
                            set(obj.stim{iStimulus}, 'visible', true);
                        end
                    else
                        for iStimulus = 1:length(obj.stim)
                            set(obj.stim{iStimulus}, 'visible', false);
                        end
                    end
                    previousMode = currentMode;
                end
                          
                
                % move stimuli when position changes
                [~, x, y] = Eyelink('targetcheck');
                                                           
                if ~isequal(currentPosition, [x y])                                                               
                    set(obj.dot, 'XData', x, 'YData', y)
                    obj.move_stimuli(x,y)

                    % give reward if we are advancing to a new target
                    [~, statusStr] = Eyelink('ReadFromTracker', 'calibration_status');                    
                    status = strsplit(statusStr, ' ');         
                    currentIndex = str2double(status{4});
                    
                    if (currentIndex > previousIndex) && (currentIndex > 1)
                        DaqServer.Reward(obj.rewardDuration);                                                                                         
                    end               
                    previousIndex = currentIndex;
                    currentPosition = [x y];
                    
                end                
                
                pause(0.5);
            end
            delete(obj)
        end
        
        function move_stimuli(obj, x, y)
            newPosition = [x-obj.eyelinkConfig.screen_pixel_coords(3)/2, ...
                y-obj.eyelinkConfig.screen_pixel_coords(2)/2];
            groupStimuli('start')
            for iStimulus = 1:length(obj.stim)
                set(obj.stim{iStimulus}, 'position', newPosition)                
            end
            groupStimuli('end')
            
        end
        
        
        function obj = onKeyPress(obj, ~, callbackdata)
            key = callbackdata.Key;
            
            if Eyelink('IsConnected') == 1
                if strcmp(key, 'r')
                    DaqServer.Reward(obj.rewardDuration);
                    return
                elseif strcmp(key, 's')
                    groupStimuli('start');
                    for iStim = 1:length(obj.stim)
                        obj.stim{iStim}.toggle_visibility();
                    end
                    groupStimuli('end');
                    return
                end
                
                [isMember, index] = ismember(key, obj.specialKeysNames);
                isSingleLetter = isequal(regexp(key, '\w'),1);
                if isMember
                    Eyelink('SendKeyButton', obj.specialKeysValues{index}, 0, obj.KB_PRESS );
                elseif isSingleLetter
                    Eyelink('SendKeyButton', double(key), 0, obj.KB_PRESS );
                else
                    fprintf('Keypress %s ignored\n', key)
                end
                if strcmp(key, 'return')
%                     DaqServer.Reward(obj.rewardDuration);
                end
            end
        end
        
        function onClose(obj, varargin)
            try
                obj.stopEvent.trigger();
                
            catch eventError
                warning('Could not properly close CalibrateEyelink')
            end
            
            try
                delete(obj.fig);
            catch figureError
                warning('Could not properly close CalibrateEyelink')
            end
            
        end
        
        
        
        function delete(obj)
            cellfun(@(x) delete(x), obj.stim)
            StimServer.Disconnect();
            delete(obj.stimServerProcess);
            DaqServer.Disconnect();
            delete(obj.daqServerProcess);
            delete(obj.stopEvent);
        end
    end
    
    methods ( Static = true )
        
        function process = start_server(server)
            switch server
                case 'StimServer'
                    cmd = fullfile(arcaderoot, 'arcade', 'StimServer', 'StimServer.exe');
                case 'DaqServer'
                    cmd = fullfile(arcaderoot, 'arcade', 'DaqServer', 'NidaqServer.exe');
            end
            
            process = processManager('command', cmd);
            
            tWait = tic;
            success = false;
            while ~success && toc(tWait) < 10
                try
                    switch server
                        case 'StimServer'
                            StimServer.Connect();
                        case 'DaqServer'
                            DaqServer.Connect();
                    end
                    success = true;
                catch me
                end
                pause(0.5);
            end
            if ~success
                rethrow(me)
            end
        end
        
        
    end
    
    
end


% el.IN_DISCONNECT_MODE=16384;   	% disconnected
% el.IN_UNKNOWN_MODE=0;    		% mode fits no class (i.e setup menu)
% el.IN_IDLE_MODE=1;    			% off-line
% el.IN_SETUP_MODE=2;   			% setup or cal/val/dcorr
% el.IN_RECORD_MODE=4;    		% data flowing
% el.IN_TARGET_MODE=8;    		% some mode that needs fixation targets
% el.IN_DRIFTCORR_MODE=16;   		% drift correction
% el.IN_IMAGE_MODE=32;   			% image-display mode
% el.IN_USER_MENU=64;				% user menu
% el.IN_PLAYBACK_MODE=256;		% tracker sending playback data
