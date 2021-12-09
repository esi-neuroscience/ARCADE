
%  
%  timeBEPeriod( BE , ms )
%  [ BE , ms ] = timeBEPeriod
%  
%  MEX wrapper for Windows system calls timeBeginPeriod and timeEndPeriod.
%  These can be used to request higher precision timers for the calling
%  process.
%  
%  Input argument BE is a scalar char. If it is 'b' then timeBeginPeriod
%  is used. Otherwise, if BE is 'e' then timeEndPeriod is used instead.
% 
%  ms is a scalar double giving the requested minimum timer resolution, in
%  milliseconds. Thus it may not be less than a value of 1 (one). Note
%  that ms is cast to an unsigned integer, so any fractional component is
%  rounded away.
%  
%  If no input argument is given then the current state of timeBEPeriod is
%  queried. The output arguments equal their input values in the most
%  recent call to timeBEPeriod( BE , ms ). The exception is when input
%  argument BE was 'e', in which case ms is returned as 0 (zero).
%  
%  The Windows documentation adds:
%  
%    Call this function immediately before using timer services, and call
%    the timeEndPeriod function immediately after you are finished using
%    the timer services.
%    
%    You must match each call to timeBeginPeriod with a call to
%    timeEndPeriod, specifying the same minimum resolution in both calls.
%    An application can make multiple timeBeginPeriod calls as long as
%    each call is matched with a call to timeEndPeriod.
%
%    See: https://docs.microsoft.com/en-us/windows/win32/api/timeapi/nf-timeapi-timebeginperiod
%  
%  Hence, timeBEPeriod will not allow two calls to timeBeginPeriod in a
%  row without an intervening call to timeEndPeriod. Also, ms must be the
%  same for paired calls to the time*Period functions.
%  
%  The same documentation goes on to confess that the behavour of
%  timeBeginPeriod is different for different versions of Windows. Thus,
%  consider carefully which version of Windows is in use.
%
%  Compile with >> mex -R2018a '-LC:\Program Files\MATLAB\R2018b\sys\lcc64\lcc64\lib64' -lwinmm timeBEPeriod.c
%  
%  Note that this is specific to Matlab R2018b. Must be able to link the
%  winmm.lib, wherever it may be.
%  
%  Written by Jackson Smith - Dec 2021 - Fries Lab (ESI Frankfurt)
%  
