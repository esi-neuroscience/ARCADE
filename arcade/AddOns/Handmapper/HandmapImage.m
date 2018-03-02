classdef HandmapImage < HandmapStimulus
    
    properties
        % button handles
        hSelect
        
        % other
        filename = fullfile(pwd, 'AddOns/Handmapper/monkey_face.jpg')
    end
    
    
    methods
        function obj = HandmapImage(hFig,pos)
            obj.name = 'Image';%need this to choose stim
            
            obj.make_stimulus();
            obj.make_uipanel(hFig,pos);
            obj.make_image_buttons();
            
        end
        
        function make_stimulus(obj)
            % this will need to be recreated if a new filename is loaded
            obj.stim = cell(1,1);
            try
                obj.stim{1} = Picture(obj.filename);
            catch
                warning('Picture stimulus could not be made from filename')
                obj.stim{1} = Rectangle;
            end
            
            obj.stim{1}.alpha = 255; % alpha transparency value between 0 (transparent) and 255 (opaque)
            obj.stim{1}.angle = 0; % angle in degrees of image, 0=horizontal, 90=vertical
            
        end
        
        function make_image_buttons(obj)
            % make image buttons
            
            % choose new image- maybe this should be dropdown with some ready images
            obj.hSelect = uicontrol(obj.hUipanel, ...
                'Style','pushbutton', ...
                'String','Load Image', ...
                'Position',[10,0,60,30], ...
                'Callback',@obj.onLoadImage);
            
            set( findall(obj.hUipanel, '-property', 'Enable'), 'Enable', 'off')
            
        end
        
        %% callbacks
        
        function onLoadImage(obj,~,~)
            oldDir = pwd;
            cd(fileparts(obj.filename));
            
            % look for image files to load - extensions currently supported by Picture class
            [fileName, uipath, ~] = uigetfile(...
                {'*.png;*.bmp;*.jpeg;*.jpg', 'Image Files (*.jpg,*.jpeg,*.png,*.bmp)';});
            if ~(fileName(1) == 0)
                pause(0.05)
                obj.filename = fullfile(uipath,fileName);
            end
            cd(oldDir);
            
        end
        
        %% set properties
        
        function set.filename(obj,filename)
            
            obj.filename = filename;
            isOn = cellfun(@(x)get(x,'visible'),obj.stim,'UniformOutput',0);
            obj.make_stimulus();
            cellfun(@(x,y)set(x,'visible',y),obj.stim,isOn);
            
        end
        
    end
    
end