function convertEsiFile(filename)
% CONVERTESIFILE - Convert behavioral data stored in .esi file written by
% ARCADE to .mat
%

if nargin == 0
    [filename, pathname] = uigetfile('*.esi', 'Pick an ARCADE esi file (*.esi)');
    if filename == 0
        return
    end
    filename = fullfile(pathname,filename);
end

[pathname, filename, ~] = fileparts(filename);
filename = fullfile(pathname, filename);

fid     = fopen([filename,'.esi'],'r'); %#ok<*PROP>
fid_hdr = fopen([filename,'.hdr'],'r');

try
    % get bit counts for each trial from header
    count = fread(fid_hdr,'uint32=>double'); % convert from uint32=>double implicitly
    %frewind(h_fid);
    nTrials = numel(count);
    disp('Reading behavioral file...')
    disp(['Reading ', num2str(nTrials), ' trials...']);
    
    trlSer = cell(nTrials,1);
    % loop over trials
    for k = 1:nTrials
        trlSer{k} = fread(fid,count(k),'*uint8'); % read all
    end
    
catch ME
    fclose(fid);
    fclose(fid_hdr);
    rethrow(ME)
end

% close files
fclose(fid);
fclose(fid_hdr);

% deserialize
trlData = cellfun(@(m) hlp_deserialize(m),trlSer,'unif',0)';

% combine structure array
bhvData = mCombineStructArray(trlData); 
% save structure
save([filename,'.mat'], '-struct','bhvData');
fprintf('Saved behavioral file to %s\n', [filename '.mat']);

end

function bhvData = mCombineStructArray(trlData) 

fnames = fieldnames(trlData{1});

% create struture
bhvData = [];
for fn = 1:numel(fnames)
    bhvData.(fnames{fn}) = [];
end

%cell2mat(userVariables)

ntrl = length(trlData);
for k = 1:ntrl
    for fn = 1:numel(fnames)
        data = trlData{k}.(fnames{fn});
        if iscell(data) || isstruct(data) || numel(data)>1
            bhvData.(fnames{fn}){k} = data;
        else
            bhvData.(fnames{fn})(k) = data;
        end
    end
end
end