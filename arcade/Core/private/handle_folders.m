function [foldersWereCreated, cfg] = handle_folders(cfg)
% HANDLE_FOLDERS(CFG) - Make sure all necessary session folders are ready
%
% 

% check if sessionLog folder exists (ARCADE/sessionLog)
sessionLogFolder = fullfile(arcaderoot, 'sessionLog');
if ~isfield(cfg.filepaths, 'Session')
    cfg.filepaths.Session =  fullfile(sessionLogFolder, cfg.sessionName);
end

foldersWereCreated = false;

% handle existing folders
while exist(cfg.filepaths.Session, 'dir') == 7
    
    answer = questdlg(sprintf('%s exists. What do you want to do?', cfg.sessionName), ...
        'Handle existing data', ...
        'Overwrite existing data', ...
        'Change session name manually', ...
        'Cancel', ...
        'Cancel');
    
    switch answer
        case 'Overwrite existing data'
            disp('overwrite!')
            warnString = sprintf('The contents of %s will be deleted', cfg.sessionName);
            warnTitle  = 'Warning!';
            f = warndlg(warnString, warnTitle, 'modal');
            waitfor(f);
  
            % delete directory
            [result, message, ~] = rmdir(cfg.filepaths.Session,'s');
            assert(result == 1, message)
            
        case 'Change session name manually'
            newSession = inputdlg('Enter new session identifier', ...
                'New session name', 1, {cfg.Session});
            cfg.Session = newSession{1};            
            cfg.filepaths.Session = fullfile(sessionLogFolder, cfg.sessionName);            
            
        case 'Cancel'            
            return
            
    end
end

% create folders
assert(dos(sprintf('md %s', cfg.filepaths.Session)) <= 1)

cfg.filepaths.Backup = fullfile(cfg.filepaths.Session, 'Backup');
assert(dos(sprintf('md %s', cfg.filepaths.Backup)) <= 1)

cfg.filepaths.Behaviour = fullfile(cfg.filepaths.Session, 'Behaviour');
assert(dos(sprintf('md %s', cfg.filepaths.Behaviour)) <= 1)

foldersWereCreated = true;
