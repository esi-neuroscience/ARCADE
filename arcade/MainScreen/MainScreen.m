classdef (Sealed) MainScreen < MSJavaObjects & MSConfig & MSEditableVariables & MSBackupCopy & SPCGUIDefinition 
    % SINGLETON GUI - MAIN SCREEN
    
    
    % INHERITANCE:
    %   HLOMaskedGrating < ...
    %       MSJavaObjects < handle 
    %       MSConfig < AUXUIControlFunctions < handle
    %       MSEditableVariables < AUXEditableVariables < handle
    %       MSBackupCopy < AUXBackupCopy (GUI\classes) & AUXDirectoryManager < handle
    %       SPCGUIDefinition < handle 
    
    % INHERITED PROPERTIES: 
    %   filepaths      = []; [MSBackupCopy] % structure of filepaths (where to write the data from this session)
    %   backupFileList = {}; [MSBackupCopy] % combined (master) backup file list
    %   taskFile             [MSConfig]     % task file fullfilepath
    %   cfgFile              [MSConfig]     % cfg file fullfilepath
    %   cfg                  [MSConfig]
    %   version_path         [AUXFilePaths]
    %   dispServer_path      [AUXFilePaths]
    
    % MSJavaObjects       -> adds java objects (JSpinners, etc) to the GUI
    % MSConfig            -> handles all cfg related functions 
    % MSEditableVariables -> handle the editables variables porition of the GUI
    % AUXCopyAndBackup    -> handle the copy and backup files portion of the GUI 
    % SPCGUIDefinition    -> a super class that defines some GUI related functions 
    

    % loading replaces values from theloaded cfg
    % ensure that the name of the cfg/task file is correct on saving  
    
    % TO DO: Required fields boarders take too long to initialize 

    %---------------------------------------------%
    % 11.3.2015 - Jarrod, Large revision changed the way the config is loaded/created 
    % 10.4.2015 - Jarrod, Added many features (mainly java objects)
    % - color selector
    % - number spinners
    % - subject/experiment/session text fields
    % - detect monitor settings
    % 14.4.2015 - Jarrod, Added several functions 
    % - added Backup Files function
    % - added attached eventmarkers file 
    % 16.4.2015 - Jarrod, 
    % - modified the way the backup files are set in the cfg
    % 20.4.2015 - Jarrod, 
    % - added default values to uicontrol objects in cfg
    % - added run button callback (check for session directory)
    % 21.4.2015 - Jarrod,
    % - added required border color
    % - added copy backup files when Run button pressed
    % 22.4.2015 - Jarrod, some minor changes to the backup files methods
    %  3.5.2015 - Jarrod, added filetype to mSelectTaskAssociatedFile
    % 29.4.2016 - Jarrod, added some documentation 
    %  3.5.2016 - Jarrod, updated the documentation
    
    properties (...
            AbortSet      = true,...
            SetObservable = true)
        taskFile =[]; % task file fullfilepath
        cfgFile  =[]; % cfg file fullfilepath  
        
        %condFile =[]; % condition selection file 
        %blckFile =[]; % block selection file 
        %evtmFile =[]; % eventmarkers file 
        
        cfg = []; % config struct **Abstract in MSConfig**
    end
    
    
    %# figure handle 
    properties (SetAccess = immutable)
        hfig    % figure handle
    end
    
    properties (SetAccess = protected)
        today       % date string
    end

    events
        %# load cfg file requested 
        requestLoadCfg % request to load the cfg file 
        cfgIsLoaded    % cfg is loaded (is this in use?)
    end

    methods (Static)
        %# public access fetch instance/constructor 
        function this = launch
            persistent thisObj
            if isempty(thisObj) || ~isvalid(thisObj)
                thisObj = MainScreen;
            end
            this = thisObj;
        end
    end
    

    methods (Access = private)
        %# private ocnstructor
        function this = MainScreen
            %------------------------%
            % launch figure
            % setup cfg 
            % -> *sets callback functions for Tags begining with 'cfg_'*
            % setup uicontrols 
            %------------------------%
            % launch gui 
            makeUIModal = false;
            this.hfig   = this.mLaunchGUI(mfilename,makeUIModal);
            
            % initialize Java objects
            this.mAddJavaSwingObjects;
            
            % initialize GUI UIObjects
            this.mSetGeneralCfgSetGetFunctions; % set general cfg uiobject callbacks
            % ***attach special functions***
            this.mCreateCfgStruct;
            
            %this.initCfgStruct;            % initialize config struct 
            this.mInitMSButtons;            % initialize Main Screen buttons
            this.mInitEditableVariables;    % initialize Editable Variables
            this.mInitJavaObjectListeners;  % initialize object listeners*
            this.mSetTodaysDate;            % set today's date 
            % *objects that depend on the value of others 
            
            % setup backup file selection 
            this.mInitBackupButtonsAndCheckboxes;
            %this.mSetMainBackupFileListeners;

            % set default values 
            this.mSetDefaultValue;
            
            % initialize required inputs to run
            %this.mInitRequireds;            
            %-----------------------------------------%
            %hPnl = findobj(this.hfig,'Tag','pnl_EditableVars');
            %set(hPnl,'ButtonDownFcn',@(src,evt) disp('Panel clicked...'));
            
            %this.initSetGetProperties;
            %-----------------------------------------%

            set(this.hfig,'Visible','on');
            drawnow;
            % wait for user action  
            this.mWaitForUserAction;
        end
        
        %# set today's date
        function mSetTodaysDate(this)
            % set today's date
            this.today = AUXDateTime.mGetTodaysDate;
            hObj_today = findobj(this.hfig,'Tag','txt_CurrentDate');
            set(hObj_today,'String',this.today);
            
        end
        

        %# Setup Buttons
        function mInitMSButtons(this)
            %----------------------------------------%
            % Buttons:
            %   -> btn_LoadCfg
            %   -> btn_SaveCfg
            %   -> btn_LoadTask
            %   -> btn_RUN
            %----------------------------------------%
            
            % disable on request cfg load
            % enable on cfg is loaded 
            
            
            % - set callback [select file]
            % - add listener [load cfg]
            %   *listener func is called when the cfgfile property is set
            
            % load task file
            % - required to allow loading a task file
            % - setting the task file name, auto loads it?
            % - 
            
            % task loads task file, and if cfgfile, sets cfg file and
            % notfies listener 
            
            % load button gets cfg filename and sets it, then notifies
            % listener
            
            % save simply sets the cfg file, but does not notify
            tag_CondSel = 'cfg_Files_ConditionSelection';
            tag_BlckSel = 'cfg_Files_BlockSelection';
            tag_EvtMrkr = 'cfg_Files_EventMarkers';
            
            
            btnTskFile    = findobj(this.hfig,'Tag','btn_TaskFile');
            btnLoadCfg    = findobj(this.hfig,'Tag','btn_ConfigFile');     % button is initially disabled
            btnSaveCfg    = findobj(this.hfig,'Tag','btn_SaveCfg');        % button is initially disabled
            btnRunTsk     = findobj(this.hfig,'Tag','btn_RUN');            % button is initially disabled
            % these have a default callback function set, and here it is overridden 
            btnSetCondSel = findobj(this.hfig,'Tag',tag_CondSel);          % button is initially disabled
            btnSetBlckSel = findobj(this.hfig,'Tag',tag_BlckSel);          % button is initially disabled
            btnSetEvtMrkr = findobj(this.hfig,'Tag',tag_EvtMrkr);          % button is initially disabled
            
            % requireds
            txt_subj     = findobj(this.hfig,'Tag', 'cfg_Subject');
            txt_expt     = findobj(this.hfig,'Tag', 'cfg_Experiment');
            txt_sess     = findobj(this.hfig,'Tag', 'cfg_Session');
            txt_ProjOwnr = findobj(this.hfig,'Tag', 'cfg_ProjectOwner');
            txt_Expmtr   = findobj(this.hfig,'Tag', 'cfg_Experimenter');
            
            % enable these buttons on task load 
            enableOnTaskLoad = [btnSetCondSel,btnSetBlckSel,btnSetEvtMrkr,btnLoadCfg];

            % this event indicates that the current cfg file should be loaded
            notifyEvt = 'requestLoadCfg';
            addlistener(this,notifyEvt,@(hObj,evt) this.mUpdateCfgandGUI(hObj,evt));
            
            % TASK FILE
            setProp = 'taskFile';
            set(btnTskFile,'Callback',...
                @(hObj,evt) this.mSelectTaskAssociatedFile(hObj,evt, 'Task','*.m', setProp, [], enableOnTaskLoad,[]) );
            % if cfg file found, notify event
            addlistener(this,setProp,'PostSet',@(hObj,evt) this.mCheckForCfg(hObj,evt,btnSaveCfg,notifyEvt));

            % LOAD CONFIG FILE
            setProp = 'cfgFile';
            %set(btnLoadCfg,'Callback',@(hObj,evt) this.mSetCfgFile(hObj,evt, setProp, notifyEvt));
            set(btnLoadCfg,'Callback',...
                @(hObj,evt) this.mSelectTaskAssociatedFile(hObj,evt, 'Config','*_cfg.mat', setProp, [], [], notifyEvt) );
            addlistener(this,setProp,'PostSet',@(hObj,evt) this.mSetCfgButtonText(hObj,evt,btnLoadCfg));

            % CONDITION & BLOCK SELECTION FILES
            % mSelectTaskAssociatedFile(this,hObj,~,fileStr,prop,field,activate)
            
            % get cfg structure paths
            cfgPath_CondFile = this.mReplaceChar(tag_CondSel,'_','.');
            cfgPath_BlckFile = this.mReplaceChar(tag_BlckSel,'_','.');
            cfgPath_EMrkFile = this.mReplaceChar(tag_EvtMrkr,'_','.');
            
            set(btnSetCondSel,'Callback',...
                @(hObj,evt) this.mSelectTaskAssociatedFile(hObj,evt,'Condition','*.m',   [], cfgPath_CondFile, [],[]) );
            set(btnSetBlckSel,'Callback',...
                @(hObj,evt) this.mSelectTaskAssociatedFile(hObj,evt,'Block','*.m',       [], cfgPath_BlckFile, [],[]) );
            
            % EVENT MARKERS FILE 
            set(btnSetEvtMrkr,'Callback',...
                @(hObj,evt) this.mSelectTaskAssociatedFile(hObj,evt,'EventMarker','*.m', [], cfgPath_EMrkFile, [],[]) );
            
            % SAVE CFG
            set(btnSaveCfg,'Callback',@(hObj,evt) this.mSaveCfgFile(hObj,evt));
            % if cfg changes, enable button
            lh = addlistener(this,'cfg','PostSet',@(hObj,evt) set(btnSaveCfg,'Enable','on'));
            
            % requestLoadCfg % request to load the cfg file 
            % cfgIsLoaded
            % lh.Enabled = false;
            %mEnableListener(this,hObj,evt,lh,value)
            addlistener(this,'requestLoadCfg',@(hObj,evt) this.mEnableListener(hObj,evt,lh,false));
            addlistener(this,'cfgIsLoaded',   @(hObj,evt) this.mEnableListener(hObj,evt,lh,true));
            %addlistener(this,'requestLoadCfg',@(hObj,evt) lh.Enabled ));
            %addlistener(this,'cfgIsLoaded',   @(hObj,evt) set(lh,'Enabled','on'));
            
            % required strings 
            reqStrings = [txt_ProjOwnr, txt_Expmtr, txt_subj, txt_expt, txt_sess];
            
            % listen to cfg save button 
            addlistener(btnSaveCfg,'Enable','PostSet',@(hObj,evt) this.mCheckRequireds(hObj,evt,reqStrings,btnRunTsk,btnSaveCfg));
            % add a listener to cfg file loaded event 
            % sets RUN button if requires are okay
            addlistener(this,'cfgIsLoaded',@(hObj,evt) this.mCheckRequireds(hObj,evt,reqStrings,btnRunTsk,btnSaveCfg));
            
            % set required listener borders
            % this.mInitRequiredBorders(reqStrings);
            
            % RUN TASK
            % -> set callback, resume
            set(btnRunTsk,'Callback',@(hObj,evt) this.mRunTask(hObj,evt));
            
        end
        
        %# enable/disable listener 
        function mEnableListener(this,hObj,evt,lh,value)
            lh.Enabled = value;
            if value
               btnSaveCfg = findobj(this.hfig,'Tag','btn_SaveCfg');  
               set(btnSaveCfg,'Enable','off');
            end
        end
        
        %# run button callback 
        function mRunTask(this,~,~)
            % 1. all relevant fields must be complete
            % 2. session path must be unique 
            % 3. settings file must be saved 
            
            %--------------------%
            % create backup filepaths and directories 
            % (warn if session directory already exists)
            success = this.mCreateBackupFilepaths;
            if ~success, return; end
            
            %--------------------%
            % if directories sucessfully created, copy files if any 

            disp('Checking for backup files...');
            copyIfAny = true;                       % copy backup files if any
            
            %------------------------------%
            %            bugs 
            this.mCreateBackupFileList(copyIfAny);  % create backup file list

            this.cfg.PauseRGB      = this.cfg.PauseRGB';
            this.cfg.BackgroundRGB = this.cfg.BackgroundRGB';
            this.cfg.filepaths     = this.filepaths;
           
            %------------------------------%
            disp('Starting Session...');
            this.mResume;
        end
        
        %# init required edit field
        function mInitRequiredBorders(this,hObj_strReqs)
            
            reqObjs = [];
            
           for k = 1:length(hObj_strReqs)
               reqObj_ = MSHightlightRequired(hObj_strReqs(k));
               %reqObj_.mCreateBorderAndListener;
               
               reqObjs = [reqObjs; reqObj_]; %#ok<AGROW>
           end
        end
        
        %------------------------------%
        %          Callback 
        
        %# check required inputs 
        % every tome the save cfg button changes, 
        % check if the appropriate fields are complete
        function mCheckRequireds(this,hObj,evt,hTxt_strReqs,btnRunTsk,btnSaveCfg) %#ok<*INUSL>
            
            %stateSaveCfg = get(evt.AffectedObject,'Enable');
            stateSaveCfg = get(btnSaveCfg,'Enable');
            % text fields
            mFindIsEmpty = @(hTxt) isempty(get(hTxt,'String'));
            reqStringsEmpty = arrayfun(@(hTxt) mFindIsEmpty(hTxt), hTxt_strReqs); % all 1s = all empty
            
            % if save cfg enabled
            if strcmpi(stateSaveCfg,'off') && all(~reqStringsEmpty) && ~isempty(this.taskFile)
                set(btnRunTsk,'Enable','on');
            else
                set(btnRunTsk,'Enable','off');
            end
            drawnow;
        end
        
        
        %# initialize object listerners
        function mInitJavaObjectListeners(this)
            % frames are used for marking the position/location
            % of a java object in the gui, set the value of the frame
            % on the callback to signal that the java object callback has
            % been called
            
            % set listener for changes in distance
            monSizeObj = findobj(this.hfig,'Tag','cfg_MonitorDiagonalSize');
            scnDistObj = findobj(this.hfig,'Tag','cfg_DistanceToScreen');
            ppdObj     = findobj(this.hfig,'Tag','cfg_PixelsPerDegree');
            
            % add listeners
            addlistener(monSizeObj,'Value','PostSet',@(hObj,evt) this.mSetPixelsPerDegree(ppdObj,evt,monSizeObj,scnDistObj));
            addlistener(scnDistObj,'Value','PostSet',@(hObj,evt) this.mSetPixelsPerDegree(ppdObj,evt,monSizeObj,scnDistObj));
            
        end
        
        %# Set the Pixel per Degree (should be moved)
        function mSetPixelsPerDegree(this,ppdObj,~,...
                hObj_monDiagSz,...
                hObj_dist2scrn)
            % 'cfg_MonitorDiagonalSize'
            % 'cfg_DistanceToScreen'
            % hObj_monPxWidth,...  % 'cfg_MonitorResolution_width'
            % hObj_monPxHeight,... % 'cfg_MonitorResolution_height'
            
            % jSpinners
            dist2screen_getFcn = get(hObj_dist2scrn,'getPropertyFcn');
            dist2screen        = dist2screen_getFcn();
            
            monDiagSize_getFcn = get(hObj_monDiagSz,'getPropertyFcn');
            monDiagSize        = monDiagSize_getFcn();
            
            
            w = str2double(this.cfg.MonitorResolution.width);
            h = str2double(this.cfg.MonitorResolution.height);
            dec = 2; % two decimal places
            
            % ppd = mPixelsPerDegree(dist2screen,diagScreen,scrnPixels,dec)
            ppd = AUXPixels2Degrees.mPixelsPerDegree(dist2screen,monDiagSize,[w,h],dec);
            if isnan(ppd), ppd=0; end; % prevent Nan
            
            set(ppdObj,'String',num2str(ppd));
            this.cfg.PixelsPerDegree = ppd;    % perhaps a quick fix
        end
        
    end
end

