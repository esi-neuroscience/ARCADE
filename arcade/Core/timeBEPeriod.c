
/*  timeBEPeriod( BE , ms )
 *  [ BE , ms ] = timeBEPeriod
 *  
 *  MEX wrapper for Windows system calls timeBeginPeriod and timeEndPeriod.
 *  These can be used to request higher precision timers for the calling
 *  process.
 *  
 *  Input argument BE is a scalar char. If it is 'b' then timeBeginPeriod
 *  is used. Otherwise, if BE is 'e' then timeEndPeriod is used instead.
 * 
 *  ms is a scalar double giving the requested minimum timer resolution, in
 *  milliseconds. Thus it may not be less than a value of 1 (one). Note
 *  that ms is cast to an unsigned integer, so any fractional component is
 *  rounded away.
 *  
 *  If no input argument is given then the current state of timeBEPeriod is
 *  queried. The output arguments equal their input values in the most
 *  recent call to timeBEPeriod( BE , ms ). The exception is when input
 *  argument BE was 'e', in which case ms is returned as 0 (zero).
 *  
 *  The Windows documentation adds:
 *  
 *    Call this function immediately before using timer services, and call
 *    the timeEndPeriod function immediately after you are finished using
 *    the timer services.
 *    
 *    You must match each call to timeBeginPeriod with a call to
 *    timeEndPeriod, specifying the same minimum resolution in both calls.
 *    An application can make multiple timeBeginPeriod calls as long as
 *    each call is matched with a call to timeEndPeriod.
 *
 *    See: https://docs.microsoft.com/en-us/windows/win32/api/timeapi/
 *      nf-timeapi-timebeginperiod
 *  
 *  Hence, timeBEPeriod will not allow two calls to timeBeginPeriod in a
 *  row without an intervening call to timeEndPeriod. Also, ms must be the
 *  same for paired calls to the time*Period functions.
 *  
 *  The same documentation goes on to confess that the behavour of
 *  timeBeginPeriod is different for different versions of Windows. Thus,
 *  consider carefully which version of Windows is in use.
 *
 *  Compile with >> mex -R2018a '-LC:\Program Files\MATLAB\R2018b\sys\
 *    lcc64\lcc64\lib64' -lwinmm timeBEPeriod.c
 *  
 *  Note that this is specific to Matlab R2018b. Must be able to link the
 *  winmm.lib, wherever it may be.
 *  
 *  Written by Jackson Smith - Dec 2021 - Fries Lab (ESI Frankfurt)
 *  
 */


/*** Include block ***/

  // Matlab APIs
  #include  "mex.h"
  #include  "matrix.h"

  // OS API
  #include  <Windows.h>


/*** Define block ***/

  // Number of input args required. This is also the maximum number of
  // output arguments in the query form of the function call.
  #define  NARGIN  2
  
  // Index of BE in p*hs
  #define  BEINDX  0

  // Index of ms in p*hs
  #define  MSINDX  1
  
  // Default value of res.
  #define  RESNUL  -1
  
  // Minimum allowable value of ms
  #define  MSMINV  1

  // Return value of ms when timeBeginPeriod has not been called i.e. no
  // multi-media timer
  #define  MSNOMM  0


/*** Static variables ***/

  // This has two functions. It tracks if timeBeginPeriod has been called.
  // Thus, it tracks whether timeEndPeriod must be called next. Second, it
  // remembers the resolution requested in the call to timeBeginPeriod.
  // Before a call to timeBeginPeriod (i.e. after a valid call to
  // timeEndPeriod) the value is RESNUL. In other words, if res == RESNUL
  // then a fresh call to timeBeginPeriod is allowed.
  static mxInt64  res = RESNUL ;


/*** timeBEPeriod main function ***/

