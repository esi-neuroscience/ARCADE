classdef PLTSessionPerformance < ABSPlotDefinition 
    % [PLOT] SESSION PERFORMANCE
    % must implement Abstract SuperClass Methods/Properties 
    % - timing test: 18-34ms
    % - only spikes to 34ms occassionally
    % - still to do: first time called it does not draw the lines!!
    % * a change to line() instead of plot() may speed it up
    
    % **** WARNIING: DrawMode *****
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    properties (SetAccess = immutable)
        parent % handle to parent axis
        cmap   % colormap
    end
    
    properties (Access = private)
        hplot   % line handles
    end
    
    % Theoretically user editable 
    properties (AbortSet = true)
        linestyle@char          = '-';
        linewidth@double scalar = 2;
    end
    
    methods (Static = true)
        function this = PLTSessionPerformance(ax_parent,cmap)
            this.parent = ax_parent;
            this.cmap   = cmap;
        end
    end
    
    methods
        function mUpdate(this,data)
            persistent hax hp 
            %%% turn plot into a lineseries
            [nters, ntrls] = size(data);
            
            % update x-axis
            set(hax,'XLim',[0 ntrls]);
            
            if isempty(hp) || any(~ishghandle(hp))
                hax = this.parent;
                hp  = this.mCreate(data,hax,this.cmap);
            else
                prfCell = mat2cell(data,ones(1,nters), ntrls);
                set(hp,...
                    {'XData'},{1:ntrls},...
                    {'YData'},prfCell);
            end
        end
        
        function hp = mCreate(this,data,parent,cmap)
            delete(allchild(parent));  % start new
            this.mSetAxis(parent,cmap); % set Axis
            
            fplot = @(xd) plot(...
                parent,...
                1:size(xd,2),...
                xd,this.linestyle,...
                'linewidth',this.linewidth);
            
            % create plot
            hp = fplot(data);
        end
    end
    
    methods (...
            Static = true,...
            Access = protected)
        %# set the axis for this particular plot
        function mSetAxis(parent,cmap)
            % xlim depends on the number of trials
            xlim = [0 1];
            set(parent,...
                'NextPlot','replacechildren',...
                'Drawmode','fast',...
                'ColorOrder',cmap,...
                'XLim',xlim);
        end
    end
    
end

