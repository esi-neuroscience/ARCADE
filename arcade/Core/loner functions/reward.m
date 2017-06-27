function reward(rMode,varargin)
% REWARD - Give a reward pulse or pulse sequence.
% 
% INPUT
% -----
% 
%   rMode : reward mode, 'pulse' or 'sequence'.
%   duration : length of reward pulse(s) in ms
%   pause    : pause after each pulse for 'sequence' mode
% 
% EXAMPLE
% -------
% Give 100 ms reward pulse
%   reward('pulse', 100)  
% 
% Give 2x50 ms pulse with a pause of 40 ms after each pulse
%   reward('sequence', [100 100], [40 40]) 
% 
% 

rewServer = SGLRewardServer.launch; % 0.000041

switch rMode
    case 'pulse'
        %t = tic;
        rewServer.mRewardPulse(varargin{1});
        %disp(['Reward Time: ',int2str(toc(t)*1000)]);
    case 'sequence'
        %[50,Reward],[rewPause,0]
        %t = tic;
        rewServer.mRewardSequence(varargin{1},varargin{2});
        %disp(['Reward Time: ',int2str(toc(t)*1000)]);
    otherwise
        % not known
        rewServer.mRewardPulse(varargin{1});
end


end

