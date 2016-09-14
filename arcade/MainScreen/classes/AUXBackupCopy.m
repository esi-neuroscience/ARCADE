classdef AUXBackupCopy < handle
    % [AUXILLARY] FILE BACKUP 
    
    
    % METHODS:
    %   mCombineFileLists(varargin)
    %   mRemoveFromFileList(masterList,remList)
    %   mGetShortFile(filepaths,keepext)
    %   mSingleShortFile(fullfilepath,keepext,varargin)
    %   mIsFilpath(fullfilepath)
    %   mGetDirectoryFiles(dirpath)
    %   mCheckFilesExist(filepaths)
    %   mFileIsInTaskDirectory(TaskFile,filepaths)
    %   mCopyFile(src_filepaths,dest_filepath)
    %   mMoveFile(src_filepaths,dest_filepath)
    
    % SUBCLASSES:
    %   SGLBehaviouralStore -> AUXBackupCopy.mSingleShortFile
    %   MSBackupCopy 

    %---------------------------------------------%
    % Jarrod, wrote class
    % 16.4.2015 - Jarrod, wrote class in place of a previous version
    % 20.4.2015 - Jarrod, added copy and move file methods 
    % 24.4.2015 - Jarrod, changed the mSingleShortFile() method for call_func
    %  3.5.2015 - Jarrod, fixed copy file bug: changed the logic in mCombineFileLists() 
    % 21.4.2016 - Jarrod, added some documentation/notes
    %  3.5.2016 - Jarrod, added some documentation 
    
    methods (Static)
        %# constructor
        function this = AUXBackupCopy
        end
    end

     
    methods (...
            Static = true,...
            Sealed = true)
        
        %# create a combined list of filepaths 
        function combinedList = mCombineFileLists(varargin)
           
            % remove empty cells 
            indxNotEmptyInputs = ~cellfun(@isempty,varargin);
            fileLists          = varargin(indxNotEmptyInputs);
            nLists             = sum(indxNotEmptyInputs);
            
            combinedList = {};
            
            if nLists==1
                combinedList = fileLists{1};
            elseif nLists>1
                combinedList = union(fileLists{1},fileLists{2},'stable');
                if nLists>2
                    for k = 3:nargin
                        combinedList = union(combinedList,varargin{k},'stable');
                    end
                end
            end
            
        end
        
        %# remove files from master list 
        function newList = mRemoveFromFileList(masterList,remList)
            newList = setdiff(masterList,remList,'stable');
        end
        
        %# get filenames from filepaths list (short names) with or without ext
        function filenames = mGetShortFile(filepaths,keepext)
            filenames = {};
            
            if iscell(filepaths) % keep cell
                
                npaths = length(filepaths);
                if npaths==0, return; end;
                
                filenames = cell(npaths,1);
                
                for k = 1:npaths
                    filenames(k) = {AUXBackupCopy.mSingleShortFile(filepaths{k},keepext)};
                end
            elseif ischar(filepaths) % keep char
                filenames = AUXBackupCopy.mSingleShortFile(filepaths,keepext);
            else
                disp('Input not a valid type.');
            end
        end
        
        %# helper to the above function 
        function shortfile = mSingleShortFile(fullfilepath,keepext,varargin)
            [~,fname,fext] = fileparts(fullfilepath);

            % check if empty of n/a
            if ~AUXBackupCopy.mIsFilpath(fullfilepath)
                if isempty(varargin)
                    shortfile = fullfilepath;
                else
                    % call function
                    switch varargin{1}
                        case 'call_func'
                            defaultFcn = @(varargin) ones(1);
                            %eval(['curCond  = defaultFcn(1);']);
                            shortfile = defaultFcn;
                        otherwise
                            % not available
                    end
                end
                return;
            end
            
            if keepext
                shortfile = [fname,fext];
            else
                shortfile = fname;
            end
        end
        
        %#  check if is a filepath
        function result = mIsFilpath(fullfilepath)
            mTestFilepath = @(fpath) isempty(fpath) || strcmp(fpath,'n/a');

            if ischar(fullfilepath)
                result = ~mTestFilepath(fullfilepath);
            elseif iscell(fullfilepath)
                result = ~cellfun(mTestFilepath,fullfilepath); 
            else
                result = false;
            end
            
        end
        
        %# get all the files from a directory
        function dirfiles = mGetDirectoryFiles(dirpath)

            dirfiles = {};
            if exist(dirpath,'dir')==7
                % filenames  = arrayfun(@(s) s.name,dirFiles,'unif',0);
                % validFiles = arrayfun(@(s) ~s.isdir,dirFiles);
                
                % get the task directory files
                dirFiles_  = dir(dirpath);
                
                dirfiles   = {dirFiles_.name}';
                validFiles = ~cell2mat({dirFiles_.isdir}');
                
                % only keep valid files names
                dirfiles   = dirfiles(validFiles);
            end
        end
        
        %# check if files exist
        function fexist = mCheckFilesExist(filepaths)
            fexist = [];
            if iscell(filepaths)
                npaths = length(filepaths);
                if npaths==0, return; end;
                
                fexist = false(npaths,1);
                
                for k = 1:npaths
                    fexist(k) = exist(filepaths{k},'file')==2;
                end
                
            elseif ischar(filepaths)
                fexist = exist(filepaths,'file')==2;
            else
                disp('Input not a valid type.');
            end
        end
        %tskFile = 'C:\Users\dowdallj\Documents\MATLAB\blah.m';
        %[tskpath,f,e] = fileparts(tskFile);
        
        
        %# check if file is in task directory 
        function result = mFileIsInTaskDirectory(TaskFile,filepaths)
            result = [];
            [tskpath,~,~] = fileparts(TaskFile);
       
            if iscell(filepaths)
                npaths = length(filepaths);
                if npaths==0, return; end;
                
                result = false(npaths,1);
                
                for k = 1:npaths
                    [fpath,~,~] = fileparts(filepaths{k});
                    result(k) = isequal(tskpath,fpath);
                end
                
            elseif ischar(filepaths)
                [fpath,~,~] = fileparts(filepaths);
                result = isequal(tskpath,fpath);
            else
                disp('Input not a valid type.');
            end
            
        end
        
        %# check if file is in search path 
        function result = mFileIsInSearchPath(filepaths)
            result = [];
            % get current search paths 
            sPaths = regexp(path,';','split')';
            
            if iscell(filepaths)
                npaths = length(filepaths);
                if npaths==0, return; end;
                
                result = false(npaths,1);
                
                for k = 1:npaths
                    [fpath,~,~] = fileparts(filepaths{k});
                    result(k) = any(strcmp(sPaths,fpath));
                end
                
            elseif ischar(filepaths)
                [fpath,~,~] = fileparts(filepaths);
                result = any(strcmp(sPaths,fpath));
            else
                disp('Input not a valid type.');
            end
        end

        %# copy file(s)
        function success = mCopyFile(src_filepaths,dest_filepath)
            success = [];
            fcopyfile = @(src,dst) copyfile(src,dst,'f'); %#ok<*NASGU,*ASGLU>

            if ischar(src_filepaths)
                [success,MESSAGE,MESSAGEID] = fcopyfile(src_filepaths,dest_filepath);
            elseif iscell(src_filepaths)
                success = cellfun(@(src) fcopyfile(src,dest_filepath), src_filepaths);
            end
        end
        
        %# move file(s)
        function success = mMoveFile(src_filepaths,dest_filepath)
            success = [];
            fmovfile = @(src,dst) movfile(src,dst,'f'); %#ok<*NASGU,*ASGLU>

            if ischar(src_filepaths)
                [success,MESSAGE,MESSAGEID] = fmovfile(src_filepaths,dest_filepath);
            elseif iscell(src_filepaths)
                success = cellfun(@(src) fmovfile(src,dest_filepath), src_filepaths);
            end
        end
        
        %# 
        %function mDeleteFile(src_filepaths,dest_filepath) 
        %end

    end

end

