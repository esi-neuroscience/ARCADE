function setManualRewardDuration(duration)
%SETMANUALREWARDDURATION Set reward duration for manual reward
%
% INPUT
% -----
%   duration : reward duration in ms
%
% For more information, see <a href="matlab:doc('arcade')">the ARCADE guide</a>.
%
% See also DaqServer

DaqServer.SetRewardTime(duration)
