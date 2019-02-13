

%% Start ControlScreen and dummy EyeServer
cfg = ArcadeConfig;
cfg.ControlScreen = 'MatlabControlScreen.bat';
cfg.EyeServer = 'EyeLinkServer.exe';
cfg.DaqServer = [];
cfg.StimServer = [];

p = launch_processes(cfg);

%% Write random data into pipe

tStart = tic;
for trial = 1:100
    % current = [currentCondition currentBlock currentTrial]
    % trialdata = [trialError, reactionTime, trialErrorTime, writeTime];
    current = [randi(10), 1, trial];
    trialdata = [abs(round(randn())+1), randn()*30+200, randn()*30+100, randi(9)];
    SGLTrialDataPipe.WriteTrialData(current, trialdata)
    pause(0.3)
end

%% Clean up
IPCEvent.set_event('ControlScreenDone')

SGLTrialDataPipe.Close
SGLTrialDataPipe.delete
EyeServer.delete
cellfun(@(x) x.stop, p)