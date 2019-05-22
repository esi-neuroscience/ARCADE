function version = arcadeVersion
gitCMD = 'git.exe';
[result, version] =  system([gitCMD ' -C ' arcaderoot ' describe']);
if ~result == 0
% 	warning('Could not find git.exe')
	version = 'unknown (could not find git.exe)';
end
version = strrep(version, char(10), '');