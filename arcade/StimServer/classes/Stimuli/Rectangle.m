classdef Rectangle < Shape
    % RECTANGLE < Shape < Stimulus - Rectangle stimulus for ARCADE
    %
    % 
    % PROPERTIES
    % -----------
    %   width  : width of rectangle (pixel) for rotation angle=0
    %   height : heigth of rectangle (pixel) for rotation angle=0
    %
    % For more information, see <a href="matlab:doc('arcade')">the ARCADE guide</a> and the superclasses.
    %
    % See also Shape, Stimulus

    properties ( SetAccess = public, GetAccess = public, Transient = true )
        width = 11; % width of rectangle in px for angle=0
        height = 21; % height of rectangle in px for angle=0
    end       
        
    methods
        function obj = Rectangle            
            StimServer.Command(0, uint8(20));
            obj = obj@Shape();

            % set defaults (trigger set methods)
            obj.set_all_properties();
        end
        
        
        function set.width(obj, width)
            StimServer.Command(obj.key, [uint8([1,1]), typecast(uint16([width, obj.height]),'uint8')]);
            obj.width = width;
        end
        
        function set.height(obj, height)
            StimServer.Command(obj.key, [uint8([1,1]), typecast(uint16([obj.width, height]),'uint8')]);
            obj.height = height;
        end
                
        function delete(obj)            
        end
        
    end

    
end