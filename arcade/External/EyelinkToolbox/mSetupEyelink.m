



% 1. Init EyeLink
% 2. set output to Raw
% 3. flip Y
% 4. set Gain to [-10 10]

% TO DO:
% implement a GUI to specify EDF file name 

function mSetupEyelink(task, varargin)
persistent g el flags

% el    - eytelink structure
% g     - input parameter structure
% flags - flags that control state flow

% always parse the inputs into a structure g
g = parseVarArgin(varargin,g);

%------------------------------%
%   start Eyelink Connection
%------------------------------%
if task == 1
    
% init persistents
g = [];
flags.edfStart = 0; 
    
%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%   initialize paramters
%%%%%%%%%%%%%%%%%%%%%%%%%%%%


% make sure these are correct
dist2topScreen   = 90;
dist2bottomScreen = 90;
dist2screen      = 89;
camer2eyeDist    = 73;

% get screen size
% screenSize = get(0,'ScreenSize');
% get the current px screen size using Matlab
g.sWidth  = 1680;
g.sHeight = 1050;
sWidth  = g.sWidth;
sHeight = g.sHeight;
% dac card range
dacRange = [-5,5];

% physical size of the screen
physScreenSize = [476.76 296.1];

% recording sample rate
rsRate = 500;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%      initiate eyelink
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
if Eyelink('initialize') ~= 0,
    fprintf('Problem initializing Eyelink\n');
    return;
end;

% return the el struct, it contains some useful information
% it does not poll E|yelink, it just sets some values and polls for
% platform specific values
el = EyelinkInitDefaults([]);

% el=EyelinkInitDefaults(window);
% 
% el.backgroundcolour = BlackIndex(el.window);
% el.msgfontcolour    = WhiteIndex(el.window);
% el.imgtitlecolour = WhiteIndex(el.window);
% el.targetbeep = 0;
% el.calibrationtargetcolour= WhiteIndex(el.window);
% el.calibrationtargetsize= 1;
% el.calibrationtargetwidth=0.5;
% el.displayCalResults = 1;
% el.eyeimgsize=50;
% EyelinkUpdateDefaults(el);



%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%      settings in Eyelink
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%
%      analog.ini
%%%%%%%%%%%%%%%%%%%%%%%%%%
Eyelink('command','analog_binocular_mapping = monocular');
Eyelink('command','analog_out_data_type = GAZE');
%Eyelink('command','analog_out_data_type = RAW'); % for initial training
Eyelink('command','analog_dac_range = %d,%d', dacRange(1), dacRange(2)); % set DAC card range

%%%%%%%%%%%%%%%%%%%%%%%%%%
%      parser.ini
%%%%%%%%%%%%%%%%%%%%%%%%%%
% set saccade sensitivity
Eyelink('command','select_parser_configuration = 1');
Eyelink('command','recording_parse_type = GAZE');

% set parser (conservative saccade thresholds)
Eyelink('command','saccade_velocity_threshold = 22');
Eyelink('command','saccade_acceleration_threshold = 5000');
Eyelink('command','saccade_motion_threshold = 0');
%Eyelink('command','fast_velocity_filter = YES');

%%%%%%%%%%%%%%%%%%%%%%%%%%
%      .ini
%%%%%%%%%%%%%%%%%%%%%%%%%%

% flip the y or x anolog range
Eyelink('command','analog_x_range = GAZE, 0.0, 1.0'); % ? don't know if it works
%Eyelink('command','analog_x_range = GAZE, 1.2, -0.2');

% get binocular sampling going, and set left eye to be tracked
Eyelink('command','binocular_enabled = NO');
%Eyelink('command','active_eye = LEFT');
Eyelink('command','active_eye = RIGHT');
% Eyelink('Command', 'current_camera = LEFT'); % sets camera to Left Eye
% Eyelink('Command', 'current_camera = RIGHT'); % sets camera to Right Eye

% what to output if the pupil is not visible
%Eyelink('command','analog_non_pupil_value = 0.0');

Eyelink('command','rec_plot_data = ANALOG');
%Eyelink('command','rec_plot_data = RAW');
%Eyelink('command','rec_plot_data = GAZE'); % recording data view

