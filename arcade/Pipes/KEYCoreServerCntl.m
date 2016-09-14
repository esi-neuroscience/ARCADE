classdef KEYCoreServerCntl < handle
    % [KEY]
    
    % READ  -> turn byte message into data
    % WRITE -> turn data into byte message

    % buffer eye
    %
    
    %---------------------------------------------%
    % Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    methods (Static)
        %# constructor 
        function this = KEYCoreServerCntl
        end

        %# message key
        function msg = mGetMessageKey(byte_string)
            % task -> Read / Write
            % is byte   -> convert to string (first two bytes)
            % if string -> convert to byte   (send as two bytes)
            
            %byte_string = typecast(uint16(7),'uint8');
            %byte_string = 'load_cfg';
            
            messageMap = {...
                uint16( 0), 'start';...         % sent by client
                uint16( 1), 'stop';...          % sent by client
                uint16( 7), 'load_cfg';...      % sent by client
                uint16(86), 'quit_proc';...     % sent by client
                uint16(87), 'pause_request';... % sent by server
                uint16(90), 'trial_data';...    % sent by client
                uint16(99), 'reply_err'};       % sent by server
            
            if isnumeric(byte_string)
                msg_id   = typecast(byte_string,'uint16');
                msgIdx   = msg_id==cell2mat(messageMap(:,1));
                msg      = messageMap{msgIdx,2};
            elseif ischar(byte_string)
                msgIdx   = strcmpi(byte_string,messageMap(:,2)); 
                msg      = typecast(messageMap{msgIdx,1},'uint8');
            end
        end
        
        
%         %# read message 
%         function msg = mReadMessage(byte_message)
%             messageMap = {...
%                 uint16(0), 'mCommandMessage';...
%                 uint16(1), 'mTrialDataMessage'};
% 
%             msg_id   = typecast(byte_message(1:2),'uint16');
%             msgIdx   = msg_id==cell2mat(messageMap(:,1));
%             msg = KEYCoreServerCntl.(messageMap{msgIdx,2})('Read',byte_message(3:end));
%         end

%         %# Command Message
%         function msg = mCommandMessage(task,cmd)
%             % *** reads should exclude key ***
%             %-------------------------------------%
%             % Commands => [00 C]
%             % 0 [uint8] -> quit
%             % 1 [uint8] -> start
%             %-------------------------------------%
%             cmdKey         = uint16(0);
%             commandMapping = {...
%                 uint8(0),'quit';...
%                 uint8(1),'start'};
%             %cmd = 'start';
%             switch task
%                 case 'Read'
%                     msgIdx = cmd==cell2mat(commandMapping(:,1));
%                     msg = commandMapping{msgIdx,2};
%                 case 'Write'
%                     msgIdx   = strcmpi(cmd,commandMapping(:,2));
%                     cmd_byte = commandMapping{msgIdx,1};
%                     msg      = [typecast(cmdKey,'uint8'), cmd_byte];
%             end
%         end
        
        %# Trial Data Message 
        function msg = mIOTrialData(task, varargin)
            % *** reads should exclude key ***
            %-------------------------------------%
            % varargin{1} 6-bytes  (3*2bytes)
            % current = uint16([currentCondition, currentBlock, currentTrial]);
            % varargin{2} 12-bytes (4*4bytes) 
            % trldata = single([trialError, reactionTime, trlErrorTime, WriteTime]);
            %-------------------------------------%

            switch task
                case 'Read'
                    msg = [...
                        double(typecast(varargin{1}(1:6),'uint16')),...
                        double(typecast(varargin{1}(7:22),'single'))];
                case 'Write'
                    TrialDataKey = KEYCoreServerCntl.mGetMessageKey('trial_data');
                    msg = [...
                        TrialDataKey,...
                        typecast(uint16(varargin{1}(1:3)),'uint8'),...
                        typecast(single(varargin{2}(1:4)),'uint8')];
                    
            end
        end 
    end % methods
end % classdef 

