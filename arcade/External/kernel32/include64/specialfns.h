#ifndef __specialfns_h__
#define __specialfns_h__
#ifndef __math_h__
#include <math.h>
#endif
// Factorial
long double factoriall(int);
double factorial(double);
float factorialf(float);
// Table of factorials from 0 to 50 inclusive
extern long double __factorialTable[];

// Exponential integral with 1 arg
double expint(double x);
float expintf(float x);
long double expintl(long double x);
qfloat expintq(qfloat x);

// Exponential integral with two args
long double expintN(int n,long double x);
qfloat expintNq(int n,qfloat x);

// Bessel functions
// BesselJ is called jn in the POSIX standard
// Mathematica calls it BesselJ
long double BesselJ(int,long double);
// BesselY is called yn in the POSIX standard
// Mathematica calls it BesselY
long double BesselY(int,long double);
long double y0l(long double);
double y0(double);
long double y1l(long double);
long double j0l(long double);
double BesselK(int,double);
long double BesselKl(int, long double);
long double sph_bessel(int,long double);
double BesselI(int,double);

//--------------------------------------------------------
// Cylindrical bessel functions
//--------------------------------------------------------
double cyl_bessel_j(double,double);
qfloat cyl_bessel_jq(qfloat &nu,qfloat &x);

//-------------------------------------------------------
// Spherical bessel functions
//-------------------------------------------------------
long double SphericalBesselY(int,long double);
long double SphericalBesselJ(int,long double);
long double SphericalBesselK(int,long double);


// Incomplete gamma
long double igaml(long double, long double);
double igam(double a,double x);
long double igamcl(long double, long double);

double dbesi0(double);
double dbesi1(double);

// Struve function
double struve(double,double);

// Bessel function of non integer order
double jv(double n,double x );

// Confluent hypergeometric function
double hypergeom(double,double,double);

// Airy function. Solution of the differential equation y''(x) = xy
double airy(double,double *,double *,double *,double *);

// PSI (digamma)
double psi(double);
long double psil(long double);

// Harmonic numbers
double HarmonicNumber(unsigned);
long double HarmonicNumberl(unsigned);

// Elliptic functions
long double elliel(long double,long double);
long double ellpel(long double x);

// Complete elliptic integral of the first kind
long double ellipticKl(long double);
double ellipticK(double);

// Incomplete elliptic integral of the first kind
// Following Mathematica nomenclature
long double ellipticFl(long double,long double);

// Hypergeom2f1: confluent hypergeometric function.
long double hypergeom2f1(long double,long double,long double,long double);

double legendre(int,double);
long double legendrel(int,long double);
double hermite(int,double);
long double hermitel(int,long double);
double assoc_laguerre(int,int,double);
long double assoc_laguerrel(int,int,long double);

// Polynomials roots
int PolyRoots(long double *coeff, int degree, long double *zero_real, long double *zero_imag);
// Polynomial evaluation
double PolyEval(double x,double *coeff, int degree);
long double PolyEvall(long double x,long double *coeff, int degree);

// Constants: Calculate the nth constant of a series
int fibonacci(int);
long long fibonaccil(int);
qfloat fibonacciq(int);

// Binomial coefficient c(n,k)
long long ibinomial_coeff(int,int);
long double binomial_coeff(int,int);

// Bell numbers
void ibell(int n,long long b[]);

// Catalan numbers
int catalan(int n,long long results[static 1]);

// Lambert's W function
long double lambertw(long double);
unsigned long eulerphi(unsigned long);

// Stirling numbers (First and second kind)
double stirling1(int,int);
double stirling2(int,int);

// Bernoulli numbers
qfloat Bernoulliq(unsigned);

// Zetac function
// Rieman Zeta = zetac+1
double zetac(double);
long double zetacl(long double);

//Pochhammer symbol
double pochhammer(double,int);
long double pochhammerl(long double,int);

//
// Fresnel Integral
//
void Fresnel(double x, double *S, double *C);
double FresnelS(double);
double FresnelC(double);
void Fresnelq(qfloat &x,qfloat &S,qfloat &C);

//------------------------------------------------------
// Complex bessel functions
//------------------------------------------------------
long double _Complex CBesselY(long double _Complex order,
			long double _Complex argument,
			int KODE, int *NZ, int *IERR);

long double _Complex HankelH2(long double _Complex order,
			  long double _Complex argument,
			  int scaled);

long double _Complex CBesselJ(long double _Complex order, 
			long double _Complex argument, 
			int scaled,int *NZ,int *IERR);
//-----------------------------------------------------
// Airy functions
//-----------------------------------------------------
long double _Complex AiryAl(long double _Complex);
double _Complex AiryA(double _Complex);
long double _Complex AiryBl(long double _Complex);
double _Complex AiryB(double _Complex);
// Airy Prime functions
long double _Complex AiryAPrimel(long double _Complex);
double _Complex AiryAPrime(double _Complex);
long double _Complex AiryBPrimel(long double _Complex);
double _Complex AiryBPrime(double _Complex);
#endif
