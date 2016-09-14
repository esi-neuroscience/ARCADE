classdef JSXSpinner < SPCJavaObjectDefinition
    % [JAVA SWING]
    
    % specific functions related to the jSpinner
        
    
    % must implement these 
    % mCreateJavaObject(this,varargin); % create object 
    % mSetGetFunctions(this);           % set/get 
    
    
    % INHERITANCE:
    % JSXSpinner < SPCJavaObjectDefinition < handle
    
    %------------------------------%
    % unknown - Jarrod, wrote class
    
    
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
        
        % java swing object
        jModel
        jSpinner
        jhSpinner
    end
    
    
    properties (AbortSet = true)
        % set by user 
        value@double      scalar = 10;
        minValue@double   scalar = 0;
        maxValue@double   scalar = 1000;
        step@double       scalar = 1;
    end

    methods (Static)
        %# Create an instance of the spinner 
        function this = JSXSpinner(hfig)
            this.hfig = hfig; %#ok<*PROP>
        end
        
    end

    methods (Sealed = true)

        %# create spinner and add to figure
        function mCreateJavaObject(this,varargin)
            
            if ~isempty(varargin)
                this.value    = varargin{1}(1);
                this.minValue = varargin{1}(2);
                this.maxValue = varargin{1}(3);
                this.step     = varargin{1}(4);
            end

            % create spinner model 
            jModel = javax.swing.SpinnerNumberModel(...
                this.value,...
                this.minValue,...
                this.maxValue,...
                this.step);
            
            % create spinner 
            jSpinner  = javax.swing.JSpinner(jModel);
            % add to figure
            jhSpinner = javacomponent(...
                jSpinner, this.pos, this.hfig);
            
            this.jModel    = jModel;
            this.jSpinner  = jSpinner;
            this.jhSpinner = jhSpinner;
            
            % set font and alignment 
            this.mSetHorizontalAlignment;
            this.mSetFont;
        end
        
        %# set alignment 
        function mSetHorizontalAlignment(this)
            jEditor = this.jSpinner.getEditor();
            jEditor.getTextField().setHorizontalAlignment(javax.swing.JTextField.CENTER);
        end
        
        %# set font 
        function mSetFont(this)
            jEditor = this.jSpinner.getEditor();
            jEditor.getTextField().setFont(java.awt.Font('SansSerif',java.awt.Font.BOLD,15));
        end
        
        %#  Add tool tip
        function mAddToolTip(this, msg)
            this.jhSpinner.setToolTipText(msg);
        end
        
        %# enable/disable
        function mSetEnabled(this, value)
            this.jSpinner.setEnabled(value);
        end
        
        % java swing set/get function 
        %function [setFcn,getFcn] = mRetriveSetGetFunctions(this)
        function mSetGetFunctions(this)
            % set function 
            setFcn = @(~,value) this.jSpinner.setValue(value); 
            % get function 
            getFcn = @(~) this.jSpinner.getValue();
            % add set/get function to user data 
            %set(this.hObj,'UserData',{setFcn,getFcn});
            this.mSetUserData(setFcn,getFcn,this.jhSpinner);
        end
    
    end
    
    
    
    % not editable 
    % jSpinner.getEditor().getTextField().setEditable(false);

    % sets it as an integer number 
    % jEditor = javaObject('javax.swing.JSpinner$NumberEditor',jSpinner,'#');
    % jSpinner.setEditor(jEditor);
    
end


