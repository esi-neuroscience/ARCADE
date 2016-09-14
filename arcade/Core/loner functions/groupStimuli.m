function groupStimuli(setmode)

% setmode 'begin', 'end'
StimControl = SGLStimServerGeneral.launch;
switch lower(setmode)
    case 'begin'
        StimControl.defer(1); % begin deferred mode
    case 'end'
        StimControl.defer(0); % end deferred mode
end

end

