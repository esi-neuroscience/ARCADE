classdef (Sealed) SGLEyeServerEvents < MSEvents
    % [SINGLETON]
    
    % INHERITANCE:
    % SGLEyeServerEvents < MSEvents < handle
    
    %---------------------------------------------%
    % Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    
    properties
        hEvent    = [];            % event handle 
        eventName = 'EyeCommand';
        %timeout   = 1;
    end
    
   methods (Static)
        function this = launch
            persistent thisObj
            if isempty(thisObj) || ~isvalid(thisObj)
                thisObj = SGLEyeServerEvents;
            end
            this = thisObj;
        end
    end
    
    methods (Access = private)
        function this = SGLEyeServerEvents
        end
    end
    
    methods
        %# open as server
        function mOpenServer(this)
            this.hEvent = this.mCreateEventA(this.eventName);
        end
        %# open as client 
        function mOpenClient(this)
            this.hEvent = this.mOpenEventA(this.eventName);
        end
        
        %# set event
        function result = mSendEvent(this)
            result = this.mSetEvent(this.hEvent);
        end
        
        %# check event
        function result = mWaitOnEvent(this,timeout)
            %timeout = 1; % ms
            result = this.mWaitForEvent(this.hEvent,timeout);
            result = result==0; % event was flagged when ==0, else error
        end
        
        function delete(this)
           hEvent = this.hEvent; %#ok<*PROP>
           if ~isempty(hEvent)
               this.mCloseHandle(hEvent);
           end
        end
        
    end
           
end

