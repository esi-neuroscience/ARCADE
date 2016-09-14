


% WHY?
% When sampling the eye signal 
% *** every 65 samples the sampling rate jumps to ~2ms from ~1ms ***

% TO DO:
% - complete class methods
% - get channels
% - get specs 

% methods:
% + DAQmxGetNthTaskReadChannel

% + DAQmxGetReadAttribute
% + DAQmxSetReadAttribute
% + DAQmxResetReadAttribute

% + DAQmxWriteDigitalU8
% + DAQmxWriteDigitalU16

% + DAQmxGetWriteAttribute

% + DAQmxCfgOutputBuffer
% + DAQmxCfgInputBuffer
% + DAQmxGetBufferAttribute
% + DAQmxSetBufferAttribute

% + DAQmxResetDevice
% + DAQmxGetDeviceAttribute
% + DaqmxGetSystemInfoAttribute

% + DAQmxCreateWatchdogTimerTask

% + DAQmxGetPhysicalChanAttribute

% + DAQmxGetBufInputOnbrdBufSize
% + DAQmxGetBufInputBufSize

% + DAQmxStartTask
% + DAQmxStopTask
% + DAQmxWaitUntilTaskDone

delete(reward)
delete(events)
delete(eyeData)
% delete(events)
% clear('events')

close all
clear all
clear classes
clc

cd('H:\projects\displayServer\mNIDAQmx');


RUN.rewardExample    = 0;
RUN.eventsExample    = 0;
RUN.eyeSampleExample = 0;
%%%----------------------------------------------------%%%
if RUN.rewardExample
    
    reward = mNIDAQ;
    reward.daqmxCreateTask('reward');
    reward.daqmxCreateDOChan({'Dev1/port2/line3'});
    
    msdur = 100; % ms
    % reward
    t = tic;
    reward.daqmxWriteDigitalLines(1); % open
    java.lang.Thread.sleep(msdur) % will fluctuate by a bit, but is more accuate than pause
    reward.daqmxWriteDigitalLines(0); % close
    rewTime = toc(t)*1000;
    
end


%%%----------------------------------------------------%%%
if RUN.eventsExample
    % send event trigger
    
    evtLines = {...
        'Dev1/port0/line7:0',...
        'Dev1/port1/line7:0',...
        'Dev1/port2/line7'};
    % create session, add lines
    events = mNIDAQ;
    events.daqmxCreateTask('events');
    events.daqmxCreateDOChan(evtLines);
    
    nbits     = 16;
    N         = 1000;
    evt_times = zeros(N,1);
    
    for k = 1:N
        bin_evt = decimalToBinaryVector(k,nbits);
        t = tic;
        events.daqmxWriteDigitalLines([bin_evt,1]); % write to port and trigger event
        evt_times(k) = toc(t)*1000;
        events.daqmxWriteDigitalLines(zeros(1,nbits+1)); % zero port(s)
        java.lang.Thread.sleep(10) % sleep 10 ms
    end
    
    figure;
    set(gcf,'color','w','position',[100 250 1200 400]);
    
    hold on;
    plot(evt_times);
    plot([1 N],ones(1,2)*mean(evt_times),'k--'); 
    xlabel('events (N)');
    ylabel('Time (ms)');
    title('Time to Trigger Event');

end

%%%----------------------------------------------------%%%

if RUN.eyeSampleExample
    % *** every 65 samples the sampling rate jumps to ~2ms from ~1ms ***
    
    eyeData = mNIDAQ;
    eyeData.daqmxCreateTask('eyedata');
    eyeData.daqmxCreateAIVoltageChan({'Dev1/ai0','Dev1/ai1'}); % left eye
    %eyeData.daqmxCreateAIVoltageChan({'Dev1/ai2','Dev1/ai3'}); % right eye
    
    DAQmx_Dev_AI_MinRate = 10638;
    value = eyeData.daqxGetDeviceAttribute(DAQmx_Dev_AI_MinRate)
    
    
    N = 1000;
    sampTime = zeros(N,1);
    eye_pos  = zeros(2,N);
    
    t = tic;
    for k = 1:N
        eye_pos(:,k) = eyeData.daqmxReadAnalogF64(1);
        sampTime(k) = toc(t)*1000;
        %java.lang.Thread.sleep(4)
    end
    
    
    figure;
    set(gcf,'color','w','position',[100 250 1200 400]);
    
    hold on;
    plot(diff(sampTime));
    plot([1 N-1],ones(1,2)*mean(diff(sampTime)),'k--'); 
    xlabel('Samples (N)');
    ylabel('Inter-Sample-Interval (ms)');
    title('Sampling Eye Data');
    
    %plot(eye_pos(1,:),eye_pos(2,:));
    %xlim([-11 11]); ylim([-11 11]);
    %set(gca,'DataAspectRatio',[1 1 1]);
    
end

%{
DAQmx_Sys_DevNames 	6459

DAQmx_Dev_AI_Gains 	10643
DAQmx_Dev_AI_FreqRngs 	10642

DAQmx_Dev_AI_MaxSingleChanRate 	10636
DAQmx_Dev_AI_MaxMultiChanRate 	10637
DAQmx_Dev_AI_VoltageRngs 	10640

DAQmx_Dev_AI_MinRate 	10638


DAQmx_Dev_AI_PhysicalChans 	8990
DAQmx_Dev_AO_PhysicalChans 	8991
DAQmx_Dev_DI_Lines 	8992
DAQmx_Dev_DI_Ports 	8993
DAQmx_Dev_DO_Lines 	8994
DAQmx_Dev_DO_Ports 	8995

DAQmx_Dev_DI_MaxRate 	10649
DAQmx_Dev_DO_MaxRate 	10650

DAQmxGetSystemInfoAttribute(DAQmx_Sys_DevNames, NULL) = 5
DAQmxGetSystemInfoAttribute(DAQmx_Sys_DevNames, ["Dev1"]) = DAQmxSuccess
DAQmxGetDeviceAttribute("Dev1", DAQmx_Dev_AI_PhysicalChans, NULL) = 341
DAQmxGetDeviceAttribute("Dev1", DAQmx_Dev_AI_PhysicalChans, [""]) = DAQmxErrorBufferTooSmallForString
DAQmxGetDeviceAttribute("Dev1", DAQmx_Dev_AO_PhysicalChans, NULL) = 39
DAQmxGetDeviceAttribute("Dev1", DAQmx_Dev_AO_PhysicalChans, [""]) = DAQmxErrorBufferTooSmallForString
DAQmxGetDeviceAttribute("Dev1", DAQmx_Dev_DO_Lines, NULL) = 885
DAQmxGetDeviceAttribute("Dev1", DAQmx_Dev_DO_Lines, [""]) = DAQmxErrorBufferTooSmallForString
DAQmxGetDeviceAttribute("Dev1", DAQmx_Dev_DI_Lines, NULL) = 885
DAQmxGetDeviceAttribute("Dev1", DAQmx_Dev_DI_Lines, [""]) = DAQmxErrorBufferTooSmallForString

%}


















