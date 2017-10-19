function reward(rewardTimes)
% REWARD - Give a reward pulse or pulse sequence.
% 
% INPUT
% -----
% 
%  rewardTime : durations of reward pulses and inter-reward intervals in ms
% 
% 
% EXAMPLE
% -------
% Give 100 ms reward pulse
%   reward(100)  
% 
% Give 2x50 ms pulse with a pause of 40 ms 
%   reward([50 40 50]) 
% 
% 
if DaqServer.GetConnectionStatus()
    DaqServer.Reward(rewardTimes);
else
    warning('Reward triggered but not connected to DAQ/Reward server')
end
    
