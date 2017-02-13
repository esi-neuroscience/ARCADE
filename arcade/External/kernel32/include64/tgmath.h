#ifndef __tgmath_h__
#define __tgmath_h__
#ifndef __math_h__
#include <math.h>
#endif
/*
This functions are defined in tgmath.h as generic.

atan2 cbrt ceil copysign erf erfc exp2 expm1 fdim floor fma fmax fmin fmod frexp
hypot ilogb ldexp lgamma llrint llround log10 log1p log2 logb lrint lround nearbyint
nextafter nexttoward remainder remquo rint round scalbn scalbln tgamma trunc
*/

double overloaded __atan2.atan2(double,double);
float overloaded __atan2.atan2f(float,float);
long double overloaded __atan2.atan2l(long double,long double);

double overloaded __atan.atan(double);
long double overloaded __atan.atanl(long double);
float overloaded __atan.atanf(float);
#define atan(a) __atan(a)

double overloaded __tan.tan(double);
long double overloaded __tan.tanl(long double);
float overloaded __tan.tanf(float);
#define tan(a)  __tan(a)

#undef cos
double overloaded __cos.cos(double);
long double overloaded __cos.cosl(long double);
float overloaded __cos.cosf(float);
double overloaded __cos._cosi(int);
double overloaded __cos._cosll(long long);
double overloaded __cos._cosull(unsigned long long);
#define cos(a) __cos(a)

#undef sin
double overloaded __sin.sin(double);
long double overloaded __sin.sinl(long double);
float overloaded __sin.sinf(float);
double overloaded __sin._sini(int);
double overloaded __sin._sinll(long long);
double overloaded __sin._sinull(unsigned long long);
#define sin(a) __sin(a)


double overloaded __exp2.exp2(double);
long double overloaded __exp2.exp2l(long double);
float overloaded __exp2.exp2f(float);
#define exp2(a) __exp2(a)

double overloaded __expm1.expm1(double);
long double overloaded __expm1.expm1l(long double);
float overloaded __expm1.expm1f(float);
#define expm1(a) __expm1(a)

double overloaded __tanh.tanh(double);
long double overloaded __tanh.tanhl(long double);
float overloaded __tanh.tanhf(float);
#define tanh(a) __tanh(a)

double overloaded __frexp.frexp(double,int *);
long double overloaded __frexp.frexpl(long double,int *);
float overloaded __frexp.frexpf(float,int *);
#define frexp(a,b) __frexp(a,b)

long double _stdcall overloaded __fabs.fabsl(long double);
double _stdcall overloaded __fabs.fabsd(double);
float _stdcall overloaded __fabs.fabsf(float);
double _stdcall overloaded __fabs._fabsi(int);
double _stdcall overloaded __fabs._fabsu(unsigned);
double _stdcall overloaded __fabs._fabsll(long long);
double _stdcall overloaded __fabs._fabsull(unsigned long long);
long double overloaded __fabs.cabsl(long double _Complex);
#define fabs(a) __fabs(a)

long double overloaded __cbrt.cbrtl(long double);
double overloaded __cbrt.cbrt(double);
float overloaded __cbrt.cbrtf(float);
#define cbrt(a) __cbrt(a)

double overloaded __floor.floor(double);
float overloaded __floor.floorf(float);
long double overloaded __floor.floorl(long double);
double overloaded __floor._floori(int);
double overloaded __floor._flooru(unsigned);
#define floor(a) __floor(a)

double overloaded __fdim.fdim(double,double);
float overloaded __fdim.fdimf(float,float);
long double overloaded __fdim.fdiml(long double,long double);
#define fdim(a,b) __fdim(a,b)

double overloaded __fma.fma(double,double,double);
float overloaded __fma.fmaf(float,float,float);
long double overloaded __fma.fmal(long double,long double,long double);
#define fma(a,b,c) __fma(a,b,c)

double _Complex cacosl(double _Complex);
double overloaded __acos.acos(double);
long double overloaded __acos.acosl(long double);
float overloaded __acos.acosf(float);
double _Complex overloaded __acos.cacosl(double _Complex);
#define acos(a) __acos(a)

