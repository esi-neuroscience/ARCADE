classdef Sync2PDEvent < handle
    % check for a photo-diode event
    % if the photo-diode event occurs
    % send event marker 
    % prevent further events from being sent
    % stop timer 
    
    properties (SetAccess = private)
        evt_tic
        pdflag = false; % 
        trigEvt
    end
    
    properties (Access = private)
        evt_obj % eventmarker object
        pd_obj  % photo-diode object
        tim_obj % timer object
        
    end
    
    methods (Static)
        % constructor 
        function this = Sync2PDEvent(evt_obj, pd_obj)
            this.evt_obj = evt_obj;
            this.pd_obj  = pd_obj;
        end
    end
    
    methods
        %# public check pd 
        function checkPDEvent(this)
            
            pdbit = this.pd_obj.daqmxReadDigitalLines(1);
            if pdbit && ~this.pdflag
                this.evt_tic = tic;      % get time
                this.pdflag  = true;     % set flag
                this.sendEvent; % send trigger event 
            end
                
        end
        %# public send event
        function sendEvent(this)
            nbits   = 16;
            %trigEvt = this.trigEvt;
            
            bin_evt = decimalToBinaryVector(this.trigEvt,nbits);
            this.evt_obj.daqmxWriteDigitalLines([bin_evt,1]);      % write to port and trigger event
            this.evt_obj.daqmxWriteDigitalLines(zeros(1,nbits+1)); % zero port(s)
        end
        
        %# create Timer
        function createTimer(this)
            this.tim_obj = timer(...
                'ObjectVisibility','off',...
                'TimerFcn',{@(~,~) this.checkPDEvent},...
                'ExecutionMode','fixedRate',...
                'Period',5/1000,...
                'BusyMode','drop'); % default
        end
        
        %# sync this event 
        function syncEvent(this,trigEvt)
           this.trigEvt = trigEvt; % set event 
           %this.createTimer;       % create timer 
           this.start;             
        end
        
        %# public start and stop methods 
        function start(this)
            start(this.tim_obj);
        end
        
        function stop(this)
            stop(this.tim_obj);
        end
        
        function delete(this)
            this.stop;
            delete(this.tim_obj);
        end
        
    end
    
end

