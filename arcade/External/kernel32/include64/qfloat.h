#ifndef __qfloat_h__
#define __qfloat_h__
#ifndef __math_h__
#include <math.h>
#endif
#ifdef DLL
#define EXPORT __declspec(dllexport)
#ifndef __NO_AUTOMATIC_LIB__
#define IMPORT __declspec(dllimport)
#else
#define IMPORT
#endif
#else
#define EXPORT
#define IMPORT
#endif
#if 0

// Qfloats are now bult-in in the compiler. The definition used is this one though, and it
// is left here for documentation purposes

#define _NQ_	12
typedef struct qfloatstruct {
  int sign;
  int exponent;
  unsigned int mantissa[_NQ_];
}qfloat;
#endif
void _stdcall qclear (qfloat &);
void e24toq (const float *, qfloat *);
void e64toq(const long double *,qfloat *);
void etoq (const double *, qfloat *);
void ltoq (long int *, qfloat *);
void lltoq(long long *, qfloat &);

void asctoq (const char *, qfloat *);

void _stdcall qadd (const qfloat &, const qfloat &, qfloat &);
void _stdcall qsub (const qfloat &, const qfloat &, qfloat &);
void _stdcall qmul (const qfloat &, const qfloat &, qfloat &);
void _stdcall qdiv (const qfloat &, const qfloat &, qfloat &);
int qcmp (const qfloat &, const qfloat &);
void qtoasc (const qfloat *, char *, const int);
void qtoe24 (const qfloat *, float *);
void qtoe (const qfloat *, double *);
void qtoe64 (const qfloat *, long double *);
void qtoe113 (const qfloat *, long double *);
void qifrac (const qfloat *, long *, qfloat *);
void qabs (qfloat &);
void qneg (qfloat &);
qfloat sqrtq(qfloat &);
qfloat overloaded __sqrt.sqrtq(qfloat &);
int mtherr (char *, int);
void qfloor (const qfloat &, qfloat &);
qfloat fdimq(qfloat &x,qfloat &y);
qfloat overloaded __fdim.fdimq(qfloat &x,qfloat &y);
qfloat overloaded __floor(qfloat &);
qfloat overloaded __log(qfloat &);
qfloat log10q(qfloat &);
qfloat fabsq(qfloat &);
qfloat overloaded __fabs.fabsq(qfloat &);
qfloat powq(qfloat &,qfloat &);
qfloat overloaded __pow.powq(qfloat &,qfloat &);
qfloat cbrtq(qfloat &);
qfloat overloaded __cbrt.cbrtq(qfloat &);
qfloat qpow (qfloat &, qfloat &);
void qfpow(qfloat *x,qfloat *y,qfloat *result);
void qfexp (const qfloat *, qfloat *);
void qexp10(qfloat *x,qfloat *y);
void qfsin (const qfloat *, qfloat *);
void qfcos (const qfloat *, qfloat *);
void qftan(const qfloat *,const qfloat *);
void qremain (const qfloat *, const qfloat *, qfloat *);
qfloat qnew(void);
qfloat *qeuclid(qfloat *,qfloat *,qfloat *);
qfloat qratio(int,int);
qfloat qratiol(long long numerator,long long denominator);
qfloat frexpq(qfloat &x,int *exp);
qfloat overloaded __frexp.frexpq(qfloat &,int *);
qfloat roundq(qfloat &x);
qfloat overloaded __round.roundq(qfloat &);
qfloat qipow(qfloat &x,qfloat &y);
qfloat acoshq(qfloat &);
qfloat overloaded __acosh.acoshq(qfloat &);
qfloat asinhq(qfloat &);
qfloat overloaded __asinh.asinhq(qfloat &);
qfloat atanhq(qfloat &);
qfloat overloaded __atanh.atanhq(qfloat &);
qfloat sinhq(qfloat &);
qfloat overloaded __sinh.sinhq(qfloat &);
qfloat coshq(qfloat &);
qfloat overloaded __cosh.coshq(qfloat &);
qfloat tanhq(qfloat &);
qfloat overloaded __tanh.tanhq(qfloat &);
qfloat atanq(qfloat &);
qfloat overloaded __atan.atanq(qfloat &);
qfloat asinq(qfloat &);
qfloat overloaded __asin.asinq(qfloat &);
qfloat acosq(qfloat &);
qfloat overloaded __acos.acosq(qfloat &);
int ilogbq(qfloat &);
qfloat logq(qfloat &);
qfloat remquoq(qfloat &,qfloat &,int *);
qfloat overloaded __remquo.remquoq(qfloat &,qfloat &,int *);

