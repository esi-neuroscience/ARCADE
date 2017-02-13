#ifndef _LCC_TIMEB
#define _LCC_TIMEB


#ifndef _TIME_T_DEFINED
typedef long time_t;
#define _TIME_T_DEFINED
#endif
#define timeb	_timeb
/* current definition */
struct timeb {
	time_t time;
	unsigned short millitm;
	short timezone;
	short dstflag;
	};

void _ftime(struct _timeb *);
#endif	/* _LCC_TIMEB */
