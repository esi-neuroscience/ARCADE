

%% setup eye tracking

trackeye('reset');
eventNames = trackeye([0 0], 50, 'fp');



%% stimulus

fp = Gaussian;



%% states

WaitForFix = State('WaitForFix');
WaitForFix.waitEvents = eventNames{1};
WaitForFix.nextStateAfterEvent = {'changeColor'};
WaitForFix.onEntry = {...
    @(x) set(fp, 'color', [255 255 255], 'visible', true), ...
    };

WaitForFix.duration = 10000;

changeColorOnFix = State('changeColor');
changeColorOnFix.waitEvents = eventNames{2};
changeColorOnFix.onEntry = {...
    @(x) set(fp, 'color', [0 0 0]), ...
    };
changeColorOnFix.nextStateAfterEvent = {'WaitForFix'};
changeColorOnFix.duration = 60000;



%%
createTrial('WaitForFix', WaitForFix, changeColorOnFix)
stateArc = SGLStateArc.launch();
stateArc.mRunTrial();