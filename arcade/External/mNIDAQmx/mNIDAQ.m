classdef mNIDAQ < handle 
    % [EXTERNAL MODULE] NI-DAQ
    % Uses the NI-DAQmx API
    % see nidaqBuild.m => makes use of nicaiu.dll, & NIDAQmx.h
    
    % the result of nidaqBuild.m is in this directory mNIDAQmx.m
    % -> lines for functions not used are commented to speed loading
    
    % When an instance of ths class is created
    % this class automatically creates a NI-DAQ Task,
    % and ni-daq autogenerates the task name (to avoid potential conflicts)
    % Although the task name is not known by this object,
    % it does have the task handle [mHandle], which is stored in the object
    
    properties (Access = private)
        mHandle 
        lib      = 'nicaiu';
        %numchan  = 0;
        %numSampsPerChan = 1;
        %timeout         = 1;
    end
    
    methods (Static = true)
        function this = mNIDAQ
            this.loadlib;         % load library 
            this.daqmxCreateTask; % create a task
        end
    end
   
    methods (Access = private)
        %# load dll 
        function loadlib(this)
            if ~libisloaded(this.lib) 
                warning('off','MATLAB:loadlibrary:functionnotfound');
                warning('off','MATLAB:loadlibrary:typenotfound');
                warning('off','MATLAB:loadlibrary:enumexists');
                switch computer
                    case 'PCWIN'
                        loadlibrary(this.lib, @mNIDAQmx); 
                    case 'PCWIN64'
                        loadlibrary(this.lib, @mNIDAQmx64); 
                    otherwise
                        error('Architecture not supported.');
                end
                         
            end;
        end
        %# create task
        function daqmxCreateTask(this)
            %function daqmxCreateTask(this,taskname)
            % sometimes task name is not reset despite that the task was cleared properly
            % Matlab's DAQ toolbox gets around this by randomly generating names
            % Here we set the task name to nothing allowing it to be auto generated
            taskname = ''; % forces ni-daq to auto-generate the task name avoiding conflicts
            mHandle_ = libpointer('uint32Ptr',0);
            [err,~,this.mHandle] = calllib('nicaiu','DAQmxCreateTask',taskname,mHandle_);
            this.daqmxCheckError('daqmxCreateTask',err); % error check
        end
        
        %# error check 
        function daqmxCheckError(this,caller,err)
            if err ~= 0
                % find out how long the error string is
                [numerr,~] = calllib(this.lib,'DAQmxGetErrorString',err,'',0);
                % get error string
                errstr = char([1:numerr]);	% have to pass dummy string of correct length
                [err,errstr] = calllib(this.lib,'DAQmxGetErrorString',err,errstr,numerr);
                error(['mNIDAQ:',caller,' - ',errstr]) % matlab error
            end
        end
    end
    
    methods

        %--------------------------------------%
        % DIGITAL IO
        function daqmxCreateDOChan(this,lines)
            %DAQmx_Val_ChanPerLine     = 0; % One Channel For Each Line
            %DAQmx_Val_ChanForAllLines = 1; % One Channel For All Lines
            lineGrouping = int32(0); % One Channel For Each Line
            for m = 1:numel(lines)
                err = calllib(this.lib,'DAQmxCreateDOChan',this.mHandle,lines{m},'',lineGrouping);
                this.daqmxCheckError('daqmxCreateDOChan',err); % error check
            end
        end
        function daqmxWriteDigitalLines(this,DOvalue)
            dataLayout      = 0; % DAQmx_Val_GroupByChannel
            autoStart       = 1; 
            timeout         = 1;
            numSampsPerChan = 1;
            [err,sampsperchanwritten,empty] = calllib(this.lib,'DAQmxWriteDigitalLines',...
                this.mHandle,numSampsPerChan,autoStart,timeout,dataLayout,...
                DOvalue,0,[]);
            this.daqmxCheckError('daqmxWriteDigitalLines',err); % error check
        end
        
        % DIGITAL INPUT
        function daqmxCreateDIChan(this,lines)
            lineGrouping = int32(0); % One Channel For Each Line
            for m = 1:numel(lines)
                err = calllib(this.lib,'DAQmxCreateDIChan',this.mHandle,lines{m},'',lineGrouping);
                this.daqmxCheckError('daqmxCreateDIChan',err); % error check
            end
            
        end
        function readarray1 = daqmxReadDigitalLines(this,numsample)
            %(lib,taskh,numSampsPerChan,timeout,fillMode,numchan,numsample)
            numchan         = 1;
            timeout         = 1;
            numSampsPerChan = 1;
            
            DAQmx_Val_GroupByChannel    = 0; % Group by Channel
            %DAQmx_Val_GroupByScanNumber = 1; % Group by Scan Number
            fillMode =  DAQmx_Val_GroupByChannel; % Group by Channel
            % fillMode = DAQmx_Val_GroupByScanNumber; % Group by Scan Number
            
            readarray1   = ones(numchan,numsample); 
            sampread     = numsample; 
            bytespersamp = 1; 
            empty        = []; 

            readarray1_ptr   = libpointer('uint8Ptr', readarray1);
            sampread_ptr     = libpointer('int32Ptr', sampread);
            bytespersamp_ptr = libpointer('int32Ptr', bytespersamp);
            empty_ptr        = libpointer('uint32Ptr',empty);
            
            arraylength  = numsample*numchan; % more like 'buffersize'
            
            [err, readarray1, sampread, bytespersamp, empty]=calllib(this.lib,'DAQmxReadDigitalLines',...
                this.mHandle, numSampsPerChan, timeout, fillMode,...
                readarray1_ptr, arraylength, sampread_ptr,...
                bytespersamp_ptr, empty_ptr);
            this.daqmxCheckError('daqmxReadDigitalLines',err); % error check
        end
        
        %--------------------------------------%
        % ANALOG IO
        function daqmxCreateAIVoltageChan(this,physicalChannel)
            %DAQmx_Val_RSE =10083; % RSE
            %DAQmx_Val_NRSE = 10078; % NRSE
            %DAQmx_Val_Diff = 10106; % Differential
            %DAQmx_Val_PseudoDiff = 12529; % Pseudodifferential
            % 'Dev1/ai0'
            vRange          = int32([-10 10]); 
            terminalConfig  = int32(10083); % RSE
            DAQmx_Val_Volts = int32(10348); % Volts
            
            for m = 1:numel(physicalChannel)
                err = calllib(this.lib,'DAQmxCreateAIVoltageChan',...
                    this.mHandle, physicalChannel{m},'',...
                    terminalConfig, vRange(1), vRange(2), DAQmx_Val_Volts, '');
                
                this.daqmxCheckError('daqmxCreateAIVoltageChan',err); % error check
            end
        end
            
        function readarray1 = daqmxReadAnalogF64(this,numsample) 
            numSampsPerChan = 1;
            timeout = 1;
            DAQmx_Val_GroupByChannel    = 0; % Group by Channel
            %DAQmx_Val_GroupByScanNumber = 1; % Group by Scan Number
            fillMode =  DAQmx_Val_GroupByChannel; % Group by Channel
            % fillMode = DAQmx_Val_GroupByScanNumber; % Group by Scan Number

            numchan   = 2;
            sampread  = numsample;
            empty     = [];
            arraylength=numsample*numchan; % more like 'buffersize'
            
            readarray1     = nan(numchan,numsample);
            
            readarray1_ptr = libpointer('doublePtr',readarray1);
            sampread_ptr   = libpointer('int32Ptr',sampread);
            empty_ptr      = libpointer('uint32Ptr',empty);
 
            [err,readarray1,sampread,empty]=calllib(this.lib,'DAQmxReadAnalogF64',...
                this.mHandle, numSampsPerChan,timeout,fillMode,...
                readarray1_ptr,arraylength,sampread_ptr,empty_ptr);
            
            this.daqmxCheckError('daqmxReadAnalogF64',err); % error check
        end
        
        %--------------------------------------%
        % int32 DAQmxGetDeviceAttribute ( const char deviceName [], int32 attribute , void * value , ...); 
        % DAQmxGetChanAttribute
        %function value = daqxGetDeviceAttribute(this,attribute)
            % return attribute
            %value = int32(0);
            %value_ptr = libpointer('voidPtr',value);
            %'cstring', 'long', 'voidPtr', 'error'
            %value = calllib(this.lib, 'DAQmxGetDeviceAttribute',...
            %    'Dev1', int32(attribute), value_ptr);
       
        %end
        
        
        function daqmxClearTask(this)
            [err] = calllib(this.lib,'DAQmxClearTask',this.mHandle); 
            this.daqmxCheckError('daqmxClearTask',err); % error check
        end
        
        function delete(this)
            this.daqmxClearTask;
            %unloadlibrary(this.lib); % problem if there are multiple
            %objects
        end
        
    end
    

    % create session
    % get channel information 
    % allows on to set the information 
    
    %DAQmx_Val_Task_Verify = 2; % Verify
    %[err,b] = calllib(lib,'DAQmxTaskControl',taskh,DAQmx_Val_Task_Verify);
    
    
    
    
    
    
end

