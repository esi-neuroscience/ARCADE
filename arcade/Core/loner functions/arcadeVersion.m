function version = arcadeVersion
gitCMD = '"C:\Program Files\Git\bin\git.exe"';
[result, version] =  system([gitCMD ' -C ' arcaderoot ' describe']);
if ~result == 0
	warning('Could not find git.exe')
	version = 'unknown';
end
