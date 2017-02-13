#ifndef __io_h__
#define __io_h__
#include <stdint.h>
/*---------------------------------------------------------------------------*/
/* io.h - low level i/o header file                                          */
/*---------------------------------------------------------------------------*/
#include <crt.h>
#include <stddef.h>

#define _CR_   0x0d
#define _LF_   0x0a
#define _EOF_  0x01a
#define _CRLF_ 0x0a0d
#define _FOPN_ 0x04000
#define _FEOF_ 0x08000
/*---------------------------------------------------------------------------*/
/* macro definitions                                                         */
/*---------------------------------------------------------------------------*/
#define _fmode (_crt_base->_crt_fmode)
struct _finddata_t {
        unsigned    attrib;
        time_t      time_create;
        time_t      time_access;
        time_t      time_write;
        unsigned long    size;
        char        name[260];
};
/*---------------------------------------------------------------------------*/
/* function prototypes                                                       */
/*---------------------------------------------------------------------------*/
int setmode(int, int);
int isatty(int fd);
#define _isatty isatty
int access(char *pathname, int mode);
int eof(int handle);
int close(int handle);
int creat(char *filename, int pmode);
int dup(int handle);
int dup2(int handle1, int handle2);
long lseek(int handle, long offset, int origin);
int open(char *filename, int oflag, ...);
int read(int handle, void *buffer, unsigned int count);
int sopen(char *filename, int oflag, int shflag, ...);
long tell(int handle);
int umask(int pmode);
int write(int handle, void *buffer, unsigned int count);
intptr_t _findfirst(const char * szWild, struct _finddata_t * pfd);
int _findnext(intptr_t hFile, struct _finddata_t * pfd);
int _findclose(intptr_t hFile);
int  chmod(const char *, int);
#endif

