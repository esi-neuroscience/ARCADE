classdef AUXDateTime < handle 
    % [AUXILLARY]
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes

    
    methods (Static)
        function this = AUXDateTime
        end
        
        %# todays date
        function today = mGetTodaysDate
            today     = datestr(now,'dd.mm.yy');
            %today     = datestr(now,'yy.mm.dd');
        end
        
        %# 24 hour time 
        function timeNow = mGetTimeNow24Hour
            timeNow = datestr(datestr(now,'HH:MM AM'),'HH:MM');
        end
        
    end
    
end

