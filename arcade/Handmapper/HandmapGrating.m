classdef HandmapGrating < HandmapStimulus

    properties
        % button handles
        hWid
        hHeight
        hFull
    end


    methods

        function obj = HandmapGrating(hFig,pos)
            obj.name = 'Grating'; %need this to choose stim

            obj.make_stimulus();
            obj.make_uipanel(hFig,pos);
            obj.make_grating_buttons();

        end

        function make_stimulus(obj)
            obj.stim = cell(1,1);

            obj.stim{1} = Grating;
            obj.stim{1}.color1 = [255 255 255 255]; % [r g b alpha]
            obj.stim{1}.color2 = [0 0 0 255]; % [r g b alpha]
            obj.stim{1}.spatialFrequency = 25; % px / cycle
            obj.stim{1}.direction = 0;  % drift direction in degree
            obj.stim{1}.smoothing = 10; % 2 = sinusoidal grating, 10 = square wave grating
            obj.stim{1}.phaseShift = 0;
            obj.stim{1}.maskWidth = 200; % width of circular mask in px
            obj.stim{1}.maskHeight = 200; % height of circular mask in px
            obj.stim{1}.temporalFrequency = 1; % cycles / s

        end

        function make_grating_buttons(obj)
            % make grating buttons

            stim = obj.stim{1};

            obj.hWid = obj.editbox(obj.hUipanel, 'Width', stim.maskWidth, [10 4], @obj.onWidth);

            obj.hHeight = obj.editbox(obj.hUipanel, 'Height', stim.maskHeight, [70 4], @obj.onHeight);

            col = {'white','red','green','blue','yellow','black'};
            obj.dropdown(obj.hUipanel, 'Color1', 1, col, [130 4], @obj.onColor1);
            obj.dropdown(obj.hUipanel, 'Color2', 6, col, [200 4], @obj.onColor2);

            obj.editbox(obj.hUipanel, 'SpatialFreq', stim.spatialFrequency, [270 4], @obj.onSpatialFreq)

            obj.editbox(obj.hUipanel, 'Speed', stim.temporalFrequency, [330 4], @obj.onSpeed)
            
            % fullscreen
            obj.hFull = uicontrol(obj.hUipanel, ...
                'Style','togglebutton', ...
                'String','Fullscreen', ...
                'Value',0, ...
                'Position',[390,4,60,30], ...
                'Callback',@obj.onFullscreen);
            
            set( findall(obj.hUipanel, '-property', 'Enable'), 'Enable', 'off')

        end

        function update_buttons(obj)

            set(obj.hHeight, 'String', obj.stim{1}.maskHeight)
            set(obj.hWid, 'String', obj.stim{1}.maskWidth)

        end

        function add_angle(obj,addAngle) % not called angle for grating
            try
                angles = cellfun(@(x)get(x,'direction'), obj.stim, 'UniformOutput', 0);
                % range check
                for iAng = 1:length(angles)
                    tmp = angles{iAng} + addAngle;
                    if tmp > 360
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

        function onWidth(obj,src,~)

            obj.stim{1}.maskWidth = str2double(get(src, 'String'));

        end

        function onHeight(obj,src,~)

            obj.stim{1}.maskHeight = str2double(get(src, 'String'));

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




