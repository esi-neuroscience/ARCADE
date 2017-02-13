function eventmarker(value,varargin)

% add in wait option 
% java.lang.Thread.sleep(1);

%----------------------------------%
% 20.3.2015 - Jarrod, 
%    - added in round event value. 

% if there is a value, and it is an unsigned 16-bit integer
if ~isempty(value) && isnumeric(value) && value<2^16 && value>=0
    % get event server
    EventServer = SGLEventMarkerServer.launch;
    
    value = round(value); % ensure it is an integer 
    
    if isempty(varargin)
        EventServer.mSendEventMarker(value);% send eventmarker
    else
        EventServer.mSendEventMaErker(value,varargin{1});% send eventmarker
    end
end

end

