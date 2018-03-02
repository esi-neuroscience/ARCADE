classdef HandmapGammatron < HandmapStimulus

    properties
        % button handles
        hRadius
        hFull
    end


    methods

        function obj = HandmapGammatron(hFig,pos)
            obj.name = 'Gammatron';

            obj.make_stimulus();
            obj.make_uipanel(hFig,pos);
            obj.make_gammatron_buttons();

        end

        function make_stimulus(obj)

            obj.stim = cell(1,1);

            obj.stim{1} = Gammatron;
            obj.stim{1}.temporalFrequency = 1; % cycles per second;
            obj.stim{1}.spatialPeriod = 50; % pixel per cycle
            obj.stim{1}.direction = 1; % -1=inward, 1=outward;
            obj.stim{1}.color1 = [0 0 0 255]; % [r g b alpha]
            obj.stim{1}.color2 = [255 255 255 255]; % [r g b alpha]
            obj.stim{1}.radius = 250; % pixels

        end

        function make_gammatron_buttons(obj)
            % make gammatron buttons

            stim = obj.stim{1};

            obj.hRadius = obj.editbox(obj.hUipanel, 'Radius', stim.radius, [10 4], @obj.onRadius);

            col = {'white','red','green','blue','yellow','black'};
            obj.dropdown(obj.hUipanel, 'Color1', 1, col, [70 4], @obj.onColor1);
            obj.dropdown(obj.hUipanel, 'Color2', 6, col, [140 4], @obj.onColor2);

            obj.editbox(obj.hUipanel, 'Thickness', stim.spatialPeriod, [210 4], @obj.onSpatialPeriod)

            obj.editbox(obj.hUipanel, 'Speed', stim.temporalFrequency, [270 4], @obj.onSpeed)

            % direction
            uicontrol(obj.hUipanel, ...
                'Style','togglebutton', ...
                'String','Direction', ...
                'Value',1, ...
                'Position',[330,4,60,30], ...
                'Callback',@obj.onDirection);
            
            % fullscreen
            obj.hFull = uicontrol(obj.hUipanel, ...
                'Style','togglebutton', ...
                'String','Fullscreen', ...
                'Value',0, ...
                'Position',[400,4,60,30], ...
                'Callback',@obj.onFullscreen);
            
            set( findall(obj.hUipanel, '-property', 'Enable'), 'Enable', 'off')

        end

        %% callbacks

        function onRadius(obj,src,~)

            obj.stim{1}.radius = str2double(get(src, 'String'));

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

        function onSpatialPeriod(obj,src,~)

            obj.stim{1}.spatialPeriod = str2double(get(src, 'String'));

        end

        function onSpeed(obj,src,~)

            obj.stim{1}.temporalFrequency = str2double(get(src, 'String'));

        end

        function onDirection(obj,src,~)

            if get(src, 'Value') == 1
                obj.stim{1}.direction = 1;
            else
                obj.stim{1}.direction = -1;
            end

        end

        function onFullscreen(obj,src,~)
        
            if get(src, 'Value') == 1
            
              orig = [obj.stim{1}.radius];
              set(src, 'UserData', orig);

              obj.stim{1}.radius = 2000;
            
            else
              orig = get(src, 'UserData');
              if ~isempty(orig)
                  obj.stim{1}.radius = orig(1);
              end
            
            end

            set(obj.hRadius, 'String', obj.stim{1}.radius)

        end


    end
    
end








