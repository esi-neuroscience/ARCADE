classdef  SPCPanelRegister < handle
    % [SUPERCLASS]
    
    % SUBCLASSES:
    %   ControlScreen
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    properties (Access = protected)
        %trlErrLeg =[]; % trial error legend
        evtLog    =[]; % event log
    end
    
    methods (Static)
        %# constructor
        function this = SPCPanelRegister
        end
    end
    
    methods (Sealed = true)
        
        function mUpdateControlDisplay(this, task, data)
            persistent pnlObjs
            %persistent shrdDataObj
            
            switch task
                case 'init'
                    % ------------ setup panels -------------- %
                    if ~isempty(pnlObjs)
                        % ensure panel objects are deleted
                        structfun(@(sObj) delete(sObj), pnlObjs);
                        pnlObjs = [];
                    end
                    hfig = this.hfig;
                    pnlObjs.SS_ = PNLSessionSummary(hfig);     % mUpdate(current,guiperf,txtdata)
                    pnlObjs.RT_ = PNLReactionTime(hfig);       % mUpdate(reactionTime)
                    pnlObjs.TEH = PNLTrialErrorHist(hfig);     % mUpdate(trial error time stamps, trial errors indexed)
                    pnlObjs.SP_ = PNLSessionPerformance(hfig); % mUpdate(perfData)
                    pnlObjs.RTH = PNLRecenTrialHistory(hfig);  % mUpdate(sessData,currCond)
                    pnlObjs.PB_ = PNLPerformanceBars(hfig);    % mUpdate(trialErrCounts, idxCurrCond, idxCurrBlock)
                    pnlObjs.SDT = PNLSessionDateTime(hfig);    % auto-sets current date and time  
                    pnlObjs.BTN = PNLButtons(hfig);
                    %pnlObjs.PT  = PNLPreviousTrial(hfig);
                    
                    % fectch shared data object
                    %shrdDataObj = SGLSharedDataPool.fetch;
                    
                    pnlObjs.SDT.mSetDate; % set current date and time 
                    
                    % create the evnt log object
                    this.evtLog = SGLEventLog.fetch(hfig);
                    drawnow;
                    return;
                case 'delete'
                    if ~isempty(pnlObjs)
                        % ensure panel objects are deleted
                        structfun(@(sObj) delete(sObj), pnlObjs);
                        pnlObjs = [];
                        this.evtLog.delete;
                    end
                    return;
                case 'update'
                    %  current: [condition, block, trial]
                    % sessData: [...
                    %             session conditions;...
                    %             session blocks;...
                    %             session trial errors;...
                    %             session reaction times;...
                    %             session trial error time stamps]
                    %  guiperf: [UpdateTime, ITI]
                    
                    % first Trial -> only update SessionSummary
                    %                and reset EventLo
                    % mUpdate(current,guiperf,txtdata)
                    pnlObjs.SS_.mUpdate(data.current,data.guiperf,data.sessSummary);
                    % reset Event Log String
                    this.evtLog.mResetString;
                    
                    if data.current(3)>1
                        pnlObjs.RT_.mUpdate(data.sessData(4,:));
                        pnlObjs.TEH.mUpdate(data.sessData(5,:),   data.trialErrIndxs);
                        pnlObjs.SP_.mUpdate(data.perfData);
                        pnlObjs.RTH.mUpdate(data.sessData(1:3,:), data.currCond);
                        pnlObjs.PB_.mUpdate(data.trialErrCounts,  data.currCond, data.currBlock);
                    end
            end

        end % function
    end % methods
    
    methods
        function delete(this)
            this.mUpdateControlDisplay('delete',[]);
        end
    end
    
end % classdef

