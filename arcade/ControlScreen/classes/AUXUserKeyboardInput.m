classdef AUXUserKeyboardInput < handle
    % [AUXILLARY] USER KEYBOARD INPUT
    
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    properties %(SetAccess = private)
        keyPressed  = false;
        userRequest = []; % 'Pause', 'Quit', 'QuickEscape'
    end

    methods (Static)
        function this = AUXUserKeyBoardInput
        end
    end
    
    methods (Sealed = true)
        % set(this.hfig,'WindowKeyPressFcn',...
        %        @(hObj,evt) this.mWindowKeyPressCallback(hObj,evt));
        
        %------------------------------------%
        %#      flag key press 
        % - take first key press
        % - this allows drawnow to be called 
        % - many calls buffer over the trial, if they are not handled
        % - they will all evaluate at the end of the trial
        % - perhaps it is best just to let them execute 
        % - but at the same time prevent this function from executing until
        %  the flag is checked 
        function mWindowKeyPressCallback(this,hObj,evt) %#ok<INUSL>
            
            % reject multiple keypresses
            if this.keyPressed, return; end;
            
            switch evt.Character
                case {'P','p'}
                    % pause
                    this.keyPressed  = true;
                    this.userRequest = 'Pause';
                case {'Q','q'}
                    % quit 
                    %this.keyPressed  = true;
                    %this.userRequest = 'Quit';
                otherwise
                    % nothing
            end
        end
        
        
        function quitSess = mUserPauseScreen(this,BHVstore)
            % get the cfg from the Behavioural Store,
            % and pass working copy of CFG
            %BHVstore = SGLBehaviouralStore.launch;
            while 1
                PauseGui = PauseScreen.launch(BHVstore.cfg); % launch Pause Screen
                quitSess = PauseGui.userQuitRequest;         % get user quit request
                if quitSess
                    break; 
                end
                % only modify cfg if user selected resume 
                BHVstore.cfg = PauseGui.cfg;% retreive the cfg
                break;
            end
            
            delete(PauseGui);
            set(0, 'currentfigure', this.hfig); % make current figure
            drawnow; % force draw
            
            % give some time to complete the draw,
            % so the pause figure is destroyed before resuming
            java.lang.Thread.sleep(20);
        end
        

        
        %# WindowKeyPressCallback
        %------------------------------------%
        % the Interruptible property is set to 'on'
        % thus, this callback can be interrupted,
        % but only when it triggers, calls drawnow, figure, getframe,
        % pause, or waitfor.
        %------------------------------------%
        % prevent multiple keypresses
        % User presses a key
        % key is either Q or P
        % P can enter quit
        % Q goes directly to quit
        %{
        function mWindowKeyPressCallback(this,hObj,evt) %#ok<INUSL>
            % quit session flag
            quitSession = false; 
            
            switch evt.Character
                case {'P','p'}
                    % user has pressed pause
                    disp('Pause...');
                    
                    % get the cfg from the Behavioural Store,
                    % and pass working copy of CFG
                    BHVstore = SGLBehaviouralStore.launch;
                    PSgui = PauseScreen.launch(BHVstore.cfg);    % launch Pause Screen
                    quitSession  = PSgui.userQuitRequest;        % get user quit request
                    BHVstore.cfg = PSgui.cfg;                    % retreive the cfg
                    delete(PSgui);
                    set(0, 'currentfigure', this.hfig); % make current figure
                    drawnow;                            % force draw
                    % give some time to complete the draw, 
                    % so the pause figure is destroyed before resuming
                    java.lang.Thread.sleep(50);         
                    
                case {'Q','q'}
                    % user has pressed quit 
                    quitSession = true;
                otherwise
            end
            
            % has quit session been flagged
            % either by pressing 'q'
            % or by pressing the QUIT button 
            % in the Pause screen
            if quitSession
                disp('Quit...');
                % flag session quit 
                SArc = SGLSessionArc.launch;
                SArc.quitSession = true;
            end
        end
        %}
    end
end

