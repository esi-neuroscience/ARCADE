%% Tracking the eye position
% ARCADE can track and respond to the eye position of the subject. This is
% handled by the |EyeServer|, which sets system events when the gaze enters
% an area. 
%
% Tracking the eye is configured via the |trackeye| function, which sends a
% message to the |EyeServer|.
help trackeye
%%
% The current eye position can also be retrieved via the |EyeClient| class.
eye = EyeClient;
eye.eyePosition