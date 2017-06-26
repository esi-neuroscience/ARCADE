
trl.posTarget1 = [-300 -300];
trl.posTarget2 = [+300 +300];


%% setup eye tracking
trackeye('reset');
fpEvents = trackeye([0 0], 50, 'fp');
target1Events = trackeye(trl.posTarget1, 50, 'target1');
target2Events = trackeye(trl.posTarget2, 50, 'target2');

%% stimulus

fp = Gaussian;
target1 = Gaussian;
target1.position = trl.posTarget1;
target1.color = [0 0 128];
target2 = Gaussian;
target2.position = trl.posTarget2;
target2.color = [128 0 0];



%% states
waitForFix = State('waitForFix');
waitForFix.waitEvents = fpEvents{1};
waitForFix.nextStateAfterEvent = 'chooseStim';
waitForFix.nextStateAfterTimeout = 'ignored';
waitForFix.onEntry = {...
    @() set(fp, 'color', [255 255 255], 'visible', true), ...
    };
waitForFix.duration = 10000;


chooseStim = State('chooseStim');
chooseStim.waitEvents = {target1Events{1}, target2Events{1}};
chooseStim.duration = 10000;
chooseStim.nextStateAfterEvent = {'choseTarget1', 'choseTarget2'};
chooseStim.nextStateAfterTimeout = 'ignored';
chooseStim.onEntry = {...
	@() groupStimuli('start'), ...
	@() set(fp, 'visible', false), ...
	@() set([target1 target2], 'visible', true), ...
	@() groupStimuli('end'), ...
};

choseTarget1 = State('choseTarget1');
choseTarget1.onEntry = {...
	@() set(target2, 'visible', false), ...
	@() set(target1, 'color', [0 0 255]), ...
	@() trialerror(1), ...
	};
choseTarget1.duration = 500;
choseTarget1.nextStateAfterTimeout = 'final';

choseTarget2 = State('choseTarget2');
choseTarget2.onEntry = {...
	@() set(target1, 'visible', false), ...
	@() set(target2, 'color', [255 0 0]), ...
	@() trialerror(2), ...
	};
choseTarget2.duration = 500;
choseTarget2.nextStateAfterTimeout = 'final';

ignored = State('ignored');
ignored.onEntry = {...	
	@() trialerror(9), ...
	};
ignored.duration = 500;
ignored.nextStateAfterTimeout = 'final';

%%

createTrial('waitForFix', waitForFix, chooseStim, choseTarget1, choseTarget2, ignored)
