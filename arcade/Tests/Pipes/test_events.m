

eventName = 'testEvent';
%% Test: MSEvents 
% server
addpath(genpath('C:\Toolbox\ARCADE\arcade'))
msevents = MSEvents; % load library



hEventServer = msevents.mCreateEventA(eventName);

timeout = 60000;
result = msevents.mWaitForEvent(serverEvent.handle, timeout);
disp('Done')

msevents.mCloseHandle(hEventServer);

%% client
addpath(genpath('C:\Toolbox\ARCADE\arcade'))
msevents = MSEvents; % load library

hEventClient = msevents.mOpenEventA(eventName);
result = msevents.mSetEvent(hEventClient);
result = msevents.mCloseHandle(hEventClient);
