@Echo OFF
SET EDITORDIR="%~dp0"
SET RUNCMD=matlab -r "EditableVariableEditor" 

echo %RUNCMD%
%RUNCMD%
