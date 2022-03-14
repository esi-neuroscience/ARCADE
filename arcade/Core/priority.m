
% 
% [ ... ] = priority( cmd , ... )
% 
% Query or change the priority level of specified processes. cmd is a
% single char used to select the form and action of the function:
% 
%   [ pid , exe ] = priority( 'i' , names )
% 
%     Find processes that have executables listed in names, a cell array
%     of strings. Returns pid, a uint32 row vector of their process
%     identifiers.
% 
%     It is possible that pid has more entries than names. This can
%     happen when the same executable is running in multiple processes.
%     Hence, cell array of strings exe is also returned. It names the
%     executable of each process identified in pid.
% 
%     In order to get the process identifier of the current process that
%     is calling priority( ), include an empty string i.e. '' in names.
%     The corresponding identifier pid( end ) will contain something like
%     'MATLAB.exe' in exe{ end }.
% 
%     Any string in names that does not match the executable of any
%     visible process is quietly ignored. If no processes are found then
%     pid and exe is empty i.e. [ ] and { }.
% 
%     Example: pid = priority( 'i' , { '' , 'DaqServer.m' ,
%                'EyeLinkServer.exe' , 'StimServer.exe' } ) ;
% 
%   [ pc , exe ] = priority( 'g' , pid )
% 
%     Get the priority class of processes with process identifiers given
%     in uint32 row vector pid. Returns uint32 row vector pc containing
%     the priority class of each process. pc is in register with pid. exe
%     contains cell array of strings in register with pid and pc; each
%     string is the name of the executable file running on each process.
%     Compare exe from priority( 'i' ) and priority( 'g' ) for additional
%     error checking. Process identifiers can be recycled. It is not
%     impossible that a process may be closed, and that its PID becomes
%     reassigned to a new process running a different executable.
% 
%   res = priority( 's' , pid , exe , pcname )
% 
%     Set the priority class for processes with process identifiers given
%     in uint32 row vector pid. exe is a cell array of strings in
%     register with pid that names the executable file of each process.
%     The function will check that the current executable names match the
%     contents of exe. See priority( 'g' ) help (above) for rationale.
% 
%     The new priority level is named in pcname which must be one of the
%     following strings:
% 
%       'ABOVE_NORMAL_PRIORITY_CLASS'
%       'BELOW_NORMAL_PRIORITY_CLASS'
%               'HIGH_PRIORITY_CLASS'
%               'IDLE_PRIORITY_CLASS'
%             'NORMAL_PRIORITY_CLASS'
% 
%     res is a logical row vector in register with pid that is true for
%     each process that was successfully set to the new priority class.
% 
%   res = priority( 's' , pid , exe , pc )
% 
%     Alternatively, instead of pcname, pc can be a uint32 row vector in
%     register with pid that provides the desired priority class for
%     each process. This allows different priority classes to by assigned
%     to each process identified by pid.
% 
%    pc = priority( 'c' , pcname )
% 
%     Return scalar uint32 value of the priority class named in pcname.
%     pcname must be one of the strings listed for priority( 's' , ... ).
%     If pcname is not found in the list then pc is empty.
% 
% This function is specific to Windows.
% 
% Compile with >> mex -R2018a '-LC:\Program Files\MATLAB\R2018b\sys\lcc64\lcc64\lib64' -lPsapi priority.c
% 
% For more information, see: https://docs.microsoft.com/en-us/windows/win32/procthread/process-and-thread-functions
% 
% Written by Jackson Smith - Dec 2021 - Fries Lab (ESI Frankfurt)
% 
