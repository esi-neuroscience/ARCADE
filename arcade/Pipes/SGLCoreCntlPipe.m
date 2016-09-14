classdef (Sealed) SGLCoreCntlPipe < MSMessagePipe & KEYCoreServerCntl
    % [SINGLETON]
    
    % INHERITANCE:
    % SGLCoreCntlPipe < ...
    %   MSMessagePipe < MSNamedPipe < handle 
    %   KEYCoreServerCntl < KEYCoreServerCntl < handle
    
    % MSMessagePipe
    % + mOpenServer(this)
    % + mOpenClient(this)
    
    % KEYCoreServerCntl
    % + msg = mReadMessage(byte_message)
    % + msg = mCommandMessage(task,cmd)
    % + msg = mTrialDataMessage(task, varargin)
    
    %---------------------------------------------%
    % Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    properties
        hPipe      = [];      % pipe handle
        pipeBuffer = [44 44]; % [out, in] relative to server
        pipeName   = '\\.\pipe\CoreServerCntlPipe';
    end
    
    methods (Static)
        function this = launch
            persistent thisObj
            if isempty(thisObj) || ~isvalid(thisObj)
                thisObj = SGLCoreCntlPipe;
            end
            this = thisObj;
        end
    end
    
    methods (Access = private)
        function this = SGLCoreCntlPipe
        end
    end
    
    % use handle
    % pipebuffer 
    methods
        %# send command message
        function success = mWriteCommandMessage(this, cmd, varargin)
            % uint16( 0), 'start';...         % sent by client
            % uint16( 1), 'stop';...          % sent by client
            % uint16(86), 'quit_proc';...     % sent by client
            % uint16(87), 'pause_request';... % sent by server
 
            byte_msg = this.mGetMessageKey(cmd);
            success  = this.mWriteFile(this.hPipe,byte_msg);
        end
        
        function [msg, byte_msg] = mReadMessageKey(this)
            msg = [];
            byte_msg = this.mReadFile(this.hPipe,this.pipeBuffer(2));
            if isempty(byte_msg), return; end; % no message
            msg  = this.mGetMessageKey(byte_msg(1:2));
        end
        
        %# write trial data 
        function success = mWriteTrialData(this,current,trlData)
            % convert data
            byte_msg = this.mIOTrialData('Write',current,trlData);
            % send message
            success = this.mWriteFile(this.hPipe,byte_msg);
        end
        
        %# empty the pipe
        % read pipe until empty
        function msgs = mReadMessagePipeEmpty(this)
            msgs = {};
            while 1
                byte_msg    = this.mReadFile(this.hPipe,this.pipeBuffer(2));
                if isempty(byte_msg), break; end; % no message
                msgs{end+1,1} = this.mGetMessageKey(byte_msg(1:2)); %#ok<*AGROW>
            end
        end


        
%         %# read pipe 
%         function msg = mReadPipe(this)
%             msg = [];
%             % read pipe
%             byte_msg = this.mReadFile(this.hPipe,this.pipeBuffer(2));
%             if ~isempty(byte_msg)
%                 % convert message
%                 msg = this.mReadMessage(byte_msg);
%             end
%         end
    end
  
end

