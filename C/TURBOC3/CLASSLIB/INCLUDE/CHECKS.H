/*------------------------------------------------------------------------*/
/*                                                                        */
/*  CHECKS.H                                                              */
/*                                                                        */
/*  Copyright Borland International 1991                                  */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __CHECKS_H )
#define __CHECKS_H

#if !defined( ___DEFS_H )
#include <_defs.h>
#endif  // ___DEFS_H

extern "C" void _Cdecl __assertfail( char _FAR *__msg,
                                     char _FAR *__cond,
                                     char _FAR *__file,
                                     int __line);

#if !defined( __DEBUG )
#define __DEBUG 2
#endif

#undef PRECONDITION

#if __DEBUG < 1
#define PRECONDITION(p)   ((void)0)
#else
#define PRECONDITION(p)   ((p) ? (void)0 : (void) __assertfail(      \
                    "Precondition violated: %s, file %s, line %d\n", \
                    #p, __FILE__, __LINE__ ) )
#endif

#undef CHECK

#if __DEBUG < 2
#define CHECK(p)    ((void)0)
#else
#define CHECK(p)    ((p) ? (void)0 : (void) __assertfail(   \
                    "Check failed: %s, file %s, line %d\n", \
                    #p, __FILE__, __LINE__ ) )
#endif

#endif  // __CHECKS_H
