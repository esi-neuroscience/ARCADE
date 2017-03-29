%% server
clear all
sharedObject = MSNamedSharedMemory;
sharedObject.mCreateFileMapping('EyeMap', 16);

setdatatype(sharedObject.pointer, 'singlePtr', 2);
count = single(0.0);
tStart = tic;
while true
    count = count+1;
    sharedObject.pointer.Value = [count; count];
    pause(0.0001);
end

delete(sharedObject)


%% client
clear all
sharedObject = MSNamedSharedMemory;
sharedObject.mOpenFileMapping('EyeMap');

setdatatype(sharedObject.pointer, 'singlePtr', 2);
while true
    disp(num2str(sharedObject.pointer.Value'));
    pause(0.5);
end
delete(sharedObject);
