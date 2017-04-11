classdef SGLEyelinkEyeServer < ABSEyeServer
    
    methods (Static)
        function this = launch
            persistent thisObj
            if isempty(thisObj) || ~isvalid(thisObj)
                thisObj = SGLTestEyeServer;
            end
            this = thisObj;
        end
    end
    
    methods ( Access = private )
        function this = SGLEyelinkEyeServer()
            this = this@ABSEyeServer;            
            status = Eyelink('Initialize')
            Eyelink('Command', 'link_sample_data = LEFT,RIGHT,GAZE,AREA');
            edfFile='demo.edf';
            Eyelink('Openfile', edfFile);
            
        end
    end % private methods
    
    
    methods ( Access = public )
        
        
        function start(this)
            MISSING_DATA=-32768;
            eye_used = 0;
            stopEvent = IPCEvtServer('StopEyelink')
            
            
            err =  Eyelink('StartRecording'); % [,file_samples, file_events, link_samples, link_events] )
            Eyelink('Message', 'SYNCTIME');
            
            % TODO: add event for stopping the recording
            while true 
                if Eyelink('NewFloatSampleAvailable') > 0
                    % get the sample in the form of an event structure
                    evt = Eyelink('NewestFloatSample');
                    x = evt.gx(eye_used+1); % +1 as we're accessing MATLAB array
                    y = evt.gy(eye_used+1);
                    if x~=MISSING_DATA && y~=MISSING_DATA && evt.pa(eye_used+1)>0
                        this.sharedMemory.pointer.Value = [x; y];
                    end
                end
                if stopEvent.wasTriggered
                    break
                end
                java.lang.Thread.sleep(1)
            end
            this.stop()
        end
        
        
        function this = stop(this)
            Eyelink('StopRecording');
            Eyelink('CloseFile');
            status=Eyelink('ReceiveFile');
            
        end
        
        
        function delete(this)
            this.stop()
            Eyelink('Shutdown');
        end
    end % public methods
    
end % classdef


%  Eyelink('Command', 'screen_pixel_coords = %d %d %d %d',rect(1),rect(2),rect(3)-1,rect(4)-1);