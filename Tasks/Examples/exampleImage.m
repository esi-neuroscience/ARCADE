



dbstop in exampleImage at 61

% timing 
trl.stimDuration  = randi([1900,2100],1); 
trl.itiDuration   = 500;


%% DEFINE AND CREATE STIMULI
TaskFolder = 'C:\Toolboxes\ARCADE\Tasks\Examples'; 
% image 1
img1 = Picture(fullfile(TaskFolder, 'exampleImage1.bmp'));
img1.position = [200 350];
img1.alpha = 128;


% image 2
img2 = Picture(fullfile(TaskFolder, 'exampleImage2.bmp'));
img2.position = [300 350];
img2.alpha = 100;



%% DEFINE AND CREATE TRIAL STATES

%# STIMULUS ON
sStimOn = [];
sStimOn.name      = 'stimOn';
sStimOn.duration  = trl.stimDuration;
sStimOn.nextState = 'cleanUp';
sStimOn.onEntry   = {...    
    {@() set(img1, 'visible', true)},...
    {@() set(img2, 'visible', true)},...
    };
sStimOn.onExit    = {...
    };


%# END OF TRIAL CLEANUP 
sCleanUp = [];
sCleanUp.name      = 'cleanUp';
sCleanUp.duration  = 0;
sCleanUp.nextState = 'iti';
sCleanUp.onEntry = {...    
    {@() set(img1, 'visible', false)},...
    {@() set(img2, 'visible', false)},...
    };
sCleanUp.onExit  = {...
    {@() delete([img1, img2])}, ...    
    };

%# ITI
sITI = [];
sITI.name      = 'iti';
sITI.duration  = trl.itiDuration;
sITI.nextState = 'final';


initialState = 'stimOn';
createTrial(initialState,...
    sStimOn,...
    sCleanUp, ...
    sITI);


