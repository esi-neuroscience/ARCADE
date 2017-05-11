classdef (Sealed) SGLEventMarkerServer < handle
    
    
    properties (SetAccess = immutable)
        nidaqObj 
        sendToDaq = true;
        filename = [];
        fileHandle = [];
    end
    
    properties ( Access = private )
        timestamps = uint64(zeros(1,1000))
        values = uint64(zeros(1,1000))
        lastEvent = 0;  
    end
    
    properties ( Access = public )
        tStart
    end
    
    methods (Static)
        function this = launch(filename)
            if nargin == 0
                filename = [];
            end
            persistent thisObj
            if isempty(thisObj) || ~isvalid(thisObj)
                thisObj = SGLEventMarkerServer(filename);
            end
            this = thisObj;
        end
    end
    
    methods (Access = private)
        function this = SGLEventMarkerServer(filename)
            
            try            
                %------------------------------%
                %       Init Events Port
                evtLines = {...
                    'Dev1/port0/line7:0',...
                    'Dev1/port1/line7:0',...
                    'Dev1/port2/line7'};
                % create session, add lines
               
                nidaqObj = mNIDAQ; %#ok<*PROP>
                nidaqObj.daqmxCreateDOChan(evtLines);
                %------------------------------%
                % ZERO ALL
                nbits = 16; % trigger bits
                nidaqObj.daqmxWriteDigitalLines(zeros(1,nbits+1)); % zero port(s)
                this.nidaqObj = nidaqObj;
            catch me
                this.sendToDaq = false;
                me
                warning('Could not find NI DAQ card. No event markers will be send out.')
            end
            this.tStart = tic;
            if ~isempty(filename)
                this.filename = filename;
                h = fopen(this.filename, 'w');
                assert(h ~= -1);
                this.fileHandle = h;
            end
        end
    end
    
    methods
        
        function mSendEventMarker(this,value,varargin)
            
            this.timestamps(this.lastEvent+1) = uint64(toc(this.tStart)*1E6);
            this.values(this.lastEvent+1) = uint64(value);
            this.lastEvent = this.lastEvent+1;
            
            if this.sendToDaq
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
            
        end
        
        function writeEvents(this)
            if ~isempty(this.filename)
                writeArray = [this.timestamps(1:this.lastEvent); this.values(1:this.lastEvent)];
                nWritten = fwrite(this.fileHandle, writeArray, 'uint64');
                assert(nWritten == this.lastEvent*2)
                this.lastEvent = 0;
                this.timestamps(:) = 0;
                this.values(:) = 0;
            end
        end
        
        function delete(this)
            if this.sendToDaq
                delete(this.nidaqObj);
            end
            if ~isempty(this.filename)
                fclose(this.fileHandle);
            end
        end
    end   
end