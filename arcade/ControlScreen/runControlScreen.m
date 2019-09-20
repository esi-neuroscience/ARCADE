function runControlScreen(varargin)

run(fullfile(fileparts(mfilename('fullpath')), '..', 'add_arcade_to_path.m'))

% turn on all warnings
warning('on','all');
% turn off some known warnings
warning('off','MATLAB:RMDIR:RemovedFromPath');
warning('off','MATLAB:mir_warning_unrecognized_pragma');
if verLessThan('matlab', '9.6')
    warning('off', 'MATLAB:hg:WillBeRemovedReplaceWith')
    warning('off', 'MATLAB:hg:EraseModeIgnored')
    warning('off', 'MATLAB:hg:DrawModeIgnored')
end

SGLTrialDataPipe.Create();
finishup = onCleanup(@cleanup);
logmessage('Created TrialData Pipe')

logmessage(sprintf('Using predefined configuration file\n         %s', varargin{:}))

if nargin == 1 && ~isempty(varargin{1})
    cfg = ArcadeConfig(load(varargin{1}));
else
    cfg = ArcadeConfig;
end

% Launch/Initialize ControlScreen
CntlScreen = ControlScreen.launch;

for iTrialErrorLegend = 1:length(cfg.TrialErrorLegend)
    currErrLegend = cfg.TrialErrorLegend{iTrialErrorLegend};
    if ~isempty(currErrLegend)
        tag = sprintf('trx_%d', iTrialErrorLegend-1);
        set(findobj(CntlScreen.hfig, 'Tag', tag), ...
            'String', currErrLegend)
    end
end
set(findobj(CntlScreen.hfig, 'Tag', 'stx_sessionName'), ...
    'String', cfg.sessionName)


% launch Eye Plot
PltEyePos = SGLEyePosition.launch(CntlScreen.hfig);

% Launch SharedDataPool
ShrdDataPool = SGLSharedDataPool.launch(CntlScreen.hfig);


guiperf = zeros(1,2); % [WriteTime, UpdateTime]

logmessage('Entering loop');

% Signal Core process that we're ready for connect
controlScreenEvent = IPCEvent('ControlScreenDone');
controlScreenEvent.trigger();

% Wait for Core process to connect
assert(controlScreenEvent.waitForTrigger(30000), ...
    'Core process connect timed out')

try
    eyeClient = EyeClient;
catch me
    warning('Could not open current eye position')
    eyeClient = [];
end

pauseCoreEvt = IPCEvent('PauseCoreRequested');

while ~controlScreenEvent.wasTriggered && ishghandle(CntlScreen.hfig) 
    
    if CntlScreen.keyPressed
        switch CntlScreen.userRequest
            case 'pause_request'
                pauseCoreEvt.trigger()
        end
        CntlScreen.keyPressed = false;
    end
    
    % update eye position
    if ~isempty(eyeClient)
        eye_pos = eyeClient.eyePosition;
    else
        eye_pos = [NaN NaN];
    end
    PltEyePos.mUpdate(eye_pos);
    drawnow
    
    
    % check for trial data from Core    
    trialData = SGLTrialDataPipe.ReadTrialData();
    while ~isempty(trialData)        
        ShrdDataPool.mUpdateTrialData(trialData);
        
        % compute trial metrics
        trlMetrics = ShrdDataPool.mComputeTrialMetrics;
        trlMetrics.guiperf = guiperf; % add gui performance
        
        % update control screen
        t = tic;
        CntlScreen.mUpdateControlDisplay('update', trlMetrics);
        drawnow('expose'); % just update graphics
        
        % get the gui update time
        guiperf(1) = trialData(7);% write BHV time
        guiperf(2) = round(toc(t)*1000);     
        drawnow; % flush events
        trialData = SGLTrialDataPipe.ReadTrialData();
    end
    
    java.lang.Thread.sleep(5); % pause a bit
end
logmessage('Exiting loop');
quit

function cleanup()    
    SGLTrialDataPipe.Close
    SGLTrialDataPipe.delete()
end


end















