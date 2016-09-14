function createTrial(initialState,varargin)

% user should pass ->
% (initialState, Structs,.....)

% error check! varargin are all structs?

% get instance of SesArc
% *already created in SessionArc*
stateArc = SGLStateArc.launch;
stateArc.mAddState(varargin{:});
stateArc.initialState = initialState;

end

