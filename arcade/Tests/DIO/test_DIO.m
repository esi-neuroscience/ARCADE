
clear
close all

%% General test of EventMarkerServer
EventServer = SGLEventMarkerServer.launch;

% all possible event markers
for event = 1:2^16-1
    EventServer.mSendEventMarker(event)
    java.lang.Thread.sleep(0.1)
end
% TODO: test 'default'/'leave' options

%% many random event markers
nMin = 60*24*1; % 1 day
nMin = 0.5;
nEvents = 0;
tic
events = randi(2^16-1, 1000,1);
while toc<nMin*60
    
    iEvent = mod(nEvents+1,length(events));
    eventmarker(events(iEvent))
    nEvents = nEvents+1;
    pause(0.1)
    
end
duration = toc;
fprintf('Sent %u events in %g min\n', nEvents, duration/60)

%% General test of RewardServerreward
% RewardServer = SGLRewardServer.launch();

% single reward
reward('pulse', 100)
reward('sequence', [100, 100], [10 0])

%% many rewards
nMin = 0.5;
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


