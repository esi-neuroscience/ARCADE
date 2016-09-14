

% designed to set a flag -> UserRequestsToQuitSession
% this allows users to determine in their TrialScript logic
% if they would like to quit the session
% for example if they have enough trials.
% the flag is checked at the end of each trial
function result = requestQuitSession(varargin)
persistent quitSession
result = [];

if ~isempty(varargin)
    % 
    switch varargin{1}
        case 'init'
            quitSession = false;
        case 'set'
            quitSession = varargin{2};
        case 'read'
            if isempty(quitSession)
                disp('REQUEST_QUIT_SESSION: Not initialized or set.');
            else
                result = quitSession;
            end
    end
else
    % assume user wants to set quit 
    quitSession = true;
end

end

