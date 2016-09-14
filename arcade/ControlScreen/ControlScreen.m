classdef (Sealed) ControlScreen < SPCPanelRegister & SPCGUIDefinition 
    % launch and update control screen
    
    % INHERITANCE:
    % ControlScreen < ...
    %   SPCPanelRegister < handle
    %   SPCGUIDefinition < handle 
    
    % --- SUPERCLASSES --- 
    % SPCGUIDefinition < handle 
    % + hfig = mLaunchGUI(this,guiName,ismodal)
    % + mResume(this,varargin)
    % + mWaitForUserAction(this)
    % + mCloseRequestCallback(this,hObj,evt)
    % + delete(this)
    
    % AUXUserKeyboardInput < handle
    % + mWindowKeyPressCallback(this,hObj,evt)
    
    % SPCPanelRegister < handle
    % + mUpdateControlDisplay(this, task, data)
    
    % - launch GUI,and intialize plots
    % - open Pipe to EyeServer
    %---------------------------------------------%
    % Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    % 29.4.2016 - Jarrod, added some documentation
    
    properties (SetAccess = immutable)
        hfig            % figure handle
    end
    
    properties (Access = protected)
       trlErrLeg = []; % trial error legend
    end
    
    properties
        keyPressed  = false;
        userRequest = []; % 'Pause', 'Quit', 'QuickEscape'
    end

    methods (Static)
        function this = launch
            persistent thisObj
            if isempty(thisObj) || ~isvalid(thisObj)
                thisObj = ControlScreen;
            end
            this = thisObj;
        end
    end
    
    methods (Access = private)
        %# constructor
        function this = ControlScreen
            
            % Launch GUI 
            makeModal = true; % false is better when debugging 
            this.hfig = this.mLaunchGUI(mfilename,makeModal);
            %set(0, 'currentfigure', this.hfig); 
            
            % Set a Callback for User Keyboard Events 
            set(this.hfig,'WindowKeyPressFcn',...
                @(hObj,evt) this.mWindowKeyPressCallback(hObj,evt));
            
            % Init Trial Error Legend 
            this.mSetupGUIData;
            
            % init panels/plots 
            this.mUpdateControlDisplay('init',[]);
        end
        
        %# add things to the GUI data
        % used by many objects that all have a handle to the gui
        function mSetupGUIData(this)
            % The Trial Error Legend Panel is a bit special
            % many plots depend on the trial error colormap
            % thus it must be set before initializing other plots
            % the colormap itself is stored in the GUI
            trlErrLeg = PNLTrialErrorLegend(this.hfig); %#ok<*PROP>
            % create a structure to add to the GUI data  
            % - colormap
            % - correct value
            correctValue = 1;
            % - trial error names
            % - trial error values
            gdata = cell2struct({...
                trlErrLeg.trlErrorCMap,...
                trlErrLeg.trlErrorValues,correctValue},...
                {'cmap','trlErrorValues','correctValue'},2);
            
            this.mSetGUIdata(gdata);
            this.trlErrLeg = trlErrLeg;
        end

         
        %------------------------------------%
        %#      flag key press 
        % - take first key press
        % - this allows drawnow to be called 
        % - many calls buffer over the trial, if they are not handled
        % - they will all evaluate at the end of the trial
        % - perhaps it is best just to let them execute 
        % - but at the same time prevent this function from executing until
        %  the flag is checked 
        function mWindowKeyPressCallback(this,hObj,evt) %#ok<INUSL>
            
            % reject multiple keypresses
            if this.keyPressed, return; end;
            
            switch evt.Character
                case {'P','p'}
                    % pause
                    this.keyPressed  = true;
                    this.userRequest = 'pause_request';
                case {'Q','q'}
                    % quit 
                    %this.keyPressed  = true;
                    %this.userRequest = 'quit_proc';
                otherwise
                    % nothing
            end
        end
    end % end of methods
end % end of class






