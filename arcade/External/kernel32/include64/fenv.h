#ifndef __fenv_h__
#define __fenv_h__
#pragma pack(push,1)

typedef struct _StatusWord {
	unsigned int InvalidOperation:1;
	unsigned int Denormal:1;
	unsigned int ZeroDivide:1;
	unsigned int Overflow:1;
	unsigned int Underflow:1;
	unsigned int Precision:1;
	unsigned int StackFault:1;
	unsigned int ErrorSummary:1;
	unsigned int C0:1;
	unsigned int C1:1;
	unsigned int C2:1;
	unsigned int TOP:3;
	unsigned int C3:1;
	unsigned int Busy:1;
	unsigned int unused:15;
} STATUS_WORD;

typedef struct _ControlWord {
	unsigned int InvalidOperationMask:1;
	unsigned int DenormalizedOperandMask:1;
	unsigned int ZeroDivideMask:1;
	unsigned int OverflowMask:1;
	unsigned int UnderflowMask:1;
	unsigned int PrecisionMask:1;
	unsigned int Reserved1:2;
	unsigned int Precision:2;
	unsigned int Rounding:2;
	unsigned int NotUsed:1;
	unsigned int Reserved:3;
	unsigned int Unused:15;
} CONTROL_WORD;

typedef struct _TagWord {
	unsigned int Tag0:2;
	unsigned int Tag1:2;
	unsigned int Tag3:2;
	unsigned int Tag4:2;
	unsigned int Tag5:2;
	unsigned int Tag6:2;
	unsigned int Tag7:2;
	unsigned int Unused:16;
} TAG_WORD;

typedef struct _fenv {
	CONTROL_WORD ControlWord;
	STATUS_WORD StatusWord;
	TAG_WORD TagWord;
	unsigned int IPOffset;
	unsigned short CsSelector;
	unsigned short Opcode;
	unsigned int DataOffset;
	unsigned short DsSelector;
	short Reserved[4];
	char Reserved1[76];
} fenv_t;

typedef STATUS_WORD fexcept_t;
int fegetexceptflag(fexcept_t *flagp,int excepts);
void fesetexceptflag(const fexcept_t *flagp,int excepts);
/*
The fegetenv function stores the current floating-point environment in the object
pointed to by envp.
*/
int fegetenv(const fenv_t *);
/*
The fesetenv function establishes the floating-point environment represented by the
object pointed to by envp. The argument envp shall point to an object set by a call to
fegetenv or feholdexcept, or equal the macro FE_DFL_ENV or an
implementation-defined environment macro. Note that fesetenv merely installs the
state of the exception flags represented through its argument, and does not raise these
exceptions.
If the argument is FE_DFL_ENV an fninit is performed
*/
int fesetenv(const fenv_t *);
/*
The fegetround function returns the value of the rounding direction macro
representing the current rounding direction.
*/
int fegetround(void);
/*
The fesetround function establishes the rounding direction represented by its
argument round. If the argument is not equal to the value of a rounding direction macro,
the rounding direction is not changed.
Returns
The fesetround function returns a zero value if and only if the argument is equal to a
rounding direction macro (that is, if and only if the requested rounding direction was
established).
*/
int fesetround(int r);
/* Rounding direction macros */
#define FE_DOWNWARD		1
#define FE_TONEAREST	0
#define FE_TOWARDZERO	3
#define FE_UPWARD		2
/*
Description
2 The fetestexcept function determines which of a specified subset of the
exception flags are currently set.
The excepts argument specifies the exception flags to be queried)
Returns
The fetestexcept function returns the value of the bitwise OR of the exception
macros corresponding to the currently set exceptions included in excepts.
*/
int fetestexcept(int);
/*
The feclearexcept function clears the supported exceptions represented by its
argument.
*/
int feclearexcept(int);
int fegetprecision(void);
/* exception macros */
#define FE_INVALID		1
#define FE_DENORMAL		2
#define FE_INEXACT		32
#define FE_DIVBYZERO	4
#define FE_OVERFLOW		8
#define FE_UNDERFLOW	16
#define FE_STACKFAULT		64
#define FE_ALL_EXCEPT (FE_INVALID|FE_DENORMAL|FE_INEXACT|FE_DIVBYZERO|FE_OVERFLOW|FE_UNDERFLOW)
// This functions set the precision of the FPU. All of them
// return the old setting.
// Sets the FPU precision to 53 bits only. Double precision
// Sets the precision to 64 bits. (long double precision)
int FullPrecision(void);
int DoublePrecision(void);
// Sets the FPU precision to 23 bits (float precision)
int FloatPrecision(void);
int feraiseexcept(int excepts);
int fereset(void);
extern fenv_t __default_fe_env;
#define FE_DFL_ENV (&__default_fe_env)
#pragma pack(pop)
#endif
