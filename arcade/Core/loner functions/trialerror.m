function trialerror( trlerr )

% simple functions 

%t = tic;
BHVStore = SGLBehaviouralStore.launch;
BHVStore.trialError(BHVStore.currentTrial) = trlerr;
trialerror_tic('end');
%toc(t)
%evalin('caller'

%0.000719 sec
%0.000094 sec

end



% trialerror(value)
% reactionTime('start')
% reactionTime('end')








