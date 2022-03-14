
function  apriority ( fnam , arg )
% 
% apriority ( fnam , arg ) - Manages priority class of critical ARCADE
%   processes. Select form and function by providing one of the following
%   strings in fnam:
% 
% apriority ( 'initialise' , exenam ) - Initialise apriority by searching
%   for the process identifiers of processes running executables named in
%   exenam, a cell array of strings. PID numbers are stored internally in a
%   persistent variable which can be overwritten with subsequent calls to
%   'initialise'. In addition, the current priority class is stored, along
%   with a copy of the executable file name. Reports success or failure to
%   detect processes, but will not raise an error. Provide an empty string
%   '' to refer to the calling process.
%   
%   e.g. apriority ( 'initialise' , { '' , 'EyeLinkServer.exe' ,
%          'NidaqServer.exe' , 'StimServer.exe' } )
% 
% apriority ( 'change' , pnam ) - Change the priority of the processes that
%   were found during initialisation. pnam specifies the new priority class
%   that will be applied to all found processes. Valid strings are:
%   
%             'high' - Highest priority that an ARCADE process may use.
%     'above normal' - Higher priority than 'normal' but less than 'high'.
%           'normal' - No special scheduling requirements, likely default.
%     'below normal' - Less priority than 'normal' but more than 'low'.
%              'low' - Lowest priority that an ARCADE process can have.
%            'reset' - Switch processes back to their priority during
%                      initialisation.
%   
%   Note: If a process identifier has a different executable name at the
%   time that the priority class is being changed, then an error will be
%   triggered. This situation is possible, as process identifiers are
%   recycled between closing and opening new processes on the system.
% 
% Written by Jackson Smith - Dec. 2021 - Fries Lab (ESI Frankfurt)
% 
  
  
  %%% Input check %%%
  
  % Check number of input args
  narginchk ( 2 , 2 )
  
  % fnam must be a char array
  if  ~ ischar ( fnam )  ||  ~ isrow ( fnam )
    error ( 'fnam must be a char array' )
  end
  
  
  %%% Persistent variables %%%
  
  % proc is a struct with fields .pid, .pc, and .exe that are set during
  % initialisation
  persistent  proc
  
  
  %%% Select function %%%
  
  switch  fnam
    
    % Search for process identifiers, exe names, and current priorities
    case  'initialisation'
      
      %-- Input arg check --%
      
      if  ~ iscellstr ( arg )
        error ( 'arg must be cell array of strings during initialisation' )
      end
      
      %-- Init --%
      
      % New empty struct in persistent variable
      proc = struct ;
      
      % Search for processes
      [ proc.pid , proc.exe ] = priority ( 'i' , arg ) ;
      
      % We will assume that empty strings referring to calling process will
      % map to MATLAB.exe
      i = strcmp( arg , '' ) ;
      arg( i ) = { 'MATLAB.exe' } ;
      
      % Determine which executables were found in running processes
      i = ismember ( arg , proc.exe ) ;
      
      % Report which processes were found, and which weren't
      fprintf ( 'apriority init %s success.\n' , arg{   i } )
      fprintf ( 'apriority init %s failure.\n' , arg{ ~ i } )
      
      % Retrieve current priority class for found processes
      [ proc.pc , exe ] = priority( 'g' , proc.pid ) ;
      
      % Check that executable names are still the same
      if  any( ~strcmp( proc.exe , exe ) )
        error ( 'Process executable name mismatch' )
      end
      
    % Change process priority class of initialised processes
    case  'change'
      
      %-- Input arg check --%
      
      if  ~ ischar ( arg )  ||  ~ isrow ( arg )
        error ( 'arg must be a char array when changing priority class' )
      end
      
      %-- Map arg string to priority class --%
      
      switch  arg
        case          'high' , pcnew = 'HIGH_PRIORITY_CLASS'         ;
        case  'above normal' , pcnew = 'ABOVE_NORMAL_PRIORITY_CLASS' ;
        case        'normal' , pcnew = 'NORMAL_PRIORITY_CLASS'       ;
        case  'below normal' , pcnew = 'BELOW_NORMAL_PRIORITY_CLASS' ;
        case           'low' , pcnew = 'IDLE_PRIORITY_CLASS'         ;
        case         'reset' , pcnew =  proc.pc                      ;
      end
      
      %-- Change priority class --%
      
      res = priority( 's' , proc.pid , proc.exe , pcnew ) ;
      
      % Report failures
      if  ~ all (  res  )
        
        % Identify processes that were did not change priority
        i = ~ res ;
        
        % New cell array with row order [ process identifier ; executable
        % name ]. Each process represented by one column of C.
        C = [ num2cell( proc.pid( i ) ) ; proc.exe( i ) ] ;
        
        % Return arguments in column major order. Generates one line of
        % printed output per process.
        fprintf ( [ 'Failed set process pid: %d, exe: %s to ' , arg , ...
          ' priority.\n' ] , C{ : } )
        
      end % report failures
      
    % Unrecognised function
    otherwise , error ( 'fnam is unrecognised' )
        
  end % select process priority function
end % apriority

