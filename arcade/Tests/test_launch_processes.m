


%% Test 1
cfg = ArcadeConfig;
cfg.EyeServer = 'EyelinkServer.exe';
cfg.DaqServer = 'NidaqServer.exe';
cfg.ControlScreen = 'MatlabControlScreen.bat';
cfg.StimServer = 'StimServer.exe';
cfg.OtherExecutables = {'C:\Windows\notepad.exe'};


procs = launch_processes(cfg);
assert(length(procs) == 5)

% quit jobs
IPCEvent.set_event('ControlScreenDone')
cellfun(@(x) x.stop(), procs);