% % set EDF file contents
% Eyelink('command',  'file_event_data = GAZE,AREA,HREF,VELOCITY');                   % data for events written to edf
% Eyelink('command','file_event_filter = LEFT,RIGHT,FIXATION,SACCADE,BLINK,MESSAGE'); % type of events written to edf
% Eyelink('command', 'file_sample_data = LEFT,RIGHT,GAZE,HREF,AREA,STATUS');          % sample data written to edf
% 
% % set link data (used for gaze cursor)
% Eyelink('command','link_event_filter = LEFT,RIGHT,FIXATION,SACCADE,BLINK,MESSAGE'); % types of events going over the tcp/ip link
% Eyelink('command', 'link_sample_data = LEFT,RIGHT,GAZE,AREA,STATUS');               % sample data going over the link
% Eyelink('command', 'link_event_data  = GAZE,HREF,AREA,VELOCITY,STATUS');            % data in events going over the link

% do not need EVENTS, want HREF in EDF, convert this to degrees 

% GAZERES 
% remove status 
% set EDF file contents
Eyelink('command', 'file_event_data = GAZE,GAZERES,AREA');                        % data for events written to edf
Eyelink('command', 'file_event_filter = LEFT,RIGHT,FIXATION,SACCADE,BLINK,MESSAGE');                        % type of events written to edf
Eyelink('command', 'file_sample_data = LEFT,RIGHT,GAZE,GAZERES,HREF,AREA');                      % sample data written to edf

% set link data (used for gaze cursor)
Eyelink('command', 'link_event_filter = LEFT,RIGHT,MESSAGE');                        % types of events going over the tcp/ip link
Eyelink('command', 'link_sample_data = LEFT,RIGHT,GAZE,AREA,STATUS');               % sample data going over the link
Eyelink('command', 'link_event_data  = GAZE,AREA,VELOCITY,STATUS');            % data in events going over the link
%Eyelink('command', 'link_event_data  = GAZE,AREA,STATUS');            % data in events going over the link

% Link/Analog Filter, Can always filter the data after

% set pupil Tracking model in camera setup screen
% no = centroid. yes = ellipse
%Eyelink('command', 'use_ellipse_fitter = no');
% set sample rate in camera setup screen
Eyelink('command', 'sample_rate = %d', rsRate);

%%%%%%%%%%%%%%%%%%%%%%%%%%%
%    calibration stuff 
%%%%%%%%%%%%%%%%%%%%%%%%%%%
% eye calibration, general setup
Eyelink('command','calibration_type = HV9');
Eyelink('command','enable_automatic_calibration = NO');

% you must send this command with value NO for custom calibration
% you must also reset it to YES for subsequent experiments
Eyelink('command', 'generate_default_targets = YES'); % NO if you want custom points

Eyelink('command','randomize_calibration_order = YES'); % NO
Eyelink('command','randomize_validation_order = YES'); % NO

Eyelink('command','cal_repeat_first_target = YES'); % repeat fixation
Eyelink('command','val_repeat_first_target = YES');

%-------------------------%

% set the participant distance from screen, convert to mm
Eyelink('command','screen_distance = %d,%d', dist2topScreen*10,dist2bottomScreen*10); %mm
Eyelink('command','camera_to_eye_distance = %d', camer2eyeDist*10); %mm

% Used to compute correct visual angles and velocities when head tracking not used.
% simulation_screen_distance = <mm>
Eyelink('command','simulation_screen_distance = %d', dist2screen*10); %mm

% set the physical size of the screen
phySc = round(physScreenSize./2.0);
phySc = [phySc phySc] .*[-1 1 1 -1];
% passed to Eyelink [-x y x -y], this is the physical size of the monitor
Eyelink('command','screen_phys_coords = %d %d %d %d',phySc(1),phySc(2),phySc(3),phySc(4));

Eyelink('command','screen_pixel_coords = %d %d %d %d', 0.0, 0.0, g.sWidth, g.sHeight);

%-------------------------%

% query tracker for mount type using elcl_select_configuration variable
[~,reply]=Eyelink('ReadFromTracker','elcl_select_configuration');
% check to make sure we are in the right config mode
% we want Long Range Monocular = MLRR
if ~strcmp('MLRR',reply)
    % set to the right configuration mode
    Eyelink('command','elcl_select_configuration MLRR');
