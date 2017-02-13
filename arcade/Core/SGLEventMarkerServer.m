classdef (Sealed) SGLEventMarkerServer < handle
    % [SINGLETON]
    
    % Should run a timing test with this version
    % and a version using a peristent variable
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 14.7.2015 - Jarrod, replaced decimalToBinaryVector() with dec2bin()-'0'
    % - because decimalToBinaryVector() is in the daq toolbox, and -'0' dec2bin returns a string
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    
    properties (SetAccess = immutable)
        nidaqObj % object for
    end
    
    methods (Static)
        function this = launch
            persistent thisObj
            if isempty(thisObj) || ~isvalid(thisObj)
                thisObj = SGLEventMarkerServer;
            end
            this = thisObj;
        end
    end
    
    methods (Access = private)
        function this = SGLEventMarkerServer
            %------------------------------%
            %       Init Events Port
            evtLines = {...
                'Dev1/port1/line7:0',... %port order changed in lab209!!
                'Dev1/port0/line7:0',... %port order changed in lab209!!
                'Dev1/port2/line7'};
            % create session, add lines
            nidaqObj = mNIDAQ; %#ok<*PROP>
            nidaqObj.daqmxCreateDOChan(evtLines);
            %------------------------------%
            % ZERO ALL
            nbits = 16; % trigger bits
            nidaqObj.daqmxWriteDigitalLines(zeros(1,nbits+1)); % zero port(s)
            this.nidaqObj = nidaqObj;
        end
    end
    
    methods
        %# set the state of the reward bit
        function mSendEventMarker(this,value,varargin)
            nbits = 16; 
                        
            % 16-bit event
            bin_evt = dec2bin(value,nbits)-'0';                    
            this.nidaqObj.daqmxWriteDigitalLines([bin_evt,0]);	   
            java.lang.Thread.sleep(1);                                                                
            this.nidaqObj.daqmxWriteDigitalLines([bin_evt,1]);                 
            java.lang.Thread.sleep(5);                             
            
            if isempty(varargin)
                this.nidaqObj.daqmxWriteDigitalLines(zeros(1,nbits+1)); % zero port(s)
            else
                switch varargin{1}
                    case 'default'
                        % zero port after sending event
                        postEvent = zeros(1,nbits+1); % zero all
                    case 'leave'
                        postEvent = [bin_evt,0];      % zero trigger bit
                    otherwise
                        postEvent = zeros(1,nbits+1); % zero all
                end
                this.nidaqObj.daqmxWriteDigitalLines(postEvent);
            end
            
        end
        
        %# general delete function
        function delete(this)
            delete(this.nidaqObj);
        end
    end
    
end


% [f,e]=log2(max(d)); % How many digits do we need to represent the numbers?
% s = char(rem(floor(d*pow2(1-max(n,e):0)),2)+'0');
% OR,
% x = dec2bin(value,nbits)-'0';






