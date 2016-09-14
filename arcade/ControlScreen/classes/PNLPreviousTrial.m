classdef PNLPreviousTrial < PLTEyePosition
    % [PANEL] PREVIOUS TRIAL
    % expansions to the panel should go here

    % txt_PreviousTrialCondition
    % txt_PreviousTrialBlock
    % txt_PreviousTrialTrialError
    % txt_PreviousTrialReactionTime
    
    % ax_PreviousTrialEyePlot
    % uip_PreviousTrialScreen
    % text and previous trial eye plot 
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    properties (AbortSet = true)
        mode@char = 'screen'; % fix 
    end
    
   methods (Static)
        function this = PNLPreviousTrial(hfig)
            Tags = {...
                'txt_PreviousTrialCondition';...
                'txt_PreviousTrialBlock';...
                'txt_PreviousTrialTrialError';...
                'txt_PreviousTrialReactionTime'};            
            htxt = AUXTextField.getHandles(hfig,Tags);
            
            ax_parent = findobj(hfig,'Tag','ax_PreviousTrialEyePlot');
            this = this@PLTEyePosition(ax_parent);
            this.mUpdate([0,0],[0,0,0,0],htxt);
        end
   end
    
   methods 
       % extend update 
       function mUpdate(this,eyedata,txtdata,varargin)
           persistent htxt
           if ~isempty(varargin)
               htxt     = varargin{1}; % text field handles
           end
           % eyedata = [x,y] column vectors 
           % txtdata = [condition, block, trial error, RT]
           
           % update fields
           AUXTextField.mUpdateTextField(htxt,txtdata);
           
           % update eye data
           %pltUpdate@PLTEyePosition(this,eyedata);
           
       end
   end
end

