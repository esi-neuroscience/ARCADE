classdef (Sealed = true) MultipleEvents < handle
    
    properties (Constant, Access = private, Hidden = true)
        this = MultipleEvents
    end
    
    methods (Access = private, Hidden=true)
        function obj = MultipleEvents()
        end
    end
    
    methods (Static)
        
        function Init(eventNames)
            if ischar(eventNames)
                eventNames = {eventNames};
            end
            WaitForEvents(0, eventNames);
        end
        
        function delete()
        %     munlock;
        %     clear MultipleEvents;
            WaitForEvents(3);
        end
        
        function result = WaitFor(eventNames, all, timeout)
            if ischar(eventNames)
                eventNames = {eventNames};
            end
            result = WaitForEvents(1, eventNames, all, timeout);
        end
        
        % MultipleEvents.Reset() resets all events
        % MultipleEvents.Reset(eventNames) resets the requested events
        function Reset(varargin)
            if isempty(varargin)
                WaitForEvents(2);
            else
                WaitForEvents(2, varargin{1});
            end
        end
    end
        
end

