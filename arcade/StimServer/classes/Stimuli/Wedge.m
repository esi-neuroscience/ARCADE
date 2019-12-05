classdef Wedge < Shape
    % WEDGE < Shape < Stimulus - Wedge stimulus for ARCADE
    %
    % 
    % PROPERTIES
    % -----------
    %   gamma   : wedge's center angle (>0° <90°)
    %
    %      
    % USAGE
    % -----
    %   w = Wedge();
    %
    % For more information, see <a href="matlab:doc('arcade')">the ARCADE guide</a> and the superclasses.
    %
    % See also Shape, Stimulus

    properties ( Access = public, Transient = true )
        gamma = 9; % wedge's center angle (>0° <90°)
    end       
        
    methods
        function obj = Wedge            
            StimServer.Command(0, uint8(30));
            obj = obj@Shape();            

            % set defaults (trigger set methods)
            obj.set_all_properties()
        end
        
        function set.gamma(obj, gamma)
            StimServer.Command(obj.key, uint8([1, 1, typecast(single(gamma),'uint8')]));
            obj.gamma = gamma;
        end
                              
        function delete(obj)            
        end
        
    end

    
end