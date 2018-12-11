classdef Ellipse < Shape
    % ELLIPSE - Class for elliptic stimuli
    % 
    % See also Stimulus, Shape

    properties ( Access = public, Transient = true )
        width = 100; % width of ellipse in px for angle=0
        height = 100; % height of ellipse in px for angle=0      
    end       
        
    methods
        function obj = Ellipse            
            StimServer.Command(0, uint8(28));
            obj = obj@Shape();            

            % set defaults (trigger set methods)
            obj.set_all_properties()


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