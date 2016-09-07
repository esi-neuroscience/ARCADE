classdef AUXAuxMethods < handle 
    % [AUXILLARY] Methods that are general to many plots/panels 
    
    % Classes that use this class:
    %   PNLPerformanceBars
    %   PNLRecenTrialHistory 
    %   PNLSessionPerformance

    %# assignIndexToData()
    % + Assign trial errors to appropriate index 
    % chars:
    % errvec = {'A','B','C','D'};   % cell vector
    % data = {'B','C','A','B','B'}; % cell vector 
    % assignvec = cellfun(@(x) find(strcmp(x,errvec)),data);
    
    % numeric:
    % errvec = 0:10; % this order defines the order in the performance data
    % data = randi(11,1,100)-1;
    % assignvec = arrayfun(@(x) find(x==errvec),data);
    
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 13.1.2015 - Jarrod 
    % - made changes to mAssignIndexToData()
    % - made changes to mCummulativeTrialErrors()
    % - made changes to mGetConditionBlockIndicies()
    % - added function to get handles from a cell 
    % 14.1.2015 - Jarrod
    % - added m to the beginning of method names 
    %   to help better distinguish methods from properties
    % 16.1.2015 - Jarrod
    % - added a sparse version of mCummulativeTrialErrors
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    
    methods (Static)
        function this = AUXAuxMethods
        end
    end
    
    methods (...
            Sealed = true,...
            Static = true)
        % assign indices to the values in the data from the matchvec
        % in the order that the [matchvec] is given
        % * data and matchvec must match in class type
        % * data can be numeric or char [chars are case sensitive]
        function [assignidx, err] = mAssignIndexToData(matchvec,data)
            err = false; % error 
            
            if iscell(matchvec) && iscell(data)            %# character input
                try
                    % *case sensitive*
                    assignidx = cellfun(@(x) find(strcmp(x,matchvec)),data);
                catch
                    err = true; % flag error
                    assignidx = cellfun(@(x) find(strcmp(x,matchvec)),data,'unif',0);
                end
            elseif isnumeric(matchvec) && isnumeric(data)  %# numeric input
                try
                    assignidx = arrayfun(@(x) find(x==matchvec),data);
                catch
                    err = true; % flag error
                    assignidx = arrayfun(@(x) find(x==matchvec),data,'unif',0);
                end
            else
                % *error: input and data must agree*
                assignidx = [];   % return nothing 
                err       = true; % flag error 
                return;
            end
            
            if err
                % ** set unassignable to dummy value **
                % if a match could not be made
                % (i.e, there is a value present in the data...
                %  that is not in the matcvec, the result is an empty cell)
                
                % find trials where something went wrong
                flagtrls = cellfun(@isempty,assignidx); % find empty cells
                assignidx(flagtrls) = {nan(1)};         % assign a {dummy value}
                assignidx = cell2mat(assignidx);        % return index assignments
            end
        end

        %# cummulative trial errors over trials
        % INPUT:
        %   indxData          = row vector of data as indexes of a match
        %   maxPossibleIndex  = maximum possible index 
        % OUTPUT:
        %   counts            = 2D matrix of cumsums [maxPossibleIndex, length(indxData)]
        function counts = mCummulativeTrialErrors(maxIndx,indxData)
            ntrl   = numel(indxData);
            counts = zeros(maxIndx,ntrl); 
            % -- create 2D matrix of cummulative sums --  
            % treat the index vector as row indices, 
            % and the length of the vector [1:N] as column indices 
            inds      = sub2ind([maxIndx,ntrl],indxData,1:ntrl);
            counts(inds) = 1;           % assign a value of 1 to each position in the 2d matrix
            counts = cumsum(counts,2);  % cummulative sum
            % if there are data already, then append
            %if ~isempty(counts) && maxIndx==size(counts,1)
            %    lastcount = counts(:,end);
            %    newcounts = [counts, lastcount(:,ones(1,ntrl)) + newcounts]; 
            %end
        end
        
        %# same function as above but no cummulative sum 
        function counts = mSparseTrialErrors(maxIndx,indxData)
            ntrl   = numel(indxData);
            counts = zeros(maxIndx,ntrl); 
            % -- create 2D matrix of cummulative sums --  
            % treat the index vector as row indices, 
            % and the length of the vector [1:N] as column indices 
            inds      = sub2ind([maxIndx,ntrl],indxData,1:ntrl);
            counts(inds) = 1;           % assign a value of 1 to each position in the 2d matrix
        end
        
        %# compute percent from counts (cummulative sum) matrix/vector
        % INPUT:
        %   counts  -> returned by cummulativeTrialErrors()
        % OUPUT: 
        %   percentCounts -> vector [1 x size(counts,1)]
        function percentCounts = mComputePercent(counts)
            [N,ntrls] = size(counts);  % usually N = num. trial errors, ntrls = num. trials
            trlnum    = 1:ntrls;       % trial number vector
            percentCounts = counts./trlnum(zeros(1,N)+1,:)*100;
        end
        
        %# get the indicies of the current condition/block
        % INPUT:
        %   sessData = [...
        %    conditions vector; ...
        %    block vector; ...
        %    trialerrors vector]; *does not include current trial*
        %   current = [this condition, this block]
        % OUTPUT:
        %   currcond  -> logical vector of current condition trials 
        %               *(in current block)
        %   currblock -> logical vector of current block trials
        function [currcond,currblock] = mGetConditionBlockIndicies(current, sessData)
            % most recent block of the current block
            idxblock  = cumsum(diff([0,sessData(2,:)])); % blocks incremented (most recent block)
            currblock = (idxblock==max(idxblock)) & (sessData(2,:)==current(2));
            
            % indicies of this condition, within this current block
            currcond = (sessData(1,:)==current(1));% & currblock;
        end
        
        %# GET HANDLES 
        function varargout = mGetHandles(hfig,varargin)
            gethndls = @(strTag) findobj(hfig,'Tag',strTag);
            for k = 1:length(varargin)
                varargout(k) = {cellfun(@(tag) gethndls(tag),varargin{k},'unif',0)};  %#ok<AGROW>
            end
        end

    end
end



% does session data include the last trial
% used to update the errors for this condition
% used to get the indicies for the session performance/ etc
% this will be used at the end of a trial
% but also at the start of a trial
% find the number of trials corrrect
% sessionData, should not include the trial being processed

% always update at the start of a trial
% if user clicks pause/quit process update first
% then allow pause or quit













