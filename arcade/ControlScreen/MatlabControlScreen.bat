@ECHO OFF
SETLOCAL

SET ControlScreenDir=%~dp0
SET CfgPath=%1

SET matlabCmd="cd %ControlScreenDir%; runControlScreen(%CfgPath%)"
ECHO matlabCmd
START /MIN matlab -wait -r %matlabCmd%