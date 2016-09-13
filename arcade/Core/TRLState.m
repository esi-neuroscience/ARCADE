classdef TRLState <  AUXPropertyManager & AUXEvalFunctions %& EyeTrack 
    % [TRIAL] STATE: 
    % - run a loop
    % - evaluate functions on entry and exit
    % - evaluate function on property value (e.g. current time)*todo
    % - turn on/off trackers (eye/joy)
    
    % Superclasses:
    %  PropertyManager - provides a method to set the object properties 
    %  EyeTrack        - provides eye tracking functions 

    % TO DO: change the evalution method of the onEntry/onExit functions
    
    % -> create instance of State
    % -> add properties
    % -> *all properties must be added before creating listener 
    % -> optimize the start 
    
    % evaluate all onEntry functions 
    % - eventmarker
    % - stim server calls
    % - reactionTime 
    % then, start the ey polling, do not want to 
    
    % IDEAS:
    % onEarlyExit -> functions only on early exit
    % add reset to original values for nextState
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 19.3.2015 - Jarrod, added in error checks for trackEye. Jarrod
    % 19.3.2015 - Jarrod, added default value for duration. Jarrod
    % 19.3.2015 - Jarrod, added error check for required inputs. Jarrod
    % 11.9.2015 - Jarrod, 
    % - added property runNumber, indicates the number of times this state
    % has been called 
    % - added a evaluate function(s) functionality for run number
    % 'onRunNumber'
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    %# properties set by user
    properties (AbortSet = true)
        % >> required 
        name@char       % name of this state
        nextState@char  % name of nextState, should time elapse
        % *nextState can be overwritten by functions such as those in trackEye
        
        % >> optional 
        duration@double  scalar = 0; % default duration 

        % anonymous functions
        onEntry%@cell vector = {}; % {function handle, input}
        onExit%@cell  vector = {};
        
        onRunNum@struct
        
        %.onEntry = [];% struct with fields onEntry, onExit
        %onRunNum.onExit = [];
        
        % these should not be altered after being set
        trackEye = [];    
        
        %duringFunc
        % onTime
        % onProperty
        %breakState = false; % break state loop

    end
    
    %# properties set during operation 
    properties (...
            AbortSet  = true,...
            SetAccess = private) 
        
        startTic       % set at start
        exitTime  = 0; % time this state finished 
        timeNow   = 0;
        runNumber = 0; % number of times this state has been called 
        % elapsedTime
        isRunning = false; % flag to control the execution of callbacks
    end
    
    properties (...
            AbortSet  = true,...
            SetAccess = immutable) 
        % set on creation 
        atCreation_nextState
        atCreation_name        
    end

    methods (Static = true)
        %# constructor
        function this = TRLState(varargin)  
            if ~isempty(varargin)
                this.mSetProperties(varargin);
                % check the state properties
                % error checking at this point forces the user to avoid
                % errors on instance creation 
                this.mErrorCheck;
                % these variables are reset onExit 
                this.atCreation_nextState = this.nextState;
                this.atCreation_name      = this.name; 
            end
        end       
    end
    
    methods
        %# begin state
        function ns = mRunState(this)
            runMode = 0;
            % increment run number
            this.runNumber = this.runNumber+1;

            % if eye trackers, then track eye
            trackEye = this.trackEye; %#ok<*PROP>
            if ~isempty(trackEye)
                runMode = 1;
                this.mCheckEyePosition(trackEye);
            end
            
            this.isRunning = true;           % set is running flag
            this.mRunStateLoop(runMode);     % run state loop mRunTrial (move through states)
            this.isRunning = false;
            
            ns = this.nextState;      % return nextstate when loop returns
            this.mResetCreationState; % reset some properties to creation
        end

        %# set method for the eye tracker 
        function set.trackEye(this,structInput)
            
            % Check input:
            %   input should be a struct or an array of structs
            %   thus fundamental input should be a structure

            % check input and convert if necessary
            while 1
                if iscell(structInput)
                    if all(cellfun('isclass',structInput,'struct'))
                        structInput = cell2mat(structInput);
                        break;
                    end
                elseif isstruct(structInput)
                    % valid input 
                    break;
                end
                error('set.trackEye: Unknown or Inconsistent input.'); 
            end

            % make sure that there is input 
            if isempty(structInput)
                disp('Warning: trackEye input is empty.');
                this.trackEye = [];
                return;
            end

            % create an instance of TrackEyePosition
            trkEye = TRKEyePosition;
            [fcnEvalEyePosition, returnNextState] = ...
                arrayfun(@(strct) trkEye.(['m_',strct.method])(strct), structInput, 'unif',0);

            % set the trackEye property 
            % transpose to columns 
            this.trackEye = [fcnEvalEyePosition', returnNextState'];
            
            %this.mCheckEyePosition([fcnEvalEyePosition', returnNextState']);
            
        end

        %# Check Eye Position function 
        %function mCheckEyePosition(this,hObj,evt,varargin) 
        function shouldBreak = mCheckEyePosition(this,varargin)
            persistent fcnEvalEyePosition returnNextState
            persistent EyeServer
            
            shouldBreak = false;
            if ~isempty(varargin) % initialize
                % fetch a the Eye Server
                EyeServer = SGLEyeServerCorePipe.launch;
                fcnEvalEyePosition = varargin{1}(:,1);
                returnNextState    = varargin{1}(:,2);
                return;
            end

            % else get eye
            % returns eye position in pixels, and [x_pos, y_pos];
            eye_pos = EyeServer.mRequestEyeData;
            
            if ~isempty(eye_pos)
                %disp(['Eye Position: ', this.nextState]);
                % evaluate functions sequentially
                k = 1;
                nFuncs = length(fcnEvalEyePosition);
                while k<=nFuncs
                    %fcnEvalEyePosition{k}
                    %eye_pos
                    shouldBreak = fcnEvalEyePosition{k}(eye_pos);
                    if shouldBreak
                        %disp(['Current State: ', this.nextState]);
                        this.nextState = returnNextState{k};
                        %disp(['Next State changed: ', this.nextState]);
                        break;
                    end
                    k = k+1;
                end
            end
        end
        
        
    end
    

    methods (Access = private)
        %# State Loop (run this state)
        % - start trial by starting first state
        % - return when 'final' state is returned 
        % runMode: 
        %   0 -> normal
        %   1 -> poll eye
        function mRunStateLoop(this,runMode)
            % call onEntry method
            this.mEvaluateFunctionsOnEntry;
            while 1
                if runMode==1
                    % check eye position
                    breakState = this.mCheckEyePosition;
                    if breakState, break; end;
                end
                
                if this.mElapsedTime, break; end;
                java.lang.Thread.sleep(1);
            end
            % call onExit method
            this.mEvaluateFunctionsOnExit;
        end
        
        %# On Entering State Loop
        function mEvaluateFunctionsOnEntry(this)
            % assign start tic
            this.startTic = tic; 
            % evaluate entry functions 
            transitionFunc = this.onEntry;  
            if ~isempty(transitionFunc)
                this.evalFunctions(transitionFunc);
            end 
            
            % test if there is a function to run 
            %evalFuncOnRun = this.onRunNum.onEntry;
            try  %#ok<TRYNC>
               evalFuncOnRun = this.onRunNum.onEntry{this.runNumber};
               this.evalFunctions(evalFuncOnRun);
            end

        end
         
        %# On Exiting State Loop
        function mEvaluateFunctionsOnExit(this)
            % exit time 
            this.exitTime = toc(this.startTic)*1000; % ms
            % evaluate any exit functions 
            transitionFunc = this.onExit;    
            if ~isempty(transitionFunc)
                this.evalFunctions(transitionFunc);
            end 
            
            try  %#ok<TRYNC>
               evalFuncOnRun = this.onRunNum.onExit{this.runNumber};
               this.evalFunctions(evalFuncOnRun);
            end
        end
        
        %# Check Elapsed Time 
        function result = mElapsedTime(this)
            this.timeNow = toc(this.startTic)*1000;       
            result       = this.timeNow >= this.duration;
        end
        
        %# Error Checking
        function mErrorCheck(this)
           % check for required inputs
           if isempty(this.name) || isempty(this.nextState)
               error('Create State: All states require the property name and nextState');
           end
        end
        
        function mResetCreationState(this)
            % reset these properties 
            % other variables will remain as they were when the state exited
            % these 2 variables, can be changed, but only
            % nextState will have any influence on behaviour 
            % it is reset here because many users may not be aware that it
            % was changed, for example trackEye changes nextSate
            this.nextState = this.atCreation_nextState;
            this.name      = this.atCreation_name; 
        end
        

  %{
        %# Evaluate functions 
        function evalFunctions(this,funcs)
            % *add: collect output of functions
            % issue for functions  with no output
            % out = cellfun(@(func) func{1}(func{2:end}), funcs, 'unif',0);
            % use function to set a property (need to add property first)
            
            for k = 1:numel(funcs)
                func_ = funcs{k};
                
                if length(func_)==1
                    func_{1}();
                else
                    % for set/get properties of self
                    self = strcmp(func_{2:end},'self'); % replace 'self' with this
                    if any(self), func_{find(self)+1} = this; end
                    func_{1}(func_{2:end});
                end
            end
        end
        %}
        % ****** listen to property ******
        % function at time 
        % function on property change
        
        
        
    end
    
    methods 
        %# delete function 
        function delete(this)
          % if ~isempty(this.hlEye)% && isvalid(this.hlEye)
                %this.hlEye.Enabled = false;
             %   delete(this.hlEye);
           % end
        end
    end
