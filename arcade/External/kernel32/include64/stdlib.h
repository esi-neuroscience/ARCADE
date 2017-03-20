/*
 * stdlib.h  Definitions for common types, variables, and functions.  */

#ifndef __stdlib_h__
#define __stdlib_h__
#include <stddef.h>
#include <import.h>
#define _MAX_PATH 260
#define _MAX_FNAME	256
#define _MAX_EXT	256
#define _MAX_DRIVE	3
#define _MAX_DIR	256
#define RAND_MAX 0x7FFF
typedef struct {
  int quot; /* quotient */
  int rem; /* remainder */
} div_t;

typedef struct {
  long quot; /* quotient */
  long rem; /* remainder */
} ldiv_t;
typedef struct {
	long long quot;
	long long rem;
} lldiv_t;
#ifndef max
#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))
#endif

#undef NULL
#define NULL ((void *)0)

#ifndef _WCHAR_T_DEFINED
typedef unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif

#undef EXIT_FAILURE
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

#undef RAND_MAX
#define RAND_MAX 0x7fff

void	abort(void);
int	abs(int);
long long llabs(long long);
int __import	atexit(void (*_func)(void));
double	atof(const char *_nptr);
double  __import wtof(const wchar_t *input);
int	atoi(const char *_nptr);
/*long long atoll(char *str);*/
char    *itoa(int,char *,int);
char    *_i64toa(long long,char *,int);
char    *_ui64toa(unsigned long long,char *,int);
long long _atoi64(const char *);
#define atoi64	_atoi64
char	*ltoa(long,char *,int);
char    *_ultoa(unsigned long,char *,int);
#define ultoa _ultoa
#define ultow _ultow
long	atol(char *_nptr);
#include "safelib.h"
typedef void (*constraint_handler_t)( const char * restrict msg, void * restrict ptr, errno_t error);
constraint_handler_t set_constraint_handler_s( constraint_handler_t handler);
constraint_handler_t get_constraint_handler_s( void );
void abort_handler_s( const char * restrict msg, void * restrict ptr, errno_t error);
void ignore_handler_s( const char * restrict msg, void * restrict ptr, errno_t error);
errno_t getenv_s(size_t * restrict len, char * restrict value, rsize_t maxsize, const char * restrict name);
void *bsearch_s(const void *key, const void *base, rsize_t nmemb, rsize_t size, int (*compar)(const void *k, const void *y, void *context), void *context);
errno_t qsort_s(void *base, rsize_t nmemb, rsize_t size, int (*compar)(const void *x, const void *y, void *context), void *context);
errno_t wctomb_s(int * restrict status, char * restrict s, rsize_t smax, wchar_t wc);
errno_t mbstowcs_s(size_t * restrict retval, wchar_t * restrict dst, rsize_t dstmax, const char * restrict src, rsize_t len);
errno_t wcstombs_s(size_t * restrict retval, char * restrict dst, rsize_t dstmax, const wchar_t * restrict src, rsize_t len);

void *	__import bsearch(const void * _key,const void * _base, size_t _nmemb, size_t _size,
		       int (*_compar)(const void *,const void *));
void *	__import calloc(size_t _nmemb, size_t _size);
#if __LCCOPTIMLEVEL > 0
inline div_t __declspec(naked) div(int a,int b)
{
        _asm("\tmovl\t%ecx,%eax");
	_asm("\tmovl\t%edx,%ecx");
        _asm("\tcdq");
        _asm("\tdivl\t%ecx");
	_asm("\tshlq\t$32,%rdx");
	_asm("\torq\t%rax,%rdx");
	_asm("\tmovq\t%rdx,%rax");
}
#else
div_t   div(int _numer, int _denom);
#endif
void	__import exit(int _status);
void	__import _exit(int status);
void	__import free(void *);
char	*__import _fullpath( char *absPath, const char *relPath, size_t maxLength );
void __import _makepath(char *path, const char *drive, const char *dir, const char *fname, const char *ext );
void __import _splitpath(const char*, char*, char*, char*, char*);
char * __import getenv(const char *_string);
long	labs(long);
ldiv_t	ldiv(long _numer, long _denom);
void *	__import malloc(size_t _size);
unsigned long _lrotl(unsigned long,int);
unsigned long _lrotr(unsigned int,int);
void	__import qsort(void * _base, size_t _nmemb, size_t _size, int(*_compar)(const void *, const void *));
int	rand(void);
void *	__import realloc(void * _r, size_t _size);
void	srand(unsigned _seed);
double	strtod(const char *_n, char **_endvoid);
long double strtold(const char *,char **);
long long strtoll(const char *,char **,int);
unsigned long long strtoull(const char *,char **,int);
long	strtol(const char *_n, char **_endvoid, int _base);
unsigned long strtoul(const char *_n, char **_end, int _base);
//__int128 strtoi128(const char *nptr,char ** endptr,int base);
int	system(const char *_string);
int     _System(const char *cmd,int nCmdShow);
int __import putenv(const char *_string);
int __import setenv(char *_string, char *_value, int _overwrite);
char *	_gcvt(double,int,char *);
char *	_fcvt(double,int,int *,int *);
char *	ecvt(double,int,int *,int *);
size_t     mbstowcs(wchar_t *,const char *,size_t);
size_t wcstombs( char *mbstr, const wchar_t *wcstr, size_t count );
int __import mblen(char *,size_t);
int __import mbstrlen(char *s);
extern int __import  _sleep(unsigned long);
#define sleep _sleep
#define	_mbstrlen mbstrlen
void __import _searchenv(char *,char *,char *);
wchar_t * __import _itow (int, wchar_t *, int);
wchar_t *__import  _ltow (long, wchar_t *, int);
unsigned short *__import  _ultow (unsigned long, unsigned short *, int);
double __import  wcstod(const wchar_t *, wchar_t **);
long  __import  wcstol(const wchar_t *, wchar_t **, int);
int __import wctomb(char *s,wchar_t wchar);
unsigned long __import wcstoul(const wchar_t *, wchar_t **, int);
wchar_t *__import  _wgetenv(const wchar_t *);
int  __import   _wsystem(const wchar_t *);
int __import  _wtoi(const wchar_t *);
long __import _wtol(const wchar_t *);
// Contains argv[0]
extern char * __declspec(dllimport) _pgmptr;
#define abs(a) ((a)>=0?a:-(a))
#endif /* _STDLIB_H_ */
