# Change Log of ARCADE

## Unreleased
## NEW
*  StimServer v1.4.2.3:  The deferred mode (`groupStimuli`) can now be canceled 
   by using new cancel command or the `StimServerEndDeferredMode` event.
*  EyeLinkServer v1.2.3.0: Support to receive samples for speed up, 
   support for `EndDeferredMode` events
*  The new add-on `EditableVariableEditor` contributed by Yufeng Zhang can be
   used to edit the editable variables in an existing configuration file (`*_cfg.mat`)


## [2.5.7] - 2020-04-07
## CHANGED
*  StimServer v1.4.2.1: The window size of the StimServer stimulus screen in
   windowed mode is now 800x600 pixels. This prevents accidental switches to 
   go unnoticed. Timing and performance in windowed mode are not reliable.

## FIXED
*   A bug process synchronization could prevent successful startup of ARCADE


## [2.5.6] - 2020-03-02
## NEW
*   StimServer v1.4.2.0: support for Gamma correction
*   measure_screen_gamma.m: new script for measuring the screen gamma value

## CHANGED
*   EyeLinkServer 1.2.0.0: In and Out events are now mutually exclusive


## [2.5.5] - 2019-12-10
## NEW
*   StimServer v1.4.1.1: the Wedge stimulus can now be rotated via
    a LinearRange animation.
*   NidaqServer v1.0.17.1: added support for PCIe-6351

## [2.5.4] - 2019-11-08
## NEW
*   StimServer v1.4.1.0:
        - New Wedge stimulus
        - Photodiode position can be set in Windows registry
*   EyelinkServer v1.1.7.0: new 'Message' command for message to be stored
    in EDF data file.

### FIXED
*   No timeout error in runControlScreen for connecting to the Core process.

## [2.5.3] - 2019-06-14
### FIXED
*   StimServer v1.3.1.6: The LinearMotion animation could sometimes fully reach
    the very final position. The MovingBar stimulus was also affected.
*   EyeLinkServer v1.1.6.2: If the Eyelink system was offline at EyeLinkServer
    startup, connecting to the Eyelink system via the GUI menu  did not work.
    This was fixed.
*   CalibrateEyelink: The startup of the StimServer and NidaqServer processes
    could sometimes fail. This is fixed by switching to the new `launch_processes`
    function for startup.

## [2.5.2] - 2019-06-12
### FIXED
*   Using MATLAB 2014a with ARCADE 2.5.0-2.5.1, sessions were not terminated
    properly such that the eye data was not received from Eyelink and the
    behavioral data file was not closed. The error did not occur with MATLAB
    2018b.

### CHANGED
*   EyeLinkServer v.1.1.6.1: speedup of start recording


## [2.5.1] - 2019-06-07
### NEW
*   EyeLinkServer v1.1.6.0: When both eyes are tracked, the eye used for
    monitoring regions can be selected from the EyeLinkServer GUI. If only one
    eye is tracked, the selected eye is displayed.

### FIXED
*   EyeLinkServer v1.1.6.0: For binocular tracking, the current position was
    sometimes switching between the two eyes at runtime, causing small eye
    position jumps. This was fixed.


## [2.5.0] - 2019-05-23
### NEW
*   ARCADE sends a [0 1 0] eventmarker sequence at beginning and and of a
    session. This can be used to synchronize different recording systems, e.g.
    Eyelink and TDT Sys3.

## [2.5.0b3] - 2019-05-17
### NEW
*   NidaqServer v1.0.10.6: support for PCIe-6323
*   For testing a task script, the `simulate_trial` function will create all
    editable variables from a _cfg.mat file in the MATLAB workspace as well as
    a valid TrialData struct.

### FIXED
*   In configuration MainScreen, the starting folder was not the ARCADE\Tasks
    folder.
*   CalibrateEyelink:
        - The last position of the Eyelink calibration and the first position
          of a validation sequence was not rewarded.
        - The CalibrateEyelink sets the screen_pixel_coords variable of
          Eyelink to [-w/2 h/2-1 w/2-1 -h/2] with w and h being screen width
          and height, respectively. It is recommended to the same in the
          final.ini file on the Eyelink PC.

## [2.5.0b2] - 2019-04-01
### NEW
*   EyeLinkServer v1.1.3.1: 
        - Support for mixed-term biquadratatic transformations
        - Support vor overlapping targets
