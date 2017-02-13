/* math.h -- Definitions for the math floating point package.  */
#ifndef __math_h__
#define __math_h__
// Use the HUGE_VAL of crtdll.dll
#ifndef HUGE_VAL
#define HUGE_VAL 1.7976931348623157e+308
#endif /* ! defined (HUGE_VAL) */

#ifndef __LCC__
#define __ANSIC__ONLY__
#else
#pragma extensions(push,on)
#endif

#define FLT_EVAL_METHOD	2

typedef float float_t;
typedef double double_t;

// atan
double atan(double);
double _atani(int);
long double atanl(long double);
float atanf(float);

// tan
long double tanl(long double);
double tan(double);
float tanf(float);

// cos
double cos(double);
long double cosl(long double);
float cosf(float);
double _cosi(int);
double _cosu(unsigned);
double _cosll(long long);
double _cosull(unsigned long long);

long double sinl(long double);
float sinf(float);
double sin(double);
double _sini(int);
double _sinu(unsigned);
double _sinll(long long);
double _sinull(unsigned long long);

// exp2
long double exp2l(long double);
double exp2(double);
float exp2f(float);

// exp10
double exp10(double);
float exp10f(float);
long double exp10l(long double);

// expm1
long double expm1l(long double);
double expm1(double);
float expm1f(float);
double _expm1i(int);

// tanh
double tanh(double);
long double tanhl(long double);
float tanhf(float);

// frexp
double frexp(double, int *);
long double frexpl(long double,int *);
double _frexpi(int,int *);
float frexpf(float,int *);

// fdim
long double fdiml(long double x,long double y);
double fdim(double x,double y);
float fdimf(float x,float y);

double modf(double, double *);
long double modfl(long double,long double *);

// ceil
double ceil(double);
long double ceill(long double);
float ceilf(float);
double _ceili(int);

// cbrt
double cbrt(double);
long double cbrtl(long double);
float cbrtf(float);

// fabs
long double fabsl(long double);
double fabsd(double);
float fabsf(float);
double fabs(double);
double _fabsi(int);
double _fabsull(unsigned long long);
double _fabsll(long long);
double _fabsu(unsigned);

// floor
long double floorl(long double);
double floord(double);
float floorf(float);
double floor(double);
double _floori(int);
double _flooru(unsigned);

// fma
long double fmal(long double,long double,long double);
double fma(double,double,double);
float fmaf(float,float,float);
double _fmai(int,int,int);

// fmax
long double fmaxl(long double,long double);
double fmax(double,double);
float fmaxf(float,float);
// acos
double acos (double);
float acosf(float);
long double acosl(long double);

// asin
double asin (double);
long double asinl(long double);
float asinf(float);

double atan2 (double, double);
long double atan2l(long double,long double);
float atan2f(float,float);

// cosh
double cosh (double);
long double coshl(long double);
float coshf(float);
double _coshi(int);

// sinh
double sinh (double);
long double sinhl(long double);
float sinhf(float);
double _sinhi(int);
double _sinhll(long long);

// exp 
long double expl(long double);
float expf(float);
double exp(double);

// ldexp
double ldexp(double, int);
long double ldexpl(long double,int);
float ldexpf(float,int);

// log
long double logl(long double);
float logf(float);
double log(double);
double _logi(int);

// log10
double log10(double);
long double log10l(long double);
float log10f(float);

// log1p
double log1p(double);
long double log1pl(long double);
float log1pf(float);

// log10
long double log10l(long double);
float log10f(float);
double _log10i(int);
double log10(double);

// pow 
double pow(double,double);
long double powl(long double,long double);
double powd(double,double);
long double powlli(long double,int);
double ipow(double,int);
double powdi(double,int);
long double ipowl(long double,int);
float ipowf(float,int);
float powf(float,float);
double powii(int,int);
long double powlld(long double,double);
long double powlli(long double,int);
long double powdll(double,long double);
double powid(int,double);

// scalb
double scalb(double,double);
long double scalbl(long double,long double);
float scalbf(float,float);

// scalbn
double scalbn(double,int);
long double scalbnl(long double,int);
float scalbnf(float,int);

// scalbln
double scalbln(double,long);
long double scalblnl(long double,long);
float scalblnf(float,long);

// sqrt
long double sqrtl(long double);
double _sqrti(int);
double _sqrtu(unsigned);
double _sqrtll(long long);
double _sqrtull(unsigned long long);
float sqrtf(float);
double sqrt(double);

// fmod
double fmod(double,double);
long double fmodl(long double, long double);
float fmodf(float,float);

