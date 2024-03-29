% 2/Aug/2023 MSt Removed change of processes' priority

function procs = launch_processes(cfg, varargin)

% defaults
if ~exist('cfg', 'var'); cfg = ArcadeConfig; end
if nargin == 1
    cfgPath = '';
elseif nargin == 2
    cfgPath = varargin{1};
end

% Accumulate executable file names for critical ARCADE processes in this.
% Empty string is a reference to the calling, Core process.
% critical = { '' } ;

procs = {};
readyEvents = {};
% launch other processes
for iExe = 1:length(cfg.OtherExecutables)
    cmd = cfg.OtherExecutables{iExe};
    logmessage(sprintf('Starting %s', cmd))
    procs{end+1} =  processManager('id', cmd, 'command',  cmd , ...
      'printStdout' , false , 'printStderr' , false );
end

% launch control screen process
if ~isempty(cfg.ControlScreen)
    logmessage(sprintf('Starting %s', cfg.ControlScreen))
    
    controlScreenExePath = fullfile(arcaderoot, 'arcade', ...
        'ControlScreen', [cfg.ControlScreen ' "' cfgPath '"']);
    procs{end+1} = processManager('id', 'ControlScreen', ...
        'command',  controlScreenExePath, ...
        'workingDir', fullfile(arcaderoot, 'arcade', 'ControlScreen'), ...
        'printStdout', false, 'printStderr', false);
    controlScreenDoneEvent = IPCEvent('ControlScreenDone');
    readyEvents{end+1} = controlScreenDoneEvent.name;
end

% launch EyeServer process
if ~isempty(cfg.EyeServer)
    logmessage('Starting EyeServer')
    eyeServerExePath = fullfile(arcaderoot, 'arcade', ...
        'EyeServer', cfg.EyeServer);
    procs{end+1} = processManager('id', 'EyeServer', ...
        'command', eyeServerExePath, 'printStdout' , false , ...
        'printStderr' , false);
    readyEvents{end+1} = EyeServer.doneEventName;
%    [ ~ , exe.name , exe.ext ] = fileparts ( eyeServerExePath ) ;
%    critical{ end + 1 } = [ exe.name , exe.ext ] ;
end

% launch DaqServer process
if ~isempty(cfg.DaqServer)
    logmessage('Starting DaqServer')
    daqServerExePath = fullfile(arcaderoot, 'arcade', ...
        'DaqServer', cfg.DaqServer);
    procs{end+1} = processManager('id', 'DaqServer', ...
        'command', daqServerExePath , 'printStdout' , false , ...
        'printStderr' , false);
    readyEvents{end+1} = DaqServer.doneEventName;
%    [ ~ , exe.name , exe.ext ] = fileparts ( daqServerExePath ) ;
%    critical{ end + 1 } = [ exe.name , exe.ext ] ;
end



logmessage('Waiting for processes to start')
pause(0.5)
if ~isempty(readyEvents)
    MultipleEvents.Init(readyEvents)
    result = MultipleEvents.WaitFor(readyEvents, 1, 20000);
    assert(result == 1, 'Not all processes could be started within 20 s')
    MultipleEvents.delete()
end

% launch StimServer process last when all other windows are open to prevent 
% change of StimServer full screen mode

if ~isempty(cfg.StimServer)
    logmessage('Starting StimServer')
    stimServerExePath = fullfile(arcaderoot, 'arcade', ...
        'StimServer', cfg.StimServer);
    procs{end+1} = processManager('id', 'StimServer', ...
        'command',  stimServerExePath , 'printStdout' , false , ...
        'printStderr' , false);
%    [ ~ , exe.name , exe.ext ] = fileparts ( stimServerExePath ) ;
%    critical{ end + 1 } = [ exe.name , exe.ext ] ;
    
    
    assert(IPCEvent.wait_for_event(StimServer.doneEventName, 10000), ...
        'StimServer startup failed')
    
    
    % connect to StimServer
    logmessage('Connect to StimServer')
    StimServer.Connect();
    logmessage(sprintf('FrameRate = %3.0f', StimServer.GetFrameRate));
end

% connect to DaqServer
if ~isempty(cfg.DaqServer)
    logmessage('Connect to DaqServer')
    DaqServer.Connect();
end

% connect to EyeServer
if ~isempty(cfg.EyeServer)
    logmessage('Connect to EyeServer')
    EyeServer.Connect();
    
    % Quick and dirty way for the user to optionally enable sample mode.
    % User must create an empty text file in the same folder as the task
    % file, and rename it EyeServer_SetSampleMode.arcade.
    if  exist( fullfile( fileparts( cfg.taskFile ) , ...
          'EyeServer_SetSampleMode.arcade' ) , 'file' )
      logmessage( 'Enabling EyeServer Sample Mode' )
      EyeServer.SetSampleMode( ) ;
    end
    
    EyeServer.Start('tmp.edf')
end

% connect to ControlScreen
if ~isempty(cfg.ControlScreen)
    logmessage('Connect to ControlScreen')
    SGLTrialDataPipe.Open()
    IPCEvent.set_event('ControlScreenDone')
end

% At this point, we have opened up all sub-processes. Now find and disable
% all Matlab timers that were set up by processManager, because these lead
% to a ~10% increase in the duration of any timer e.g. when calling
% WaitForEvents with a positive timeout value.
for  t = cellfun( @( p ) p.pollTimer , procs )
  if  isvalid( t )
    stop( t )
  end
end

% Find process identifiers of critical ARCADE processes
% apriority ( 'initialisation' , critical )
