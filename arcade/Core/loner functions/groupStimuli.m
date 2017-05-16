function groupStimuli(setmode)
% Group changes to stimuli together.
% 
% INPUT
% -----
% 	mode :  'start' or 'end'
% 
% All changes made to stimuli following a groupStimuli('start') call
% will be applied simulataneously once groupStimuli('end') is called.
% 
% Example
% ------
% 
% 	r = Rectangle;
% 	set(r, 'visible', true)
% 	groupStimuli('start')
% 	set(r, 'angle', 45)
%   set(r, 'position', [-500 -300])
% 	groupStimuli('end')

switch lower(setmode)
    case 'start'
        StimServer.Defer(1); % begin deferred mode
    case 'end'
        StimServer.Defer(0); % end deferred mode
end

end

