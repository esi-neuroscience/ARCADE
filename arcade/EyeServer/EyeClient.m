classdef EyeClient < handle
    
    properties
        sharedMemoryName = 'EyePosition';
    end
    
    properties ( Access = private )
        sharedMemory
    end
    
    methods
        
        function this = EyeClient
            sharedObject = MSNamedSharedMemory;
            sharedObject.mOpenFileMapping(this.sharedMemoryName);
            setdatatype(sharedObject.pointer, 'doublePtr', 2);
            this.sharedMemory = sharedObject;
        end
        
        function eyePos = mGetEyePosition(this)
            eyePos = this.sharedMemory.pointer.Value;
            
        end
    end
    
    
    
    
end
