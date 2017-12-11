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
            setdatatype(sharedObject.pointer, 'singlePtr', 4);
            this.sharedMemory = sharedObject;
        end
        
        function value = get.eyePosition(this)
            value = double(this.sharedMemory.pointer.Value([1 2]))';
        end
    end
    
    
    
    
end
