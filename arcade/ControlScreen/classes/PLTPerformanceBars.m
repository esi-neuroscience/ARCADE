classdef PLTPerformanceBars < ABSPlotDefinition & AUXFastHistogram 
    % [PLOT] PERFORMANCE BARS -> stacked histogram
    % timing test: 8-24ms to update 
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    properties (SetAccess = immutable)
        parent % handle to parent axis
        cmap   % colormap 
    end
    
    properties (AbortSet = true)
        edgecolor@double vector = [0 0 0]; % patch edge color
        linewidth@double scalar = 1;       % edge line width
    end
    
    properties (...
            AbortSet = true,...
            Access   = private)
        hgpatch  % hghandle to histogram patch
    end
    
    methods (Static = true)
        function this = PLTPerformanceBars(ax_parent,cmap)
            %this = this@AUXFastHistogram;
            this.parent = ax_parent;
            this.cmap   = cmap;
        end
    end
    
    methods
        function mUpdate(this, data)
            % data arranged: rows = trial error, col = bar
            ydata = this.mCompYData(data);
            
            % xdata never changes
            % cdata never changes
            % only ydata needs to be updated 
            if isempty(this.hgpatch) || ~ishghandle(this.hgpatch)
                brwdth = 0.65;
                barpos = 1:3;
                
                % get from data
                [nstack, nbars]  = size(data);
                %nbars  = size(data,2);
                
                xdata = this.mCompXData(brwdth,barpos,nstack); % compute once
                cdata = this.mCompCData(nbars,nstack);         % compute once
                
                % create patches
                this.mCreate(xdata,ydata,cdata);
            else
                % update histogram data
                set(this.hgpatch,...
                    'YData',ydata);
            end
        end
        
        function mCreate(this,xdata,ydata,cdata)
            parent = this.parent;%#ok<PROP>
            xlim = [0.5 3.5]; % depends on bar pos 
            ylim = [0 100];
            
            %# setup axis
            this.mSetAxis(parent,this.cmap,...
                xlim,ylim,'bottom'); %#ok<PROP>
            
            % create histogram patch
            this.hgpatch = this.mCreatePatch(...
                parent,...
                xdata,...
                ydata,...
                cdata,...
                this.edgecolor,...
                this.linewidth); %#ok<PROP>

        end
    end
    
    methods (...
            Static = true,...
            Access = protected)
        %# compute xdata redefined 
        function xdata = mCompXData(brwdth,barpos,nstack)
            nbars = numel(barpos);
            xdata = bsxfun(@minus, barpos(ones(1,4),:),...
                [ones(2,1)*0.5*brwdth; -ones(2,1)*0.5*brwdth]);
            % replicate for stack
            % ordered: bar1&stack1, bar2&stack2, etc
            xdata = reshape(permute(xdata(:,:,ones(1,nstack)),[1,3,2]),[4,nbars*nstack]);
        end
        %# compute ydata redefined 
        function ydata = mCompYData(data)
            % bars in columns
            % stack is dim 1
            % bars is nstack
            data   = cumsum(data,1); % compute cummulative sum
            starts = [zeros(1,size(data,2)); data(1:end-1,:)];
            finish = data;
            
            % each column first
            ydata = reshape(permute(cat(3,starts,finish,finish,starts),[3,1,2]),[4,numel(data)]);
        end
        %# compute cdata 
        function cdata = mCompCData(nbars,nstack)
            % color indices must match
            % the CLIM in the axis
            % and number of elemnts in the cmap
            ci = 1:nstack; % color indices
            cx = reshape(ci(ones(1,3),:)',[1 nstack*nbars]);
            cdata = cx(ones(1,4),:);
        end
    end
 
end