%     

end

       %{
        %# Error check for on Entry
        function set.onEntry(this,value)
            % input must be either:
            % 1. a cell vector
            % 2. a single anonymous function 
            % 2. a vector of anonymous functions  
            this.onEntry = value;
        end
        
        %# Error check for on Exit
        function set.onExit(this,value)
            % input must be either:
            % 1. a cell vector
            % 2. a single anonymous function 
            % 2. a vector of anonymous functions  
            this.onExit = value;
        end
        %}

%{
function flag=isMultipleCall()
  flag = false; 
  % Get the stack
  s = dbstack();
  if numel(s)< =2
    % Stack too short for a multiple call
    return
  end
 
  % How many calls to the calling function are in the stack?
  names = {s(:).name};
  TF = strcmp(s(2).name,names);
  count = sum(TF);
  if count>1
    % More than 1
    flag = true; 
  end
end

function MyCallback(hObj, EventData)
  % Quick bail-out if callback code is called before another has ended
  
  %Code Block 1 - interrruptable
  if isMultipleCall();  return;  end
 
  % is evaluating
  % if this is interrupted
  % dump and return here
  % - unterruptbale
  
  ...  % do some actual callback work here
  drawnow();
end



% Variant1
function myCallbackFcn1(hObject,eventData,varargin)
   persistent inCallback
   if ~isempty(inCallback),  return;  end
   inCallback = true;
   try
       % do something useful here
   catch
       % error trapping here
   end
   inCallback = [];
end  % myCallbackFcn1
 
% Variant2
function myCallbackFcn2(hObject,eventData,varargin)
   inCallback = getappdata(hObject,'inCallback');
   if ~isempty(inCallback),  return;  end
   setappdata(hObject,'inCallback',true);
   try
       % do something useful here
   catch
       % error trapping here
   end
   setappdata(hObject,'inCallback',[]);
end  % myCallbackFcn2

%}






