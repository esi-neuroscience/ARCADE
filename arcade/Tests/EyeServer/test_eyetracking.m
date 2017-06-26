
 SGLEyeServerPipe.Open()
%%
 pauseTime = 0;
 n = 1;
while true
    disp(n)
%     pause(pauseTime)
    disp('Reset eye trackers')
    trackeye('reset');
%     pause(pauseTime)
    disp('Set eye trackers')
    eventNames = trackeye([500 500], 50, 'fix');
%     pause(pauseTime)
    disp('Delete events')
    MultipleEvents.delete();    
    pause(pauseTime)
    disp('Init events')
    MultipleEvents.Init(eventNames);
    pause(pauseTime)
    disp('Waiting')
    result = MultipleEvents.WaitFor('fixIn', false, 60000)    
    
    
    
    
    n = n+1;
end

%%
SGLEyeServerPipe.Close()
clear classes
