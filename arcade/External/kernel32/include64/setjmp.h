#ifndef __setjmp_h__
#define __setjmp_h__

typedef long jmp_buf[20];
void	longjmp(jmp_buf jmpb, int retval);
int	setjmp(jmp_buf jmpb);

#endif /* __setjmp_h__ */

