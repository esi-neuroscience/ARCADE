classdef SPCAnimation < AUXPipeReadWrite
    % [SUPERCLASS]
    
    % +createAnimation (abstract)
    % +replaceAnimation (abstract)
    % +mFetchAnimationKey
    % +mSetTerminalAction
    % +mAttachAnimation
    % +mRemoveAnimation
    
    % INHERITANCE:
    % SPCAnimation < ...
    %   AUXPipeReadWrite < handle
    
    % PROPERTIES: 
    %   + hPipe
    
    % METHODS: 
    %   + mReadKey
    %   + mWriteCommand
    
    %------------------------------------------%
    % 18.4.2016 - Jarrod, wrote class 

    %# Object Key
    properties (...
            SetAccess = private,...
            AbortSet  = true)
        aKey@uint16 scalar         = 0;      % animation key
        aValid@logical scalar      = false;  % animation valid         
    end
    
    %# Track Current State
    properties (...
            AbortSet  = true,...
            SetAccess = private)
        %aEnabled@logical scalar   = false;    % enabled/visible
        %aProtected@logical scaler = false;    % protected from 'all' actions
        %aPosition@single vector   = [0,0];    % position
    end
    
    %# constructor
    methods (Static)
        function this = SPCAnimation
        end
    end
    
    %# abstract methods
    methods (...
            Abstract = true,...
            Access   = protected)
        mCreateAnimation(this)
        %mReplaceAnimation(this)
    end
    
    methods (...
            Sealed = true,...
            Access = protected)
        %# attach animation to object in StimServer
        function mAttachAnimation(this, oKey, value) 
            %[ka 0 e kk] assign (e=1) or deassign (e=0) animation ka to/from stimulus kk
            this.mWriteCommand(this.aKey, [uint8([0, value]), typecast(uint16(oKey),'uint8')]);
        end
        
        %# set terminal action on path end 
        function mSetTerminalAction(this, bitmask) %
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
            this.mWriteCommand(this.aKey, [0, bitmask]);
        end
        
        
        %# remove animation object in StimServer
        function mRemoveAnimation(this)
            %[ka 0] remove (destroy) animation (not deferrable)
            % success -> Bytes Written = Command Byte Length
            % ensure it is unassigned 
            % remove from stim server
            success = this.mWriteCommand(this.aKey, 0); %#ok<NASGU>
            % set key to 00
            this.aKey = uint16(0);
        end
        
        %# fetch stimulus reference key
        % add more error handling 
        function mFetchAnimationKey(this, createSuccess, objectString)
            % *** generalize this to fetch key with error handling ***
            if createSuccess % get object key
                aKey = this.mReadKey;   %#ok<*PROP>
                % has the object been created successfully
                this.aValid = aKey~=uint16(0);
                this.aKey   = aKey;
                
                if ~this.aValid
                    disp(['FAILED to get Key for animation: ', objectString]);
                end
            else
                disp(['FAILED to Create animation: ', objectString]);
            end
        end
    end
    
    methods
        %# delete 
        function delete(this)
            % do not try to delete if object is invald 
            if this.aKey 
                this.mRemoveAnimation;
            end
        end
    end
end

