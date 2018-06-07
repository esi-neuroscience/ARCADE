classdef  SPCPanelRegister < handle
    % [SUPERCLASS] ControlScreen Panel Registrar
    
    % SUBCLASSES:
    %   ControlScreen
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    %  6.4.2018 - Jarrod, added documentation and removed dead features
    
    methods (Static)
        %# constructor
        function this = SPCPanelRegister
        end
    end
    
    methods (Sealed = true)
        
        function mUpdateControlDisplay(this, task, data)
            persistent pnlObjs
            
            switch task
                case 'init'
                    % ------------ setup panels -------------- %
                    nDeletePanelObjects();  % delete if they exist 
                    
                    hfig = this.hfig;
                    pnlObjs.SS_ = PNLSessionSummary(hfig);     % mUpdate(current,guiperf,txtdata)
                    pnlObjs.RT_ = PNLReactionTime(hfig);       % mUpdate(reactionTime)
                    pnlObjs.TEH = PNLTrialErrorHist(hfig);     % mUpdate(trial error time stamps, trial errors indexed)
                    pnlObjs.SP_ = PNLSessionPerformance(hfig); % mUpdate(perfData)
                    pnlObjs.RTH = PNLRecenTrialHistory(hfig);  % mUpdate(sessData,currCond)
                    pnlObjs.PB_ = PNLPerformanceBars(hfig);    % mUpdate(trialErrCounts, idxCurrCond, idxCurrBlock)
                    pnlObjs.SDT = PNLSessionDateTime(hfig);    % auto-sets current date and time  
                    pnlObjs.BTN = PNLButtons(hfig);            % Manual Control Buttons
                    
                    % set current date and time 
                    pnlObjs.SDT.mSetDate; 
                    drawnow;
                    return;
                case 'delete'
                    nDeletePanelObjects(); % delete if they exist 
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
                    
                    % action on first Trial -> only update SessionSummary
                    % general update method -> mUpdate(current,guiperf,txtdata)
                    pnlObjs.SS_.mUpdate(data.current,data.guiperf,data.sessSummary);              % SessionSummary 

                    if data.current(3)>1  % if TrialNumber >1
                        pnlObjs.RT_.mUpdate(data.sessData(4,:));                                  % Reaction Time
                        pnlObjs.TEH.mUpdate(data.sessData(5,:),   data.trialErrIndxs);            % Trial Error History
                        pnlObjs.SP_.mUpdate(data.perfData);                                       % Session Performance
                        pnlObjs.RTH.mUpdate(data.sessData(1:3,:), data.currCond);                 % Recent Trial History
                        pnlObjs.PB_.mUpdate(data.trialErrCounts,  data.currCond, data.currBlock); % Performance Bars
                    end
            end
            
            % nested function(s)
            function nDeletePanelObjects()
                if ~isempty(pnlObjs)
                    % ensure panel objects are deleted
                    structfun(@(sObj) delete(sObj), pnlObjs);
                    pnlObjs = [];
                end
            end % nested function
        end % function
    end % methods
    
    methods
        function delete(this)
            this.mUpdateControlDisplay('delete',[]);
        end
    end
    
end % classdef

