classdef PNLTrialErrorHist < PLTTrialErrorHist
    % [PANEL] TRIAL ERROR HIST

    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    methods (Static)
        function this = PNLTrialErrorHist(hfig)
            gdata     = guidata(hfig);
            ax_parent = findobj(hfig,'Tag','ax_TrialErrorHist');
            this      = this@PLTTrialErrorHist(ax_parent,gdata.cmap);
            
            %this.mUpdate([],[],gdata.trlErrorValues);
        end
    end
    
    %*** use superclass -> mUpdate()
    
    methods (...
            Access = private,...
            Hidden = true)

        %# function to update plot without precomputing the data 
        % in constructor -> this.mUpdate([],[],gdata.trlErrorValues);
        % tmdata = time stamps of errors 
        % sessData = trial errors
        function mUpdate_computeOnTheFly(this,tmStamps,sessData,varargin) 
            persistent trlErrVals % shrdpool 
            if ~isempty(varargin)
                trlErrVals    = varargin{1}; % number of trial errors
                %shrdpool = CSPSharedDataPool.shrdpool; % get shared pool
                return;
            end
            
            % *if not using shared pool
            [teIndxs, err] = AUXAuxMethods. mAssignIndexToData(trlErrVals,sessData(3,:));
            
            %teIndxs = shrdpool.trialErrorIndexes;
            %mUpdate@PLTTrialErrorHist(this, tmStamps, teIndxs); %#ok<MCSCM>
            
        end
    end
end

