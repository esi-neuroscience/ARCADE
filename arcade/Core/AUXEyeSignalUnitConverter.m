classdef AUXEyeSignalUnitConverter < handle
    % [AUXILLARY]
    
    %     properties
    %         ppd        = 50;          % pixels per degree
    %         vgain      = [10 10];     % voltage gain
    %         screensize = [1680 1050]; % screen size
    %     end
    
    %------------------------------------------%
    % Jarrod, wrote class 
    % 21.4.2016 - Jarrod, added some notes
    
    methods (Static)
        %# constructor 
        function this = AUXEyeSignalUnitConverter
            % requires:
            % + pixels per deg
            % + volts gain
            % + screen size
        end
        
        %### conversion functions 
        function hfunc = volts2pixels(vgain,screensize)
            % IN = volts, OUT = pixels
            hfunc = AUXEyeSignalUnitConverter.createAnonymousFunction(abs(vgain),screensize./2,'fwd');
        end
        function hfunc = volts2degrees(vgain,screensize,ppd)
            % IN = volts, OUT = degrees
            hfunc = AUXEyeSignalUnitConverter.createAnonymousFunction(abs(vgain),screensize./(2*ppd),'fwd');
        end
        
        %         function pixels2volts
        %         end
        %         function degrees2volts
        %         end
        %         function pixels2degrees
        %         end
        %         function degrees2pixels
        %         end
        
    end
    
    methods (...
            Static = true,....
            Access = protected)
        
        %# create geometric transform
        function tform = createAffineTform(vgain, units)
            U = [...
                -1,  1;...
                1,  1;...
                1, -1;...
                -1, -1];
            % moving points (IN)
            MP = bsxfun(@times, U, vgain); % [xGain, yGain]
            % control points (OUT)
            CP = bsxfun(@times, U, units); % [xPixels, yPixels] or [scaled pixels per deg]
            % compute transform
            tform  = fitgeotrans(MP, CP,'affine'); %
            
            %CP_pix = CP;
            %CP_deg = CP./this.ppd;
            %tform_pix  = fitgeotrans(MP, CP_pix, 'affine'); % volts to pixels
            %tform_deg  = fitgeotrans(MP, CP_deg, 'affine'); % volts to degrees
        end
        %# create anonymous function
        function hfunc = createAnonymousFunction(U,V,Z)
            tform = AUXEyeSignalUnitConverter.createAffineTform(U,V);
            switch Z
                case 'fwd'
                    hfunc = @(u,v) transformPointsForward(tform, u, v); % output [x,y]
                case 'inv'
                    hfunc = @(x,y) transformPointsInverse(tform, x, y); % output [u,v]
            end
        end
        
    end
    
    
end


%{
ppd = 50;

U = [...
    -1,  1;...
     1,  1;...
     1, -1;...
    -1, -1];
% moving points
MP = bsxfun(@times, U, [10 10]); % [xGain,     yGain]
% control points
CP = bsxfun(@times, U, [1680 1050]./2); % [xPixels, yPixels]

CP_pix = CP;
CP_deg = CP./ppd;

tform_pix = fitgeotrans(MP, CP_pix, 'affine'); % volts to pixels
tform_deg = fitgeotrans(MP, CP_deg, 'affine'); % volts to degrees



vx = -1;
vy = -1;

[xp,yp] = transformPointsForward(tform_pix,vx,vy)


[xd,yd] = transformPointsForward(tform_deg,vx,vy)
%}








