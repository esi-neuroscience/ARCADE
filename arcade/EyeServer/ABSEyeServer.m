classdef ABSEyeServer < handle
    % Abstract class for Eye Servers
    %
    
    properties
        sharedMemoryName = 'EyePosition'
    end
    
    properties ( Access = protected )
        sharedMemory
    end
    
    methods
        function this = ABSEyeServer
            sharedObject = MSNamedSharedMemory;
            sharedObject.mCreateFileMapping(this.sharedMemoryName, 16);
            setdatatype(sharedObject.pointer, 'doublePtr', 2);
            sharedObject.pointer.Value = [0.0; 0.0];
            this.sharedMemory = sharedObject;
            
        end
    end
    
    methods ( Abstract = true )
        start(this)
    end
end