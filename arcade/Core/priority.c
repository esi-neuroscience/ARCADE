
/*  [ ... ] = priority( cmd , ... )
 *  
 *  Query or change the priority level of specified processes. cmd is a
 *  single char used to select the form and action of the function:
 *  
 *    [ pid , exe ] = priority( 'i' , names )
 *
 *      Find processes that have executables listed in names, a cell array
 *      of strings. Returns pid, a uint32 row vector of their process
 *      identifiers.
 *      
 *      It is possible that pid has more entries than names. This can
 *      happen when the same executable is running in multiple processes.
 *      Hence, cell array of strings exe is also returned. It names the
 *      executable of each process identified in pid.
 *      
 *      In order to get the process identifier of the current process that
 *      is calling priority( ), include an empty string i.e. '' in names.
 *      The corresponding identifier pid( end ) will contain something like
 *      'MATLAB.exe' in exe{ end }.
 *      
 *      Any string in names that does not match the executable of any
 *      visible process is quietly ignored. If no processes are found then
 *      pid and exe is empty i.e. [ ] and { }.
 *      
 *      Example: pid = priority( 'i' , { '' , 'DaqServer.m' ,
 *                 'EyeLinkServer.exe' , 'StimServer.exe' } ) ;
 *      
 *    [ pc , exe ] = priority( 'g' , pid )
 *      
 *      Get the priority class of processes with process identifiers given
 *      in uint32 row vector pid. Returns uint32 row vector pc containing
 *      the priority class of each process. pc is in register with pid. exe
 *      contains cell array of strings in register with pid and pc; each
 *      string is the name of the executable file running on each process.
 *      Compare exe from priority( 'i' ) and priority( 'g' ) for additional
 *      error checking. Process identifiers can be recycled. It is not
 *      impossible that a process may be closed, and that its PID becomes
 *      reassigned to a new process running a different executable.
 *    
 *    res = priority( 's' , pid , exe , pcname )
 *      
 *      Set the priority class for processes with process identifiers given
 *      in uint32 row vector pid. exe is a cell array of strings in
 *      register with pid that names the executable file of each process.
 *      The function will check that the current executable names match the
 *      contents of exe. See priority( 'g' ) help (above) for rationale.
 *
 *      The new priority level is named in pcname which must be one of the
 *      following strings:
 *      
 *        'ABOVE_NORMAL_PRIORITY_CLASS'
 *        'BELOW_NORMAL_PRIORITY_CLASS'
 *                'HIGH_PRIORITY_CLASS'
 *                'IDLE_PRIORITY_CLASS'
 *              'NORMAL_PRIORITY_CLASS'
 *      
 *      res is a logical row vector in register with pid that is true for
 *      each process that was successfully set to the new priority class.
 *    
 *    res = priority( 's' , pid , exe , pc )
 *      
 *      Alternatively, instead of pcname, pc can be a uint32 row vector in
 *      register with pid that provides the desired priority class for
 *      each process. This allows different priority classes to by assigned
 *      to each process identified by pid.
 *    
 *     pc = priority( 'c' , pcname )
 *      
 *      Return scalar uint32 value of the priority class named in pcname.
 *      pcname must be one of the strings listed for priority( 's' , ... ).
 *      If pcname is not found in the list then pc is empty.
 *    
 *  This function is specific to Windows.
 *
 *  Compile with >> mex -R2018a '-LC:\Program Files\MATLAB\R2018b\sys\
 *    lcc64\lcc64\lib64' -lPsapi priority.c
 *
 *  For more information, see: https://docs.microsoft.com/en-us/windows/
 *    win32/procthread/process-and-thread-functions
 *  
 *  Written by Jackson Smith - Dec 2021 - Fries Lab (ESI Frankfurt)
 *  
 */


/*** Include block ***/

  // Matlab APIs
  #include       "mex.h"
  #include    "matrix.h"

  // OS API
  #include   <windows.h>
  #include  <tlhelp32.h>
  #include     <psapi.h>

  // C standard library
  #include    <string.h>


