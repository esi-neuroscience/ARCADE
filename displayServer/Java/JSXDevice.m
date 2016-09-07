classdef JSXDevice < handle
    % [JAVA SWING] DEVICE
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 29.4.2016 - Jarrod, added some documentation 
    
    properties (...
            AbortSet  = true,...
            SetAccess = protected)
        jScreenDevices
        jDeviceID
    end
    
    properties 
       verbose = true; 
    end
    
    methods (Static)
        %# constructor
        function this = JSXDevice
            % get screen devices
            jScreenDevices = java.awt.GraphicsEnvironment.getLocalGraphicsEnvironment().getScreenDevices(); %#ok<*PROP>

            % get device id 
            this.jDeviceID = arrayfun(@(dev) dev.getScreen(), jScreenDevices);
            
            ndev = numel(jScreenDevices);
            
            if this.verbose
                disp(['Detected ',num2str(ndev),' screen devices.']); 
            end
            
            this.jScreenDevices = jScreenDevices;
        end
    end

    methods (Sealed = true)
        
        %# get settings for the device 
        function deviceModes = mGetScreenDeviceSettings(this,devID,devMode)
            
            % anonymous function
            % pixel width, pixel height, refresh rate
            getDisplayModeString = @(dsMode) [dsMode.getWidth(),dsMode.getHeight(), dsMode.getRefreshRate()];
            
            % for this specific device 
            thisDev = find(this.jDeviceID==devID); %#ok<*EFIND>
            if isempty(thisDev)
                error('Device not found.');
            end

            switch devMode
                case 'current'
                    % get current device settings 
                    jDevModes = this.jScreenDevices(thisDev).getDisplayMode();
                case 'all'
                    % get all possible device settings
                    jDevModes = this.jScreenDevices(thisDev).getDisplayModes();
                otherwise 
                    % nothing 
            end
            
            % return device modes 
            deviceModes = arrayfun(@(dsMode) getDisplayModeString(dsMode), jDevModes, 'unif',0);
        end
    end

end


