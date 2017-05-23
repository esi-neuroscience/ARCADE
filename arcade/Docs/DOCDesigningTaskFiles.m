%% Designing a task file
% The task m-file is the where everything about the flow of your experiment
% is defined. In it, all stimuli, and trial states are defined. Each task file 
% contains basically three sections
% 
% # Code to be run at beginning of each trial, e.g. definition of
% eventmarkers, the logic of experimental conditions, etc.
% # Definition of stimuli
% # Definition of trial states

%% Creating the stimuli
% Each stimulus is first defined with several stimulus type-specific
% parameters. The stimulus will then be turned on in one of the trial
% states.
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