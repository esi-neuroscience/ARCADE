classdef MSEvents < handle
    % [MICROSOFT]
    
    %---------------------------------------------%
    % Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
     

    methods (Static)
        function this = MSEvents
            if ~libisloaded('kernel32'); loadlibrary('kernel32', @win_kernel32); end;
        end
    end
    
    methods (...
            Static = true,...
            Sealed = true)
        
        %# create Event
        % event server 
        function hEvent = mCreateEvent(eventName)
            secAttr = libstruct('s_SECURITY_ATTRIBUTES');
            eventName = uint8([eventName 0]);
            hEvent = calllib('kernel32', 'CreateEventA', secAttr, false, false, eventName);
        end
        
        %# open event
        % event client
        function hEvent = mOpenEvent(eventName)
            %access = uint32(hex2dec('00100000'));
            access = uint32(hex2dec('1F0003'));
            eventName = uint8([eventName 0]);
            [hEvent, ~] = calllib('kernel32', 'OpenEventA', access, false, eventName);
        end
        
        %# flag event
        function result = mSetEvent(hEvent)
            result = calllib('kernel32', 'SetEvent', hEvent);
        end
        
        %# wait for event
        function result = mWaitForEvent(hEvent,timeout) % timeout = ms
            timeout = uint32(timeout); % ulong
            result = calllib('kernel32', 'WaitForSingleObject', hEvent, timeout);
        end
        
        %# reset event
        function result = mResetEvent(hEvent)
           result = calllib('kernel32', 'ResetEvent', hEvent); 
        end
        
        %# close event handle 
        function result = mCloseHandle(hEvent)
            result = calllib('kernel32', 'CloseHandle',hEvent);
        end
    end
    

end



%S = libstruct('s_SECURITY_ATTRIBUTES');
%hA = calllib('kernel32', 'CreateEventA', S, false, false, 'SentData');
% calllib('kernel32', 'CloseHandle',hPipe);
%
%
%}
%calllib('kernel32', 'CloseHandle',hA);
%result = calllib('kernel32', 'ResetEvent', hA);

%


% EyeServer
% poll eye signal
% but only write to the pipe if requested to do so


% event and pipe
% event -> ready for eye
% eye <-- write eye signal

% on a pipe
% eye --> ready for eye
% eye <--- write eye
% ---- offers commands -> start eye buffer
% ----> stop polling eye
% ----> start polling eye 

% if I have written to a pipe
% what happens if I read from the pipe, before the message is read


% opening multiple instances of the same pipe?
















