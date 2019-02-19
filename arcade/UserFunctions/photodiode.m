function photodiode(setmode)
%PHOTODIODE Set the mode of the photodiode stimulus
% 
% INPUT
% -----
% 	'on'     : turn photodiode stimulus white
%   'off'	 : turn photodiode stimulus black
% 	'toggle' : switch status of photodioe (i.e., on->off, or off->on)
% 	'flicker': flip between black and white with every frame
%
% For more information, see <a href="matlab:doc('arcade')">the ARCADE guide</a>.
%
% See also StimServer

switch setmode
    case 'toggle'
        StimServer.PDmode(2);
    case 'on'
        StimServer.PDmode(1)
    case 'off'
        StimServer.PDmode(0)
    case 'flicker'
        StimServer.PDmode(3)
end
       


end


