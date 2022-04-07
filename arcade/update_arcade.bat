@Echo OFF

git pull --all 2>NULL

if %ERRORLEVEL% neq 0 goto gitError

@rem If git is available pull from repo and wait for button press then exit w/return 0
pause
exit /b 0

:gitError
@rem if git is not available point user to GH releases page
ECHO It seems git is not installed. Please update ARCADE manually by downloading a newer version from https://github.com/esi-neuroscience/ARCADE/releases
