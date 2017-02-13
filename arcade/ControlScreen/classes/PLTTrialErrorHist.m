classdef PLTTrialErrorHist < ABSPlotDefinition & AUXFastHistogram
    % [PLOT] TRIAL_ERROR_HIST -> multiline histogram
    % - similar to ReactionTimeHist
    % timing test: 8-22ms to draw
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    properties (SetAccess = immutable)
        parent % handle to parent axis
        cmap   % colormap 
    end
    
    properties (AbortSet = true)
        nbins@double scalar     = 100;             % number of bins
        edgecolor@double vector = [0 0 0];         % patch edge color
        linewidth@double scalar = 1;               % edge line width
    end
    
    properties (...
            AbortSet = true,...
            Access   = private)
        hgback   % hghandle to background patch
        hgpatch  % hghandle to histogram patch
    end
    
    methods (Static = true)
        function this = PLTTrialErrorHist(ax_parent,cmap)
            %this = this@AUXFastHistogram;
            this.parent = ax_parent;
            this.cmap   = cmap;
        end
    end
    
    methods
        function mUpdate(this, tdata, idata)
            persistent xblim edges xdata nmap
            
            if isempty(nmap)
                nmap = size(this.cmap,1);
            end
            
            % unique indices
            unq  = unique(idata)';
            
            % size of...
            nunq = numel(unq);
            ntdt = numel(tdata);
            
            % compute new x-axis lims 
            xblim_ = [0 nanmax([tdata,0.001])];
            
            if isempty(xblim) || ~isequal(xblim, xblim_)
                xblim = xblim_;
                % compute x-data 
                [~,edges] = this.mCompBins(xblim,this.nbins);
                xdata = this.mCompXData(edges); 
                % set new xlim
                set(this.parent,'XLim',xblim);
            end
            
            % replicate size of unique indices 
            % patch 1,2,3... in columns
            xdata = xdata(:,zeros(1,nunq)+1);
            
            % compute color data 
            cdata = unq(:,zeros(1,size(xdata,1))+1)';

            % prepare data 
            indx = unq(:,zeros(1,ntdt)+1) == idata(zeros(1,nunq)+1,:);
            % pick a value smaller than the min
            data = zeros(nunq,ntdt)-min(edges)-1;
            data(indx) = tdata;
            
            % compute y-data 
            norm  = 1; % norm to max, look into super for diff options
            hdata = this.mCompHist(data,edges,norm);
            ydata = this.mCompYData(hdata);
            
            % height shift data
            height = nmap/nunq;
            kshift = (0:nunq-1)*height;
            kshift = kshift(zeros(1,size(ydata,1))+1,:);
            ydata  = (ydata*height)+kshift;

            if isempty(this.hgpatch) || ~ishghandle(this.hgpatch)
                % create patches 
                this.mCreate(xdata,ydata,cdata,xblim(2));
            else
                % update background data
                set(this.hgback,...
                    'XData',[0; 0; xblim(2); xblim(2)]);
                
                % update histogram data
                set(this.hgpatch,...
                    'XData',xdata,...
                    'YData',ydata,...
                    'CData',cdata);
            end
            
        end
        
        %# Create Initial Plot
        function mCreate(this,xdata,ydata,cdata,xmax)
            %set_axis(parent,cmap)
            %hp = createPatch(parent,xdata,ydata,cdata,cEdge,lw)
            
            ymax = size(this.cmap,1);
            
            parent    = this.parent;    %#ok<PROP>
            linewidth = this.linewidth; %#ok<PROP>
            ylim      = [0 ymax];
            xlim      = [0 xmax];
            
            %# setup axis
            this.mSetAxis(parent,this.cmap,...
                xlim,ylim,'top'); %#ok<PROP>

            %# create background patch
            % edge/color set to that of the parent axis
            this.hgback = this.mCreatePatch(...
                parent,...
                [0; 0; xmax; xmax],...  % xdata
                [0; ymax; ymax; 0],...  % ydata
                get(parent,'Color'),... % fillcolor
                get(parent,'Color'),... % edgecolor
                linewidth); %#ok<PROP>
            
            % create histogram patch
            this.hgpatch = this.mCreatePatch(...
                parent,...
                xdata,...
                ydata,...
                cdata,...
                this.edgecolor,...
                linewidth);%#ok<PROP>
            
        end
    end
end

function [maximum, iMax] = nanmax(x, varargin)
x(isnan(x)) = -Inf;
[maximum, iMax] = max(x, varargin{:});
end