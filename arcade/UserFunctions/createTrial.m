function createTrial(initialState, varargin)
%CREATETRIAL Create and start a trial from several trial states
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
% For more information, see <a href="matlab:doc('arcade')">the ARCADE guide</a>.
%
% See also State, SGLStateArc


% add states to state arc
stateArc = SGLStateArc.launch;
stateArc.states = [varargin{:}];
if ~ismember(initialState, stateArc.stateNames)
    error('Initial state %s is not among defined states', initialState)
end
stateArc.initialState = initialState;
  
end


