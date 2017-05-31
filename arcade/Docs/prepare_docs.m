function prepare_docs(format)
% Convert documentation into readable format: html, pdf or doc

if ~exist('format', 'var'); format = 'html'; end
outputdir = fullfile(arcaderoot, 'arcade', 'Docs', format);

cmd = fullfile(arcaderoot, 'arcade', 'StimServer', 'StimServer.exe');
stimServerProcess = processManager('command', cmd, 'autoStart', true);
pause(1)
tStart = tic;
while toc(tStart)<15
    try
        StimServer.Connect();       
        break
    catch me
        pause(0.5);
        continue
    end
    
end

docDirectory = fileparts(mfilename('fullpath'));

docFiles = dir(fullfile(docDirectory, 'DOC*.m'));

for iFile = 1:length(docFiles)
    publish(fullfile(docDirectory, docFiles(iFile).name), 'format', format, 'outputDir', outputdir)
end
StimServer.Disconnect();
stimServerProcess.stop()