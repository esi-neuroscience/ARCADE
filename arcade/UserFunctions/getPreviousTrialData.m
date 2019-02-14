function trialdata = getPreviousTrialData()
% GETPREVIOUSTRIALDATA - Retreive behavioral outcomes and conditions of
% previous trials
% 
% USAGE
% ------
%   trialdata = getPreviousTrialData();
% 
% If this function is called during the task script, the last entry of the
% data is already the current trial.
%
% EXAMPLE
% -------
% trialdata = 
% 
%       trialError: [3 3 3 1 3 1]
%       conditions: [1 1 2 2 1 1]
%           blocks: [1 1 1 1 1 1]
%     reactionTime: [NaN NaN NaN 0.2527 NaN 0.3257]
%	 userVariables: [0 0 1 40 NaN 0]


bhv = SGLBehaviouralStore.launch; 
trialdata = [];
trialdata.trialError = bhv.trialError;
trialdata.conditions = bhv.sessionConditions;
trialdata.reactionTime = bhv.reactionTime;
trialdata.blocks = bhv.sessionBlocks;
trialdata.userVariable = bhv.userVariables;