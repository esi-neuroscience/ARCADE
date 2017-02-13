#ifndef __stdio_h__
#define __stdio_h__
#include <import.h>
#ifdef __LCCLIBC__
#pragma dllimport(push,on)
#endif

#ifndef _SIZE_T_DEFINED
typedef unsigned long long size_t;
#define _SIZE_T_DEFINED
#endif

#ifndef _WCHAR_T_DEFINED
typedef unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif

#ifndef _WCTYPE_T_DEFINED
typedef wchar_t wint_t;
typedef wchar_t wctype_t;
#define _WCTYPE_T_DEFINED
#endif

#include <stdarg.h>
//#ifndef _VA_LIST_DEFINED
//typedef char *	va_list;
//#define _VA_LIST_DEFINED
//#endif

#define BUFSIZ	512

#define EOF	(-1)
#define FOPEN_MAX 80

#ifndef USE_MSVCRT
struct __FILE;
typedef struct __FILE FILE;
extern FILE *_Files[];
#define stdin  (_Files[0])
#define stdout (_Files[1])
#define stderr (_Files[2])
#else
#ifndef _FILE_DEFINED
struct _iobuf {
        char *_ptr;
        int   _cnt;
        char *_base;
        int   _flag;
        int   _file;
        int   _charbuf;
        int   _bufsiz;
        char *_tmpfname;
        };
typedef struct _iobuf FILE;
#define _FILE_DEFINED
#endif
__import FILE * __iob_func(void);
#define stdin  (&__iob_func()[0])
#define stdout (&__iob_func()[1])
#define stderr (&__iob_func()[2])
#endif

#ifndef __ANSIC__ONLY__
/* Directory where temporary files may be created. */
#define _P_tmpdir   "\\"
#define _wP_tmpdir  L"\\"
#define L_tmpnam sizeof(_P_tmpdir)+12
#else
#define L_tmpnam 13
#endif

/* Seek method constants */

#define SEEK_CUR    1
#define SEEK_END    2
#define SEEK_SET    0


#define FILENAME_MAX	260
#define TMP_MAX 	32767

/* Define NULL pointer value */
#ifndef NULL
#define NULL	((void *)0)
#endif

/* Define file position type */

#ifndef _FPOS_T_DEFINED
typedef long fpos_t;
#define _FPOS_T_DEFINED
#endif


#define _IOREAD 	0x0001
#define _IOWRT		0x0002

#define _IOFBF		0x0000
#define _IOLBF		0x0040
#define _IONBF		0x0004

#ifndef __ANSIC__ONLY__
#define _IOMYBUF	0x0008
#define _IOEOF		0x0010
#define _IOERR		0x0020
#define _IOSTRG 	0x0040
#define _IORW		0x0080
#define	_IOAPPEND	0x0200
#endif
/*
 * Function prototypes 
 */
void __import clearerr(FILE *);
int __import fclose(FILE *);

int __import feof(FILE *);
int __import ferror(FILE *);
int __import fflush(FILE *);
int __import fgetc(FILE *);
wchar_t __import fgetwc(FILE *);
wchar_t __import getwc(FILE *);
#define getwc fgetwc
int __import _fgetchar(void);
int __import fgetpos(FILE *, fpos_t *);
char * __import fgets(char *, int, FILE *);

