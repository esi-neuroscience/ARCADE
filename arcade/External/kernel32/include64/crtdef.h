/*---------------------------------------------------------------------------*/
/* crtdef.h - C runtime base definitions include file                        */
/*---------------------------------------------------------------------------*/

#ifndef _CRT_DEFINED

  #include <locale.h>

  #ifndef _TIME_T_DEFINED
    typedef long time_t;
    #define _TIME_T_DEFINED
  #endif

  #define _MAX_SIG_       10
  #define _MAX_EXIT_      32
  #define _BASE_FILES_    20
  #define _BASE_BUFSZ_    4096
  #define _MAX_LOCALE_    6

  #define _CRT_SYSERR_    38

  #define _CRT_EZERO_     "No error"
  #define _CRT_EDOM_      "Math argument error"
  #define _CRT_ERANGE_    "Result too large"
  #define _CRT_EPERM_     ""
  #define _CRT_ENOENT_    "No such file or directory"
  #define _CRT_ESRCH_     ""
  #define _CRT_EINTR_     ""
  #define _CRT_EIO_       ""
  #define _CRT_ENXIO_     ""
  #define _CRT_E2BIG_     "Argument list too long"
  #define _CRT_ENOEXEC_   "Exec format error"
  #define _CRT_EBADF_     "Bad file number"
  #define _CRT_ECHILD_    ""
  #define _CRT_EAGAIN_    ""
  #define _CRT_ENOMEM_    "Not enough memory"
  #define _CRT_EACCES_    "Permission denied"
  #define _CRT_EFAULT_    ""
  #define _CRT_ENOTBLK_   ""
  #define _CRT_EBUSY_     ""
  #define _CRT_EEXIST_    "File already exists"
  #define _CRT_EXDEV_     "Cross device link"
  #define _CRT_ENODEV_    ""
  #define _CRT_ENOTDIR_   ""
  #define _CRT_EISDIR_    ""
  #define _CRT_EINVAL_    "Invalid argument"
  #define _CRT_ENFILE_    ""
  #define _CRT_EMFILE_    "Too many open files"
  #define _CRT_ENOTTY_    ""
  #define _CRT_ETXTBSY_   ""
  #define _CRT_EFBIG_     ""
  #define _CRT_ENOSPC_    "No space left on device"
  #define _CRT_ESPIPE_    ""
  #define _CRT_EROFS_     ""
  #define _CRT_EMLINK_    ""
  #define _CRT_EPIPE_     ""
  #define _CRT_EUCLEAN_   ""
  #define _CRT_EDEADLOCK_ "Resource deadlock"
  #define _CRT_ENOTEXIST_ "File not found"
  #define _CRT_EUNKNOWN_  "Unknown error"

  #define _ASCTIME_BUFSZ_ 26

  struct _crt_
  {
    int            _crt_openmax;
    int            _crt_bufsize;
    int            _crt_errno;
    int            _crt_doserrno;
    int            _crt_umask;
    int            _crt_fmode;
    int            _crt_nerr;
    int            _exit_list;
    int            _crt_getchbuf;
    int            _envar_buflen;
    int            *_crt_llioflg;
    int            *_htab_base;
    char           *_strtok_ptr;
    char           *_tmpnam_ptr;
    char           *_asctim_ptr;
    char           *_envar_buffer;
    char           *_printf_buffer;
    void           *_io_base;
    void           *_excp_base;
    void           *_tmpnam_base;
    void           **_exit_base;
    unsigned long  _rand_next;
    unsigned long  _base_time;
    unsigned long  _base_date;
    int            _crt_daylight;
    time_t         _crt_timezone;
    char           *_crt_tzname[2];
    char           _crt_tzbuffer[2][4];
    struct tm      *_tm_base;
    struct lconv   _crt_lcbuffer;
    char           *_crt_locale[_MAX_LOCALE_];
    char           *_crt_localday[7];
    char           *_crt_localmon[12];
    char           *_crt_syserrlist[_CRT_SYSERR_ + 1];
  };

  extern int *_crt_errno;
  extern struct _crt_ *_crt_base;
  extern unsigned long *_crt_excp_base;

  #define _CRT_DEFINED
#endif

