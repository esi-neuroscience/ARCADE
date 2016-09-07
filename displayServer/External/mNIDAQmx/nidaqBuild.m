

% original header path
%hdrpath   = 'C:\Program Files (x86)\National Instruments\NI-DAQ\DAQmx ANSI C Dev\include\';

% use this .h file 
% typedef uInt32 TaskHandle; // Line 91: changed to uInt32 from void*



%hdrpath = 'S:\Michael_Stephan\Projects\displayServer\inDevelopment\NIDAQ\';
%cd(hdrpath); % make protofile here
cd(fileparts(mfilename));

if strcmp(computer,'PCWIN') % 32-bit 
    % (Windows 32-bit on Windows 64-bit)
    libPath = 'C:\Windows\SysWOW64\';
    [notfound,warnings] = loadlibrary([libPath,'nicaiu.dll'],[hdrpath,'NIDAQmx.h'],'mfilename','mNIDAQmx');
elseif strcmp(computer,'PCWIN64') % 64-bit
    libPath = 'C:\Windows\System32\';
    [notfound,warnings] = loadlibrary([libPath,'nicaiu.dll'],[hdrpath,'NIDAQmx.h'],'mfilename','mNIDAQmx64');
end



