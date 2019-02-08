@ECHO OFF
SETLOCAL

SET ControlScreenDir=%~dp0
SET CfgPath=%1
TITLE ControlScreen
SET matlabCmd="cd %ControlScreenDir%; dbstop if error; runControlScreen(%CfgPath%)"
START "" /MIN /B matlab -automation -logfile test.log -wait -r %matlabCmd%