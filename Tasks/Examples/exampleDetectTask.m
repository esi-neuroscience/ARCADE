

%% CONDITIONS
targetPositions = [
    250 300;
    -200 300;
    0 500;
    0 -500
    ];

%% EYE TRACKING
fixRadius = 50; % px
targetRadius = 300;
trackeye('reset')
fixEvents = trackeye([0 0], fixRadius, 'fix');
targetEvents = trackeye(targetPositions(TrialData.currentCondition,:), ...
    targetRadius, 'target');

%% STIMULI
[TaskFolder,~] = fileparts(mfilename('fullpath'));

% fixation point
fp = Circle;
fp.diameter = 5;
fp.position = [0 0];

% target
target = Circle;
target.diameter = 20;
target.color = [0 255 0];
target.alpha = 100;
target.position = targetPositions(TrialData.currentCondition,:);

%% STATES
acqFix = State('acqFix');
acqFix.duration = 5000;
acqFix.nextStateAfterTimeout = 'noFix';
acqFix.waitEvents = fixEvents{1};
acqFix.nextStateAfterEvent = 'holdFix';
acqFix.onEntry = {...
    @(x) eventmarker(1), ...
    @(x) set(fp, 'visible', true), ...
    };

holdFix = State('holdFix');
holdFix.duration = 1000;
holdFix.waitEvents = fixEvents{2};
holdFix.nextStateAfterEvent = 'breakFix';
holdFix.nextStateAfterTimeout = 'targetOn';
holdFix.onEntry = {...
    @(x) eventmarker(2), ...
    };

targetOn = State('targetOn');
targetOn.duration = 0;
targetOn.onEntry = {...
    @() eventmarker(3), ...
    @() groupStimuli('start'), ...
    @() set(target, 'visible', true), ...
    @() set(fp, 'visible', false), ...
    @() photodiode('on'), ...
    @() groupStimuli('end'), ...
    };
targetOn.nextStateAfterTimeout = 'waitForResponse';

waitForResponse = State('waitForResponse');
waitForResponse.duration = 5000;
waitForResponse.nextStateAfterTimeout = 'noResponse';
waitForResponse.waitEvents = targetEvents{1};
waitForResponse.nextStateAfterEvent = 'correct';

correct = State('correct');
correct.duration = 0;
correct.nextStateAfterTimeout = 'cleanUp';
correct.onEntry = {...
    @() set(target, 'visible', false), ...
    @() eventmarker(4), ...
    @() trialerror(1), ...
    @() reward('pulse', 100), ...
    };

noFix = State('noFix');
noFix.duration = 0;
noFix.onEntry = {...
    @() eventmarker(9), ...
    @() trialerror(9), ...
    };
noFix.nextStateAfterTimeout = 'cleanUp';


breakFix = State('breakFix');
breakFix.duration = 0;
breakFix.onEntry = {...
    @() eventmarker(5), ...
    @() trialerror(3), ...
    };
breakFix.nextStateAfterTimeout = 'cleanUp';


noResponse = State('noResponse');
noResponse.duration = 0;
noResponse.onEntry = {...
    @() eventmarker(6), ...
    @() trialerror(4), ...
    };
noResponse.nextStateAfterTimeout = 'cleanUp';


cleanUp = State('cleanUp');
cleanUp.onEntry = {...
    @() delete(fp), ...
    @() delete(target), ...
    @() photodiode('off')
    };
cleanUp.nextStateAfterTimeout = 'final';

%% create trial from states
createTrial('acqFix', ... % initial state
    acqFix, holdFix, targetOn, waitForResponse, correct, ...
    noFix, breakFix, noResponse, cleanUp);

