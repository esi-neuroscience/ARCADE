classdef MSConfig < AUXUIControlFunctions
    % [MAINSCREEN] CONFIG
    % predominately for setting up cfg functions and related
    % abstract def: cfg, task file, and cfg file 
    
    % INHERITANCE:
    %   MSConfig < ...
    %       AUXUIControlFunctions < handle
    
    
    
    % when the user selects a task file
    % -> get task file name, set task button with filename
    % -> check if there exists a cfg, if not return
    % -> else load cfg file
    % if cfg changes, listeners call cfg edit
    % user selects a cfg -> get filepath for cfg, set button with cfg filename
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote initial class
    % 26.2.2015 - Jarrod, fixed cfgFile bug 
    %  3.3.2015 - Jarrod, fixed cfgFile bug 
    % 11.3.2015 - Jarrod, Large revision changed the way the config is loaded/created
    % 15.4.2015 - Jarrod, did some minor cleaning up of the text 
    % 16.4.2015 - Jarrod, mainly added methods
    % - added from cfg set/get field methods
    % - added methods to set the cfg file name 
    % - consolidated some file selector methods into one method
    % - added error check method
    % 20.4.2015 - Jarrod, 
    % - added default values to uicontrol objects in cfg
    % - modified error check function 
    % - changed the way a field is checked when loading the config file 
    % 24.4.2015 - Jarrod, mSelectTaskAssociatedFile file bug
    %  3.5.2015 - Jarrod, added filetype to mSelectTaskAssociatedFile
    %  6.7.2015 - Jarrod, added a temporary bug fix for tables (no Style property)
    % 14.7.2015 - Jarrod, 
    % - struct2array() appears not to be toolbox dependent. Removed dependency on this function. 
    % 21.4.2016 - Jarrod, added some documentation/notes
    % 29.4.2016 - Jarrod, added some documentation
    
    
    properties (...
            Abstract      = true,...
            AbortSet      = true,...
            SetObservable = true)
        taskFile  % task file fullfilepath
        cfgFile   % cfg file fullfilepath
        cfg
    end
    

    properties (Access = protected)
        cfgExt      = '_cfg'; % cfg file extension
        %cfgParam    = 'cfg_';     % Tag prefix indicating it is a cfg field
        cfgElements = [];
    end
    
    methods (Static)
        %# constructor 
        function this = MSConfig
        end
    end
    
    methods (Sealed = true)
        %# set general set/get functions (to create cfg) in the appropriate uicontrols
        function mSetGeneralCfgSetGetFunctions(this)
            %--------------------------------------%
            % - get figure handles
            % - find the relevant uiobjects
            % - get the feildnames, and handles for the cfg struct
            % - add properties to uiobjects
            % - add general set/get functions
            % - add general callback
            %--------------------------------------%

            handles = guihandles(this.hfig);
            
            % cfgHandles_cntls = findobj(struct2array(handles),...
            %   'flat', 'Type', 'uitable',...
            %   '-or', 'Type', 'uicontrol',...
            %   '-regexp','Tag','^?cfg_');
            
            
            % Convert structure to cell
            %c = struct2cell(s);
            
            % Construct an array
            %a = [c{:}];
            
            % UICONTROLS
            cfgHandles_cntls = findobj(cell2mat(struct2cell(handles)),...
                'flat', 'Type', 'uicontrol','-regexp','Tag','^cfg_');
            % UITABLES
            cfgHandles_tbles = findobj(cell2mat(struct2cell(handles)),...
                'flat', 'Type', 'uitable', '-regexp','Tag','^cfg_');
            
            % fieldnames (cfg Tag Paths)
            cfgFields_cntls = arrayfun(@(h) this.mReplaceChar(get(h,'Tag'),'_','.'),cfgHandles_cntls,'unif',0);
            cfgFields_tbles = arrayfun(@(h) this.mReplaceChar(get(h,'Tag'),'_','.'),cfgHandles_tbles,'unif',0);
            
            % --- combined -----
            cfgHandles = cat(1,cfgHandles_cntls,cfgHandles_tbles);
            cfgFields  = cat(1,cfgFields_cntls, cfgFields_tbles);
            
            % cfg fieldnames (cell), ui handles (cell)
            this.cfgElements = {cfgFields,cfgHandles}; % store for reference later
            % create struct by getting current value which initializes the structure
            
            % ---- add properties -----
            % UICONTROL/UITABLE
            msp_get = arrayfun(@(obj) schema.prop(obj, 'getPropertyFcn', 'mxArray'), cfgHandles, 'unif',0); %#ok<*NASGU>
            msp_set = arrayfun(@(obj) schema.prop(obj, 'setPropertyFcn', 'mxArray'), cfgHandles, 'unif',0);
            msp_def = arrayfun(@(obj) schema.prop(obj, 'uiDefaultValue', 'mxArray'), cfgHandles, 'unif',0);
            
            % cfgTagPath
            %msp_cfg = arrayfun(@(obj) schema.prop(obj, 'cfgTagPathFcn', 'mxArray'), cfgHandles, 'unif',0);
            
            % UITABLE
            msp_ind = arrayfun(@(obj) schema.prop(obj, 'selectedIndices','mxArray'), cfgHandles_tbles, 'unif',0);
            
            % specific set/get depending on the UICONTROL Style
            %hStyle = get(cfgHandles_cntls,'Style');
            hStyle = arrayfun(@(cntls) get(cntls,'Style'),cfgHandles_cntls,'unif',0);
            
            
            % ---- general Set/Get functions -----
            % UICONTROL General Set/Get/Callback
            for k = 1:length(hStyle)
                
                [fcnGetFcn,fcnSetFcn] = this.mGetUIControlSetGetFunc(hStyle{k},cfgHandles_cntls(k));
                
                set(cfgHandles_cntls(k), 'getPropertyFcn', fcnGetFcn); % general get fcn
                set(cfgHandles_cntls(k), 'setPropertyFcn', fcnSetFcn); % general set fcn
                % set general callback (hObj, evt, cfg fieldname)
                %set(cfgHandles_cntls(k), 'Callback', @(hObj,evt) disp(cfgFields_cntls{k}));
                
                % Frames have no Callbacks associated with them
                if strcmpi(hStyle{k},'frame')
                    
                    %mGeneralCallback(this,hObj,evt,field)
                    %fcnCallback = @(hObj,evt) this.mGeneralCallback(cfgHandles_cntls(k),[],cfgFields_cntls{k});
                    fcnCallback = @(hObj,evt) this.mGeneralCallback(cfgHandles_cntls(k),evt,cfgFields_cntls{k});
                    % callback depends on the specific java object
                    jsxObj = get(cfgHandles_cntls(k),'UserData');
                    % set callback of Java object, with specific callback (depends on java object)
                    set(jsxObj{3},jsxObj{4},fcnCallback);
                    
                else
                    set(cfgHandles_cntls(k), 'Callback',@(hObj,evt) this.mGeneralCallback(hObj,evt,cfgFields_cntls{k}));
                end
            end
            
            % UITABLE General Set/Get
            arrayfun(@(h) set(h, 'getPropertyFcn',...
                @(hObj) get(hObj,'data')), cfgHandles_tbles);
            arrayfun(@(h) set(h, 'setPropertyFcn',...
                @(hObj,data) set(hObj,'data',data)), cfgHandles_tbles);
            % UITABLE selected indicies
            arrayfun(@(h) set(h, 'CellSelectionCallback',...
                @(hObj,evt) set(hObj,'selectedIndices',evt.Indices)), cfgHandles_tbles);
            % Cell Edit Callback
            % here is a source of an error for uitables not having a style property
            arrayfun(@(h,fn) set(h, 'CellEditCallback',...
                @(hObj,evt) this.mGeneralCallback(hObj,evt,fn{1})), cfgHandles_tbles, cfgFields_tbles);
            
            %arrayfun(@(h,fn) set(h, 'CellEditCallback',...
            %    @(hObj,evt) disp(fn{1})), cfgHandles_tbles, cfgFields_tbles);
            
            %------------------------------------------------%
            %this.mCreateCfgStruct;
            
        end

        
        %# UIControl style specific get/set functions
        function [fcnGetFcn,fcnSetFcn] = mGetUIControlSetGetFunc(this,hStyle,hCntrl)
            
            switch hStyle
                case {'togglebutton', 'checkbox',...
                        'radiobutton',  'slider'}
                    % get the Value and set the Value
                    fcnGetFcn = @(hObj) get(hObj,'Value');
                    fcnSetFcn = @(hObj,value) set(hObj,'Value',value);
                %case {'listbox','popupmenu'}
                    % get/set the Value (selected) depending on the String
                    % return string based on value
                    %fcnRetrieveString = @(sStr,sVal) sStr{sVal};
                    %fcnGetFcn = @(hObj) fcnRetrieveString(get(hObj,'String'),get(hObj,'Value'));
                   % fcnGetFcn = @(hObj) fcnRetrieveString(get(hObj,'String'),get(hObj,'Value'));
                    
                    % return value based on string
                   % fcnSetFcn = @(hObj,inText) set(hObj,'Value', find(strcmp(inText,get(hObj,'String'))));
                case {'edit','pushbutton','text','listbox','popupmenu'}
                    % **listbox callback is only executed on double clicks**
                    % get the String and set the String
                    
                    if strncmp(get(hCntrl,'Tag'),'cfg_Files_',9) % if files list
                        [fcnGetFcn, fcnSetFcn] = this.mGetFileSelectionSetGetFcns;
                    else
                        fcnGetFcn = @(hObj) get(hObj,'String');
                        fcnSetFcn = @(hObj,inText) set(hObj,'String',inText);
                    end
                    
                case {'frame'}
                    % frames are used to position java objects
                    % position a java object here
                    % the java object is stored in the UserData 
                    % set/get function is unique to the java object
                    % all java classes will have a schema prop that gives
                    % thir set/get functions
                    % this is retrieved from 
                    
                    % create an instance of a java object
                    % associated with a frame
                    
                    % after the figure is created
                    % add the java objects
                    
                    % retrieve the set/get from the UserData
                    UserData = get(hCntrl,'UserData');
                    if ~isempty(UserData)
                        fcnSetFcn = UserData{1};
                        fcnGetFcn = UserData{2};
                    else
                        disp('Java Object Set/Get functions not set.');
                    end
                    
                    
                otherwise
                    fcnGetFcn = [];
                    fcnSetFcn = [];
            end
            
        end
        
        %# get file selection functions 
        function [fcnGetFcn, fcnSetFcn] = mGetFileSelectionSetGetFcns(this)
            % get the string from the 
            
            fcnGetFcn = @(hObj) get(hObj,'String');
            % set short filename without file ext
            fcnSetFcn = @(hObj,filepath) set(hObj,'String',this.mGetShortFile(filepath,false));
        end
 
        %# Create CFG structure
        function mCreateCfgStruct(this)

            cfgTagPaths = this.cfgElements{1};
            cfgUIHandle = this.cfgElements{2};
            
            nElements = length(cfgTagPaths);

            % get the generalized functions
            getFuncs = get(cfgUIHandle,{'getPropertyFcn'});
            % get default values
            cfgValues = cellfun(@(h,func) func(h), mat2cell(cfgUIHandle,ones(length(cfgUIHandle),1)), getFuncs, 'unif',0);

            for k = 1:nElements
                this.mSetFieldCfg(cfgTagPaths{k}, cfgValues{k})
            end
            drawnow;
        end
        
        %# set default value 
        % should be called after all uicontrol objects have been created 
        function mSetDefaultValue(this)
            cfgUIHandle = this.cfgElements{2};
            
            % get the generalized functions
            getFuncs = get(cfgUIHandle,{'getPropertyFcn'});
            %setFuncs = get(cfgUIHandle,{'setPropertyFcn'});
            
            % get the current property and set that as the default value 
            nElements = length(cfgUIHandle);
            
            for k = 1:nElements
                defaultValue = getFuncs{k}(cfgUIHandle(k));
                set(cfgUIHandle(k), 'uiDefaultValue', defaultValue);
            end
            drawnow;
        end
        
        
        %-------------------------------------%
        %            CALLBACKS 
        
        %# UIObject - general callback function
        function mGeneralCallback(this,hObj,~,field)
            % ------ gets the data, and sets it as it is -------
            % get user input & convert to appropriate value
            fcnGetUIInput = get(hObj,'getPropertyFcn'); % allows a unique/general function
            uiinput       = fcnGetUIInput(hObj);        % has all params, only needs object handle
            
            this.mSetFieldCfg(field, uiinput);
            
            % frames are used for marking the position/location 
            % of a java object in the gui, set the value of the frame
            % on the callback to signal that the java object callback has
            % been called
            Z = get(hObj);
            if isfield(Z,'Style')
                switch Z.Style
                    case 'frame'
                        % if the spinner should change another object on
                        % callback, a listner on this event can help with that
                        
                        %disp('Frame callback called');
                        set(hObj,'Value',~get(hObj,'Value'));
                    otherwise
                        % ignore
                end
            end
            drawnow;
        end
        
        %# Set a Task Associated file 
        % -> Task file 
        % -> Condition, Block selection files
        % -> EventMarker file 
        function mSelectTaskAssociatedFile(this,hObj,~,fileStr,fileType,prop,cfgFieldPath,activate,notifyEvt)
            %--------------------------------%
            % Task associated file 
            % all should be .m files
            %--------------------------------%
            % INPUTS:
            % fileStr   -> file string
            % prop      -> class property to assign filepath to 
            % cfgPath   -> fieldname of config file to assign file path to 
            % actvate   -> objects to enable on success
            % notifyEvt -> notify event
            
            msg      = ['Select ',fileStr,' File'];
            if isempty(fileType), fileType = '*.m'; end;
            fullfilepath = this.mFilePrompt(fileType,msg,'open');
            
            if ~isempty(fullfilepath)
                % if the file is the condition/block selection file
                % check if it is in the search path or task directory
                if ~isempty(cfgFieldPath)  % set field of cfg
                    [result,~] = this.mGeneralErrorCheck(hObj,cfgFieldPath,fullfilepath);
                    if ~result
                        disp([cfgFieldPath,' file not set.']);
                        return;
                    end
                end
                
                % get simplified name
                [~,fname,~] = fileparts(fullfilepath);
                set(hObj,'String',fname);  % set button string
                
                if ~isempty(cfgFieldPath)  % set field of cfg
                   this.mSetFieldCfg(cfgFieldPath, fullfilepath)
                end
                if ~isempty(activate)      % activate UI objects
                    arrayfun(@(h) set(h,'Enable','on'),activate);
                end
                if ~isempty(prop)          % set property of object
                    this.(prop) = fullfilepath;  
                end
                if ~isempty(notifyEvt)     % notify event 
                    notify(this,notifyEvt);
                end
                
            end
            drawnow;
        end
        
        %# set the text of the cfg file load button
        % called by a listener to the cfg property in MainScreen
        function mSetCfgButtonText(this,hObj,evt,btnCfg)
            % set cfg button name
            %[~,fname,ext] = fileparts(this.cfgFile);
            fname = this.mGetShortFile(this.cfgFile,false);
            set(btnCfg,'String',fname);
            %set(btnCfg,'Enable','on'); % enable load button
            drawnow;
        end
        
        %-------------------------------------%
        %         SAVE CFG FILE
        
        %# save cfg file button callback
        % is enabled by any change to the cfg
        function mSaveCfgFile(this,hObj,~)
            % cfg loaded,
            %   1. shares name with task
            %   2. does not share name with task
            % cfg no loaded,
            %   - save as task name
            % no cfg file, no task file
            
            % usave button activty because of change in default cfg
            % allow user to save the cfg, but prompt for a save location
            
            cfgFile  = this.cfgFile; %#ok<*PROP>
            taskFile = this.taskFile;
            
            while 1
                [result,cfgFile] = this.mCheckCfgFile(cfgFile,taskFile);
                %  0 = means repeat loop
                %  1 = overwrite
                % -1 = abort/cance;l
                if (result~=0), break; end;
            end
            
            if result==1
                cfg = this.cfg;
                %save(fullfilepath,'cfg');
                % Save the fields of a structure as individual variables:
                save(cfgFile,'-struct','cfg');
                set(hObj,'Enable','off'); % upon successful save
                this.cfgFile = cfgFile;
                
                disp(['Saved cfg file here: ', cfgFile]);
            end
            
        end
        
        %# check if cfg filename is okay to save
        function [result,cfgFile] = mCheckCfgFile(this,cfgFile,taskFile)
            cases = [...
                isempty(cfgFile) &&  isempty(taskFile),...
                isempty(cfgFile) && ~isempty(taskFile),...
                ~isempty(cfgFile)];
            
            result = 0;
            
            switch find(cases)
                case 1
                    % cfg does not exist, taskfile does not exist
                    %cfgFile = this.mSelectNewSaveFile(['Untitled',this.cfgExt,'.mat']);
                    cfgFile = this.mSelectNewSaveFile('Untitled');
                    if isempty(cfgFile), result = -1; end;
                    return;
                case 2
                    % cfg does not exist, taskfile does exist
                    % assign the task file name
                    taskFile = this.mSetFileExt(taskFile,'.mat');
                    cfgFile  = this.mAppendRemoveCfgExt('append',taskFile);
                    
                    %[tskPath,tskName,~] = fileparts(taskFile);
                    %cfgFile = fullfile(tskPath,[tskName,this.cfgExt,'.mat']);
                    return;
                case 3
                    % cfg does exist
                    if exist(cfgFile,'file')==2
                        %[~,fname,~] = fileparts(cfgFile);
                        %fileparts('H:\projects\DisplayServer_tasks\DisplayServer\Version_beta\GUIs\classes.m')
                        
                        % short file, without file ext
                        cfgFileShort = this.mAppendRemoveCfgExt('remove',this.mGetShortFile(cfgFile,false));
                        
                        
                        % ask user if he/she wants to proceed
                        request = questdlg(...
                            {['There already exists a cfg file ', cfgFileShort,'.'],'',...
                            'Would you like to overwrite the file?'},...
                            'Warning!', 'Yes','No','Rename','No');
                        
                        if strcmp(request,'Rename')
                            cfgFile = this.mSelectNewSaveFile(cfgFileShort);
                            if ~isempty(cfgFile), result = 1; end;
                            return;
                        elseif strcmp(request,'No') || isempty(request)
                            result = -1; % abort
                            return;
                        end
                        
                    end
            end
            % make it hear if
            % -> filename is okay to write
            % -> user requests overwrite
            result = 1;
        end
        
        %# select a new behavioural file
        function cfgFile = mSelectNewSaveFile(this,sugTitle)
            
            msg      = 'Save Settings file';
            fileType = [this.cfgExt,'.mat']; % config file ext
            fullfilepath = this.mFilePrompt(['*',fileType],msg,'save',sugTitle);
            
            cfgFile = [];
            
            if ~isempty(fullfilepath)
                % user has selected a filename for the cfg
                % ensure that the name has _cfg appended to the filename
                
                % remove _cfg if it exists
                cfgFile = this.mAppendRemoveCfgExt('remove',fullfilepath);
                % append _cfg
                cfgFile = this.mAppendRemoveCfgExt('append',cfgFile);
                % ensure cfg has correct file ext
                cfgFile = this.mSetFileExt(cfgFile,'.mat');
            end
        end
        
        %-------------------------------------%
        %         LOAD CFG FILE
        
        %# check cfg
        % called when the taskfile is set
        function mCheckForCfg(this,hobj,dat,hSaveBtn,notifyEvt)
            %taskFilepath = 'H:\projects\DisplayServer_tasks\DisplayServer\Version_beta\default.h';
            % files = dir([filepath,'\*_cfg.mat']);
            % first find file of the appropriate name,
            % second look for any file
            taskFilepath = this.taskFile;
            taskFilepath = this.mSetFileExt(taskFilepath,'.mat');
            cfgFile = this.mAppendRemoveCfgExt('append',taskFilepath);
            %cfgFile = this.mSetFileExt(cfgFile,'.mat');
            %[filepath,fname,ext] = fileparts(taskFilepath);
            % find file named after the task file
            %cfgFile = fullfile(filepath,[fname,'_cfg.mat']);
            
            %cfgFile = [filepath,'\',fname,'_cfg.mat'];
            %files = dir(cfgFile);
            
            if exist(cfgFile,'file')==2
                disp(['Found cfg file: ', cfgFile]);
                this.cfgFile = cfgFile;
                notify(this,notifyEvt);
                % update gui
                %this.mUpdateCfgandGUI([],[]);
            else
                % no cfg, allow user to save with defaults
                % enable save cfg button
                set(hSaveBtn,'Enable','on');
            end
            drawnow;
        end
        
        
        %# update CFG and GUI
        % called by listener when the cfgFile property changes
        % can be changed by SetTaskFile, setCfgFile
        function mUpdateCfgandGUI(this,hObj,evt) %#ok<*INUSL,*INUSD>
            %----------------------------------------%
            % this function is called when the cfgFile is set
            % - set because user requested loading a cfg file
            % - user loaded a task file, and there was an appropriately
            %   named cfg in that directory
            % - user saved a cfg file that was not named
            
            % find common fields in loaded structure
            % -> update in the cfg struct
            % -> update in the GUI
            %----------------------------------------%
            
            cfgFile = this.cfgFile;
            % if cfg file exists, then load it
            if ~exist(cfgFile,'file')==2,
                warndlg('File does not exist.', 'Warning!', 'modal');
                return;
            end
            
            cfg     = load(cfgFile); % load cfg file
            currcfg = this.cfg;
            % fieldnames {1}, handles {2}
            cfgTagPaths = this.cfgElements{1};
            cfgUIHandle = this.cfgElements{2};
            
            % get the generalized set functions
            % fcnSetFuncs = get(cfgUIHandle,'setPropertyFcn');
            getSetFcn   = @(hUI) get(hUI,'setPropertyFcn');
            fcnSetFuncs = arrayfun(getSetFcn,cfgUIHandle,'unif',0);
            
            % try assign to cfg, and to GUI
            for k = 1:length(cfgTagPaths)

                % select this set function
                thisSetFcn = fcnSetFuncs{k};
                
                % 1. check if default, assign default if empty?
                % 2. else, check if valid input
                % - class should match default
                % - if file, file must exist/be accessible
                try
                    % get value from loaded cfg
                    value = eval(cfgTagPaths{k}); % this new config file
                catch ME
                    fprintf('Field %s missing in config file.\n', cfgTagPaths{k});
                    continue;
                end
                
                % error check and default check
                [result,newValue,errMsg] = this.mGeneralErrorCheck(cfgUIHandle(k),cfgTagPaths{k},value);
                
                if ~result
                    % value needs to be re-assigned
                    value = newValue;
                end
                
                try
                    % try to set value in cfg
                    err = 1;
                    this.mSetFieldCfg(cfgTagPaths{k},value);
                    
                    % try to update gui
                    err = 2;
                    eval('thisSetFcn(cfgUIHandle(k),value)');
                    
                catch
                    % if either one does not go through, retore to previous
                    prevValue = eval(['curr',cfgTagPaths{k}]);
                    this.mSetFieldCfg(cfgTagPaths{k},prevValue); % set cfg
                    eval('thisSetFcn(cfgUIHandle(k),prevValue)'); % set uicontrol
                    
                    disp(['Failed to load: ', cfgTagPaths{k},' ...']);
                    switch err
                        case 1
                            disp('Unable to set value to configuration structure');
                        case 2
                            disp('Unable to set value in GUI');
                    end
                end
            end
            drawnow;
            disp('Config file loaded...');
            notify(this,'cfgIsLoaded');
            
        end
        
        %# check if input value (from loaded cfg) is default value
        function [isDefault, defValue] = mCheckDefault(this, hObj,value)
            % 1 = is default
            % 0 = is not default
            
            %getFcn = get(hObj,'getPropertyFcn');
            defValue  = get(hObj,'uiDefaultValue');
            isDefault = isequal(value,defValue);
            
        end
        
        %# check input class type
        %function result mCheckInputClass(this,)
        %end
        
        
        %# Assign data to Config structure
        function mSetFieldCfg(this, cfgFieldPath, value)
            try
                eval(['this.',cfgFieldPath,'=value;']);
            catch
                disp(['Could not assign ',cfgFieldPath,' to config structure.']);
            end
        end
        
        %# get data to Config structure
        function value = mGetFieldCfg(this, cfgFieldPath)
            value = [];
            try
                eval(['value = this.',cfgFieldPath,';']);
            catch
                disp(['Could not get ',cfgFieldPath,' in config structure.']);
            end
        end
        %------------------------%
        %      HELPER FUNCS
        
        %# check if the cfg field is okay for assignment to GUI
        %
        function [result,newValue,errMsg] = mGeneralErrorCheck(this,cfgUIHandle,cfgFieldPath,cfgValue)
            % returns true, if value is okay to be assigned to GUI
            % if it is the default it is okay to be assigned to the GUI
            assignDefault = false; % flag
            
            result   = true; % assign to cfg as is
            newValue = [];   % no new value
            errMsg   = '';   % no error message
            
            % check if value is default value
            [isDefault, defaultValue] = this.mCheckDefault(cfgUIHandle,cfgValue);
            
            if isDefault
                errMsg = 'Is default value';
                return;
            end
            
            % else, not default value
            % then error check
            
            switch cfgFieldPath
                case 'cfg.Files.ConditionSelection'
                    % isempty
                    if isempty(cfgValue)
                        assignDefault = true;
                    else
                        % else check file is accessible
                        isokay = this.mCheckIfTrialSelectionFileIsAccessible('"Condition"',cfgValue);
                        if ~isokay
                            assignDefault = true;
                        end
                    end
                    
                case 'cfg.Files.BlockSelection'
                    % isempty
                    if isempty(cfgValue)
                        assignDefault = true;
                    else
                        % else check file is accessible
                        isokay = this.mCheckIfTrialSelectionFileIsAccessible('"Block"',cfgValue);
                        if ~isokay
                            assignDefault = true;
                        end
                    end
                    
                case 'cfg.Files.EventMarkers'
                    % isempty
                    if isempty(cfgValue)
                        assignDefault = true;
                    else
                        % this file does not need to be accessible, but it must exist
                        isokay = exist(cfgValue,'file')==2;
                        if ~isokay
                            this.mThrowWarningDialog('"Event Marker"');
                            assignDefault = true;
                        end
                    end
                    
                case 'cfg.Files.UserAdded'
                    if isempty(cfgValue)
                        assignDefault = true;
                    else
                        fexist = this.mCheckUserAddedFilesExist(cfgValue);
                        if any(~fexist)
                            result   = false;
                            newValue = cfgValue(fexist); % only keep those that exist
                        elseif all(~fexist)
                            assignDefault = true;
                        end
                    end
                otherwise
                    % not coded
            end
            
            % assign default if necessary
            if assignDefault
                % then assign default value
                result   = false;
                newValue = defaultValue;
                errMsg   = 'Value in config file cannot be empty';
            end
        end
        
        
        %# check if files are in task directory or matlab search path
        % necessary for the condition/block selection files to be called
        function result = mCheckIfTrialSelectionFileIsAccessible(this,fileType,filepath)
            
            %result = false;
            %if all(~this.mIsFilpath(filepath))
            
            %disp('Check files......');
            tskFile = this.taskFile; % get task file
            isTaskFileSet = ~isempty(tskFile) &&  this.mCheckFilesExist(tskFile);
            
            fileInTaskDir = false;
            if isTaskFileSet
                fileInTaskDir = this.mFileIsInTaskDirectory(tskFile,filepath);
            end
            
            fileDoesExist    = exist(filepath,'file')==2;
            fileInSearchPath = this.mFileIsInSearchPath(filepath);
            
            result = (fileInSearchPath || fileInTaskDir) && fileDoesExist;
            
            if ~result
                this.mThrowWarningDialog(fileType);
            end
            % end
            
        end
        
        %# throw warning message
        function mThrowWarningDialog(this,fileType)
            disp('file error......');
            warnString = ['The ',fileType,' file cannot be found.\n Move this file to task directory and reload.'];
            
            f = warndlg(sprintf(warnString),'File Not Accessible', 'modal');
            waitfor(f);
        end
        
        %# add or remove the cfg file extention for a given filepath
        function cfgfile = mAppendRemoveCfgExt(this,rmode,filename)
            %filename    = 'H:\projects\DisplayServer_tasks\DisplayServer\Version_beta\GUIs\classes.m';
            %             filename    = 'classes.m';
            %             this.cfgExt = '_cfg';
            %             filename    = 'classes_cfg';
            switch rmode
                case 'append'
                    [fpath,fname,fext] = fileparts(filename);
                    cfgfile = fullfile(fpath,[fname,this.cfgExt,fext]);
                case 'remove'
                    cfgfile = cell2mat(regexp(filename,this.cfgExt,'split'));
                otherwise
                    % not available
            end
        end

    end
    
    
    methods (...
            Static = true,...
            Sealed = true)
        
 
        %# ensure file has a specfic file ext
        function filepath = mSetFileExt(fullfilepath,ext)
            [fpath,fname,fext] = fileparts(fullfilepath);
            filepath = fullfile(fpath,[fname,ext]);
        end
        
        %# remove file ext
        function minusext = mRemoveFileExt(fullfilepath)
            [fpath,fname,fext] = fileparts(fullfilepath);
            minusext = [fpath,fname];
        end
        
        %# replace a char in the string with a new one
        % primarily used for creating structs by replacing '_' with '.'
        % which is a in the tags of the ui objects
        function newStr = mReplaceChar(str,charIn,charOut)
            % charIn = '_'
            % charOut = '.';
            newStr = str;
            newStr(strfind(str,charIn)) = charOut;
        end
        
        %# check input type
        function [result, test] = mCheckUIControlInput(test,className,id)
            %----------------------------------------%
            % CHECK TYPES:
            %   'integer'
            %   'uinteger'
            %   'float'     [4 decimal places]
            %   'char'
            %----------------------------------------%
            % if empty, assume char
            if isempty(className), className = 'char'; end;
            
            switch className
                case 'uinteger'
                    test   = str2double(test);
                    result = isa(test,'integer') & abs(test) == test;
                case {'float','integer'}
                    test   = str2double(test);
                    result = isa(str2double(test),className);
                case 'char'
                    result = isa(test,'char');
                otherwise
                    % not implemented
                    result = false;
            end
            
            if ~result
                % do not let user continue until ok clicked
                errordlg(sprintf('Input %s must be of type %s',id,className),'Input Error:');
            end
        end
    end
end


