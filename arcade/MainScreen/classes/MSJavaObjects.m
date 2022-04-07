classdef MSJavaObjects < handle 
    % [MAIN SCREEN] JAVA OBJECTS
    
    %---------------------------------------------%
    % 14.4.2015 - Jarrod, minor text changes
    % 14.4.2015 - Jarrod, added a quick and dirty enable JSpinner
    % 15.4.2015 - Jarrod, removed reward eventmarker  
    % 16.4.2015 - Jarrod, changed properties to hidden
    % 17.4.2015 - Jarrod, added tooltips
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    properties (Hidden = true)
       jsxNumberSpinners 
       jsxColorSelectors
       jsxDevice
    end
    
    %# constructor 
    methods (Static)
        function this = MSJavaObjects
        end
    end
    
    
    methods (Access = protected)
        %# java objects 
        function mAddJavaSwingObjects(this)
            % number spinners
            this.mCreateJavaNumberSpinners;
            
            % color selectors
            this.mCreateJavaColorSelectors;
            
            % detect current secondary monitor settings
%%%            this.mDetectScreen;
            
        end
        
        %# java number spinners objects 
        function mCreateJavaColorSelectors(this)
            
            jsxObjects = {};
            jsxTags = {...
                'cfg_BackgroundRGB','<html>Set Color of Task Background Screen';...
                'cfg_PauseRGB',     '<html>Set Color of Pause Screen';};
            
            initValues = [...
                0.5, 0.5,  0.5;... 
                0.38,0.494,0.992];
            
            % Java Number Spinners
            for k = 1:length(jsxTags);

                jsxObjects{k} = JSXColorSelector(this.hfig); % create instance
                jsxObjects{k}.mGetPosition(jsxTags{k});      % get position
                jsxObjects{k}.mCreateJavaObject(initValues(k,:));
                jsxObjects{k}.mSetGetFunctions;
                
                
                if ~isempty(jsxTags{k,2})
                    jsxObjects{k}.mAddToolTip(jsxTags{k,2});
                end
                
            end
            
            this.jsxColorSelectors = jsxObjects;
        end

        
        %# java number spinners objects 
        function mCreateJavaNumberSpinners(this)
            %'<html>This spinner is editable, but only the<br/>preconfigured values can be entered'
            
            jsxObjects = {};
            jsxTags = {...
                'cfg_MonitorDiagonalSize',  '<html>Diagonal Size of Monitor in centimeters';...
                'cfg_DistanceToScreen',     '<html>Distance from monitor in centimeters';...
                'cfg_MaximumNumberOfTrials','<html>Maximum number of trials to run';...
                'cfg_EventMarker_Pause',    '<html>Event Marker sent when "Pause" button is pressed';...
                'cfg_EventMarker_Resume',   '<html>Event Marker sent when "Resume" or "Quit"<br>button pressed during Pause'};
            

            tBits   = 16;
            maxTrig = (2^tBits)-1;
            
            % init values
            initValues = [...
                55.50,  0,     200, 0.01;... 'cfg_MonitorDiagonalSize'
                80.67,  0,     300, 0.01;... 'cfg_DistanceToScreen'
                5000,   1,   10000, 1;...    'cfg_MaximumNumberOfTrials'
                29600,  0, maxTrig, 1;...    'cfg_EventMarker_Pause'
                29601,  0, maxTrig, 1;...    'cfg_EventMarker_Resume'
                ];
            
            % Java Number Spinners
            for k = 1:size(jsxTags,1);
                jsxObjects{k} = JSXSpinner(this.hfig); %#ok<*MCNPN,*AGROW> % create instance
                jsxObjects{k}.mGetPosition(jsxTags{k,1});                  % get position
                jsxObjects{k}.mCreateJavaObject(initValues(k,:));
                jsxObjects{k}.mSetGetFunctions;
                
                if ~isempty(jsxTags{k,2})
                    jsxObjects{k}.mAddToolTip(jsxTags{k,2});
                end
            end
            
            this.jsxNumberSpinners = jsxObjects;
 
        end
        
        %# detect the secondary monitor 
        function mDetectScreen(this)
            
            SecScreenTags = {...
                'cfg_MonitorResolution_width',...
                'cfg_MonitorResolution_height',...
                'cfg_MonitorRefreshRate'};
            
            txtObjs = cellfun(@(tag) findobj(this.hfig,'Tag',tag),SecScreenTags,'unif',0);
            
            % create an instance
            jsxDevice      = JSXDevice; %#ok<*PROP>
            this.jsxDevice = jsxDevice;
            
            % get the current settings for the secondary monitor
%%%            curSettings = jsxDevice.mGetScreenDeviceSettings(1,'current');
            % curSettings = jsxDevice.mGetScreenDeviceSettings(0,'current'); %specific to lab209, we don't understand why this change was necessary
            
            mMakeString = @(num) int2str(num);
            
            for k = 1:length(txtObjs)
                set(txtObjs{k},'String',mMakeString(curSettings{1}(k)));
            end

        end

    end
    
end

