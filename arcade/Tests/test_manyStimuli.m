
cfg = ArcadeConfig;
cfg.ControlScreen = '';
cfg.StimServer = 'StimServer.exe';
procs = launch_processes(cfg);


%% Test 1


nStimuli = 200;
stim = @Grating;
stimuli = cell(1,nStimuli);
for iStimulus = 1:nStimuli
	stimuli{iStimulus} = stim();
	stimuli{iStimulus}.position = round([rand()*1600-1680/2 rand()*1050-1050/2]);
	stimuli{iStimulus}.direction = round(rand()*360);
	stimuli{iStimulus}.color1 = [randi(255) randi(255) randi(255) 128];
	stimuli{iStimulus}.spatialPeriod = 10+rand()*200;
	stimuli{iStimulus}.temporalFrequency = rand()*5+0.1;
    stimuli{iStimulus}.maskWidth = randi(300)+20;
    stimuli{iStimulus}.maskHeight = stimuli{iStimulus}.maskWidth;
    stimuli{iStimulus}.smoothing = 8*rand()+2;
end

groupStimuli('on')
cellfun(@(x) set(x, 'visible', true), stimuli)
groupStimuli('off')
pause(5)

clear stimuli
StimServer.delete
clear procs