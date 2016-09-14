classdef OBJSymbol < SPCObject 
    % [OBJECT] SYMBOL
    
    
    % INHERITANCE:
    % OBJSymbol < ...
    %   SPCObject < AUXPipeReadWrite < handle
    
    % PROPERTIES: oKey, oValid
    % METHODS: 
    
    %------------------------------------------%
    % 18.4.2016 - Jarrod, wrote class 
    

    %# constructor
    methods (Static)
        function this = OBJSymbol
        end
    end
    
    
    methods (Access = protected)
        %# create particle stimulus
        function mCreateObject(this, symType, symSize)
            % [00 12 t s] create a symbol stimulus of type t (uint8) and size s (uint16).
            % The size specifies the width and the height of the symbol.
            %            t symbol type
            %         --------------------
            %            1 filled circle
            %            2 outlined circle
            success = this.mWriteCommand(this.oKey,...
                [uint8([12,symType]), typecast(uint16(symSize),'uint8')]);
            % try to fetch stimulus key
            this.mFetchObjectKey(success, 'Symbol'); % object string
        end
        
        % function mReplaceStimulus(this)
        % [00 13 t s kk] create or replace symbol stimulus of type t and size s.
        % end
        
        %# set symbol diameter in pixels
        function mSetDiameter(this, size_pixels)
            %[kk 1 1 value] set symbol size (uint16 - initial value is 4)
            % value is passed as an integer, pixels -> diameter
            % the dots are anti-alised and thus they will have a thin dark edge
            % if the dot is positioned exactly on a pixel (e.g. [0,0], then
            % even dot diameters are recommended, otherwise odd dot
            % diameters are recommended 
            this.mWriteCommand(this.oKey, [uint8([1,1]), typecast(uint16(size_pixels),'uint8')]);
        end
        
        %# set symbol color
        function mSetColor(this, rgbw)
            % [kk 5 r g b w] set components (uint8, 0...255) for color of symbol. 
            % The initial color is inherited from the "default draw color"
            % **This command is not yet implemented for outlined circles**
            this.mWriteCommand(this.oKey, [5, rgbw]); % includes alpha (w)
        end
    end
end

