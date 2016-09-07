classdef (Sealed) SGLFilepathManager < handle
    % [SINGLETON] Filepaths - singleton class
    % holds all the filepaths for the project
    % and allows access from any function
    
    % *replaces AUXFilePaths*
    
    
    %------------------------------------------%
    %  2.5.2016 - Jarrod, wrote class
    %  3.5.2016 - Jarrod, added pathProcessLaunch
    % 16.5.2016 - Jarrod, 
    %   - debugging
    
    %# filepaths 
    properties (SetAccess = immutable)
        pathProcessLaunch     % ...[ver]\displayServer\ProcessLaunch
        pathDisplayServer     % ...[ver]\displayServer
        pathWholeProjectDir   % ...[ver]\
        pathTaskDirectory     % ...[ver]\Tasks
        pathSessionLog        % ...[ver]\sessionLog
        pathErrorLog          % ...[ver]\errorLog
    end
    
    %properties 
    %    % set once 
    %   userTaskDir        % ...\Tasks\[task]
    %   userErrorDir       % ...\errorLog\[date]
    %   userSessionLogDir  % ...\sessionLog\[subject]\[task]\[session]
    %end
    
    
    %# constructor 
    methods (Static)
        function this = launch
            persistent thisObj
            if isempty(thisObj) || ~isvalid(thisObj)
                thisObj = SGLFilepathManager;
            end
            this = thisObj;
        end
    end
    
    methods (...
            Access = private,...
            Hidden = true)
        
        %# constructor
        function this = SGLFilepathManager
            % initialize filepaths 
            pat = filesep;
            % [user path] \displayServer_[ver]\displayServer\ProcessLaunch\SGLFilepaths
            pathSplit = regexp(mfilename('fullpath'),pat,'split');

            % this class lives in ...\displayServer_[ver]\displayServer\ProcessLaunch 
            this.pathProcessLaunch   = fullfile(pathSplit{1:end-1}); 
            this.pathDisplayServer   = fullfile(pathSplit{1:end-2}); 
            this.pathWholeProjectDir = fullfile(pathSplit{1:end-3}); 
            this.pathTaskDirectory   = fullfile(pathSplit{1:end-3},'Tasks'); 
            this.pathSessionLog      = fullfile(pathSplit{1:end-3},'sessionLog'); 
            this.pathErrorLog        = fullfile(pathSplit{1:end-3},'errorLog'); 

        end
    end
end