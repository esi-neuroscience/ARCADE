classdef CalibrateEyelink < handle
    
    properties
        fig
        ax
        dot
        eyelinkConfig
        stim
    end
    
    
    methods
        function obj = CalibrateEyelink(eyelinkConfig)
               if ~Eyelink('IsConnected')
                assert(Eyelink('InitializeDummy') == 0, 'Eyelink: could not initialize')
            end
            
            if nargin == 0
                eyelinkConfig = EyelinkConfig();
                %                 eyelinkConfig.read_config_from_tracker();
            end
            
            if ischar(eyelinkConfig)
                cfg = load(eyelinkConfig);
                eyelinkConfig = cfg.eyelinkConfig;
            end
            obj.eyelinkConfig = eyelinkConfig;
            %             obj.eyelinkConfig.send_config_to_tracker();
            
            
            obj.fig = figure('Color', 'w', 'WindowStyle', 'normal', 'MenuBar', 'None');
            set(obj.fig, 'WindowKeyPressFcn', @obj.onKeyPress)
            obj.ax = axes('SortMethod','childorder', ...
                'XLim', eyelinkConfig.screen_pixel_coords([1 3]), ...
                'YLim', eyelinkConfig.screen_pixel_coords([2 4]) ...
                );
            obj.dot = line('XData', 0,'YData', 0,...
                'Marker','o','color','k', 'MarkerSize', 40);
            
         
            
            for iCalTarget = 1:2:numel(obj.eyelinkConfig.calibration_targets)
                pos = obj.eyelinkConfig.calibration_targets(iCalTarget:iCalTarget+1);
                line('XData', pos(1),'YData', pos(2),...
                    'Marker','o','color', [0.2 0.2 0.2], 'MarkerSize', 20);
            end
            
            %             obj.start();
            %             stim = Grating;
            
        end
        
        function start(obj)
            el.IN_IDLE_MODE=1;    			% off-line
            el.IN_SETUP_MODE=2;   			% setup or cal/val/dcorr
            el.IN_RECORD_MODE=4;    		% data flowing
            el.IN_TARGET_MODE=8;
            stop = 0;
            if ~Eyelink('IsConnected')
                assert(Eyelink('InitializeDummy') == 0, 'Eyelink: could not initialize')
            end
            Eyelink('StartSetup');
            
            
            while ~stop %&& bitand(Eyelink('CurrentMode'), el.IN_TARGET_MODE)
                [~, x, y] = Eyelink('targetcheck');
                set(obj.dot, 'XData', x, 'YData', y)
                obj.stim.position = [x,y];
                obj.stim.visible = true;
                pause(0.5);
            end
        end
        
        function obj = onKeyPress(obj, ~, callbackdata)
            disp(callbackdata.Key)
            KB_PRESS   = 10; % Eyelink.h
            if ~(Eyelink('IsConnected') == -1)
                Eyelink('SendKeyButton', double(callbackdata.Key), 0, KB_PRESS );
            end
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