function add_arcade_to_path()

arcadeFolder = fileparts(mfilename('fullpath'));
addpath(genpath(arcadeFolder));

parts = strsplit(arcadeFolder, filesep);
parts = parts(1:end-1);
tasksFolder = fullfile(parts{:}, 'Tasks');
addpath(genpath(tasksFolder));