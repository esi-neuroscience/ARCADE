classdef PNLSessionSummary < handle
    % [PANEL] SESSION SUMMARY
    % - a concise summary/inventory of the current session 
    % - an inventory of trial counts correct/total
    % - previous ITI/ Control GUI update time (gui performance)
    
    % --- dependencies ---
    % AUXAuxMethods < handle
    % + varargout = mGetHandles(hfig,varargin)

    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    methods (Static = true)
        function this = PNLSessionSummary(hfig)
            %gdata = guidata(hfig); % gui data 
            
            Tags = {...
                'txt_CurrentCondition';...
                'txt_CurrentBlock';...
                'txt_CurrentTrial';...
                'txt_WriteTime';...
                'txt_UpdateTime';...
                'txt_CorrectCondition';...
                'txt_CorrectBlock';...
                'txt_CorrectOverall';...
                'txt_TotalCondition';...
                'txt_TotalBlock';...
                'txt_TotalOverall'};
            % get handles 
            % other functions using the handles expect a double vector
            htxt = cell2mat(AUXAuxMethods.mGetHandles(hfig,Tags));
            
            this.mUpdate([0,0,0],[0,0],zeros(1,6),htxt);
            %this.mUpdate([0,0,0],[0,0],[],htxt,gdata.correctValue);
        end
    end
    
    methods (Static)
        % no superclass method
        function mUpdate(current,guiperf,txtdata,varargin)
            persistent htxt
            
            if ~isempty(varargin)
                htxt = varargin{1};
            end
            % update fields
            AUXTextField.mUpdateTextField(htxt,[current,guiperf,txtdata]);
        end
    end
    
    
    methods (...
            Access = private,...
            Hidden = true)
        %# function to update plot without precomputing the data 
        % in constructor -> this.mUpdate([0,0,0],[0,0],[],htxt,gdata.correctValue); 
        function mUpdate_computeOnTheFly(current,guiperf,sessData,varargin)
            persistent htxt crrtidx %
            if ~isempty(varargin)
                htxt     = varargin{1}; % text field handles 
                crrtidx  = varargin{2}; % index of correct trial error (sorted numbers)
                txtdata  = zeros(1,6);
            else
                % current: [condition, block, trial]
                % guiperf: [WriteTime, UpdateTime]
                % Correct/Total
                
                [currcond, currblock] = AUXAuxMethods.mGetConditionBlockIndicies(current, sessData);
                
                % all correct trials
                crrctTrials = sessData(3,:)==crrtidx;
                
                % correct for each 
                crrctCnd = sum(currcond & crrctTrials);  % sum
                crrctBlk = sum(currblock & crrctTrials); % sum
                crrctAll = sum(crrctTrials); % find the correct trials
                % total for each
                totalCnd = sum(currcond);
                totalBlk = sum(currblock);
                totalAll = size(sessData,2); % total number of trials completed
                
                % data to plot
                txtdata = [...
                    crrctCnd,crrctBlk,crrctAll,...
                    totalCnd,totalBlk,totalAll,];

                
            end
            
            % update fields
            AUXTextField.mUpdateTextField(htxt,[current,guiperf,txtdata]);
            
        end
    end
end
