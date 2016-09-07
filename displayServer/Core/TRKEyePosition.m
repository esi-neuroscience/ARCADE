classdef TRKEyePosition < handle 
    % [TRACK] EYE POSITION  
    % - provides specifc shape functions 
    
    % one potential concern is 
    % use try and catch 
    % error check 
    % get field names, are necessary present 
    % method does not need to be the function name
    % could be in aswitch statement 
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    
    methods (Static)
        %# constructor
        function this = TRKEyePosition
        end
    end

    methods (...
            Static = true,...
            Sealed = true)
        
        %------------------------------------------%
        %# shape functions 
        %------------------------------------------%
        function [fcn, nextState] = m_circle(params)
            % check to make sure all the relevant fields are there 
            
            % these fields must be present 
            % ignore the rest 
            report    = params.report;    %#ok<*MCNPN>
            nextState = params.nextState;
            center    = params.center;
            radius    = params.radius;    %#ok<*PROP>
            
            % construct callback function 
            switch report
                case 'enter' 
                    fcn = @(eyePos) sqrt(sum((eyePos-center).^2)) <= radius;
                case 'leave'
                    fcn = @(eyePos) sqrt(sum((eyePos-center).^2)) > radius;
            end
        end
        
        %# shape is a square 
        function [fcn, nextState] = m_square(params) 
            % assumption is that eye_position is:
            % eyePos -> eye position in pixels, and [x_pos, y_pos];
            report    = params.report;    %#ok<*MCNPN>
            nextState = params.nextState;
            center    = params.center;    % pixels 
            halfWidth = params.radius; % pixels 
            
            % construct callback function 
            switch report
                case 'enter' 
                    % true if either x or y is inside halfWidth
                    fcn = @(eyePos) any(abs(eyePos-center)<=halfWidth);
                case 'leave'
                    % true if either x or y is outside halfWidth
                    fcn = @(eyePos) any(abs(eyePos-center)> halfWidth);
            end
        end

        %# shape is a rectangle
        function [fcn, nextState] = m_rectangle(params) 
            % assumption is that eye_position is:
            % eyePos -> eye position in pixels, and [x_pos, y_pos];
            report    = params.report;    %#ok<*MCNPN>
            nextState = params.nextState;
            center    = params.center;    % pixels x,y
            halfWH    = params.radius;    % pixels width, height 
            
            % construct callback function 
            switch report
                case 'enter' 
                    % true if either x or y is inside respective WidthHeight
                    fcn = @(eyePos) any((abs(eyePos-center)./halfWH)<=1);
                case 'leave'
                    % true if either x or y is outside respective WidthHeight
                    fcn = @(eyePos) any((abs(eyePos-center)./halfWH)>1);
            end
        end
        
        %# shape is an ellipse 
        function [fcn, nextState] = m_ellipse(params) 
            
            
            % assumption is that eye_position is:
            % eyePos -> eye position in pixels, and [x_pos, y_pos];
            report      = params.report;    %#ok<*MCNPN>
            nextState   = params.nextState;
            center      = params.center;        % pixels x,y
            halfWH      = params.halfWH;        % pixels width, height 
            orientation = params.orientation;   % rotation from horizontal 
            
        end
        
        %# shape are pixels
        function [fcn, nextState] = m_pixels(params) 
            
        end

        
        % USE RECT
                
%         %# shape is the screen
%         function [fcn, nextState] = m_screen(params)
%             % these fields must be present 
%             % ignore the rest 
%             report     = params.report;    %#ok<*MCNPN>
%             nextState  = params.nextState;
%             pixelInset = params.pixelInset;
%             %center    = params.center;
%             %radius    = params.radius;    %#ok<*PROP>
%             
%             % construct callback function 
%             switch report
%                 case 'enter' 
%                     fcn = @(eyePos) sqrt(sum((eyePos-center).^2)) <= radius;
%                 case 'leave'
%                     fcn = @(eyePos) sqrt(sum((eyePos-center).^2)) > radius;
%             end
%         end
        
    end

end



