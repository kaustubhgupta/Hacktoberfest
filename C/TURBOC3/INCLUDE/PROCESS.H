/*  process.h

    Symbols and structures for process management.

    Copyright (c) 1987, 1991 by Borland International
    All Rights Reserved.
*/

#if !defined( __PROCESS_H )
#define __PROCESS_H

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

/*  Modes available as first argument to the spawnxx functions. */

#define P_WAIT    0 /* child runs separately, parent waits until exit */
#define P_NOWAIT  1 /* both concurrent -- not implemented */
#define P_OVERLAY 2 /* child replaces parent, parent no longer exists */

#define P_NOWAITO 3 /* ASYNCH,       toss RC    */
#define P_DETACH  4 /* DETACHED,     toss RC    */

#define WAIT_CHILD       0
#define WAIT_GRANDCHILD      1

/*  MSDOS does not have any abstract identifier for a process, but the
    process Program Segment Prefix location provides a similar token.
*/

extern  unsigned _Cdecl _psp;    /* provided unconditionally in dos.h */

#define  getpid()   (_psp)

#ifdef __cplusplus
extern "C" {
#endif
void _Cdecl abort(void);
void _Cdecl _cexit(void);
void _Cdecl _c_exit(void);
int  _Cdecl execl(char *__path, char *__arg0, ...);
int  _Cdecl execle(char *__path, char *__arg0, ...);
int  _Cdecl execlp(char *__path, char *__arg0, ...);
int  _Cdecl execlpe(char *__path, char *__arg0, ...);
int  _Cdecl execv(char *__path, char *__argv[]);
int  _Cdecl execve(char *__path, char *__argv[], char **__env);
int  _Cdecl execvp(char *__path, char *__argv[]);
int  _Cdecl execvpe(char *__path, char *__argv[], char **__env);
void _Cdecl exit(int __status);
void _Cdecl _exit(int __status);
int  _Cdecl spawnl(int __mode, char *__path, char *__arg0, ...);
int  _Cdecl spawnle(int __mode, char *__path, char *__arg0, ...);
int  _Cdecl spawnlp(int __mode, char *__path, char *__arg0, ...);
int  _Cdecl spawnlpe(int __mode, char *__path, char *__arg0, ...);
int  _Cdecl spawnv(int __mode, char *__path, char *__argv[]);
int  _Cdecl spawnve(int __mode, char *__path, char *__argv[], char **__env);
int  _Cdecl spawnvp(int __mode, char *__path, char *__argv[]);
int  _Cdecl spawnvpe(int __mode, char *__path, char *__argv[], char **__env);
int  _Cdecl system(const char *__command);
#ifdef __cplusplus
}
#endif

#endif  /* __PROCESS_H */

