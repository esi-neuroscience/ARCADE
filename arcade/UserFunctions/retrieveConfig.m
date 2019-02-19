function cfg = retrieveConfig
%RETRIEVECONFIG Retreive ArcadeConfig of current session
%
% This function can be used to extract information about the current session
% at session runtime, e.g. the name of the subject.
%
% USAGE
% -----
%
%	 cfg = retreiveConfig()
%
%
% EXAMPLE
% -------
%	cfg = retreiveConfig()	
%	if strcmp(cfg.Subject, 'monkeyK')
%		rewardDuration = 90;
%	end
%
% See also ArcadeConfig

BHVstore = SGLBehaviouralStore.launch;   % behavioural store (for CFG)
cfg = BHVstore.cfg;

end