double infinity(void);
long double infinityl(void);
float infinityf(void);
long double max_normall(void);
double max_normal(void);
float max_normalf(void);
long double min_normall(void);
double min_normal(void);
float min_normalf(void);
#undef isnan
int isnand(double);
int isnanl(long double);
int isnanf(float);
int isnan(double);

int finite(double);

int isnormalf(float);
int isnormal(double);
int isnormall(long double);

double copysign(double, double);
long double copysignl(long double,long double);
float copysignf(float,float);

int ilogb(double);
int ilogbf(float);
int ilogbl(long double);

double logb(double);
long double logbl(long double);
float logbf(float);

double erf(double);
long double erfl(long double);
float erff(float);

// erfc
double erfc(double);
long double erfcl(long double);
float erfcf(float);

int _signbit(double);
#define signbit _signbit

// asinh
double asinh (double);
long double asinhl(long double);
long double sinhl(long double);
float asinhf(float);

// nextafter
double nextafter (double, double);
long double nextafterl(long double,long double);
float nextafterf(float,float);

// nexttoward
double nexttoward(double,long double);
long double nexttowardl(long double,long double);
float nexttowardf(float,long double);

// acosh
double acosh (double);
long double acoshl(long double);
long double acoshl(long double);
float acoshf(float);

//atanh
double atanh(double);
long double atanhl(long double);
float atanhf(float);

// lgamma
double lgamma (double);
long double lgammal(long double);
float lgammaf(float);

long double tgammal(long double);
double tgamma(double);
float tgammaf(float);

#ifndef __ANSIC__ONLY__
double _y0 (double);
long double y0l(long double);
double y1 (double);
long double y1l(long double);
double yn(int, double);
long double ynl(int,long double);
double j0(double);
double j1 (double);
long double j1l(long double);
double jn (int, double);
long double jnl(int,long double);
#endif

// log2
long double log2l(long double);
double log2(double);
float log2f(float);
double _log2i(int);
double _log2ll(long long);

// nearbyint
long double nearbyintl(long double);
double nearbyint(double);
float nearbyintf(float);

// hypot
double hypot (double, double);
long double hypotl(long double,long double);
float hypotf(float,float);

double _rint(double);
#define rint _rint

// isinf
int isinf(double);
int _isinfd(double);
int isinfl(long double);
int isinff(float);
int _isinfi(int);

// isfinite
int isfinite(double);
int isfinitef(float);
int isfinitel(long double);

int __fpclassifyl(long double);
int __fpclassifyd(double);
int __fpclassifyf(float);

// round
double round(double);
float roundf(float);
long double roundl(long double);
double _roundi(int);

// remainder
double remainder(double,double);
long double remainderl(long double,long double);
float remainderf(float,float);

int lrint(double);
int lrintf(float);
long lrintl(long double);
long long llrintl(long double);
long long llrintf(float);
long long llrint(double);

long lround(double);
long lroundf(float);
long lroundl(long double);

long long llround(double);
long long llroundf(float);
long long llroundl(long double);

long double remquol(long double,long double,int *);
double remquo(double,double,int *);
float remquof(float,float,int *);

double trunc(double x);
long double truncl(long double);
float truncf(float);

// fmin
long double fminl(long double,long double);
float fminf(float ,float);
double fmin(double,double);

/* This codes are returned by the lcc-win32 function fpclass */
#define FPCLASS_PINFINITY       5 /* Positive infinity */
#define FPCLASS_NINFINITY	7 /* Negative infinity */
#define FPCLASS_ZERO            64 /* zero */
#define FPCLASS_NZERO           66 /* Negative zero */
#define FPCLASS_PNORMAL         4 /* Positive normal number */
#define FPCLASS_NNORMAL         6 /* Negative normal number */
#define FPCLASS_PDENORMAL       69 /* Positive denormal */
#define FPCLASS_NDENORMAL       71 /* Negative denormal */
#define FPCLASS_NAN             1 /* Not a number */
void ldtoa(long double,char *);
double cabs(double _Complex);
float cabsf(float _Complex);
long double cabsl(long double _Complex);


/* The exception structure passed to the matherr routine.  */

struct exception 
{
  int type;
  char *name;
  double arg1;
  double arg2;
  double retval;
  int err;
};

