classdef RFhandmapperGUI < handle
    
    properties
        fig
        ax
        stimPanel
        centerCross
        
        hHide
        hFlash
        hStimpos
        hBackground
        
        main
        eye
    end
    
    
    methods
        function obj = RFhandmapperGUI(main,Eye)
            obj.main = main;
            obj.eye = Eye;
            
            screenCenter = [obj.main.screenX, obj.main.screenY]./2;
            screenQuart = screenCenter./2;
            
            figPos = [screenQuart(1), 100, screenCenter(1), screenCenter(2)+200];
            
            %% Initilise GUI
            obj.fig = figure('Name','RF_Handmapper', ...
                'NumberTitle','off', ...
                'CloseRequestFcn',@obj.onClose, ...
                'WindowScrollWheelFcn',@obj.onScrollWheel, ...
                'WindowKeyPressFcn',@obj.onKeyPress,...
                'MenuBar','none', ...
                'Units','pixels', ...
                'Position', figPos,...
                'Resize','off', ...
                'Visible','off');
            
            % Interactive mouse area
            obj.ax = axes('Parent',obj.fig, ...
                'Color', 'black', ...
                'Units', 'pixels', ...
                'Position', [0, 60, screenCenter(1) screenCenter(2)+20], ...
                'xLim', [-screenQuart(1) screenQuart(1)], ... %Size the same as size in pixels
                'xLimMode', 'manual', ...
                'yLim', [-screenQuart(2) screenQuart(2)], ... %Size the same as size in pixels
                'yLimMode', 'manual', ...
                'ButtonDownFcn', @obj.onClick, ...
                'Box', 'off',...
                'XTickLabel',[]);
            
            obj.makeGridLines(screenCenter);
            obj.makeCenterCross();
            obj.eye.makeFixationCircle();

            % make panels
            panelSize = [screenCenter(1) 58];
            
            obj.main.make_stim_buttons(obj.fig, [0,  screenCenter(2)+82, panelSize]);
            obj.make_stim_panel(screenCenter, [0, screenCenter(2)+80+62, panelSize]);
            obj.eye.make_eye_panel(obj.fig, screenCenter, [0, 0, panelSize]);
            drawnow;
            
        end
        
        function makeGridLines(obj,screenCenter)
            
            screenQuart = screenCenter./2; % all half size
            
            % Grid lines
            gridStep = obj.main.ppd/2; % all half size
            
            xLinePos = [(0:-gridStep:-screenQuart(1)), (0:gridStep:screenQuart(1))];
            yLinePos = [(0:-gridStep:-screenQuart(2)), (0:gridStep:screenQuart(2))];
            
            line(... % horizontal
                repmat([-screenQuart(1); screenQuart(1)], 1, length(yLinePos)), ...
                [yLinePos; yLinePos], ...
                'Color', [0.2 0.2 0.2], ...
                'ButtonDownFcn', @obj.onClick, ...
                'Parent', obj.ax);
            
            line(... % vertical
                [xLinePos; xLinePos], ...
                repmat([-screenQuart(2); screenQuart(2)], 1, length(xLinePos)), ...
                'Color', [0.2 0.2 0.2], ...
                'ButtonDownFcn', @obj.onClick, ...
                'Parent', obj.ax);
            
            line(... % Center lines
                [-screenQuart(1) 0; screenQuart(1) 0], ...
                [0 -screenQuart(2); 0 screenQuart(2)], ...
                'Color', [0.3 0.3 0.3], ...
                'ButtonDownFcn', @obj.onClick, ...
                'Parent', obj.ax);
            
        end
        
        function make_stim_panel(obj, screenCenter, pos)
            % This panel is to select stimulus, set visibility, choose flashing rate, turn everything off, background color
            
            obj.stimPanel = uipanel(obj.fig,...
                'BorderType', 'none', ...
                'Title', 'Stimulus Control',...
                'FontSize', 12,...
                'BackgroundColor', get(obj.fig, 'Color'),...
                'Units','Pixels', ...
                'Position', pos);
            
            % dropdown box to select each stimulus. Callback creates currstim which enables stim buttons
            liststim = cellfun(@(x)x.name, obj.main.stim, 'UniformOutput', 0);
            HandmapButtons.dropdown(obj.stimPanel,'Stimulus', 1, liststim, [20,4], @obj.onChooseStimulus);
            
            % on/off
            uicontrol(obj.stimPanel, ...
                'Style','togglebutton', ...
                'String','Stim Off', ...
                'Value',0, ...
                'Position',[120,4,60,30], ...
                'Callback',@obj.onOff);
            
            % hide
            obj.hHide = uicontrol(obj.stimPanel, ...
                'Style','togglebutton', ...
                'String','Invisible', ...
                'Value',1, ...
                'Position',[200,4,60,30], ...
                'Callback',@obj.onInvisible);
            
            % flash rate
            obj.hFlash = HandmapButtons.editbox(obj.stimPanel, 'Flash', obj.main.flash(1), [280,4], @obj.onFlash);
            set(obj.hFlash,'TooltipString',sprintf('# frames on, # frames off\n0 is no flashing'))
            
            % Stim position in visual degrees
            h = uicontrol(obj.stimPanel, ...
                'BackgroundColor', get(obj.fig, 'Color'), ...
                'Style','text', ...
                'String','Position', ...
                'Position',[370,19,80,15]);
            obj.hStimpos = uicontrol(obj.stimPanel, ...
                'BackgroundColor', get(obj.fig, 'Color'), ...
                'Style','text', ...
                'String',sprintf('%.1f,%.1f',obj.main.stimpos./obj.main.ppd), ...
                'Position',[370,4,80,15]);
            set([h,obj.hStimpos],'TooltipString',sprintf('Stimulus position in ppd'))
            
            % background dropdown
            col = {'gray','white','black'};
            HandmapButtons.dropdown(obj.stimPanel,'Background', 1, col, ...
                [screenCenter(1)-300,4], @obj.onChooseBackground);
            
            % background colour
            obj.hBackground = HandmapButtons.editbox_rgb(obj.stimPanel, 'Background', obj.main.background, 0, 255, ...
                [screenCenter(1)-200,4], @obj.onBackground);
            set(obj.hBackground,'TooltipString',sprintf('256 color value (0-255)'))
            
            % save stimulus
            h = uicontrol(obj.stimPanel, ...
                'Style','pushbutton', ...
                'String','Save', ...
                'Position',[screenCenter(1)-80,4,60,30], ...
                'Callback',@obj.onSave);
            set(h,'TooltipString',...
                sprintf(['Save properties and position of current stimulus\n',...
                    'Filename: RFhandmapStimulus_name_currdate_currtime']))
            
        end
        
        %% Gui display - if we want more than just a cross will need a new class
        
        function makeCenterCross(obj)
            % Put center cross at new center position
            delete(obj.centerCross)
            
            axisCoords = obj.main.stimpos./2;
            
            sz = 10;
            
            obj.centerCross(1) = line(...
                'XData', [axisCoords(1)-sz; axisCoords(1)+sz], ...
                'YData', [axisCoords(2); axisCoords(2)], ...
                'Color', [1 0 0], ...
                'LineWidth', 1.5, ...
                'ButtonDownFcn', @obj.onStartMove);
            obj.centerCross(2) = line(...
                'XData', [axisCoords(1); axisCoords(1)], ...
                'YData', [axisCoords(2)-sz; axisCoords(2)+sz], ...
                'Color', [1 0 0], ...
                'LineWidth', 1.5, ...
                'ButtonDownFcn', @obj.onStartMove);
            
            obj.centerCross(3) = rectangle(...
                'Position', [axisCoords-sz sz*2 sz*2], ...
                'Curvature',[1 1], ...
                'LineStyle','none', ...
                'ButtonDownFcn', @obj.onStartMove);
        end
        
        function onStartMove(obj, ~, ~) % Start dragging target
            set(obj.fig, 'WindowButtonMotionFcn', @obj.onMotion);
            set(obj.fig, 'WindowButtonUpFcn', @obj.onStopMove);
        end
        
        function onMotion(obj, ~, ~) % During target dragging
            obj.onClick();
        end
        
        function onStopMove(obj, ~, ~) % End of dragging
            set(obj.fig, 'WindowButtonMotionFcn', '');
            set(obj.fig, 'WindowButtonUpFcn', '');
        end
        
        
        %% figure/axis callbacks
        
        function obj = onClick(obj, ~, ~)
            mousePosition = get(obj.ax, 'CurrentPoint');
            screenCoords = mousePosition(1,1:2)*2; % this could be made flexible
            obj.main.stimpos = screenCoords;
            obj.makeCenterCross();
            drawnow;
        end
        
        function obj = onScrollWheel(obj, ~, callbackdata)
            degrees = 15*callbackdata.VerticalScrollCount;
            obj.main.currstim.add_angle(degrees);
        end

        function obj = onKeyPress(obj, ~, callbackdata)
            % if possible run callbacks of buttons attached to keypress
            keyPressed = callbackdata.Key;

            switch keyPressed
                case 'space' % currstim invisible/visible
                    buttonStat = get(obj.hHide,'Value');
                    set(obj.hHide,'Value', ~buttonStat);

                    obj.onInvisible(obj.hHide);

                case 'r' %reward
                    obj.eye.onManualReward();

                case 'e' %fixation and eyetracking off
                    buttonStat = get(obj.eye.hEyeOff,'Value');
                    set(obj.eye.hEyeOff,'Value', ~buttonStat);

                    obj.eye.onEyeOff(obj.eye.hEyeOff);
            end
        end
        
        %% stim panel callbacks
        
        function obj = onChooseStimulus(obj, src, ~)
            chosen = get(src, 'Value');
            
            obj.main.currstim = obj.main.stim{chosen};
        end
        
        function onOff(obj, src, ~)
            if get(src, 'Value') == 1
                obj.main.currstim.hide();
            else
                obj.main.currstim.show();
            end
            set(obj.hHide,'Value',1)
        end
        
        function onInvisible(obj, src, ~)
            if get(src, 'Value') == 1
                obj.main.currstim.invisible();
            else
                obj.main.currstim.visible();
            end
        end
        
        function onFlash(obj, src, ~)
            flash = str2double(get(src,'String'));
            obj.main.flash = flash;
            try
                stop_animation(obj.main.currstim)
            end
            if flash ~= 0
                anim = Flicker(flash,flash);
                obj.main.currstim.add_animation(anim);
                obj.main.currstim.play_animation();
            end
        end
        
        function onChooseBackground(obj,src,~)
            colors = get(src, 'String');
            value = get(src, 'Value');
            
            col = HandmapButtons.colorList(colors{value});
            obj.main.background = col;
        end
        
        function onBackground(obj, src, ~)
            kids = sort(get(get(src,'parent'),'children'));
            if src == kids(2)
                obj.main.background(1) = str2double(get(src, 'String'));
            elseif src == kids(3)
                obj.main.background(2) = str2double(get(src, 'String'));
            elseif src == kids(4)
                obj.main.background(3) = str2double(get(src, 'String'));
            end
        end
        
        function onSave(obj, ~, ~)
            
            todayDate = datestr(now,'yyyymmdd');
            nowTime = datestr(now,'HHMM-ss');
            savename = sprintf('RFhandmapStimulus_%s_%s_t%s', obj.main.currstim.name, todayDate, nowTime);
            
            stim = save_properties(obj.main.currstim);
            save(savename, 'stim');
            
        end
        
        
        %% figure callbacks
        function onClose(obj, varargin)
            obj.eye.eyeTracking = 0;
            pause(0.05)
            obj.main.stopEvent.trigger();
            delete(obj.fig);
        end
        
    end
    
end
