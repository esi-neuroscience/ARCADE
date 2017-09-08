
% initialize StimServer & set parameters
StimServer.Connect()

pauseTime = 1;
TESTFOLDER = fileparts(mfilename('fullpath'));
TESTFOLDER = 'C:\Toolboxes\ARCADE\arcade\Tests\Stimuli';


%% TEST: image 
img2 =  Picture(fullfile(TESTFOLDER, 'test.png'));
img2.position = [200 0];
img2.alpha = 200;
img2.angle = 200;

img =  Picture(fullfile(TESTFOLDER, 'test.png'));
img.position = [0 0];
img.alpha = 200;
img.angle = 45;


set([img, img2], 'visible', true)


% delete(img);


%% TEST: filled dot
dot = Circle(100);
dot.visible = true;
pause(pauseTime)
dot.position = [0 250];
pause(pauseTime)
dot.color = [0 0 0 255];
pause(pauseTime)
dot.diameter = 200;
pause(pauseTime)
dot.visible = false;
delete(dot)

%% TEST: masked grating
grat =  Grating;
grat.visible = true;
pause(pauseTime)
grat.position       = [400,-100];             % [x,y] position
pause(pauseTime)
grat.color1         = [ 0, 255, 0,150]; % [r,g,b,w] [0...255] color when sinewave is 0
pause(pauseTime)
grat.color2         = [255,0,0,150]; % [r,g,b,w] [0...255] color when sinewave is 1
pause(pauseTime)
grat.spatialFrequency = 100;                % [>=1] pixels per cycle of grating
pause(pauseTime)
grat.direction      = 90;                 % direction of movement (orthogonal to orientation)
pause(pauseTime)
grat.animationIncrement = 3;                 % each frame shift by N pixels
pause(pauseTime)
grat.animationIncrement = 0;                 % each frame shift by N pixels
pause(pauseTime)
grat.phaseShift     = 100;                 % grating degrees
pause(pauseTime)
grat.smoothing      = 10;                 % sinewave == 2, values greater tend to squarewave ~10
pause(pauseTime)
grat.maskWidth      = 100;
pause(pauseTime)
grat.maskHeight      = 500;
pause(pauseTime)
grat.maskRotation   = 57;                 % degrees
pause(pauseTime)
grat.visible = false;
delete(grat)


%% TEST: random dot pattern
% %           create defaults
% def =  [];
% def.position           = [0,0];     % [x,y] position             (signed floats)
% def.dotDiameter        = 10;         % pixels
% def.dotColor           = [255,255,255,255];
% def.dotPixelsPerFrame  = 3;         % velocity -> pixelsPerFrame (signed float)
% def.dotDirection       = 0;         % degrees                    (signed float)
% def.dotCoherence       = 1;       % value between [0,1]
% def.coherenceType      = 'angle';   % 'ratio','angle' [string]
% def.dotNumber          = 10;       %                   [must be an integer >0]
% def.maskType           = 'circle';  % 'square','circle' [string]
% def.maskDiameter       = 300;       % pixels            [must be an integer >0]

% rdpObject = createNewStimulus('RandomDots', def);
% rdpObject.visible(true)

% pause(pauseTime);
% rdpObject.setParameter('position', [100,0])
% pause(pauseTime)
% rdpObject.setParameter('dotDiameter', 40)
% pause(pauseTime);
% rdpObject.setParameter('dotColor', [0 255 0 128])
% pause(pauseTime);
% rdpObject.setParameter('dotDirection', 0)
% pause(pauseTime);

% rdpObject.delete();
% % BUG: dots appear on screen instead of flying into mask


%% TEST: static bar
rect = Rectangle;
rect.visible = true;
pause(pauseTime)
rect.position      = [0,0];             % [x,y] position
pause(pauseTime)
rect.width   = 500;
pause(pauseTime)
rect.height   = 3;
pause(pauseTime)
rect.angle   = 30;                 % degrees
pause(pauseTime)
rect.color         = [0,100,255]; % rgbw
pause(pauseTime)
rect.alpha = 128;
pause(pauseTime)
delete(rect)

%% TEST: moving bar
%           create defaults
rect =  MovingBar(100,200);
rect.visible = true;
pause(pauseTime)
rect.position      = [-100,250];       
pause(pauseTime)
rect.width   = 40;
pause(pauseTime)
rect.direction   = 90;            
pause(pauseTime)
rect.color         = [255,255,0]; 
pause(pauseTime)
rect.alpha         = 137;
pause(pauseTime)
rect.visible = false;
delete(rect)

%% cleanup
StimServer.delete()