int matherr (struct exception *e);
#define NAN __nan__
extern float __nan__;
#define INFINITY	__infinity__
extern float __infinity__;
double nan(const char *);
float nanf(const char *);
long double nanl(const char *);
#ifndef __ANSIC__ONLY__
// Knuth's fcmp function
// fcmp(double x,double y,double epsilon);
int fcmp(double,double,double);
int fcmpl(long double,long double,long double);
void sincos(double x, double *sin, double *cos);
void sincosf(float x, float *sin, float *cos);
void sincosl(long double x, long double *sin, long double *cos);
#endif
#ifdef __COMPILING_LCC_CRT__
#ifndef __tgmath_h__
#include "tgmath.h"
#endif
#endif
int _isgreater(long double,long double);
#define isgreater(_a,_b) _isgreater(_a,_b)

int _isgreaterequal(long double,long double);
#define isgreaterequal(a,b) _isgreaterequal(a,b)

int _isless(long double,long double);
#define isless(a,b) _isless(a,b)

int _islessequal(long double,long double);
#define islessequal(a,b) _islessequal(a,b)

int _islessgreater(long double,long double);
#define islessgreater(a,b) _islessgreater(a,b)

int _isunordered(long double,long double);
#define isunordered(a,b) _isunordered(a,b)

/* Values for the type field of struct exception.  */

#define DOMAIN 1
#define SING 2
#define OVERFLOW 3
#define UNDERFLOW 4
#define TLOSS 5
#define PLOSS 6

#ifndef __ANSIC__ONLY__
double atof(const char *);
//Solves the cubic equation of the general cubic ax3+bx2+cx+d = 0
int cubic(double  a,         /* coefficient of x^3 */
                double  b,         /* coefficient of x^2 */
                double  c,         /* coefficient of x   */
                double  d,         /* constant term      */
                double *x);         /* array of solutions      */
int cubicl(long double  a,         /* coefficient of x^3 */
           long double  b,         /* coefficient of x^2 */
           long double  c,         /* coefficient of x   */
           long double  d,         /* constant term      */
           long double *x);         /* array of solutions      */
/* Useful constants.
   The Open Group proposes this names.
   http://www.opengroup.org/onlinepubs/007908799/xsh/math.h.html
 */

#define M_E		2.7182818284590452354
#define M_LOG2E		1.4426950408889634074
#define M_LOG10E	0.43429448190325182765
#define M_LN2		0.69314718055994530942
#define M_LN10		2.30258509299404568402
#define M_PI		3.14159265358979323846
#define M_TWOPI         (M_PI * 2.0)
#define M_PI_2		1.57079632679489661923
#define M_PI_4		0.78539816339744830962
#define M_3PI_4		2.3561944901923448370E0
#define M_SQRTPI        1.77245385090551602792981
#define M_1_PI		0.31830988618379067154
#define M_2_PI		0.63661977236758134308
#define M_2_SQRTPI	1.12837916709551257390
#define M_SQRT2		1.41421356237309504880
#define M_SQRT1_2	0.70710678118654752440
#define M_LN2LO         1.9082149292705877000E-10
#define M_LN2HI         6.9314718036912381649E-1
#define M_SQRT3   	1.73205080756887719000
#define M_IVLN10        0.43429448190325182765 /* 1 / log(10) */
#define M_LOG2_E        0.693147180559945309417
#define M_INVLN2        1.4426950408889633870E0  /* 1 / log(2) */
/* The same constants in long double precision */
# define M_El           2.7182818284590452353602874713526625L  /* e */
# define M_LOG2El       1.4426950408889634073599246810018922L  /* log_2 e */
# define M_LOG10El      0.4342944819032518276511289189166051L  /* log_10 e */
# define M_LN2l         0.6931471805599453094172321214581766L  /* log_e 2 */
# define M_LN10l        2.3025850929940456840179914546843642L  /* log_e 10 */
# define M_PIl          3.1415926535897932384626433832795029L  /* pi */
# define M_PI_2l        1.5707963267948966192313216916397514L  /* pi/2 */
# define M_PI_4l        0.7853981633974483096156608458198757L  /* pi/4 */
# define M_1_PIl        0.3183098861837906715377675267450287L  /* 1/pi */
# define M_2_PIl        0.6366197723675813430755350534900574L  /* 2/pi */
# define M_2_SQRTPIl    1.1283791670955125738961589031215452L  /* 2/sqrt(pi) */
# define M_SQRT2l       1.4142135623730950488016887242096981L  /* sqrt(2) */
# define M_SQRT1_2l     0.7071067811865475244008443621048490L  /* 1/sqrt(2) */
#define FP_ILOGB0	0x80000000
#define FP_NORMAL	0
#define FP_INFINITE	5
#define FP_SUBNORMAL	69
#define FP_NAN		1
#define FP_ZERO		64
#endif
#ifdef __LCC__
#pragma extensions(pop)
#endif
#endif /* _MATH_H_ */