qfloat overloaded __log.logq(qfloat &);
qfloat ldexpq(qfloat &,long);
qfloat expm1q(qfloat &);
qfloat overloaded __expm1.expm1q(qfloat &);
qfloat log1pq(qfloat &);
qfloat overloaded __log1p.log1pq(qfloat &);
qfloat erfq(qfloat &);
qfloat overloaded __erf.erfq(qfloat &);
qfloat erfcq(qfloat &);
qfloat overloaded __erfc.erfcq(qfloat &);
qfloat lgammaq(qfloat &);
qfloat overloaded __lgamma.lgammaq(qfloat &);
qfloat tgammaq(qfloat &);
qfloat overloaded __tgamma.tgammaq(qfloat &);
qfloat floorq(qfloat &);
qfloat overloaded __floor.floorq(qfloat &);
qfloat ceilq(qfloat &);
qfloat overloaded __ceil.ceilq(qfloat &);
qfloat log2q(qfloat &);
qfloat overloaded __log2.log2q(qfloat &);
qfloat scalbnq(qfloat &x,int n);
qfloat overloaded __scalbn.scalbnq(qfloat &,int);
qfloat hypotq(qfloat &x,qfloat &y);
qfloat overloaded __hypot.hypotq(qfloat &,qfloat &);


// Conversions

qfloat operator()(int);
qfloat operator()(double);
qfloat operator()(long double);
qfloat operator()(long long);
qfloat operator()(unsigned int);

double operator()(qfloat &);
int operator()(qfloat &);
long long operator()(qfloat &);
long double operator()(qfloat &);

int qtoi (qfloat &x);
float qtof (qfloat &x);
double qtod (qfloat &x);
long double qtold (qfloat &x);
int qtol(qfloat &x);
unsigned int operator()(qfloat &);

qfloat overloaded __sqrt(qfloat &x);
qfloat expq(qfloat &x);
qfloat logbq(qfloat &x);
qfloat overloaded __exp.expq(qfloat &x);
qfloat exp2q(qfloat &);
qfloat overloaded __exp2.exp2q(qfloat &);
qfloat sinq(qfloat &x);
qfloat overloaded __sin.sinq(qfloat &);
qfloat cosq(qfloat &x);
qfloat overloaded __cos.cosq(qfloat &);
qfloat tanq(qfloat &);
qfloat overloaded __tan.tanq(qfloat &);
qfloat overloaded __copysign(qfloat &,qfloat &);
qfloat overloaded __tan.tanq(qfloat &);

// Arithmetic operators.
// += operator
qfloat &operator += (qfloat & x, const qfloat & y);
// + operator
qfloat operator + (const qfloat & x, const qfloat & y);
// - operator
qfloat operator - (const qfloat & x, const qfloat & y);

// Unary negation.
qfloat operator - (const qfloat & x);

// -= operator
qfloat operator -= (qfloat & x, const qfloat & y);
// * operator
qfloat operator * (const qfloat & x, const qfloat & y);
// *= operator
qfloat operator *= (qfloat & x, const qfloat & y);
// / operator
qfloat operator / (const qfloat & x, const qfloat & y);
// /= operator
qfloat operator /= (qfloat & x, const qfloat & y);

// Comparisons.
// == operator
int operator == (const qfloat & x, const qfloat & y);

// != operator
int operator != (const qfloat & x, const qfloat & y);

// < operator
int operator < (const qfloat & x, const qfloat & y);

