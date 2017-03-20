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
        function result = mOpenServer(this)
            pipeAccess = 'PIPE_ACCESS_DUPLEX';
            pipeMode   = 'PIPE_NOWAIT | PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE';
            
            % create a named pipe
            this.hPipe = MSNamedPipe.mCreateNamedPipeA(this.pipeName,pipeAccess,pipeMode,this.pipeBuffer);
            
            % test if creation was successful
            [result, flags, outSize, inSize, ~] = MSNamedPipe.mGetNamedPipeInfo(this.hPipe);
            if ~(result > 0) || flags ~= 5 || outSize ~= this.pipeBuffer(1) || inSize~= this.pipeBuffer(2)
                error('MSMessagePipe:mOpenServer', 'Message pipe creation of %s failed', this.pipeName)
            end                        
            
            % wait for connect
            result = this.mCheckClientIsConnected();
            
        end
        
        %# connect to server as a client
        function result = mOpenClient(this)
            pipe_available = this.mWaitForServerAvailable(5000);
            if ~pipe_available
                error('MSMessagePipe:mOpenClient',...
                    'Named pipe %s not available', this.pipeName);
            end
            
            % connect to pipe
            pipeAccess = 'GENERIC_READ_WRITE';
            hPipe = MSNamedPipe.mCreateFileA(this.pipeName,pipeAccess); %#ok<*PROP>
            
            % set as a message pipe
            pipeMode = 'PIPE_READMODE_MESSAGE | PIPE_NOWAIT';
            result = this.mSetNamedPipeHandleState(hPipe,pipeMode);
            if ~result
                error('MSMessagePipe:mOpenClient',...
                    'Unable to set pipe mode for %s', this.pipeName);
            end
            
            % check successful creation
            [result, flags, outSize, inSize, ~] = MSNamedPipe.mGetNamedPipeInfo(hPipe);
            if ~(result > 0) || flags ~= 4 || outSize ~= this.pipeBuffer(1) || inSize~= this.pipeBuffer(2)
                error('MSMessagePipe:mOpenClient', ...
                    'Message pipe creation of %s failed', this.pipeName)
            end
            this.hPipe = hPipe;
            
        end
        
        %# client has connected to server  [server]
        function result = mCheckClientIsConnected(this)
            result = this.mConnectNamedPipe(this.hPipe);
        end
        
        %# server is available for connection [client]
        function result = mWaitForServerAvailable(this,timeout)
            tStart = tic;
            result = 0;
            while (toc(tStart)<(timeout/1000) && result == 0)
                result = this.mWaitNamedPipeA(this.pipeName,timeout);
                pause(0.005)
            end
        end
        
        function result = mIsServer(this)
            result = false;
            if ~isempty(this.hPipe)
                [result, flags] = MSNamedPipe.mGetNamedPipeInfo(this.hPipe);
                if flags == 5
                    result = true;
                end
            end
        end
    end
    
    methods
        function delete(this)
            hPipe = this.hPipe;
            if ~isempty(hPipe)
                if this.mIsServer();
                    successFlush = this.mFlushFileBuffers(hPipe);
                    successDisconnect = this.mDisconnectNamedPipe(hPipe);
                    if any([successFlush, successDisconnect] == 0)
                        warning('Server disconnect of pipe %s failed. Client already closed?', this.pipeName)
                    end
                end
                successClose = this.mCloseHandle(hPipe);
                if successClose == 0
                    warning('Closing of pipe %s failed', this.pipeName)
                end
            end
        end
    end
end