/* assert.h */
#undef assert
#ifdef NDEBUG
#define assert(p)  	((void)0)
#else
#define assert(p)   ((p) ? (void)0 : (void) _assertfail("Assertion failed: ",#p, __FILE__, __LINE__ ))
int _assertfail(char *__msg, char *__cond, char *__file, int __line);
#endif
