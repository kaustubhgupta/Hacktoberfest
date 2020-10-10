/*  stdarg.h

    Definitions for accessing parameters in functions that accept
    a variable number of arguments.

    Copyright (c) 1987, 1991 by Borland International
    All Rights Reserved.
*/

#ifndef __STDARG_H
#define __STDARG_H

#ifdef __VARARGS_H
#error Can't include both STDARG.H and VARARGS.H
#endif

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

typedef void *va_list;

#define __size(x) ((sizeof(x)+sizeof(int)-1) & ~(sizeof(int)-1))

#ifdef  __cplusplus
#define va_start(ap, parmN) (ap = ...)
#else
#define va_start(ap, parmN) ((void)((ap) = (va_list)((char *)(&parmN)+__size(parmN))))
#endif

#define va_arg(ap, type) (*(type *)(((*(char **)&(ap))+=__size(type))-(__size(type))))
#define va_end(ap)          ((void)0)

#if !__STDC__
#define _va_ptr             (...)
#endif

#endif
