classdef AUXDirectoryManager < handle 
    % [AUXILLARY] DIRECTORY MANAGER 
    %    manage creation, removal, and checks for directories
    
    % *this class has assumed methods from AUXFilePaths*
    
    % SUBCLASSES:
    %   MainScreen < MSBackupCopy
    
    
    
    %---------------------------------------------%
    % 2.5.2016 - Jarrod, wrote class
    % 16.5.2016 - Jarrod, fixed bug in filename warning
    
    methods (Static)
        function this = AUXDirectoryManager
        end
    end
    

    methods (...
            Static = true,...
            Sealed = true)
        
        %# check if directory exists 
        function result = mCheckDirectory(dirpath,warn)
            % ----------------------------- %
            % check if the dirctory exists
            % - yes -> return 1
            % - no  -> return 0
            
            % if warn, ask user to overwrite if exists 
            % - if yes, delete
            % - else, return
            
            % default: directory does not already exist
            result = false;
            % check if directory write path is okay
            if exist(dirpath,'dir')==7
                result = true;
                if warn
                    % user should be warned
                    pathSplit = regexp(dirpath,filesep,'split');
                    dirName   = pathSplit{end}; % add directory name into warning 
                    
                    request = questdlg(...
                        {sprintf('"%s" already exists!',dirName),'',...
                        'Would you like to overwrite the contents of this directory?'},...
                        'Warning!', 'Yes','No','No');
                    
                    if strcmp(request,'Yes')
                        warnString = sprintf('The contents of %s will be deleted',dirName);
                        warnTitle  = 'Warning!';
                        AUXDirectoryManager.mWarningWait(warnString,warnTitle);
                        % delete directory 
                        AUXDirectoryManager.mRemoveDirectory(dirpath);
                        
                        % one last check
                        % exist(dirpath,'dir')==7
                        result = false; % directory does not exist
                    end
                end
            end
        end
        
        %# create directory
        function success = mCreateDirectory(dirpath,warn)
            success   = false;
            doesExist = AUXDirectoryManager.mCheckDirectory(dirpath,warn);
            %keyboard
            if ~doesExist
                % create directory
                success = mkdir(dirpath);
            end
        end
        
        % remove directory contents 
        function mRemoveDirectory(dirpath)
            try
                [SUCCESS,MESSAGE,MESSAGEID] = rmdir(dirpath,'s'); %#ok<*NASGU,*ASGLU>
            catch ME
                disp(ME);
            end
        end
        
        %# warning wait for response 
        function mWarningWait(wmsg,wtitle)
            f = warndlg(sprintf(wmsg),wtitle, 'modal');
            waitfor(f);
        end
        
    end
    
end

