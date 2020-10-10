/*  timeb.h

    Struct and function declarations for ftime().

    Copyright (c) 1987, 1991 by Borland International
    All Rights Reserved.
*/

#if !defined( __TIMEB_H )
#define __TIMEB_H

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

struct timeb {
      long  time;
      short millitm;
#if defined(_RTLDLL)
      short _timezone;
#else
      short timezone;
#endif
      short dstflag;
      };

#ifdef __cplusplus
extern "C" {
#endif
void _Cdecl ftime(struct timeb *);
#ifdef __cplusplus
}
#endif

#endif  /* __TIMEB_H */
