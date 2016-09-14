








close all
clear all
clc

%eval(['mex -v -largeArrayDims hat.c']);



% 
% /* retrieves the frequency of the high-resolution performance counter */
% QueryPerformanceFrequency( &frequency );
% sec_per_tick = ( double )1 / ( double )frequency.QuadPart;
% 
% /* retrieves the current value of the high-resolution performance counter */
% QueryPerformanceCounter( &counter );
% total_ticks = ( double )counter.QuadPart;
% 
% /* time in seconds */
% *hTimePtr = sec_per_tick * total_ticks;


addpath('H:\projects\DisplayServer_tasks\DisplayServer\Version_beta\ServerClient');

if ~libisloaded('kernel32'); loadlibrary('kernel32', @win_kernel32); end;

tick_freq = int64(0);
total_ticks = int64(0);

[result1,tick_freq]   = calllib('kernel32', 'QueryPerformanceFrequency', tick_freq);
[result2,total_ticks] = calllib('kernel32', 'QueryPerformanceCounter', total_ticks);

timeStamp = (1/double(tick_freq) * double(total_ticks))/3600 ;















