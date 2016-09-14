classdef KEYEyeServer < handle 
    % [KEY]
    
    % read 
    % send eye data
    % send command
    
    % 00 - start eye polling 
    % 01 - stop eye polling
    % 86 - disconnect and quit process 
    % 90 - send eye sample
    
    
    % decipher the byte message
    % send a byte message
    
    % READ  -> turn byte message into data
    % WRITE -> turn data into byte message

    % Eye Server should report error
    % Eye Server should return eye signal
    
    % Other than that everything is a command
    
    %---------------------------------------------%
    % Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    methods(Static)
        %# constructor 
        function this = KEYEyeServer
        end

        %# message key
        function msg = mGetMessageKey(byte_string)
            % task -> Read / Write
            % is byte   -> convert to string (first two bytes)
            % if string -> convert to byte   (send as two bytes)
            
            %byte_string = typecast(uint16(7),'uint8');
            %byte_string = 'load_cfg';
            
            messageMap = {...
                uint16( 0), 'start_eye';...   % sent by client
                uint16( 1), 'stop_eye';...    % sent by client
                uint16( 7), 'load_cfg';...    % sent by client
                uint16(86), 'quit_proc';...   % sent by client
                uint16(90), 'request_eye';... % sent by client
                uint16(91), 'eye_data';...   % sent by server
                uint16(99), 'reply_err'};     % sent by server
            
            if isnumeric(byte_string)
                msg_id   = typecast(byte_string,'uint16');
                msgIdx   = msg_id==cell2mat(messageMap(:,1));
                msg      = messageMap{msgIdx,2};
            elseif ischar(byte_string)
                msgIdx   = strcmpi(byte_string,messageMap(:,2)); 
                msg      = typecast(messageMap{msgIdx,1},'uint8');
            end
        end
        
      
        %# read/write eye data
        function msg = mIOEyeData(task, varargin)

            switch task
                case 'Read'
                    % 1:2, 3:6, 7:10, 11:14
                    % 2-bytes, 4-bytes, 4-Bytes, 4-bytes 
                    msg = double(typecast(varargin{1}(1:8),'single'));
                case 'Write'
                    %varargin{1} [X,Y]
                    %varargin{2} timestamp **not used yet**
                    key = KEYEyeServer.mGetMessageKey('eye_data');
                    eye_data = [varargin{1},99999];
                    msg = [key, typecast(single(eye_data),'uint8')];
            end
        end % function 
    end % methods
end % classdef

