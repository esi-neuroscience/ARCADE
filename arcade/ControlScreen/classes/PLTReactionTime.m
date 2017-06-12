classdef PLTReactionTime < ABSPlotDefinition & AUXFastHistogram
    % [PLOT] REACTION TIME HIST -> normal histogram 
    
    % ABSPlotDefinition -> abstract class 
    %   -> all PLT classes should implement these functions 
    % AUXFastHistogram  -> auxillary function 
    %   -> fast implemetation of creating a histogram
    
    % timing test: takes 1-5ms 
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 14.1.2015 - Jarrod added comments, change access, & class names 
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    properties (SetAccess = immutable)
        parent % handle to parent axis
    end
    
    properties (Access = private)
        hgback   % hghandle to background patch
        hgpatch  % hghandle to histogram patch
    end
    
    % Theoretically user editable 
    properties (AbortSet = true)
        nbins@double scalar     = 50;              % number of bins
        fillcolor@double vector = [86 56 255]/255; % patch fill color
        edgecolor@double vector = [0 0 0];         % patch edge color
        linewidth@double scalar = 1;               % edge line width
        xbuf@double scalar      = 100;             % buffer xaxis
        
        %norm@double scalar = 1; % norm to hist data to max bin
    end
 
    methods (Static = true)
        function this = PLTReactionTime(ax_parent)
            %this = this@AUXFastHistogram;
            this.parent = ax_parent;
        end
    end
    
    methods 
        %# update reaction time plot
        % INPUT:
        %   data -> vector of reaction times {1 x ntrials]
        %
        function mUpdate(this, data)
            persistent xblim edges xdata
            %* if last data point is a nan, don't update
            % don't waste time updating if, isnan, or isempty
            %if isempty(data),    return; end;
            if isnan(data(end)), return; end;
            
            % compute new x-axis lims 
            xblim_ = [0 nanmax([data,1])+this.xbuf];
            
            if isempty(xblim) || ~isequal(xblim, xblim_)
                xblim = xblim_;
                % compute x-data 
                [~,edges] = this.mCompBins(xblim,this.nbins);
                xdata = this.mCompXData(edges);
                
                % set new xlim
                set(this.parent,'XLim',xblim);
            end
            
            % compute y-data 
            norm  = 1; % norm to max
            hdata = this.mCompHist(data,edges,norm);
            ydata = this.mCompYData(hdata);

            if isempty(this.hgpatch) || ~ishghandle(this.hgpatch)
                % create patches 
                this.mCreate(xdata,ydata,xblim(2));
            else
                % update background data
                set(this.hgback,...
                    'XData',[0; 0; xblim(2); xblim(2)]);
                
                % update histogram data
                set(this.hgpatch,...
                    'XData',xdata,...
                    'YData',ydata);
            end

        end

        %# Create Initial Plot
        function mCreate(this,xdata,ydata,xmax)
            %set_axis(parent,cmap)
            %hp = createPatch(parent,xdata,ydata,cdata,cEdge,lw)
            parent    = this.parent;   %#ok<PROP>
            linewidth = this.linewidth; %#ok<PROP>
            ylim      = [0 1];
            xlim      = [0 xmax];
            
            %# setup axis
            this.mSetAxis(parent,[],...
                xlim,ylim,'top'); %#ok<PROP>
            
            %# create background patch
            % edge/color set to that of the parent axis
            this.hgback = this.mCreatePatch(...
                parent,...
                [0; 0; xmax; xmax],...  % xdata
                [0; 1; 1; 0],...        % ydata
                get(parent,'Color'),... % fillcolor
                get(parent,'Color'),... % edgecolor
                linewidth); %#ok<PROP>
            
            % create histogram patch
            this.hgpatch = this.mCreatePatch(...
                parent,...
                xdata,...
                ydata,...
                this.fillcolor,...
                this.edgecolor,...
                linewidth);%#ok<PROP>
            
        end
    end
    
end

function [maximum, iMax] = nanmax(x, varargin)
x(isnan(x)) = -Inf;
[maximum, iMax] = max(x, varargin{:});
end







