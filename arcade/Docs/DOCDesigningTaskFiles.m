%% Designing a task script
% The task m-file is the where everything about the flow of your experiment
% is defined. In it, all stimuli, and trial states are defined. Each task 
% script contains basically three sections
% 
% # Code to be run at beginning of each trial, e.g. definition of
% eventmarkers, the logic of experimental conditions, etc.
% # Definition of stimuli
% # Definition of trial states
% 
% Task scripts should be stored in subfolder(s) of ARCADE/Tasks.

%% Handling conditions
% Choosing the condition for each trial is done in user-generated condition
% and block selection functions. These functions are selected during the
% configuration of the session and must take the current trial
% as first input and return associated condition/block as first output. For
% example, the following function will return a random condition between 1
% and 10:
%
%   function condition = random_condition(currentTrial)
%   condition = randi(10)
% 
% 
% The block selection script is evaluated first and its outcome can be used
% in the condition selection script as second input argument, e.g.
% 
%   function condition = random_condition(currentTrial, currentBlock)
%   ... 
% 
% 
% To retrieve the outcomes of past trials for determining the next 
% condition use the |getPreviousTrialData| function
help getPreviousTrialData

%% 
% After the selection was completed, the current trial number, condition 
% and block are then available in the task script as the |TrialData| struct, e.g.
% 
%  TrialData = 
% 
%     currentCondition: 8
%         currentBlock: 1
%         currentTrial: 1
% 
% This information can then be used to determine the flow of the trial. 
% 
% If no condition and/or block selection functions are provided, the
% current condition/block is always 1.

%% Creating visual stimuli
% Each stimulus is first defined with several stimulus type-specific
% parameters. The stimulus will then be turned on in the entry or exit 
% functions of the trial states.
% 
% 
%   
%   % Code that creates stimuli
%   target = Circle;
%   target.position = [4 -1];
%   target.color = [0 255 0 128];
%   ...
% 
%
% Documentation of all possible stimuli can be found <DOCAvailableStimuli.html here>.

%% Creating trial states
% The flow of a trial is defined by a sequence of states. Each state starts
% with the execution of its _entry functions_, in which actions such as
% changing the stimulus parameters or triggering event markers can be
% taken.
% 
% After the completion of these, the state waits for the expiration of 
% a timeout or an event, e.g. from an input device such as an eye tracker.
% The next state is determined during this waiting process, either by
% expiration of a timeout or by a triggered event, e.g. a fixation break. 
% 
% After the waiting process is completed the 
% _exit functions_ are executed and the next state started.
% 
% <<state.png>>
% 
% A trial consists of a sequence of these trial states starting at an 
% _initial state_ and ending in a _final state_. States are defined via
% the |State| class
help State
properties('State')
%%
% The states are then passed to the |createTrial| function to create the
% state sequence.
help createTrial
%%
% Events can be triggered by any process and provide a flexible tool for
% managing the flow of the experiment. For example, the EyeServer can set
% events when the eye enters a specific area of the screen. See
% <DOCEyetracking.html here> for the documentation of eye tracking. 

%%
% *Example*
% 
% The example below shows 
% a complete state flow diagram for a simple detection task. 
% 
% <<exampleStateSequence.png>>
% 
% The definition of the states would start like this 
acqFix = State('acqFix');
acqFix.duration = 5000;
acqFix.waitEvents = {'fixIn'};
acqFix.nextStateAfterEvent = {'holdFix'};
acqFix.nextStateAfterTimeout = 'noFix';
acqFix.onEntry = {...
    @(x) eventmarker(1), ...
    @(x) set(fp, 'visible', true), ...
    };

%%
% The complete task script for the above task can be found in
% <matlab:edit(fullfile(arcaderoot,'Tasks','Examples','exampleDetectTask.m')) ARCADE\Tasks\Examples\exampleDetectTask.m> 
