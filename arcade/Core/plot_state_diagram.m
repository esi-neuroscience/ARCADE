function [G,h] = plot_state_diagram(varargin)
% PLOT_STATE_DIAGRAM - Plot flow diagram of states
%   
%     plot_state_diagram(state1, state2, ...)
% 
% INPUT
% -----
%      state1 : ARCADE State object
%      state2 : ...
% 
% 
% OUTPUT
% ------
%       G   :  digraph object
%       h   :  GraphPlot object
%
% Note: This function only works with MATLAB >= 2014b
% 
% EXAMPLE
% -------
% 
% waitForResponse = State('waitForResponse');
% waitForResponse.duration = 5000;
% waitForResponse.nextStateAfterTimeout = 'noResponse';
% waitForResponse.waitEvents = {'leverPull', 'leverPush'} ;
% waitForResponse.nextStateAfterEvent = {'pull', 'push'};
% 
% pull = State('pull');
% pull.nextStateAfterTimeout = 'final';
% 
% push = State('push');
% push.nextStateAfterTimeout = 'final';
% 
% noResponse = State('noResponse');
% noResponse.nextStateAfterTimeout = 'final';
% 
% plot_state_diagram(waitForResponse, pull, push, noResponse)
% 
% See also State, digraph

if verLessThan('matlab', 'R2014b') || verLessThan('MATLAB', '8.4')
    error('MATLAB:digraph:MATLAB versions older than R2014b are not supported')
end
%% adjacency matrix
nodenames = [cellfun(@(x) x.name, varargin, 'UniformOutput', false) 'final'];
A = zeros(length(nodenames));
for iNode = 1:length(varargin)
    state = varargin{iNode};
    A(iNode, ismember(nodenames, state.nextStateAfterEvent)) = 1;
    A(iNode, ismember(nodenames, state.nextStateAfterTimeout)) = 2;
    A(iNode, ismember(nodenames, state.nextStateAfterMaxRepetitions) & ...
        repmat(~isinf(state.maxRepetitions), [1 length(nodenames)])) = 3;
    
    
end

%% plot
figure
G = digraph(A, nodenames);
h = plot(G);

h.EdgeCData = nonzeros(A);
colormap(lines(3));


if nargout == 0
    clear G h
end