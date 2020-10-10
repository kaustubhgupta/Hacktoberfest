/*  stdlib.h

    Definitions for common types, variables, and functions.

    Copyright (c) 1987, 1991 by Borland International
    All Rights Reserved.
*/

#ifndef __STDLIB_H
#define __STDLIB_H

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

#ifndef NULL
#include <_null.h>
#endif

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned size_t;
#endif

#ifndef _DIV_T
#define _DIV_T
typedef struct {
        int     quot;
        int     rem;
} div_t;
#endif

#ifndef _LDIV_T
#define _LDIV_T
typedef struct {
        long    quot;
        long    rem;
} ldiv_t;
#endif

#ifndef _WCHAR_T
#define _WCHAR_T
typedef char wchar_t;
#endif

/* Old typedef 
*/
typedef void _Cdecl (* atexit_t)(void);

/* Maximum value returned by "rand" function
*/
#define RAND_MAX 0x7FFFU

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define MB_CUR_MAX 1

#ifdef __cplusplus
extern "C" {
#endif

void        _Cdecl abort(void);
int         _Cdecl __abs__(int);
#ifdef __cplusplus
inline int _Cdecl  abs(int __x) { return __abs__(__x); }
#else
int         _CType abs(int __x);
#  define abs(x)   __abs__(x)
#endif
int         _Cdecl atexit(void (_Cdecl *__func)(void));
double      _Cdecl atof(const char *__s);
int         _CType atoi(const char *__s);
long        _CType atol(const char *__s);
void * _CType bsearch(const void *__key, const void *__base,
               size_t __nelem, size_t __width,
               int (_CType *fcmp)(const void *,
               const void *));
void * _Cdecl calloc(size_t __nitems, size_t __size);
div_t       _Cdecl div(int __numer, int __denom);
void        _Cdecl exit(int __status);
void        _Cdecl free(void *__block);
char * _CType getenv(const char *__name);
long        _Cdecl labs(long __x);
ldiv_t      _Cdecl ldiv(long __numer, long __denom);
void * _Cdecl malloc(size_t __size);
int         _Cdecl mblen(const char *__s, size_t __n);
size_t      _Cdecl mbstowcs(wchar_t *__pwcs, const char *__s,
            size_t __n);
int     _Cdecl mbtowc(wchar_t *__pwc, const char *__s, size_t __n);
void    _CType qsort(void *__base, size_t __nelem, size_t __width,
        int _CType (*__fcmp)(const void *, const void *));
int     _Cdecl rand(void);
void *_Cdecl realloc(void *__block, size_t __size);
void    _Cdecl srand(unsigned __seed);
double  _Cdecl strtod(const char *__s, char **__endptr);
long    _Cdecl strtol(const char *__s, char **__endptr,
              int __radix);
long double _Cdecl _strtold(const char *__s, char **__endptr);
unsigned long _Cdecl strtoul(const char *__s, char **__endptr,
                 int __radix);
int     _Cdecl system(const char *__command);
size_t  _Cdecl wcstombs(char *__s, const wchar_t *__pwcs,
            size_t __n);
int     _Cdecl wctomb(char *__s, wchar_t __wc);

#ifdef __cplusplus
}
#endif

#if !__STDC__

/* Variables */

extern  int   _Cdecl _doserrno;
extern  int   _Cdecl errno;

/*
  These 2 constants are defined in MS's stdlib.h.  Rather than defining them
  all the time and invading the ANSI programmers name space we'll only make
  them visible when __STDC__ is *off*.  Anybody using these constants ain't
  writing standard C anyway!
*/
#define DOS_MODE  0
#define OS2_MODE  1

extern  unsigned        _Cdecl _psp;

extern  char          **_Cdecl environ;
extern  int             _Cdecl _fmode;
extern  unsigned char   _Cdecl _osmajor;
extern  unsigned char   _Cdecl _osminor;
extern  unsigned int    _Cdecl _version;

extern  char           *_Cdecl sys_errlist[];
extern  int             _Cdecl sys_nerr;

/* Constants for MSC pathname functions */

#define _MAX_PATH       80
#define _MAX_DRIVE      3
#define _MAX_DIR        66
#define _MAX_FNAME      9
#define _MAX_EXT        5

#ifdef __cplusplus
inline int _Cdecl random(int __num)
                 { return(int)(((long)rand()*__num)/(RAND_MAX+1)); }
/* need prototype of time() for C++ randomize() */
extern "C" long _Cdecl time(long *);  
inline void _Cdecl randomize(void) { srand((unsigned) time(NULL)); }
inline int  _Cdecl atoi(const char *__s) { return (int) atol(__s); }
#else
#define random(num)(int)(((long)rand()*(num))/(RAND_MAX+1))
#define randomize()     srand((unsigned)time(NULL))
#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))
#define atoi(s)     ((int) atol(s))
#endif

#ifdef __cplusplus
extern "C" {
#endif

long double _Cdecl _atold(const char *__s);
char   *_Cdecl ecvt(double __value, int __ndig, int *__dec,
             int *__sign);
void    _Cdecl _exit(int __status);
char   *_Cdecl fcvt(double __value, int __ndig, int *__dec,
            int *__sign);
char * _CType _fullpath( char *__buf,
                  const char *__path,
                  size_t __maxlen );
char   *_Cdecl gcvt(double __value, int __ndec, char *__buf);
char   *_CType itoa(int __value, char *__string, int __radix);
void   *_Cdecl lfind(const void *__key, const void *__base,
         size_t *__num, size_t __width,
         int _Cdecl(*__fcmp)(const void *, const void *));

unsigned long _Cdecl _lrotl(unsigned long __val, int __count);
unsigned long _Cdecl _lrotr(unsigned long __val, int __count);

void   *_Cdecl lsearch(const void *__key, void *__base,
         size_t *__num, size_t __width,
         int _Cdecl(*__fcmp)(const void *, const void *));
char * _CType ltoa(long __value, char *__string, int __radix);
void _Cdecl _makepath( char *__path,
                  const char *__drive,
                  const char *__dir,
                  const char *__name,
                  const char *__ext );
int     _Cdecl putenv(const char *__name);

unsigned    _Cdecl _rotl(unsigned __value, int __count);
unsigned    _Cdecl _rotr(unsigned __value, int __count);

unsigned    _Cdecl __rotl__(unsigned __value, int __count);     /* intrinsic */
unsigned    _Cdecl __rotr__(unsigned __value, int __count);     /* intrinsic */

void        _Cdecl _searchenv(const char *__file,
                  const char *__varname,
                  char *__pathname);
void _Cdecl _splitpath( const char *__path,
                   char *__drive,
                   char *__dir,
                   char *__name,
                   char *__ext );
void    _Cdecl swab(char *__from, char *__to, int __nbytes);
char *_CType ultoa(unsigned long __value, char *__string,
              int __radix);


#ifdef __cplusplus
}
#endif

#endif  /* !__STDC__ */

#endif  /* __STDLIB_H */
