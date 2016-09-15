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
            nbits = 16; % trigger bits
            % port should be all zeros
            % send trigger

            bin_evt = dec2bin(value,nbits)-'0';                    % 16-bit event
            this.nidaqObj.daqmxWriteDigitalLines([bin_evt,0]);	   % from 20160628: first write bits without triggering strobe
            java.lang.Thread.sleep(1);                             % changed in lab209!!
            %java.lang.Thread.sleep(2);                             % changed in lab209!!
            %java.lang.Thread.sleep(3);                             % changed in lab209!! 31 05 2016
            
            this.nidaqObj.daqmxWriteDigitalLines([bin_evt,1]);     % from 20160628: then write to port and trigger event            
            
            java.lang.Thread.sleep(5);                             % changed in lab209!! 01 06 2016 - try to make sure em are not overwritten
            
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






