function allStimuliClear


% provides access to general StimServer functions
StimControl = SGLStimServerGeneral.launch;   
StimControl.showAll(false);
StimControl.removeAll;


end

