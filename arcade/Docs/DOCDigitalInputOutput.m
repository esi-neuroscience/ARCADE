%% Digital input and output
% Handling digital input and output in ARCADE is done via the DaqServer
% module, to which the Core sends commands for input and output. 
% 
% Currently  only a DaqServer for National Instruments Cards is
% implemented, NidaqServer.exe. Detailed documentation for it can be found
% in arcade/DaqServer/NidaqServer.pdf.
%
%% Reward
% Reward signals can be triggered as as on and off times of a digital output
% line via the |reward| command:
help reward
%%
% Alternatively, reward can be triggered by using an event
%%
% 
%   reward = IPCEvent('Reward');
%   reward.trigger();
% 
%%
% The reward button in the Control Screen uses this mechanism. The duration
% of the manual reward can be configured using the
% |DaqServer.SetRewardTime| command. Optionally, the DaqServer can be
% configured to send out an event marker with the manual reward by using
% |DaqServer.SetRewardCode|.

%% Event markers
% Events occuring during the experiment, e.g. stimulus onset times, can be
% signalled to a recording system via digital event markers, usually 8-bit 
% values. An eventmarker can be triggered using the |eventmarker| function.
help eventmarker

%% Tracking digital inputs
% ARCADE can track and respond to digitial inputs delivered via National
% Instruments PCI(e) cards such as the PCI-6221 and PCI-6503 models.
%
% Tracking a digital input line is configured via the |trackdigitalinput| 
% function, which sends a message to the |DaqServer|, which is currently
% always the |NidaqServer.exe|.
help trackdigitalinput
