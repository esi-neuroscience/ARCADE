classdef MSEvents < handle

    properties (Constant, Access = private, Hidden = true)
        this = MSEvents
    end
    
    methods (Access = private, Hidden=true)
        function obj = MSEvents()
            if ~libisloaded('kernel32'); loadlibrary('kernel32', @win_kernel32); end;            
        end
    end
    
     
    methods (...
            Static = true,...
            Sealed = true)
        
        %# create Event
        % event server 
        function hEvent = mCreateEvent(eventName, manualReset)
            if nargin < 2
                manualReset = false;
            end
            secAttr = libstruct('s_SECURITY_ATTRIBUTES');
            eventName = uint8([eventName 0]);
            hEvent = calllib('kernel32', 'CreateEventA', secAttr, manualReset, false, eventName);
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
        
        function result = mWaitForMultipleEvents(hEvents, waitAll, timeout)
           timeout = uint32(timeout); % ms
%             DWORD nCount , const HANDLE * lpHandles , BOOL bWaitAll , DWORD dwMilliseconds ); 
%            fcns.RHS{fcnNum}={'ulong', 'voidPtrPtr', 'int32', 'ulong'};

            result = calllib('kernel32', 'WaitForMultipleObjects', ...
                length(hEvents), hEvents, waitAll, timeout)
                
                
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






