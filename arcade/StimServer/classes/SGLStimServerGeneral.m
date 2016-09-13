classdef (Sealed) SGLStimServerGeneral < AUXStimServerGeneral
    % [SINGELTON]
    % just make me a singelton
    
    % INHERITANCE:
    % AUXStimServerGeneral < AUXPipeReadWrite < handle
    % + background(this, rgbw)
    % + enablePD(this, shown)     % enable/disable pd 
    % + setPDvalue(this, value)   % turn pd on/off
    % + togglePD(this)
    % + flickerPD(this)
    % + defer(this, deferred)
    % + removeAll(this)
    % + showAll(this, visible)
    
    %------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, changed the superclass

    methods (Static)
        function this = launch
            persistent thisObj
            if isempty(thisObj) || ~isvalid(thisObj)
                thisObj = SGLStimServerGeneral;
            end
            this = thisObj;
        end
    end
    
    methods (Access = private)
        function this = SGLStimServerGeneral
            % set properties
        end
    end
    
end

% general class that gives access to special methods 

% photo-diode
% defer
% background
% remove all
