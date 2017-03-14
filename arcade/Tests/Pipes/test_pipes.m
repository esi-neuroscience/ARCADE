
addpath(genpath('C:\Toolbox\ARCADE\arcade'))

msNamedPipe = MSNamedPipe; % load library

%% Test: MSNamedPipe 
% server
serverPipe.name = '\\.\pipe\test';
serverPipe.access = 'PIPE_ACCESS_DUPLEX';
serverPipe.mode   = 'PIPE_NOWAIT | PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE';
serverPipe.buffer = [14 14];

serverPipe.handle = MSNamedPipe.mCreateNamedPipeA(serverPipe.name, serverPipe.access, serverPipe.mode, serverPipe.buffer);
success = MSNamedPipe.mConnectNamedPipe(serverPipe.handle);

[result, flags, outSize, inSize, nMaxInstances] = MSNamedPipe.mGetNamedPipeInfo(serverPipe.handle);
assert(result > 0 & flags == 5, 'Server pipe creation using MSNamedPipe failed');

% client
clientPipe.name = '\\.\pipe\test';
clientPipe.access =  'GENERIC_READ_WRITE';
clientPipe.mode   = 'PIPE_NOWAIT | PIPE_READMODE_MESSAGE';

clientPipe.handle = MSNamedPipe.mCreateFileA(clientPipe.name, clientPipe.access);
[result, flags, outSize, inSize, nMaxInstances] = MSNamedPipe.mGetNamedPipeInfo(clientPipe.handle);
assert(result > 0 & flags == 4, 'Client pipe creation using MSNamedPipe failed');

% close handles
MSNamedPipe.mCloseHandle(clientPipe.handle)
MSNamedPipe.mCloseHandle(serverPipe.handle)

%% Test: MSMessagePipe 
% server
serverPipe = TestPipe;
serverPipe.mOpenServer();
% assert(isa(serverPipe.hPipe, 'libpointer')) % works in matlab 2015b

% client
clientPipe = TestPipe;
clientPipe.mOpenClient();
% assert(isa(clientPipe.hPipe, 'libpointer'))

% send some data
tStart = tic;

while toc(tStart) < 5 
    sendData = uint8(randi(255, 1, serverPipe.pipeBuffer(1)));
    serverPipe.mWriteFile(serverPipe.hPipe, sendData);    
    pause(0.001)
    receivedData = clientPipe.mReadFile(clientPipe.hPipe, clientPipe.pipeBuffer(2));
    assert(isequal(sendData, receivedData))
end

MSNamedPipe.mCloseHandle(clientPipe.hPipe)
MSNamedPipe.mCloseHandle(serverPipe.hPipe)


 