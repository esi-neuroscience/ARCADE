function version = arcadeVersion
releaseVersion = '2.6';
gitCMD = 'git.exe';
[result, version] =  system([gitCMD ' -C ' arcaderoot ' describe']);
if ~result == 0
	version = [releaseVersion, ' (zip-release)'];
else
	version = [strrep(version, char(10), ''), ' (git)'];
end
