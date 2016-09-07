


%------------------------------------------%
% 2.5.2016 - Jarrod, wrote function 

function runEyeServer 
%--------------------------%
% turn on all warnings
warning('on','all');
% turn off some known warnings 
warning('off','MATLAB:RMDIR:RemovedFromPath');
% some notation I used that should be fixed 
warning('off','MATLAB:mir_warning_unrecognized_pragma');
%--------------------------%
initialWorkingDirectory = pwd;
cd(fileparts(mfilename('fullpath'))); 

% create instance of server/process
PROC = SGLEyeServerProc.launch;  
% move back to original working directory
cd(initialWorkingDirectory);
% run server
PROC.mRunServer; 

% cleaup
delete(PROC);

java.lang.Thread.sleep(500);
% quit matlab
quit

end




















