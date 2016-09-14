classdef DSPRecentTrialHistory < handle 
    % [DISPLAY] RECENT TRIAL HISTORY

    % txt_ConditionHistory     % 28 characters 
    % txt_TrialErrorsOverall   % 25 ...
    % txt_TrailErrorsCondition % 25 ...

    % htxt(1) -> 'txt_ConditionHistory'
    % htxt(2) -> 'txt_TrialErrorsOverall'
    % htxt(3) -> 'txt_TrailErrorsCondition'
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 14.1.2015 - Jarrod 
    % - changed updateTrialErrorHistory() to remove NaNs and Infs
    % 21.4.2016 - Jarrod, added some documentation/notes

    methods (Static)
        function this = DSPRecentTrialHistory
        end
    end
    
    methods 
        function mUpdate(this,cnds,alltrl,cndtrl,htxt)
            % Condition Number -> recent 28 conditions
            % Trial Errors Overall -> recent 25 trial errors 
            % Trial Errors this condition -> recent 25 trial errors 
            
            % cnds   -> vector of condition numbers
            % alltrl -> all trialerrors 
            % cndtrl -> alltrialerrors this condition
            
            % CONDITION HISTORY
            if ~isempty(cnds)
                this.mUpdateConditionNumber(htxt(1),cnds);
            else
                set(htxt(1),'String','...');
            end
            % OVERALL TRIAL ERROR HISTORY
            if ~isempty(alltrl)
                this.mUpdateTrialErrorHistory(htxt(2),alltrl)
            else
                set(htxt(2),'String','...');
            end
            % THIS CONDITION TRIAL ERROR HISTORY
            if ~isempty(cndtrl)
                this.mUpdateTrialErrorHistory(htxt(3),cndtrl)
            else
                set(htxt(3),'String','...');
            end
             
        end
    end
    
    methods (...
            Sealed = true,...
            Static = true,...
            Access = protected) 
        function mUpdateTrialErrorHistory(htxt,trlerrs) % Overall and Condition
            % maximum is 28 characters (25 with '...')
            % 
            strtxt = textscan(int2str(trlerrs),'%s');
            strtxt = strtxt{1};
            strtxt = strcat(strtxt{:});
            
            % remove NaNs and Infs
            rNans = cell2mat(regexp(strtxt,{'aN'}));
            strtxt([rNans,rNans+1]) = [];
            rInf = cell2mat(regexp(strtxt,{'nf'}));
            strtxt([rInf,rInf+1]) = [];
            
            if numel(strtxt)>25
                strtxt = strtxt(end-24:end);
            end
            set(htxt,'String',['...',strtxt]);
        end

        function mUpdateConditionNumber(htxt,cnds)
            % maximum is 28 characters 
            % 1.5-4ms 
            strtxt = textscan(int2str(cnds),'%s');
            strtxt = strcat({','},strtxt{1});
            strtxt = strcat(strtxt{:});
            if numel(strtxt)>28
                strtxt = strtxt(end-27:end);
                strtxt = strtxt(find(strtxt==',',1,'first'):end);
            end
            set(htxt,'String',strtxt);
        end
    end
    
end










