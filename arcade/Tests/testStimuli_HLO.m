
pauseTime = 1;
%% initialize StimServer
StimServer = SGLStimServer.launch;
StimServerGeneral = SGLStimServerGeneral.launch;

%%
ARCADEFOLDER = 'C:\Toolbox\ARCADE\arcade';
TESTFOLDER = fullfile(ARCADEFOLDER, 'Tests');
LEFTEYE = [1 3];
RIGHTEYE = [2 4];
BOTHEYES = 1:4;

%% image on
img =  [];
img.imageFile = fullfile(TESTFOLDER, 'test.png');
img.position = [0 0];
img.alpha = 200;
% img.angle = 200;
imageObject = createNewStimulus('Image', img);

imageObject.visible(true);
pause(pauseTime)
imageObject.setParameter('alpha', 100);
pause(pauseTime)
imageObject.setParameter('angle', 30);

%% image off
imageObject.visible(false);
imageObject.delete();

%% quad4x image on
imgLeft =  [];
imgLeft.imageFile =  fullfile(TESTFOLDER, 'test.bmp');
imgLeft.position = [0 0];

imgRight =  [];
imgRight.imageFile =  fullfile(TESTFOLDER, 'test2.bmp');
imgRight.position = [0 0];

quadObjectsLeft = createNewQuad4XStimulus('Image', imgLeft, LEFTEYE);
quadObjectsRight = createNewQuad4XStimulus('Image', imgRight, RIGHTEYE);

arrayfun(@(x) x.visible(true), quadObjectsLeft);
arrayfun(@(x) x.visible(true), quadObjectsRight);

%% quad4x image off
arrayfun(@(x) x.visible(false), [quadObjectsLeft quadObjectsRight]);
arrayfun(@(x) x.delete, [quadObjectsLeft quadObjectsRight]);


%% filled dot on
dot = [];
dot.position = [0 250];
dot.color = [0 0 0 255];
dot.diameter = 100;
dotObject = createNewStimulus('FilledDot', dot);
dotObject.visible(true)

pause(pauseTime)
dotObject.setParameter('diameter', 150);
pause(pauseTime)
dotObject.setParameter('position', [300 -100]);

%% filled dot off
dotObject.visible(false)
dotObject.delete()

%% masked grating on
def =  [];
def.position       = [0,0];             % [x,y] position
def.color0         = [ 0, 255, 0,150]; % [r,g,b,w] [0...255] color when sinewave is 0
def.color1         = [255,0,0,150]; % [r,g,b,w] [0...255] color when sinewave is 1
def.pixelsPerCycle = 100;                % [>=1] pixels per cycle of grating
def.direction      = 90;                 % direction of movement (orthogonal to orientation)
def.pixelsPerFrame = 3;                 % each frame shift by N pixels
def.phaseShift     = 0;                 % grating degrees
def.smoothing      = 2;                 % sinewave == 2, values greater tend to squarewave ~10
def.maskRadii      = [200 200];               % circle mask [x,y] elliptical
def.maskRotation   = 0;                 % degrees

gratingObject = createNewStimulus('MaskedGrating', def);
gratingObject.visible(true)


pause(pauseTime)
gratingObject.setParameter('color0', [0,0,0,255])
pause(pauseTime)
gratingObject.setParameter('color1', [255,255,255,255])
pause(pauseTime)
gratingObject.setParameter('pixelsPerCycle', 200)
pause(pauseTime)
gratingObject.setParameter('direction', 90)
pause(pauseTime)
gratingObject.setParameter('pixelsPerFrame', 0)
pause(pauseTime)
gratingObject.setParameter('phaseShift', 90)
pause(pauseTime)
gratingObject.setParameter('smoothing', 2);
pause(pauseTime)
gratingObject.setParameter('maskRotation', 45);
pause(pauseTime)
gratingObject.setParameter('maskRadii', [500 200]);


