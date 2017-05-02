@Echo OFF
SETLOCAL
:: 64-bit version of matlab 2014a
SET PATH="C:\Program Files\MATLAB\R2014a\bin\";"C:\Program Files\MATLAB\R2014a\bin\win64";C:\Windows\system32;C:\Windows;%~dp0StimServer\;%~dp0External\EyelinkToolbox"
SET ARCADEDIR="%~dp0"\ProcessLaunch\

IF "%~1"=="/DEBUG" (
	SET RUNCMD=matlab -r "dbstop if error; run('%ARCADEDIR%runCore.m')";
) ELSE (
	SET RUNCMD=matlab -nodesktop -r "run('%ARCADEDIR%runCore.m')"
)

%RUNCMD%
