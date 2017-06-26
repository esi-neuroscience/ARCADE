function createTrial(initialState, varargin)
% Create and start a trial from several trial states
% 
% INPUT 
% -----
%   initialState : name of first state as string
%   states
% 
% The state with nextState='final' will be the last state of the trial.
%
%
% Example
% -------
%   initialState = 'acqFix';
%   sAcquireFix = State('acqFix')
%   sAcquireFix.duration  = 5000;
%   sAcquireFix.nextState = 'ignore';         
%   sAcquireFix.onEntry   = {...
%       {@() eventmarker(1)}, ...
%       {@() set(fixationPoint, 'visible', true)};
%   ... 
%   createTrial(initialState, sAcquireFix, ...)
%   
% See also State


% add states to state arc
stateArc = SGLStateArc.launch;
MultipleEvents.delete();
stateArc.states = [varargin{:}];
if ~ismember(initialState, stateArc.stateNames)
    error('Initial state %s is not among defined states', initialState)
end
stateArc.initialState = initialState;
if ~isempty(unique([stateArc.states.waitEvents]))
    MultipleEvents.Init(stateArc.eventNames);
end    
end

