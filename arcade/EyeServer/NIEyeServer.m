classdef NIEyeServer < handle
    
    properties ( Constant )
        eyelines = {'Dev1/ai0:1'};
        samplingRate = 1000; % Hz
        
        vgain = [10 10]; % V
        screensize = [1680 1050]; % x y in px
        sharedMemoryName = 'EyePosition'; % name for memory mapping to be used in EyeClient
    end
    
    properties ( Access = private )
        nidaqObj
        sharedMemory        
    end
    
    methods
        function this = NIEyeServer
            this.nidaqObj = mNIDAQ;
            this.nidaqObj.daqmxCreateAIVoltageChan(this.eyelines); % create channels
            this.nidaqObj.daqmxCfgSampClkTiming(this.samplingRate)
            
            sharedObject = MSNamedSharedMemory;
            sharedObject.mCreateFileMapping(this.sharedMemoryName, 16);
            setdatatype(sharedObject.pointer, 'doublePtr', 2);
            sharedObject.pointer.Value = [0.0; 0.0];
            this.sharedMemory = sharedObject;            
            
        end
        
        function this = start(this)
            this.nidaqObj.daqmxStartTask();
            try
                while true
                    analogInput = this.nidaqObj.daqmxReadAnalogF64(1);
                    [xPx, yPx] = volts2pixels(analogInput(1),analogInput(2), ...
                        this.vgain, this.screensize);
                    this.sharedMemory.pointer.Value = [xPx; yPx];
%                     java.lang.Thread.sleep(0.1);
                end
            catch me
                delete(this)
                rethrow(me)
            end
            
        end
        
        function this = delete(this)
            delete(this.nidaqObj);
            delete(this.sharedMemory);
        end
    end
end
    
    
    
    
