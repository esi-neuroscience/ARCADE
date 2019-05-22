@Echo OFF
SETLOCAL

SET EYESERVERDIR="%~dp0"

if "%1"=="" (
	SET EYESERVER="BinaryEyelink"
	) else (
	SET EYESERVER="%1"
	)
TITLE "EyeServer"
echo Running %EYESERVER% EyeServer
if %EYESERVER%=="BinaryEyelink" (
	SET RUNCMD="%~dp0"\EyelinkServer.exe
	) else (
	echo Unknown EyeServer
	pause
	exit /b 2
	)
%RUNCMD%

