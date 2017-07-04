
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%      Eye Calibration with Eyelink
% ---------------------------------------
% 
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% To Do:
% - add in check calibration at the end of calibration
% for now this is just accomplished in Eyelink
% - start validation, for now this is done in Eyelink
% - break calibration, move to next trial

% - calibration background and fixation should mirror the average luminance
% in your experiment
% - the idea of the small black dot in the centre of the white dot is to
% make the target more visible 

% editable 
editable('reward_dur','ITI');

%ELKEY_DOWN = 1;
%ELKEY_UP   = 0;
% hard code key codes
KB_PRESS   = 10; % Eyelink.h
ENTER_KEY  = hex2dec('000D');
ESC_KEY    = hex2dec('001B');
BCK_SPC    = 008;

% for reference:
% Eyelink('SendKeyButton', double('c'), 0, KB_PRESS ); % start calibration
% Eyelink('SendKeyButton', double('v'), 0, KB_PRESS ); % start validation
% Eyelink('SendKeyButton', BCK_SPC,     0, KB_PRESS ); % move back one point 
% Eyelink('SendKeyButton', ESC_KEY,     0, KB_PRESS ); % reset all points
% Eyelink('SendKeyButton', ENTER_KEY,   0, KB_PRESS ); % accept point, and cal/val

% --------- objects ------------% 
fp = 1;

%--------- set the ITI ---------%
ITI = 500;  % it seems like it needs a minimum of 1000ms
set_iti(ITI);

%-------- reward params --------%
reward_dur    = 50; % editable reward
smRewardPulse = 50; % add to reward_dur for total reward
smRWIdle      = 50; % time duration between reward pulses 

% --------  hotkeys  --------%
acceptKey = 'n'; % accept point
bckoneKey = 'b'; % back one
rejallKey = 'x'; % reject all
quickEscapeKey = 's';

hotkey(acceptKey, sprintf('Eyelink(''SendKeyButton'', %d,   0, %d ); goodmonkey(%d); abort_trial;', ENTER_KEY, KB_PRESS, reward_dur));
hotkey(bckoneKey, sprintf('Eyelink(''SendKeyButton'', %d,   0, %d ); abort_trial;', BCK_SPC, KB_PRESS));
hotkey(rejallKey, sprintf('Eyelink(''SendKeyButton'', %d,   0, %d ); goodmonkey(%d); abort_trial;', ESC_KEY, KB_PRESS, reward_dur));
hotkey(quickEscapeKey, 'escape_screen; abort_trial;'); % flag ESC and abort to enter ESC screen immediately

% for auto calibration one would either use eyelink 
% or one could look for period of time where the eye is stable 
%[analogdata frq] = get_analog_data(signal, duration)

% time of idle 
wait_for_fix  = 10000; % a sufficiently long time 
fix_radius = 2; % does not really matter
% ------ start task ------ %

if TrialRecord.CurrentTrialWithinBlock == 1 && TrialRecord.CurrentBlock == 1
    % start calibration
    Eyelink( 'StartSetup' ); % set to Camera Setup screen
    Eyelink( 'SendKeyButton', double('c'), 0, KB_PRESS );

    idle(500, ScreenInfo.BackgroundColor); % need to allow EL to setup 
    % could check if EyeLink is connected?
end

% ----- get target position ----%
% ask Eyelink for current position
[~, targX, targY] = Eyelink('targetcheck');
targetPos = [targX, targY];
%ScreenInfo
targetPos = (targetPos - round([ScreenInfo.Xsize*0.5 ScreenInfo.Ysize*0.5])).*[1.0 -1.0];         
%%% The incoming Eyelink signal is in pixels, convert to degrees
targetPos = targetPos./ScreenInfo.PixelsPerDegree;  % pixels per degree


% ----- re-position object -----% 
reposition_object(fp, targetPos(1),targetPos(2));


% ------- display target ------ %
toggleobject(fp);% turn on target


%[ontarget rt] = eyejoytrack('idle', target, fix_radius, wait_for_fix);
% track the eyes 
idle(wait_for_fix); 

% Becaue you theoretically abort each trial this code never gets executed
% but incase the max timne elapses then it would be
toggleobject(fp); % turn off target

% goodmonkey(reward_dur);
trialerror(4); % Correct






























