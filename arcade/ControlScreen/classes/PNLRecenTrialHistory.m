classdef PNLRecenTrialHistory < DSPRecentTrialHistory
    % [PANEL] RECENT TRIAL HISTORY
    % expansions to the panel should go here
    % if multiple panels require the same computations
    % overlaoding the update function in the panel object os the way to go
    % thus those should also be moved up from lower levels

    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    methods (Static) 
        function this = PNLRecenTrialHistory(hfig)
            htxt    = [];
            htxt(1) = findobj(hfig,'Tag','txt_ConditionHistory');
            htxt(2) = findobj(hfig,'Tag','txt_TrialErrorsOverall');
            htxt(3) = findobj(hfig,'Tag','txt_TrailErrorsCondition');
            this    = this@DSPRecentTrialHistory;
            
            % set text handles
            % *signature different from super
            this.mUpdate([],[],htxt); 
        end
    end
    
    methods 
        function mUpdate(this,sessData,currcond,varargin)
            persistent htxt
            if ~isempty(varargin)
                htxt     = varargin{1};
                mUpdate@DSPRecentTrialHistory(this,[],[],[],htxt);
                return;
            end
            
            mUpdate@DSPRecentTrialHistory(this,sessData(1,:),sessData(3,:),sessData(3,currcond),htxt);
        end
    end
    
    % 
    methods(...
            Access = private,...
            Hidden = true)

        %# function to update plot without precomputing the data 
        % in constructor -> this.mUpdate([],[],htxt); 
        function mUpdate_computeOnTheFly(this,current,sessData,varargin)
            persistent htxt 
            if ~isempty(varargin)
                htxt     = varargin{1};
                %mUpdate@DSPRecentTrialHistory(this,[],[],[],htxt);
                return;
            end;
            
            % *if not using shared pool (needs current)
            % cndblk  -> [conditions vector; block vector; trialerrors]
            % current -> [this condition, this block]
            [currcond,~] = AUXAuxMethods.mGetConditionBlockIndicies(current,sessData);
            %[currcond,currblock] = getConditionBlockIndicies(current, sessData)
            % get this condition indicies
            %currcond = shrdpool.conditionIndicies; % get current condition indicies
            
            % call superclass method
            % vector of conditions #s, vector of trialerrors,
            % sessData -> does not include current trial
            % condition numbers, trial errors overall, trial errors this condition
            
            % cnds   -> vector of condition numbers
            % alltrl -> all trialerrors
            % cndtrl -> alltrialerrors this condition
            
            %mUpdate@DSPRecentTrialHistory(this,sessData(1,:),sessData(3,:),sessData(3,currcond),htxt);
            
        end
    end
end

