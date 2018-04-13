classdef MSBackupCopy < AUXBackupCopy & AUXUIControlFunctions & AUXDirectoryManager
    % [MAIN SCREEN]

    % *uses methods in MSConfig 
    % -> mReplaceChar()
    % -> mGetFieldCfg()
    % -> mSetFieldCfg()
    
    % when the RUN button is clicked
    % files are copied over
    
    % METHODS:
    %   mInitBackupButtonsAndCheckboxes(this)
    %   mCreateBackupFilepaths(this)
    %   mCreateBackupFileList(this,boolCopyFiles)
    %   mGetFileGroup(this,fgrp)
    %   mAddBackupFileCallback(this,~,~,cfgFieldPath,hObj_LBox,hObj_UserChkBx)
    %   mRemoveBackupFileCallback(this,~,~,cfgFieldPath,hObj_LBox)
    %   mClearBackupCallback(this,~,~,cfgFieldPath,hObj_LBox)
    %   mUserAddedFilesChanged(this,~,~,cfgFieldPath,hObj_LBox)
    %   mCheckUserAddedFilesExist(this,userFiles)
    
    % INHERITANCE:
    % MSBackupCopy < ...
    %   AUXDirectoryManager < handle *replaces AUXFilePaths*
    %   AUXBackupCopy < handle (GUIs\MainScreen\classes)

    % INHERITED PROPERTIES:
    %   version_path    [AUXFilePaths]
    %   dispServer_path [AUXFilePaths]
    
    % DEPENDENCIES:
    %   WRNGFileNotFound
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote initial class
    % 16.4.2015 - Jarrod, wrote class contains functions from a previous version
    % 20.4.2015 - Jarrod, 
    % - added filepath property 
    % - added ask user if User Added Files, but backup checkbox not selected
    % 21.4.2015 - Jarrod, Added some methods
    % - mCreateBackupFileList(this)
    % - mGetFileGroup(this,fgrp)
    % 22.4.2015 - Jarrod, some minor changes to the backup files methods
    %  3.5.2015 - Jarrod, fixed copy file bug
    % - made a small change in mGetFileGroup(), combine filepaths with union()
    % 21.4.2016 - Jarrod, added some documentation/notes
    % 29.4.2016 - Jarrod, added some documentation 
    %  2.5.2016 - Jarrod, 
    % - replaced AUXFilePaths with AUXDirectoryManager
    %  3.5.2016 - Jarrod, 
    % - replaced the old AUXFilepaths with the new version
    % FPATH = SGLFilepathManager.launch;
    % 27.2.2018 - commented a redundant line of code 
    
    properties (...
            AbortSet  = true,...
            SetAccess = protected)
        filepaths      = []; % structure of filepaths (where to write the data from this session)
        backupFileList = {}; % combined (master) backup file list
    end
    
    methods (Static)
        %# constructor 
        function this = MSBackupCopy
        end
    end
    
    methods (Sealed = true)
        %# initialize buttons/checkboxes
        function mInitBackupButtonsAndCheckboxes(this)
            
            % buttons 
            btnAddBckup = findobj(this.hfig,'Tag','btn_AddBackup');
            btnRemBckup = findobj(this.hfig,'Tag','btn_RemoveBackup');
            btnClrBckup = findobj(this.hfig,'Tag','btn_ClearBackup');
            
            hObj_LBox      = findobj(this.hfig,'Tag','cfg_Files_UserAdded');
            hObj_UserChkBx = findobj(this.hfig,'Tag','cfg_BackupSettings_User');
            
            cfgPath_UserFile = this.mReplaceChar('cfg_Files_UserAdded','_','.');
            % for the files listbox (user added files)
            % 1. overwrite the callback for the list box
            % 2. [add/remove/clear] buttons modify the list, and notify an event
            % 3. a listener to the event adds the short file names to the list
            
            % overwrite listbox callback function 
            set(hObj_LBox,'Callback',[]); 
            % when the cfg is loaded call this function
            addlistener(this,'cfgIsLoaded',@(hObj,evt) this.mUserAddedFilesChanged(hObj,evt,cfgPath_UserFile,hObj_LBox));

            % button callbacks 
            set(btnAddBckup,'Callback',...
                @(hObj,evt) this.mAddBackupFileCallback(hObj,evt,cfgPath_UserFile,hObj_LBox,hObj_UserChkBx));
            set(btnRemBckup,'Callback',...
                @(hObj,evt) this.mRemoveBackupFileCallback(hObj,evt,cfgPath_UserFile,hObj_LBox));
            set(btnClrBckup,'Callback',...
                @(hObj,evt) this.mClearBackupCallback(hObj,evt,cfgPath_UserFile,hObj_LBox));
            
        end
        

        %--------------------------%

        %# create backup filepaths and directories 
        % create the SessionLog directory
        % to store the behavioural data and,
        % store a backup of the task files 
        function success = mCreateBackupFilepaths(this)
            
            % get the session log path 
            FPATH = SGLFilepathManager.launch;
            sessPath = FPATH.pathSessionLog; 
            
            % get strings 
            subj = this.cfg.Subject;
            expt = this.cfg.Experiment;
            sess = this.cfg.Session;
            
            % create this session directory 
            %sessFilepath = fullfile(sessPath,subj,expt,sess);
            sessFilepath = fullfile(sessPath,[subj '_' today '_' expt '_' sess]);
            
            warn = true;
            success_sess = this.mCreateDirectory(sessFilepath,warn);
            if ~success_sess
                success = success_sess;
                return;
            end

            % create subdirectories 
            bckpFilepath = fullfile(sessFilepath,'Backup');
            behvFilepath = fullfile(sessFilepath,'Behaviour');
            
            % create directories 
            warn = false;
            success_bck = this.mCreateDirectory(bckpFilepath,warn);
            success_bhv = this.mCreateDirectory(behvFilepath,warn);
            
            success = success_bck & success_bhv & success_sess;
            
            filepaths = [];
            if success
                % add filepaths 
                filepaths.Backup    = bckpFilepath;
                filepaths.Behaviour = behvFilepath;
                filepaths.Session   = sessFilepath;
            end
            this.filepaths = filepaths;    
            
        end
        
        
        %# create backup list
        function mCreateBackupFileList(this,boolCopyFiles)
            % when the run button is clicked
            %this.cfg.Files;
            %this.cfg.BackupSettings;

            backupFileList = {}; %#ok<*PROP>
            bkfiles = {'Main','Task','User'}; % check these
            
            for k = 1:length(bkfiles)
                
                if this.cfg.BackupSettings.(bkfiles{k})
                    grpfilepaths = this.mGetFileGroup(bkfiles{k});
                    
                    if ~isempty(grpfilepaths)
                        % combine file lists into master list
                        % removes duplicates 
                        backupFileList = this.mCombineFileLists(backupFileList,grpfilepaths);
                    end
                end
            end
            
            if ~isempty(backupFileList) 
                % set backuplist
                this.backupFileList = backupFileList;
                
                % if user requested backup files
                if boolCopyFiles
                    % get backup filepath
                    bckpFilepath = this.filepaths.Backup;
                    if ~isempty(bckpFilepath)
                        disp('Copying backup files....');
                        success = this.mCopyFile(backupFileList,bckpFilepath);
                        if any(~success)
                            disp('WARNING: Some backup files not copied...');
                        end
                    end
                end
            end
            
        end
        
        %# get filepaths in group 
        function filepaths = mGetFileGroup(this,fgrp)
            filepaths = [];
            switch fgrp
                case 'Main'
                    mainFiles = {...
                        'EventMarkers';....
                        'BlockSelection';...
                        'ConditionSelection'};
                    
                    filepaths = {...
                        this.taskFile;...
                        this.cfgFile};
                    
                    for k = 1:length(mainFiles)
                        mainFile_ = this.cfg.Files.(mainFiles{k});
                        result    = this.mIsFilpath(mainFile_);
                        if result
                            filepaths = union(filepaths,mainFile_,'stable'); 
                        end
                    end
  
                case 'Task'
                    filepaths = this.mGetDirectoryFiles(fileparts(this.taskFile));
                case 'User'
                    userFiles = this.cfg.Files.UserAdded;
                    result    = this.mIsFilpath(userFiles); % check if filepaths
                    if all(result) 
                        % there are many error checks along the way,
                        % so this should be the case 
                        % however, in the case that the backup checkbox is checked, 
                        % but the file list is empty
                        filepaths = userFiles;
                    end
                case 'Stim'
                    % not available 
                otherwise 
                    % not available
            end
        end
        
        %--------------------------%
        %    button callbacks
        
        %# add file(s) callback 
        function mAddBackupFileCallback(this,~,~,cfgFieldPath,hObj_LBox,hObj_UserChkBx)
            persistent flagAskedUserManBackup
            % set flag to false 
            if isempty(flagAskedUserManBackup), flagAskedUserManBackup = false; end;
            %------------------------%
            boolUpdateListBox = false;
            msg        = 'Select File(s) to Backup';
            fileType   = '*.*'; % all files 
            multisel   = 'on';
            fullfilepath = this.mFilePrompt(fileType,msg,'open',multisel);

           if ~isempty(fullfilepath)
                
                % get current filepaths 
                userFiles = this.mGetFieldCfg(cfgFieldPath);
                %eval(['userFiles =',cfgFieldPath,';']);
                
                if isempty(userFiles)
                    
                    this.mSetFieldCfg(cfgFieldPath,fullfilepath);
                    %eval([cfgFieldPath,'= fullfilepath;']);
                    boolUpdateListBox = true;
                else
                    % combine files 
                    combinedList = this.mCombineFileLists(userFiles,fullfilepath);
                    %keyboard
                    
                    %varargin = {userFiles,fullfilepath};
                    
                    if ~isequal(userFiles,combinedList)
                        this.mSetFieldCfg(cfgFieldPath,combinedList);
                        %eval([cfgFieldPath,'= combinedList;']);
                        boolUpdateListBox = true;
                    end
                end
            end
            
            if boolUpdateListBox
                this.mUserAddedFilesChanged([],[],cfgFieldPath,hObj_LBox);
                
                % **only ask user once**
                % if user has added files, 
                % but the backup file checkbox is not checked,
                % ask user if they wish to backup the Manually added files
                if ~flagAskedUserManBackup
                    % if the user has not been asked
                    backupChkBxValue = get(hObj_UserChkBx,'Value');
                    % checkbox is not clicked
                    if backupChkBxValue==0
                        % ask user
                        request = questdlg(...
                            {'Files have been associated with this task, but the "Manually Added Files" checkbox is not checked.','',...
                            'Would you like to backup/copy these files to the session directory?'},...
                            'Backup Files Checkbox not Checked', 'Yes','No','Yes');
                        
                        if strcmpi(request,'Yes')
                            set(hObj_UserChkBx,'Value',1);
                        else
                            wmsg = sprintf(...
                            ['Manually Added Files will not be copied to the session log.\n',...
                            'This can be changed by checking the "Manually Added Files" checkbox.\n',...
                            'This question will not be asked again.']);
                            wtitle = 'Warning!';
                            
                            this.mWarningWait(wmsg,wtitle);
                        end
                        % only ask user once
                        flagAskedUserManBackup = true; 
                    end
                end
            end
        end
        
        
        %# remove file(s) user added files 
        function mRemoveBackupFileCallback(this,~,~,cfgFieldPath,hObj_LBox)
            
            % get selected
            userSelected = get(hObj_LBox,'Value');
            
            % get current filepaths
            %eval(['userFiles =',cfgFieldPath,';']);
            userFiles = this.mGetFieldCfg(cfgFieldPath);
            % if none selected return
            if (numel(userSelected)==1 && userSelected(1)==0) ||...
                    isempty(userSelected) || isempty(userFiles) %#ok<*NODEF>
                return;
            end
            
            userFiles(userSelected) = [];
            %eval([cfgFieldPath,'= newList;']);
            this.mSetFieldCfg(cfgFieldPath,userFiles);
            
            this.mUserAddedFilesChanged([],[],cfgFieldPath,hObj_LBox);
        end
        
        %# clear all user added files 
        function mClearBackupCallback(this,~,~,cfgFieldPath,hObj_LBox)
            
            %eval([cfgFieldPath,'= [];']);
            this.mSetFieldCfg(cfgFieldPath,[]);
            
            % set new value
            set(hObj_LBox,'Value', 0);
            set(hObj_LBox,'String',{});  
        end
        
        %--------------------------%
        %  event/button callbacks
        
        % function user added files changed 
        % this function is called when the cfg file is loaded 
        function mUserAddedFilesChanged(this,~,~,cfgFieldPath,hObj_LBox)
            
            % get current filepaths
            %eval(['userFiles =',cfgFieldPath,';']);
            userFiles = this.mGetFieldCfg(cfgFieldPath);
            
            filenames = this.mGetShortFile(userFiles,true);
            
            % set selected value
            if isempty(userFiles)
                newValue = 0;
            else
                newValue = min([get(hObj_LBox,'Value'),length(userFiles)]);
                newValue = max(newValue,1); % ensure it is at least 1
            end
            set(hObj_LBox,'Value',newValue);
            set(hObj_LBox,'String',filenames);
            
        end
        
        %-----------------------------------%
        %         error functions 
        
        %function mCheckCheckboxUserAddedFiles(this)
            % if the check box is checked
            % but there are no User Added files 
        %end
        
        
        function fexist = mCheckUserAddedFilesExist(this,userFiles)
            if isempty(userFiles)
                fexist = [];
                return; 
            end
            
            fexist = this.mCheckFilesExist(userFiles);
            if any(~fexist)
                % if any files do not exist
                
                doNotExist = userFiles(~fexist);
                
                WRNG = WRNGFileNotFound.launch;
                WRNG.mSetFilesNotFound(doNotExist);
                
                % set the existing fileaths
                %userFiles(~fexist) =[]; % remove the files that do not exist
                %this.mSetFieldCfg(cfgFieldPath,userFiles);
            end
            
        end
        
    end

end