/*** Define block ***/
  
  // Input arg indices in prhs
  #define  I_CMD       0
  #define  I_NAMES_I   1
  #define  I_PCNAME_C  1
  #define  I_PID_G     1
  #define  I_PID_S     1
  #define  I_EXE_S     2
  #define  I_PC_S      3

  // Output arg indices in plhs
  #define  O_PC_C   0
  #define  O_PID_I  0
  #define  O_EXE_I  1
  #define  O_PC_G   0
  #define  O_EXE_G  1
  #define  O_RES_S  0

  // Number of input args by cmd
  #define  NARGIN_I  2
  #define  NARGIN_C  2
  #define  NARGIN_G  2
  #define  NARGIN_S  4

  // Max number of output args by cmd
  #define  NARGOUT_I  2
  #define  NARGOUT_C  1
  #define  NARGOUT_G  2
  #define  NARGOUT_S  1

  // priority( 's' ... pc* ) input arg pc conditions for pcflag
  #define  PCISCHAR  0
  #define  PCISUINT  1
  
  // Number of priority classes
  #define  NUMPCS  6


/*** MACRO block ***/

  // Check for correct number of input (nin) and output (nout) args for
  // cmd string cch. Give cch in double quotes so that it concatenates with
  // the error id string in mexErrMsgIdAndTxt( ).
  #define  NARGSCHK( nin , nout , cch )                    \
                                                           \
            if  ( nrhs != nin )                            \
              mexErrMsgIdAndTxt ( "priority:" cch "nrhs" , \
                "Expecting %d input args" , nin ) ;        \
                                                           \
            if  ( nlhs > nout )                            \
              mexErrMsgIdAndTxt ( "priority:" cch "nlhs" , \
                "Too many output args" ) ;

  // Declare variables for system call error handling. errflg triggers
  // additional error handling. err stores return value of GetLastError.
  // errnam points to local constant string naming the system call.
  #define  ERRDEC  char   errflg ; \
                   DWORD     err ; \
                   char * errnam ;
	
  // Initialise variables for system call error handling.
  #define  ERRINI  errflg = 0    ; \
                      err = 0    ; \
                   errnam = NULL ;
  
  // Error handling macro following Windows system call error
  #define  ERRMAC( fnam , label )          \
             {                             \
               errflg = 1 ;                \
                  err = GetLastError ( ) ; \
               errnam = fnam ;             \
               goto  label ;               \
             }


/** Error handling variables **/

	// Declare them for all local functions to see
  ERRDEC


/** Priority class **/ 

  // Names
  const char * LEVNAM[ ] = { "ABOVE_NORMAL_PRIORITY_CLASS" ,
                             "BELOW_NORMAL_PRIORITY_CLASS" ,
                                     "HIGH_PRIORITY_CLASS" ,
                                     "IDLE_PRIORITY_CLASS" ,
                                   "NORMAL_PRIORITY_CLASS" ,
                                 "REALTIME_PRIORITY_CLASS" } ;

  // Numeric values
  const DWORD  LEVVAL[ ] = { ABOVE_NORMAL_PRIORITY_CLASS ,
                             BELOW_NORMAL_PRIORITY_CLASS ,
                                     HIGH_PRIORITY_CLASS ,
                                     IDLE_PRIORITY_CLASS ,
                                   NORMAL_PRIORITY_CLASS ,
                                 REALTIME_PRIORITY_CLASS } ;


/*** Function prototypes ***/
	
  // Find numeric value of named priority class. Returns zero if nothing
  // found.
  DWORD  prival ( char * ) ;
  
  // Find processes with matching names
  mxUint64  findproc ( HANDLE , mxUint64 , char ** , char * , mxUint64 ,
                       DWORD * , mwSize * ) ;
  
  // Scan backwards along char buffer to find first path delimiter
  // character + 1
  char * getexe ( DWORD , char * , char ) ;


/*** priority( ) main function ***/

