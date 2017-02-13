#ifndef __STDDEF_H
#define __STDDEF_H
#ifndef _SIZE_T_DEFINED
typedef unsigned long long size_t;
#define _SIZE_T_DEFINED
#endif
typedef long long ptrdiff_t;
#define offsetof(s,m) (long long)&(((s *)0)->m)
#ifndef NULL
#define NULL (void *)0
#endif
#ifndef _RSIZE_T_DEFINED
#define _RSIZE_T_DEFINED
typedef size_t rsize_t;
#endif
#endif
