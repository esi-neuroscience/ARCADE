classdef AUXMarkerObject 
    % [AUXILLARY] MARKER OBJECT
    
    % base object: meant to be inherited
    % - stimulus objects (outline object)
    % - eye tracker (outline fixation)
    % - screen grid (draw grid)
    
    % Use 'none' for objects that are only drawn once (e.g., grids)
    % Use 'xor' for objects that could change properties, (e.g., fixation/stimulus objects)

    % Manipulations to objects:
    % color change     -> set(hm,'Color',[r,g,b]);
    % size change      -> set(hm,'MarkerSize',msize(pix));
    % position change  -> set(hm,'XData',xpos,'YData',ypos);
    
    % *should not change marker, because the size function may not yield
    % the expecte result
    
    % *knows nothing about the parent axis, size, pixels etc
    % correct mapping/axis setup must be done elsewhere
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    
    methods (Static)
        function this = AUXMarkerObject
        end
    end
    
    methods (...
            Static = true,...
            Sealed = true)
        
        % return the marker handle, and size function 
        function [hm, msize] = mDrawMarker(...
                parent_ax, pos, mclr, pix, mrkr, erase)            
            % parent_ax -> Parent: parent axis 
            % pos(1)    -> XData: x position in pixels
            % pos(2)    -> YData: y position in pixels
            % mclr      -> Color: [r,g,b]
            % pix       -> MarkerSize - diameter in pixels
            % mrkr      -> Marker: 'o','s','*','+','x'
            % erase     -> EraseMode: 'none', 'xor'
            
            % **for the SyncMaster 2233 monitor**
            % most markers need to be scaled by 0.75
            % except sqr, it needs 0.755
            % this is done before computing the respective markersize
            % *a different scaling factor may have to be computed for different
            % monitors 
            scale = 0.75;
            switch mrkr
                case 'o'
                    msize = @(px) px*scale;
                case 's'
                    scale = 0.755;
                    msize = @(px) (px*scale*4)/pi; 
                case '+'
                    msize = @(px) px*scale;
                case 'x'
                    msize = @(px) sqrt((px*scale)^2*2);
                case '*'
                    msize = @(px) px*scale;
                otherwise
                    error('Marker not implemented');
            end

            % create marker 
            hm = line(...
                'Parent',parent_ax,...
                'XData',pos(1),...
                'YData',pos(2),...
                'Color',mclr,...
                'LineStyle','none',...
                'MarkerSize',msize(pix),...
                'Marker',mrkr,...
                'EraseMode',erase); 
        end
    end
end




