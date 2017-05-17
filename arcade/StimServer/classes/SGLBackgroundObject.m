classdef (Sealed) SGLBackgroundObject
    % [SINGELTON]
    
    % singleton class
    % meant to evolve into class for the background
    % image or solid color 
    % control pause/resume screen
    % control background in ITI etc
    
    % background loner function will need to be revised accordingly
    
    % 1. pause screen
    % 2. main background 
    % - visible
    % - set color/image 
    
    % maintained through out trials 
    % leads to the idea of "persistent stimuli"
    % - background is a persistent stimulus
    % - other objects can be as well 
    
    %---------------------------------------------%
    % 13.8.2015 - Jarrod, wrote class
    % 12.4.2016 - Jarrod
    % - update methods for AUXPipeReadWrite
    % - remove the image class
    % 21.4.2016 - Jarrod, 
    % - removed image functionality
    % - changed name of class
    

    properties 
        backgroundColor  = [128,128,128];
        pauseColor       = [128,128,128];
    end

    methods (Static)
        function this = launch
            persistent thisObj
            if isempty(thisObj) || ~isvalid(thisObj)
                thisObj = SGLBackgroundObject;
            end
            this = thisObj;
        end
    end
    
    
    methods (Access = private)
        function this = SGLBackgroundObject
        end
    end

    methods
        %# Turn ON background
        function setBackground(this)
            % set background color
            StimServer.SetBackgroundColor(this.backgroundColor);
        end
        %# Turn ON Pause Screen
        function setPauseScreen(this) % turn on
            % set pause color
            StimServer.SetBackgroundColor(this.backgroundColor);
        end
    end
    
end

