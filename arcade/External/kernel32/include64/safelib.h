#ifndef __safelib_h__
#define __safelib_h__
int ConstraintFailed( const char *fn, const char *reason, void *reserved );
#define __STDC_LIB_EXT1__
#ifndef _ERRNO_T_DEFINED
typedef int errno_t;
#define _ERRNO_T_DEFINED
#endif
#define L_tmpnam_s	512
#ifndef _RSIZE_T_DEFINED
#define _RSIZE_T_DEFINED
typedef unsigned int rsize_t;
#endif
#endif

