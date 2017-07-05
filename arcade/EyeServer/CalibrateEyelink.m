classdef CalibrateEyelink < handle
    
    properties
        fig
        ax
        dot
        eyelinkConfig
        stim
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
        stopEvent
    end
    
    methods
        function obj = CalibrateEyelink(eyelinkConfig, stim)
            if ~Eyelink('IsConnected')
                assert(Eyelink('Initialize') == 0, 'Eyelink: could not initialize')
            end
            
            if nargin == 0
                eyelinkConfig = EyelinkConfig();
            end
            
            if ischar(eyelinkConfig)
                cfg = load(eyelinkConfig);
                eyelinkConfig = cfg.eyelinkConfig;
            end
            obj.eyelinkConfig = eyelinkConfig;
            obj.eyelinkConfig.send_config_to_tracker();
            
            
            obj.fig = figure('Color', 'w', 'WindowStyle', 'normal', 'MenuBar', 'None');
            set(obj.fig, 'WindowKeyPressFcn', @obj.onKeyPress, ...
                'CloseRequestFcn', @obj.onClose)
            
            obj.ax = axes('SortMethod','childorder', ...
                'XLim', eyelinkConfig.screen_pixel_coords([1 3]), ...
                'YLim', eyelinkConfig.screen_pixel_coords([2 4]) ...
                );
            obj.dot = line('XData', 0,'YData', 0,...
                'Marker','o','color','k', 'MarkerSize', 40);                             
            
            % start StimServer
            cmd = fullfile(arcaderoot, 'arcade', 'StimServer', 'StimServer.exe');
            obj.stimServerProcess = processManager('command', cmd);
            
            
            tWait = tic;
            success = false;
            while ~success && toc(tWait) < 5
                try 
                    StimServer.Connect();
                    success = true;
                catch
                end
                pause(0.5);
            end
            
            if nargin < 2
                stim1 = Gaussian;
                stim1.color = [255 255 255]; stim1.sdx = 10; stim1.sdy = 10;
                
                stim2 = Gaussian;
                stim2.color = [0 0 0]; stim2.sdx = 2; stim2.sdy = 2;
                
                obj.stim = [stim1 stim2];
            elseif nargin == 2
                obj.stim = stim;
            end
            
            
            obj.stopEvent = IPCEvent('StopEyelinkCalibration');
            obj.stopEvent.CreateEvent;
            obj.start()
            
            
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
                        y-obj.eyelinkConfig.screen_pixel_coords(4)/2];
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
            end
        end
        
        function onClose(obj, varargin)
            obj.stopEvent.trigger();
            delete(obj.fig);
            
        end
        
        
        function delete(obj)
            %             close('all')
            delete(obj.stim)
            
            StimServer.Disconnect();
            delete(obj.stimServerProcess);
            delete(obj.stopEvent);
            %             delete(obj.fig);
        end
    end
    
end

% %cfg.send_config_to_tracker();
%
%
%
% KB_PRESS   = 10; % Eyelink.h
% ENTER_KEY  = hex2dec('000D');
% ESC_KEY    = hex2dec('001B');
% BCK_SPC    = 008;
%
% mode = Eyelink('CurrentMode')
% result = Eyelink('CalResult')
%
%
%
% [result =] Eyelink('StartSetup' [, stype=0])
% [status = ] Eyelink('DriftCorrStart', x, y [,dtype=0][, dodraw=1][, allow_setup=0])
% [result = ] Eyelink('ApplyDriftCorr')
% [result, tx, ty] = Eyelink('TargetCheck')
% [result = ] Eyelink('AcceptTrigger')
% Eyelink( 'SendKeyButton', double('c'), 0, KB_PRESS );
% [result, messageString =] Eyelink('CalMessage')
%
% el.IN_IDLE_MODE=1;    			% off-line
% el.IN_SETUP_MODE=2;   			% setup or cal/val/dcorr
% el.IN_RECORD_MODE=4;    		% data flowing
% el.IN_TARGET_MODE=8;
% while stop==0 && bitand(Eyelink('CurrentMode'), el.IN_TARGET_MODE)
%     while true
%         [~, x, y] = Eyelink('targetcheck');
%         stim.position = [x,y];
%         pause(5)
%     end