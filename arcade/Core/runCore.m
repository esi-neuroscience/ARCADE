function runCore(varargin)
run(fullfile(fileparts(mfilename('fullpath')), '..', 'add_arcade_to_path.m'))

%--------------------------%
% turn on all warnings
warning('on','all');
% turn off some known warnings
warning('off','MATLAB:RMDIR:RemovedFromPath');
% some notation I used that should be fixed
warning('off','MATLAB:mir_warning_unrecognized_pragma');
%--------------------------%
initialWorkingDirectory = pwd;
cd(fileparts(mfilename('fullpath')));

sessionLogFolder = fullfile(arcaderoot, 'sessionLog');
if ~exist(sessionLogFolder, 'dir') == 7
    assert(dos(['md ' sessionLogFolder]))
end

%% Configure session
if nargin == 0
    % launch Main Screen
    MSgui = MainScreen.launch;
    
    if ~ishghandle(MSgui.hfig)
        delete(MSgui)
        fclose('all');
        return
    end
    
    cfg = MSgui.cfg; % get cfg file
    cfg.taskFile = MSgui.taskFile;
    
    % close main screen
    delete(MSgui);
    drawnow()
    
else
    cfg = load(varargin{1});
    if ~isfield(cfg, 'taskFile')
        cd(fullfile(arcaderoot, 'Tasks'))
        [filename, pathname] = uigetfile('*.m', 'Pick a MATLAB Taskscript');
        if filename == 0; return; end
        cfg.taskFile = fullfile(pathname, filename);
        cd(initialWorkingDirectory)
    end
    if ~isfield(cfg, 'filepaths')
        cfg.filepaths = [];
    end         
end

%% Initialize folders
[foldersCreated, cfg] = handle_folders(cfg);
if ~foldersCreated
    return
end

%% Initialize Servers
evtFile = fullfile(cfg.filepaths.Behaviour, ...
    [cfg.Subject '_' today() '_' cfg.Experiment '_' cfg.Session '.evt']);
eventServer = SGLEventMarkerServer.launch(evtFile);

% asynchronously launch subprocesses
processes = launch_processes(cfg);

cleanup = onCleanup(@() cleanup_function(cfg, processes));

%% Run session
cd(fileparts(cfg.taskFile));

% Launch Behavioural Data Store
BHVstore = SGLBehaviouralStore.launch(cfg);
% Launch a Session
SESSArc  = SGLSessionArc.launch;
% Start Session
logmessage('Starting Session')
SESSArc.mStart;

%----------------------------------------%
% close behavioural file
BHVstore.mCloseFile;
% convert file
BHVstore.mESIRead;

%----------------------------------------%
% leaving session
logmessage('Quitting session');

delete(BHVstore);
delete(SESSArc);

clear VARIABLES



%% Stop session and cleanup

logmessage('Closing MATLAB in 5 s. Press CTRL+C to cancel or see log files');

for seconds = 5:-1:0
    fprintf('%g\n', seconds)
    pause(1)
end
exit

end


function cleanup_function(cfg, procs)

% quit eye server
if ~strcmp(cfg.EyeServer, 'None')
    eyeFile =  fullfile(cfg.filepaths.Behaviour, ...
        [cfg.Subject '_' today() '_' cfg.Experiment '_' cfg.Session '.edf']);
    EyeServer.Stop(eyeFile)
    waitForFileEvt = IPCEvent('EyeServerDone');
    logmessage('Waiting for eye data transfer')
    result = waitForFileEvt.waitForTrigger(300000);
    if ~result
        warning('Could not transfer eye data')
    end
end

% quit control screen
IPCEvent.set_event('ControlScreenDone')

% Close StimServer pipe
% if ~strcmp(cfg.StimServer, 'None')
    StimServer.delete()
% end

% Close StimServer pipe
if ~strcmp(cfg.DaqServer, 'None')
    DaqServer.delete();
end

% close TrialData pipe
% if ~strcmp(cfg.ControlScreen, 'None')
    SGLTrialDataPipe.delete()
% end

% kill subprocesses
cellfun(@(x) x.stop(), procs)

fclose('all'); % close all open files

end

















