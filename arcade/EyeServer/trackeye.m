function eventNames = trackeye(position, tolerance, name)

if nargin == 1 && strcmp(position, 'reset')
    SGLEyeServerPipe.WriteEyeTrackerMsg([inf Inf], Inf, Inf)
end

SGLEyeServerPipe.WriteEyeTrackerMsg(position, tolerance, name)

eventNames = {[name 'Enter'], [name 'Leave']};