%% Available stimuli for ARCADE
% Stimuli are created in the task script using the |createNewStimulus|
% function. Possible stimuli are described here.
% 
%% Images
%%
%   imgDefinition =  [];
%   imgDefinition.imageFile = 'C:\ARCADE\Tasks\Examples\imageFile.bmp';
%   imgDefinition.position = [200 350]; % pixel from screen center
%   imgDefinition.alpha = 128; % 0-255
%   imgDefinition.angle = 30; % degree
%   IMG = createNewStimulus('Image', imgDefinition);
% 
% Possible image formats are BMP, PNG and JPEG. The position can be defined
% as an |[x y]| vector in pixels relative to the screen center. An alpha
% transparency level can be defined between 0 and 255 with 0 being fully
% transparent and 255 fully opaque. Transparency in PNGs is also supported.

%% Masked grating
def =  [];
def.position       = [0,0];             % [x,y] position (px)
def.color0         = [ 0, 255, 0,150];  % [r,g,b,w] [0...255] color when sinewave is 0
def.color1         = [255,0,0,150];     % [r,g,b,w] [0...255] color when sinewave is 1
def.pixelsPerCycle = 100;               % [>=1] pixels per cycle of grating
def.direction      = 90;                 % direction of movement (orthogonal to orientation)
def.pixelsPerFrame = 3;                 % each frame shift by N pixels
def.phaseShift     = 0;                 % grating degrees
def.smoothing      = 2;                 % sinewave == 2, values greater tend to squarewave ~10
def.maskRadii      = [200 100];               % circle mask [x,y] elliptical
def.maskRotation   = 0;                 % degrees

%     gratingObject = createNewStimulus('MaskedGrating', def);


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