void  mexFunction ( int nlhs ,       mxArray ** plhs ,
                    int nrhs , const mxArray ** prhs )
{ 
  
  /** Input checking **/
    
    // No input args, must be timeBEPeriod( BE , ms )
    if  ( nlhs  ==  0 )
    {
      // Check number of input args. If this is correct then we fall
      // through the rest of this if else ... block to input value checking
      if  ( nrhs != NARGIN )
        mexErrMsgIdAndTxt ( "timeBEPeriod:input" , "expect %d input args" ,
          NARGIN ) ;
    }
      
    // Query state of multimedia timer with [ BE , ms ] = timeBEPeriod
    else  if  ( nlhs <= NARGIN )
    {
      
      // Check there are no input args
      if  ( nrhs != 0 )
        mexErrMsgIdAndTxt ( "timeBEPeriod:output", "expect 0 input args" );
      
      // timerBeginPeriod not called yet, BE is 'e'
      if  ( res == RESNUL )  plhs[ BEINDX ] = mxCreateString ( "e" ) ;
      
      // timerBeginPeriod already called, BE is 'b'
      else                   plhs[ BEINDX ] = mxCreateString ( "b" ) ;
      
      // ms is also requested
      if  ( nlhs == NARGIN )
      {
        // timerBeginPeriod not called, default return value
        if  ( res == RESNUL )
          plhs[ MSINDX ] = mxCreateDoubleScalar ( MSNOMM ) ;
        
        // timerBeginPeriod called, return current timer resolution
        else  plhs[ MSINDX ] = mxCreateDoubleScalar ( res ) ;
        
      } // set ms
      
      /* Done */
      return ;
      
    } // end [ BE , ms ] = timeBEPeriod
      
    // No recognised form of call to function timeBEPeriod
    else  mexErrMsgIdAndTxt ( "timeBEPeriod:notvalid" , 
                                    "Unrecognised call to timeBEPeriod" ) ;
    
    /* From here on, we are executing timeBEPeriod( BE , ms ) */
    
    // Allocate generic counter
    int  i ;
    
    // Input args, check generic property requirements
    for  ( i = 0 ; i < NARGIN ; ++i )
    {
      
      // Input arg cannot be empty
      if  ( mxIsEmpty( prhs[ i ] ) )
        mexErrMsgIdAndTxt ( "timeBEPeriod:empty" , "Input %d is empty" ,
          ++i ) ;
      
      // Input arg must be scalar
      if  ( !mxIsScalar( prhs[ i ] ) )
        mexErrMsgIdAndTxt ( "timeBEPeriod:scalar"  , 
          "Input %d is not scalar" , ++i ) ;
      
    } // generic arg check
    
    // BE must be type char
    if  ( !mxIsChar( prhs[ BEINDX ] ) )
      mexErrMsgIdAndTxt ( "timeBEPeriod:BEtype" , "BE is not char" ) ;
    
    // Point to BE value
    mxChar * BE = mxGetChars ( prhs[ BEINDX ] ) ;
    
    // Check value of BE
    if  ( *BE != 'b'  &&  *BE != 'e' )
      mexErrMsgIdAndTxt ( "timeBEPeriod:BEval" , "BE must be 'b' or 'e'" ,
        ++i ) ;
    
    // A previous call to timeBeginPeriod has not yet been ended by a call
    // to timeEndPeriod!
    if  ( *BE == 'b'  &&  res != RESNUL )
      mexErrMsgIdAndTxt ( "timeBEPeriod:begin" , "Previous call to "
        "timeBEPeriod( 'b' , %lld ) has not been ended yet" , res ) ;
    
    // No call to timeBeginPeriod has been issued yet
    if  ( *BE == 'e'  &&  res == RESNUL )
      mexErrMsgIdAndTxt ( "timeBEPeriod:end" , "No previous call to "
        "timeBEPeriod( 'b' , ms ) has been made yet" ) ;
    
    // Input must be real-valued
    if  ( mxIsComplex( prhs[ MSINDX ] ) )
      mexErrMsgIdAndTxt ( "timeBEPeriod:complex" , "ms is complex value" );
    
    // ms must be type double
    if  ( !mxIsDouble( prhs[ MSINDX ] ) )
      mexErrMsgIdAndTxt ( "timeBEPeriod:mstype" , "ms is not double" ) ;
    
    // Copy the value of ms
    double  ms = mxGetScalar ( prhs[ MSINDX ] ) ;
    
    // Undefined very large value or NaN
    if  ( !mxIsFinite( ms ) )
      mexErrMsgIdAndTxt ( "timeBEPeriod:notfinite" , "ms is not finite" ) ;
    
    // Check value of ms
    if  ( ms < MSMINV )
      mexErrMsgIdAndTxt ( "timeBEPeriod:msval" , "ms < %d" , MSMINV ) ;
    
    // We're ending a time period, does the timer resolution match?
    if  ( *BE == 'e'  &&  res != ms )
      mexErrMsgIdAndTxt ( "timeBEPeriod:msmatch" , "ms does not match "
        "most recent call timeBEPeriod( 'b' , %lld )" , res ) ;
  
  
  /* Multimedia timer resolution */
    
    // Point to function name
    char * fnam ;
    
    // Error code
    MMRESULT  err ;
    
    // Choose function
    switch  ( *BE )
    {
      // timerBeginPeriod
      case  'b' : fnam = "timeBeginPeriod" ;  err = timeBeginPeriod( ms ) ;
                  break ;
      
      // timerEndPeriod
      case  'e' : fnam =   "timeEndPeriod" ;  err =   timeEndPeriod( ms ) ;
                  break ;
      
      // We should never get here
      default :  mexErrMsgIdAndTxt ( "timeBEPeriod:logic" , "Logical error"
                   "with timeBEPeriod detected, complain to the function's"
                     "author." ) ;
      
    } // switch
    
    // Error calling time*Period function
    if  ( err == TIMERR_NOCANDO )
      mexErrMsgIdAndTxt ( "timeBEPeriod:outofrng" , "ms is out of range" );
    
    // Call was successful, so update res
    switch  ( *BE )
    {
      case  'b' : res =     ms ; break ; // Remember timer resolution
      case  'e' : res = RESNUL ; break ; // Reset res to default value
    }
  
} // timeBEPeriod

