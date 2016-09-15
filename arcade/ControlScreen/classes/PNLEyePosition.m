classdef PNLEyePosition < PLTEyePosition
    
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
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    methods (Static)
        function this = PNLEyePosition(hfig)
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

