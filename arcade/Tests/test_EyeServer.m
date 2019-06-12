% initialize EyeServer
cfg = ArcadeConfig;
cfg.EyeServer = 'EyeLinkServer.exe';
cfg.DaqServer = [];
cfg.ControlScreen = [];
cfg.StimServer = [];

procs = launch_processes(cfg);
assert(length(procs) == 1)

%% Test trackeye
fpEvents = trackeye([0,0], 50, 'fp');
targetEvents = trackeye([300,300], 50, 'target');
pause(1)
assert(IPCEvent.wait_for_event(fpEvents{1}, 200))
assert(~IPCEvent.wait_for_event(fpEvents{2}, 200))

assert(~IPCEvent.wait_for_event(targetEvents{1}, 200))
assert(~IPCEvent.wait_for_event(fpEvents{2}, 200))

%% Test polynomial transform
c = EyeClient;
originalEyePosition = c.eyePosition;
% [x0 y0 x1 y1]
coeff = [200, 50, 10, 12, 5, 7];
EyeServer.Transform(coeff)
pause(0.1);
newEyePosition = c.eyePosition;
assert(newEyePosition(1) == coeff(1) + coeff(3)*originalEyePosition(1));
assert(newEyePosition(2) == coeff(2) + coeff(4)*originalEyePosition(2));

%% Test mixed term polynomial transform
% [1 x y x*y x*2 y*2] * [a0 b0; a1 b1; a2 b2; a3 b3; a4 b4; a5 b5]  
biquadCoeff = [
    12, 11;
    10, 9;
    8, 7; 
    6, 5;
    4, 3;
    2, 1;
    ]';

EyeServer.Transform(biquadCoeff(:)')
pause(0.1)
newEyePosition = c.eyePosition;
x = originalEyePosition(1);
y = originalEyePosition(2);
desiredEyePosition = [1 x y x*y x*2 y*2]  * biquadCoeff';
assert(newEyePosition(1) == desiredEyePosition(1))
assert(newEyePosition(2) == desiredEyePosition(2))


%% Test stop
EyeServer.Stop('test.edf')
assert(IPCEvent.wait_for_event('EyeServerDone', 2000))
delete('test.edf')

%% Test disconnect
trackeye('reset')
clear all
EyeServer.Disconnect
EyeServer.delete

