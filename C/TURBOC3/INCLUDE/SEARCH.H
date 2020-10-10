/*  search.h

    Definitions for search functions.

    Copyright (c) 1991 by Borland International
    All Rights Reserved.
*/

#ifndef __SEARCH_H
#define __SEARCH_H

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned size_t;
#endif

#ifdef __cplusplus
extern "C" {
#endif
void   *_CType bsearch(const void *__key, const void *__base, 
                size_t __nelem, size_t __width,
                int _Cdecl(* __fcmp)(const void *, const void *));
void   *_Cdecl lfind(const void *__key, const void *__base, 
                 size_t *__num, size_t __width,
                 int _Cdecl(* __fcmp)(const void *, const void *));
void   *_Cdecl lsearch(const void *__key, void *__base, 
                 size_t *__num, size_t __width, 
                 int _Cdecl(* __fcmp)(const void *, const void *));
void    _CType qsort(void *__base, size_t __nelem, size_t __width,
                int _CType (* __fcmp)(const void *, const void *));
#ifdef __cplusplus
}
#endif

#endif  /* __SEARCH_H */
