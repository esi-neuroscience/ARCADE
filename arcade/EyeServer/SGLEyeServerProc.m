classdef (Sealed) SGLEyeServerProc < SPCServerProc
    % [SINGELTON] EYE SERVER PROCESS
    
    % INHERITANCE:
    %   SGLEyeServerProc < ...
    %       SPCServerProc < handle
    
    % INHERITED PROPERTIES:
    %   FPATH % filepath manager object
    
    
    %------------------------------------------%
    % 29.4.2016 - Jarrod, wrote class
    
    methods (Static)
        function this = launch
            persistent thisObj
            if isempty(thisObj) || ~isvalid(thisObj)
                thisObj = SGLEyeServerProc;
            end
            this = thisObj;
        end
    end
     
    methods (...
            Access = private,...
            Hidden = true) 
        %# constructor
        function this = SGLEyeServerProc
            % create diary
            this.mCreateProcessDiary('EyeServer');
            % always print header
            this.mPrintErrorLogHeader('Eye Server');
            % ensure command line is writtent to txt file
            this.mFlushDiary;
        end
    end
    
    
    methods
        function mRunServer(this, eyeServerType)
            % initialize eye server
            
            switch eyeServerType
                case 'NationalInstruments'
                    eyeServer = SGLNiEyeServer.launch();
                case 'Test'
                    eyeServer = SGLTestEyeServer.launch();
                case 'Eyelink'
                    eyeServer = SGLEyelinkEyeServer.launch();                
            end
            readyEvent = IPCEvent('EyeServerReady');
            readyEvent.trigger();
            
            %----------------------------%
            this.mWriteToDiary('Starting eye data acquisition', true);
            eyeServer.start();
            
            %---------------------------%
            this.mWriteToDiary('Stopping data acquisition', false);
            
            
            delete(eyeServer);
        end
    end
    
end


