function reactiontime( setmode, varargin )
%REACTIONTIME Measure and store reaction times.
%  
% INPUT
% -----
% Input is always a string plus optional further arguments:   
% 
%   'start'    : start timer for reaction time
%   'end'      : record elapsed time in ms since reactiontime('start')
%                in behavioral data file
%   'writeRT', rt   : write rt as reaction time value to
%                     behavioral data file, e.g.
%                     reactiontime('writeRT', 264)
%   'settic', timer : set start timer to timer handle returned by tic
%
%
% EXAMPLE
% -------
%   ...
%   sWaitForResponse = State('WaitForResponse');
%   sWaitForResponse.duration = 2000;
%   sWaitForResponse.waitEvents = {'targeIn'};
%   sWaitForResponse.onEntry = {
%       @() reationtime('start')
%       };
%   sWaitForResponse.nextStateAfterEvent = {'Correct'};
%   sWaitForResponse.nextStateAfterTimeout = 'NoResponse';
%
%   sCorrect = State('Correct');
%   sCorrect.duration = 0;
%   sCorrect.onEntry = {
%       @() reactiontime('end')
%       };
%   ...
%
% For more information, see <a href="matlab:doc('arcade')">the ARCADE guide</a>.
%
%
% See also tic
 
persistent startTic

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


