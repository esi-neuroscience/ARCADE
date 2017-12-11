classdef SGLEyelinkEyeServer < ABSEyeServer
    
    properties
        usedEye = 0;
        screenSize = [1680 1050]; % x y in px
        config
    end
    
    
    properties ( Access = private )
        folder = [];
        shortFilename = [];
        blinkStartEvent
        blinkEndEvent
        saccadeStartEvent
        saccadeEndEvent
    end
    
    methods (Static)
        function obj = launch(filename)
            persistent objObj
            if isempty(objObj) || ~isvalid(objObj)
                if nargin == 0
                    filename = [];
                end
                objObj = SGLEyelinkEyeServer(filename);
                
            end
            obj = objObj;
        end
    end
    
    methods ( Access = private )
        function obj = SGLEyelinkEyeServer(filename)
            obj = obj@ABSEyeServer(filename);
            obj.config = EyelinkConfig;
            obj.config.read_config_from_tracker;
            scrSz = obj.config.screen_pixel_coords;
            obj.screenSize = [max(scrSz([1 3])) max(scrSz([2 4]))];
            
            obj.blinkStartEvent = IPCEvent('BlinkStart');
            obj.blinkEndEvent = IPCEvent('BlinkEnd');
            obj.saccadeStartEvent = IPCEvent('SaccadeStart');
            obj.saccadeEndEvent = IPCEvent('SaccadeEnd');
            
        end
    end
    
    
    methods ( Access = public )
        
        function eyePosition = acquire_eye_position(obj)
            
            % get the newest sample in the form of an event structure
            evt = Eyelink('NewestFloatSample');
            
            % translate coordinates to rel. to center
            x = evt.gx(obj.usedEye+1)-obj.screenSize(1)/2;
            y = (1*evt.gy(obj.usedEye+1)-obj.screenSize(2)/2);
            eyePosition = [x y];
            
            % Handle events
            evtype = Eyelink('GetNextDataType');
            switch evtype
                case 3
                    obj.blinkStartEvent.trigger();
                case 4
                    obj.blinkEndEvent.trigger();
                case 5
                    obj.saccadeStartEvent.trigger();
                case 6
                    obj.saccadeEndEvent.trigger();
                otherwise
                    
            end
            java.lang.Thread.sleep(1)
            
        end
        
        function draw_tracker(obj, tracker)
            if isempty(tracker)
                Eyelink('Command', 'clear_screen 0');
                return
            end
            
            position = tracker.center;
            tolerance = tracker.tolerance;
            x1 = position(1)-tolerance+obj.screenSize(1)/2;
            y1 = position(2)-tolerance+obj.screenSize(2)/2;
            x2 = x1+2*tolerance;
            y2 = y1+2*tolerance;
            cmd = sprintf('draw_box %u %u %u %u 15', x1, y1, x2, y2);
            Eyelink('Command',  cmd);
            
        end
        
        function initialize(obj)
            
            err = Eyelink('Initialize');
            assert(err == 0, 'Eyelink: Could not initialize link')
            Eyelink('Command', 'link_sample_data = LEFT,RIGHT,GAZE,AREA');
            Eyelink('Command', 'link_event_data = GAZE,GAZERES,HREF,AREA,VELOCITY');
            Eyelink('Command', 'link_event_filter = LEFT,RIGHT,BLINK,SACCADE');
            
            if ~isempty(obj.filename)
                [obj.folder,base,ext] = fileparts(obj.filename);
                if length(base) > 8
                    warning('Eyelink: filename will be shortened on Eyelink PC to %s', base(1:8))
                    base = base(1:8);
                end
                obj.shortFilename = [base ext];
                err = Eyelink('OpenFile', obj.shortFilename);
                assert(err == 0, 'Eyelink: Could not open %s', obj.filename)
            end
            Eyelink('StartRecording');
            obj.usedEye = Eyelink('EyeAvailable'); % get eye that's tracked
            if  obj.usedEye == 2; % if both eyes are tracked
                obj.usedEye  = 0; % use left eye
            end
            obj.draw_tracker([])
        end
    end
    
    
    methods ( Access = public )
        function stop(obj)
            Eyelink('StopRecording');
            
            if ~isempty(obj.filename);
                err = Eyelink('CloseFile');
                assert(err == 0, 'Eyelink: Could not close data file')
                fprintf('Receiving data file\n')
                nBytes = Eyelink('ReceiveFile');
                
                if ~isequal(fullfile(pwd, obj.shortFilename), obj.filename)
                    movefile(obj.shortFilename, obj.filename);
                end
                fprintf('Stored %g MB in %s\n', nBytes/1024/1024, obj.filename)
            end
        end
        
        function delete(obj)
            obj.draw_tracker([])
            Eyelink('Shutdown');
        end
    end % public methods
    
end % classdef
