classdef HandmapButtons < handle
    
    methods
        function obj = HandmapButtons()
        end
    end
    
    methods (Static)
        
        function colour = colorList(colorName)
            
            switch colorName
                case 'white'
                    colour(1:3) = [255,255,255];
                case 'red'
                    colour(1:3) = [255,0,0];
                case 'green'
                    colour(1:3) = [0,255,0];
                case 'blue'
                    colour(1:3) = [0,0,255];
                case 'yellow'
                    colour(1:3) = [255,255,0];
                case 'black'
                    colour(1:3) = [0,0,0];
                case 'gray'
                    colour(1:3) = [127,127,127];
                otherwise
                    warning('Unknown colour input to colorList')
                    colour = [0,0,0];
            end
            
        end
        
        %align([hplot,gtext,htext,hpopup,gpopup],'Center','None'); % does this work in 2014a/b?
        
        
        function [ hEdit ] = dropdown(parent, Label, Value, Choices, posLL, callback)
            % initial selection number of "Value"
            % and cell array of choices of "Choices"
            
            bgColor = get(gcf, 'Color');
            h = uipanel(parent, ...
                'BorderType', 'none', ...
                'BackgroundColor', bgColor);
            
            %Title
            label = uicontrol(h, ...
                'BackgroundColor', bgColor, ...
                'Style', 'Text', ...
                'String', Label);
            pos = get(label, 'Position');
            pos(1) = [0];
            set(label, 'Position', pos);
            
            % Drop down menu
            hEdit = uicontrol(h, ...
                'Style', 'popupmenu', ...
                'String', Choices, ...
                'Value', Value, ...
                'Callback', callback);
            pos2 = get(hEdit, 'Position');
            set(hEdit, 'Position', [0, 4, pos2(3), pos2(4)]);
            set(h, 'Units', 'Pixel', ...
                'Position', [posLL pos(3)+pos2(3) pos2(4)]);
        end
        
        function [ editBox ] = editbox(parent, Label, Value, posLL, callback)
            % makes an edit box
            
            bgColor = get(gcf, 'Color');
            h = uipanel(parent, ...
                'BorderType','none', ...
                'BackgroundColor',bgColor);
            
            % make label
            label = uicontrol(h, ...
                'BackgroundColor',bgColor, ...
                'Style','Text', ...
                'String',Label);
            pos = get(label, 'Position');
            pos(1) = [0];
            set(label, 'Position', pos);
            
            % make edit box
            editBox = uicontrol(h, ...
                'Style', 'Edit', ...
                'String', Value, ...
                'Callback', callback);
            pos2 = get(editBox, 'Position');
            set(editBox, 'Position', [0, 4, pos2(3)-20, pos2(4)], ...
                'String',Value);
            pos2 = get(editBox, 'Position');
            set(h, 'Units','Pixel', ...
                'Position', [posLL pos(3)+pos2(3) pos2(4)]);
            
            % move label to align with edit box
            set(label, 'Position', [pos2(1)-8 pos(2:4)]);
        end
        
        function hEdit = editbox_range(parent, Label, Value, Min, Max, posLL, callback)
            % makes an edit box with a range check
            
            userdata.min = Min;
            userdata.max = Max;
            
            bgColor = get(gcf, 'Color');
            h = uipanel(parent, ...
                'BorderType','none', ...
                'BackgroundColor',bgColor);
            label = uicontrol(h, ...
                'BackgroundColor',bgColor, ...
                'Style','Text', ...
                'String',Label);
            pos = get(label, 'Position');
            pos(1) = [0];
            set(label, 'Position', pos);
            
            % make edit
            hEdit = uicontrol(h, ...
                'Style','Edit', ...
                'String', Max, ...
                'Callback', callback, ...
                'UserData', userdata);
            pos2 = get(hEdit, 'Position');
            
            % rearrange
            set(hEdit, 'Position', [0, 4, pos2(3)-20, pos2(4)], ...
                'String',Value);
            pos2 = get(hEdit, 'Position');
            set(h, 'Units','Pixel', ...
                'Position', [posLL pos(3)+pos2(3) pos2(4)]);
            set(label, 'Position', [pos2(1)-8 pos(2:4)]);
        end
        
        function [ hEdit ] = editbox_rgb( parent, String, Value, Min, Max, posLL, ...
                callback)
            %Makes an editable input box with label and 3 fields
            
            bgColor = get(gcf, 'Color');
            h = uipanel(parent, ...
                'BorderType','none', ...
                'BackgroundColor',bgColor);
            label = uicontrol(h, ...
                'BackgroundColor',bgColor, ...
                'Style','Text', ...
                'String',String);
            pos = get(label, 'Position');
            pos(1) = [0];
            set(label, 'Position', pos);
            
            edit1 = uicontrol(h, ...
                'Style','Edit', ...
                'String',Min, ...
                'Callback', callback);
            pos1 = get(edit1, 'Position');
            set(edit1, 'Position', [0, 4, pos1(3)-30, pos1(4)], ...
                'String',Value(1));
            pos1 = get(edit1, 'Position');
            
            edit2 = uicontrol(h, ...
                'Style','Edit', ...
                'Callback', callback, ...
                'Position', [pos1(3), 4, pos1(3), pos1(4)], ...
                'String',Value(2));
            pos2 = get(edit2, 'Position');
            
            edit3 = uicontrol(h, ...
                'Style','Edit', ...
                'Callback', callback, ...
                'Position', [pos2(1)+pos2(3), 4, pos2(3), pos2(4)], ...
                'String',Value(3));
            pos3 = get(edit3, 'Position');
            
            set(h, 'Units','Pixel', ...
                'Position', [posLL pos3(1)+pos3(3) pos3(4)]);
            set(label, 'Position', [pos2(1)-12 pos(2) pos(3) pos(4)]);
            
            hEdit = [edit1, edit2, edit3];
            
        end
        
        %function obj = slider_range(obj, parent, Label, Value, Min, Max, posAll, callback)
        %% slider with edit box? Do we really need this?
        %
        %userdata.min = Min;
        %userdata.max = Max;
        %
        %bgColor = get(gcf, 'Color');
        %
        %% Panel
        %h = uipanel(parent, ...
        %'BorderType','none', ...
        %'BackgroundColor',bgColor);
        %set(h, 'Units','Pixel', ...
        %'Position', posAll);
        %
        %% Label
        %label = uicontrol(h, ...
        %'BackgroundColor',bgColor, ...
        %'Style','Text', ...
        %'String',Label);
        %pos = [0 0 50 posAll(4)];
        %set(label, 'Position', pos);
        %
        %% Input value
        %obj.hEdit(1) = uicontrol(h, ...
        %'Style','Edit', ...
        %'String',Value, ...
        %'Callback', @obj.onInput,...
        %'UserData', userdata);
        %pos2 = get(obj.hEdit(1), 'Position');
        %set(obj.hEdit(1), 'Position',...
        %[posAll(3)-pos2(3), posAll(2), pos2(3), pos2(4)]);
        %pos2 = get(obj.hEdit(1), 'Position');
        %
        %% Slider
        %obj.hEdit(2) = uicontrol(h, ...
        %'Style','slider', ...
        %...'String',Max, ...
        %'Min', obj.Min, ...
        %'Max', obj.Max, ...
        %'Callback', callback, ...
        %'UserData', userdata);
        %set(obj.hEdit(2), 'Position', ...
        %[pos(1) + pos(3), posAll(2),...
        %posAll(3)-pos2(3)-pos(3), posAll(4)], ...
        %'Value',Value);
        %end
        
        function value = rangeCheck(value,userdata)
            if isnan(value)
                value = 0;
            end
            if value < userdata.min
                value = userdata.min;
            end
            if value > userdata.max
                value = userdata.max;
            end
        end
        
        
        
    end
    
    
end