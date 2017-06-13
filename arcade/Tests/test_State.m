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
MultipleEvents.Init(eventNames);

s = State('testState');
s.waitEvents = eventNames;
s.nextStateAfterEvent = {'ns1', 'ns2', 'ns3'};
s.nextStateAfterTimeout = 'ignore';
s.waitForAllEvents = true;
s.duration = 60000;
s.maxRepetitions = 5;

ns = '';
while ~strcmp(ns, 'final') 
    ns = s.run()
end
