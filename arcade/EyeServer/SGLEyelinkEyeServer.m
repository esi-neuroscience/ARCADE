classdef SGLEyelinkEyeServer < ABSEyeServer
    
    properties
        filename = [];
        usedEye = 0;
        screenSize = [1680 1050]; % x y in px
        eyeTracker = {};
    end
    
    
    properties ( Access = private )
        folder = [];
        shortFilename = [];
    end
    
    methods (Static)
        function this = launch(filename)
            persistent thisObj
            if isempty(thisObj) || ~isvalid(thisObj)
                if nargin == 0
                    filename = [];
                end
                thisObj = SGLEyelinkEyeServer(filename);
                
            end
            this = thisObj;
        end
    end
    
    methods ( Access = private )
        function this = SGLEyelinkEyeServer(filename)
            this = this@ABSEyeServer;
            this.filename = filename;
            
            
            
            err = Eyelink('Initialize');
            assert(err == 0, 'Eyelink: Could not initialize link')
            Eyelink('Command', 'link_sample_data = LEFT,RIGHT,GAZE,AREA');
            if ~isempty(this.filename)
                [this.folder,base,ext] = fileparts(filename);
                if length(base) > 8
                    warning('Eyelink: filename will be shortened on Eyelink PC to %s', base(1:8))
                    base = base(1:8);
                end
                this.shortFilename = [base ext];
                err = Eyelink('OpenFile', this.shortFilename);
                assert(err == 0, 'Eyelink: Could not open %s', this.filename)
            end
            
            % Create pipe
            SGLEyeServerPipe.Create();
        end
    end % private methods
    
    
    methods ( Access = public )
        
        
        function start(this)
            MISSING_DATA=-32768;
            
            stopEvent = IPCEvent('StopEyeServer');
            stopEvent.CreateEvent();
            
            
            err =  Eyelink('StartRecording');
            assert(err == 0, 'Eyelink: Could not start recording')
            err = Eyelink('Message', 'SYNCTIME');
            assert(err == 0, 'Eyelink: Could not reset time to zero')
            
            
            while ~stopEvent.wasTriggered && Eyelink('CheckRecording') == 0
                
                this.setup_eye_tracker();
                
                if Eyelink('NewFloatSampleAvailable') > 0
                    % get the sample in the form of an event structure
                    evt = Eyelink('NewestFloatSample');
                    x = evt.gx(this.usedEye+1)-this.screenSize(1)/2;
                    y = -1*(1*evt.gy(this.usedEye+1)-this.screenSize(2)/2);
                    if x~=MISSING_DATA && y~=MISSING_DATA && evt.pa(this.usedEye+1)>0
                        this.sharedMemory.pointer.Value = [x; y];
                    end
                    for iTracker = 1:length(this.eyeTracker)
                        this.eyeTracker{iTracker}.checkEye();
                    end
                end
                java.lang.Thread.sleep(1)
                drawnow
            end
            this.stop()
        end
        
        
        function stop(this)
            Eyelink('StopRecording');
            
            if ~isempty(this.filename);
                err = Eyelink('CloseFile');
                assert(err == 0, 'Eyelink: Could not close data file')
                fprintf('Receiving data file\n')
                nBytes = Eyelink('ReceiveFile');
                if ~isequal(fullfile(pwd, this.shortFilename), this.filename)
                    movefile(this.shortFilename, this.filename);
                end
                fprintf('Stored %g MB in %s\n', nBytes/1024/1024, this.filename)
            end
            
            
        end
        
        function setup_eye_tracker(this)
            [position, tolerance, name] = SGLEyeServerPipe.ReadEyeTrackerMsg();
            if ~isempty(position)
                obj.eyeTracker{end+1} = EyeTracker(name, position, tolerance);
            elseif isequal(position, [int16(Inf) int16(Inf)]) && tolerance == uint16(Inf)
                this.eyeTracker = {};
            end
            
        end
        
        function delete(this)
            Eyelink('Shutdown');
            SGLEyeServerPipe.delete();
        end
    end % public methods
    
end % classdef


%  Eyelink('Command', 'screen_pixel_coords = %d %d %d %d',rect(1),rect(2),rect(3)-1,rect(4)-1);