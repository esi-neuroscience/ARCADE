@Echo OFF
SETLOCAL
SET EYESERVERDIR="%~dp0"\..
TITLE Calibrate Eyelink
echo Starting eye calibration for Eyelink...
SET RUNCMD=matlab -automation -wait -r "restoredefaultpath(); cd %EYESERVERDIR%; addpath(genpath(pwd)); CalibrateEyelink; exit";
start /min /b /wait %RUNCMD%

