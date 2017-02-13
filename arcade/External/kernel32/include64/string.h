/* string.h * Definitions for memory and string functions.  */
#ifndef __string_h__
#define	__string_h__
#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
typedef unsigned long long size_t;
#endif
#ifndef NULL
#define NULL ((void *)0)
#endif
void *	 memchr(const void *, int, size_t);
#ifndef __ANSIC__ONLY__
short *  memshort(const short *,short,size_t);
unsigned short *memushort(const unsigned short *,unsigned short,size_t);
int *    memint(const int *,int,size_t);
unsigned int *memuint(const unsigned int *,unsigned int,size_t);
long long *memll(const long long *,long long,size_t);
unsigned long long *memull(const unsigned long long *,unsigned long long,size_t);
char    *strupr(char *);
char    *strlwr(char *);
char    *strnupr(char *,size_t);
char    *strnlwr(char *,size_t);
int      strtrim(char *);
char    *strrev(char *);
#endif
int 	 memcmp(const void *, const void *, size_t);
void * 	 memcpy(void *, const void *, size_t);
void *   mempcpy(void *,const void *,size_t);
void *	 memmove(void *, const void *, size_t);
void *	 memset(void *, int, size_t);
char 	*strcat(char *, const char *);
char 	*strchr(const char *, int);
int	 strcmp(const char *, const char *);
int	 strcoll(const char *, const char *);
char 	* strcpy(char *, const char *);
unsigned int strlcpy(char *destination,const char *source,unsigned int bufsize);
size_t	 strcspn(const char *, const char *);
char 	*strerror(int);
size_t	 strlen(const char *);
size_t  strnlen_s(const char *,size_t);
char 	*strncat(char *, const char *, size_t);
unsigned int strlcat(char *destination,const char *source,unsigned int bufsize);
int	 strncmp(const char *, const char *, size_t);
char 	*strncpy(char *, const char *, size_t);
char 	*strpbrk(const char *, const char *);
char 	*strrchr(const char *, int);
size_t	 strspn(const char *, const char *);
char 	*strstr(const char *, const char *);
char    *stristr(const char *,const char *);
char 	*strtok(char *, const char *);
void *	 memccpy(void *, const void *, int, size_t);
void *   _memccpy(void *,void *,unsigned int);
char 	*strdup(const char *);
char    *strndup(const char *,size_t siz);
int	 strnicmp(const char *, const char *, size_t);
void	 swab(const char *, char *, size_t);
int	 stricmp(const char *,const char *);
char	*_strset( char *,int);
int	 strcmpi(const char *,const char *);
#define memicmp _memicmp
int memicmp(const void *,const void *,size_t);
int strrepl(char *InputString,char *StringToFind,char *Replacement,char *OutputString);
int strtobase64(char *dst,size_t destsiz,unsigned char *src,size_t srcsiz);
int strfrombase64(char *dst,size_t destsiz,unsigned char *src,size_t srcsiz);
/*
#include "safelib.h"

errno_t memmove_s(void *s1, rsize_t s1max, const void *s2, rsize_t n);
errno_t strcpy_s(char * restrict s1, rsize_t s1max, const char * restrict s2);
errno_t strcat_s(char * restrict s1, rsize_t s1max, const char * restrict s2);
char *strtok_s(char * restrict s1, rsize_t * restrict s1max, const char * restrict s2, char ** restrict ptr);
errno_t memcpy_s(void * restrict s1, rsize_t s1max, const void * restrict s2, rsize_t n);
errno_t strerror_s(char *s, rsize_t maxsize, errno_t errnum);
size_t strnlen_s(const char *s, size_t maxsize);
size_t strerrorlen_s(errno_t errnum);
errno_t strerror_s(char *s, rsize_t maxsize, errno_t errnum);
errno_t strncpy_s(char * restrict s1, rsize_t s1max, const char * restrict s2, rsize_t n);
errno_t strncpy_s(char * restrict s1, rsize_t s1max, const char * restrict s2, rsize_t n);
errno_t strncat_s(char * restrict s1, rsize_t s1max, const char * restrict s2, rsize_t n);
errno_t strerror_s(char *s, rsize_t maxsize, errno_t errnum);
*/
#endif /* __string_h__ */
