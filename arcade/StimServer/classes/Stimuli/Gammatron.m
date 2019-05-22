classdef Gammatron < PixelShader
    % GAMMATRON < PixelShader < Stimulus - Annular gratings for ARCADE
    %
    % Shader file: ARCADE\arcade\StimServer\classes\Stimuli\Gammatron.fx
    %
    % PROPERTIES
    % -----------
    %      
    %  temporalFrequency : (cycles per second)
    %                      < 0: inward, > 0: outward, 0:static
    %  spatialPeriod     : (pixel per cycle)
    %  color1            : 24-bit color [r g b alpha]/[r g b]
    %  color2            : 24-bit color [r g b alpha]/[r g b]
    %  radius            : radius of circular mask (pixels)
    %  smoothing         : width of antialising window at edge (pixels)
    %  phaseShift        : phase offset (degree)
    %  
    % USAGE
    % -----
    %   g = Gammatron();
    %
    % For more information, see <a href="matlab:doc('arcade')">the ARCADE guide</a> and the superclasses.
    % 
    % See also PixelShader, Stimulus
     
    properties  ( Access = public, Transient = true )
        temporalFrequency = 1; % (cycles per second)
        spatialPeriod = 50; % (pixel per cycle)
        color1 = [0 0 0 255]; % [r g b alpha]/[r g b]
        color2 = [255 255 255 255]; % [r g b alpha]/[r g b]
        radius = 250; % (pixels)
        smoothing = 1; % (pixels)
        phaseShift = 0; % (degree)
    end
    
    properties ( Dependent = true )
        direction
    end
    
    properties ( GetAccess = private, Transient = true, SetAccess = immutable )
        frameRate = [];
    end        
    
    methods
        function obj = Gammatron()
            
            fxFile = 'Gammatron.fx';                
            filename = fullfile(fileparts(mfilename('fullpath')), fxFile);                                
            obj = obj@PixelShader(filename);
            obj.frameRate = StimServer.GetFrameRate();
            
            % set defaults
            obj.temporalFrequency = obj.temporalFrequency;
            obj.spatialPeriod = obj.spatialPeriod;
            obj.radius = obj.radius;
            obj.color1 = obj.color1;
            obj.color2 = obj.color2;
            obj.smoothing = obj.smoothing;
            obj.phaseShift = obj.phaseShift;
            
        end
        
        function direction = get.direction(obj)
            direction = sign(obj.temporalFrequency);
        end
        
        function set.color1(obj, rgbw)
            color = obj.handle_color_input(rgbw);
            obj.setColor(1, color);
            obj.color1 = color;
        end
        
        function set.color2(obj, rgbw)
            color = obj.handle_color_input(rgbw);
            obj.setColor(2, color)
            obj.color2 = color;
        end
        
        function set.radius(obj, radius)
            obj.shaderWidth = radius;
            obj.shaderHeight = radius;
        end
        
                
        function set.spatialPeriod(obj, sp)
            obj.setParameter(1, sp);
            obj.spatialPeriod = sp;
        end
        
        function set.temporalFrequency(obj, tf)            
            obj.setParameter(2, tf/obj.frameRate);
            obj.temporalFrequency =  tf;
        end
        
        function set.smoothing(obj, aa)
            obj.setParameter(3, aa);
            obj.smoothing = aa;
        end
        
        function set.phaseShift(obj, offset)
            obj.setParameter(4, offset);
            obj.phaseShift = offset;
        end
        
        function set.direction(obj, direction)
            warning('Stimulus:Gammatron:direction', ...
                'The direction property is obsolete. For inward/outward drift use negative/positive temporal frequencies.')
            if direction == 1 || direction == -1
                obj.temporalFrequency = obj.temporalFrequency * direction;
            else
                error('Invalid direction; %g. Gammatron direction must be 1 (outward) or -1 (inward)', direction)
            end
        end
        
    end        
end