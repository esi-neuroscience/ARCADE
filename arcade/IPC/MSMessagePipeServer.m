classdef ( Sealed ) MSMessagePipeServer < MSMessagePipe
     
    
    methods
        function this = MSMessagePipeServer(name, pipeBuffer, waitMode)
            
            pipeAccess = 'PIPE_ACCESS_DUPLEX';
            this.duplex = true;
            
            if waitMode
                pipeMode = 'PIPE_WAIT | PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE';
            else
                pipeMode = 'PIPE_NOWAIT | PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE';
            end
            
            this.waitMode = waitMode;
            
            % create a named pipe
            this.hPipe = MSNamedPipe.mCreateNamedPipeA( ...
                name, pipeAccess, pipeMode, pipeBuffer);
            
            this.pipeBuffer = pipeBuffer;
            this.pipeName = name;
            
            % test if creation was successful
            [result, flags, outSize, inSize, ~] = MSNamedPipe.mGetNamedPipeInfo(this.hPipe);
            if ~(result > 0) || flags ~= 5 || outSize ~= this.pipeBuffer(1) || inSize~= this.pipeBuffer(2)
                error('Creation of message pipe %s failed', this.pipeName)
            end
                        
            
        end
        
        function result = waitForClient(this)
            result = MSNamedPipe.mConnectNamedPipe(this.hPipe);
        end
        
        function delete(this)
            
            successFlush = MSNamedPipe.mFlushFileBuffers(this.hPipe);
            successDisconnect = MSNamedPipe.mDisconnectNamedPipe(this.hPipe);
           
%             delete@MSMessagePipe(this)
           
        end
    end
end
