classdef SPCObject < AUXPipeReadWrite
    % [SUPERCLASS] OBJECT
    % each class that inherits SPCObject
    % 1. has a create/replace method 
    % 2. can be enabled/disbaled
    % 3. can be removed/deleted
    % 4. can be protected
    
    % SUBCLASSES:
    %   OBJParticleStimulus
    %   OBJPixelShader
    %   OBJSymbol
    %   OBJPixel 
    %   OBJImage        (not coded)
    % 	OBJBitmapBrush  (not coded)
    
    % INHERITANCE:
    % AUXPipeReadWrite < handle
    
    % - provides Pipe Read/Write methods
    % - holds a copy of the pipe handle 
    
    %------------------------------------------%
    % 12.4.2016 - Jarrod, wrote class 
    
    %# Object Key
    properties (...
            SetAccess = private,...
            AbortSet  = true)
        oKey@uint16 scalar    = 0;
        oValid@logical scalar = false;
    end
    
    %# Track Current State
    properties (...
            AbortSet  = true,...
            SetAccess = private)
        %oEnabled@logical scalar   = false;    % enabled/visible
        %oProtected@logical scaler = false;    % protected from 'all' actions
    end
    
    %# constructor
    methods (Static)
        function this = SPCObject
        end
    end
    
    %# abstract methods
    methods (...
            Abstract = true,...
            Access   = protected)
        mCreateObject(this)
        %mReplaceObject(this)
    end
    
    % public
    methods (Sealed = true)
        %# set visibility
        function visible(this, value)
            % [kk 0 e] enable (e=1) or disable (e=0) stimulus
            this.mWriteCommand(this.oKey, [0, value]);
        end
    end

    %# universal object methods 
    methods (...
            Sealed = true,...
            Access = protected)
        %# set position
        function mSetPosition(this, position)
            % [kk 3 x y] move (center of) stimulus to x, y
            this.mWriteCommand(this.oKey, [uint8(3), typecast(single(position), 'uint8')]);
        end

        %# protect object from "all" actions 
        %function mProtect(this, value)
        %end
        
        %# remove object in StimServer
        function mRemoveObject(this)
            % success -> Bytes Written = Command Byte Length
            success = this.mWriteCommand(this.oKey, 0); %#ok<NASGU>
            % set key to 00
            this.oKey = uint16(0);
        end
        
        %# fetch stimulus reference key
        % add more error handling 
        function mFetchObjectKey(this, createSuccess, objectString)
            % *** generalize this to fetch key with error handling ***
            if createSuccess % get object key
                oKey = this.mReadKey;   %#ok<*PROP>
                % has the object been created successfully
                this.oValid = oKey~=uint16(0);
                this.oKey   = oKey;
                
                if ~this.oValid
                    disp(['FAILED to get Key for stimulus: ', objectString]);
                end
            else
                disp(['FAILED to Create stimulus: ', objectString]);
            end
            
        end
    end

    methods
        %# delete 
        function delete(this)
            % do not try to delete if object is invalid 
            if this.oKey 
                this.mRemoveObject;
            end
        end
    end
end