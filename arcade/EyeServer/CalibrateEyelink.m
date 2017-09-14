classdef CalibrateEyelink < handle
    
    properties
        fig
        ax
        dot
        eyelinkConfig
        stim
        rewardDuration
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
    end
    
    methods
        function obj = CalibrateEyelink(rewardDuration, stim)
            if ~Eyelink('IsConnected')
                assert(Eyelink('Initialize') == 0, 'Eyelink: could not initialize')
            end
            
            obj.eyelinkConfig = EyelinkConfig;
            obj.eyelinkConfig.read_config_from_tracker();
            
            
            obj.fig = figure('Color', 'w', 'WindowStyle', 'normal', 'MenuBar', 'None');
            set(obj.fig, 'WindowKeyPressFcn', @obj.onKeyPress, ...
                'CloseRequestFcn', @obj.onClose)
            
            obj.ax = axes('SortMethod','childorder', ...
                'XLim', obj.eyelinkConfig.screen_pixel_coords([1 3]), ...
                'YLim', obj.eyelinkConfig.screen_pixel_coords([4 2]) ...
                );
            obj.dot = line('XData', 0,'YData', 0,...
                'Marker','o','color','k', 'MarkerSize', 40);                             
            
  
            
            cmd = fullfile(arcaderoot, 'arcade', 'DaqServer', 'NidaqServer.exe');
            obj.daqServerProcess = processManager('command', cmd);
            
            % Connect to StimServer or start it if it's not running 
            tWait = tic;
            success = false;
            while ~success && toc(tWait) < 5
                try 
                    StimServer.Connect();
                    success = true;
                catch
                    % start StimServer
                    if isempty(obj.stimServerProcess)
                        cmd = fullfile(arcaderoot, 'arcade', 'StimServer', 'StimServer.exe');
                        obj.stimServerProcess = processManager('command', cmd);
                    end
                end
                pause(0.5);
            end
            assert(success, 'Could not connect to StimServer')
            
            % Connect to NidaqServer or start it if it's not running 
            tWait = tic;
            success = false;
            while ~success && toc(tWait) < 5
                try 
                    NidaqServer.Connect();
                    success = true;
                catch
                    % start StimServer
                    if isempty(obj.daqServerProcess)
                        cmd = fullfile(arcaderoot, 'arcade', 'DaqServer', 'NidaqServer.exe');
                        obj.daqServerProcess = processManager('command', cmd);
                    end
                end
                pause(0.5);
            end
            assert(success, 'Could not connect to NidaqServer')
            
            if ~exist('stim', 'var')
                stim1 = Gaussian;
                stim1.color = [255 255 255]; stim1.sdx = 10; stim1.sdy = 10;
                
                stim2 = Gaussian;
                stim2.color = [0 0 0]; stim2.sdx = 2; stim2.sdy = 2;
                
                obj.stim = [stim1 stim2];
            else 
                obj.stim = stim;
            end
            
            
            obj.stopEvent = IPCEvent('StopEyelinkCalibration');            
            obj.start()
            
            if ~exist('rewardDuration', 'var')
                rewardDuration = 100;
            end
            obj.rewardDuration = rewardDuration;
            
            if nargout == 0
                clear obj
            end
            
            
        end
        
        function start(obj)
            
            if ~Eyelink('IsConnected')
                assert(Eyelink('Initialize') == 0, 'Eyelink: could not initialize')
            end
            Eyelink('StartSetup');
            Eyelink('SendKeyButton', double('c'), 0, obj.KB_PRESS)
            
            while ~obj.stopEvent.wasTriggered %&& (Eyelink('CurrentMode') == 10)
                
                [~, statusStr] = Eyelink('ReadFromTracker', 'calibration_status');
                status = strsplit(statusStr, ' ');
                
                [~, x, y] = Eyelink('targetcheck');
                set(obj.dot, 'XData', x, 'YData', y)
                
                title(obj.ax, statusStr)
                if ~strcmp(status{3}, '0') % visible
                    newPosition = [x-obj.eyelinkConfig.screen_pixel_coords(3)/2, ...
                        y-obj.eyelinkConfig.screen_pixel_coords(2)/2];
                    groupStimuli('start')
                    set(obj.stim, 'position', newPosition)
                    set(obj.stim, 'visible', true);
                    groupStimuli('end')
                else
                    set(obj.stim, 'visible', false);
                end
                pause(0.5);
%                 result = Eyelink('CalResult')
            end
            delete(obj)
        end
        
        function obj = onKeyPress(obj, ~, callbackdata)            
            key = callbackdata.Key;
            
            if Eyelink('IsConnected') == 1                
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
                   NidaqServer.Reward(obj.rewardDuration);
                end
            end
        end
        
        function onClose(obj, varargin)
            obj.stopEvent.trigger();
            delete(obj.fig);
            
        end
        
        
        function delete(obj)
            delete(obj.stim)
            StimServer.Disconnect();
            delete(obj.stimServerProcess);
            NidaqServer.Disconnect();
            delete(obj.daqServerProcess);
            delete(obj.stopEvent);
        end
    end
    
end
