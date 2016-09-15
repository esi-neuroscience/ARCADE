classdef (Sealed) SGLStateArc < handle
    % [SINGELTON] StateArc 
    % - handles the movement from one state to another 
    % - holds a vector of states, 
    %   which, together, represent the possible states that make up a trial
    % - the StateArc is blind to the next state, 
    %   as well as all possible state trajectories
    % - StateArc relies on the return value from each state to determine 
    %   what the next state is
    
    
    % *Matlab takes time to load classes
    % thus the first time a StateArc object is created it could take 80-100ms
    % However, once the class is loaded StateArc will take roughly 10ms to create
    % unless clear all or clear classes is called, then it will again be 80-100ms
    

    % TrialStart time is when the initial state is started 
    % next state calls are logged 
    
    
    % the turnover time is around 10-16ms
    
    %---------------------------------------------%
    % unknown   - Jarrod, wrote class
    % 21.4.2016 - Jarrod, added some documentation/notes
    
    
    %# set by user 
    properties (AbortSet = true)
        states = {}; % vector of states 
        initialState 
        %finalState
    end
    
    %# set during operation 
    properties (...
            Access   = private,...
            AbortSet = true)
        currentState  
        previousState
        startTrialTic
        nextState
    end 
    
    properties (...
            AbortSet = true,...
            Access   = private)
        % indicies of the states
        %idx_currentState
        %idx_previousState
        %idx_nextSate
        % EventLog Object 
        % - send start trial 
    end
    
    properties (SetAccess = immutable)
        % EventLog Object 
        % - send start trial 
        %evtLogObj 
    end
    
    methods (Static)
        function this = launch
            persistent thisObj
            if isempty(thisObj) || ~isvalid(thisObj)
                thisObj = SGLStateArc;
            end
            this = thisObj;
        end
    end
    
    methods (Access = private)
        %# constructor
        function this = SGLStateArc 
            % get the instance of the event logger 
            % was created by control screen 
            %this.evtLogObj = SGLEventLog.launch;
        end  
    end

    methods
        %# Add States
        function mAddState(this,varargin)
            %---------------------------------------%
            % Create instance of State
            %   input can be:
            %   struct, fields = names, values = data
            %   'name', value pairs
            %   cell vector of structs
            %   cell vector of 'name', value pairs
            %
            if all(cellfun('isclass',varargin,'struct'))   % single state struct
                for k = 1:numel(varargin)
                    this.states{end+1} = TRLState(varargin{k});
                end
            elseif all(cellfun('isclass',varargin,'cell')) % cell vector of states
                for k = 1:numel(varargin)
                    this.states{end+1} = TRLState(varargin{k}{:});
                end
            else
                % assume 'name', value pairs
                this.states{end+1} = TRLState(varargin{:});
            end
            
        end
        
        %# set the property of an already existing state
        % generally not used 
        function mSetStateProperty(this,kstate,varargin)
            
            % error checking
            if isempty(varargin) || isempty(kstate)
                error('Must pass in state, properties and values.'); 
            elseif isnumeric(kstate) && kstate>=numel(this.states)
                error('State has not been initialized.');
            end
            
            % get index
            if ischar(kstate) 
                kstate = this.mFindState(kstate);
            end
            
            this.states{kstate}.mSetProperties(varargin);
        end
        
        %---------------------------%
        %# Run a single trial, move through states
        function mRunTrial(this)
                % catch errors and warnings
                dbstop if error
                % event log object
                %evtLogObj = SGLEventLog.launch;
                % nextState is always convert to an index 
                %this.finalizeStates; % finalize states
                
                % Move through States 
                % until the 'final' state is reached, then break 
                while 1
                    changeState = false;
                     
                    if isempty(this.currentState) 
                        ns = this.initialState;
                        if ischar(ns), ns = this.mFindState(ns); end
                        this.currentState  = ns;
                        this.startTrialTic = tic;
                        changeState        = true;
                    else
                        if this.currentState ~= this.nextState
                            changeState        = true;
                            this.previousState = this.currentState;
                            this.currentState  = this.nextState;
                        end
                    end
                    % this.currentState  => is the state to transition to 
                    % this.previousState => is the state transitioning from 
                    % this.nextState     => is the flag indicating what the next state should be  
                    
                    % *** STATE TRANSITION ***
                    if changeState 
                        %if ~isempty(leaveState) 
                        %    disp(['Transition Time: ', num2str(toc(leaveState)*1000)]);
                        %end
                        %------------------------------%
                        % print message to event log 
                        %timestamp   = toc(this.startTrialTic)*1000;
                        %eventstring = this.states{this.currentState}.name;
                        %evtLogObj.mUpdateString(timestamp,eventstring);
                        %drawnow; % - 16ms
                        %drawnow('expose'); % - only graphics objects
                        % drawnow('update'); % - only non-graphics objects
                        
                        % this returns whatever the next state should be 
                        ns = this.states{this.currentState}.mRunState;% begin state
                        %leaveState = tic;
                        % if char, find state index
                        if ischar(ns), ns = this.mFindState(ns); end;  
                        this.nextState = ns; % set nextstate 
                        % break trial if reached final state
                        if ns == 0, break; end;
                    end
                end
        end
        
        %-----------------------------------%
        % delete states 
        %function removeState(this, varargin)
            % allow deleting 1 or all
            %delete(this.states);
            %this.states = [];
        %end
        
        
        %function mCleanup(this)
           % need a good cleanup function  
            %delete(this.states{:}); % does that work
       % end
        
        function delete(this)
            if ~isempty(this.states)
                for k = 1:length(this.states)
                    this.states{k}.delete;
                end
            end
        end
    end
    
    
    methods (Access = private)
        %function set_StateIndicies(this)
            % loop through states
            % turn strings into indicies 
        %end
        
        %# call the finalize setup of each state 
        function finalizeStates(this)
            statesVec = this.states;
            if ~isempty(statesVec)
                for k = 1:length(statesVec)
                    this.states{k}.finalizeStateSetup;
                end
            end
        end
        
        %# if state name is a character string
        % find the index of the state in the state vector 
        function indx = mFindState(this,name)
            if strcmpi(name,'final')
                indx = 0;
            else
                indx = find(strcmp(name,cellfun(@(state) state.name, this.states, 'unif', 0)));
            end
            if isempty(indx)
                error(['State ',name,' does not exist.']);
            end
        end
    end % methods
end % classdef


%mco   = ?State;
%plist = mco.PropertyList;
%names =

% put it in stateArc
% or put it in CORBehaviroual 



