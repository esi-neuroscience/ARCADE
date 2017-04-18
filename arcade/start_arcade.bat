@Echo OFF
SETLOCAL
:: 64-bit version of matlab 2014a
SET PATH=%PATH%;"C:\Program Files\MATLAB\R2014a\bin\"
echo PATH
SET DISPLAYDIR="%~dp0"\ProcessLaunch\

IF "%~1"=="/DEBUG" (
	SET RUNCMD=matlab -r "dbstop if error; run('%DISPLAYDIR%runCore.m')";
) ELSE (
	SET RUNCMD=matlab -nodesktop -nosplash -r "run('%DISPLAYDIR%runCore.m')"
)

%RUNCMD%