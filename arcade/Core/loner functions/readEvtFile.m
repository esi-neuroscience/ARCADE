function evt = readEvtFile(filename)
% Read .evt file written by ARCADE.
%   
% .evt files contain the timestamps in microseconds and marker values as 
% uint64 values.
% 
% INPUT
% -----
%       filename : string, optional
% 
% OUTPUT
% ------
%       evt : struct with fields timestamps (us) and values
% 
if nargin == 0
    [filename, pathname] = uigetfile('*.evt', 'Pick an ARCADE event file (*.evt)');
    if filename == 0
        return
    end    
    filename = fullfile(pathname,filename);
end

fid = fopen(filename, 'r');
assert(fid ~= -1, 'Could not open %s', filename)
dat = fread(fid, Inf, 'uint64');
fclose(fid);


evt.timestamps = dat(1:2:end);
evt.values = dat(2:2:end);