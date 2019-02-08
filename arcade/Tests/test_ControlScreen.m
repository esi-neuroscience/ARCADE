

%% Start ControlScreen and dummy EyeServer
cfg = [];
cfg.ControlScreen = 'MatlabControlScreen.bat';
cfg.EyeServer = 'EyeLinkServer.exe';
cfg.DaqServer = 'None';
cfg.StimServer = 'None';

p = launch_processes(cfg);

%% Write random data into pipe

tStart = tic;
for trial = 1:20
    % current = [currentCondition currentBlock currentTrial]
    % trialdata = [trialError, reactionTime, trialErrorTime, writeTime];
    current = [randi(10), 1, trial];
    trialdata = [randi(9), rand()*1000, rand()*1000, 15];
    SGLTrialDataPipe.WriteTrialData(current, trialdata)
    pause(rand*2+0.2)
end

%% Clean up
IPCEvent.set_event('ControlScreenDone')

SGLTrialDataPipe.Close
SGLTrialDataPipe.delete
EyeServer.delete
cellfun(@(x) x.stop, p)