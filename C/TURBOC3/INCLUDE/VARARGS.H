/*  varargs.h

    Definitions for accessing parameters in functions that accept
    a variable number of arguments.  These macros are compatible
    with UNIX System V.  Use stdarg.h for ANSI C compatibility.

    Copyright (c) 1991 by Borland International
    All Rights Reserved.
*/

#ifndef __VARARGS_H
#define __VARARGS_H

#ifdef __STDARG_H
#error Can't include both STDARG.H and VARARGS.H
#endif

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

typedef void *va_list;
#define va_dcl va_list va_alist;
#define va_start(ap) ap = (va_list)&va_alist
#define va_arg(ap, type) (*(type *)(((*(char **)&(ap))+=((sizeof(type)+1) & 0xFFFE))-(((sizeof(type)+1) & 0xFFFE))))
#define va_end(ap)   ap = ((void *)0)

#endif  /* __VARARGS_H */
