


%------------------------------------------%
% 2.5.2016 - Jarrod, wrote function 

function runCore
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
PROC = SGLCoreProc.launch; 
% move back to original working directory
cd(initialWorkingDirectory);
% run server
PROC.mRunServer; 


% cleanup
PROC.mWriteToDiary('Closing MATLAB in 5 s. Press CTRL+C to cancel or see log files', true);
delete(PROC);
for seconds = 5:-1:0
    fprintf('%g\n', seconds)
    pause(1)
end
exit

end




















