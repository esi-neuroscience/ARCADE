function [procs, readyEvents] = launch_processes(cfg)


% defaults
if ~exist('cfg', 'var'); cfg = []; end
if ~isfield(cfg, 'EyeServer')
    cfg.EyeServer = 'EyeLinkServer.exe';
end
if ~isfield(cfg, 'DaqServer')
    cfg.DaqServer = 'NidaqServer.exe';
end
if ~isfield(cfg, 'ControlScreen')
    cfg.ControlScreen = 'MatlabControlScreen.bat';
    cfg.ControlScreen = 'None';
end
if ~isfield(cfg, 'StimServer')
    cfg.StimServer = 'StimServer.exe';
end
if ~isfield(cfg, 'OtherExecutables')
    cfg.OtherExecutables = {};
end

procs = {};
readyEvents = {};
% launch other processes
for iExe = 1:length(cfg.OtherExecutables)
    cmd = cfg.OtherExecutables{iExe};
    logmessage(sprintf('Starting %s', cmd))
    procs{end+1} =  processManager('id', cmd, 'command',  cmd);
 
end

% launch control screen process
if ~strcmp(cfg.ControlScreen, 'None')
    logmessage('Starting ControlScreen')
    controlScreenExePath = fullfile(arcaderoot, 'arcade', ...
        'ControlScreen', cfg.ControlScreen);
    procs{end+1} = processManager('id', 'ControlScreen', ...
        'command',  controlScreenExePath);
    controlScreenDoneEvent = IPCEvent('ControlScreenDone');
%     readyEvents{end+1} = Control
end

% launch EyeServer process
if ~strcmp(cfg.EyeServer, 'None')
    logmessage('Starting EyeServer')
    eyeServerExePath = fullfile(arcaderoot, 'arcade', ...
        'EyeServer', cfg.EyeServer);
    procs{end+1} = processManager('id', 'EyeServer', ...
        'command', eyeServerExePath);
    readyEvents{end+1} = EyeServer.doneEventName;
end

% launch DaqServer process
if ~strcmp(cfg.DaqServer, 'None')
    logmessage('Starting DaqServer')
    daqServerExePath = fullfile(arcaderoot, 'arcade', ...
        'DaqServer', cfg.DaqServer);
    procs{end+1} = processManager('id', 'DaqServer', ...
        'command', daqServerExePath);
%     readyEvents{end+1} = DaqServer.doneEventName;
end


% launch StimServer process
if ~strcmp(cfg.StimServer, 'None')
    logmessage('Starting StimServer')
    stimServerExePath = fullfile(arcaderoot, 'arcade', ...
        'StimServer', cfg.StimServer);
    procs{end+1} = processManager('id', 'StimServer', ...
        'command',  stimServerExePath);
    readyEvents{end+1} = StimServer.doneEventName;
end

pause(0.5)
MultipleEvents.Init(readyEvents)
result = MultipleEvents.WaitFor(readyEvents, 1, 5000);
assert(result == 1, 'Not all processes could be started within 5 s')

% connect to StimServer
if ~strcmp(cfg.StimServer, 'None')
    StimServer.Connect();
end

% connect to DaqServer
if ~strcmp(cfg.DaqServer, 'None')
     DaqServer.Connect();
end


% connect to EyeServer
if ~strcmp(cfg.EyeServer, 'None')
     EyeServer.Connect();
     EyeServer.Start([datestr(now,'mmddHHMM') '.edf'])
end




