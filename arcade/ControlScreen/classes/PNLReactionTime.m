classdef PNLReactionTime < PLTReactionTime
    % [PANEL] REACTION TIME HISTOGRAM
    % expansions to the panel should go here
    
    % this PANEL only has one plot
    % -> PLTReactionTime

    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    methods (Static)
        function this = PNLReactionTime(hfig)
            ax_parent = findobj(hfig,'Tag','ax_ReactionTime');
            this = this@PLTReactionTime(ax_parent);
        end
    end
    
    % can overload update (method not Sealed)
    
end

