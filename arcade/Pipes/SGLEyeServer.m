classdef (Sealed) SGLEyeServer < handle
    % [SINGLETON] EYESERVER - singleton class
    % polls the eye signal (Waitable Timer)
    % knows about NI-DAQ
    % clean this class up
    
    % convert data to degrees
    % separate class
    
    
    % can be set to simulation mode, or poll dac card
    
    % TO DO:
    % - add ready (timer start function)
    % - add methods to acces timer properties
    % - add polling stop function (timer completion function)
    % - add conversion degrees/pixels/volts
    % - add both eyes, or right/left
    
    
    % allow access to timer
    % cannot change properties of timer while running
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    properties (SetAccess = immutable)
        nidaqObj % nidaq object
    end
    
    
    methods (Static)
        function this = launch
            persistent thisObj
            if isempty(thisObj) || ~isvalid(thisObj)
                thisObj = SGLEyeServer;
            end
            this = thisObj;
        end
    end
    
    methods (...
            Access = private,...
            Hidden = true)
        
        %# constructor
        function this = SGLEyeServer
            %---------------------------------------%
            eyelines = {'Dev1/ai0:1'}; % left eye
            %eyelines = {'Dev1/ai2:3'}; % right eye
            
            nidaqObj = mNIDAQ; %#ok<*PROP>               % create object
            nidaqObj.daqmxCreateAIVoltageChan(eyelines); % create channels
            this.nidaqObj = nidaqObj;
            %---------------------------------------%
            % accessing a persistent is faster than a property
            % therefore, I use a perisstent giving slightly better performance
            this.mFetchEyePosition; % init peristent
            
        end
        
    end
    
    methods
        
        %# fetch eye sample
        % return eye position in pixels, and [x_pos, y_pos];
        function eye_pos = mFetchEyePosition(this)
            persistent nidaqObj volts2pixels
            
            if isempty(nidaqObj) || ~isvalid(nidaqObj)
                nidaqObj = this.nidaqObj;
            end
            
            if isempty(volts2pixels)
                vgain      = [10 10]; % ****** hard-coded at the moment******
                screensize = [1680 1050];
                volts2pixels = AUXEyeSignalUnitConverter.volts2pixels(vgain,screensize);
            end
            
            % set eye position
            %this.eye_pos = eyeObj.daqmxReadAnalogF64(1);
            eye_pos = nidaqObj.daqmxReadAnalogF64(1);
            % convert eye position into pixels
            [xeye,yeye] = volts2pixels(eye_pos(1),eye_pos(2));
            eye_pos = [xeye,yeye];
            
        end
        %# delete
        function delete(this)
            
            % close NI-DAQ
            if ~isempty(this.nidaqObj)
                delete(this.nidaqObj);
            end
        end
    end
end
