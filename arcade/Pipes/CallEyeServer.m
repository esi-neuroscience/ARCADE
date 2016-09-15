function RESULT = CallEyeServer
RESULT = 1;
% ConnectNamedPipe 
% DisconnectNamedPipe 
% WaitNamedPipe

% mainFrame = com.mathworks.mde.desk.MLDesktop.getInstance.getMainFrame;
% mainFrame.toFront;

thisDirectory = fileparts(mfilename('fullpath'));

% directory for NIDAQ
addpath(fullfile(thisDirectory,'External','mNIDAQmx'));
addpath(fullfile(thisDirectory,'Pipes'));

%addpath('H:\projects\DisplayServer_tasks\DisplayServer\Version_beta\ServerClient');
%addpath(genpath('H:\projects\DisplayServer_tasks\DisplayServer\Version_beta\GUIs'));
%addpath('H:\projects\DisplayServer_tasks\DisplayServer\Version_beta\ExternalModules\mNIDAQmx');


%nBytes = 14;
% Create Two Pipes
% 1. send eye data to Core for behavioural control 
% 2. send eye data to ControlScreen for feedback 

% instance of Eye-Core Pipe 
CorePipe   = SGLEyeServerCorePipe.launch; 
%hPipe_core = CorePipe.mOpenServer;  % connect as server

% instance of Eye-ControlScreen Pipe 
CntrlPipe   = SGLEyeServerCntrlPipe.launch; 
%hPipe_cntrl = CntrlPipe.mOpenServer;  % connect as server



% 2 + 4 + 4 + 4
% 16-bit, X single, Y single, timeStamp - single

% are they connected?
% flags 

% 1. get eye signal 
% 2. read pipe Core
% -> if message send eye signal, write message
% 3. read pipe ControlScreen
% -> if message send eye signal, write message

% should wait for a client to connect, else timeout 

disp('Waiting for connection....');
core_msg = CorePipe.mReadFile(hPipe_core,nBytes);
while isempty(core_msg)
    core_msg = CorePipe.mReadFile(hPipe_core,nBytes);
    java.lang.Thread.sleep(100); % pause a bit
    drawnow;
end

disp('Start Polling Eye Signal....');

% poll eye sigal
while 1
    
    % get eye signal
    eye_pos = randi([-500 500],1,2); % plut time stamp
    % create message
    %byte_msg = [typecast(uint16(90),'uint8'), typecast(single(eye_pos),'uint8')];
    
    
    %byte_msg = KEYEyeServer.mEyeServerMessage('Write',eye_pos);
    
    
    % dispatch eye signal 
    success_core = CorePipe.mDispatchEyeData(eye_pos);
    success_ctrl = CntrlPipe.mDispatchEyeData(eye_pos);

    
%     %---------------------------------%
%     core_msg = CorePipe.mReadFile(hPipe_core,nBytes);
%     if ~isempty(core_msg)
%         success_core_write = CorePipe.mWriteFile(hPipe_core,byte_msg);
%     end
% 
%     ctrl_msg = CntrlPipe.mReadFile(hPipe_cntrl,nBytes);
%     if ~isempty(ctrl_msg)
%         success_cntl_write = CntrlPipe.mWriteFile(hPipe_cntrl,byte_msg);
%     end
    %---------------------------------%
    % interpret core_msg 
    %if ~isempty(core_msg) && typecast(core_msg(1:2),'uint16')==0
    %    break;
    %end
    
    drawnow;
    java.lang.Thread.sleep(1);
end

% disconnect clients 

% first event starts
% second event quits 



% quit 
disp('Quitting...');
% setup better disconnect
CorePipe.mCloseHandle(hPipe_core);
CntrlPipe.mCloseHandle(hPipe_cntrl);

disp('Bye Bye!');
java.lang.Thread.sleep(500);
% quit matlab
quit

%{
% 16-bit key, X single, Y single, timestamp single

% create NIDAQ card object
%---------------------------------------%
%eyelines = {'Dev1/ai0:1'}; % left eye
eyelines = {'Dev1/ai2:3'}; % right eye

nidaqObj = mNIDAQ;                           % create object
nidaqObj.daqmxCreateAIVoltageChan(eyelines); % create channels
%---------------------------------------%

% get function 
vgain        = [10 10]; 
screensize   = [1680 1050];
volts2pixels = AUXEyeSignalUnitConverter.volts2pixels(vgain,screensize);

% fetch eye position
eye_pos = nidaqObj.daqmxReadAnalogF64(1);
% convert eye position into pixels
[xeye,yeye] = volts2pixels(eye_pos(1),eye_pos(2));
%}



end

