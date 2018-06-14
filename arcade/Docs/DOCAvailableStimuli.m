%% Visual stimuli for ARCADE
% Stimuli are created invisibly in the task script before the creation of the trial
% states. They can then be manipulated (made visible, moved, ...) in the
% |onEntry| and |onExit| functions of the trial states.
% Possible stimuli are described here. A stimulus is created by calling the
% stimulus type class and storing it in a variable, e.g.
% 
%   stim = MyStimulus;
% 
% |MyStimulus| is the type of stimulus, e.g. |Grating|, |Picture|, |Rectangle|, ...
% Stimulus properties can be then be changed in two ways. Either by directly
% setting the property, similar to changing fields of a struct array, e.g.
%
%   stim.property = 3.14;
%
% or by using the |set| command, similar to how figures and axes can be
% manipulated in MATLAB, e.g.,
%
%   set(stim, 'property', 3.14)
%
% Only the latter variant can be used in the |onEntry| and |onExit|
% functions of trial states. The former variant is useful for testing your
% stimuli. To see all properties of a stimulus, use
%   |properties('MyStimulus')|, e.g. |properties('Rectangle')|
%
% To ensure stable operation of ARCADE, all stimuli should be explicitly
% deleted at the end of a trial, e.g. in a |cleanUp| state by issuing
%
%   stim.delete()
% 
%
% *Testing stimuli*
% 
% All stimuli can be tested from any open MATLAB if ARCADE is in the
% MATLAB search path and |ARCADE/arcade/StimServer/StimServer.exe| is running.
% The first command in such a test environment has to be
%
%   StimServer.Connect()
% 
% This command is not necessary in the actual trial script.

%% General stimulus properties
% All stimuli share a few properties. All stimuli can be made visible, 
% repositioned, or animated (smoothly translated).
properties('Stimulus')
%%
% Visibility can be |true| for on or |false| for off. 
% Coordinates are usually in pixels. The stimulus |position| is always relative
% to the screen center. Angles are defined in degree with 0 being rightward
% (--) and 90 upward (|). 
% 
% Colors are always specified as 24-bit RGB values, e.g. [255 255 255] for
% white and [0 0 0] for black. Alpha values range from fully transparent
% (0) to fully opaque (255).
% 
% _Note_: For displays with an even number of pixels the center |[0 0]| is
% actually between the two center pixels. To achieve pixel-perfect display of
% stimuli you should add 0.5 to the coordinate. 

%% Circles
% Filled circles can be created as a |Circle|. Type 1 circles are filled, 
% type 2 circles are outlined circles (5 px width, currently not flexible).
properties('Circle')
%%
% *Example*
%
circ1 = Circle(1);
circ1.alpha = 200;
circ1.diameter = 400;
circ1.position = [0 0];
circ2 = Circle(2);
circ2.diameter = 50;
circ2.position = [20 100];
circ2.color = [128 0 255];
circ3 = Circle(1);
circ3.diameter = 300;
circ3.color = [0 180 255];
circ3.position = [275 49];
circ3.alpha = 100;
set([circ1, circ2, circ3], 'visible', true)
pause(1)
circ1.delete()
circ2.delete()
circ3.delete()

%%
%
% <<exampleCircle.png>>
%
% Detailed documentation can be found with <matlab:doc('Circle') doc Circle>

%% Pictures
% Possible Picture formats are BMP, PNG, TIFF and JPEG. The position can be defined
% as an |[x y]| vector in pixels relative to the screen center. An alpha
% transparency level can be defined between 0 and 255 with 0 being fully
% transparent and 255 fully opaque. Transparency in PNGs is also supported.
properties('Picture')
%%
% *Example*
%
imgPath = 'C:\Toolboxes\ARCADE\arcade\Docs';
img = Picture(fullfile(imgPath, 'image.png'));
img.position = [0 0];
img.alpha = 200;
img.angle = 45;

img2 = Picture(fullfile(imgPath, 'image.png'));
img2.position = [200 0];
img2.alpha = 200;
img2.angle = 200;
set([img, img2], 'visible', true)
pause(1)
img.delete()
img2.delete()

