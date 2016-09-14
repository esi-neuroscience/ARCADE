classdef PNLTrialErrorLegend < AUXTrialErrorLegend %& AUXGUIMethods
    % [PANEL] TRIAL ERROR LEGEND
    % expansions to the panel should go here
    
    % there must always be a correct/indeterminate trial error
    % but allow for the mobility of these in future versions 
    % allow for the possibility of using chars instead of digits
    
    % at the moment nothing depends on the actual value of a correct trial
    % error, rather replying on the number of trial errors, assuming 
    % digits starting at 0, the trial errors are cummulated, thus the index
    % is used to refer to where the correct trial should be in the data
    % vector
    
    % want to know what each trial error color is
    % -> this is fixed in the gui
    % want to know what the name is for each trigger
    % -> this has to be set
    % want to know what each is
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    properties (AbortSet = true)
        % allows the possibility of using chars
        % mapping the correct value onto a particular index
        correctVal = 0; % actual value/char used to indicate a correct
        correctIdx = 1; % index in tags vector/cmap, etc
        
        
        % want to know what it 
        trlErrorCMap    = []; % the colormap stored in the GUI
        trlErrorValues  = []; % the values stored in the GUI
        %trlErrorIndices = [];
    end
    
    methods (Static)
        function this = PNLTrialErrorLegend(hfig)
            % trial error text field Tags
            trxTags = {'trx_0',...
                'trx_1', 'trx_2',...
                'trx_3', 'trx_4',...
                'trx_5', 'trx_6',...
                'trx_7', 'trx_8',...
                'trx_9', 'trx_Inf'};
            % trial error color Tags
            ctxTags = {'ctx_0',...
                'ctx_1', 'ctx_2',...
                'ctx_3', 'ctx_4',...
                'ctx_5', 'ctx_6',...
                'ctx_7', 'ctx_8',...
                'ctx_9', 'ctx_Inf'};
            
            this = this@AUXTrialErrorLegend(hfig,trxTags,ctxTags);
            % get Trial Error Colormap 
            this.trlErrorCMap  = this.mGetTrialErrorColormap;
            % get Trial Error Values
            this.trlErrorValues = this.mGetTrialErrorValues;
        end
    end
end

