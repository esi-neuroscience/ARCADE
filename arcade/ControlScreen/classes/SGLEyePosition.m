classdef (Sealed) SGLEyePosition < PLTEyePosition
    % 
    
    % --- Superclasses ---
    % PLTEyePosition < ABSPlotDefinition < handle
    % + mUpdate(this,pos)
    % + hl = mCreate(this,pos)
    % + mSetAxis(parent)
    % PLTEyePosition < AUXGridDisplay < handle
    % + mDrawGrid(this, parent_ax, screensize, pixelspacing)

    %ax_EyePlot
    %uip_Screen
    
    %ax_EyePlot
    % ax_PreviousTrialEyePlot
    %properties
    %end
    
    % perhaps will need a way of setting its 
    % aspect ratio for different screen ratios
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    
    methods (Static)
        function this = launch(varargin)
            persistent thisObj
            if isempty(thisObj) || ~isvalid(thisObj)
                hfig = varargin{1}; % must not be empty
                thisObj = SGLEyePosition(hfig);
            end
            this = thisObj;
            
        end
    end
    
    methods (Access = private)
        %# constructor
        function this = SGLEyePosition(hfig) 
            ax_parent = findobj(hfig,'Tag','ax_EyePlot');
            this = this@PLTEyePosition(ax_parent);
            % init plot 
            this.mUpdate([0,0]);
        end
    end
    

    %methods 
        %function pltUpdate(eyedata,varargin)
        %end
    %end
    
end

