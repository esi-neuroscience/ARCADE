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
% TrialData = 
% 
%     currentCondition: 8
%         currentBlock: 1
%         currentTrial: 1
% DESCRIPTIVE TEXT
% % 


%% Creating the stimuli
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
% Documentation of all possible stimuli can be found in <DOCAvailableStimuli.html>.

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
% _initial state_ and ending in a _final state_. The example below shows 
% a complete state flow diagram for a simple detection task. 
% 
% <<exampleStateSequence.png>>
% 

% 

%%
% *Example*
% 
%   sAcquireFix = [];
%   sAcquireFix.name      = 'acqFix';
%   sAcquireFix.duration  = trl.acqFixTime;
%   sAcquireFix.nextState = 'ignore';          % if time elapses
%   sAcquireFix.trackEye  = eyesEnterFixation;  % this changes nextState
%   sAcquireFix.onEntry   = {...
%       {@() eventmarker(trig.acqFixation)}};
%   sAcquireFix.onRunNum.onEntry{1} = {... % only evaluate on the first entry
%       {@() eventmarker(trig.FixSpotOn)},...
%       {@() groupStimuli('start')},...
%       {@() set(fixObj, 'visible', true)},... 
%       {@() backgroundColor([128,128,128])},...
%       {@() groupStimuli('end')}};
%   sAcquireFix.onRunNum.onEntry{2} = {... % on second entry change duration
%       {@(me) set(me,'duration',trl.reAcqFixTime), 'self'}};
%  ...
%  initialState = 'acqFix';
%  createTrial(initialState,...
%      sAcquireFix, 
%      ...
%      );