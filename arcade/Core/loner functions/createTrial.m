function createTrial(initialState, varargin)
% CREATETRIAL - Create and start a trial from several trial states
% 
% INPUT 
% -----
%   initialState : name of first state as string
%   states : experimental states of class State
% 
%
% EXAMPLE
% -------
%   initialState = 'acqFix';
%   sAcquireFix = State('acqFix')
%   ... 
%   createTrial(initialState, sAcquireFix, ...)
%   
% See also State, SGLStateArc


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

