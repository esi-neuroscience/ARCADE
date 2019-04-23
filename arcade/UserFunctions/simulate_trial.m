function simulate_trial(cfg, trialno)
% SIMULATE_TRIAL - Populate current workspace with ARCADE runtime variables
%
%   simulate_trial([cfg, trialno])   
%
% This function will create all editable variables as defined in the 
% configuration and a TrialData struct in the workspace it was called from. 
% This is useful for testing a task script without launching ARCADE.
%
% INPUT (optional)
% ----------------
%   cfg : struct, ArcadeConfig object or path to cfg
%   trialno : simulated current trial number to be passed to 
%             condition/block selection functions
% 
% For more information, see <a href="matlab:doc('arcade')">the ARCADE guide</a>.
%
% See also ArcadeConfig

if nargin < 2
    trialno = 1;
end
if nargin < 1
    cfg = ArcadeConfig();
end

    
cfg = ArcadeConfig(cfg);
clear SGLBehviouralStore
bhv = SGLBehaviouralStore.launch(cfg);

bhv.mCreateTrialData();

EditableVars = bhv.mGetEditableVariables;
fields = fieldnames(EditableVars);
for k = 1:length(fields)
    assignin('caller', fields{k}, EditableVars.(fields{k}))
end

TrialData    = bhv.mGetTrialData;

[curCond, curBlock] = bhv.mCallTrialSelectionFcns(trialno);

TrialData.currentCondition = curCond;
TrialData.currentBlock = curBlock;
TrialData.currentTrial = trialno;

assignin('caller', 'TrialData', TrialData);