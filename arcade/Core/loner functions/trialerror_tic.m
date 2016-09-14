function trialerror_tic( setmode, varargin )
persistent startTic

switch setmode
    case 'settic'
        startTic = varargin{1};
    case 'start'
        startTic = tic;
    case 'end'
        % record in ms
        try
            endTime = toc(startTic)*1000;
        catch
            endTime = nan(1);
        end
        BHVStore = SGLBehaviouralStore.launch;
        BHVStore.trialErrorTime(BHVStore.currentTrial) = endTime;
     case 'reset'
        startTic = [];   
end

end

