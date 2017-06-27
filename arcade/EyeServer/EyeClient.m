classdef EyeClient < handle
    % EYECLIENT - Class for retrieving the current eye position from shared
    % memory
    properties
        sharedMemoryName = 'EyePosition';
    end
    
    properties ( Dependent = true, SetAccess = immutable )
        eyePosition
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
        
        function value = get.eyePosition(this)
            value = (this.sharedMemory.pointer.Value)';
        end
    end
    
    
    
    
end
