function storeUserVariables(var) 
% STOREUSERVARIABLES - Store a variable in the behavioral data file of ARCADE.
% 
% INPUT
% -----
%   var : MATLAB variable to be stored in behavioral data
% 
% Only one variable per trial can be stored. Multiple
% variables can be held together in cell array or struct.
% 
% Note: large variables (> ~5 MB) will cause a noticable delay.
% 
BHVStore = SGLBehaviouralStore.launch;
BHVStore.userVariables{BHVStore.currentTrial} = var;

end