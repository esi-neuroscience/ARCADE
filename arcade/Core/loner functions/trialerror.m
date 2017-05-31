function trialerror( trlerr )
% Store outcome of trial in behavioral record file
% 
% INPUT
% -----
%   trlerr : code for outcome of trial in range 1-9 

BHVStore = SGLBehaviouralStore.launch;
BHVStore.trialError(BHVStore.currentTrial) = trlerr;
trialerror_tic('end');

end










