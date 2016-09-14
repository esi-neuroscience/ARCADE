classdef DSPEventLog < handle 
    % EVENT LOG
    % *font is set to FixedWidth
    
    % Max String Size:
    % 5 digit timestamps 
    % 14 character eventmarkers
    % 37 lines 
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    properties (...
            AbortSet  = true,...
            SetAccess = immutable)
        htxt % handle to text field 
    end
    
    methods (Static = true)
        function this = DSPEventLog(htxt)
            this.htxt = htxt;
            this.mResetString; % make is empty
        end
    end
    
    methods
        %# UPDATE TEXT FIELD
        function mUpdateString(this,timestamp,eventmarker)
            persistent htxt
            if isempty(htxt), htxt = this.htxt; end
            
            % create print string
            str_timestamp   = ['       ',int2str(timestamp)];
            str_eventmarker = [eventmarker,'              '];
            
            print_str = [str_timestamp(end-4:end),' - ',str_eventmarker(1:14)];
            
            current_str = get(htxt,'String');
            if size(current_str,1)<37
                % restart textfields
                print_str = [current_str;print_str];
            end
            set(htxt,'String',print_str);
        end
        
        %# CLEAR TEXT FIELD
        function mResetString(this)
            set(this.htxt,'String',[]);
        end
        %# DELETE OBJECT
        %function delete(this)
            %this.htxt = [];
            %this.mResetString;
        %end
    end
    
end

