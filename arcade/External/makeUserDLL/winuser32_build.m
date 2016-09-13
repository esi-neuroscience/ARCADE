
close all
clear all
clc

cd(fileparts(mfilename('fullpath')));

%{
%unloadlibrary('user32')
hdrpath2 = 'C:\Program Files (x86)\MATLAB\R2014a\sys\lcc\include\';
%hdrpath2 = 'C:\Program Files\MATLAB\R2014a\sys\lcc64\lcc64\include64\';


libPath = 'C:\Windows\SysWOW64\';
[notfound,warnings] = loadlibrary([libPath,'user32.dll'],...
    [hdrpath2,'win.h'],...          
    'addheader','WinUserXtra.h',... % win.h
    'addheader',[hdrpath2,'stdarg.h'],...
    'addheader',[hdrpath2,'limits.h'],... % some type defs
    'mfilename','win_user32');

%libPath = 'C:\Windows\SysWOW64\';
%[notfound,warnings] = loadlibrary([libPath,'nicaiu.dll'],[hdrpath,'NIDAQmx.h'],'mfilename','mNIDAQmx');
%}

% need visual studio

%includepath = '-I.\Include';

eval('mex -v -largeArrayDims -I.\Include EnumerateDisplays.c');















