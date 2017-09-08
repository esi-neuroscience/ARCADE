function setManualRewardDuration(duration)
% setManualRewardDuration - Set reward duration for event-triggered reward
% 
% INPUT
% -----
%   duration : reward duration in ms
% 

NidaqServer.SetRewardTime(duration)