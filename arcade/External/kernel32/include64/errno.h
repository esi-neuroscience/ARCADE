/*---------------------------------------------------------------------------*/
/* errno.h - error number header file                                        */
/*---------------------------------------------------------------------------*/
#define EZERO           0
#define EDOM            1
#define ERANGE          2
#define EPERM           3
#define ENOENT          4
#define ESRCH           5
#define EINTR           6
#define EIO             7
#define ENXIO           8
#define E2BIG           9
#define ENOEXEC        10
#define EBADF          11
#define ECHILD         12
#define EAGAIN         13
#define ENOMEM         14
#define EACCES         15
#define EFAULT         16
#define ENOTBLK        17
#define EBUSY          18
#define EEXIST         19
#define EXDEV          20
#define ENODEV         21
#define ENOTDIR        22
#define EISDIR         23
#define EINVAL         24
#define ENFILE         25
#define EMFILE         26
#define ENOTTY         27
#define ETXTBSY        28
#define EFBIG          29
#define ENOSPC         30
#define ESPIPE         31
#define EROFS          32
#define EMLINK         33
#define EPIPE          34
#define EUCLEAN        35
#define EDEADLOCK      36
#define ENOTEXIST      37
#define EUNKNOWN       38
#define EILSEQ         39
#define _sys_nerr      39

#include <crtdef.h>

/*---------------------------------------------------------------------------*/
/* macro definitions                                                         */
/*---------------------------------------------------------------------------*/
#define errno (_crt_base->_crt_errno)
#define _doserrno (_crt_base->_crt_doserrno)
typedef int errno_t;
