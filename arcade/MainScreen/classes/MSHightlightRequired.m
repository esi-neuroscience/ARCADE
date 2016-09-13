classdef MSHightlightRequired < AUXCustomizeUIControl
    % [MAIN SCREEN]
    
    
    %---------------------------------------------%
    % 21.4.2015 - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    properties (SetAccess = immutable)
        hObj_edit
    end

    methods (Static)
        %# constructor 
        function this = MSHightlightRequired(hObj_edit)
            this.hObj_edit = hObj_edit;
            this.mCreateBorderAndListener;
        end
    end
    
    methods
        % # create customized border
        % add listener to self 
        function mCreateBorderAndListener(this)
            lineColor      = [206,56,91]/255; % red  
            lineThickness  = 2;  
            roundedCorners = false;
            
            this.mCreateCustomizedBorder(this.hObj_edit,lineColor,lineThickness,roundedCorners);
            
            % set selected border now 
            this.mSetSelectedBorder([],[]);
            
            % add listener 
            addlistener(this.hObj_edit, 'String','PostSet',@(hObj,evt) this.mSetSelectedBorder(hObj,evt));
        end
        
        %-----------------------------%
        %        Callbacks
        
        %# set selected border 
        function mSetSelectedBorder(this,hObj,evt) %#ok<*INUSD>
            
            %if isempty(get(evt.AffectedObject,'String'))
            if isempty(get(this.hObj_edit,'String'))
                % if empty, set new border 
                this.mSetCustomizedBorder(this.jEdit_border_new);
            else
                % if not empty, set original border
                this.mSetCustomizedBorder(this.jEdit_border_orig);
            end
            drawnow;
        end
    end
end

