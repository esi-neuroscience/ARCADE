classdef AUXStimServerGeneral < AUXPipeReadWrite
    % [AUXILLARY]
    
    % PROPERTIES: 
    %    + hPipe is inherited from super-class
    
    %----------------------------------%
    % 12.4.2016 - Jarrod
    % - update methods for AUXPipeReadWrite
    % 21.4.2016 - Jarrod, changed name of class
    

    methods (Static)
        function this = AUXStimServerGeneral
        end
    end
    
    methods
        %# set background color 
        function background(this, rgb)
            this.mWriteCommand(0, [0, rgb]);
        end
        %# enable/disable photo-diode 
        function enablePD(this, shown)
            this.mWriteCommand(0, [0, shown]);
        end
        %# turn pd on = 1, off = 0
        function setPDvalue(this, value)
            this.mWriteCommand(0, [16, value]);
        end
        %# toggle photo-diode
        function togglePD(this)
            this.mWriteCommand(0, [16, 2]);
        end
        %# frame-toggle photo-diode 
        function flickerPD(this) % flicker each from 
            this.mWriteCommand(0, [16, 3]);
        end
        %# deferred mode
        function defer(this, deferred)
            this.mWriteCommand(0, [1, deferred]);
        end
        %# remove all stimuli
        function removeAll(this)
            this.mWriteCommand(0, 0);
        end
        %# show/hide all stimuli
        function showAll(this, visible)
            this.mWriteCommand(0, [0, 0, visible]);
        end
        
    end
    
end

