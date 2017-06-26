classdef SGLEyeServerPipe < handle
    
    properties (Constant, Access = private, Hidden = true)
        this = SGLEyeServerPipe
    end
    
    properties (Access = private, Transient = true, Hidden = true)
        pipe = [];
        pipeName = '\\.\pipe\EyeServer';
        pipeBuffer = [0 256]; % [serverOut serverIn]
    end
    
    methods (Access = private, Hidden = true)
        function this = SGLEyeServerPipe
            mlock
        end
    end
    
    methods (Static)
        function Create()
            obj = SGLEyeServerPipe.this;
            obj.pipe = MSMessagePipeServer('\\.\pipe\EyeServer', [0 256], false);
        end
        
        function Open()
            obj = SGLEyeServerPipe.this;
            obj.pipe = MSMessagePipeClient('\\.\pipe\EyeServer', false);
        end
        
        function Close()
            obj = SGLEyeServerPipe.this;
            delete(obj.pipe);
        end
        
        function WriteEyeTrackerMsg(position, tolerance, name)
            position = position(:)';
            msg = [...
                typecast(int16(position),'uint8'),...
                typecast(uint16(tolerance),'uint8'), ...
                typecast(uint8(name),'uint8'), ...
                ];
            result = SGLEyeServerPipe.this.pipe.writeMessage(msg);
            assert(result > 0, 'Could not write eye tracker info to pipe');
        end
        
        function [position, tolerance, name] = ReadEyeTrackerMsg()
            msg = SGLEyeServerPipe.this.pipe.readMessage();
            if ~isempty(msg)
                position = double(typecast(msg(1:4),'int16'));
                tolerance = double(typecast(msg(5:6),'uint16'));
                name = char(typecast(msg(7:end),'uint8'));
            else
                position = [];
                tolerance = [];
                name = [];
            end
            
        end
        
        function delete()
            SGLEyeServerPipe.Close();
            munlock;
            clear SGLEyeServerPipe;
        end
        
    end
    
end