classdef IPCEvent < handle
    % IPCEVENT - Class for handling kernel32 system events
    % 
    % IPCEvent always calls CreateEvent, which either creates an event or
    % returns the handle of an existing event, see <a href="https://docs.microsoft.com/en-us/windows/desktop/sync/synchronization">MSDN</a> for more information.
    % 
    % Events are created with auto reset by default, i.e. a successful wait 
    % will reset the event.
    % 
    % METHODS
    % -------
    %   trigger : Set event to true
    %   waitForTrigger(timeout) : Wait for specified time (ms) for event to be set
    %   reset   : Reset event to false
    %
    % PROPERTIES
    % ----------
    %   wasTriggered : true if event was set. Checking this property is 
    %                  equivalent to calling waitForTrigger(0)
    %   
    %
    % METHODS (static)
    % ----------------
    %   set_event(eventName) : set/trigger an event without creating an IPCEvent object
    %   wait_for_event(eventName, timeout) : wait for event without creating 
    %                                        an IPCEvent object
    %
    % EXAMPLES
    % --------
    %   event = IPCEvent('StimServerAnimationDone');
    %   result = event.waitForTrigger(2000);
    %
    %   event = IPCEvent('EyeServerDone');
    %   event.trigger();
    %   
    %   result = IPCEvent.wait_for_event('EyeServerDone', 1000)
    %
    % See also State, win_kernel32
    
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
    
    methods ( Static = true )
        function set_event(eventName)
            event = IPCEvent(eventName);
            event.trigger()
        end

        function result = wait_for_event(eventName, timeout)
            event = IPCEvent(eventName);
            result = event.waitForTrigger(timeout);
        end
    end
    
end