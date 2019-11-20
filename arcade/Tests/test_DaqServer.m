
% initialize DaqServer
cfg = ArcadeConfig;
cfg.EyeServer = [];
cfg.DaqServer = 'NidaqServer.exe';
cfg.ControlScreen = [];
cfg.StimServer = [];

procs = launch_processes(cfg);
assert(length(procs) == 1)


%% Test reward
logmessage('Give 80 ms reward')
reward(80)
pause(0.5)
logmessage('Give [200 100 200] reward pulse')
reward([200 100 200])
pause(1)
logmessage('Set manual reward code to 888')
DaqServer.SetRewardCode(888);
pause(1)
logmessage('Set manual reward duration to 1000')
DaqServer.SetRewardTime(1000)
pause(1)
logmessage('Trigger manual reward')
IPCEvent.set_event('Reward')
logmessage('Retreive total reward time')
assert(DaqServer.GetTotalRewardTime() == 1480)

%% Test eventmarker
logmessage('Send eventmarkers [22, 33, 4444]')
eventmarker(22)
eventmarker(33)
pause(0.2)
eventmarker(4444)

%% Test digital input
eventNames = {'testLineOn', 'testLineOff'};
logmessage('Track digital input line port2/line4')
trackdigitalinput(4, eventNames);
trackdigitalinput('start')
pause(1)
assert(IPCEvent.wait_for_event(eventNames{2}, 2000));
assert(~IPCEvent.wait_for_event(eventNames{1}, 2000));

%% Test disconnect
logmessage('Disconnect and exit DaqServer')
DaqServer.Disconnect
DaqServer.delete
clear all



