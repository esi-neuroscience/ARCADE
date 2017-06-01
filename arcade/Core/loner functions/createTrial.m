function createTrial(initialState, varargin)
% Create and start a trial from several trial states
% 
% INPUT 
% -----
%   initialState : name of first state as string
%   state1 : definitions of state as struct array with fields
%       .name    :  name of state as string
%       .onEntry :  cell array of anonymous functions to be executed when
%                   the state is started
%       .onExit  :  cell array of anonymous functions to be executed when
%                   the state ends
%       .duration:  duration of state in ms if no eye tracking event is
%                   triggered
%       .nextState: name of next state to be run if duration expires and no
%                   eye tracking event is triggered
%       .trackEye:  definition of eye tracking behavior
%   state2 : ...
%   state3 : ...
% 
% The state with nextStat='final' will be the last state of the trial.
%
%
% Example
% -------
%   initialState = 'acqFix';
%   sAcquireFix = [];
%   sAcquireFix.name      = 'acqFix';
%   sAcquireFix.duration  = 5000;
%   sAcquireFix.nextState = 'ignore';         
%   sAcquireFix.trackEye  = eyesEnterFixation;  
%   sAcquireFix.onEntry   = {...
%       {@() eventmarker(1)}, ...
%       {@() set(fixationPoint, 'visible', true)};
%   ... 
%   createTrial(initialState, sAcquireFix, ...)
%   
% See also <a
% href="https://de.mathworks.com/help/matlab/matlab_prog/anonymous-functions.html">Anonymous Functions</a>, TRLState


% add states to state arc
stateArc = SGLStateArc.launch;
stateArc.mAddState(varargin{:});
stateArc.initialState = initialState;

end

