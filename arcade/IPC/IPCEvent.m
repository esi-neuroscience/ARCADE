classdef IPCEvent < handle
    % IPCEVENT - Class for handling kernel32 system events
    % 
    % IPCEvent always calls CreateEvent, which either creates an event or
    % returns the handle of an existing event.
    % 
    % Events are created with auto reset by default.
    % 
    % See also State
    properties        
        name % name of event
    end
    
    properties ( Access = private )
        hEvent = libpointer;
    end
    
    properties ( Dependent )
       wasTriggered % boolean flag whether event was triggered
    end
    
    methods
        function this = IPCEvent(eventName, manualReset)
            % Create or open system event
            if nargin < 2
                manualReset = false;
            end
            this.name = eventName;
            this.hEvent = MSEvents.mCreateEvent(this.name, manualReset);
            
        end
        
        function trigger(this)
            % Set event
            result = MSEvents.mSetEvent(this.hEvent);
            assert(result>0, 'Failed to trigger event %s', this.name)
        end
        
        function reset(this)
            % Reset event
            result = MSEvents.mResetEvent(this.hEvent);
            assert(result > 0, 'Failed to reset event %s', this.name)
        end
        
        function wasTriggered = waitForTrigger(this, timeout)
            % Wait for event until timeout in ms is elapsed
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