%%
%
% <<exampleImage.png>>
%
% Detailed documentation can be found with <matlab:doc('Picture') doc Picture>
%% Masked grating
% Gratings with a hard circular mask are implemented as |PixelShader| 
% (see below) stimuli with various parameters:
properties('Grating')
%%
% Spatial frequency is defined as |spatialFrequency| in pixel per cycle. 
% Temporal frequency is
% specified via the |temporalFrequency| property in units of cycles per
% s. The mask can be circular or elliptical (|maskWidth|, |maskHeight|), 
% and can be rotated (|maskRotation|). 
% The two colors of the grating are specfied as a vector of 8-bit values for
% |[red green blue alpha]|. The |smoothing| parameter is 2 for purely
% sinusoidal gratings. Values > 2 will approach a square wave grating.
%%
% *Example*
%
grat1 = Grating();
grat1.color1 = [255 0 0 200];
grat1.color2 = [0 255 0 200];
grat1.maskRotation = 45;
grat1.maskWidth = 400;
grat1.spatialFrequency = 60;
grat1.smoothing = 2;
grat1.temporalFrequency = 1;
grat1.visible = true;

grat2 = Grating();
grat2.color1 = [255 0 0 200];
grat2.color2 = [0 0 0 200];
grat2.maskRotation = 270;
grat2.maskWidth = 400;
grat2.spatialFrequency = 20;
grat2.smoothing = 10;
grat2.temporalFrequency = 1;
grat2.position = [400 0];
grat2.direction = 45;
grat2.visible = true;


pause(1);
grat1.delete();
grat2.delete();
%%
%
% <<exampleGrating.png>>
%
% Detailed documentation can be found with <matlab:doc('Grating') doc Grating>

%% Gabor
% Gabors are gratings with a Gaussian mask and also are implemented 
% as |PixelShader| (see below) stimuli with various
% parameters:
properties('Gabor')
%%
% Spatial frequency is defined via |spatialPeriod| in pixel per cycle
% (actually the inverse of the spatial frequency).
% Temporal frequency is specified via the |temporalFrequency| property in 
% units of cycles per s. 
% The gaussian mask can be circular or elliptical (|maskWidth|, |maskHeight|), 
% and can be rotated (|maskRotation|).  The two colors of the grating are 
% specfied as a vector of 8-bit values for |[red green blue ]|. The 
% |smoothing| parameter is 2 for purely can be used to achieve square-wave 
% instead of of sinusoidal gratings: values > 2 will approach a square wave grating.
%%
% *Example*
%
gabor1 = Gabor();
gabor1.color1 = [255 0 0];
gabor1.color2 = [0 255 0];
gabor1.maskRotation = 45;
gabor1.maskWidth = 50;
gabor1.spatialPeriod = 60;
gabor1.smoothing = 2;
gabor1.temporalFrequency = 1;
gabor1.visible = true;

gabor2 = Gabor();
gabor2.color1 = [255 0 0];
gabor2.color2 = [0 0 0];
gabor2.maskRotation = 50;
gabor2.maskWidth = 20;
gabor2.spatialPeriod = 20;
gabor2.smoothing = 10;
gabor2.temporalFrequency = 1;
gabor2.position = [400 0];
gabor2.direction = 45;
gabor2.visible = true;


pause(1);
gabor1.delete();
gabor2.delete();
%%
%
% <<exampleGabor.png>>
%
% Detailed documentation can be found with <matlab:doc('Gabor') doc Gabor>


%% Rectangles
% Rectangles are always filled and have the following properties:
properties('Rectangle')
%%
% *Example*
%
r1 = Rectangle;
r1.color = [128 0 255];
r1.height = 200;
r1.angle = 45;
r1.alpha = 100;
r1.visible = true;

r2 = Rectangle;
r2.color = [128 255 255];
r2.height = 200;
r2.angle = 180;
r2.alpha = 100;
r2.visible = true;
pause(1)
r1.delete();
r2.delete();
%%
%
% <<exampleRectangle.png>>
%
% Detailed documentation can be found with <matlab:doc('Rectangle') doc Rectangle>

