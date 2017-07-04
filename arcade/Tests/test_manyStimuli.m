


nStimuli = 200;
stim = @Grating;
stimuli = cell(1,nStimuli);
for iStimulus = 1:nStimuli
	stimuli{iStimulus} = stim();
	stimuli{iStimulus}.position = round([rand()*1600-1680/2 rand()*1050-1050/2]);
	stimuli{iStimulus}.direction = round(rand()*360);
	stimuli{iStimulus}.color1 = [randi(255) randi(255) randi(255) 128];
	stimuli{iStimulus}.spatialFrequency = 10+rand()*200;
	stimuli{iStimulus}.temporalFrequency = rand()*5+0.1;
    stimuli{iStimulus}.maskWidth = randi(300)+20;
    stimuli{iStimulus}.maskHeight = stimuli{iStimulus}.maskWidth;
    stimuli{iStimulus}.smoothing = 8*rand()+2;
end

% allStimuliVisible(true);
%%
stimuliOn = State('stimuliOn');
stimuliOn.duration = 30000;
stimuliOn.onEntry = {...
	@() set([stimuli{:}], 'visible', true)
};
stimuliOn.onExit = {...
	@() set([stimuli{:}], 'visible', false)
};

createTrial('stimuliOn', stimuliOn)