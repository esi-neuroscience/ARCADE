classdef IPCEvtClient < MSEvents
    
    properties        
        name
    end
    
    properties ( Access = private)
        hEvent
    end
    
    methods
        function this = IPCEvtClient(eventName)
            this.hEvent = this.mOpenEvent(eventName);
            this.name = eventName;
        end
        
        function trigger(this)
            result = this.mSetEvent(this.hEvent);
            assert(result>0, 'Failed to trigger event %s', this.name)
        end
        
        function reset(this)
            result = this.mResetEvent(this.hEvent);
            assert(result > 0, 'Failed to reset event %s', this.name)
        end
        
        function delete(this)            
            result = this.mCloseHandle(this.hEvent);
            assert(result > 0, 'Failed to close event handle %s', this.name)
        end
        
    end
    
    
end