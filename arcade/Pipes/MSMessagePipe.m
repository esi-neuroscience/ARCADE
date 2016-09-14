classdef MSMessagePipe < MSNamedPipe
    % [MICROSOFT] Message Pipe Class
    
    % INHERITANCE:
    %   MSMessagePipe < MSNamedPipe < handle 
    
    %---------------------------------------------%
    % Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    properties (Abstract = true)
        hPipe      % pipe handle
        pipeBuffer % pipe [OUT IN] relative to server
        pipeName   % pipe name
    end
    
    methods (Static)
        function this = MSMessagePipe
        end
    end
    
    methods (Sealed = true)
        %# create server pipe
        function mOpenServer(this)
            pipeAccess = 'PIPE_ACCESS_DUPLEX';
            pipeMode   = 'PIPE_NOWAIT | PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE';

            % create a named pipe 
            this.hPipe = MSNamedPipe.mCreateNamedPipeA(this.pipeName,pipeAccess,pipeMode,this.pipeBuffer);
        end
        
        %# conect to server as a client 
        function mOpenClient(this)
            % client should not try to connect if the 
            % named pipe has not been created, try for 100ms
            pipe_available = this.mWaitForServerAvailable(100);
            if ~pipe_available
                error('MSMessagePipe:mOpenClient',...
                    'Named pipe not available');
            end
            
            % connect to pipe 
            pipeAccess = 'GENERIC_READ_WRITE';
            hPipe = MSNamedPipe.mCreateFileA(this.pipeName,pipeAccess); %#ok<*PROP>
            
            % set as a message pipe
            pipeMode = 'PIPE_READMODE_MESSAGE | PIPE_NOWAIT';
            result = MSNamedPipe.mSetNamedPipeHandleState(hPipe,pipeMode);
            if ~result
                error('MSMessagePipe:mOpenClient',...
                    'Unable to set pipe mode');
            end
            this.hPipe = hPipe;
        end
        
        %# client has connected to server  [server]
        function result = mCheckClientIsConnected(this)
            result = this.mConnectNamedPipe(this.hPipe);
        end
        
        %# server is available for connection [client]
        function result = mWaitForServerAvailable(this,timeout)
            %timeout = 10;
            result = this.mWaitNamedPipeA(this.pipeName,timeout);
        end
    end
    
    methods
        function delete(this)
            hPipe = this.hPipe;
            if ~isempty(hPipe)
                this.mCloseHandle(hPipe);
            end
        end
    end
    
    
end % classdef


