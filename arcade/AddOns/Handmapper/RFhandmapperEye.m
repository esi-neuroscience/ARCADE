classdef RFhandmapperEye < handle
    
    properties
        rewardDuration = 70 %ms
        fixDuration = 3000
        countRew = 0
        
        fixPoint = @CalibrationStimulusGaussian;%@CalibrationStimulusCircle;%
        
        % eye tracking
        fixRadius = 70
        fixCenter = [0,0]
        eyeIn = 0
        eyeTracking = 0
        fpEvents
        
        % handles
        eyePanel
        rewTimer
        hEyeOff
        hCountRew
        hFixCircle
        
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

        function makeFixationCircle(obj)
            sz = obj.fixRadius;

            obj.hFixCircle = rectangle(...
                'Position', [obj.fixCenter/2 - sz/2, sz sz], ...
                'Curvature',[1 1], ...
                'LineWidth', 3, ...
                'EdgeColor', [0 0 0]);

        end
        
        function make_eye_panel(obj, fig, screenCenter, pos)
            % buttons for eye tracking on off, boxes for fixation center and window, fixation time, 
            % reward amount,  and button for manual reward
            obj.eyePanel = uipanel(fig,...
                'BorderType', 'none', ...
                'Title','Eye Reward Control',...
                'FontSize',12,...
                'BackgroundColor',get(gcf, 'Color'),...
                'Units','Pixels', ...
                'Position',pos);
            
            % on/off
            obj.hEyeOff = uicontrol(obj.eyePanel, ...
                'Style','togglebutton', ...
                'String','Eye Off', ...
                'Value',1, ...
                'Position',[10,4,60,30], ...
                'Callback',@obj.onEyeOff);
            set(obj.hEyeOff,'TooltipString',sprintf('Fixation point and eye tracking on/off'))

            % Fixation location
            h = HandmapButtons.editbox(obj.eyePanel, 'Fix center', ...
                sprintf('%0.1f, %0.1f', obj.fixCenter/obj.main.ppd), ...
                [80,4], @obj.onFixCenter);
            set(h,'TooltipString',sprintf('ppd'))
            
            % Fixation radius
            h = HandmapButtons.editbox(obj.eyePanel, 'Fix radius', ...
                sprintf('%0.2f', obj.fixRadius/obj.main.ppd), ...
                [140,4], @obj.onFixRadius);
            set(h,'TooltipString',sprintf('ppd'))
            
            % Fixation time
            h = HandmapButtons.editbox_range(obj.eyePanel, 'Fix time', obj.fixDuration, 500, Inf, ...
                [200,4], @obj.onFixDur);
            set(h,'TooltipString',sprintf('ms'))
            
            % Reward duration
            h = HandmapButtons.editbox(obj.eyePanel, 'Reward time', obj.rewardDuration, ...
                [270,4], @obj.onRewardDur);
            set(h,'TooltipString',sprintf('ms'))
            
            % Manual reward
            uicontrol(obj.eyePanel, ...
                'Style','pushbutton', ...
                'String','Reward', ...
                'Position',[350,4,60,30], ...
                'Callback',@obj.onManualReward);

            % Reward counter
            h = uicontrol(obj.eyePanel, ...
                'BackgroundColor', get(fig, 'Color'), ...
                'Style','text', ...
                'String','Reward Counter', ...
                'Position',[screenCenter(1)-100,19,80,15]);
            obj.hCountRew = uicontrol(obj.eyePanel, ...
                'BackgroundColor', get(fig, 'Color'), ...
                'Style','text', ...
                'String',obj.countRew, ...
                'Position',[screenCenter(1)-100,4,80,15]);
            set([h,obj.hCountRew],'TooltipString',sprintf('Number of reward pulses given during fixation'))
        end

        %% set/get

        function set.countRew(obj,countRew)
            set(obj.hCountRew, 'String', countRew);
            obj.countRew = countRew;
        end

        function set.eyeIn(obj,eyeIn)
            obj.eyeIn = eyeIn;
            set(obj.hFixCircle,'EdgeColor',[eyeIn eyeIn eyeIn])
            drawnow;
        end

        function set.fixCenter(obj,fixCenter)

            sz = obj.fixRadius;
            newPos = [fixCenter/2 - sz/2, sz sz];
            set(obj.hFixCircle,'Position', newPos);
            obj.fixCenter = fixCenter;

        end

        function set.fixRadius(obj,fixRadius)
            
            sz = fixRadius;
            newPos = [obj.fixCenter/2 - sz/2, sz sz];
            set(obj.hFixCircle,'Position', newPos);
            obj.fixRadius = fixRadius;

        end
        
        %% callbacks
        
        function onEyeOff(obj,src,~)
            if get(src,'Value')
                cellfun(@(x)set(x,'visible',false),obj.fixPoint);
                obj.eyeTracking = 0;
                obj.eyeIn = 0;
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

        function onFixCenter(obj,src,~)
            % Get new fixation center
            fixCenter= str2num(get(src,'String'));
            if length(fixCenter) ~= 2
                fixCenter = [0,0];
                set(src, 'String', sprintf('%0.1f, %0.1f', fixCenter));
            end
            obj.fixCenter = fixCenter*obj.main.ppd;

            % Move fixation point
            cellfun(@(x)set(x,'position',obj.fixCenter), obj.fixPoint);
            
            % Track new fixation position
            trackeye('reset');
            obj.fpEvents = trackeye(obj.fixCenter, obj.fixRadius, 'fp');
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
            obj.countRew = obj.countRew + 1;
        end
        
        %% eye tracking
        
        function waitfor_eye(obj)
            while obj.eyeTracking
                
                if isempty(obj.fpEvents)
                    trackeye('reset');
                    obj.fpEvents = trackeye(obj.fixCenter, obj.fixRadius, 'fp');
                    MultipleEvents.Init(obj.fpEvents);
                end

                result = obj.WAIT_TIMEOUT;
                
                while obj.eyeTracking && result == obj.WAIT_TIMEOUT && ~obj.main.stopEvent.wasTriggered
                    result = MultipleEvents.WaitFor(obj.fpEvents, false, 0);
                    pause(0.005)
                end
                
                assert(result ~= obj.WAIT_FAILED, 'Waiting for eye event failed, check trackeye inputs')
                
                % start and stop timer
                if obj.main.stopEvent.wasTriggered
                    stop(obj.rewTimer)
                    obj.eyeTracking = 0;
                    return
                elseif result == 1
                    obj.eyeIn = 1;
                    if  strcmp(obj.rewTimer.running, 'off')
                        start(obj.rewTimer)
                    end
                    MultipleEvents.Reset(obj.fpEvents(1));
                else
                    obj.eyeIn = 0;
                    stop(obj.rewTimer)
                    MultipleEvents.Reset(obj.fpEvents(2));
                end
                
            end
        end
        
    end
    
end