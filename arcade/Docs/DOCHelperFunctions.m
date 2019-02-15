%% User functions
% ARCADE provides several <matlab:doc('UserFunctions') UserFunctions> 
% that are useful for controlling  the experiment and storing additional 
% behavioral data. See below for a
% list. They are stored in the |ARCADE/arcade/UserFunctions| folder.

%% backgroundColor
help backgroundColor
    
%% convertEsiFile
help convertEsiFile

%%


    createTrial             - Create and start a trial from several trial states
    eventmarker             - Send a digital marker for an event to the DAQ card (if
    getPreviousTrialData    - Retreive behavioral outcomes and conditions of
    groupStimuli            - Group changes to stimuli together.
    logmessage              - Write message with timestamp to terminal and log
    photodiode              - Set the mode of the photodiode stimulus
    reactiontime            - Measure and store reaction times.
    readEvtFile             - Read .evt file written by ARCADE.
    requestQuitSession      - end session after current trial
    retrieveConfig          - Retreive ArcadeConfig of current session
    reward                  - Give a reward pulse or pulse sequence.
    setManualRewardDuration - Set reward duration for manual reward
    storeUserVariables      - Store a variable in the behavioral data file of ARCADE.
    totalRewardTime         - Retreive total reward of session
    trackdigitalinput       - Tell DaqServer to signal events when digitial input line
    trackeye                - Tell EyeServer to signal events when gaze enters/exits a screen position
    trialerror              - Store outcome of trial in behavioral record file
    StateRuntimeVariable    - Class for storing values in onEntry/onExit
                              State functions