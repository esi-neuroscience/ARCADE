classdef SGLTrialDataPipe < handle
    
    properties (Constant, Access = private, Hidden = true)
        this = SGLTrialDataPipe
    end
    
    properties (Access = private, Transient = true, Hidden = true)
        pipe
    end
    
    methods (Access = private, Hidden = true)
        function this = SGLTrialDataPipe
            mlock
        end
    end
    
    methods (Static)
        function Create()
            obj = SGLTrialDataPipe.this;
            obj.pipe = MSMessagePipeServer('\\.\pipe\TrialData', [44 44], true);
        end
        
        function Open()
            obj = SGLTrialDataPipe.this;
            obj.pipe = MSMessagePipeClient('\\.\pipe\TrialData', false);
        end
        
        function Close()
            obj = SGLTrialDataPipe.this;
            obj.pipe.delete();
        end
        
        function WriteTrialData(current, trialdata)
            % current = [currentCondition currentBlock currentTrial]
            % trialdata = [trialError, reactionTime, trialErrorTime, writeTime];
            msg = [...
                typecast(uint16(current(1:3)),'uint8'),...
                typecast(single(trialdata(1:4)),'uint8'), ...
                ];
            result = SGLTrialDataPipe.this.pipe.writeMessage(msg);
            assert(result > 0, 'Could not write trial data to pipe');
        end
        
        function trialdata = ReadTrialData()
            msg = SGLTrialDataPipe.this.pipe.readMessage();
            if ~isempty(msg)
                trialdata = [...
                    double(typecast(msg(1:6),'uint16')),...
                    double(typecast(msg(7:22),'single')), ...
                    ];
            else
                trialdata = [];
            end
            
        end
        
        function delete()
            SGLTrialDataPipe.Close();
            munlock;
            clear SGLTrialDataPipe;
        end
        
    end
    
end