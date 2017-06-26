@Echo OFF
SETLOCAL
:: 64-bit version of matlab 2014a
SET PATH="C:\Program Files\MATLAB\R2014a\bin\";"C:\Program Files\MATLAB\R2014a\bin\win64";C:\Windows\system32;C:\Windows;%~dp0\..\StimServer\;%~dp0\..\External\EyelinkToolbox"
SET EYESERVERDIR="%~dp0"\

if "%1"=="" (
	SET EYESERVER="Test"
	) else (
	SET EYESERVER="%1"
	)


SET RUNCMD=matlab -automation -r "addpath %EYESERVERDIR%; runEyeServer('%EYESERVER%')";



%RUNCMD%
