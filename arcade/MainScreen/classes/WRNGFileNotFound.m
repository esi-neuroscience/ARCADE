classdef (Sealed) WRNGFileNotFound < SPCGUIDefinition
    % [WARNING]
    
    % INHERITANCE:
    %   WRNGFileNotFound <SPCGUIDefinition < handle 
    
    % CALLED BY;
    %   MSBackupCopy
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    % 29.4.2016 - Jarrod, added some documentation 
    
    %# figure handle 
    properties (SetAccess = immutable)
        hfig    % figure handle
    end
    
    methods (Static)
        %# public access fetch instance/constructor 
        function this = launch
            persistent thisObj
            if isempty(thisObj) || ~isvalid(thisObj)
                thisObj = WRNGFileNotFound;
            end
            this = thisObj;
        end
    end
    

    methods (Access = private)
        %# private ocnstructor
        function this = WRNGFileNotFound
            makeUIModal = true;
            this.hfig   = this.mLaunchGUI(mfilename,makeUIModal);
            
            hBtnOk = findobj(this.hfig,'Tag','btn_OK');
            
            set(hBtnOk, 'Callback',@(hObj,evt) this.mOKButtonCallback(hObj,evt)); 
            
        end
    end
    
    
    methods
        % # set files not found 
        function mSetFilesNotFound(this,filepaths)
            hLstBx = findobj(this.hfig,'Tag','lstbx_FilesNotFound');
            
            set(hLstBx,'String',filepaths);
            
            % wait for user action
            this.mWaitForUserAction;
        end

        %# Quit Button Callback
        function mOKButtonCallback(this,hObj,evt) %#ok<INUSD>
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