double overloaded __asin.asin(double);
long double overloaded __asin.asinl(long double);
float overloaded __asin.asinf(float);
#define asin(a) __asin(a)

double _Complex cpowld(const double _Complex x,double y);
extern double _Complex cpowll(const double _Complex x,double y);
extern double _Complex cpow(const double _Complex x,double _Complex y);

long double overloaded __pow.powl(long double,long double);
double overloaded __pow.pow(double,double);
long double overloaded __pow.powlli(long double,int);
long double overloaded __pow.powlld(long double,double);
long double overloaded __pow.powdll(double,long double);
double overloaded __pow.ipow(double,int);
long double overloaded __pow.ipowl(long double,int);
float overloaded __pow.ipowf(float,int);
double overloaded __pow.powid(int,double);
double overloaded __pow.powii(int,int);
float overloaded  __pow.powf(float,float);
double _Complex overloaded __pow.cpow(double _Complex,double _Complex);
double _Complex overloaded __pow.cpowld(const double _Complex,double);
double _Complex overloaded __pow.cpowll(const double _Complex, double);
#define pow(a,b) __pow(a,b)

double _Complex clogl(const double _Complex x);
double overloaded __log.log(double);
long double overloaded __log.logl(long double);
float overloaded __log.logf(float);
double overloaded __log._logi(int);
double _Complex overloaded __log.clogl(double _Complex);
#define log(a) __log(a)

double overloaded __ldexp.ldexp(double,int);
long double overloaded __ldexp.ldexpl(long double,int);
float overloaded __ldexp.ldexpf(float,int);
#define ldexp(a,b) __ldexp(a,b)

double overloaded __scalbn.scalbn(double,int);
long double overloaded __scalbn.scalbnl(long double,int);
float overloaded __scalbn.scalbnf(float,int);
#define scalbn(a,b) __scalbn(a,b)

double _Complex cexpl(const double _Complex);
long double overloaded __exp.expl(long double);
double overloaded __exp.exp(double);
float overloaded __exp.expf(float);
double _Complex overloaded __exp.cexpl(const double _Complex);
#define exp(a) __exp(a)

long double overloaded __exp10.exp10l(long double);
double overloaded __exp10.exp10(double);
float overloaded __exp10.exp10f(float);

double overloaded __log1p.log1p(double);
float overloaded __log1p.log1pf(float);
long double overloaded __log1p.log1pl(long double);
#define log1p(a)	__log1p(a)

double _Complex csqrtl(double _Complex x);
long double overloaded __sqrt.sqrtl(long double);
double overloaded __sqrt.sqrt(double);
float overloaded __sqrt.sqrtf(float);
double overloaded __sqrt._sqrti(int);
double overloaded __sqrt._sqrtu(unsigned);
double overloaded __sqrt._sqrtll(long long);
double overloaded __sqrt._sqrtull(unsigned long long);
double _Complex overloaded __sqrt.csqrtl(double _Complex);
#define sqrt(a) __sqrt(a)

long double overloaded __log10.log10l(long double);
double overloaded __log10.log10(double);
float overloaded __log10.log10f(float);
#define log10(a) __log10(a)

long double overloaded __asinh.asinhl(long double);
double overloaded __asinh.asinh(double);
float overloaded __asinh.asinhf(float);
#define asinh(a) __asinh(a)

long double overloaded __acosh.acoshl(long double);
double overloaded __acosh.acosh(double);
float overloaded __acosh.acoshf(float);
#define acosh(a) __acosh(a)

long double overloaded __atanh.atanhl(long double);
double overloaded __atanh.atanh(double);
float overloaded __atanh.atanhf(float);
#define atanh(a) __atanh(a)

long double overloaded __lgamma.lgammal(long double);
double overloaded __lgamma.lgamma(double);
float overloaded __lgamma.lgammaf(float);
#define lgamma(a) __lgamma(a)

long double overloaded __tgamma.tgammal(long double);
double overloaded __tgamma.tgamma(double);
float overloaded __tgamma.tgammaf(float);
#define tgamma(a) __tgamma(a)

long double overloaded __hypot.hypotl(long double,long double);
double overloaded __hypot.hypot(double,double);
float overloaded __hypot.hypotf(float,float);
#define hypot(a,b) __hypot(a,b)