### FIXED
*   NidaqServer v1.0.10.4: error in support for PCIe-6321


## [2.5.0b1] - 2019-03-13
### NEW
*   All modules of ARCADE (EyeServer, DaqServer, StimServer, ControlScreen)
    can now be enabled or disabled in the configuration (see ArcadeConfig).
    The function arcade/Core/launch_processes handles their startup based on
    the configuration and connects to the respective communication pipes.
*   The configuration used for a particular session is now saved together with
    the behavioral data in the corresponding sessionLog folder.
*   ARCADE can now be started with the path to a _cfg.mat file as an input
    argument skipping the MainScreen GUI for configuration. This makes it
    possible to start a task for a subject via a shortcut that calls
    start_arcade.bat <pathToCfg>
*   Square wave grating with anti-aliased bands and circular mask
*   StimServer v1.3.1.3:
        - anti-aliased Ellipse and Rectangle stimuli with support for outlines
        - support for swapping stimuli (drawing order)
*   The new binary EyeLinkServer replaces the TestEyeServer and
    EyelinkEyeServer. This adds several new features:
        - A separate GUI for displaying the current eye position and the
          monitored screen locations
        - Speed: the EyeLinkServer can monitor many screen locations (~100)
        - Simulation mode: When no Eyelink system is connected, the GUI will
          act as a mouse simulation
        - Extandable: Due to a flexible pipe command interface additional
          features can be added in future releases (e.g. non-circular target
          windows)
*   Support for MATLAB > 2014a.
*   NidaqServer v.1.0.10.2: support for PCIe-6251 and PCIe-6321

### CHANGED
*   All user-facing functions and classes have extensive documentation of all
    relevant methods and properties.
*   ControlScreen:
        - The GUI has been made more compact and resizable such that other
          windows can fit next to it.
        - The trial error legend now displays the correct labels that were set
          in MainScreen/configuration.
*   ARCADE will now use the matlab.exe from the Windows PATH environmental
    variable. This is usually the one that was installed last. Tested versions
    are 2014a and 2018b Update 2
*   Gammatron stimulus:
        - The drift direction is now configure via the sign of the temporal
          frequency
        - A temporal frequency of 0 will create a static Gammatron.
        - The phase offset can now be set in degree
        - The edge of the circular mask is now anti-aliased

### DEPRECATED
*   The following stimulus properties are deprecated and should not be used
    anymore:
        - Rectangle.color (use Rectangle.faceColor instead)
        - Rectangle.alpha (use Rectangle.faceAlpha instead)
        - Circle.color (use Circle.faceColor instead)
        - Circle.alpha (use Circle.faceAlpha instead)
        - Gammatron.direction (use sign of Gammatron.temporalFrequency
          instead)

### REMOVED
*   The SaccadeStart and SaccadeEnd events that were triggered by previous
    EyeServers are currently not supported.
*   The EyeLinkServer currently does not support overlapping target windows.

## [2.4.0] - 2018-06-15
### NEW
*   A petal-like shape stimulus can now be created using the Petal class
*   The total reward issued during a session can now be retreived using the
    MATLAB function totalRewardtime
*   Improved documentation for helper functions and stimuli


## [2.3.0] - 2018-05-17
### NEW
*   MotionPicture stimuli trigger an event when playback has finished, with
    the name stored in the MotionPicture.endEventName property

### FIXED
*   Animations: De-assigning already finished/de-assigned animations was
    crashing StimServer
*   MotionPicture stimuli were played at half the specified frame rate
    (MotionPicture.screenFramesPerVideoFrame)
*   The specified MotionPicture frame rate was not stored in the MATLAB
    object.

## [2.3.0b2] - 2018-05-04
### CHANGED
*   Default size of PixelShader-based stimuli is now 50x50 px. Shader size is
    automatically increased on demand in Grating and Gabor if radius exceeds
    current shader size
*   Direction of maskRotation parameter of Gabor has been inverted. It used to
    be defined opposite of the Gabor.direction parameter

### FIXED
*   StimServer: changes to stimuli occuring after the end of a deferred mode
    (groupstimli('end')) but before the next frame were ignored. These are now
    also applied with the next frame.
*   Obsolete shader code in Gabor and Grating has been removed


## [2.3.0b1] - 2018-04-13
### NEW
*   Handmapper: an ARCADE add-on for manual receptive field mapping, which can
    be started via arcade/AddOns/Handmapper/RFhandmapper.bat
