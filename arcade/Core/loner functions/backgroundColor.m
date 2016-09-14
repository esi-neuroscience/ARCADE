function backgroundColor(rgb)

% provides access to general StimServer functions
StimControl = SGLStimServerGeneral.launch;    
StimControl.background(rgb(1:3));

end

