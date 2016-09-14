classdef AUXCustomizeUIControl < handle 
    % [AUXILLARY] CUSTOMIZE UICONTROL
    % used in the construction of the MainScreen GUI
    
    
    % uses findjobj() 
    
    %---------------------------------%
    % 21.4.2015 - Jarrod, wrote class
    % 29.4.2016 - Jarrod, added some documentation 
    
    properties (...
            AbortSet  = true,...
            SetAccess = protected)
       jEdit
       jEdit_border_orig
       jEdit_border_new
    end
    

    methods (Static)
        %# constructor
        function this = AUXCustomizeUIControl
        end
    end
    
    
    methods (Access = protected)
        %--------------------------------%
        %       UICONTROL EDIT 
        %# create customize boarder 
        function mCreateCustomizedBorder(this,hObj_edit,lineColor,lineThickness,roundedCorners)
            jEdit = findjobj(hObj_edit); %#ok<*PROP>
            
            % java object border is immutable
            % thus create new
            if isempty(lineColor)
                lineColor = java.awt.Color(1,1,1);
            else
                lineColor = java.awt.Color(lineColor(1),lineColor(2),lineColor(3));
            end
            
            if isempty(lineThickness)
                lineThickness  = 1;  % pixels
            end
            if isempty(roundedCorners)
                roundedCorners = false;
            end
            % create new border object
            newjBorder = javax.swing.border.LineBorder(lineColor,lineThickness,roundedCorners);
            
            % set properties 
            this.jEdit             = jEdit; 
            this.jEdit_border_orig = jEdit.Border;
            this.jEdit_border_new  = newjBorder;

        end
        
        %# set customized border 
        function mSetCustomizedBorder(this,border)
            
            if ~isempty(border)
                this.jEdit.Border = border;
                this.jEdit.repaint;  % redraw the modified control
            end
        end
    end 
end

