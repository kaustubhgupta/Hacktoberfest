/*  _defs.h

    Common definitions for pointer size and calling conventions.

    Copyright (c) 1991 by Borland International
    All Rights Reserved.
*/

#if !defined( __DEFS_H )
#define __DEFS_H

#if __STDC__
#  define _Cdecl
#else
#  define _Cdecl  cdecl
#endif

#ifndef __PAS__
#  define _CType _Cdecl
#else
#  define _CType pascal
#endif

#if !__STDC__
#  if defined(__TINY__) || defined(__SMALL__) || defined(__MEDIUM__)
#    define _CLASSTYPE  near
#  elif defined(__COMPACT__) || defined(__LARGE__)
#    define _CLASSTYPE  far
#  else
#    define _CLASSTYPE  huge
#  endif
#endif

#define _FAR
#define _FARFUNC

#if defined( __cplusplus )
#  define _PTRDEF(name) typedef name * P##name;
#  define _REFDEF(name) typedef name & R##name;
#  define _REFPTRDEF(name) typedef name * & RP##name;
#  define _PTRCONSTDEF(name) typedef const name * PC##name;
#  define _REFCONSTDEF(name) typedef const name & RC##name;
#  define _CLASSDEF(name) class _CLASSTYPE name; \
    _PTRDEF(name) \
    _REFDEF(name) \
    _REFPTRDEF(name) \
    _PTRCONSTDEF(name) \
    _REFCONSTDEF(name)
#endif

#endif  /* __DEFS_H */
