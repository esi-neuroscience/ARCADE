classdef PLTEyePosition < ABSPlotDefinition & AUXGridDisplay
    % [PLOT] EYE POSITION 
    % - setup eye plot size 
    % - plot grid
    % - plot eye position
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    % 15.6.2023 - Michael
    %               removed undocumented syntax to restrict property values
    
    properties (SetAccess = immutable)
        parent % handle to parent axis
    end
    
    properties (AbortSet = true)
        linestyle  = '-';
        linewidth  = 0.5;
        linecolor  = [0.3098,0.7333,1.000];
        markersize = 17;
        marker     = '.';
    end
    
    methods (Static)
        function this = PLTEyePosition(ax_parent)
            this.parent = ax_parent;
        end
    end
    
    methods
        function mUpdate(this,pos)
            persistent hl
            
            if isempty(hl) || ~ishghandle(hl)
                hl = this.mCreate(pos);
            else
                set(hl,...
                'XData',pos(:,1),...
                'YData',pos(:,2));
            end
        end
        
        function hl = mCreate(this,pos)
%             Warning: The EraseMode property is no longer supported and will error in a future release.
%             Use the ANIMATEDLINE function for animating lines and points instead of EraseMode 'none'.
%             Removing instances of EraseMode set to 'normal', 'xor', and 'background' has minimal
%             impact.
            
            parent = this.parent;  %#ok<*PROP>
            linecl = this.linecolor;
            linest = this.linestyle;
            mrkrsz = this.markersize;
            mrkr   = this.marker;
            
            pixelsPerDeg = 52.18*3;
            pixelspacing = pixelsPerDeg;
            screensize   = [1680,1050]; 
            % set axis
            this.mSetAxis(parent,screensize);
            
            % draw grid
            % screensize   = in pixels
            % pixelspacing = pixels per degree (for degrees)
            this.mDrawGrid(parent, screensize, pixelspacing);

            % create line
            % xor/none are the fastest options 
            hl = line(...
                'Parent',parent,...
                'XData',pos(:,1),...
                'YData',pos(:,2),...
                'Color',linecl,...
                'LineStyle',linest,...
                'MarkerSize',mrkrsz,...
                'Marker',mrkr,...
                'EraseMode','xor'); 
        end
    end
       
    methods (Static = true)
        function mSetAxis(parent,screensize)
            % Warning: The DrawMode property will be removed in a future release. Use the SortMethod
            % property instead. 
            %screensize = [1680,1050];
            xylim = [-1,-1;1,1].*(screensize(ones(1,2),:)./2);
            
            % set axis for optimal drawing
            % axis should not need to change size dynamically
            set(parent,...
                'Units','pixels',...
                'NextPlot','replacechildren',...
                'Drawmode','fast',...
                'XLim',xylim(:,1),...
                'YLim',xylim(:,2),...
                'box','off');
            
        end
    end
end



% To immediately display changes to object data, call 'drawnow update' 
% or 'drawnow expose' instead of setting EraseMode to 'xor'.
% 
% 'drawnow update' updates a graph with maximum loop speed, but only sends updates 
% if the renderer is free. If the renderer is busy, then 'drawnow update' discards the updates.
% 'drawnow expose' updates a graph as quickly as possible without losing any updates.

% In R2014a and earlier, setting the 'EraseMode' property to 'xor' increases the 
% rendering speed. Remove code that sets the 'EraseMode' property to get similar rendering speeds.


