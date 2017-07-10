if TrialData.currentTrial == 1	
	trackdigitialinput(2, {'leverOn', 'leverOff'});
	trackdigitialinput('start')
end


%% stimulus

g = Gaussian;



%% states
waitForLever = State('waitForLever');
waitForLever.waitEvents = {'leverOn', 'SkipTrial'};
waitForLever.nextStateAfterEvent = {'colorChange', 'iti'};
waitForLever.nextStateAfterTimeout = 'ignored';
waitForLever.onEntry = {...
    @() set(g, 'color', [255 255 255], 'visible', true), ...
    };
waitForLever.duration = 5000;

colorChange = State('colorChange');
% colorChange.waitEvents = 'leverOff';
% colorChange.nextStateAfterEvent = 'waitForLever';
colorChange.nextStateAfterTimeout = 'iti';
colorChange.onEntry = {...
    @() set(g, 'color', [255 0 0]), ...
    @() reward(500), ...
    @() trialerror(1), ...
    };
colorChange.duration = 1000;


ignored = State('ignored');
ignored.onEntry = {...	
	@() trialerror(9), ...
	};
ignored.duration = 500;
ignored.nextStateAfterTimeout = 'iti';

iti = State('iti');
iti.duration = 500;
iti.onEntry = {...
    @() delete(g), ...
    @() drawnow(), ...
    }
iti.nextStateAfterTimeout = 'final'

createTrial('waitForLever', waitForLever, colorChange, ignored, iti)
