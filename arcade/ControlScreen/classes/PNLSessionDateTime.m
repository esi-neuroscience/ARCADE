classdef PNLSessionDateTime < handle
    % [PANEL]
    

    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 4.3.2015  - Jarrod, fixed date typo
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    methods (Static = true)
        function this = PNLSessionDateTime(hfig)
            Tags = {...
                'txt_Date';...
                'txt_StartTime';...
                'txt_EndTime'};
            htxt = cell2mat(AUXAuxMethods.mGetHandles(hfig,Tags));
            this.mSetDate(htxt);
        end
    end
    
    methods (Static = true)
        function mSetDate(varargin)
            persistent htxt
            % set date and start time 
            % then set end time 
            
            if ~isempty(varargin)
                htxt = varargin{1};
            end
            
            today     = AUXDateTime.mGetTodaysDate;
            startTime = AUXDateTime.mGetTimeNow24Hour;
            endTime   = '';
            
            set(htxt(1),'String',today);
            set(htxt(2),'String',startTime);
            set(htxt(3),'String',endTime);
            
            %startTime = datestr(datestr(now,'HH:MM AM'),'HH:MM')
            %endTime = datestr(datestr(now,'HH:MM AM'),'HH:MM')
        end
    end
    
    
end

