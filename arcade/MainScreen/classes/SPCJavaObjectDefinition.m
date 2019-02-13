classdef SPCJavaObjectDefinition < handle
    % [SUPERCLASS] Java Object Definition
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 29.4.2016 - Jarrod, added some documentation 
    
    properties (...
            Abstract = true,...
            SetAccess = immutable)
        hfig    % figure handle
    end
    
    properties (...
            Abstract  = true,...
            AbortSet  = true,...
            SetAccess = protected)
        % set by getting associated frame
        pos      % position 
        hObj     % associated frame object
    end
    
    properties (...
            AbortSet  = true,...
            SetAccess = protected)
        % java objects seem to be offset a bit
        offset = 5;
    end
    
    methods (Static)
        %# constructor
        function this = SPCJavaObjectDefinition
        end
    end
    
    methods (Abstract = true)
        mCreateJavaObject(this,varargin); % create object 
        mSetGetFunctions(this);           % set/get 
    end
    
    methods (Sealed = true)
        %# get the position of the uicontrol
        % where the object should be placed in the figure
        function mGetPosition(this,tag)
            % find the associated frame
            hObj = findobj(this.hfig,'Tag',tag);  %#ok<*PROP>
            % position in figure
            pos = getpixelposition(hObj,true);
            
            % add offset
            pos(1:2) = pos(1:2)+this.offset;
            
            % set frame vibible off
            set(hObj,'Visible','off');
            
            % set properties 
            this.pos  = pos;
            this.hObj = hObj;
        end
        
        %# set user data 
        function mSetUserData(this,setFcn,getFcn,jsxObj)
            
            % javahandle_withcallbacks.javax.swing.JSpinner
            % javahandle_withcallbacks.com.jidesoft.combobox.DateComboBox
            % javahandle_withcallbacks.com.jidesoft.combobox.ColorComboBox
            
            pat = '\.';
            jsxName = regexp(class(jsxObj),pat,'split');

            switch jsxName{end}
                case {'DateComboBox','ColorComboBox'}
                    jsxCall= 'ActionPerformedCallback';
                case {'JSpinner'}
                    jsxCall= 'StateChangedCallback';
                otherwise
            end
            
            set(this.hObj,'UserData',{setFcn,getFcn,jsxObj,jsxCall});

        end
        % delete function
    end
end


