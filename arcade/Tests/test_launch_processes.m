

cfg = [];
cfg.EyeServer = 'EyelinkServer.exe';
% cfg.DaqServer = 'NidaqServer.exe';
cfg.DaqServer = 'None';
cfg.ControlScreen = 'None';
cfg.StimServer = 'StimServer.exe';
cfg.OtherExecutables = {'C:\Windows\notepad.exe'};

procs = launch_processes(cfg)