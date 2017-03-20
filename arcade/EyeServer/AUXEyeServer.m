classdef AUXEyeServer < MSMessagePipe & KEYEyeServer
    % [AUXILLARY]
    
    % combines MSMessagePipe & KEYEyeServer
    % dispatch eye data
    % request eye data
    
    % INHERITANCE:
    % AUXEyeServer < ...
    %   MSMessagePipe < MSNamedPipe < handle
    %   KEYEyeServer < KEYEyeServer < handle
    
    %---------------------------------------------%
    % Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    properties (Abstract = true)
        hPipe      % pipe handle
        pipeBuffer % pipe [OUT IN] relative to server
        pipeName   % pipe name
    end
    
    
    methods (Static)
        function this =  AUXEyeServer
        end
    end
    
    methods
        %# send command message
        function success = mWriteCommandMessage(this, cmd, varargin)
            % uint16( 0), 'start_eye';...   % sent by client
            % uint16( 1), 'stop_eye';...    % sent by client
            % uint16(86), 'quit_proc';...   % sent by client
            % uint16(90), 'request_eye';... % sent by client
            
            byte_msg = this.mGetMessageKey(cmd);
            success  = this.mWriteFile(this.hPipe,byte_msg);
        end
        
        function [msg, byte_msg] = mReadMessageKey(this)
            msg = [];
            byte_msg = this.mReadFile(this.hPipe,this.pipeBuffer(2));
            if isempty(byte_msg), return; end; % no message
            msg  = this.mGetMessageKey(byte_msg(1:2));
        end
        
        
        function success = mWriteEyeData(this,eye_pos) % [x,y]
            hPipe = this.hPipe; %#ok<*PROP>
            % check for eye data request
            byte_msg = KEYEyeServer.mIOEyeData('Write',eye_pos);
            success = this.mWriteFile(hPipe,byte_msg);
        end
        
        function eye_pos = mRequestEyeData(this)
            eye_pos     = [];
            hPipe       = this.hPipe;
            pipeReadBuf = this.pipeBuffer(2);
            % key_eye  = this.mGetMessageKey('eye_data');
            
            key_eye = this.mGetMessageKey('request_eye');
            success = this.mWriteFile(hPipe, key_eye);
            byte_msg = [];
            if success
                while isempty(byte_msg)
                    java.lang.Thread.sleep(1); % wait a ms
                    byte_msg = this.mReadFile(hPipe, pipeReadBuf);                    
                end
                str_msg  = this.mGetMessageKey(byte_msg(1:2));
                if strcmpi(str_msg,'eye_data')
                    eye_pos = KEYEyeServer.mIOEyeData('Read',byte_msg(3:end));
                else
                    warning('AUXEyeServer:mRequestEyeData', 'Wrong message: %s', str_msg)
                end
            else
                error('AUXEyeServer:mRequestEyeData', 'Request of eye data failed')
            end            
        end
    end
end

