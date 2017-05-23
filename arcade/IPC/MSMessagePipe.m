classdef ( Abstract ) MSMessagePipe < handle
    
    properties ( SetAccess = protected )
        hPipe      % pipe handle
        pipeBuffer % pipe [OUT IN] relative to server
        pipeName   % pipe name
        waitMode 
        duplex 
    end
        
    
    
    methods
        
        function result = writeMessage(this, msg)
            result = MSNamedPipe.mWriteFile(this.hPipe,msg);
            if nargout == 0
                clear result
            end
        end
        
        function msg = readMessage(this)
            msg = MSNamedPipe.mReadFile(this.hPipe,this.pipeBuffer(1));
        end
        
        function delete(this)
            successClose = MSNamedPipe.mCloseHandle(this.hPipe);            
            if successClose == 0
                warning('Closing of pipe %s failed', this.pipeName)
            end
        end
        
    end
end