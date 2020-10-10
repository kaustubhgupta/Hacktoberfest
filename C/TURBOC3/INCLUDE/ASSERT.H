/*  assert.h

    assert macro

    Copyright (c) 1987, 1991 by Borland International
    All Rights Reserved.
*/

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

void _Cdecl __assertfail(char *__msg, char *__cond,
                         char *__file, int __line);

#ifdef  __cplusplus
}
#endif

#undef assert

#ifdef NDEBUG
#  define assert(p)   ((void)0)
#else
#  define _ENDL "\n"
#  define assert(p) ((p) ? (void)0 : (void) __assertfail( \
                    "Assertion failed: %s, file %s, line %d" _ENDL, \
                    #p, __FILE__, __LINE__ ) )
#endif
