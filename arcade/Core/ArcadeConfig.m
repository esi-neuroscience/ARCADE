classdef ArcadeConfig
    % ARCADECONFIG - Class for all ARCADE configuration parameters
    %
    %
    %
    % PROPERTIES
    % ----------
    %  BackgroundRGB : 24-bit [r g b] background color during task
    %  BackupSettings :
    %  ControlScreen : path to ControlScreen executable in ARCADE/ControlScreen
    %  DaqServer : path to DaqServer executable in ARCADE/DaqServer
    %  DistanceToScreen : subject distance from screen (cm)
    %  EditableVariables
    %  EventMarker
    %  Experiment
    %  Experimenter
    %  EyeServer : path to EyeServer executable in ARCADE/EyeServer
    %  Files : struct with paths to additional files
    %        .UserAdded : cell array of files to be copied to backup folder
    %        .EventMarkers : ?
    %        .BlockSelection : function for selecting the next block
    %        .ConditionSelection : function for selecting the next condition
    %  InitFunction : function to be run before first trial
    %  MaximumNumberOfTrials
    %  MonitorDiagonalSize
    %  MonitorRefreshRate
    %  MonitorResolution
    %  OtherExecutables : cell array of executables to be launched along ARCADE
    %  PauseRGB : 24-bit [r g b] background color during pause
    %  PixelsPerDegree
    %  ProjectOwner
    %  rngSeed : seed of random number generator
    %  rngGenerator : type of random number generator
    %  Session
    %  StimServer : path to StimServer executable in ARCADE/StimServer
    %  Subject : name of subject
    %  TrialErrorLegend : 10 element cell array with trialerror labels (0-9)
    %  taskFile
    %  filepaths
    %
    % METHODS
    % -------
    %  save(filename, varargin) : store configuration parameters in .mat file
    %  struct : convert class instance to struct
    %
    %
    
    
    properties
        BackgroundRGB = [128 128 128]; % 24-bit [r g b] background color during task
        BackupSettings
        ControlScreen = 'MatlabControlScreen.bat';
        DaqServer
        DistanceToScreen
        EditableVariables
        EventMarker
        Experiment
        Experimenter
        EyeServer
        Files = struct('UserAdded', {''}, ...
            'EventMarkers', {''}, ...
            'BlockSelection', {''}, ...
            'ConditionSelection', {''})
        InitFunction
        MaximumNumberOfTrials
        MonitorDiagonalSize
        MonitorRefreshRate
        MonitorResolution
        OtherExecutables
        PauseRGB = [128 128 128]
        PixelsPerDegree
        ProjectOwner
        rng
        Session
        StimServer = 'StimServer.exe';
        Subject
        TrialErrorLegend = cell(1,10);
        taskFile
        filepaths = struct('Backup', {''}, 'Behaviour', {''}, 'Session', {''})
    end
    
    properties ( Dependent = true )
        sessionName
    end
    
    methods
        function obj = ArcadeConfig(cfg)
            if nargin == 1 && isstruct(cfg)
                fields = fieldnames(cfg);
                for iField = 1:length(fields)
                    % leave fields set to 'None' empty
                    if strcmp(cfg.(fields{iField}), 'None')
                        cfg.(fields{iField}) = [];
                    end
                    obj.(fields{iField}) = cfg.(fields{iField});
                end
            end
        end
        
        function save(obj, filename, varargin)
            if nargin < 2
                if ~isempty(obj.taskFile)
                    [~, shortTaskFile, ~] = fileparts(obj.taskFile);
                else
                    shortTaskFile = '';
                end
                filename =  [obj.Subject '_' obj.Experiment '_' shortTaskFile '_cfg.mat'];
            end
            cfg = obj.struct();
            save(filename, '-struct', 'cfg', varargin{:})
        end
        
        function obj = set.EyeServer(obj, exe)
            obj.assert_exe_exists('EyeServer', exe)
            obj.EyeServer = exe;
        end
        
        function obj = set.DaqServer(obj, exe)
            obj.assert_exe_exists('DaqServer', exe)
            obj.DaqServer = exe;
        end
        
        function obj = set.StimServer(obj, exe)
            obj.assert_exe_exists('StimServer', exe)
            obj.StimServer = exe;
        end
        
        function obj = set.ControlScreen(obj, exe)
            obj.assert_exe_exists('ControlScreen', exe)
            obj.ControlScreen = exe;
        end
        
        function obj = set.taskFile(obj, taskFile)
            if ~isempty(taskFile)
                assert(exist(taskFile, 'file') == 2, ...
                    'Taskfile %s not found', taskFile)
                obj.taskFile = taskFile;
            end
        end
        
        function obj = set.BackgroundRGB(obj, rgb)
            obj.BackgroundRGB = obj.handle_color(rgb);
        end
        
        function obj = set.PauseRGB(obj, rgb)
            obj.PauseRGB = obj.handle_color(rgb);
        end
        
        function cfg = struct(obj)
            props = properties(obj);
            emptyCells = cell(length(props), 1);
            cfg = cell2struct(emptyCells, props);
            for iProp = 1:length(props)
                cfg.(props{iProp}) = obj.(props{iProp});
            end
        end
        
        function obj = set.InitFunction(obj, func)
            if ~isempty(func)
                if ischar(func)
                    func = str2func(func);
                end
                assert(isa(func, 'function_handle'), ...
                    'Init function must be a function handle')
            end
            obj.InitFunction = func;
        end
        
        function name = get.sessionName(obj)
            name = [obj.Subject '_' today '_' obj.Experiment, '_' obj.Session];
        end
        
        function obj = set.sessionName(obj, ~)
            
        end
        
        function obj = set.TrialErrorLegend(obj, errorLegend)
            if isstruct(errorLegend)
                if isfield(errorLegend, 'numInf')
                    errorLegend = rmfield(errorLegend, 'numInf');
                end
                fields = fieldnames(errorLegend);
                errorLegend = struct2cell(errorLegend);
                [fields, idx] = sort(fields);
                errorLegend = errorLegend(idx);                
            end
            assert(numel(errorLegend) == 10,...
                'Number of trial error legends must be 10 element cell array')
            obj.TrialErrorLegend = errorLegend;
        end
        
        
        
        function obj = set.Files(obj, files)
            assert(isstruct(files))
            fields = fieldnames(files);
            % replace old char options 'none', 'n/a' with empty values
            for iField = 1:length(fields)
                value = files.(fields{iField});
                if strcmp(value, 'n/a') || strcmp(value, 'none')
                    value = '';
                end
                obj.Files.(fields{iField}) = value;
            end
        end
        
    end
    
    methods ( Access = private, Static = true )
        function assert_exe_exists(server, exe)
            if ~strcmp(exe, 'None') && ~isempty(exe)
                assert(exist(fullfile(arcaderoot, 'arcade', server, exe), 'file') == 2, ...
                    '%s %s not found', server, exe)
            end
        end
        function color = handle_color(color)
            assert(numel(color) == 3)
            assert(all(color>=0) && all(color<=255))
            color = color(:)';
        end
    end
end