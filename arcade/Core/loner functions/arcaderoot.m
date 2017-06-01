function path = arcaderoot()
mpath = mfilename('fullpath');
parts = strsplit(mpath, filesep);
parts = parts(1:end-4);
path = fullfile(parts{:});