*   bring_to_front: The drawing order of overlapping stimuli can now be
    adjusted by bringing individual stimuli to the frontmost layer using the
    bring_to_front method.
*   Flicker animation: stimuli can be turned on and off periodically for
    speficied number of frames
*   MotionPicture stimulus (alpha version): image sequences stored in a multi-
    frame TIFF file can be presented as movies. Use
    convert_video_for_StimServer to convert compressed movie files to an
    uncompressed TIFF.
*   NidaqServer: logging option for debugging event-triggered reward
*   Function for plotting a state flow diagram based on trialscript code
*   State: set and get methods for duration and elapsedTime to determine State
    duration at runtime
*   StateRuntimeVariable: a class for holding and retreiving data created at
    runtime of the session, e.g. reaction times. See help StateRuntimeVariable
*   Improvements for CalibrateEyelink: reward is now coupled to advancing to
    the next calibration target, reward and stimulus visibility can be
    triggered via hotkeys

### CHANGED
*   Grating: the spatialFrequency property was renamed to spatialPeriod as it
    was actually specifying the period in px/cycle. spatialFrequency will
    still work but produce a warning

### FIXED
*   Editable variables where not removed from the configuration file when they
    were removed from the GUI
*   Manually adding files to backup in main GUI deleted existing files


## [2.2.0] - 2018-01-10
### NEW
*   EyelinkEyeServer: positions tracked via trackeye are not drawn on the
    Eyelink Host PC's screen.
*   A stimulus position can now be coupled to a coordinate stored in shared
    memory using the animation ExternalPositionControl. This allows for
    example gaze-contingent stimulus presentation and manual receptive field
    mapping.
*   The next state after the maximum number of repetitions of a State can now
    be defined using the nextStateAfterMaxRepetitions property.

### CHANGED
*   Updated the MovingBar class: Playing the bar animation is now triggered
    via MovingBar.play_animation() (see help MovingBar). Also, the animation
    of the bar is now configured by default to trigger the
    StimServerAnimationDone event once the bar has reached it's final
    position.

### FIXED
*   Setting the background color for the pause screen had no effect.
*   Trialscripts that do not use the createTrial function, i.e. put States
    into the StateArc, crashed ARCADE.

## [2.1.4] - 2018-01-08
### FIXED
*   StimServer 1.2.5.1: deleting PixelShader-based stimuli (gratings,
    gammatrons, gaussians, gabors)) without making them visible was crashing
    StimServer.exe in 1.2.4.0 and 1.2.5.0 (ARCADE 2.0.2-2.1.3)

## [2.1.3] - 2017-12-18
### FIXED
*   Bugs due to renaming of NidaqServer to DaqServer
*   Due to MATLAB black magic, states lasted ca. 10% longer than defined by
    the user. Timings of eventmarkers etc. should still have been correct.
    This is fixed with a workaround now. It will be fixed more elegantly in a
    future version of ARCADE.

## [2.1.2] - 2017-11-15
### NEW
*   NidaqServer.exe: support for USB-6353

### FIXED
*   Bugs introduced due to renaming NidaqServer

## [2.1.1] - 2017-11-02
### FIXED
*   NidaqServer.exe 1.0.8.0 sends sufficiently long and spaced eventmarkers
    for TDT's RZ2 (40 microseconds)

## [2.1.0] - 2017-10-30
### NEW
*   Gabor stimulus
*   NidaqServer can be configured to give out an event marker for manual
    rewards
*   Added tutorial documentation for digital input/output

### CHANGED
*   Animations should now be played and stopped via the play_animation and
    stop_animation methods of a stimulus. Using the animation property is
    still supported but deprecated.
*   Default terminal action of animations now 0, i.e., the stimulus persists
    after the animation
*   getPreviousTrialdata now also returns user variables stored with
    storeUserVariables

### FIXED
*   Wrong path of pixel shader file of Gammatron stimulus

## [2.0.1] - 2017-09-29
### FIXED
*   Fixed bugs related to CalibrateEyelink

## [2.0.0] - 2017-09-08
### NEW
*   Linear range animation for image alpha values, StimServer 1.2.3.0
*   Flash animation, StimServer 1.2.3.0

### FIXED
*   Wrong file name of trackdigitalinput function

### CHANGED
*   Restructured StimServer folder
*   terminalAction property of Animation is now a binary string or a number