FILE * __import fopen(const char *, const char *);
int fprintf(FILE *, const char *, ...);
int __import fputc(int, FILE *);
int __import _fputchar(int);
int __import fputs(const char *, FILE *);
size_t __import fread(void *, size_t, size_t, FILE *);
FILE * __import freopen(const char *, const char *, FILE *);
int fscanf(FILE *, const char *, ...);
int __import fsetpos(FILE *, const fpos_t *);
int __import fseek(FILE *,long long, int);
long long __import ftell(FILE *);
size_t __import fwrite(const void *, size_t, size_t, FILE *);
int __import getc(FILE *);
int __import getchar(void);
char * __import gets(char *);
int __import getw(FILE *);
int printf(const char *, ...);
int dprintf(const char *, ...);
int __import putc(int, FILE *);
int __import putchar(int);
int __import puts(const char *);
int __import remove(const char *);
int __import rename(const char *,const char *);
void rewind(FILE *);
int scanf(const char *, ...);
void __import setbuf(FILE *, char *);
int __import setvbuf(FILE *, char *, int, size_t);
int sprintf(char *, const char *, ...);
int snprintf(char *,size_t,const char *,...);
int sscanf(const char *, const char *, ...);
FILE * __import tmpfile(void);
char * __import tmpnam(char *);
char *__import tempnam(char *,char *);
int __import ungetc(int, FILE *);
int vfprintf(FILE *, const char *, va_list);
int vprintf(const char *, va_list);
int vsnprintf(char *,size_t,const char *,va_list);
int vsprintf(char *, const char *, va_list);
void __import perror(char *);
void __import _wperror(const wchar_t *);

#include "safelib.h"
errno_t tmpfile_s(FILE * restrict * restrict streamptr);
errno_t tmpnam_s(char *s, rsize_t maxsize);
errno_t fopen_s(FILE * restrict * restrict streamptr, const char * restrict filename, const char * restrict mode);
errno_t freopen_s(FILE * restrict * restrict newS, const char * restrict fname, const char * restrict m, FILE * restrict s);
int fprintf_s(FILE * restrict stream, const char * restrict format, ...);
int fscanf_s(FILE * restrict stream, const char * restrict format, ...);
int printf_s(const char * restrict format, ...);
int scanf_s(const char * restrict format, ...);
int snprintf_s(char * restrict s, rsize_t n, const char * restrict format, ...);
int sprintf_s(char * restrict s, rsize_t n, const char * restrict format, ...);
int sscanf_s(const char * restrict s, const char * restrict format, ...);
int vfprintf_s(FILE * restrict stream, const char * restrict format, va_list arg);
int vfscanf_s(FILE * restrict stream, const char * restrict format, va_list arg);
int vprintf_s(const char * restrict format, va_list arg);
int vscanf_s(const char * restrict format, va_list arg);
int vsnprintf_s(char * restrict s, rsize_t n, const char * restrict format, va_list arg);
int vsprintf_s(char * restrict s, rsize_t n, const char * restrict format, va_list arg);
int vsscanf_s(const char * restrict s, const char * restrict format, va_list arg);
char *gets_s(char *s, rsize_t n);

#ifndef __ANSIC__ONLY__
#ifndef MAX_PATH
#define MAX_PATH	260
#endif
#define TMP_MAX	32767
#ifndef MAX_FNAME
#define MAX_FNAME	256
#endif
int __import fcloseall(void);
int __import _filbuf(FILE *);
int __import flsbuf(int, FILE *);
FILE * __import _fsopen(const char *, const char *, int);
int __import _fcloseall(void);
FILE * __import fdopen(int, const char *);
int __import fileno(FILE *);
#define _fileno fileno

int __import _flushall(void);
int __import _pclose(FILE *);
#define pclose _pclose
FILE * __import popen(const char *, const char *);
int __import _putw(int, FILE *);
int _vsnprintf(char *, size_t, const char *, va_list);
int _vsnwprintf(wchar_t *, size_t, const wchar_t *, va_list);
int __import _unlink(const char *);
int _snprintf(char *, size_t, const char *, ...);
char * __import _tempnam(char *, char *);
void *__import _get_osfhandle(int);
int __import _rmtmp(void);
#define unlink remove
/*
#ifndef STD_INPUT_HANDLE
#define STD_INPUT_HANDLE   ((unsigned long long)-10)
#define STD_OUTPUT_HANDLE ((unsigned long long)-11)
#define STD_ERROR_HANDLE  ((unsigned long long)-12)
#endif
*/
#endif // __stdio_h__

#ifdef __LCCLIBC__
#pragma dllimport(pop)
#endif

#endif
