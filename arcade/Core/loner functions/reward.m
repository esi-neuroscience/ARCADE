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
persistent warnedAlready
if any(rewardTimes == 0)
	warning('Reward of zero requested and ignored')
	return
end

if DaqServer.GetConnectionStatus()
    DaqServer.Reward(rewardTimes);
else
	totalRewardTime(sum(rewardTimes(1:2:end)))
	if isempty(warnedAlready)
	    warning('Reward triggered but not connected to DAQ/Reward server')
	    warnedAlready = true;
	end		
end
    
