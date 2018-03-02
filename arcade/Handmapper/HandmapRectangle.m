classdef HandmapRectangle < HandmapStimulus

    properties
        % button handles
        hWid
        hHeight
        hCol
        hFull
    end


    methods

        function obj = HandmapRectangle(hFig,pos)
            obj.name ='Rectangle'; %need this to choose stim

            obj.make_stimulus();
            obj.make_uipanel(hFig,pos);
            obj.make_rectangle_buttons();

        end

        function make_stimulus(obj)

            obj.stim = cell(1,1);

            obj.stim{1} = Rectangle;
            obj.stim{1}.width = 80; % width of rectangle in px for angle=0
            obj.stim{1}.height = 80; % height of rectangle in px for angle=0
            obj.stim{1}.angle = 0; % counter-clockise rotation of rectangle in degrees, 0=horizontal
            obj.stim{1}.color = [255 255 255]; % 24-bit [r g b] value
            obj.stim{1}.alpha = 255; % alpha transparency, 0=transparent, 255=opaque

        end

        function make_rectangle_buttons(obj)
            % make rectangle buttons

            stim = obj.stim{1};

            obj.hWid = obj.editbox(obj.hUipanel, 'Width', stim.width, [10 0], @obj.onWidth);

            obj.hHeight = obj.editbox(obj.hUipanel, 'Height', stim.height, [70 0], @obj.onHeight);

            cols = {'white','red','green','blue','yellow','black'};
            obj.hCol = obj.dropdown(obj.hUipanel, 'Color', 1, cols, [130 0], @obj.onColor);
            
            % fullscreen
            obj.hFull = uicontrol(obj.hUipanel, ...
                'Style','togglebutton', ...
                'String','Fullscreen', ...
                'Value',0, ...
                'Position',[200,0,60,30], ...
                'Callback',@obj.onFullscreen);
            
            set( findall(obj.hUipanel, '-property', 'Enable'), 'Enable', 'off')

        end

        function update_buttons(obj)

            set(obj.hHeight, 'String', obj.stim{1}.height)
            set(obj.hWid, 'String', obj.stim{1}.width)

        end

        %% callbacks

        function onWidth(obj,src,~)

            obj.stim{1}.width = str2double(get(src, 'String'));

        end

        function onHeight(obj,src,~)

            obj.stim{1}.height = str2double(get(src, 'String'));

        end

        function onColor(obj,src,~)
            
            colors = get(src, 'String');
            value = get(src, 'Value');

            col = obj.colorList(colors{value});

            obj.stim{1}.color(1:3) = col;

        end

        function onFullscreen(obj,src,~)
        
            if get(src, 'Value') == 1
            
              orig = [obj.stim{1}.width, obj.stim{1}.height];
            
              set(src, 'UserData', orig);

              obj.stim{1}.width = 2000;
              obj.stim{1}.height = 2000;
            
            else
              orig = get(src, 'UserData');
              if ~isempty(orig)
                  obj.stim{1}.width = orig(1);
                  obj.stim{1}.height = orig(2);
              end
            
            end

            obj.update_buttons();

        end


    end
    
end