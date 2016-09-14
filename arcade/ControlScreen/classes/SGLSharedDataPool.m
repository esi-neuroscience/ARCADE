classdef (Sealed) SGLSharedDataPool < handle
    % [SINGLETON] ControlScreen Shared Data Pool
    
    % - store data
    % - perform computations that many plots require 
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    properties (Access = private)

        %  current: [condition, block, trial]
        % sessData: [...
        %     session conditions;...
        %     session blocks;...
        %     session trial errors;...
        %     session reaction times;...
        %     session trial error time stamps]
        %  guiperf: [ITI, UpdateTime]
        current  = zeros(1,3); % 
        sessData = zeros(5,1); %
        %guiPerf  = zeros(1,2); %

    end
    
    methods (Static)
        function this = launch(hfig)
            persistent thisObj
            if isempty(thisObj) || ~isvalid(thisObj)
                thisObj = SGLSharedDataPool;
                % get GUI data 
                gdata       = guidata(hfig);
                trlErrVals  = gdata.trlErrorValues; % trlErrVals
                crrtVal     = gdata.correctValue; % crrtidx
                crrtVecIndx = find(trlErrVals==crrtVal);
                
                thisObj.mComputeTrialMetrics(trlErrVals,crrtVecIndx); %#ok<FNDSB>
            end
            this = thisObj;
        end
    end
    
    methods (Access = private)
        %# constructor
        function this = SGLSharedDataPool
        end
    end
    
    methods
        % update data
        function mUpdateTrialData(this,trialData)
            % INPUT:
            % [1] current condition
            % [2] current block
            % [3] current trial
            
            % [4] trial error
            % [5] reaction time
            % [6] trial error time stamp
            currentTrial = trialData(3);
            
            if currentTrial>1 % current trial
                prevTrial = currentTrial-1;
                
                this.sessData(:,prevTrial) = [...
                    this.current(1:2)';... % previous condition, previous block
                    trialData(4:6)'];      % trial error, reaction time, trial error time stamp
                % 1,2,3, 4,5,6,7
                % put update here!!!!!
            end
            % update current
            this.current = trialData(1:3);

        end
        
        % process data in an efficient way
        function trlMetrics = mComputeTrialMetrics(this, varargin)
            persistent trlErrVals crrtidx
            
            if ~isempty(varargin)
                trlErrVals = varargin{1};
                crrtidx    = varargin{2};
                return;
            end
            
            sessData = this.sessData; %#ok<*PROP>
            current  = this.current;
            
            trlMetrics = [];
            trlMetrics.current        = current;
            trlMetrics.sessData       = sessData;
            trlMetrics.sessSummary    = zeros(1,6);
            % if first trial return
            if current(3)<=1, return; end
            
            % Assign Trial Errors to Indicies
            [trialErrIndxs, err]  = AUXAuxMethods.mAssignIndexToData(trlErrVals, sessData(3,:));
            
            % 2d spare matrix, trial error x num. trials
            trialErrCounts        = AUXAuxMethods.mSparseTrialErrors(numel(trlErrVals),trialErrIndxs);
            % compute cummulative sum
            teCounts = cumsum(trialErrCounts ,2);
            
            % find trial for current condition and current block
            [currCond, currBlock] = AUXAuxMethods.mGetConditionBlockIndicies(current, sessData(1:2,:)); % current condition/block
            
            % *** current condition in the current block ***
            currCond = currCond & currBlock;
            
            % all correct trials
            crrctTrials = sessData(3,:)==trlErrVals(crrtidx);

            % correct for each
            nCrrctCnd = sum(currCond & crrctTrials);  % sum
            nCrrctBlk = sum(currBlock & crrctTrials); % sum
            nCrrctAll = sum(crrctTrials); % find the correct trials
            % total for each
            totalCnd = sum(currCond);
            totalBlk = sum(currBlock);
            totalAll = size(sessData,2);  % total number of trials completed
            
            sessSummary = [...
                nCrrctCnd, nCrrctBlk, nCrrctAll,...
                 totalCnd,  totalBlk,  totalAll,];
            
            % session performance bars
            perfData = AUXAuxMethods.mComputePercent(teCounts);
            % rows all zeros = Nans
            perfData(all(perfData==0,2),:) = nan(1);
            
            
            % make this data available for the plots
            % computed here 
            trlMetrics.trialErrIndxs  = trialErrIndxs;
            trlMetrics.sessSummary    = sessSummary;
            trlMetrics.perfData       = perfData;
            trlMetrics.currCond       = currCond;
            trlMetrics.currBlock      = currBlock;
            trlMetrics.trialErrCounts = trialErrCounts;
            
        end
    end
end















