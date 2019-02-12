function print_header(varargin)

if nargin == 0
    procName = 'ARCADE CORE';
end

headerAsterisk = '****************  ARCADE  ********************\n';
dateTimeString      = datestr(now,'dd-mmm-yyyy HH:MM:SS');
matlabVersionString = version();
userNameString      = getenv('username');
computerNameString  = getenv('computername');

fprintf(headerAsterisk)
fprintf('Launching:')
fprintf(' %s', varargin{:});
fprintf('\n')
% date and time
fprintf('%s\n', dateTimeString);
% matlab version
fprintf('MATLAB version: %s\n', matlabVersionString);
% user name
fprintf('User name: %s\n',  userNameString);
% matlab version
fprintf('Computer name: %s\n',  computerNameString);
% ARCADE version
fprintf('ARCADE version: %s\n', arcadeVersion)
% end information header
fprintf(headerAsterisk);
