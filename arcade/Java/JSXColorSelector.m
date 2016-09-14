classdef JSXColorSelector < SPCJavaObjectDefinition
    % [JAVA SWING]

    % INHERITANCE: 
    %   JSXColorSelector < ...
    %       SPCJavaObjectDefinition < handle
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 17.4.2015 - Jarrod, added tooltip method 
    % 29.4.2016 - Jarrod, added some documentation 
    
    properties (...
            SetAccess = immutable)
        hfig    % figure handle
    end
    
    properties (...
            AbortSet  = true,...
            SetAccess = protected)
        % set by getting associated frame
        pos  % position 
        hObj % associated frame object
        
        color = [0.4,0.4,0.4];
        
        % jide object
        jCombo
        jhCombo
        
    end


    methods (Static)
        %# Create an instance of the color selector 
        function this = JSXColorSelector(hfig)
            this.hfig = hfig; %#ok<*PROP>
        end
        
    end
    
    % must implement these 
    % mCreateJavaObject(this,varargin); % create object 
    % mSetGetFunctions(this);           % set/get 
    
    
    methods (Sealed = true)

        %# create spinner and add to figure
        function mCreateJavaObject(this,varargin)
            
            if ~isempty(varargin)
                this.color    = varargin{1};
            end
            
            jCombo = javaObjectEDT(com.jidesoft.combobox.ColorComboBox);
            [jhCombo,hContainer] = javacomponent(jCombo,this.pos,this.hfig);
            
            c = this.color;
            
            jCombo.setSelectedColor(java.awt.Color(c(1),c(2),c(3)));

            this.jCombo   = jCombo;
            this.jhCombo  = jhCombo;
        end
        
        % java set/get function
        function mSetGetFunctions(this)
            % set function 
            setFcn = @(~,value) this.jCombo.setSelectedColor(java.awt.Color(value(1),value(2),value(3)));
            % get function 
            getFcn = @(~) this.jCombo.getSelectedColor().getColorComponents([]);
            % add set/get function to user data 
            %set(this.hObj,'UserData',{setFcn,getFcn});
            this.mSetUserData(setFcn,getFcn,this.jhCombo);
        end
    
        %#  Add tool tip
        function mAddToolTip(this, msg)
            this.jhCombo.setToolTipText(msg);
        end
        
        
    end
    
%     figure;
%     jCombo = javaObjectEDT(com.jidesoft.combobox.ColorComboBox);
%     [hjCombo,hContainer] = javacomponent(jCombo,[10,10,200,20],gcf);
%     
%     % set the color
%     jCombo.setSelectedColor(java.awt.Color(0.5,0.5,0.8));
%     % get selected color form 0 to 1, r,g,b
%     selectedColor = jCombo.getSelectedColor().getColorComponents([]);
    
    
end


