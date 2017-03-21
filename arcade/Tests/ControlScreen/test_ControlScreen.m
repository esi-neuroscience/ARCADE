
% launch ControlScreen
CntlScreen = ControlScreen.launch;

%% Test: SGLSharedDataPool
ShrdDataPool = SGLSharedDataPool.launch(CntlScreen.hfig);

nTrials = 500;
% INPUT:
% [1] current condition
% [2] current block
% [3] current trial

% [4] trial error
% [5] reaction time
% [6] trial error time stamp

guiperf = zeros(1,2);
t = tic;
for iTrial = 1:nTrials    
    trialData = [randi(99), randi(3) iTrial randi(9) rand()*1000 toc(t)];
    
    ShrdDataPool.mUpdateTrialData(trialData);
    trlMetrics = ShrdDataPool.mComputeTrialMetrics;
    if rem(iTrial, 500) == 0;
        fprintf('Trial %u/%u\n', iTrial, nTrials)
    end
    
    trlMetrics.guiperf = guiperf;
    t = tic;
    CntlScreen.mUpdateControlDisplay('update', trlMetrics);
    pause(rand()*0.5)
end


