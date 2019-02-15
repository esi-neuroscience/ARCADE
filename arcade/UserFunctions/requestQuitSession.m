function result = requestQuitSession(varargin)
%REQUESTQUITSESSION end session after current trial
%
%   requestQuitSession()
%
% EXAMPLE
% -------
%   if totalRewardTime() > 2000
%       requestQuitSession()
%   end
%

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


