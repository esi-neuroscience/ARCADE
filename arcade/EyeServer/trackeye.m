function eventNames = trackeye(position, tolerance, name)
readyEvent = IPCEvent('EyeTrackerReady', false);
if nargin == 1 && strcmp(position, 'reset')
    SGLEyeServerPipe.WriteEyeTrackerMsg([inf Inf], Inf, Inf)       
    % wait for ready event of eye server
	wasTriggered = readyEvent.waitForTrigger(5000);
	assert(wasTriggered, 'Setting eye tracker failed')
    return
end


SGLEyeServerPipe.WriteEyeTrackerMsg(position, tolerance, name)
% wait for ready event of eye server
wasTriggered = readyEvent.waitForTrigger(5000);
assert(wasTriggered, 'Setting eye tracker failed')

eventNames = {[name 'In'], [name 'Out']};