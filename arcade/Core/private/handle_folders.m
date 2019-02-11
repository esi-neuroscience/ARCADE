function [foldersWereCreated, cfg] = handle_folders(cfg)

sessionLogFolder = fullfile(arcaderoot, 'sessionLog');
basename =  [cfg.Subject '_' today '_' cfg.Experiment, '_' cfg.Session];
if ~isfield(cfg.filepaths, 'Session')
    cfg.filepaths.Session =  fullfile(sessionLogFolder, basename);
end

foldersWereCreated = false;

while exist(cfg.filepaths.Session, 'dir') == 7
    
    answer = questdlg(sprintf('%s exists. What do you want to do?', basename), ...
        'Handle existing data', ...
        'Overwrite existing data', ...
        'Change session name manually', ...
        'Cancel', ...
        'Cancel');
    
    switch answer
        case 'Overwrite existing data'
            disp('overwrite!')
            warnString = sprintf('The contents of %s will be deleted', basename);
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
            newBasename = [cfg.Subject '_' today '_' cfg.Experiment '_' cfg.Session];           
            cfg.filepaths.Session = fullfile(sessionLogFolder, newBasename);           
            
        case 'Cancel'            
            return
            
    end
end
assert(dos(sprintf('md %s', cfg.filepaths.Session)) <= 1)


cfg.filepaths.Backup = fullfile(cfg.filepaths.Session, 'Backup');
assert(dos(sprintf('md %s', cfg.filepaths.Backup)) <= 1)

cfg.filepaths.Behaviour = fullfile(cfg.filepaths.Session, 'Behaviour');
assert(dos(sprintf('md %s', cfg.filepaths.Behaviour)) <= 1)

foldersWereCreated = true;
