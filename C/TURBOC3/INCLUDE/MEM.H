/*  mem.h

    Memory manipulation functions

    Copyright (c) 1987, 1991 by Borland International
    All Rights Reserved.
*/

#if !defined( __MEM_H )
#define __MEM_H

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

#ifndef NULL
#include <_null.h>
#endif

#ifndef _STDDEF
#define _STDDEF
#ifndef _PTRDIFF_T
#define _PTRDIFF_T
#if defined(__LARGE__) || defined(__HUGE__) || defined(__COMPACT__)
typedef long    ptrdiff_t;
#else
typedef int ptrdiff_t;
#endif
#endif
#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned size_t;
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif
void * _Cdecl memccpy(void *__dest, const void *__src,
                           int __c, size_t __n);
void * _Cdecl memchr(const void *__s, int __c, size_t __n);
int         _Cdecl memcmp(const void *__s1, const void *__s2,
                          size_t __n);
void * _Cdecl memcpy(void *__dest, const void *__src,
                          size_t __n);
int         _Cdecl memicmp(const void *__s1, const void *__s2,
                          size_t __n);
void * _CType memmove(void *__dest, const void *__src,
                          size_t __n);
void * _CType memset(void *__s, int __c, size_t __n);
void        _Cdecl movedata(unsigned __srcseg, unsigned __srcoff,
                            unsigned __dstseg,unsigned __dstoff, size_t __n);
void        _Cdecl movmem(const void *__src, void *__dest,
                          unsigned __length);
void        _Cdecl setmem(void *__dest,unsigned __length, char __value);

#if !__STDC__
void  far * far cdecl _fmemccpy(void far *__dest, const void far *__src,
                       int c, size_t __n);
void  far * far cdecl _fmemchr(const void far *__s, int c, size_t __n);
int         far cdecl _fmemcmp(const void far *__s1, const void far *__s2,
                       size_t __n);
void  far * far cdecl _fmemcpy(void far *__dest, const void far *__src,
                       size_t __n);
int         far cdecl _fmemicmp(const void far *__s1, const void far *__s2,
                       size_t __n);
void  far * far cdecl _fmemmove(void far *__dest, const void far *__src,
                       size_t __n);
void  far * far cdecl _fmemset(void far *__s, int c, size_t __n);
void        far cdecl _fmovmem(const void far *__src, void far *__dest,
                       unsigned __length);
void        far cdecl _fsetmem(void far *__dest,unsigned __length, 
                       char __value);
#endif

#if !defined(__STRING_H)
/* Intrinsic functions */

void * _Cdecl __memchr__  (const void *__s, int __c, size_t __n);
int         _Cdecl __memcmp__(const void *__s1,
                          const void *__s2, size_t __n);
void * _Cdecl __memcpy__(void *__dest, const void *__src,
                          size_t __n);
void * _CType __memset__(void *__s, int __c, size_t __n);
#endif
#ifdef __cplusplus
}
#endif

#endif  /* __MEM_H */

