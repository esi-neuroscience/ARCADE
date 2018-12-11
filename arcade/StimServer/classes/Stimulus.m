classdef (Abstract) Stimulus < hgsetget % will be matlab.mixin.SetGet after 2014b
    % STIMULUS - Abstract base class for StimServer stimuli providing the
    % general stimulus properties visible, position and animation. Stimulus
    % properties can be changed either struct-like or using set:
    %
    %   stim.position = [0 0];
    %   set(stim, 'position', [0 0])
    %
    % The position property is retrieved from the StimServer and not stored
    % locally.
    %
    % See also Picture, Rectangle, Grating, PixelShader, Animation, MovingBar,
    % ParticleStimulus, Animation, LinearMotion, GeneralMotion, StimServer
    
    properties ( SetAccess = public, GetAccess = public, Transient = true )
        visible = false; % Visibilty of stimulus, true for on, false for off
    end
    
    properties ( Hidden = true, Access = public, Transient = true )
        animation = []; % empty for static stimuli, LinearMotion or GeneralMotion for animated stimuli
    end
    
    properties ( SetAccess = private, GetAccess = public, Hidden = true, Transient = true )
        key
    end
    
    properties ( Dependent = true )
        position % Position in pixel relative to screen center
    end
    
    properties ( GetAccess = protected, Hidden = true )
        assignedAnimations = [];
    end
    
    
    methods
        function obj = Stimulus
            Key = StimServer.ReadAck();
            assert(Key>0, 'Could not create stimulus. See log window of StimServer.exe')
            obj.key = Key;
        end
        
        function set.visible(obj, visible)
            StimServer.Command(obj.key, [0 visible]);
            obj.visible = visible;
        end
        
        function set.position(obj, value)
            assert(numel(value)==2, 'Position must be 2-element vector')
            x = value(1);
            y = value(2);
            StimServer.Command(obj.key, ...
                [3 typecast(single([x y]), 'uint8')]);
        end
        
        function position = get.position(obj)
            StimServer.Command(obj.key, 8);
            position = StimServer.read2single();
        end
        
        %         function set.protected(obj, value)
        %            error('Not implemented yet')
        %         end
        
        
        function set.animation(obj, animation)
            warning(sprintf(['Using the animation property for playing animations ' ...
                'is deprecated and will be removed in the future. \n' ...
                '\tUse the play_animation/stop_animation methods instead']))
            if ~isempty(animation)
                StimServer.Command(animation.key, ...
                    [0 1 typecast(uint16(obj.key), 'uint8')])
            elseif isempty(animation) && ~isempty(obj.animation)
                StimServer.Command(obj.animation.key, ...
                    [0 0 typecast(uint16(obj.key), 'uint8')])
            end
            obj.animation = animation;
            
        end
        
        function play_animation(obj, animation)
            % play animation
            StimServer.Command(animation.key, ...
                [0 1 typecast(uint16(obj.key), 'uint8')])
            obj.assignedAnimations(end+1) = animation.key;
        end
        
        function stop_animation(obj)
            for iAnimation = 1:length(obj.assignedAnimations)
                StimServer.Command(obj.assignedAnimations(iAnimation), ...
                    [0 0 typecast(uint16(obj.key), 'uint8')])
            end
            obj.assignedAnimations = [];
        end
        
        function obj = bring_to_front(obj)
            StimServer.Command(obj.key, 14);
            Key = StimServer.ReadAck();
            assert(Key>0, 'Could not bring stimulus to front. See log window of StimServer.exe')
            obj.key = Key;
        end
        
        function toggle_visibility(obj)
            if obj.visible
                obj.visible = false;
            else
                obj.visible = true;
            end
        end
        
        function delete(obj)
            if ~isequal(obj.key, 0)
                if ~isempty(obj.assignedAnimations)
                    obj.stop_animation()
                end
                
                if ~isempty(obj.animation)
                    StimServer.Command(obj.animation.key, ...
                        [0 0 typecast(uint16(obj.key), 'uint8')])
                end
                StimServer.Command(obj.key, 0);
            end
        end
    end
    
    methods ( Access = protected, Static = false )
        function set_all_properties(obj)
            % set all properties to current value / trigger set functions
            props = properties(obj);
            for iProp = 1:length(props)
                obj.(props{iProp}) = obj.(props{iProp});
            end
            
        end
        
        
    end
        
    methods ( Access = protected, Static = true )
        function color4 = handle_color_input(color, alpha)
            if nargin == 1
                alpha = 255;
            end
            switch numel(color)
                case 3
                    color4 = [color, alpha];
                case 4
                    color4 = color;
                otherwise
                    error('Invalid color input. Must be either [r g b] or [r g b alpha]')
            end
            
        end
        
    end
end