classdef HandmapStimulus < HandmapButtons
    
    properties
        stim
        hUipanel
        animation
        
        name
        ppd
    end
    
    methods
        
        function obj = HandmapStimulus()
        end
        
        function make_uipanel(obj,hFig,pos)
            % make stimulus control panel
            
            bgColor = get(hFig, 'Color');
            
            obj.hUipanel = uipanel(hFig, ...
                'BorderType', 'none', ...
                'Title',[obj.name ' Control'],...
                'FontSize',12,...
                'BackgroundColor', bgColor,...
                'Units','Pixels', ...
                'Position', pos,...
                'Visible', 'Off');
        end
        
        function hide(obj)
            cellfun(@(x) set(x, 'visible', false), obj.stim);
            set(obj.hUipanel, 'Visible', 'Off');
            set( findall(obj.hUipanel, '-property', 'Enable'), 'Enable', 'off')
            if ~isempty(obj.animation)
                obj.stop_animation();
            end
        end
        
        function show(obj)
            set(obj.hUipanel, 'Visible', 'On');
            set( findall(obj.hUipanel, '-property', 'Enable'), 'Enable', 'on')
            if ~isempty(obj.animation)
                obj.play_animation();
            end
        end
        
        function visible(obj)
            cellfun(@(x) set(x, 'visible', true), obj.stim);
        end
        
        function invisible(obj)
            cellfun(@(x) set(x, 'visible', false), obj.stim);
        end
        
        function toggle(obj)
            isOn = cellfun(@(x) get(x, 'visible'), obj.stim, 'UniformOutput', 0);
            cellfun(@(x,y)set(x, 'visible', ~y),obj.stim, isOn);
        end
        
        function position(obj,stimpos)
            try
                cellfun(@(x)set(x,'position',stimpos), obj.stim);
            end
        end
        
        function add_angle(obj,addAngle)
            try
                angles = cellfun(@(x)get(x,'angle'), obj.stim, 'UniformOutput', 0);
                % range check
                for iAng = 1:length(angles)
                    tmp = angles{iAng} + addAngle;
                    if tmp >= 360
                        tmp = tmp - 360;
                    elseif tmp < 0
                        tmp = tmp + 360;
                    end
                    angles{iAng} = tmp;
                end
                % set new angles
                cellfun(@(x,y)set(x,'angle',y), obj.stim, angles);
            end
        end
        
        function add_animation(obj,anim)
            obj.animation = anim;
        end
        
        function rm_animation(obj)
            obj.animation = []; %this deletes stimulus??
        end
        
        function play_animation(obj)
            cellfun(@(x)play_animation(x, obj.animation), obj.stim)
        end
        
        function stop_animation(obj)
            cellfun(@(x)stop_animation(x), obj.stim)
        end

        function prop = save_properties(obj)
            prop = cellfun(@(x)struct(x), obj.stim, 'UniformOutput', 0);
        end
        
        function delete(obj)
            try
                cellfun(@(x)delete(x),obj.stim)
            end
        end
        
    end
    
end