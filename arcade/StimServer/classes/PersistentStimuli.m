classdef (Sealed) PersistentStimuli < handle
    
    properties (Constant, Access = private, Hidden = true)
        this = PersistentStimuli
    end
    
    
    properties ( Access = private, Hidden = true )
       stimuli_
    end
    
    properties ( Access = public )
        stimuli
    end
    
    methods (Access = private, Hidden=true)
        function obj = PersistentStimuli()
            mlock;
        end
    end
    
    
    
    methods ( Static )
        
        function create()
            obj = PersistentStimuli();
        end
        
        function add(stim)
            temp = PersistentStimuli.this;
            temp.stimuli{end+1} = stim;
        end
        
        function stim = get()
            temp = PersistentStimuli.this;
            stim = temp.stimuli;
        end
        
        function delete()
            temp = PersistentStimuli.this;
            for iStimulus = 1:length(temp.stimuli)
                delete(temp.stimuli{iStimulus})
            end
            munlock;
            clear PersistentStimuli
        end
        
        
    end
    
end