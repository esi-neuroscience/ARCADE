classdef ABSEyeServer < handle
    % Abstract class for Eye Servers
    %
    
    properties
        sharedMemoryName = 'EyePosition'
        filename = [];
        positionTracker = {};
    end
    
    properties ( Access = protected )
        sharedMemory % shared memory for current eye position
        stopEvent % system event for stopping data acquisition
    end
    
    methods
        function obj = ABSEyeServer(filename)
            sharedObject = MSNamedSharedMemory;
            sharedObject.mCreateFileMapping(obj.sharedMemoryName, 16);
            setdatatype(sharedObject.pointer, 'doublePtr', 2);
            sharedObject.pointer.Value = [0.0; 0.0];
            obj.sharedMemory = sharedObject;
            obj.stopEvent = IPCEvent('StopEyeServer');

            if nargin == 1
                obj.filename = filename;
            elseif nargin == 0
                obj.filename = [];
            end
            
            % Create pipe
            SGLEyeServerPipe.Create();
        end
    end
    
    methods ( Abstract = true )
        initialize(obj)
        acquire_eye_position(obj)
        stop(opj)
    end
    
    methods ( Access = protected )
        
        function share_eye_position(obj, eyePosition)
            % Write current eye position into shared memory
            obj.sharedMemory.pointer.Value = [eyePosition(1); eyePosition(2)];
        end
        
        function setup_position_tracker(obj)
            % Check pipe for new tracking positions
            [position, tolerance, name] = SGLEyeServerPipe.ReadEyeTrackerMsg();
            if ~isempty(position)
                obj.positionTracker{end+1} = EyeTracker(name, position, tolerance);
            elseif isequal(position, [int16(Inf) int16(Inf)]) && tolerance == uint16(Inf)
                obj.positionTracker = {};
            end
            
        end
        
        
        function start(obj)
            % Start data acquisition            
            obj.initialize();
            
            while ~obj.stopEvent.wasTriggered
                % check pipe for tracker
                obj.setup_position_tracker()
                
                % get eye data
                eyePosition = obj.acquire_eye_position();
                
                % share eye data via shared memory
                obj.share_eye_position(eyePosition);
                
                % check eye position with trackers and issuve events
                for iTracker = 1:length(obj.positionTracker)
                    obj.positionTracker{iTracker}.checkEye(eyePosition)
                end
            end
            
            obj.stop();
            
        end
        
        function delete(obj)
            SGLEyeServerPipe.delete();
            obj.sharedMemory.delete();
        end
    end
end