classdef OBJPixelShader < SPCObject
    % [OBJECT] PIXEL SHADER
    
    
    % INHERITANCE:
    %   OBJPixelShader < ...
    %       SPCObject < AUXPipeReadWrite < handle
    
    
    %------------------------------------------%
    % 19.4.2016 - Jarrod, wrote class 

    
    %# constructor
    methods (Static)
        function this = OBJPixelShader
        end
    end
    
    methods (Access = protected)
        %# create particle stimulus 
        % basic input error checking 
        function mCreateObject(this, filename)
            % [00 4 filename] create a pixel shader stimulus from the specified HLSL file.
            
            % check filename
            validFiles = {'.fx'};
            try
                [~,~,ext] = fileparts(filename);
                isValid = any(validatestring(ext,validFiles)); %#ok<NASGU>
            catch ME
                error(ME.message);
            end
            
            % create pixel shader
            success = this.mWriteCommand(0, [uint8(4), uint8(filename), uint8(0)]); % 0 = endl;
            % try to fetch stimulus key
            this.mFetchObjectKey(success, filename); % pass filename as ObjectString   
        end
        
        %# set pixel shader parameter
        function mSetOptionalParameter(this, idx, value)
            %[kk 1 i value] set value (single float) for parameter i of shader
            this.mWriteCommand(this.oKey, [uint8(1), uint8(idx), typecast(single(value), 'uint8')]);
        end
        
        %# set pixel shader color 
        function mSetColor(this, idx, rgbw)
            %[kk 5 i r g b w] set components (0...255) for color i of shader (i = 1...4)
            this.mWriteCommand(this.oKey, [5, idx, rgbw]); 
        end
        
        %# set pixel shader animation increment -> value * number of frames
        function mSetAnimationIncrement(this, value)
            %[kk 2 value] set animation increment value (single float) for shader (speed)
            this.mWriteCommand(this.oKey, [uint8(2), typecast(single(value), 'uint8')]);
        end
        
        %# set pixel shader phase value 
        % overwrite the existing value -> value * number of frames ?
        function mSetAnimationValue(this, value) 
            %[kk 6 value] set animated value (single float) for shader
            this.mWriteCommand(this.oKey, [uint8(6), typecast(single(value),'uint8')]);
        end

    end
    
end

