%% Behavioral data
% ARCADE stores a record of the subject's behavior during a session in 
% subfolders of |ARCADE\sessionLog|. Each session will be stored in the
% folder named |ARCADE\sessionLog\subject\experiment\session| with
% |subject|, |experiment| and |session| as defined during configuration of
% the experiment.
% 
% ARCADE will create multiple files in the subfolder |Behaviour| of the
% session folder all named with the pattern
% |subject_experiment_session.ext|
% 
% After a successful session there will be 4 files:
% 
% * |.mat| : MATLAB file containing information about all trials. This file
%            is only created after a completed session.
% * |.esi| and |.hdr| : binary files containing the same behavioral record
% as the |.mat| file. These files are continouously updated during the
% session and are always written.  
% * |.evt| : binary file with event timestamps and codes. The timestamps
% are in microseconds and relative to the initialization of the experiment.
% Events are written to disk during the inter-trial interval.
% 
% *Example*
% 
% Contents of |ARCADE\sessionLog\hugo_20170523_petalStep2-3c_12\Behaviour| after
% session 12 with monkey hugo running the petalStep2-3c task on the 23 May 2017:
% 
% 
% * hugo_20170523_petalStep2-3c_12.esi
% * hugo_20170523_petalStep2-3c_12.hdr
% * hugo_20170523_petalStep2-3c_12.mat
% * hugo_20170523_petalStep2-3c_12.evt
% 
% 
%% 
% To read the events from the |.evt| file into MATLAB, use |readEvtFile|
help readEvtFile
%%
% If a session could not be completed successfully the |.esi| and |.hdr|
% files can be converted to a MATLAB file with |convertEsiFile|.

%% 
% *User-defined variables*
% 
% Arbitrary variables for user data can be stored using storeUserVariables
help storeUserVariables

