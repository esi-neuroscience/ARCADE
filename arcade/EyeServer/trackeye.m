function eventNames = trackeye(position, tolerance, name)
% TRACKEYE - Tell EyeServer to signal events when gaze enters/exits a screen position
% 
% INPUT
% -----
%   position    : [x y] screen position to be tracked in px rel. to center
%   tolerance   : fixation radius in px around position 
%   name        : name of tracked position
%   
%   or
% 
%   'reset'     : delete all tracked positions
% 
% OUTPUT
% ------
%   eventNames  : cell array of event names that will be triggered by the
%                 EyeServer. 1st element is event for entering a
%                 position, 2nd for leaving a position. These names can be
%                 used for the waitEvents property of the experimental
%                 States.
% 
% EXAMPLE
% -------
%   trackeye('reset')
%   eventNames = trackeye([0 0], 50, 'fixationPoint')
%   eventNames = 
% 
%         'fixationPointIn'    'fixationPointOut'
% 
% Notes: 
%   * To add more than one position, trackeye has to be called repeatedly.
%     Positions will be tracked until trackeye('reset') is called.
%   * Before calling trackeye, the pipe to the EyeServer has to be opened
%     (done automatically by ARCADE).
% 
% See also State, ABSEyeServer, SGLEyeServerPipe
persistent eyeTargets

if nargin == 1 && strcmp(position, 'reset')
    eyeTargets = {};
%     for iTarget = 1:length(eyeTargets)
%         delete(eyeTargets{iTarget})
%         eyeTargets{iTarget} = '';
%         pause(0.001)
%     end
    return
end


eyeTargets{end+1} = CircularEyeTarget(position(1), position(2), tolerance, name);

eventNames = {[name 'In'], [name 'Out']};