%% Animations
% ARCADE allows several kinds of animations. All stimulus types can be 
% smoothly translated around on the screen. To animate a
% stimulus, an animation has to be created first and then assigned to a
% stimulus by using the |play_animation| method of a stimulus.
% 
% Currently there are five types of animation
% 
% # |LinearMotion|: Move a stimulus along a polygon.
% # |GeneralMotion|: This moves the stimulus along an arbitrary path
% defined in a file. *NOT FULLY TESTED YET*
% # |LinearRange|: Change certain scalar stimulus properties linearily from a
% starting value to an end value within a specified duration 
% # |Flash|: Flash (turn on) a stimulus for a defined number of frames
% # |ExternalPositionControl|: Couple the position of a stimulus to a
% position in a shared memory, e.g. the eye position.
% 
% To start an animation is has to be passed to the |play_animation| method
% of a stimulus. 
% Animations start immediatly when the stimulus is visible or when it
% becomes visible. An animation can be stopped by using the
% |stop_animation| method of the animated stimulus.
% 
% When an animation ends several actions can be triggered, which is
% controlled via the |terminalAction| property of the animation.
help Animation.terminalAction

%%
% To keep the stimulus presentation and the experimental |State| in sync,
% it is *strongly recommended* to set the 4th bit of the |terminalAction| property
% such that the |StimServerAnimationDone| event is triggered. Otherwise the
% next state might already start before the animation is finished.

%%
% *Example*
r = Rectangle;
r.color = [255 255 255];
r.height = 200;
r.angle = 45;

pause(1)
vertices = [0 0 100 0 500 500]; % [x1 y2 x2 y2 x3 y3]
speed = 150; % px/s
a = LinearMotion(speed, vertices);
r.play_animation(a);
r.visible = true;
%%
%
% <<exampleAnimation.png>>
%
% Detailed documentation can be found with <matlab:doc('LinearMotion') doc LinearMotion>

%% Moving Bars
% The |MovingBar| class simplifies the creation of animated bars by
% automatically creating the animation. 
properties('MovingBar')
%%
% Only the |startPosition|, |direction| and |travelDistance| have to bet set.
% If |linkedOrientationDirection| is set, the bar will always be
% orthogonal to the travel direction. To start the sweep animation of the
% |MovingBar| use the |play_animation| method without arguments.
%%
% *Example*
speed = 200;
travelDistance = 500;
mb = MovingBar(speed, travelDistance);
mb.direction = 35;
mb.play_animation()
pause(5)
mb.delete()

%% Gammatron (annular grating)
% The |Gammatron| class creates an annular grating pattern with based on
% two colors that can be drifting inward or outward.
properties('Gammatron')
%%
% *Example*
g = Gammatron;
g.radius = 200;
g.visible = true;
%%
%
% <<exampleGammatron.png>>
%% Gaussian
% A 2D patch with Gaussian profile can be created using the |Gaussian|
% stimulus. Its size, rotation and color can be set:
properties('Gaussian');
%% 
% *Example*
g1 = Gaussian;
g1.sdx = 100;
g1.angle = 45;
g1.color = [128 255 0];
g1.position = [100 50];
g2 = Gaussian;
g2.sdx = 100;
g2.sdy = 100;
g3 = Gaussian;
g3.color = [0 0 0];
set([g1, g2, g3], 'visible', true);
%%
%
% <<exampleGaussian.png>>

%% Petal
% A petal-like shape based on two circles connected by Bezier curves 
% can be created using the |Petal| stimulus. 
properties('Petal');
%% 
% *Example*
p = Petal;
p.angle = 35;
p.faceColor = [255 255 255 128];
p.lineColor = [255 0 0 255];
p.drawMode = 3; % 1=face only, 2=line only, 3=both
p.visible = true;

%%
%
% <<examplePetal.png>>




%% Pixel shader
% Pixel shader are small programs that run on the graphics card and are 
% written in a specific shader language, HLSL  (see 
% <https://msdn.microsoft.com/en-us/library/windows/desktop/bb509561(v=vs.85).aspx here>
% for more information). Using HLSL any stimulus that 
% can be parameterized based on pixel location and time
% may be generated and rendered with high performance.
% 
% Programming in HLSL is not trivial, but offers great flexibility. As a
% starting point you may have a look at the gratings presented above.
% They are implemented in the file
% |ARCADE\arcade\StimServer\classes\stimfiles\pixelShader\MaskedGrating.fx|,
% which is loaded and controlled by the |PixelShader| class with the
% following properties and methods
properties('PixelShader')
%%
% Pixel shaders can currently use up to 4 RGB-Alpha colors and 12
% parameters that are passed to the shader using the |setColor| and
% |setParameter| methods.
% Detailed documentation can be found with <matlab:doc('PixelShader') doc PixelShader>









