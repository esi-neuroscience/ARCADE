@Echo OFF
SETLOCAL
:: 64-bit version of matlab 2014a
PATH "C:\Program Files\MATLAB\R2014a\bin\"
SET DISPLAYDIR="%~dp0"\ProcessLaunch\

IF "%~1"=="/DEBUG" (
	SET RUNCMD=matlab -r "dbstop if error; run('%DISPLAYDIR%runCore.m')";
) ELSE (
	SET RUNCMD=matlab -nodesktop -r "run('%DISPLAYDIR%runCore.m')"
)

%RUNCMD%