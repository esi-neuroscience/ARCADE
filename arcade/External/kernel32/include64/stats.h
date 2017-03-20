#ifndef __stats_h__
#define __stats_h__
// Beta distribution
long double beta_distribution(long double a,long double b, long double x);
// Beta distribution inverse
long double beta_distribution_inv(long double, long double, long double);
//Incomplete beta integral.
long double beta_incomplete (long double a,long double b,long double x);
//Inverse of incomplete beta integral.
long double beta_incomplete_inv (long double a,long double b,long double y);
//Binomial distribution function.
long double binomial(unsigned int k, unsigned int n, long double p);
//Binomial distribution function complemented.
long double binomial_c(unsigned int k, unsigned int n, long double p);
//Binomial distribution function inverse
long double binomial_inv(unsigned int k, unsigned int n , long double y);
//Negative binomial distribution .
long double binomial_neg_distribution(unsigned int k, unsigned int n,long double p);
//Negative binomial distribution complement.
long double binomial_neg_distribution_c (unsigned int k, unsigned int n,long double p);
//Inverse of negative binomial distribution.
long double binomial_neg_distribution_inv(unsigned int k, unsigned int n,long double p);
//Chi-squared distribution function.
long double chi_sqr_distribution(long double df,long double x);
//Chi-squared distribution function complemented.
long double chi_sqr_distribution_c(long double df, long double x);
//Inverse of Chi-squared distribution function complemented.
long double chi_sqr_distribution_cinv(long double df,long double p);
// Fisher distribution
long double fisher_distribution(unsigned int a, unsigned int b,long double c);
//Fisher F distribution complemented.
long double fisher_distribution_c(unsigned int ia, unsigned int ib,long double c); 
// Inverse Fischer distribution
long double fisher_distribution_inv(long double dfn,long double dfd,long double y);
// Inverse fisher distribution complemented
long double fisher_distribution_cinv(int a,int b,long double y);
//Gamma probability distribution function complemented.
long double gamma_distribution_c(long double a,long double b,long double x);
//Incomplete gamma function.
long double gamma_incomplete (long double a,long double x);
//Incomplete gamma function complemented.
long double gamma_incomplete_c(long double a,long double x);
//Inverse of incomplete gamma integral.
long double gamma_incomplete_cinv (long double a,long double y0);
//Inverse of complemented incomplete gamma integral.
long double gamma_incomplete_cinv (long double a,long double y0);
//Normal distribution function.
long double normal_distribution (long double a);
//Inverse of normal distribution function.
long double normal_distribution_inv (long double a);
//Poisson distribution.
long double poisson_distribution (unsigned int k, long double m);
//Complemented Poisson distribution.
long double poisson_distribution_c(unsigned int k,long double m);
//Inverse Poisson distribution.
long double poisson_distribution_inv(unsigned int k,long double y);
//Digamma (PSI) function
long double digamma(long double);
//Student's t
long double students_t (int df,long  double t); 
//Inverse of Student's t.
long double students_t_inv (int df,long double p); 
//Kolmogorov statistic.
long double kolmogorov ( long double ); 
//Kolmogorov statistic inverse.
long double kolmogorov_inv (long double p);
//Exact Smirnov statistic
long double smirnov (int n,long double e);
//Inverse Smirnov
long double smirnov_inv(int n,long double);
// median
long double medianl(long double *data,int n);
double median(double *data,int n);
float medianf(float *data,int n);
// geometric mean
long double geometric_meanl(long double *data,int n);
double geometric_mean(double *data,int n);
float geometric_meanf(float *data,int n);
// arithmetic mean
long double arithmetic_meanl(long double *data,int n);
double arithmetic_mean(double *data,int n);
float arithmetic_meanf(float *data,int n);
// harmonic mean
long double harmonic_meanl(long double *data,int n);
double harmonic_mean(double *data,int n);
float harmonic_meanf(float *data,int n);
// variance
long double variancel(long double *data,int n);
double variance(double *data,int n);
float variancef(float *data,int n);
// variance_mle
long double variance_mlel(long double *data,int n);
double variance_mle(double *data,int n);
float variance_mlef(float *data,int n);
// standard deviation
long double standard_deviationl(long double *data,int n);
double standard_deviation(double *data,int n);
float standard_deviationf(float *data,int n);
// standard deviation Maximum Likehood Estimate
long double standard_deviation_mlel(long double *data,int n);
double standard_deviation_mle(double *data,int n);
float standard_deviation_mlef(float *data,int n);
// root mean square
long double rmsl(long double *data,int n);
double rms(double *data,int n);
float rmsf(float *data,int n);
// central moment
long double central_momentl(long double *data,int n,long double K);
double central_moment(double *data,int n,double K);
float central_momentf(float *data,int n,float K);
// percentile
long double percentilel(long double *data,int n,long double K);
double percentile(double *data,int n,double K);
float percentilef(float *data,int n,float K);
// skewness
long double skewnessl(long double *data,int n);
double skewness(double *data,int n);
float skewnessf(float *data,int n);
// kurtosis
long double kurtosisl(long double *data,int n);
double kurtosis(double *data,int n);
float kurtosisf(float *data,int n);

//#pragma lib <stats.lib>
#endif
