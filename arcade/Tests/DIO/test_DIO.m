
clear
close all

%% EventMarkerServer
EventServer = SGLEventMarkerServer.launch('test.evt');


% all possible event markers via mSendEventmarker
fprintf('Sending all possible eventmarkers via mSendEventMarker (2^16=65535)\n)')
tic;
for event = 1:2^16-1
    EventServer.mSendEventMarker(event)
    java.lang.Thread.sleep(0.01)
    if mod(event, 1000) == 0
        t = toc;
        fprintf('%u/2^16 events (%.0f%%), %.0f s  \n', event, event/2^16*100, t)
        EventServer.writeEvents()
    end
end
t = toc;
fprintf('Sent %u events in %g min (%g events/s)\n', event, t/60, event/t)
% TODO: test 'default'/'leave' options
EventServer.writeEvents()
delete(EventServer)

%% many random event markers via eventmarker
nMin = 60*24*1; % 1 day
nMin = 60;
nEvents = 0;
tic
events = randi(2^16-1, 1000,1);
fprintf('Sending random eventmarkers for %g min...\n', nMin)
while toc<nMin*60       
    eventmarker(events(1))
    events = circshift(events, 1);
    nEvents = nEvents+1;
    java.lang.Thread.sleep(0.01)
    t = toc;
    if mod(nEvents,1000) == 0
        fprintf('Sent %u events in %.1f min (%g events/s)\n', nEvents, t/60, nEvents/t)
    end
end
duration = toc;
fprintf('Sent %u events in %.1f min (%g events/s)\n', nEvents, duration/60, nEvents/duration)

%% RewardServer
RewardServer = SGLRewardServer.launch();

% single reward
reward('pulse', 100)
reward('sequence', [100, 100], [10 0])

%% many rewards
nMin = 60;
nRewards = 0;
tic
events = randi(2^16-1, 1000,1);
rewardDuration = 100;
while toc<nMin*60        
    reward('pulse', rewardDuration)
    nRewards = nRewards+1;
    pause(0.5)    
end
endduration = toc;
fprintf('Sent %u rewards in %g min\n', nRewards, duration/60)

clear RewardServer


