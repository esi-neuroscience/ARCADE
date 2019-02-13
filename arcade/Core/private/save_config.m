function save_config(cfg)
% SAVE_CONFIG - Save current ARCADE configuration and associated files in 
%               backup folder
%
% The following files will be stored in ARCADE/sessionLog/<sessionName>/Backup
%   - task script (.m)
%   - ARCADE configuration (_cfg.mat)
%   - condition selection function (.m)
%   - block selection function (.m)
%   - eventmarker file (.m)
%   - manually added files (ArcadeConfig.Files.UserAdded)


filesToCopy = {};
for iFile = 1:length(cfg.Files.UserAdded)
    filesToCopy{end+1} = cfg.Files.UserAdded{iFile};    
end
if ~isempty(cfg.Files.BlockSelection)
    filesToCopy{end+1} = cfg.Files.BlockSelection;
end
if ~isempty(cfg.Files.ConditionSelection)
    filesToCopy{end+1} = cfg.Files.ConditionSelection;
end
if ~isempty(cfg.Files.EventMarkers)
    filesToCopy{end+1} = cfg.Files.EventMarkers;
end
filesToCopy{end+1} = cfg.taskFile;

for iFile = 1:length(filesToCopy)
    [~, targetFile, ext] = fileparts(filesToCopy{iFile});
    assert(copyfile(filesToCopy{iFile}, ...
        fullfile(cfg.filepaths.Backup, [targetFile, ext])));
end
cfg.save(fullfile(cfg.filepaths.Backup, [cfg.sessionName '_cfg.mat']));