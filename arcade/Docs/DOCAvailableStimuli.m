%% Visual stimuli for ARCADE
% Stimuli are created invisibly in the task script before the creation of the trial 
% states. They can then be manipulated (made visible, moved, ...) in the
% |onEntry| and |onExit| functions of the states.
% Possible stimuli are described here.
% 
% All stimuli can be tested from any open MATLAB if ARCADE is in the 
% MATLAB search path and |ARCADE/arcade/StimServer/StimServer.exe| is running.
% The first command in such a test environment has to be
% 
%   StimServer.Connect()
% 
% Properties of stimuli can be changed in two ways. Either by directly
% setting the property, similar to changing fields of a struct array, e.g.
%
%   stim = MyStimulus;
%   stim.property = 3.14;
% 
% or by using the |set| command, similar to how figures and axes can be
% manipulated in MATLAB, e.g.,
% 
%   stim = MyStimulus;
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

%% General stimulus properties
% All stimuli share a few properties. They can be made visible, repositioned, 
% protected from clearing or animated (smoothly translated)
properties('Stimulus')


%% Circles
% Filled circles can be created as a |Symbol| of type 1. Further symbols 
% will be added in the future. Type 2 symbols are outlined circles.
properties('Symbol')
%%
% *Example*
% 
%   symbolType = 1;
%   circ = Symbol(diameter, symbolType);
%   set(circ, 'visible', true)

%% Images
properties('Image')
%%
%   img = Image('C:\Toolbox\ARCADE\Tasks\Examples\imageFile.bmp')
%   img.position = [200 350]; % pixel from screen center
%   img.alpha = 128; % 0-255
%   img.angle = 30; % degree
% 
% Possible image formats are BMP, PNG and JPEG. The position can be defined
% as an |[x y]| vector in pixels relative to the screen center. An alpha
% transparency level can be defined between 0 and 255 with 0 being fully
% transparent and 255 fully opaque. Transparency in PNGs is also supported.

%% Masked grating
properties('Grating')

%% Rectnalges
properties('Rectangle')
%%
%   r = Rectangle;
%   r.color = [128 0 255];


%% Moving

%% Example stimulus test script
StimServer.Connect();
grat = Grating;
grat.visible = true;
pause(1);
circ = Symbol(200, 1);
circ.alpha = 128;
circ.visible = true;

%% Animations




