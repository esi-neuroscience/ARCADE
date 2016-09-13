classdef SPCGUIDefinition < handle 
    % [SUPERCLASS] GUI definition 
    % superclass for all GUI classes
    
    % SUBCLASSES:
    %   ControlScreen
    %   PauseScreen 
    %   MainScreen
    %   WRNGFileNotFound
    
    % METHODS:
    %   hfig = mLaunchGUI(this,guiName,ismodal)
    %   mSetGUIdata(this,data)
    %   mResume(this,varargin)
    %   mWaitForUserAction(this)
    %   mCloseRequestCallback(this,hObj,evt)
    %   delete(this)
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    % 29.4.2016 - Jarrod, added some documentation 
    
    properties (...
            Abstract  = true,...
            SetAccess = immutable)
        hfig % gui figure handle 
    end

    methods (Static)
        %# constructor
        function this = SPCGUIDefinition
        end
    end
    
    methods
        %# general launch gui function 
        function hfig = mLaunchGUI(this,guiName,ismodal)
            % launch figure 
            % guiName = mfilename
            hfig = openfig(guiName,'reuse');

            set(this.hfig,...
                'visible','off',...
                'doublebuffer','on',...
                'backingstore','off');
            % if the figure should be modal 
            set(0, 'currentfigure', this.hfig); 
            
            if ismodal 
                set(this.hfig,'WindowStyle','modal');
            end
        end
        
        %# Set GUI data  
        % INPUT => struct
        % *overwrite field if it already exists
        %  otherwise, add to existing structure
        function mSetGUIdata(this,data)
            if isempty(data), return; end;  % is there data, else return
            gdata = guidata(this.hfig);     % get current gui data
            
            for f = fieldnames(data)'       % add new data 
                gdata.(f{1}) = data.(f{1}); % overwrite if exists  
            end
            guidata(this.hfig,gdata);       % store in figure
        end

        %# resume after wait 
        function mResume(this,varargin)
            if ishghandle(this.hfig)
                uiresume(this.hfig);
            end
        end
        
        %# wait for user action 
        function mWaitForUserAction(this)
            if ishghandle(this.hfig)
                % make current figure
                set(0, 'currentfigure', this.hfig); 
                uiwait(this.hfig);
            end
        end
        
        %# close request callback
        function mCloseRequestCallback(this,hObj,evt) %#ok<INUSD>
            % do nothing for now 
            % could be like a cancel
            %this.userQuitRequest = true;
            uiresume(this.hfig);
            %closereq; % close gui
            %this.userResumeRequest(hObj,evt);
        end
        
        % find if variable
        %function mFindInWorkspace()  
        %end

        %# delete 
        function delete(this)
            % if still valid delete
            if ishghandle(this.hfig) 
                %delete(allchild(this.hfig));
                close(this.hfig);
            end
        end

    end
end

