function storeUserVariables(vars) 
%--------------------------------%
% 3.5.2015 - Jarrod, user vars should be a struct
%--------------------------------%

% variables:
% can be anything in the form of one input 

% if ~iscell(vars) % force into cell 
%     vars = {vars};
% end

BHVStore = SGLBehaviouralStore.launch;
BHVStore.userVariables{BHVStore.currentTrial} = vars;

end