@Echo OFF
SETLOCAL
:: 64-bit version of matlab 2014a
SET ARCADEDIR="%~dp0"\Core\

if not exist %~dp0..\errorLog ( 
	mkdir %~dp0..\errorLog  
	) 

if not exist %~dp0..\sessionLog ( 
	mkdir %~dp0..\sessionLog  
	) 


rem get timestamp for logfile
for /f "tokens=2 delims==" %%a in ('wmic OS Get localdatetime /value') do set "dt=%%a"
set "YY=%dt:~2,2%" & set "YYYY=%dt:~0,4%" & set "MM=%dt:~4,2%" & set "DD=%dt:~6,2%"
set "HH=%dt:~8,2%" & set "Min=%dt:~10,2%" & set "Sec=%dt:~12,2%" & set "MS=%dt:~15,3%"
set "datestamp=%YYYY%%MM%%DD%" & set "timestamp=%HH%%Min%%Sec%" 
set logfile=%~dp0..\errorLog\log_core_%datestamp%_%timestamp%.txt

cd %ARCADEDIR%

IF [%1]==[] ( 
	SET RUNCMD=matlab -nodesktop -logfile %logfile% -r "runCore()" 
	) ELSE IF [%1]==[/DEBUG] ( 
	SET RUNCMD=matlab -r "dbstop if error; runCore" 
	) ELSE ( SET RUNCMD=matlab -nodesktop -logfile %logfile% -r "runCore('%~1')"  )

echo %RUNCMD%
%RUNCMD%
