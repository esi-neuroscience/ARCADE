classdef AUXFastHistogram < handle
    % [AUXILLARY] FAST HISTOGRAM
    % 
    % creates a histogram using patch()

    % *** Drawmode ***
    % will be an issue for 2014b
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    
    methods (Static = true)
        function this = AUXFastHistogram % constructor 
        end
    end
    
    %# PATCH
    methods (...
            Static = true,...
            Sealed = true,...
            Access = protected)
        
        %# setup axis 
        function mSetAxis(parent,cmap,xlim,ylim,layer)
            
            if ~isempty(cmap)
                colormap(parent,cmap)
                cmax = size(cmap,1); % values [1 n]
                if cmax>1
                    clim = [1 cmax];
                else
                    clim = [0 1]; 
                end
            else
                clim = [0 1]; % no colormap
            end

            set(parent,...
                'NextPlot','replacechildren',...
                'Drawmode','fast',...
                'CLimMode','manual',...
                'CLim',clim,...
                'XLim',xlim,...
                'YLim',ylim,...
                'Layer',layer,...
                'box','off');
            
        end
        
        %# create a patch 
        function hp = mCreatePatch(parent,xdata,ydata,cdata,cEdge,lw)
            %delete(allchild(this.parent));
            hp = patch(...
                xdata,...
                ydata,....
                cdata,...
                'Parent',parent,...
                'EdgeColor',cEdge,...
                'LineWidth',lw,...
                'erasemode','none');
        end 
    end
    
    %# HISTOGRAM 
    methods (...
            Static = true,...
            Sealed = true,...
            Access = protected)
        
        %# histogram
        function hdat = mCompHist(data,edges,norm)
            %# compute histogram
            % histc return data in bins (edges(k) edges(k+1)] 
            % last bin are values at edges(end)
            % add the last bin to the second last bin
            % ignores all data outside of edges including Inf, -Inf, & Nan
            
            % data should be arranged in rows
            % re-arrange data to columns 
            hdat = histc(data', edges, 1);
           
            % add last bin to second last
            hdat(end-1,:) = sum(hdat(end-1:end,:),1);
            
            % 0, no normalize
            % 1, max
            % 2, sum
            switch norm
                case 1
                    % normalize to max bin of each column
                    hdat = bsxfun(@rdivide,hdat,max(hdat));
                case 2
                    % normal to sum of each column
                    hdat = bsxfun(@rdivide,hdat,sum(hdat));
                otherwise
                    % do nothing
            end
        end

        %# histogram bin centers, edges
        function [bins, edges] = mCompBins(xlimit,nbins)
            % compute hist bins (bins centers)
            edges = linspace(xlimit(1),xlimit(2),nbins+1);
            shift = diff(edges(1:2))/2;
            bins  = edges(1:end-1)+shift; % shift bins
        end
    end
    
    %# HISTOGRAM - 
    methods (...
            Static = true,...
            Access = protected)
        % these methods can be modified by subclasses
        % these methods are for use with patch
        
        %# compute XData
        function xdata = mCompXData(edges)
            % edges should be a row vector
            xdata = reshape([edges(1:end-1);edges(2:end)],[(size(edges,2)-1)*2 1]);
            % append edges
            xdata = [xdata(1,:); xdata; xdata(end,:)];
        end

        %# compute YData 
        function ydata = mCompYData(hdat)
            nreps = size(hdat,2);
            % ignore last row
            ydata = reshape(...
                permute(hdat(1:end-1,:,zeros(1,2)+1),[3,1,2]),...
                [(size(hdat,1)-1)*2,nreps]);
            % append 0 to edges
            ydata = [zeros(1,nreps); ydata; zeros(1,nreps)];
        end
    end     
end