// > operator
int operator >(const qfloat & x, const qfloat & y);

int operator >= (const qfloat & x, const qfloat & y);

int operator <= (const qfloat & x, const qfloat & y);

qfloat operator()(int n);

qfloat operator !(qfloat &q);

// Assignment operator
qfloat operator=(qfloat &,int);
qfloat operator=(qfloat &,double);
qfloat operator=(qfloat &,long double);
double operator=(double &,qfloat &);
qfloat operator=(qfloat &a,char *s);
qfloat operator=(qfloat &a,float);

// Exact remainder of x/y.
qfloat modfq(const qfloat & x, const qfloat &y);
int qfact( qfloat *x, qfloat *y);
qfloat qfabs (const qfloat & x);
// classification functions
int isfiniteq(qfloat &a);
int overloaded __isfinite.isfiniteq(qfloat &);
// Print decimal value of X with N digits.  Precede value with string s1,
// follow with string s2.
#include <stdio.h>
int signbitq(qfloat &);
void qprint ( const int n, const char *s1, const qfloat &x, const char *s2);
extern qfloat IMPORT qzero;
extern qfloat IMPORT qtens;
extern qfloat IMPORT qone;
extern qfloat IMPORT qtwo;
extern qfloat IMPORT qhalf;
extern qfloat IMPORT qpi;
#define crealq(a) (a.re)
#define cimagq(a) (a.im)
#if 0
qfloat _Complex operator+(qfloat _Complex &a,qfloat _Complex &b);
qfloat _Complex operator-(qfloat _Complex &a,qfloat _Complex &b);
qfloat _Complex operator*(qfloat _Complex &a,qfloat _Complex &b);
qfloat _Complex operator/(qfloat _Complex &a,qfloat _Complex &b);

qfloat _Complex operator()(long double _Complex &);
qfloat _Complex operator()(double _Complex &);
qfloat _Complex operator()(float _Complex &);
qfloat _Complex operator=(qfloat _Complex &a,int v);
qfloat _Complex operator=(qfloat _Complex &a,long double v);
qfloat _Complex operator=(qfloat _Complex &a,long double _Complex &v);
qfloat cabsq(qfloat _Complex &);
qfloat overloaded __cabs(qfloat _Complex &);
qfloat _Complex csinq(qfloat _Complex &a);
qfloat _Complex ccosq(qfloat _Complex &a);
qfloat _Complex ctanq(qfloat _Complex &a);
qfloat _Complex ccoshq(qfloat _Complex &);
qfloat _Complex csinhq(qfloat _Complex &);
qfloat _Complex ctanhq(qfloat _Complex &);
qfloat _Complex cacosq(qfloat _Complex &);
qfloat _Complex casinq(qfloat _Complex &);
qfloat _Complex catanq(qfloat _Complex &);
qfloat _Complex casinhq(qfloat _Complex &);
qfloat _Complex casinhq(qfloat _Complex &);
qfloat _Complex cacoshq(qfloat _Complex &);
qfloat _Complex catanhq(qfloat _Complex &);
qfloat _Complex cexpq(qfloat _Complex &);
qfloat _Complex clogq(qfloat _Complex &);
qfloat _Complex cpowq(qfloat _Complex &,qfloat _Complex &);
qfloat _Complex cpowq(qfloat _Complex &,qfloat _Complex &);
qfloat _Complex csqrtq(qfloat _Complex &);
#endif
qfloat j0q(qfloat &);
qfloat y0q(qfloat &);
qfloat j1q(qfloat &);
qfloat y1q(qfloat &);
qfloat betaq(qfloat &a,qfloat &b);
qfloat ynq(qfloat &,qfloat &);
qfloat fmaxq(qfloat &,qfloat &);
qfloat fminq(qfloat &x,qfloat &y);
qfloat overloaded __fmin.fminq(qfloat &,qfloat &);
void qigam(qfloat *a,qfloat *x,qfloat *y);
#pragma lib <qfloat.lib>
#endif /* __QFLOAT_H */
