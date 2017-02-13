#ifndef __direct_h__
#define __direct_h__
#pragma pack(push,8)
#ifndef _W64
#define _W64 __w64
#endif
#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef _WCHAR_T_DEFINED
typedef unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif

#ifndef _SIZE_T_DEFINED
typedef unsigned __int64    size_t;
#define _SIZE_T_DEFINED
#endif

#ifndef _DISKFREE_T_DEFINED
struct _diskfree_t { unsigned total_clusters; unsigned avail_clusters;
        unsigned sectors_per_cluster; unsigned bytes_per_sector; };
#define _DISKFREE_T_DEFINED
#endif

int chdir(const char *);
char * getcwd(char *, int);
int mkdir(const char *);
int rmdir(const char *);

_CRTIMP int _chdrive(int);
_CRTIMP char * _getdcwd(int, char *, int);
_CRTIMP int _getdrive(void);
_CRTIMP unsigned long _getdrives(void);
_CRTIMP unsigned _getdiskfree(unsigned, struct _diskfree_t *);

#ifndef _WDIRECT_DEFINED
_CRTIMP int _wchdir(const wchar_t *);
_CRTIMP wchar_t * _wgetcwd(wchar_t *, int);
_CRTIMP wchar_t * _wgetdcwd(int, wchar_t *, int);
_CRTIMP int _wmkdir(const wchar_t *);
_CRTIMP int _wrmdir(const wchar_t *);
#define _WDIRECT_DEFINED
#endif
#pragma pack(pop)
#endif

