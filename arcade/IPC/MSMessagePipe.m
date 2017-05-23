classdef ( Abstract ) MSMessagePipe < handle
    
    properties ( SetAccess = protected )
        hPipe      % pipe handle
        pipeBuffer % pipe [OUT IN] relative to server
        pipeName   % pipe name
        waitMode 
        duplex 
        isServer 
    end
        
    
    
    methods
        
        function result = writeMessage(this, msg)
            result = MSNamedPipe.mWriteFile(this.hPipe, msg);
            if nargout == 0
                clear result
            end
        end
        
        function msg = readMessage(this)
            if this.isServer
                msg = MSNamedPipe.mReadFile(this.hPipe,this.pipeBuffer(2));
            else
                msg = MSNamedPipe.mReadFile(this.hPipe,this.pipeBuffer(1));
            end
        end
        
        function delete(this)
            successClose = MSNamedPipe.mCloseHandle(this.hPipe);            
            if successClose == 0
                warning('Closing of pipe %s failed', this.pipeName)
            end
        end
        
    end
end