void  mexFunction ( int nlhs ,       mxArray ** plhs ,
                    int nrhs , const mxArray ** prhs )
{ 
  
  /** cmd arg check **/
  
  // No args
  if  ( nrhs < 1 )
    mexErrMsgIdAndTxt ( "priority:noargs" , "No input argument provided" );
  
  // cmd must be char array
  if  ( !mxIsChar( prhs[ I_CMD ] ) )
    mexErrMsgIdAndTxt ( "priority:cmdchar" , "cmd must be type char" ) ;
  
  // Need just one character in cmd
  if  ( !mxIsScalar( prhs[ I_CMD ] ) )
    mexErrMsgIdAndTxt ( "priority:cmdscalar" , "cmd must be scalar" ) ;
  
  
  /** Initialise error handling variables **/
  
  ERRINI
  
  
  /** Strings with heap memory allocation
  
  Several sub-functions require the conversion of input argument strings
  into C style strings. To do so, heap memory is used. These are generic
  variables for creating and tracking converted strings. All heap memory
  requested within priority() is released before returning. In the event of
  an error, Matlab will release the heap memory, because the Matlab memory
  manager is used to get it. **/
  
  // Generic counter variable and number of stings (none yet). Note, mwSize
  // is unsigned!
  mwSize  i , numstr ;  numstr = 0 ;
  
  // Pointer to array of strings
  char ** str = NULL ;
  
  
  /** Evaluate cmd **/
  
  // Point to character
  mxChar * pcmd = mxGetChars ( prhs[ I_CMD ] ) ;
  
  // Choose function based on its value. Put most urgent functions first.
  switch ( *pcmd )
  {
    
    /* Set priority class(es) */
    
    case  's' :
    {
      /* Input arg check */
      
      // Number of input and output args
      NARGSCHK( NARGIN_S , NARGOUT_S , "s" )
      
      // pid is empty, return empty
      if  (  mxIsEmpty( prhs[ I_PID_S ] )  )
        { plhs[ O_RES_S ] = mxCreateLogicalMatrix ( 0 , 0 ) ;  return ; }
      
      // Number of elements in pid
      size_t  pidnum = mxGetNumberOfElements ( prhs[ I_PID_S ] ) ;
      
      // pid must be uint32
      if  (  !mxIsUint32( prhs[ I_PID_S ] )  )
        mexErrMsgIdAndTxt ( "priority:spidtype" , "pid must be uint32" ) ;
      
      // No complex values allowed
      if  (  mxIsComplex( prhs[ I_PID_S ] )  )
        mexErrMsgIdAndTxt ( "priority:spidcomplex" , "pid is complex" ) ;
      
      // pid is correct type and is not empty, point to numerical values
      mxUint32 * pid = mxGetUint32s ( prhs[ I_PID_S ] ) ;
      
      // exe must be cell array
      if  ( !mxIsCell( prhs[ I_EXE_S ] ) )
        mexErrMsgIdAndTxt( "priority:sexecell", "exe must be cell array" );
      
      // exe must have same number of elements as pid
      if  ( pidnum != mxGetNumberOfElements( prhs[ I_EXE_S ] ) )
        mexErrMsgIdAndTxt ( "priority:sexenum" , "pid and exe have unequal"
          " number of elements" ) ;
      
      // Pointer to arrays inside exe
      mxArray * pcell = NULL ;
      
      // Allocate array of char pointers, we will convert mxChar arrays
      // from exe{ : } into C style char strings
      str = mxCalloc ( pidnum , sizeof( char * ) ) ;
      
      // Cells in exe
      for  ( i = 0 ; i < pidnum ; ++i )
      {
        // Point to contents of (i+1)-th cell
        pcell = mxGetCell ( prhs[ I_EXE_S ] , i ) ;
        
        // exe{ i+1 } is NOT mxChar array. NOTE, Matlab will deallocate str
        // and all str[ 0 .. i - 1 ] upon return to command line.
        if  ( !mxIsChar( pcell ) )  mexErrMsgIdAndTxt( "priority:sexechar",
                                      "exe{ %d } is not char" , ++i ) ;
        
        // Convert from mxChar array to C style string
        str[ i ] = mxArrayToString ( pcell ) ;
      }
      
      // Input arg pc* type flag , string or numeric vector?
      char  pcflag ;
      
      // Pointer to mxUint32 array
      mxUint32 * pc = NULL ;
      
      // Check type of pc* input argument. First, is pcname a mxChar array?
      if  (  mxIsChar( prhs[ I_PC_S ] )  )
      {
        // Set pc type flag
        pcflag = PCISCHAR ;
        
        // Convert mxChar array to C style char string
        char * pcname = mxArrayToString ( prhs[ I_PC_S ] ) ;
        
        // Look up numeric value of named priority class
        DWORD pcval = prival ( pcname ) ;
        
          // Free string memory
          mxFree ( pcname ) ;
        
        // Invalid priority class string
        if  ( !pcval )
          mexErrMsgIdAndTxt ( "priority:spcstring" , "pcname invalid" ) ;
        
        // Realtime priority is NOT allowed
        if  ( pcval == REALTIME_PRIORITY_CLASS )
          mexErrMsgIdAndTxt ( "priority:spcillegal" , "pcname may not be "
            "REALTIME_PRIORITY_CLASS" ) ;
        
        // Allocate array with one element per process listed in pid
        pc = mxMalloc ( pidnum * sizeof( mxUint32 ) ) ;
        
        // Copy numeric value of named priority class
        for  ( i = 0 ; i < pidnum ; ++i )  pc[ i ] = pcval ;
      }
      
      // Is pc a uint32 array?
      else if  (  mxIsUint32( prhs[ I_PC_S ] )  )
      {
        // Set pc type flag
        pcflag = PCISUINT ;
        
        // Check for complex value
        if  ( mxIsComplex( prhs[ I_PC_S ] ) )
          mexErrMsgIdAndTxt ( "priority:spccomplex" , "pc is complex" ) ;
        
        // Check size of pc
        if  ( pidnum != mxGetNumberOfElements( prhs[ I_PC_S ] ) )
          mexErrMsgIdAndTxt ( "priority:spcnum" , "pid and pc have unequal"
            " number of elements" ) ;
        
        // Point to new priority class values
        pc = mxGetUint32s ( prhs[ I_PC_S ] ) ;
        
        // Priority class array index
        int  v ;
        
        // Elements of pc
        for  ( i = 0 ; i < pidnum ; ++i )
        {
          // Search for valid priority class value
          for  ( v = 0 ; v < NUMPCS && pc[ i ] != LEVVAL[ v ] ; ++v ) ;
          
          // None found
          if  ( v == NUMPCS )  mexErrMsgIdAndTxt ( "priority:spcinvalid" ,
           "pc[ %d ] does not contain a valid priority class value", ++i );
          
          // Realtime priority is NOT allowed
          if  ( pc[ i ] == REALTIME_PRIORITY_CLASS )
            mexErrMsgIdAndTxt ( "priority:spcillegal" ,
              "pc[ %d ] may not be REALTIME_PRIORITY_CLASS" , ++i ) ;
        }
      }
      
      // Invlaid type
      else  mexErrMsgIdAndTxt
                     ( "priority:spctype" , "pc must be char or uint32" ) ;
      
      
      /* Set new priority level(s) */
      
      // Pointer to opened process
      HANDLE  process = NULL ;
      
      // Executable filename buffer and returned path length
       char  buf[ MAX_PATH ] ; 
      DWORD  bufnum = 0 ;
      
      // Allocate output arg res, initialised to logical 0 i.e. false
      plhs[ O_RES_S ] = mxCreateLogicalMatrix ( 1 ,pidnum ) ;
      
      // Point to logical values
      mxLogical * res = mxGetLogicals ( plhs[ O_RES_S ] ) ;
      
      // Processes
      for  (  i = 0 ; i < pidnum ; ++i )
      {
        // Retrieve process handle
        process = OpenProcess ( PROCESS_ALL_ACCESS , FALSE , pid[ i ] ) ;
        
          // Error
          if  ( process == NULL )  ERRMAC( "s :: OpenProcess" , cleanup_s )
          
        // Get executable file path of the process
        bufnum = GetProcessImageFileName ( process , buf , MAX_PATH ) ;
        
         // Error
         if ( !bufnum ) ERRMAC( "s :: GetProcessImageFileName", cleanup_s )
        
        // Process executable file name does NOT match what is expected
        if  (  strcmp( str[ i ] , getexe( bufnum, buf, '\\' ) )  )
          ERRMAC( "s :: executable name mismatch" , cleanup_s )
        
        // Change process priority, record success
        res[ i ] = SetPriorityClass( process , pc[ i ] ) ? 1 : 0 ;
        
        // Close process handle
        CloseHandle ( process ) ;
        
      } // processes
      
      
      /* Error handling jumps here */
      
      cleanup_s:
      
        
      /* Release allocated resources */
      
      if  (  pcflag == PCISCHAR )       mxFree ( pc )      ;
      if  ( process != NULL     )  CloseHandle ( process ) ;
      
      
      /* Finished setting new priority class(es) */
      
      break ;
    }
    
    
    /* Get priority classes */
    
    case  'g' :
    {
      /* Input arg check */
      
      // Number of input and output args
      NARGSCHK( NARGIN_G , NARGOUT_G , "g" )
      
      // Number of elements in pid
      size_t  pidnum = mxGetNumberOfElements ( prhs[ I_PID_G ] ) ;
      
      // pid is empty
      if  ( !pidnum )
      {
        // Return empty
        plhs[ O_PC_G ] = mxCreateUninitNumericMatrix
                                      ( 0 , 0 , mxUINT32_CLASS , mxREAL ) ;
        
        // exe requested
        if  ( nlhs > 1 )  plhs[ O_EXE_G ] = mxCreateCellMatrix ( 0 , 0 ) ;
        
        // Done
        return ;
      }
      
      // pid must be uint32
      if  ( !mxIsUint32( prhs[ I_PID_G ] ) )
        mexErrMsgIdAndTxt ( "priority:gtype", "pid must be uint32" ) ;
      
      // pid cannot be complex
      if  ( mxIsComplex( prhs[ I_PID_G ] ) )
        mexErrMsgIdAndTxt ( "priority:gcomplex", "pid can't be complex" ) ;
      
      
      /* Allocations */
      
      // Point to numeric content of input arg pid
      mxUint32 * pid = mxGetUint32s ( prhs[ I_PID_G ] ) ;
      
      // Allocate output arg pc
      plhs[ O_PC_G ] = mxCreateUninitNumericMatrix
                                 ( 1 , pidnum , mxUINT32_CLASS , mxREAL ) ;
      
      // Point to numeric values of pc
      mxUint32 * pc = mxGetUint32s ( plhs[ O_PC_G ] ) ;
      
      // Allocate a handle pointer for accessing each process
      HANDLE  process = NULL ;
      
      // exe requested. Allocate cell array and ...
      if  ( nlhs > 1 )  plhs[ O_EXE_G ] = mxCreateCellMatrix( 1 , pidnum );
      
      // ... file path buffer, ...
       char  buf[ MAX_PATH ] ; 
      DWORD  bufnum = 0 ; // ... number of char in buf, and ...
      mxArray * pcell ; // ... pointer to exe mxChar array.
      
      /* Retrieve priority classes */
      
      // Process identifiers
      for  ( i = 0 ; i < pidnum ; ++i )
      {
        // Retrieve process handle
        process = OpenProcess ( PROCESS_ALL_ACCESS , FALSE , pid[ i ] ) ;
        
          // Error
          if  ( process == NULL )  ERRMAC( "g :: OpenProcess" , cleanup_g )
        
        // Get the current priority level for this process
        pc[ i ] = GetPriorityClass ( process ) ;
    
          // Error
          if  ( !pc[ i ] )  ERRMAC( "g :: GetPriorityClass" , cleanup_g )
          
        // exe requested
        if  ( nlhs > 1 )
        {
          // Get executable path of this process
          bufnum = GetProcessImageFileName ( process , buf , MAX_PATH ) ;
          
            // ERROR
            if  ( !bufnum )
              ERRMAC( "g :: GetProcessImageFileName" , cleanup_g )
        }
        
        // Release process handle before risking Matlab error
        CloseHandle ( process ) ;  process = NULL ;
        
        // exe requested
        if  ( nlhs > 1 )
        {
          // Convert exe from char string to mxChar array
          pcell = mxCreateString (  getexe( bufnum , buf , '\\' )  ) ;
          
          // Assign to contents of exe{ i + 1 }
          mxSetCell ( plhs[ O_EXE_G ] , i , pcell ) ;
        }
      } // end process IDs
      
      
      /* Jump here when error detected */
          
      cleanup_g:
        
      
      /* Release allocated resources */
      
      if  ( process != NULL )  CloseHandle ( process ) ;
      
      
      /* Done retrieving process priority classes */
        
      break ;
    }
    
    /* Return numeric value of named priority class */
    
    case  'c' :
    {
      /* Input arg check */
      
      // Number of input and output args
      NARGSCHK( NARGIN_C , NARGOUT_C , "c" )
      
      // Check that pcname is a char array
      if  ( !mxIsChar( prhs[ I_PCNAME_C ] ) )
        mexErrMsgIdAndTxt ( "priority:cchar", "pcname must be type char" );
      
      /* Convert string from Matlab to C */
      
      // Allocate single element char pointer array
      str = mxCalloc ( 1 , sizeof( char * ) ) ;
      
      // Convert string mxChar to simple char, count one more string
      str[ 0 ] = mxArrayToString ( prhs[ I_PCNAME_C ] ) ;  ++numstr ;
      
      /* Find numeric value of named priority class */
      
      // Get numeric value of named class
      mxUint32  pc = prival ( str[ 0 ] ) ;
      
      // Create return arg. Empty if pc = 0 (nothing found) else scalar.
      plhs[ O_PC_C ] = mxCreateUninitNumericMatrix
                    ( pc ? 1 : 0 , pc ? 1 : 0 , mxUINT32_CLASS , mxREAL ) ;
      
      // Found priority class value, assign to output arg numeric value
      if  ( pc )  *( mxGetUint32s( plhs[ O_PC_C ] ) ) = pc ;
      
      /* Done returning numeric value of priority class */
                    
      break ;
    }
      
    /* Find process identifiers */
      
    case  'i' :
    {
      /* Input arg check */
      
      // Number of input and output args
      NARGSCHK( NARGIN_I , NARGOUT_I , "i" )
      
      // Initialise output arguments with empty arrays
      
        // pid is [ ]
        plhs[ O_PID_I ] = mxCreateUninitNumericMatrix ( 0 , 0 , 
          mxUINT32_CLASS , mxREAL ) ;
        
        // exe also requested, it is { }
        if  ( nlhs > 1 )  plhs[ O_EXE_I ] = mxCreateCellMatrix ( 0 , 0 ) ;
      
      // Names is empty, return empties
      if  ( mxIsEmpty( prhs[ I_NAMES_I ] ) )  return ;
      
      // names must be a cell array
      if  ( !mxIsCell( prhs[ I_NAMES_I ] ) )
        mexErrMsgIdAndTxt ( "priority:inames", "names is not cell array" );
      
      // Prepare variables needed for error checking contents of names.
      // These will also come in handy later during process search.
        
        // Number of elements in names cell array
        mwSize  namnum = mxGetNumberOfElements( prhs[ I_NAMES_I ] ) ;

        /* Tracks which elements of names are non-empty, in register with
        names. Non-zero value indicates non-empty string in names. Note,
        Matlab heap memory is freed by Matlab after error is thrown. */
        char * nempty = mxMalloc ( namnum * sizeof( char ) ) ;
        
        /* Allocate memory for array of C style char strings i.e. an array
        of char pointers, to be converted from the non-empty contents of
        each cell. Note, this is freed after the master switch statement.
        The number of strings that will be allocated is copied. */
        str = mxCalloc ( ( numstr = namnum ) , sizeof( char * ) ) ;
        
        /* Raise this flag (non-zero) if any empty strings found, trigger
        the return of the calling process identifier */
        char  pidflg = 0 ;
        
        /* Take this opportunity to allocate null pointers for pid and
        index buffers, because these will be checked following cleanup_i */
         DWORD *  pid = NULL ;
        mwSize * inam = NULL ;
        
        // Handy dandy pointer to contents of one cell in names
        mxArray * pcell = NULL ;
      
      // Each cell of names
      for  ( i = 0 ; i < namnum ; ++i )
      {
        // Point to contents of ith cell
        pcell = mxGetCell ( prhs[ I_NAMES_I ] , i ) ;
        
        // Check that cell contains a string
        if  ( !mxIsChar( pcell ) )
          mexErrMsgIdAndTxt ( "priority:inames_notchar", "names{ %d } is "
            "not char array" , ++i ) ;
        
        /* Convert from mxChar array to C char string. This allocates
        Matlab heap memory that is freed after the master switch. */
        str[ i ] = mxArrayToString ( pcell ) ;
        
        // String is non-empty
        nempty[ i ] = !mxIsEmpty ( pcell ) ;
        
        // Update self PID flag. Return PID of calling process if empty.
        pidflg = pidflg  ||  !nempty[ i ] ;
        
      } // cells of names
      
      
      /* Generate a snapshot of all visible processes on local system */
      
      // Get information about all processes running on this system
      HANDLE  snapshot = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );

        // Failure to get snapshot
        if  ( snapshot == INVALID_HANDLE_VALUE )

          ERRMAC( "i :: CreateToolhelp32Snapshot" , cleanup_i )
      
      
      /* Search processes */
      
      // Count the number of processes with executables listed in names
      mxUint64  pidnum = findproc ( snapshot , namnum , str , nempty ,
                                                        0 , NULL , NULL ) ;
      
        // Error during search
        if  ( errflg )  goto  cleanup_i ;
      
      // We found one or more matching processes
      if  ( pidnum )
      {
        // Now we can allocate pid and inam buffers, given process count
         pid = mxMalloc ( pidnum * sizeof(  DWORD ) ) ;
        inam = mxMalloc ( pidnum * sizeof( mwSize ) ) ;
        
        // Find process id's and exec names for matching processes
        if  ( pidnum  !=  findproc
               ( snapshot , namnum , str , nempty , pidnum , pid , inam ) )
          
          ERRMAC( "Inconsistent process count from findproc" , cleanup_i )
          
          // Error during search
          if  ( errflg )  goto  cleanup_i ;
        
      } // found matching processes
      
      
      /* Pack output arguments */
      
      // Compute the total length of the output argument(s)
      mwSize  outnum = pidnum  +  ( ( pidflg ) ? 1 : 0 ) ;
      
      // Output is empty, skip to the end
      if  ( !outnum )  goto cleanup_i ;
      
      // Simplest to destroy default empty arrays, instead of reshaping
      mxDestroyArray ( plhs[ O_PID_I ] ) ;
      if  ( nlhs > 1 )  mxDestroyArray ( plhs[ O_EXE_I ] ) ;

      // Re-allocate output arrays of appropriate size
      plhs[ O_PID_I ] = mxCreateUninitNumericMatrix
                               ( 1 , outnum , mxUINT32_CLASS , mxREAL ) ;
      if  ( nlhs > 1 )  plhs[ O_EXE_I ] = mxCreateCellMatrix( 1 , outnum );

      // Point to numeric content of output arg pid
      mxUint32 * pidout = mxGetUint32s ( plhs[ O_PID_I ] ) ;

      // Matching processes, not including the calling process
      for  ( i = 0 ; i < pidnum ; ++i )
      {
        // Copy process identifier
        pidout[ i ] = pid[ i ] ;

        // Output arg exe requested
        if  ( nlhs > 1 )
        {
          // Convert exe name from C char string to mxChar array
          pcell = mxCreateString ( str[ inam[ i ] ] ) ;

          // Assign to exe{ i + 1 }
          mxSetCell ( plhs[ O_EXE_I ] , i , pcell ) ;
        }
      }

      // Return PID of calling process
      if  ( pidflg )
      {
        // Final element of output array(s), pid( end ) and exe{ end }
        i = outnum - 1 ;

        // PID of calling process
        pidout[ i ] = GetCurrentProcessId ( ) ;
        
        // Output arg exe NOT requested
        if  ( nlhs < 2 )  goto cleanup_i ;
        
        // Buffer for executable name
        char  buf[ MAX_PATH ] ;
        
        // Get full executable path/name
        DWORD  bufnum = GetModuleFileName ( NULL , buf , MAX_PATH ) ;
        
          // ERROR
          if  ( !bufnum )  ERRMAC( "i :: GetModuleFileName" , cleanup_i )

        // Convert exe name from C char string to mxChar array
        pcell = mxCreateString ( getexe( bufnum , buf , '\\' ) ) ;
        
        // Return executable name of calling procecss
        mxSetCell ( plhs[ O_EXE_I ] , i , pcell ) ;
      }
      
      
      /* Jump here when error detected */
          
      cleanup_i:
        
        
      /* Free 'i' specific dynamic memory and other resources */
        
        // Dynamic mem
        mxFree ( nempty ) ;
        if  (  pid != NULL )  mxFree (  pid ) ;
        if  ( inam != NULL )  mxFree ( inam ) ;
        
        // System resources
        if  ( snapshot != INVALID_HANDLE_VALUE )  CloseHandle( snapshot ) ;
      
      
      /* Done finding process identifiers */
      
      break ;
    }
    
    /* Invalid option */
    
    default:  mexErrMsgIdAndTxt ( "priority:cmdbad" , "cmd is invalid" ) ;
    
  } // end master switch statement
  
  /** Free C string memory **/
  
  // Each string
  for  ( i = 0 ; i < numstr ; ++i )  mxFree ( str[ i ] ) ;
  
  // Array of pointers
  if  ( str != NULL )  mxFree ( str ) ;
  
  
  /** Error handling **/
  
  // Crudely bring the system crashing down
  if  ( errflg )
    mexErrMsgIdAndTxt ( "priority:system_error" , "%s :: error code %d" ,
      errnam , err ) ;
  
  
} // end priority( )