### FIXED
*   Bugs in Rectangle destructor
*   Animations are unassigned in Stimulus destructor

## [2.0.0a3] - 2017-07-14
### CHANGED
*   Eventmarkers are now controlled via NidaqServer.exe (port 0-1, strobe on
    port2/line7 (PCI-6221) or port2/line0 (PCI-6503)
  
### FIXED
*   Bugs in EyelinkEyeServer


## [2.0.0a2] - 2017-07-10
### NEW
*   Helper function for tracking digital input
*   Buttons and hotkeys in ControlScreen for setting an event to skip a trial.
*   NidaqServer.exe 1.0.4.0 sets a RewardDone event when the reward sequence
    is over
*   Example task for tracking a lever

## [2.0.0a1]
### NEW
*   Buttons and hotkeys for reward in ControlScreen
*   Support for arbitrary digital input devices, e.g. levers.
*   NidaqServer for National Instruments Cards PCI(e)-6221 and PCI-6503
*   EyeServer and DaqServer can be selected from the configuration GUI
*   A trial can be terminated after a maximal number of iterations of a
    specific state (maxRepetitions property of State)

### CHANGED
*   Definition of State: states now wait for kernel32 events and select the
    next state according to which event was triggered or a timeout occurred.
    The syntax for State definition has completely changed (see new
    documentation).
*   Reward is delivered via DaqServer
*   Eye position is monitored in EyeServer processes and status signaled via
    events

### REMOVED
*   onRun functionality of States. If necessary this will be re-added later.

##  [1.0.0b3] - 2017-06-21
### NEW
*   Added Gaussian stimulus

### CHANGED
*   Enhanced condition/block selection functions: block selection is evaluated
    first and its result can be used in the condition selection function as
    2nd argument.
*   Updated Grating stimulus to use new shader implementation

### FIXED
*   Increased refresh rate of ControlScreen to enhance capturing of key
    presses


## [1.0.0b2] - 2017-06-12
### NEW
*   Gammatron stimulus
*   Pixel-shaded picture stimulus (not yet documented)
*   PictureWithGaussianPatch stimulus (not yet documented)
*   Behavioral data from a session is now stored in a unique folder without
    subfolders for experiment and session.
*   Temporal frequencies of several stimuli are now expressed in cycles per s
*   ARCADE version is printed in log files if Git is installed

### FIXED
*   Missing nanmax function in PLTReactionTime
*   Month and day were swapped in date string


## [1.0.0b1] - 2017-05-31
### NEW
*   64-bit support: ARCADE runs on 64-bit MATLAB only (currently only 2014a).
    This allows for very long sessions (>9000 trials) and slightly improves
    performance.
*   Rewritten stimulus classes: stimulus definition has been simplified and
    can now be easily tested outside a running session. This unfortunately
    means existing task scripts have to be adapted. See tutorial documentation
    for an overview.
*   Documentation of all user-oriented functions and classes as well as
    tutorial documentation as been added.
*   New EyeServers: ARCADE provides now interfaces for eye tracking via (1)
    National Instruments Cards (SGLNiEyeServer), (2) ethernet from Eyelink SR
    1000/2000 (SGLEylinkEyeServer) and (3) a test eye signal for debugging
    (SGLTestEyeServer). Currently this has to be configured by manually
    changing line 44 of SGLEyeServerProc.m
*   Laptop mode: when no national instruments card can be detected,
    eventmarkers and reward will not be send out.
*   No MATLAB toolboxes are required to run ARCADE
*   Store events to disk: timestamps of eventmarkers are recorded in separate
    .evt file. The file can be read with readEvtFile.m
*   New file naming scheme: behavioral data files are now named according to
    the pattern subject_day_experiment_session
*   In case of crashing, the behavioral .esi and .hdr files can be converted
    to a MATLAB file using convertEsiFile.m
*   Eye position is now shared among processes via kernel32 NamedSharedMemory
*   Starting and stopping of data acquisition is now triggered via kernel32
    Events
*   The CoreControlScreenPipe was simplified and now only transfers the trial
    data
*   Processes are now managed using the MATLAB Java Runtime with
    processManager.m
*   SGLNiEyeServer now samples at a fixed rate
*   user32 functionality has been removed

### FIXED
*   Occasional freezing of ARCADE should not happen anymore. On pipe write
    error, the Core process continued to write instead of raising an error.
    This may have cause the hangups.
*   Several minor bugs.
