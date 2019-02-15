function backgroundColor(rgb)
%BACKGROUNDCOLOR Change background color of StimServer
%
% INPUT
% -----
% 	rgb : 3-element vector with color defined in 24-bit RGB space, e.g. [255
% 		   255 255] for white
%
% For more information, see <a href="matlab:doc('arcade')">the ARCADE guide</a>.
%
% See also StimServer
StimServer.SetBackgroundColor(rgb);

end


