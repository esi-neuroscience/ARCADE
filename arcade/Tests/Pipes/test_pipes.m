

%% start a matlab
runtime = java.lang.Runtime.getRuntime();
matlabCmd = 'C:\Program Files (x86)\MATLAB\R2014a\bin\matlab.exe';
process = runtime.exec(matlabCmd);


%% server
serverPipe = TestPipe;
serverPipe.mOpenServer()
success = 0;
while ~success
    success = serverPipe.mCheckClientIsConnected();
    fprintf('Waiting...\n')
    pause(1);
end
fprintf('Client connected\n')

%% client
clientPipe = TestPipe;
clientPipe.mOpenClient();