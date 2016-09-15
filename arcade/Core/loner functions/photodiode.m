function photodiode(setmode)
% 'toggle'
% 'on'
% 'off'
% 'flicker'

StimControl = SGLStimServerGeneral.launch;
switch setmode
    case 'toggle'
        StimControl.togglePD;
    case 'on'
        StimControl.setPDvalue(1);
    case 'off'
        StimControl.setPDvalue(0);
    case 'flicker'
        StimControl.flickerPD;
end



end

