
%
%  sleep( ms )
%  
%  Direct call to system kernel to pause the current process for ms
%  milliseconds. If ms is 0 (zero) then the function returns immediately.
%  
%  MEX wrapper function for Windows system call Sleep( ). Note that the
%  behaviour when ms is 0 is different from the system call.
%  
%  See: https://docs.microsoft.com/en-us/windows/win32/api/synchapi/
%    nf-synchapi-sleep
%  
%  Use in combination with timeBEPeriod to get higher-resolution timers.
%  
%  Written by Jackson Smith - Dec 2021 - Fries Lab (ESI Frankfurt)
%
 