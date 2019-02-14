%% Running ARCADE


%% Starting ARCADE
% ARCADE can be launched via the executable bat file 
% |arcade/start_arcade.bat| or by directly calling the
% |<matlab:doc('runCore') arcade/Core/runCore>| function from a running MATLAB.
%
help runCore

%%
% All possible configuration options can be found in the 
% |<matlab:doc('ArcadeConfig') ArcadeConfig>| class (see |help
% ArcadeConfig|).  A configuration can be created by  
% 
% # starting ARCADE via |start_arcade.bat| and using the configuration GUI
% (MainScreen)
% # using the ArcadeConfig class and saving the result to a file
% 

%% Configuring ARCADE via the Configuration GUI (MainScreen)
% The configuration GUI provides an easy way to configure an experimental
% session by graphically selecting files, colors, and parameters.
% Clicking the run button will launch a session with the selected
% parameters. This configuration will be saved as a .mat file both in the
% folder with the task script as well as with the behavioral data in the
% |ARCADE/sessionLog/<session>/Backup| folder. It can then later be used
% for running a session with the same parameters without launching the 
% configuration GUI. 
%

%%
% <<MainScreen.png>>

%% Configuring ARCADE on the command line 
% Alternatively, the configuration can be created in the Command Window of
% MATLAB. See the example below.

cfg = ArcadeConfig;
cfg.Subject = 'cat11';
cfg.Experiment = 'detect-task';
cfg.taskFile = 'C:\Toolboxes\ARCADE\Tasks\Examples\exampleDetectTask.m';
cfg.Experimenter = 'Erwin Schrodinger';
cfg.Session = '1';
cfg.TrialErrorLegend = {'0', ... % 0
    'Correct', ... % 1 
    'NoResponse', ... % 2 
    'NoFixation', ... % 3
    'BreakFixation', ... % 4
    [], ... % 5
    [], ... % 6
    [], ... ^ 7
    [], ... % 8
    [], ... % 9     
    };
cfg.EyeServer = 'EyeLinkServer.exe';
cfg.DaqServer = 'NiDaqServer.exe';

cfg.save('C:\Toolboxes\ARCADE\Tasks\Examples\cat_detect_cfg.mat')

%%
% The path to the resulting .mat file can then be used as an argument for
% |start_arcade.bat| or |runCore| 
%
%    start_arcade.bat "C:\Toolboxes\ARCADE\Tasks\Examples\cat_detect_cfg.mat"
%
%    runCore('C:\Toolboxes\ARCADE\Tasks\Examples\cat_detect_cfg.mat')
%

%% Running a session
% An experimental session starts with ARCADE launching all the configured
% subprocesses (EyeServer, StimServer, ControlScreen, DaqServer) and 
% initializing their connections. 
%
% This usually entails launching the |ControlScreen|, which provides a GUI
% displaying behavioral data and the current eye position. If the
% EyeLinkServer is used for eye monitoring, an additional GUI will be
% visible that shows the current eye position and the currently monitored
% screen locations.

%%
% <<ControlScreen.png>>

