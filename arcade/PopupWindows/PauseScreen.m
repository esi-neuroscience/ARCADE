classdef (Sealed) PauseScreen < AUXEditableVariables & SPCGUIDefinition
    % [GUI]
    % resume -> saves cfg
    % cancel -> rejects changes
    % quit   -> kills the software
    
    
    
    % INHERITANCE:
    % PauseScreen <  ...
    %   AUXEditableVariables (\MainScreen\classes) < handle
    %   SPCGUIDefinition < handle 
    %   AUXWindowControl (\GUIs\classes) < MSWindow < handle 
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation
    % 29.4.2016 - Jarrod, added some documentation
    % 23.2.2018 - Jarrod, HG1/HG2 Compatibility 
    % - dependance on addProp() in ARCADE\arcade\MainScreen\classes
    %  1.3.2018 - Jarrod, fixed issue #87 (hTbl -> controlObject)
    
    properties 
       userQuitRequest = false; 
       cfg             = [];
    end
    
    properties (Access = private)
        % number of variable rows 
        maxVarRows = 12; % >maxVarRows resize column
    end
    
    %# figure handle 
    properties (SetAccess = immutable)
        hfig    
    end
    
    methods (Static)
        function this = launch(cfg)
            persistent thisObj
            if isempty(thisObj) || ~isvalid(thisObj)
                thisObj = PauseScreen(cfg);
            end
            this = thisObj;
        end
    end
    

    methods (Access = private)
        %# private constructor
        function this = PauseScreen(cfg)
            this.cfg = cfg;

            % LAUNCH GUI
            makeModal = true; % false is better when debugging 
            this.hfig = this.mLaunchGUI(mfilename,makeModal);
            %set(0, 'currentfigure', this.hfig); 
            % close request function 
            %set(this.hfig,'CloseRequestFcn',@(hObj,evt) this.closeReqCallback(hObj,evt));
            
            this.mInitUIObjects;
            
            % force forward
%             this.mFindMatlabWindow;
%             this.mForceForward;
            
            % wait for user action
            this.mWaitForUserAction;
    
        end
        
        %# initialize gui
        function mInitUIObjects(this)
            % add callbacks
            % populate data 
            
            % ----------- uitable ----------- %
            % get table for Editable Variables 
            controlObject = findobj(this.hfig,'Tag','tbl_EditableVariables');
            
            % -- add propertiesand set them -- 
            % UITABLE ONLY
            addProp(controlObject, 'selectedIndices', []); 
            
            % cell edit and selection callbacks
            set(controlObject, 'CellSelectionCallback', @(hObj,evt) set(hObj,'selectedIndices',evt.Indices))
            set(controlObject, 'CellEditCallback',      @(hObj,evt) this.mGeneralCallback(hObj, evt, 'EditableVariables'));
            
            % UICONTROL and UITABLE 
            isReadOnly = true;
            addProp(controlObject, 'getPropertyFcn', @(hObj) get(hObj,'data'), isReadOnly); % create/set get property function

            % fetch data and set it 
            data = this.cfg.EditableVariables;
            
            % set editable variables 
            set(controlObject,'data',data);
            

            nRows = size(data,1); % number of editable variables
            this.mAdjustTableWidth(hTbl,this.maxVarRows,nRows,1);
 
            % ----------- buttons ----------- %
            % QUIT
            btnQuit   = findobj(this.hfig,'Tag','btn_QUIT');
            btnResume = findobj(this.hfig,'Tag','btn_RESUME');
            % RESUME 
            
            set(btnQuit,  'Callback',@(hObj,evt) this.mQuitButtonCallback(hObj,evt)); 
            set(btnResume,'Callback',@(hObj,evt) this.mResume(hObj,evt)); 
            
        end
        %# UIObject - general callback function
        function mGeneralCallback(this,hObj,evt,field) %#ok<INUSL>
            
            % ------ gets the data, and sets it as it is -------
            % get user input & convert to appropriate value
            getUIInput = get(hObj,'getPropertyFcn'); % allows a unique/general function
            uiinput    = getUIInput(hObj);           % has all params, only needs object handle
            
            % set the field in cfg struct
            this.cfg.(field) = uiinput;
            
        end
    end
    
    
    methods
        %# Quit Button Callback 
        function mQuitButtonCallback(this,hObj,evt)
            this.userQuitRequest = true; % set flag
            this.mResume;
        end
        
        % overloaded superclass method 
        function mResume(this,varargin)
            mResume@SPCGUIDefinition(this);
            close(this.hfig);
            %closereq; % close gui
        end 
    end
end

