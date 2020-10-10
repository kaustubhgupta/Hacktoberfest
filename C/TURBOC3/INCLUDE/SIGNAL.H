/*  signal.h
  
    Definitions for ANSI defined signaling capability

    Copyright (c) 1988, 1991 by Borland International
    All Rights Reserved.
*/

#ifndef __SIGNAL_H
#define __SIGNAL_H

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

typedef int sig_atomic_t;   /* Atomic entity type (ANSI) */
typedef void _Cdecl (* _CatcherPTR)();

#define SIG_DFL ((_CatcherPTR)0)   /* Default action   */
#define SIG_IGN ((_CatcherPTR)1)   /* Ignore action    */
#define SIG_ERR ((_CatcherPTR)-1)  /* Error return     */

#define SIGABRT 22
#define SIGFPE  8       /* Floating point trap  */
#define SIGILL  4       /* Illegal instruction  */
#define SIGINT  2
#define SIGSEGV 11      /* Memory access violation */
#define SIGTERM 15

#ifdef __cplusplus
extern "C" {
#endif
int _Cdecl raise(int __sig);
#ifdef __cplusplus
void _Cdecl (* _Cdecl signal(int __sig, void _Cdecl (* __func)(int))) (int);
}
#else
void _Cdecl (* _Cdecl signal(int __sig, void _Cdecl (* func)())) (int);
#endif

#endif