/*** Sub-functions ***/

// Find numeric value of named priority class. Returns zero if nothing 
// found.
DWORD  prival ( char * pcnam )
{
  // Counter variable
  int  i ;
  
  // Scan list, quit if we find something
  for ( i = 0 ; i < NUMPCS && strcmp( pcnam , LEVNAM[ i ] ) ; ++i ) ;
  
  // Return 0 is nothing found, else return priority class numeric value
  return  ( i == NUMPCS ) ? 0 : LEVVAL[ i ] ;
  
} // end prival( )


/* Search for all processes with an executable matching one of the namnum
   strings in names. names[ i ] is non-empty if nempty[ i ] is non-zero.
   OS process information given in snapshot. Process identifiers of
   matching processes are returned in pid, as well as the index of the
   matching executable string in names in inam. Thus, the ith process has
   PID pid[ i ] and executable name names[ inam[ i ] ]. Returns the total
   number of matching processes found; if pidnum is zero then only this
   count is returned while pid and inam are ignored (set to NULL). pidnum
   gives the size of buffers pid and inam. If this overflows or the number
   returned by findproc does not match pidnum then an error is triggered.
 */
mxUint64  findproc ( HANDLE snapshot ,
                     mxUint64 namnum , char ** names , char * nempty ,
                     mxUint64 pidnum , DWORD * pid , mwSize * inam )
{
  
  /* Variables */
  
  // Count matching processes here
  mxUint64  pidcnt = 0 ;
  
  // names incrementing variable
  mxUint64  i ;
  
  // Structure for retreiving process information
  PROCESSENTRY32  pinfo ;
  
    // Set structure's size ... system/version specific?
    pinfo.dwSize = sizeof ( PROCESSENTRY32 ) ;
  
  
  /* Initialise process list */
  
  if  ( !Process32First( snapshot , &pinfo ) )
    ERRMAC( "Process32First" , cleanup )
    
  
  /* Step through process list */
  
  do
  {
    
    // Search for name that matches executable
    for  ( i = 0 ; i < namnum ; ++i )
      if  ( nempty[ i ] && !strcmp( names[ i ] , pinfo.szExeFile ) )
        break ;
    
    // Executable not matched by any string in names, check next process
    if  ( i == namnum )  continue ;
    
    // PID and index buffer provided and process count within array range
    if  ( pidnum  &&  pidcnt < pidnum )
    {
       pid[ pidcnt ] = pinfo.th32ProcessID ;
      inam[ pidcnt ] = i                   ;
    }
    
    // Count one more process
    ++pidcnt ;
    
  }
  while ( Process32Next( snapshot , &pinfo ) ) ;
  
    
  /* Error jumps here */
  
  cleanup:
  
  
  /* Return number of matching processes */
  
  return  pidcnt ;
  
  
} // end findproc( )


/* Scan backwards in filename path buffer buf, starting at buf[ n - 1 ] and
   look for the final instance of path delimiter del in the string. Let
   buf[ i ] contain the final instance of del, then the function returns
   a pointer to the very next character i.e. buf + i + 1. n should be the
   length of the string excluding the final NULL character. It is assumed
   that buf contains a path as returned by GetModuleFileName( ) etc.
*/
char * getexe ( DWORD n , char * buf , char del )
{
  
  // Scan backwards. If n is non-zero then decrement n by 1, then fetch the
  // nth character in the buffer and test it against the delimiter.
  while  ( n && buf[ --n ] != del ) ;
  
  // Return pointer to first character following the last delimiter.
  return  buf + n + 1 ;
  
} // getexe

