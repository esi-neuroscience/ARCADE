@Echo OFF
SETLOCAL
:: 64-bit version of matlab 2014a

SET EYESERVERDIR="%~dp0"

echo %PATH%

if "%1"=="" (
	SET EYESERVER="Test"
	) else (
	SET EYESERVER="%1"
	)
TITLE "EyeServer"
echo Running %EYESERVER% EyeServer
if %EYESERVER%=="BinaryEyelink" (
	SET RUNCMD="%~dp0"\EyelinkServer.exe
	) else (
	SET RUNCMD=matlab -nodesktop -nosplash -minimize -wait -r "cd %EYESERVERDIR%; addpath(genpath(pwd)); runEyeServer('%EYESERVER%')";
	)
%RUNCMD%

