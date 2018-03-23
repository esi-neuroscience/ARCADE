@Echo OFF
SETLOCAL
:: 64-bit version of matlab 2014a
SET PATH="C:\Program Files\MATLAB\R2014a\bin\";"C:\Program Files\MATLAB\R2014a\bin\win64";C:\Windows\system32;C:\Windows;%~dp0\..\..\StimServer\;%~dp0\..\..\External\EyelinkToolbox"
SET HANDMAPDIR="%~dp0"\..\..
if "%1"=="" (
	SET SCREENDIST=""
	) else (
	SET SCREENDIST=%1
	)
TITLE "Hand Receptive Field Mapper"
echo "Starting RFHandmapper"
SET RUNCMD=matlab -nodesktop -minimize -wait -r "restoredefaultpath(); cd %HANDMAPDIR%; addpath(genpath(pwd)); RFhandmapper('%SCREENDIST%'); exit";
start /min %RUNCMD%

