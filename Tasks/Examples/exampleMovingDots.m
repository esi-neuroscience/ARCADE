





% timing 
trl.stimDuration  = randi([1900,2100],1); 
trl.itiDuration   = 500;

% write user variables to output file
storeUserVariables(trl);




%% DEFINE AND CREATE STIMULI

def =  [];
def.dotDiameter        = 10;            % pixels
def.dotColor           = [255,0,0,255];
def.dotDirection       = 45;            % degrees 
def.dotNumber          = 200;       
def.maskDiameter       = 300;           % pixels    
def.dotPixelsPerFrame  = 2;             % velocity -> pixelsPerFrame

if TrialData.currentCondition == 1
    def.position       = [350,0];     % [x,y] position        
else
    def.position       = [0,-350];    % [x,y] position  
end

% create the stimulus
DOTS = createNewStimulus('RandomDots', def);


%% DEFINE AND CREATE TRIAL STATES

%# STIMULUS ON
sStimOn = [];
sStimOn.name      = 'stimOn';
sStimOn.duration  = trl.stimDuration;
sStimOn.nextState = 'cleanUp';
sStimOn.onEntry   = {...
    {@() groupStimuli('begin')},...
    {@() DOTS.visible(true)},...
    {@() photodiode('on')},...
    {@() groupStimuli('end')}};
sStimOn.onExit    = {...
    {@() groupStimuli('begin')},...
    {@() photodiode('off')},...
    {@() DOTS.visible(false)},...
    {@() groupStimuli('end')}};


%# END OF TRIAL CLEANUP 
sCleanUp = [];
sCleanUp.name      = 'cleanUp';
sCleanUp.duration  = 0;
sCleanUp.nextState = 'iti';
sCleanUp.onEntry = {...
    {@() groupStimuli('begin')},...
    {@() DOTS.visible(false)},...
    {@() photodiode('off')},...
    {@() groupStimuli('end')}};
sCleanUp.onExit  = {...
    {@() DOTS.delete}};

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


