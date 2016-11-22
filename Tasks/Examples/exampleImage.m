





% timing 
trl.stimDuration  = randi([1900,2100],1); 
trl.itiDuration   = 500;


%% DEFINE AND CREATE STIMULI

% image 1
img1 =  [];
img1.imageFile = 'C:\Toolbox\ARCADE\Tasks\Examples\exampleImage1.bmp';
img1.position = [200 350];
img1.alpha = 128;
%img1.angle = 30;
IMG1 = createNewStimulus('Image', img1);

% image 2
img2 =  [];
img2.imageFile = 'C:\Toolbox\ARCADE\Tasks\Examples\exampleImage2.bmp';
img2.position = [300 350];
img2.alpha = 100;

IMG2 = createNewStimulus('Image', img2);

%% DEFINE AND CREATE TRIAL STATES

%# STIMULUS ON
sStimOn = [];
sStimOn.name      = 'stimOn';
sStimOn.duration  = trl.stimDuration;
sStimOn.nextState = 'cleanUp';
sStimOn.onEntry   = {...    
    {@() IMG1.visible(true)},...
    {@() IMG2.visible(true)},...
    }    
sStimOn.onExit    = {...
    {@() IMG1.visible(false)}, ...
    {@() IMG2.visible(false)}};


%# END OF TRIAL CLEANUP 
sCleanUp = [];
sCleanUp.name      = 'cleanUp';
sCleanUp.duration  = 0;
sCleanUp.nextState = 'iti';
sCleanUp.onEntry = {...    
    {@() IMG1.visible(false)},...
    {@() IMG2.visible(false)},...
    };
sCleanUp.onExit  = {...
    {@() IMG1.delete}, ...
    {@() IMG2.delete}, ...
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


