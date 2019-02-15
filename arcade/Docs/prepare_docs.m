function prepare_docs(format)
% Convert documentation into readable format: html, pdf or doc

if ~exist('format', 'var'); format = 'html'; end
outputdir = fullfile(arcaderoot, 'arcade', 'Docs', format);

cfg = ArcadeConfig;
cfg.ControlScreen = '';
cfg.EyeServer = 'EyeLinkServer.exe';
procs = launch_processes(cfg);
c = onCleanup(@cleanup);

docDirectory = fileparts(mfilename('fullpath'));

docFiles = dir(fullfile(docDirectory, 'DOC*.m'));

for iFile = 1:length(docFiles)
    publish(fullfile(docDirectory, docFiles(iFile).name), ...
        'format', format, 'outputDir', outputdir, 'evalCode', true);
end

doc arcade

end


function cleanup()
StimServer.delete
EyeServer.delete
end
