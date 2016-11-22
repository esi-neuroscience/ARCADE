function [screenX, screenY] = quad_coordinates(quadX,quadY,quadrant)
% Transform coordinates from quadrant space into screen space
%
% In the QUAD4X mode of the ProPIXX stimuli can be placed within
% a quadrant of size 960 x 540 pixels. This function transforms
% coordinates from that space and the quadrant number into screen
% (1920 x 1080) coordinates.
%
% Quadrant order is
% 		1 | 2
% 		-----
% 		3 | 4
%
% INPUT
% -----
% 	quadX : x-coordinate in quadrant space (0-960)
% 	quadY : y-coordinate in quadrant space (0-540)
% 	quadrant : index of quadrant for stimulus position (1-4)
%
% OUTPUT
% ------
% 	screenX : x-coordinate in screen space
% 	screenY : y-coordinate in screen space


fullSizeX = 1920;
fullSizeY = 1080;
quadrantSizeX = fullSizeX/2;
quadrantSizeY = fullSizeY/2;

quadrantCenterX = quadrantSizeX/2 * [-1 1 -1 1];
quadrantCenterY = quadrantSizeY/2 * [1 1 -1 -1];    

screenX = quadX - quadrantCenterX(quadrant);
screenY = quadY - quadrantCenterY(quadrant);
