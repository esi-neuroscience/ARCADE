function allStimuliVisible(visible)
%ALLSTIMULIVISIBLE Change visibility of all stimuli
%
% ONLY FOR DEBUGGING. DO NOT USE FOR REAL EXPERIMENTS!
% 
% This function does not update the MATLAB Stimulus objects. The
% Stimulus.visible property will not reflect the state of the stimulus on
% screen anymore. The Stimulus.toggle_visibility method won't work anymore.
%
% See also StimServer
warning('ALLSTIMULIVISIBLE ISONLY FOR DEBUGGING. DO NOT USE FOR REAL EXPERIMENTS!')
StimServer.ShowAll(visible)

end


