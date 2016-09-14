classdef PNLSessionPerformance < PLTSessionPerformance
    % [PANEL] SessionPerformance
    % expansions to the panel should go here
    
    % no error checking 
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    methods (Static)
        function this = PNLSessionPerformance(hfig)
            gdata     = guidata(hfig);
            ax_parent = findobj(hfig,'Tag','ax_SessionPerformance');
            this      = this@PLTSessionPerformance(ax_parent,gdata.cmap);
            % *super signature not the same 
            %this.mUpdate([],gdata.trlErrorValues); 
        end
    end 
    
    %*** use superclass -> mUpdate()
        
    methods (...
            Access = private,...
            Hidden = true)

        %# function to update plot without precomputing the data 
        % in constructor -> this.mUpdate([],gdata.trlErrorValues); 
        function mUpdate_computeOnTheFly(this,sessData,varargin) 
            persistent trlErrVals 
            if ~isempty(varargin)
                trlErrVals = varargin{1}; % match vector 
                return;
            end
            
            % *if not using shared pool
            [indxData, err] = AUXAuxMethods.mAssignIndexToData(trlErrVals,sessData(3,:));
            % get trial error counts 
            tecounts = AUXAuxMethods.mCummulativeTrialErrors(numel(trlErrVals),indxData);

            % compute performance overall
            %prfdata = tecounts(:,end)./size(tecounts,2);
            perfData = AUXAuxMethods.mComputePercent(tecounts);

            % rows all zeros = Nans
            perfData(all(perfData==0,2),:) = nan(1);

            %mUpdate@PLTSessionPerformance(this,perfData); %#ok<MCSCM>
        end
        
%         %*****************************************************%
%         %            *if not using shared data pool*
%         % gdata.trlErrorValues
%         [indxData, err] = AUXAuxMethods.mAssignIndexToData(trlErrorValues,sessData(3,:)); % trial errors
%         % get trial error counts
%         tecounts = AUXAuxMethods.mCummulativeTrialErrors(numel(trlErrorValues),indxData);
%         % compute performance overall
%         perfData = AUXAuxMethods.mComputePercent(tecounts);
%         % rows all zeros = Nans
%         perfData(all(perfData==0,2),:) = nan(1);
%         %*****************************************************%
        
        
    end
    
end
