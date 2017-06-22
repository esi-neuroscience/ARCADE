classdef SGLEyelinkEyeServer < ABSEyeServer
    
    properties
        usedEye = 0;
        screenSize = [1680 1050]; % x y in px
    end
    
    
    properties ( Access = private )
        folder = [];
        shortFilename = [];
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
        end
    end
    
    
    methods ( Access = public )
        
        function eyePosition = acquire_eye_position(obj)
            
            tStart = tic;
            timeout = 5; % wait maximally 5s for sample
            newSampleAvailable = Eyelink('NewFloatSampleAvailable')>0;
            while ~newSampleAvailable && toc(tStart) < timeout
                newSampleAvailable = Eyelink('NewFloatSampleAvailable')>0; 
                java.lang.Thread.sleep(1)
            end                            
            % get the sample in the form of an event structure
            evt = Eyelink('NewestFloatSample');
            
            % translate coordinates to rel. to center
            x = evt.gx(obj.usedEye+1)-obj.screenSize(1)/2;
            y = -1*(1*evt.gy(obj.usedEye+1)-obj.screenSize(2)/2);            
            eyePosition = [x y];
        end
        
        function intialize(obj)
            err = Eyelink('Initialize');
            assert(err == 0, 'Eyelink: Could not initialize link')
            Eyelink('Command', 'link_sample_data = LEFT,RIGHT,GAZE,AREA');
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
            
            err =  Eyelink('StartRecording');
            assert(err == 0, 'Eyelink: Could not start recording')
            err = Eyelink('Message', 'SYNCTIME');
            assert(err == 0, 'Eyelink: Could not reset time to zero')
            
        end
        
        
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
            Eyelink('Shutdown');
        end
    end % public methods
    
end % classdef


%  Eyelink('Command', 'screen_pixel_coords = %d %d %d %d',rect(1),rect(2),rect(3)-1,rect(4)-1);