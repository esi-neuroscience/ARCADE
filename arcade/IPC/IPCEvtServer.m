classdef IPCEvtServer < MSEvents
    
    properties
        name
    end
    
    properties ( Access = private )
        hEvent
    end
    
    methods
        
        function this = IPCEvtServer(eventName)
            this.hEvent = this.mCreateEvent(eventName);
            this.name = eventName;
        end
        
        function wasTriggered = mWaitForTrigger(timeout)
            WAIT_TIMEOUT = 258;
            result = this.mWaitForEvent(this.hEvent,timeout) % timeout = ms
            wasTriggered = (result ~= WAIT_TIMEOUT); 
        end
        
        function wasTriggered = wasTriggered(this)      
            WAIT_TIMEOUT = 258;
            result = this.mWaitForEvent(this.hEvent, 0); % timeout = ms
            wasTriggered = (result ~= WAIT_TIMEOUT);
            
        end
        
        function delete(this)
            result = this.mCloseHandle(this.hEvent);
            assert(result > 0, 'Could not release handle of event %s', this.name)
        end
        
    end
    
    
    
    
end