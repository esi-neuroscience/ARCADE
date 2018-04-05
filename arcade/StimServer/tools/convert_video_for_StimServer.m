function convert_video_for_StimServer(filename, iFrame)
% CONVERT_VIDEO_FOR_STIMSERVER - Convert a movie file to an uncompressed
% TIFF image sequence for presentation with StimServer
%
%   convert_video_for_StimServer({filename, [firstFrame lastFrame]})
%   
% The TIFF file is written to the same folder as the original file using
% the original filename with a tiff extension.
%  
% INPUT (all optional)
% ---------------------
%                    filename : filename of compressed movie file 
%      [firstFrame lastFrame] : range of frames to be included in output

%%
if ~exist('filename', 'var')
    [file,folder,~] = uigetfile(...
    {'*.avi;*.AVI;*.mov;*.MOV;*.mkv;*.MKV;*.mp4;*.MP4;*.wmv;*.WMV;*.mpg;*.MPG;', 'All Movie Files'; ...
        '*.*', 'All Files'});
    filename = fullfile(folder, file);
    if file == 0; return; end        
end
    
[folder, file, ~] = fileparts(filename);
vr = VideoReader(filename);

fprintf('Read %d frames from %s\n', vr.NumberOfFrames, filename)
if ~exist('iFrame', 'var')
    frames = read(vr);
else
    frames = read(vr, iFrame);
end
nFrames = size(frames,4);
tiffName = fullfile(folder, [file '.tiff']);

fprintf('Writing %d frames to %s\n',  nFrames, tiffName)

fprintf('%5d', 1)
imwrite(frames(:,:,:,1), tiffName, 'tiff')
for iFrame = 2:nFrames
    fprintf('\b\b\b\b\b%5d', iFrame)
    imwrite(frames(:,:,:,iFrame), tiffName, 'tiff', 'WriteMode', 'append')    
end
fprintf('\b\b\b\b\b\n')
filesize = dir(tiffName);
fprintf('Total file size: %.1f MB\n',  filesize.bytes/1024/1024);