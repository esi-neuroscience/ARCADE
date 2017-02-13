#ifndef __process_h_
#define __process_h_
int execl(const char *path, const char *argv0, ...);
int execle(const char *path, const char *argv0, ... /*, char * const *envp */);
int execlp(const char *path, const char *argv0, ...);
int execlpe(const char *path, const char *argv0, ... /*, char * const *envp */);
int execv(const char *path, char * const *argv);
int execve(const char *path, char * const *argv, char * const *envp);
int execvp(const char *path, char * const *argv);
int execvpe(const char *path, char * const *argv, char * const *envp);
int spawnl(int mode, const char *path, const char *argv0, ...);
int spawnle(int mode, const char *path, const char *argv0, ... /*, char * const *envp */);
int spawnlp(int mode, const char *path, const char *argv0, ...);
int spawnlpe(int mode, const char *path, const char *argv0, ... /*, char * const *envp */);
int spawnv(int mode, const char *path, char * const *argv);
int spawnve(int mode, const char *path, char * const *argv, char * const *envp);
int spawnvp(int mode, const char *path, char * const *argv);
int spawnvpe(int mode, const char *path, char * const *argv, char * const *envp);
int _getpid(void);
#define _spawnv spawnv
#define _spawnve spawnve
#define _spawnvp spawnvp
#define _spawnvpe spawnvpe
#define getpid _getpid
#define P_WAIT		0
#define P_NOWAIT	1
#define P_OVERLAY	2
#define P_DETACH	4
#define WAIT_CHILD 0
#define _P_WAIT P_WAIT
#define _P_NOWAIT P_NOWAIT
#define _P_OVERLAY P_OVERLAY
#ifndef __ANSIC__ONLY__
#define _beginthread beginthread
#define _endthread endthread
unsigned long  beginthread (void ( *) (void *), unsigned, void *);
void endthread(void);
unsigned long _beginthreadex(void *,unsigned,unsigned (_stdcall *)(void *),void *,unsigned,unsigned *);
void _endthreadex(unsigned);
int _cwait( int *termstat, int procHandle, int action );
int _stdcall  _System(const char *cmd,int nCmdShow);
#define _WAIT_CHILD	0
#endif
#endif


