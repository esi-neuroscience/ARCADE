classdef (Abstract) Animation < hgsetget
    % ANIMATION - Abstract base class for animations to be passed to the
    % StimServer.
    %
    % Animations are started immediately if the stimulus is already visible,
    % otherwise when the stimulus becomes visible.
    %
    % The terminalAction property is a uint8 bit mask.
    % The bits have the following meaning:
    %   1 disable the assigned stimulus
    %   2
    %   4 toggle the photodiode signal1
    %   8 signal an event (see section 3 on page 4 of StimServer documentation)
    %   16 restart animation (cyclic execution)
    %   32 
    %   64 
    %   128 end deferred mode
    % 
    % Setting a to 0 restores the default behavior of deassigning
    % the animation from the stimulus.
    %
    % See also LinearMotion, GeneralMotion, LinearRange
    %
    properties
        terminalAction %
    end
    
    properties ( SetAccess = immutable, GetAccess = public, Hidden = true, Transient = true )
        key = [];
        frameRate
    end
    
    
    methods
        
        function obj = Animation()
            Key = StimServer.ReadAck();
            assert(Key>0, 'Could not create animation')
            obj.key = Key;
            obj.terminalAction = '00000000';
            obj.frameRate = StimServer.GetFrameRate();
        end
        
        function delete(obj)
            StimServer.Command(obj.key, 0);
        end
        
        function set.terminalAction(obj, bitmask)
            %[ka 0 a] define the terminal action for the animation. a is a uint8 bit mask.
            % The bits have the following meaning:
            %   1 disable the assigned stimulus
            %   2
            %   4 toggle the photodiode signal1
            %   8 signal an event (see section 3 on page 4)
            %   16 restart animation (cyclic execution)
            %   32 reverse animation2
            %   64 goto initial state2
            %   128 end deferred mode
            % Setting a to 0 restores the default behaviour of deassigning
            % the animation from the stimulus.
            if ischar(bitmask)
                action = bin2dec(bitmask);
            elseif isnumeric(bitmask) && numel(bitmask) == 1
                action = bitmask;
            else
                error('Terimnal action bitmask must be either 8-bit binary string or a single number')
            end
                
            StimServer.Command(obj.key, [0, action]);
            obj.terminalAction = action;
        end
        
        
    end
    
end