
trl = getConditionInfo(TrialData.currentTrial,'getImageFile',TrialData.currentCondition);
trl.gratDef   = def;
trl.fixDot    = fixdef; 


%----------------------------%
% timing
trl.acqFixTime   = 3250;
trl.fixDuration  = randi([basedurmin,basedurmin+100],1); 
trl.reAcqFixTime = 250;
trl.stimDuration = randi([stimdurmin,stimdurmax],1); %min(round(wblrnd(0.27,2)*1000 + stimdurmin),3000); % not more than 3 seconds
trl.itiDuration  = randi([250+ITIextra,450+ITIextra],1); 
trl.holdTargTime = 100;

% reward
trl.smallReward = 0;    
trl.rewPause    = 0;
trl.reward      = Reward; % editable variable

% write user variables to output file
storeUserVariables(trl);