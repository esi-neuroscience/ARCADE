#ifndef _LIMITS_H___
#define CHAR_BIT 8

#ifndef MB_LEN_MAX
#define MB_LEN_MAX 2
#endif

/* Minimum and maximum values a `signed char' can hold.  */
#define SCHAR_MIN (-128)
#define SCHAR_MAX 127

/* Maximum value an `unsigned char' can hold.  (Minimum is 0).  */
#define UCHAR_MAX 255

/* Minimum and maximum values a `char' can hold.  */
#define CHAR_MIN (-128)
#define CHAR_MAX 127

/* Minimum and maximum values a `signed short int' can hold.  */
#define SHRT_MIN (-32768)
#define SHRT_MAX 32767

/* Maximum value an `unsigned short int' can hold.  (Minimum is 0).  */
#define USHRT_MAX 65535

/* Minimum and maximum values a `signed int' can hold.  */
#define __INT_MAX__ 2147483647
#define INT_MIN (-INT_MAX-1)
#define INT_MAX __INT_MAX__

/* Maximum value an `unsigned int' can hold.  (Minimum is 0).  */
#define UINT_MAX 4294967295U

/* Minimum and maximum values a `signed long int' can hold.
   (Same as `int').  */
#define LONG_MAX 2147483647L
#define LONG_MIN (-2147483647L - 1)
/* Maximum value an `unsigned long int' can hold.  (Minimum is 0).  */
#define ULONG_MAX 4294967295
/* maximum value of long long */
#define LLONG_MAX 9223372036854775807LL
#define LLONG_MIN ((long long)0x8000000000000000LL) 
// That should be -9223372036854775808LL
#define ULLONG_MAX 18446744073709551615ULL

#define I128_MAX 85070591730234615865843651857942052864I128
#endif /* _LIMITS_H___ */
