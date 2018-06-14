function t = totalRewardTime(newReward)
% GETTOTALREWARDTIME - Retreive total reward of session
%
%
%  time = totalRewardTime()
%
persistent time
if isempty(time)
    time = 0;
end

if nargin == 1 && nargout == 0
    time = time + newReward;
    clear t
end

if nargin == 0
    t = time;
end