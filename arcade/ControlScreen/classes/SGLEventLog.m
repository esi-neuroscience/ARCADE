classdef (Sealed) SGLEventLog < DSPEventLog 
    % [SINGLETON] EVENT LOG
    %  - send text strings to Control Screen event log

    % --- superclasses ---
    % DSPEventLog < handle 
    % + mUpdateString(this,timestamp,eventmarker)
    % + mResetString(this)
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    properties 
        referenceTic
    end
    
    
    methods (Static)
        function this = fetch(varargin)
            persistent thisObj
            if isempty(thisObj) || ~isvalid(thisObj)
                hfig = varargin{1}; % must not be empty
                thisObj = SGLEventLog(hfig);
            end
            this = thisObj;
        end
    end
    
    methods (Access = private)
        %# constructor
        function this = SGLEventLog(hfig)
            htxt = findobj(hfig,'Tag','txt_EventLog');
            this@DSPEventLog(htxt); % superclass constructor 
        end  
    end

end

