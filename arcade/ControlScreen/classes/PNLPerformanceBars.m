classdef PNLPerformanceBars < PLTPerformanceBars
    % [PANEL] PERFORMANCE BARS
    % expansions to the panel should go here
    
    % PNLPerformanceBars - shared data pool
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    methods (Static)
        function this = PNLPerformanceBars(hfig)
            % get gui stored data, correct index, cmap
            gdata     = guidata(hfig);
            % plotting object
            ax_parent = findobj(hfig,'Tag','ax_PerformanceBar');
            this      = this@PLTPerformanceBars(ax_parent,gdata.cmap);
            % handles to text fields
            htxt(1) = findobj(hfig,'Tag', 'txt_PercentCorrectCondition');
            htxt(2) = findobj(hfig,'Tag', 'txt_PercentCorrectBlock');
            htxt(3) = findobj(hfig,'Tag', 'txt_PercentCorrectOverall');
            
            trlErrVals  = gdata.trlErrorValues; % trlErrVals
            crrtVal     = gdata.correctValue; % crrtidx
            crrtVecIndx = find(trlErrVals==crrtVal);
            
            % setup persistent data
            % *superclass method signature different!
            %this.mUpdate([],[], htxt, gdata.trlErrorValues, gdata.correctValue);
            this.mUpdate([],[],[], htxt, crrtVal, crrtVecIndx); %#ok<FNDSB>
        end
    end
    
    %     switch varargin{1} % mode
    %         case 'init'
    %         case 'useRawInput'
    %         case 'useSharedPool'
    %     end
    
    methods
        function mUpdate(this,trialErrCounts, idxCurrCond, idxCurrBlock, varargin)
            persistent htxt crrtVal crrtVecIndx
            
            if ~isempty(varargin)
                htxt        = varargin{1};
                crrtVal     = varargin{2};
                crrtVecIndx = varargin{3};
                set(htxt,{'String'},{'0%';'0%';'0%'});
                return;
            end
            
            data = this.mCompPlotData(trialErrCounts, idxCurrCond, idxCurrBlock);
            % call superclass method
            mUpdate@PLTPerformanceBars(this,data);
            % set text fields, extract row that is the correct trial error
            AUXTextField.mUpdateAppendString(htxt,round(data(crrtVecIndx,:)),'%');
        end
    end
    
    %# below if for reference 
    methods (...
            Access = private,...
            Hidden = true)

        %# function to update plot without precomputing the data 
        % in constructor -> this.mUpdate([],[], htxt, gdata.trlErrorValues, gdata.correctValue);
        function mUpdate_computeOnTheFly(this,current,sessData,varargin) 
            persistent trlErrVals htxt crrtVal crrtVecIndx%shrdpool
            % cndblk  -> [conditions vector; block vector; trial errors]
            % current -> [this condition, this block]
            
            if ~isempty(varargin)
                % there is a slight performance advantage to
                % using persistent variables compared to class properties
                htxt       = varargin{1}; % handles to txt fields
                trlErrVals = varargin{2}; % matchvec
                crrtVal    = varargin{3}; % the correct trial error value 
                crrtVecIndx = find(trlErrVals==crrtVal); % index of correct trial error (sorted numbers)
                return;
            end
            % use the input passed to the function
            
            % *if not using shared pool (need current)
            % take the
            
            % test this
            %trialErrors = randi([0,9],1,100);
            % matchvec, data
            % Assign an index to data
            % matchvector is a vector of data, sorted in a way to
            % index the input
            %matchvec = 0:9;
            % matchvec => vector of possible trial errors
            % this vector can change
            % because it depends on the trial errors the user uses
            [trialErrIndxs, err]        = AUXAuxMethods.mAssignIndexToData(trlErrVals, sessData(3,:));
            %trialErrCounts              = AUXAuxMethods.mCummulativeTrialErrors(numel(trlErrVals),trialErrIndxs);
            trialErrCounts              = AUXAuxMethods.mSparseTrialErrors(numel(trlErrVals),trialErrIndxs);
            [idxCurrCond, idxCurrBlock] = AUXAuxMethods.mGetConditionBlockIndicies(current, sessData);
            
            % retrieve => trialErrCounts, idxCurrCond, idxCurrBlock
            
            data = this.mCompPlotData(trialErrCounts, idxCurrCond, idxCurrBlock);
            
            %if ~isempty(varargin)
            %shrdpool = CSPSharedDataPool.shrdpool; % get shared pool
            %end
            
            % compute the data
            %data = compPlotData(nters,cndblk,current);
            %data = compPlotData(nters,cndblk,shrdpool); % use shared pool
            
            % call superclass method
            %mUpdate@PLTPerformanceBars(this,data);
            
            % set text fields, extract row that is the correct trial error
            AUXTextField.mUpdateAppendString(htxt,round(data(crrtVecIndx,:)),'%');
        end
    end
    
   
    methods (...
            Static = true,...
            Access = private)
        %# compute data for performance bar plot 
        % INPUT:
        %   trialErrCounts  -> 2D sparse matrix
        %   idxCurrCond     -> logical vector of Current Condition trials
        %   idxCurrBlock    -> logical vector of Current Block trials
        % OUTPUT:
        %   data -> percent matrix 
        function data = mCompPlotData(trialErrCounts, idxCurrCond, idxCurrBlock)
            % * if there is none this block, then there is none this condition
            % could add come optimization for that case
            
            [nTrlErrs, nTrls] = size(trialErrCounts);
            
            % compute percentage overall 
            prf_overall = sum(trialErrCounts,2)./nTrls*100;

            % if any of this block
            if all(idxCurrBlock) % if only 1 block
                % same as overall performance
                prf_block = prf_overall;
            elseif any(idxCurrBlock)
                prf_block = sum(trialErrCounts(:,idxCurrBlock),2)./sum(idxCurrBlock)*100;
            else
                prf_block = zeros(nTrlErrs,1);
            end
            
            % if any of this ocndition 
            if all(idxCurrCond) % if all 1 condition
                % same as overall performance
                prf_cond = prf_overall;
            elseif any(idxCurrCond)
                prf_cond = sum(trialErrCounts(:,idxCurrCond),2)./sum(idxCurrCond)*100;
            else
                prf_cond  = zeros(nTrlErrs,1);
            end
            
            % Data are arranged as 3 bars:
            % [Condition, Block, Overall]
            data = [prf_cond, prf_block, prf_overall];
        end
    end
end


% using shared pool
%teIndxs   = shrdpool.trialErrorIndexes;
%tecounts  = shrdpool.trialErrorCounts;
%currcond  = shrdpool.conditionIndicies; % get current condition indicies
%currblock = shrdpool.blockIndicies;





