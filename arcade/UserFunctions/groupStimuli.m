function groupStimuli(setmode)
%GROUPSTIMULI Group changes to stimuli together.
% 
% INPUT
% -----
% 	mode :  'start' or 'end'
% 
% All changes made to stimuli following a groupStimuli('start') call
% will be applied simulataneously once groupStimuli('end') is called.
% 
% EXAMPLE
% -------
% 
% 	r = Rectangle;
% 	set(r, 'visible', true)
% 	groupStimuli('start')
% 	set(r, 'angle', 45)
%   set(r, 'position', [-500 -300])
% 	groupStimuli('end')
%
% For more information, see <a href="matlab:doc('arcade')">the ARCADE guide</a>.
%
% See also StimServer


switch lower(setmode)
    case {'start', 'begin'}
        StimServer.Defer(1); % begin deferred mode
    case 'end'
        StimServer.Defer(0); % end deferred mode
end

end


