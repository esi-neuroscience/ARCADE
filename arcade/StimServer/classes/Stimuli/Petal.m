classdef Petal < Shape
    % PETAL - Class for petal stimuli
    %
    % Petal-like shape based on two circles and a quadratic Bezier curve
    % connecting the circles.
    %
    %
    %                         _______
    %                        /       \
    %         _____         /         \
    %        /     \_______/           |
    %        |  r    __q____     R     |
    %        \______/       \          /
    %                        \________/
    %            ------ d ------
    %
    % See also Stimulus, Shape
    
    properties ( SetAccess = public, GetAccess = public, Transient = true )
        r = 25; % radius of medial circle in px
        R = 100; % radius of lateral circle in px
        d = 250; % distance between circles
        % position of middle point of Bezier curve (normalized to distance
        % of circles). Default = golden ratio ~ 0.382
        q = 2-(1+sqrt(5))/2;        
    end
    
    methods
        function obj = Petal
            StimServer.Command(0, uint8(26));
            obj = obj@Shape();   
            
            % set defaults (trigger set methods)
            obj.set_all_properties();
        end
        
        function set.r(obj, r)
            obj.check_params(r, obj.R, obj.q, obj.d)    
            StimServer.Command(obj.key, [uint8([1 1]), typecast(single(r),'uint8')]);
            obj.r = r;
        end
        
        function set.R(obj, R)
            obj.check_params(obj.r, R, obj.q, obj.d)    
            StimServer.Command(obj.key, [uint8([1 2]), typecast(single(R),'uint8')]);
            obj.R = R;
        end
        
        function set.d(obj, d)
            obj.check_params(obj.r, obj.R, obj.q, d)    
            StimServer.Command(obj.key, [uint8([1 3]), typecast(single(d),'uint8')]);
            obj.d = d;
        end
        
        function set.q(obj, q)
            obj.check_params(obj.r, obj.R, q, obj.d)    
            StimServer.Command(obj.key, [uint8([1 4]), typecast(single(q),'uint8')]);
            obj.q = q;
        end
        
      
        
        function delete(obj)
        end
        
    end
    
    methods ( Static = true, Access = private )
        function check_params(r,R,q,d)            
            if ~ ((d * q > r) && ((1-q) * d > R))
                error('Invalid parameters. Parameters must adhere to d*q>r && (1-q)*d > R')
            end
        end
    end
        
    
    
end