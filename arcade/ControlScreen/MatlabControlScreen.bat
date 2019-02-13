@ECHO OFF
SETLOCAL

SET ControlScreenDir=%~dp0
SET CfgPath=%1
TITLE ControlScreen

rem get timestamp for logfile
for /f "tokens=2 delims==" %%a in ('wmic OS Get localdatetime /value') do set "dt=%%a"
set "YY=%dt:~2,2%" & set "YYYY=%dt:~0,4%" & set "MM=%dt:~4,2%" & set "DD=%dt:~6,2%"
set "HH=%dt:~8,2%" & set "Min=%dt:~10,2%" & set "Sec=%dt:~12,2%" & set "MS=%dt:~15,3%"
set "datestamp=%YYYY%%MM%%DD%" & set "timestamp=%HH%%Min%%Sec%" 
set logfile=%~dp0..\..\errorLog\log_controlscreen_%datestamp%_%timestamp%.txt

SET matlabCmd="cd %ControlScreenDir%; dbstop if error; runControlScreen(%CfgPath%)"
START "" /MIN /B matlab -automation -logfile %logfile% -wait -r %matlabCmd%