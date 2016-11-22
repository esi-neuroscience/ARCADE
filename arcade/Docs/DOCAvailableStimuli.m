%% Available stimuli for ARCADE
% 
%% Images
%%
%   imgDefinition =  [];
%   imgDefinition.imageFile = 'C:\ARCADE\Tasks\Examples\imageFile.bmp';
%   imgDefinition.position = [200 350]; % pixel
%   imgDefinition.alpha = 128; % 0-255
%   imgDefinition.angle = 30; % degree
%   IMG = createNewStimulus('Image', imgDefinition);
% 
% Possible image formats are BMP, PNG and JPEG. The position can be defined
% as an |[x y]| vector in pixels relative to the screen center. An alpha
% transparency level can be defined between 0 and 255 with 0 being fully
% transparent and 255 fully opaque. Transparency in PNGs is also supported.

%% Masked grating

%% Random dot patterns
%%
%   def =  [];
%   def.dotDiameter        = 10;            % pixels
%   def.dotColor           = [255,0,0,255]; % [R G B alpha]
%   def.dotDirection       = 45;            % degrees 
%   def.dotNumber          = 200;       
%   def.maskDiameter       = 300;           % pixels    
%   def.dotPixelsPerFrame  = 2;             % velocity -> pixelsPerFrame
%   def.position           = [350,0];     % [x,y] position        
%   DOTS = createNewStimulus('RandomDots', def);
