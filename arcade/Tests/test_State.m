testEvent1 = IPCEvent('test1');
testEvent1.CreateEvent();
testEvent2 = IPCEvent('test2');
testEvent2.CreateEvent();
testEvent3 = IPCEvent('test3');
testEvent3.CreateEvent();


%%
testEvent1.trigger()


%%
clear classes
eventNames = {'test1', 'test2', 'test3'};


stimOn = State('stimOn');
stimOn.waitEvents = eventNames;
stimOn.nextStateAfterEvent = {'cleanUp','cleanUp','cleanUp'};
stimOn.nextStateAfterTimeout = 'ignore';
stimOn.waitForAllEvents = false;
stimOn.duration = 1000;
stimOn.maxRepetitions = 10;
stimOn.onEntry = {@(x) disp('stimOn')};

ignore = State('ignore');
ignore.nextStateAfterTimeout = 'stimOn';
ignore.duration = 1000;
ignore.onEntry = {@(x) disp('Ignored')};

cleanUp = State('cleanUp');
cleanUp.duration = 1000;
cleanUp.nextStateAfterTimeout = 'stimOn';
cleanUp.onEntry = {@(x) disp('cleanUp')};



%%
stateArc = SGLStateArc.launch;
stateArc.initialState = 'stimOn';
stateArc.states = [stimOn ignore cleanUp ];
stateArc.mRunTrial()