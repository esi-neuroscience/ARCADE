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
    if rem(count, 100) == 0
        fprintf('%g\n', count)
    end
end

delete(sharedObject)


%% client
clear all
sharedObject = MSNamedSharedMemory;
sharedObject.mOpenFileMapping('EyeMap');

setdatatype(sharedObject.pointer, 'singlePtr', 2);
while true
    data = sharedObject.pointer.Value';
    disp(data);
    if data(1) ~= data(2)
        warning('Value mismatch')
    end
    pause(0.1);
end
delete(sharedObject);
