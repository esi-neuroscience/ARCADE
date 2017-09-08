
% timing 
trl.stimDuration  = randi([1900,2100],1); 
trl.itiDuration   = 500;


%% DEFINE AND CREATE STIMULI
TaskFolder = fileparts(mfilename('fullpath'));
% image 1
img1 = Picture(fullfile(TaskFolder, 'exampleImage1.bmp'));
img1.position = [200 350];
img1.alpha = 128;


% image 2
img2 = Picture(fullfile(TaskFolder, 'exampleImage2.bmp'));
img2.position = [300 350];
img2.alpha = 100;


%% DEFINE AND CREATE TRIAL STATES

% STIMULUS ON
sStimOn = State('stimOn');
sStimOn.duration  = trl.stimDuration;
sStimOn.nextStateAfterTimeout = 'cleanUp';
sStimOn.onEntry   = {...    
    @() set([img1, img2], 'visible', true),...    
    };


% END OF TRIAL CLEANUP 
sCleanUp = State('cleanUp');
sCleanUp.duration  = 0;
sCleanUp.nextStateAfterTimeout = 'iti';
sCleanUp.onEntry = {...    
    @() set([img1, img2], 'visible', false),...    
    };
sCleanUp.onExit  = {...
    @() delete([img1, img2]), ...    
    };

% ITI
sITI = State('iti');
sITI.duration  = trl.itiDuration;
sITI.nextStateAfterTimeout = 'final';

initialState = 'stimOn';
createTrial(initialState,...
    sStimOn,...
    sCleanUp, ...
    sITI);