%% masked grating off
gratingObject.visible(false);
gratingObject.delete();


%% masked grating with QUAD4X
% system(fullfile(ARCADEFOLDER, 'External', 'ProPIXX', 'enable_quadx.bat'))
def =  [];
def.position       = [0,0];             % [x,y] position
def.color0         = [0, 0, 0,255]; % [r,g,b,w] [0...255] color when sinewave is 0
def.color1         = [255,255,255,255]; % [r,g,b,w] [0...255] color when sinewave is 1
def.pixelsPerCycle = 100;                % [>=1] pixels per cycle of grating
def.direction      = 0;                 % direction of movement (orthogonal to orientation)
def.pixelsPerFrame = 3;                 % each frame shift by N pixels
def.phaseShift     = 0;                 % grating degrees
def.smoothing      = 2;                 % sinewave == 2, values greater tend to squarewave ~10
def.maskRadii      = [200 200];               % circle mask [x,y] elliptical
def.maskRotation   = 0;

defLeft = def;
defRight = def;
defRight.direction = 180;

quadObjectsLeft = createNewQuad4XStimulus('MaskedGrating', defLeft, LEFTEYE);
quadObjectsRight = createNewQuad4XStimulus('MaskedGrating', defRight, RIGHTEYE);

% fixation point
dot = [];
dot.position = [0 0];
dot.color = [128 0 0 255];
dot.diameter = 10;
dotObject = createNewQuad4XStimulus('FilledDot', dot, BOTHEYES);

% turn on stimuli
arrayfun(@(x) x.visible(true), quadObjectsLeft);
arrayfun(@(x) x.visible(true), quadObjectsRight);
arrayfun(@(x) x.visible(true), dotObject);

%% quad4x gratings off
arrayfun(@(x) x.visible(false), [quadObjectsLeft quadObjectsRight]);
arrayfun(@(x) x.delete, [quadObjectsLeft quadObjectsRight]);
arrayfun(@(x) x.delete, dotObject);


%% random dots
%           create defaults
def =  [];
def.position           = [0,0];     % [x,y] position             (signed floats)
def.dotDiameter        = 10;         % pixels
def.dotColor           = [255,255,255,255];
def.dotPixelsPerFrame  = -1;         % velocity -> pixelsPerFrame (signed float)
def.dotDirection       = 0;         % degrees                    (signed float)
def.dotCoherence       = 1;       % value between [0,1]
def.coherenceType      = 'angle';   % 'ratio','angle' [string]
def.dotNumber          = 10;       %                   [must be an integer >0]
def.maskType           = 'circle';  % 'square','circle' [string]
def.maskDiameter       = 10000;       % pixels            [must be an integer >0]

rdpObject = createNewStimulus('RandomDots', def);
rdpObject.visible(true)

pause(pauseTime);
rdpObject.setParameter('position', [100,0])
pause(pauseTime)
rdpObject.setParameter('dotDiameter', 40)
pause(pauseTime);
rdpObject.setParameter('dotColor', [0 255 0 128])
pause(pauseTime);
rdpObject.setParameter('dotCoherence', 1)
pause(pauseTime);
rdpObject.setParameter('dotDirection', 0)
pause(pauseTime);

rdpObject.delete();
% There seems to be a bug here. Dots appear on screen instead of flying in


%% static bar
def =  [];
def.position      = [0,0];             % [x,y] position
def.widthHeight   = [500,21];           % pixels >=1
def.orientation   = 30;                 % degrees
def.color         = [255,255,255,255]; % rgbw
barObject = createNewStimulus('StaticBar', def);

barObject.visible(true);
pause(pauseTime);
barObject.setParameter('position', [500,0])
pause(pauseTime);
barObject.setParameter('orientation', 90)
pause(pauseTime);
barObject.setParameter('color', [128 0 0 199])
pause(pauseTime);
barObject.setParameter('widthHeight', [128 2])


