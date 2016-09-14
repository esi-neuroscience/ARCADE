classdef AUXFilePaths < handle
    % [AUXILLARY] FILEPATHS
    
    % SUBCLASSES:
    %   MainScreen < MSBackupCopy
    
    
    % the function of this class
    % is to retreive the current filepath
    % for the Main directory, and the StimServer 
    % therefore, it must always live in a defined location
    % this is assumed to be the Code directory

    %---------------------------------------------%
    % 20.4.2015 - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    % 29.4.2016 - Jarrod,
    %   - fixed path split (now more stable)
    %   - made file path properties private 
    %   - removed method mCorrectDriveLetterInSplitPath()
    %  2.5.2016 - Jarrod, 
    %   - removed directory methods
    %   - moved file to MainScreen directory
    
    properties (SetAccess = private)
        %version_path
        dispServer_path
    end
    
    %# constructor 
    methods (Static)
        function this = AUXFilePaths
            % get the filepath where this class lives 
            pathSplit = this.mSplitFilepath(mfilename('fullpath'));
            
            %this.version_path    = fullfile(pathSplit{1:end-2},filesep); %#ok<*SBTMP>
            %this.dispServer_path = fullfile(pathSplit{1:end-3},filesep);
            %this.version_path    = fullfile(pathSplit{1:end-2}); %#ok<*SBTMP>
            this.dispServer_path = fullfile(pathSplit{1:end-3});
        end
    end
    
    methods (Sealed = true)
        %function mGetDisplayServerPaths(this)
        %    pathSplit = this.mSplitFilepath(mfilename('fullpath'));
        %end
        
        
        % get filepath 
        function filepath = mGetFilepath(this,fpath)
            switch fpath
                case 'Task'
                    filepath = fullfile(this.dispServer_path,'Tasks');
                case 'SessionLog'
                    filepath = fullfile(this.dispServer_path,'session_log');
                case 'ErrorLog'
                    filepath = fullfile(this.dispServer_path,'error_log');
                otherwise
                    % not available 
                    filepath = [];
            end
        end
    end
    
    
    methods (...
            Static = true,...
            Sealed = true)

        %# split filepath
        function pathSplit = mSplitFilepath(filepath)
            % updated method to handle filepaths better
            % returns cell vector of filepath parts
            pat = filesep;
            pathSplit = regexp(filepath,pat,'split');
        end


    end
    
end
