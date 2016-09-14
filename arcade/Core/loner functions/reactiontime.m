function reactiontime( setmode, varargin )
persistent startTic

% ----------------------------------------- %
% 13.8.2015 - Jarrod,
% - added writeRT which for some reason was not there
% - added otherwise

switch setmode
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
        BHVStore.reactionTime(BHVStore.currentTrial) = endTime;
    case 'reset'
        startTic = [];
    case 'settic'
        startTic = varargin{1};    
    case 'writeRT'
        rt = varargin{1};
        if isnumeric(rt)
            BHVStore = SGLBehaviouralStore.launch;
            BHVStore.reactionTime(BHVStore.currentTrial) = rt;
        else
            disp('ERROR calling reactiontime(): value NOT numeric.');
        end
    otherwise
        fprintf('ERROR calling reactiontime(): unknown mode %s\n',setmode);
        
end

end

