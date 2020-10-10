/*  math.h

    Definitions for the math floating point package.

    Copyright (c) 1987, 1991 by Borland International
    All Rights Reserved.
*/

#ifndef  __MATH_H
#define  __MATH_H

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

#define HUGE_VAL    _huge_dble
extern double _Cdecl _huge_dble;
#define _LHUGE_VAL   _huge_ldble
extern long double _Cdecl _huge_ldble;

#ifdef __cplusplus
extern "C" {
#endif
double  _Cdecl acos  (double __x);
double  _Cdecl asin  (double __x);
double  _Cdecl atan  (double __x);
double  _Cdecl atan2 (double __y, double __x);
double  _Cdecl ceil  (double __x);
double  _Cdecl cos   (double __x);
double  _Cdecl cosh  (double __x);
double  _Cdecl exp   (double __x);
double  _Cdecl fabs  (double __x);
double  _Cdecl __fabs__  (double __x);          /* Intrinsic */
double  _Cdecl floor (double __x);
double  _Cdecl fmod  (double __x, double __y);
double  _Cdecl frexp (double __x, int *__exponent);
double  _Cdecl ldexp (double __x, int __exponent);
double  _Cdecl log   (double __x);
double  _Cdecl log10 (double __x);
double  _Cdecl modf  (double __x, double *__ipart);
double  _Cdecl pow   (double __x, double __y);
double  _Cdecl sin   (double __x);
double  _Cdecl sinh  (double __x);
double  _Cdecl sqrt  (double __x);
double  _Cdecl tan   (double __x);
double  _Cdecl tanh  (double __x);

long double _Cdecl acosl  (long double __x);
long double _Cdecl asinl  (long double __x);
long double _Cdecl atan2l (long double __x, long double __y);
long double _Cdecl atanl  (long double __x);
long double _Cdecl ceill  (long double __x);
long double _Cdecl coshl  (long double __x);
long double _Cdecl cosl   (long double __x);
long double _Cdecl expl   (long double __x);
long double _Cdecl fabsl  (long double __x);
long double _Cdecl floorl (long double __x);
long double _Cdecl fmodl  (long double __x, long double __y);
long double _Cdecl frexpl (long double __x, int *__exponent);
long double _Cdecl ldexpl (long double __x, int __exponent);
long double _Cdecl log10l (long double __x);
long double _Cdecl logl   (long double __x);
long double _Cdecl modfl  (long double __x, long double *__ipart);
long double _Cdecl powl   (long double __x, long double __y);
long double _Cdecl sinhl  (long double __x);
long double _Cdecl sinl   (long double __x);
long double _Cdecl sqrtl  (long double __x);
long double _Cdecl tanhl  (long double __x);
long double _Cdecl tanl   (long double __x);

typedef enum
{
    DOMAIN = 1,    /* argument domain error -- log (-1)        */
    SING,          /* argument singularity  -- pow (0,-2))     */
    OVERFLOW,      /* overflow range error  -- exp (1000)      */
    UNDERFLOW,     /* underflow range error -- exp (-1000)     */
    TLOSS,         /* total loss of significance -- sin(10e70) */
    PLOSS,         /* partial loss of signif. -- not used      */
    STACKFAULT     /* floating point unit stack overflow       */
}   _mexcep;

#ifdef __cplusplus
}
#endif


#if !__STDC__

struct  exception 
{
    int type;
    char   *name;
    double  arg1, arg2, retval;
};

struct  _exceptionl
{
    int type;
    char   *name;
    long double  arg1, arg2, retval;
};

#ifdef __cplusplus
extern "C" {
#endif
int     _Cdecl abs   (int __x);
double  _Cdecl atof  (const char *__s);
double  _Cdecl hypot (double __x, double __y);
long    _Cdecl labs  (long __x);
int     _Cdecl matherr (struct exception *__e);
double  _Cdecl poly  (double __x, int __degree, double *__coeffs);
double  _Cdecl pow10 (int __p);
int     _Cdecl _matherrl (struct _exceptionl *__e);

long double _Cdecl _atold (const char *__s);
long double _Cdecl hypotl (long double __x, long double __y);
long double _Cdecl polyl  (long double __x, int __degree, long double *__coeffs);
long double _Cdecl pow10l (int __p);

#ifdef __cplusplus
    /* use class complex instead of cabs in C++ */
#else
struct complex      /* as used by "cabs" function */
{
    double  x, y;
};

struct _complexl    /* as used by "cabsl" function */
{
    long double  x, y;
};

#define cabs(z)     (hypot  ((z).x, (z).y))
#define cabsl(z)    (hypotl ((z).x, (z).y))
#endif

#ifdef __cplusplus
}
#endif

/* Constants rounded for 21 decimals. */
#define M_E         2.71828182845904523536
#define M_LOG2E     1.44269504088896340736
#define M_LOG10E    0.434294481903251827651
#define M_LN2       0.693147180559945309417
#define M_LN10      2.30258509299404568402
#define M_PI        3.14159265358979323846
#define M_PI_2      1.57079632679489661923
#define M_PI_4      0.785398163397448309616
#define M_1_PI      0.318309886183790671538
#define M_2_PI      0.636619772367581343076
#define M_1_SQRTPI  0.564189583547756286948
#define M_2_SQRTPI  1.12837916709551257390
#define M_SQRT2     1.41421356237309504880
#define M_SQRT_2    0.707106781186547524401

#define EDOM    33      /* Math argument */
#define ERANGE  34      /* Result too large */

#endif  /* !__STDC__ */

#endif
