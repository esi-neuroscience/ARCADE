function prepare_docs(format)
% Convert documentation into readable format: html, pdf or doc

if ~exist('format', 'var'); format = 'html'; end

docDirectory = fileparts(mfilename('fullpath'));

docFiles = dir(fullfile(docDirectory, 'DOC*.m'));

for iFile = 1:length(docFiles)
    publish(fullfile(docDirectory, docFiles(iFile).name), format)
end