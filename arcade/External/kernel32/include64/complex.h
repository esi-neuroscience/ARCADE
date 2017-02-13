#ifndef __complex_h__
#define __complex_h__
#include <math.h>
#ifndef __ANSIC__ONLY__
#include <iostream.h>
#endif
extern double log1p(double);
#ifndef __ANSIC__ONLY__
//------------------------------------------------------------
// _Complex data structure
// It is now automatically defined by the compiler at startup for
// the types float, double
//typedef struct __complex {
//	double re;
//	double im;
//} _Complex;
#define creal(a) (a.re)
#define cimag(a) (a.im)
#define creall(a) (a.re)
#define cimagl(a) (a.im)
#define cimagf(a) (a.im)
#define crealf(a) (a.re)
#define complex _Complex
#ifndef __ANSIC__ONLY__
double _Complex operator += (double _Complex &a,double _Complex r);
double _Complex operator -= (double _Complex &a,const double _Complex r);
double _Complex operator *=(double _Complex &a,const double _Complex r);
double _Complex operator +(double _Complex x, double _Complex y);
//
// Addition operator
//
double _Complex operator +(const double _Complex x, const double _Complex y);
double _Complex operator += (double _Complex a,const double _Complex r);
double _Complex operator += (double _Complex a,const double _Complex r);
double _Complex operator+(double,const double _Complex);
double _Complex operator+(double,const double _Complex);
double _Complex operator +(double _Complex x, double y);
//
// Minus operator
//
double _Complex operator -(const double _Complex x, const double _Complex y);
double _Complex operator -(const double _Complex x, double y);
double _Complex operator -(double x, const double _Complex y);
double _Complex operator -(const double _Complex x, double y);
double _Complex operator -(const double y,const double _Complex x);
double _Complex operator -(const double x, const double _Complex y);
double _Complex operator-(const double x,const double _Complex y);
//
// Multiplication
//
//double _Complex operator * (const double _Complex x, const double _Complex y);
double _Complex operator * (const double _Complex x, double y);
double _Complex operator * (const double _Complex x, const float _Complex y);
double _Complex operator*(const float _Complex x,const double _Complex y);
double _Complex operator*(const double _Complex x,const float _Complex y);
double _Complex operator * (double x, const double _Complex y);
double _Complex operator*(double x,const float _Complex y);
double _Complex operator * (const double _Complex x, const double _Complex y);
double _Complex operator * (const double _Complex x, const float _Complex y);
double _Complex operator * (const double _Complex x, const float _Complex y);
double _Complex operator * (const double _Complex x, double y);
double _Complex operator * (const double _Complex x, double y);
double _Complex operator * (double x, const double _Complex y);
double _Complex operator *(double x,const float _Complex y);
double _Complex operator *(double x,const float _Complex y);
//double _Complex operator *(const float _Complex x,double y);
//
// division
//
double _Complex operator / (const double _Complex x, double y);
double _Complex operator /= (double _Complex &a,const double _Complex y);
//double _Complex operator / (const double _Complex x, const double _Complex y);
double _Complex operator / (double x, const double _Complex y);
double _Complex operator / (const double _Complex x, double _Complex y);
double _Complex operator - (const double _Complex x);
int operator == (const double _Complex x, const double _Complex y);
int operator == (const double _Complex x, double y);
int operator == (double x, const double _Complex y);
int operator != (const double _Complex x, const double _Complex y);
int operator != (const double _Complex x, double y);
int operator != (double x, const double _Complex y);
//
// Casts
//
double _Complex operator()(double _Complex &a);
double _Complex operator()(double _Complex &a);
double _Complex operator()(float _Complex &a);
double _Complex operator()(float _Complex &a);
double _Complex operator()(double ld);
double _Complex operator()(double d);
double _Complex operator()(double);
double _Complex operator()(double);
double _Complex operator()(int);
//
//Assignments
//
double _Complex operator=(double _Complex &a,double d);
double _Complex operator=(double _Complex &a,double _Complex d);
double _Complex operator=(double _Complex &a,double _Complex d);
double _Complex operator=(double _Complex &a,float _Complex d);
float _Complex operator=(float _Complex &a,double _Complex d);
double _Complex operator=(double _Complex &a,float _Complex d);
float _Complex operator=(float _Complex &d,double _Complex a);
#endif


extern float _Complex I;
double norm (const double _Complex);
// cabs
double cabs(const double _Complex x);
long double cabsl(double _Complex);
float cabsf(float _Complex);

double arg(const double _Complex x);
// conj
double _Complex conj(const double _Complex x);
double _Complex conjl(const double _Complex x);
float _Complex conjf(const float _Complex x);

//ccos
double _Complex ccos(const double _Complex);
double _Complex ccosl(const double _Complex);
float _Complex ccosf(const float _Complex);

//cacos
double _Complex cacos(const double _Complex);
double _Complex cacosl(const double _Complex);
float _Complex cacosf(const float _Complex);

// ccosh
double _Complex ccosh (const double _Complex x);
double _Complex ccoshl(double _Complex);
float _Complex ccoshf(float _Complex x);

//ctanh
double _Complex ctanh(double _Complex);
double _Complex ctanhl(double _Complex);
float _Complex ctanhf(float _Complex);

//ctan
double _Complex ctan(double _Complex);
double _Complex ctanl(double _Complex);
float _Complex ctanf(float _Complex);

//catan
double _Complex catan(double _Complex);
double _Complex catanl(double _Complex);
float _Complex catanf(float _Complex);

double _Complex c_polar (double r, double t);
// Cexp
double _Complex cexp(const double _Complex x);
double _Complex cexpl(double _Complex x);
float _Complex cexpf(float _Complex x);

// Clog
double _Complex clog(const double _Complex x);
double _Complex clogl(double _Complex x);
float _Complex clogf(float _Complex x);

// Cpow
double _Complex cpow(const double _Complex x,const double _Complex y);
double _Complex cpowl(double _Complex x,double _Complex y);
float _Complex cpowf(float _Complex x,float _Complex y);

// Csqrt
double _Complex csqrt(const double _Complex x);
double _Complex csqrtl(double _Complex x);
float _Complex csqrtf(float _Complex x);

// csin
double _Complex csin(const double _Complex x);
double _Complex csinl(double _Complex x);
float _Complex csinf(float _Complex x);

// casin
double _Complex casin(double _Complex);
double _Complex casinl(double _Complex);
float _Complex casinf(float _Complex);

double _Complex csinh(const double _Complex);
double _Complex csinhl(double _Complex);
float _Complex csinhf(float _Complex);

// CASINH
double _Complex casinh(const double _Complex);
double _Complex casinhl(double _Complex);
float _Complex casinhf(float _Complex);

// CACOSH
double _Complex cacosh(const double _Complex);
double _Complex cacoshl(double _Complex);
float _Complex cacoshf(float _Complex);

// CATANH
double _Complex catanh(const double _Complex);
double _Complex catanhl(double _Complex);
float _Complex catanhf(float _Complex);

#ifndef __ANSIC__ONLY__
iostream* operator << (iostream* os, double _Complex x);
#endif
double _Complex c_intpow (const double _Complex xin, int y);


double carg(const double _Complex);
double cargl(double _Complex);

double _Complex cerf(double _Complex);
#endif

#endif
