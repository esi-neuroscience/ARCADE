classdef SPCServerProc < AUXDiary
    % [SUPERCLASS] SERVER PROCESS
    
    
    % INHERITANCE:
    %   SPCServerProc  <  ...
    %        AUXDiary < handle 
    
    % METHODS: 
    %   + mCreateDiary
    %   + mWriteToDiary
    %   + mFlushDiary 
    

    %------------------------------------------%
    %  2.5.2016 - Jarrod, wrote class
    % 16.5.2016 - Jarrod, 
    %   - debugged class 
    %   - moved diary methods to AUXDiary class
    
    properties (AbortSet = true)
        FPATH % filepath manager object
    end
   
    
    methods (Static)
        function this = SPCServerProc
            % create filepath manager, 
            % and set filepaths 
            this.mSetProjectFilepaths;
        end
    end
    
    methods
        %# mSetProjectFilepaths
        % 1. create filepath manager
        % 2. add project filepaths 
        function mSetProjectFilepaths(this)
            % create instance of filepaths
            fpath = SGLFilepathManager.launch;
            % add filepaths to matlab
            addpath(genpath(fpath.pathWholeProjectDir)); 
            this.FPATH = fpath;
        end
        
        %# create this process diary
        function mCreateProcessDiary(this, proc)
            diaryFile = sprintf('log_%s_%s.txt',proc,datestr(now,'HHMM'));
            diaryDir  = fullfile(this.FPATH.pathErrorLog, datestr(now,'yy.mm.dd'));
            this.mCreateDiary(diaryFile, diaryDir);
        end
        
    end
    
    methods (Static = true)
        %# randomize RNG
        function mInitilazeRandomNumberGenerator
            % initialize random number generator
            % shuffle RNG
            fprintf('Matlab Random Number Generator shuffled...\n'); 
            rng('shuffle');
            thisRNG = rng;
            fprintf(...
                'RNG: %s, SEED: %s\n',...
                thisRNG.Type,...
                int2str(thisRNG.Seed));
            % ensure command line is writtent to txt file 
            %this.mFlushDiary; 
        end
        
        %# print error log header 
        function mPrintErrorLogHeader(procName)
            
            %procName = 'Control Screen';
            headerAsterisk = '************************************\n';
            % get some details about this run 
            dateTimeString      = datestr(now,'dd-mmm-yyyy HH:MM:SS');
            matlabVersionString = version();
            userNameString      = getenv('username');
            computerNameString  = getenv('computername');
            
            % PRINT TO COMMAND LINE -> written to log file 
            fprintf(headerAsterisk)
            fprintf('Launching... %s process\n', procName);
            % date and time 
            fprintf('%s\n', dateTimeString);
            % matlab version 
            fprintf('MATLAB version: %s\n', matlabVersionString); 
            % user name 
            fprintf('User name: %s\n',  userNameString); 
            % matlab version 
            fprintf('Computer name: %s\n',  computerNameString); 
            % ARCADE version
            fprintf('ARCADE version: %s', arcadeVersion)
            % end information header 
            fprintf(headerAsterisk);
            % ensure command line is writtent to txt file 
            %this.mFlushDiary; 
        end
    end
    
    methods
        function delete(this)
            % delete filepath manager
            delete(this.FPATH);
            delete@AUXDiary(this);  % call super class delete
        end
    end
end

