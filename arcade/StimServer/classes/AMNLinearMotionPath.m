classdef AMNLinearMotionPath < SPCAnimation
    % [ANIMATION] LINEAR MOTION PATH
    
    
    % INHERITANCE:
    % AMNLinearMotionPath <  ...
    %   SPCAnimation < AUXPipeReadWrite < handle
    
    % PROPERTIES: 
    %   + aKey
    %   + aValid

    % METHODS: 
    %   + mAttachAnimation
    %   + mSetTerminalAction
    %   + mRemoveAnimation
    %   + mFetchAnimationKey
    
    % ABSTRACT METHODS: [SPCAnimation]
    %   + mCreateAnimation(this)

    %------------------------------------------%
    % 21.4.2016 - Jarrod, wrote class 
    

    %# constructor
    methods (Static)
        function this = AMNLinearMotionPath
        end
    end
    
    methods (Access = protected)
        %# create vertex animation 
        function mCreateAnimation(this, velocity)
            % [00 132 vv] create a straight line segment motion path object. vv is the velocity in
            % pixels per second (16 bit unsigned integer). A frame rate of 120 Hz is assumed.
            success = this.mWriteCommand(0, [uint8(132), typecast(uint16(velocity),'uint8')]);
            % try to fetch stimulus key
            this.mFetchAnimationKey(success, 'Animation'); % object string
        end
        
        %# set the vertices for the vertex animation 
        function mSetVerticies(this, verticies)
            % [ka 11 vertices] set the vertex coordinates of the straight line segment motion path.
            % vertices are 16 bit signed integers in pixel space. The animation starts instantly if
            % it's already assigned to a stimulus { else it starts once it is assigned. The maximum
            % number of vertices to be specified with this command is 31.
            this.mWriteCommand(this.aKey, [uint8(11), typecast(int16(verticies),'uint8')]);
        end
    end
end

