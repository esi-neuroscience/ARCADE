classdef ( Sealed ) MSMessagePipeClient < MSMessagePipe
    
     
    methods
        function this = MSMessagePipeClient(name, waitMode)
            
            if ~exist('waitMode', 'var')
                waitMode = true;
            end
            this.waitMode = waitMode;
            
            pipeAccess = 'GENERIC_READ_WRITE';
            this.duplex = true;
            
            % open a named pipe
            this.hPipe = MSNamedPipe.mCreateFileA( ...
                name, pipeAccess);
            
            % test if creation was successful
            [result, flags, outSize, inSize, ~] = MSNamedPipe.mGetNamedPipeInfo(this.hPipe);
            if ~(result > 0) || flags ~= 4
                error('Creation of message pipe %s failed', name)
            end
                        
            if ~waitMode 
                pipeMode = 'PIPE_NOWAIT | PIPE_READMODE_MESSAGE';
            else
                pipeMode = 'PIPE_READMODE_MESSAGE';
            end
            
            result = MSNamedPipe.mSetNamedPipeHandleState(this.hPipe, pipeMode);
            assert(result>0, 'Could not waiting state of %s', this.pipeName)
            
            this.pipeBuffer(1) = outSize;
            this.pipeBuffer(2) = inSize;
            this.pipeName = name;
            this.isServer = false;
        end
        
        
    end
end
