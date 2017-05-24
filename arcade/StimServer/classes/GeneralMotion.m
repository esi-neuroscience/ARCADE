classdef GeneralMotion < Animation
    % Class for arbitrary animations along positions read from a file.
    % 
    % In Matlab you can create files by calling NumericBinaryFile with a 
    % single(2,n) array. The array has to contain pixel coordinates for 
    % each frame.    
    %     
    % THIS STIMULUS IS STILL UNTESTED.
    %     
    % See also Animation, Stimulus, NumericBinaryFile
    
    properties ( SetAccess = immutable )
       filename = []; % filename to NumericBinaryFile with coordinates
    end
    
    methods
        function obj = GeneralMotion(filename)
            StimServer.Command(0, uint8([130 filename]))
            obj = obj@Animation();
            obj.filename = filename;            
        end
        
    end
    
    
end