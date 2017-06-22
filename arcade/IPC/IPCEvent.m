classdef IPCEvent < handle
    
    properties        
        name
    end
    
    properties ( Access = private )
        hEvent = libpointer;
    end
    
    properties ( Dependent )
       wasTriggered 
    end
    
    methods
        function this = IPCEvent(eventName, manualReset)        
            if nargin < 2
                manualReset = false;
            end
            this.name = eventName;
            this.hEvent = MSEvents.mCreateEvent(this.name, manualReset);
            
        end
        
        function trigger(this)
            result = MSEvents.mSetEvent(this.hEvent);
            assert(result>0, 'Failed to trigger event %s', this.name)
        end
        
        function reset(this)
            result = MSEvents.mResetEvent(this.hEvent);
            assert(result > 0, 'Failed to reset event %s', this.name)
        end
        
        function wasTriggered = waitForTrigger(this, timeout)
            result = MSEvents.mWaitForEvent(this.hEvent, timeout);
            if result == 0
                wasTriggered = true;
            elseif result == 258
                wasTriggered = false;
            else
                error('Unknown return value during wait for event %s', this.name)
            end
        end
        
        function wasTriggered = get.wasTriggered(this)
            wasTriggered = this.waitForTrigger(0);
        end
            
        
        function delete(this)            
            result = MSEvents.mCloseHandle(this.hEvent);
            assert(result > 0, 'Failed to close event handle %s', this.name)
        end
        
    end
    
    
end