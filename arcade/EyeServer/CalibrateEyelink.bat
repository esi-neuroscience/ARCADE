@Echo OFF
SETLOCAL
:: 64-bit version of matlab 2014a
SET PATH="C:\Program Files\MATLAB\R2014a\bin\";"C:\Program Files\MATLAB\R2014a\bin\win64";C:\Windows\system32;C:\Windows;%~dp0\..\StimServer\;%~dp0\..\External\EyelinkToolbox"
SET EYESERVERDIR="%~dp0"\..
TITLE "Calibrate Eyelink"
echo "Starting eye calibration for Eyelink"
SET RUNCMD=matlab -nodesktop -minimize -wait -r "restoredefaultpath(); cd %EYESERVERDIR%; addpath(genpath(pwd)); CalibrateEyelink; exit";
start /min %RUNCMD%

