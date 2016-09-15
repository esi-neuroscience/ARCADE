classdef (Sealed) SGLStimServer < handle
    % [SINGLETON CLASS] STIMSERVER
    % this class has is a singleton,
    % and has 2 primary functions:
    %   launch StimServer
    %   open pipe 
    
    % *StimServer.exe is assumed to be in the directory one up
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    properties (SetAccess = immutable)
        pipeObj
    end
    
    properties (AbortSet = true)
       isRunning  = false;
       pipeIsOpen = false;
    end
    
    methods (Static = true)
        function this = launch
            persistent thisObj
            if isempty(thisObj) || ~isvalid(thisObj)
                thisObj = SGLStimServer;
            end
            this = thisObj;
        end
    end
    
    methods (Access = private)
        %# constructor
        function this = SGLStimServer
            % launch display server 
            this.mLauchStimServer;

            % bring matlab to front
            %bringMatlabToFront;

            if this.isRunning
                this.pipeObj    = SGLOpenPipe.fetch; % open pipe
                this.pipeIsOpen = isvalid(this.pipeObj);
            else
                % working directory must have StimServer
                error('DisplayServer: Unable to launch StimServer.exe');
            end
            
            this.mSwitchWorkingDirectory('Previous');
        end
        %# launch StimServer.exe
        % StimServer.exe is assumed to be in the directory one up
        function mLauchStimServer(this)
            % check if running. if running, kill
            perl('quitproc.pl','StimServer.exe','kill');
            
            this.mSwitchWorkingDirectory('StimServerFolder');
            
            % launch StimServer.exe and return control to matlab
            !StimServer.exe &
            
            % check if launch was successful
            [~,this.isRunning] = perl('quitproc.pl','StimServer.exe','isRunning');
            
            this.mSwitchWorkingDirectory('Previous');
        end
        
        %# 
        function mSwitchWorkingDirectory(~,task)
            persistent currentFolder
            % assume this file is in the same folder as the StimServer
            switch task
                case 'StimServerFolder'
                    currentFolder = pwd; % current working directory
                    mfilepath = fileparts(mfilename('fullpath')); 
                    stimServerPath = fileparts(mfilepath);
                    cd(stimServerPath);
                case 'Previous'
                    cd(currentFolder); % move back to old folder
            end
        end
    end
    
    methods
        function delete(this)
            % kill the StimServer.exe
            if this.isRunning
                try
                    perl('quitproc.pl','StimServer.exe','kill');
                    this.isRunning = false;
                catch ME
                    throw(ME);
                end
            end
            if this.pipeIsOpen
                delete(this.pipeObj);
                this.pipeIsOpen = isvalid(this.pipeObj);
            end
        end
    end
    
end

function mBringMatlabToFront
%commandwindow; %pause(1);
mainFrame = com.mathworks.mde.desk.MLDesktop.getInstance.getMainFrame;
mainFrame.toFront;
end