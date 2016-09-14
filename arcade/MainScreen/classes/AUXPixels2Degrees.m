classdef AUXPixels2Degrees < handle 
    % [AUXILLARY] STATIC class
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes

    methods (Static)
        %# constructor
        function this = AUXPixels2Degrees
        end
        
        %# calculate pixels from dist2screen, width/height of monitor 
        function  ppd = mPixelsPerDegree(dist2screen,diagScreen,scrnPixels,dec)
            % scrnPixels  -> [width height]
            % dist2screen -> in cm
            % diagScreen  -> diaginal screen size in cm
            % dec         -> number of decimal places 
            diagPixels  = sqrt(sum(scrnPixels.^2));
            diagDegrees = AUXPixels2Degrees.mCalculateVisualDegrees(diagScreen,dist2screen,[]);
            
            % calculate to 2 decimal places
            ppd = AUXPixels2Degrees.mCalculatePixelsPerDeg(diagPixels,diagDegrees,dec);
        end
        
        
        %# calculate pixels per degree
        function ppd = mCalculatePixelsPerDeg(pix,deg,dec)
            ppd = pix/deg; 
            if ~isempty(dec), ppd = AUXPixels2Degrees.mSetDecimalPlaces(ppd,dec); end; 
        end
        
        %# calculate degrees of visual angle 
        function degs = mCalculateVisualDegrees(widthcm,distcm,dec)
            % widthcm -> distance on screen
            % distcm  -> distance to screen 
            % calculate degrees
            degs = (2*atan2(widthcm,2*distcm))*180/pi;
            if ~isempty(dec), degs = AUXPixels2Degrees.mSetDecimalPlaces(degs,dec); end;
            
            %degs = (2*atan2(55.5,2*80.67))*180/pi;
            %ppd  = sqrt(sum([1680,1050].^2))/degs
            
        end
        
        %# set decimal places
        function value = mSetDecimalPlaces(value,dec)
            % set the number of decimal places
            x     = 10.^round(dec);
            value = round(value*x)/x;
            %value = value;
        end
        
        %function 
            % pixels

        %end
        
        
    end
    
end

