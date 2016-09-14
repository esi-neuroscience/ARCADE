classdef AUXTrialErrorLegend < handle 
    % TRIAL ERROR LEGEND
    % - get/set colormap
    % - and text strings 
    
    % + getColormap    [r,g,b]
    % + setColormap    [r,g,b]
    % + setTrialErrors 'text string'
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    properties (SetAccess = private)
        htrx % handles to text strings
        hctx % handles to colors
    end

    %properties (AbortSet = true)
        %cmap % colormap
    %end

    methods (Static = true)
        function this = AUXTrialErrorLegend(hfig,trxTags,ctxTags)
           [this.htrx, this.hctx] = AUXAuxMethods.mGetHandles(hfig,trxTags,ctxTags);
        end
    end
    
    methods (Access = protected)
        %# Get TrialError Values 
        function values = mGetTrialErrorValues(this)
            % returned as chars
            value = cellfun(@(h) get(h,'String'),this.hctx,'unif',0);
 
            % convert I to Inf
            % convert N to Nan
            % convert numbers numbers
            infs = strcmp('I',value);
            nans = strcmp('N',value);
            
            values = str2double(value);
            values(infs) = inf(1);
            values(nans) = nan(1);
        end
        
        %# GET COLORMAP
        function cmap = mGetTrialErrorColormap(this)
            cmap = cell2mat(cellfun(@(h)...
                    get(h,'BackgroundColor'),this.hctx,'unif',0)');
        end    
        
        %# SET COLORMAP
        %function setColormap(this,cmap)  
        %end
        %# SET TRIAL ERROR TEXT FIELDS
        function mSetTrialErrorTxt(this,trlerrs)
            set(this.htrx,{'String'},trlerrs);
        end
    end
        
end

