function reward(rMode,varargin)
% Give a reward pulse or pulse sequence.
% 
% INPUT
% -----
% 
%   rMode : reward mode, 'pulse' or 'sequence'.
%   
% 

% pulse ms    = varargin{1} 
% sequence ms = varargin{2} 

% reward 
%t = tic;
rewServer = SGLRewardServer.launch; % 0.000041
%toc(t)

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

