
%% launch eye server

launchCmd = 'matlab  -nosplash -r "runEyeServer" ';

% launch process
runtime = java.lang.Runtime.getRuntime();
process = runtime.exec(launchCmd);

%% SGLEyeServerCorePipe
EyeCorePipe = SGLEyeServerCorePipe.launch();
EyeCorePipe.mOpenClient();

%%
EyeCorePipe.mWriteCommandMessage('start_eye');
%%
while true
    EyeCorePipe.mRequestEyeData()
    pause(0.001)
end