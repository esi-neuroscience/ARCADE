

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
def.maskRadii      = [200 100];               % circle mask [x,y] elliptical
def.maskRotation   = 0;                 % degrees

gratingObject = createNewStimulus('MaskedGrating', def);
gratingObject.visible(true)

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
def.dotPixelsPerFrame  = 5;         % velocity -> pixelsPerFrame (signed float)
def.dotDirection       = 180;         % degrees                    (signed float)
def.dotCoherence       = 0;       % value between [0,1]
def.coherenceType      = 'angle';   % 'ratio','angle' [string]
def.dotNumber          = 100;       %                   [must be an integer >0]
def.maskType           = 'circle';  % 'square','circle' [string]
def.maskDiameter       = 500;       % pixels            [must be an integer >0]

rdpObject = createNewStimulus('RandomDots', def);
rdpObject.visible(true)



