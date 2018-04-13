classdef HandmapGrating < HandmapStimulus
    
    properties
        % button handles
        hSz
        hFull
    end
    
    methods
        
        function obj = HandmapGrating(main,hFig,pos)
            obj.name = 'Grating'; %need this to choose stim
            obj.ppd = main.ppd;
            
            obj.make_stimulus();
            obj.make_uipanel(hFig,pos);
            obj.make_grating_buttons();
            
        end
        
        function make_stimulus(obj)
            obj.stim = cell(1,1);
            
            obj.stim{1} = Grating;
            obj.stim{1}.color1 = [255 255 255 255]; % [r g b alpha]
            obj.stim{1}.color2 = [0 0 0 255]; % [r g b alpha]
            obj.stim{1}.spatialFrequency = 60; % px / cycle
            obj.stim{1}.direction = 0;  % drift direction in degree
            obj.stim{1}.smoothing = 10; % 2 = sinusoidal grating, 10 = square wave grating
            obj.stim{1}.phaseShift = 0;
            obj.stim{1}.maskWidth = 200; % width of circular mask in px
            obj.stim{1}.maskHeight = 200; % height of circular mask in px
            obj.stim{1}.temporalFrequency = 3; % cycles / s
            
        end
        
        function make_grating_buttons(obj)
            % make grating buttons
            
            stim = obj.stim{1};
            
            obj.hSz = obj.editbox(obj.hUipanel, 'Size', ...
                sprintf('%0.2f', obj.stim{1}.maskWidth/obj.ppd), ...
                [10 4], @obj.onSize);
            set(obj.hSz,'TooltipString',sprintf('ppd'))
            
            col = {'white','red','green','blue','yellow','black'};
            obj.dropdown(obj.hUipanel, 'Color1', 1, col, [70 4], @obj.onColor1);
            obj.dropdown(obj.hUipanel, 'Color2', 6, col, [140 4], @obj.onColor2);
            
            h = obj.editbox(obj.hUipanel, 'SpatialFreq', stim.spatialFrequency, ...
                [210 4], @obj.onSpatialFreq);
            set(h,'TooltipString',sprintf('pixels per cycle'))
            
            h = obj.editbox(obj.hUipanel, 'Speed', stim.temporalFrequency, ...
                [270 4], @obj.onSpeed);
            set(h,'TooltipString',sprintf('cycles per second'))
            
            % fullscreen
            obj.hFull = uicontrol(obj.hUipanel, ...
                'Style','togglebutton', ...
                'String','Fullscreen', ...
                'Value',0, ...
                'Position',[330,4,60,30], ...
                'Callback',@obj.onFullscreen);
            
            set( findall(obj.hUipanel, '-property', 'Enable'), 'Enable', 'off')
            
        end
        
        function update_buttons(obj)
            
            set(obj.hSz, 'String', ...
                sprintf('%0.2f', obj.stim{1}.maskWidth/obj.ppd));
            
        end
        
        function add_angle(obj,addAngle) % not called angle for grating
            try
                angles = cellfun(@(x)get(x,'direction'), obj.stim, 'UniformOutput', 0);
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
                cellfun(@(x,y)set(x,'direction',y), obj.stim, angles);
            end
        end
        
        %% callbacks
        
        function onSize(obj,src,~)
            sz = str2double(get(src, 'String'))*obj.ppd;
            obj.stim{1}.maskWidth = sz;
            obj.stim{1}.maskHeight = sz;
            
        end
        
        function onColor1(obj,src,~)
            
            colors = get(src, 'String');
            value = get(src, 'Value');
            
            col = obj.colorList(colors{value});
            obj.stim{1}.color1(1:3) = col;
        end
        
        function onColor2(obj,src,~)
            
            colors = get(src, 'String');
            value = get(src, 'Value');
            
            col = obj.colorList(colors{value});
            obj.stim{1}.color2(1:3) = col;
        end
        
        function onSpatialFreq(obj,src,~)
            
            obj.stim{1}.spatialFrequency = str2double(get(src, 'String'));
            
        end
        
        function onSpeed(obj,src,~)
            
            obj.stim{1}.temporalFrequency = str2double(get(src, 'String'));
            
        end
        
        function onFullscreen(obj,src,~)
            
            if get(src, 'Value') == 1
                
                orig = [obj.stim{1}.maskWidth, obj.stim{1}.maskHeight];
                set(src, 'UserData', orig);
                
                obj.stim{1}.maskWidth = 2000;
                obj.stim{1}.maskHeight = 2000;
                
            else
                orig = get(src, 'UserData');
                if ~isempty(orig)
                    obj.stim{1}.maskWidth = orig(1);
                    obj.stim{1}.maskHeight = orig(2);
                end
                
            end
            
            obj.update_buttons();
            
        end
        
        
    end
    
end