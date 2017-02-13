#if defined(USE_MSVCRT)
#define __import __declspec(dllimport)
#else
#define __import
#endif
