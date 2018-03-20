classdef RFhandmapperEye < handle
    
    properties
        rewardDuration = 70 %ms
        fixDuration = 3000
        
        fixPoint = @CalibrationStimulusGaussian;
        
        % eye tracking
        fixRadius = 70
        fixCenter = [0,0]
        eyeIn = 0
        eyeTracking = 0
        fpEvents
        
        % handles
        eyePanel
        rewTimer
        
        main
    end
    
    properties ( Access = private, Constant = true )
        WAIT_TIMEOUT = uint32(hex2dec('00000102'));
        WAIT_FAILED  = uint32(hex2dec('FFFFFFFF'));
    end
    
    methods
        
        function obj = RFhandmapperEye(main, reward, fixPoint)
            obj.main = main;
            
            if isempty(reward)
                reward = obj.rewardDuration;
            end
            obj.rewardDuration = reward;
            
            if isempty(fixPoint)
                fixPoint = obj.fixPoint;
            end
            
            if ~isa(fixPoint, 'function_handle')
                error('fixPoint must be a function handle')
            end
            
            tmp = fixPoint();
            obj.fixPoint = tmp;
            cellfun(@(x)set(x,'position',obj.fixCenter), obj.fixPoint);
            
        end
        
        function make_eye_panel(obj, fig, screenCenter, pos)
            % buttons for eye tracking on off, boxes for fixation window, fixation time, reward amount,  and button for manual reward
            obj.eyePanel = uipanel(fig,...
                'BorderType', 'none', ...
                'Title','Eye Reward Control',...
                'FontSize',12,...
                'BackgroundColor',get(gcf, 'Color'),...
                'Units','Pixels', ...
                'Position',pos);
            
            % on/off
            uicontrol(obj.eyePanel, ...
                'Style','togglebutton', ...
                'String','Eye Off', ...
                'Value',1, ...
                'Position',[10,4,60,30], ...
                'Callback',@obj.onEyeOff);
            
            % Fixation radius
            HandmapButtons.editbox(obj.eyePanel, 'Fix radius', obj.fixRadius/obj.main.ppd, ...
                [80,4], @obj.onFixRadius);
            
            % Fixation time
            HandmapButtons.editbox_range(obj.eyePanel, 'Fix time', obj.fixDuration, 500, Inf, ...
                [140,4], @obj.onFixDur);
            
            % Reward duration
            HandmapButtons.editbox(obj.eyePanel, 'Reward time', obj.rewardDuration, ...
                [210,4], @obj.onRewardDur);
            
            % Manual reward
            uicontrol(obj.eyePanel, ...
                'Style','pushbutton', ...
                'String','Reward', ...
                'Position',[290,4,60,30], ...
                'Callback',@obj.onManualReward);
        end
        
        %% callbacks
        
        function onEyeOff(obj,src,~)
            if get(src,'Value')
                cellfun(@(x)set(x,'visible',false),obj.fixPoint);
                obj.eyeTracking = 0;
                stop(obj.rewTimer);
            else
                
                if mean(obj.main.background) >= 127
                    set(obj.fixPoint{2}, 'visible', true);
                else
                    set(obj.fixPoint{1}, 'visible', true);
                end
                
                obj.fpEvents = [];
                obj.eyeIn = 0;
                obj.eyeTracking = 1;
            end
        end
        
        function onFixRadius(obj,src,~)
            fixRadius= str2num(get(src,'String'));
            obj.fixRadius = fixRadius*obj.main.ppd;
            
            trackeye('reset');
            obj.fpEvents = trackeye(obj.fixCenter, obj.fixRadius, 'fp');
        end
        
        function onFixDur(obj,src,~)
            fixDur = str2num(get(src,'String'));
            fixDur = HandmapButtons.rangeCheck(fixDur, get(src,'UserData'));
            
            obj.fixDuration = fixDur;
            
            if strcmp(obj.rewTimer.running,'on')
                stop(obj.rewTimer)
                obj.rewTimer.StartDelay = fixDur/1000;%s
                obj.rewTimer.Period = fixDur/1000;%s
                start(obj.rewTimer)
            else
                obj.rewTimer.StartDelay = fixDur/1000;%s
                obj.rewTimer.Period = fixDur/1000;%s
            end
        end
        
        function onRewardDur(obj,src,~)
            rewDur = str2num(get(src,'String'));
            obj.rewardDuration = rewDur;
        end
        
        function onManualReward(obj,~,~)
            reward(obj.rewardDuration);
        end
        
        %% reward timer
        function rew = make_reward_timer(obj)
            
            rew = timer;
            rew.Tag = 'RewardTimer';
            rew.StartDelay = obj.fixDuration/1000;%s
            rew.Period = obj.fixDuration/1000;%s
            rew.ExecutionMode = 'FixedSpacing';%Waits until reward is given until starting timer again
            rew.TimerFcn = @obj.rew_timer_fnc;
            
            obj.rewTimer = rew;
            
        end
        
        function rew_timer_fnc(obj, ~, ~)
            reward(obj.rewardDuration);
        end
        
        %% eye tracking
        
        function result = waitfor_eye(obj)
            
            if obj.eyeTracking
                
                MultipleEvents.Reset();
                
                if isempty(obj.fpEvents)
                    trackeye('reset');
                    obj.fpEvents = trackeye(obj.fixCenter, obj.fixRadius, 'fp');
                end
                
                if obj.eyeIn
                    event = obj.fpEvents{2};%out
                else
                    event = obj.fpEvents{1};%in
                end
                
                result = obj.WAIT_TIMEOUT;
                MultipleEvents.Init(obj.fpEvents);
                while obj.eyeTracking && result == obj.WAIT_TIMEOUT && ~obj.main.stopEvent.wasTriggered
                    result = MultipleEvents.WaitFor(event, false, 0);
                    pause(0.05)
                end
                
                assert(result ~= obj.WAIT_FAILED, 'Waiting for eye event failed, check trackeye inputs')
                
                if result == 1
                    % start and stop timer
                    obj.eyeIn = ~obj.eyeIn;
                    if obj.eyeIn == 1 && strcmp(obj.rewTimer.running, 'off')
                        start(obj.rewTimer)
                    else
                        stop(obj.rewTimer)
                    end
                end
                
            end
            
            
        end
        
    end
    
end