end

%-------------------------%
Eyelink( 'StartSetup' ); % set to Camera Setup screen

% make sure we're still connected
if Eyelink('IsConnected')~=1
    warndlg('EyeLink is not connected');
    %return;
end;

return;

%------------------------------%
%      init EDF name
%------------------------------%
elseif task==2
    % set edf file name 
    % get filename from BHV filepath
    % path, name, ext = fileparts()
    if ~isfield(g,'filePath')
        g.filePath = ['C:\behavioralData\', datestr(now,29),'\eyeData.edf']; 
    end
 
    [g.dirEDF,fName,~] = fileparts(g.filePath);
    
    % set the default 
    
    % Eyelink will only allow file names up to 8 chars
    % example: MMDDYYTN
    % T = task
    % N = number that day
    % edfFile ='052112F1.edf';
    if length(fName)<=8
        g.edfFile = [fName,'.edf']; 
    else
        %g.edfFile = [fName(end-7:end),'.edf'];
        % take first eight characters 
        g.edfFile = [fName(1:8),'.edf']; 
    end
    % check just to make sure 
    if length(g.edfFile)>8+4, error('EDF file name too long'); end
    return; 
    
%------------------------------%
%   start EyeLink Recording 
%------------------------------%   
elseif task==3
    % start recording 
    mode=Eyelink('CurrentMode');
    if (el.IN_RECORD_MODE ~= mode)
        % open file to record data
        i = Eyelink('Openfile', g.edfFile);
        if i~=0
            warndlg('EyeLink can not open edf file');
            %Eyelink( 'Shutdown');
            return;
        end
        % set recording flag
        flags.edfStart = 1; 

        % start recording eye position (preceded by a short pause so that
        % the tracker can finish the mode transition)
        % The paramerters for the 'StartRecording' call controls the
        % file_samples, file_events, link_samples, link_events availability
        Eyelink('Command', 'set_idle_mode');
        WaitSecs(0.05);
        Eyelink('StartRecording', 1, 1, 1, 1);
        WaitSecs(0.1); % wait a 100ms to guarantee some data before the first event
    else
       warndlg('Already recording...');
    end
    return;
    
 
%------------------------------%
%   stop EyeLink Recording 
%------------------------------%    
    
elseif task==4
    % stop recording
    
    %mode=Eyelink('CurrentMode');
    %if (el.IN_RECORD_MODE == mode) % in practice this does not seem to
    %work
    
    if ~isempty(flags.edfStart)
        if (flags.edfStart == 1)
            % stop recording and close eyelink
            % could use: Eyelink('checkrecording')
            % -1 = not recording
            %  0 = recording
            
            Eyelink('message', 'RecordEnd');
            WaitSecs(0.5)
            Eyelink('stoprecording');
            Eyelink('CloseFile');
            
			[~,fName,~] = fileparts(g.filePath);
			
            % get file from eyelink computer
            cd(g.dirEDF)
            try
                fprintf('Receiving data file ''%s''\n', g.edfFile );
                status=Eyelink('ReceiveFile');
                if status > 0
                    fprintf('ReceiveFile status %d\n', status);
                end
				movedFilename = fullfile(g.dirEDF, [fName '.edf']);
				movefile(g.edfFile, movedFilename);
				if 2==exist(movedFilename, 'file')
					fprintf('Data file can be found in ''%s''\n', movedFilename);
				end
                
            catch
                warndlg('Problem receiving data file');
            end
            
        end
        return;
    end
end


end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%              secondary functions
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% parse the input and store it in a struct
function out_g = parseVarArgin(argsin, in_g)

% init return
out_g = in_g;
%g = varargin;
numvarin = length(argsin);

% a very strict way of error handling, unless no inputs
if mod(numvarin,2)
    if numvarin>0
        error('Mismatch between number input values and fields');
    else
        return;
    end
end

% add/modifty fields in return structure
if numvarin>0
    for in = 1:2:numvarin
        out_g.(argsin{in}) = argsin{in+1};
    end
end

end
%[result, reply] = Eyelink('ReadFromTracker', 'analog_x_range')
%[result, reply] = Eyelink('ReadFromTracker','analog_non_pupil_value = 0.0')








