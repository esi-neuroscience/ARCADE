@Echo OFF
SETLOCAL
:: 32-bit version of matlab 2014a
PATH "C:\Program Files (x86)\MATLAB\R2014a\bin\"
SET DISPLAYDIR="%~dp0"\ProcessLaunch\
SET RUNCMD=matlab -nodesktop -r "dbstop if error ; run('%DISPLAYDIR%runCore.m')";
%RUNCMD%