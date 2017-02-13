

% original header path
%hdrpath   = 'C:\Program Files (x86)\National Instruments\NI-DAQ\DAQmx ANSI C Dev\include\';

% use this .h file 
% typedef uInt32 TaskHandle; // Line 91: changed to uInt32 from void*


folder = fileparts(mfilename('fullpath'))
cd(folder);

if strcmp(computer,'PCWIN') % 32-bit 
    % (Windows 32-bit on Windows 64-bit)
    libPath = 'C:\Windows\SysWOW64\';
    protoFile = fullfile(folder, 'mNIDAQmx');
elseif strcmp(computer,'PCWIN64') % 64-bit
    libPath = 'C:\Windows\System32\';
    protoFile = fullfile(folder, 'mNIDAQmx64');
end


[notfound,warnings] = loadlibrary(fullfile(libPath,'nicaiu.dll'), ...
    fullfile(folder,'NIDAQmx.h'), ...
    'mfilename', protoFile);

