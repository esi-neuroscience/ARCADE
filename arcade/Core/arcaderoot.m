function path = arcaderoot()
mpath = mfilename('fullpath');
parts = strsplit(mpath, filesep);
parts = parts(1:end-3);
path = fullfile(parts{:});