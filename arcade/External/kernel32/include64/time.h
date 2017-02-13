/*---------------------------------------------------------------------------*/
/* time.h - date and time header file                                        */
/*---------------------------------------------------------------------------*/
#ifndef __time_h__
#define __time_h__
#ifndef NULL
#define NULL            ((void *)0)
#endif
#define CLOCKS_PER_SEC  100

#ifndef _TIME_T_DEFINED
typedef long time_t;
#define _TIME_T_DEFINED
#endif

#ifndef _CLOCK_T_DEFINED
typedef long clock_t;
#define _CLOCK_T_DEFINED
#endif

#ifndef _SIZE_T_DEFINED
typedef unsigned long long size_t;
#define _SIZE_T_DEFINED
#endif

#ifndef _TM_DEFINED

   /* standard date and time structure tm */
   struct tm
      {
        int tm_sec;      /* seconds after the minute [0-61]        */
        int tm_min;      /* minutes after the hour [0-59]          */
        int tm_hour;     /* hours since midnight [0-23]            */
        int tm_mday;     /* day of the month [1-31]                */
        int tm_mon;      /* months since January [0-11]            */
        int tm_year;     /* years since 1900                       */
        int tm_wday;     /* days since Sunday [0-6]                */
        int tm_yday;     /* days since January 1 [0-365]           */
        int tm_isdst;    /* Daylight Saving Time flag              */
      };
#define _TM_DEFINED
#endif

#include <crtdef.h>

#define _daylight  _crt_base->_crt_daylight
#define _timezone  _crt_base->_crt_timezone
#define _tzname    _crt_base->_crt_tzname


/*---------------------------------------------------------------------------*/
/* function prototpes                                                        */
/*---------------------------------------------------------------------------*/
clock_t clock(void);
time_t mktime(struct tm *tp);
time_t time(time_t *tp);
char *asctime(const struct tm *tp);
char *ctime(const time_t *tp);
struct tm *gmtime(const time_t *tp);
struct tm *localtime(const time_t *tp);
struct tm *localtime_s(const time_t * restrict timer, struct tm * restrict result);
size_t strftime(char *string, size_t smax, const char *fmt,
                const struct tm *tp);
char *_strdate(char *string);
char *_strtime(char *string);
void _tzset(void);
char *_strtime(char *);
char *strtime(char *);
#define strtime _strtime
char *_strdate(char *);
#define strdate _strdate

#endif

