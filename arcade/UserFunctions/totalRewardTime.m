function t = totalRewardTime(newReward)
%TOTALREWARDTIME Retreive total reward duration of session
%
%  time = totalRewardTime()
%
% The returned total reward duration includes manual reward triggered via 
% the reward button/hotkey.
%
% EXAMPLE
% -------
%	
%	if totalRewardTime() > 2000
%		requestQuitSession()
%	end
%
% For more information, see <a href="matlab:doc('arcade')">the ARCADE guide</a>.
%
% See also DaqServer, reward


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
