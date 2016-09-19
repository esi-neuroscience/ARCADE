%% Tracking the eye position
% ARCADE can track and respond to the eye position of the subject. This is
% defined in the |trackEye| property of each trial state. When defining a
% state the trackEye property can be set with a struct with the following
% fields
%%
%
% * |method|: |'circle'| (further methods will be implemented later)
% * |report|: |'enter'| or |'leave'| . Defines for which change of the eye 
%               position change the |nextState| is entered.  
% * |nextState|: Name of the next state as string
% * |center|: |[x y]| coordinates of tracked position in pixels
% * |radius|: Radius of tracking area around tracked position in pixels
% 
% For example:

% define trackEye for use in state definition
trackEye = struct(...
    'method', 'circle', ...
    'report', 'enter', ...
    'nextState', 'holdFix', ...
    'center', [0 0], ...
    'radius', 0.8);

% state definition
sAcquireFix = [];
sAcquireFix.name      = 'acqFix';
sAcquireFix.duration  = 0.8;
sAcquireFix.nextState = 'ignore';         
sAcquireFix.trackEye  = trackEye;