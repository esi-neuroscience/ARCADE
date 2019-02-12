classdef ArcadeConfig
    
    
    properties
        BackgroundRGB
        BackupSettings
        ControlScreen = 'MatlabControlScreen.bat';
        DaqServer
        DistanceToScreen
        EditableVariables
        EventMarker
        Experiment
        Experimenter
        EyeServer
        Files
        InitFunction
        MaximumNumberOfTrials
        MonitorDiagonalSize
        MonitorRefreshRate
        MonitorResolution
        OtherExecutables
        PauseRGB
        PixelsPerDegree
        ProjectOwner
        Session
        StimServer = 'StimServer.exe';
        Subject
        TrialErrorLegend
        taskFile
        filepaths
    end
    
    methods
        function obj = ArcadeConfig(cfg)
            if nargin == 1 && isstruct(cfg)
                fields = fieldnames(cfg);
                for iField = 1:length(fields)
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