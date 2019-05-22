function trialerror( trlerr )
%TRIALERROR Store outcome of trial in behavioral record file
% 
% INPUT
% -----
%   trlerr : code for outcome of trial in range 1-9
%
%
% EXAMPLE
% -------
%  ...
%  sCorrect = State('correct');
%  sCorrect.duration = 0;
%  sCorrect.onEntry = {
%     @(x) trialerror(1)
%    };
%  ...
%
% For more information, see <a href="matlab:doc('arcade')">the ARCADE guide</a>.


BHVStore = SGLBehaviouralStore.launch;
BHVStore.trialError(BHVStore.currentTrial) = trlerr;
trialerror_tic('end');

end











