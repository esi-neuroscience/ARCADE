function eventmarker(value,varargin)
% EVENTMARKER - Send a digital marker for an event to the DAQ card (if
% available) and store the corresponding timestamp in the .evt file.
% 
% INPUT
% -----
%   value : event code number >=0 and <2^16
% 
persistent hasDaqServer
if isempty(hasDaqServer)
	hasDaqServer = NidaqServer.GetConnectionStatus();
end
evtServer = SGLEventMarkerServer.launch();

% if there is a value, and it is an unsigned 16-bit integer
if ~isempty(value) && isnumeric(value) && value<2^16 && value>=0 
    if hasDaqServer
        NidaqServer.EventMarker(round(value));    
    end
    evtServer.storeEvent(value);
else
    error('Eventmarker value (%g) is not a 16-bit integer', value)
end

end