long double overloaded __log2.log2l(long double);
double overloaded __log2.log2(double);
float overloaded __log2.log2f(float);
double overloaded __log2._log2i(int);
double overloaded __log2._log2ll(long long);
#define log2(a) __log2(a)

long double overloaded __nearbyint.nearbyintl(long double);
double overloaded __nearbyint.nearbyint(double);
float overloaded __nearbyint.nearbyintf(float);
#define nearbyint(a) __nearbyint(a)

int overloaded __isinf._isinfd(double);
int overloaded __isinf.isinff(float);
int overloaded __isinf.isinfl(long double);
#define isinf(a) __isinf(a)

long double overloaded __sinh.sinhl(long double);
double overloaded __sinh.sinh(double);
float overloaded __sinh.sinhf(float);
#define sinh(a) __sinh(a)

long double overloaded __cosh.coshl(long double);
double overloaded __cosh.cosh(double);
float overloaded __cosh.coshf(float);
#define cosh(a) __cosh(a)

long double overloaded __ceil.ceill(long double);
double overloaded __ceil.ceil(double);
float overloaded __ceil.ceilf(float);
#define ceil(a) __ceil(a)

long double overloaded __erfc.erfcl(long double);
double overloaded __erfc.erfc(double);
float overloaded __erfc.erfcf(float);
#define erfc(a) __erfc(a)

long double overloaded __erf.erfl(long double);
double overloaded __erf.erf(double);
float overloaded __erf.erff(float);
#define erf(a) __erf(a)

long double overloaded __round.roundl(long double);
double overloaded __round.round(double);
float overloaded __round.roundf(float);
#define round(a) __round(a)

int overloaded __isfinite.isfinite(double);
int overloaded __isfinite.isfinitef(float);
int overloaded __isfinite.isfinitel(long double);
#define isfinite(a) __isfinite(a)

double overloaded __trunc.trunc(double);
float overloaded __trunc.truncf(float);
long double overloaded __trunc.truncl(long double);
#define trunc(a) __trunc(a)

int overloaded __lrint.lrint(double);
int overloaded __lrint.lrintf(float);
long overloaded __lrint.lrintl(long double);
#define lrint(a) __lrint(a)

long long overloaded __llrint.llrint(double);
long long overloaded __llrint.llrintf(float);
long long overloaded __llrint.llrintl(long double);
#define llrint(a) __llrint(a)

long overloaded __lround.lround(double);
long overloaded __lround.lroundf(float);
long overloaded __lround.lroundl(long double);
#define lround(a) __lround(a)

long long overloaded __llround.llround(double);
long long overloaded __llround.llroundf(float);
long long overloaded __llround.llroundl(long double);
#define llround(a) __llround(a)

int overloaded __isnan.isnand(double);
int overloaded __isnan.isnanl(long double);
int overloaded __isnan.isnanf(float);
#define isnan(a) __isnan(a)

int overloaded __isnormal.isnormalf(float);
int overloaded __isnormal.isnormal(double);
int overloaded __isnormal.isnormall(long double);
#define isnormal(a) __isnormal(a)

long double overloaded __remquo.remquol(long double,long double,int *);
double overloaded __remquo.remquo(double,double,int *);
float overloaded __remquo.remquof(float,float,int *);
#define remquo(a,b,c) __remquo(a,b,c)

long double overloaded __copysign.copysignl(long double,long double);
double overloaded __copysign.copysign(double,double);
float overloaded __copysign.copysignf(float,float);

long double overloaded __fmod.fmodl(long double , long double);
double overloaded __fmod.fmod(double,double);
float overloaded __fmod.fmodf(float,float);
#define fmod(a,b) __fmod(a,b)

int overloaded __fpclassify.__fpclassifyl(long double);
int overloaded __fpclassify.__fpclassifyd(double);
int overloaded __fpclassify.__fpclassifyf(float);
#define fpclassify(a)	__fpclassify(a)

long double overloaded __remainder.remainderl(long double,long double);
double overloaded __remainder.remainder(double,double);
float overloaded __remainder.remainderf(float,float);
#define remainder(a,b) __remainder(a,b)
#endif
