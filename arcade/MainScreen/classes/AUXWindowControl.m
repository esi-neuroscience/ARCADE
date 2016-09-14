classdef AUXWindowControl < MSWindow
    % [AUXILLARY]
    
    
    % INHERITANCE:
    % AUXWindowControl < MSWindow < handle 
    
    % SUBCLASSES:
    %   PauseScreen
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    % 29.4.2016 - Jarrod, added some documentation
    
    
    properties (Access = protected)
        hwnd = [];
    end
    
    methods (Static)
        function this = AUXWindowControl
        end
    end
    
    methods 
        % must call this first 
        function mFindMatlabWindow(this)
            winName = get(this.hfig,'Name');
            this.hwnd = this.mFindWindow('SunAwtFrame',winName);
        end

        function mForceForward(this)
            result = this.mShowWindow(this.hwnd,'SHOW');
            %result = this.mSetActiveWindow(this.hwnd);
            %result = this.mBringWindowToTop(this.hwnd);
        end
        
    end
end

