/*  io.h

    Definitions for low level I/O functions.

    Copyright (c) 1987, 1991 by Borland International
    All Rights Reserved.
*/

#ifndef __IO_H
#define __IO_H

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

#define HANDLE_MAX  20U

extern  unsigned int    _Cdecl _nfile;

struct  ftime   {
    unsigned    ft_tsec  : 5;   /* Two second interval */
    unsigned    ft_min   : 6;   /* Minutes */
    unsigned    ft_hour  : 5;   /* Hours */
    unsigned    ft_day   : 5;   /* Days */
    unsigned    ft_month : 4;   /* Months */
    unsigned    ft_year  : 7;   /* Year */
};

#define SEEK_CUR    1
#define SEEK_END    2
#define SEEK_SET    0

#ifdef __cplusplus
extern "C" {
#endif
int  _Cdecl access   (const char *path, int amode);
#ifdef __IN_CHMOD
int  _Cdecl _chmod   ();
#else
int  _Cdecl _chmod   (const char *__pathname, int __func, ... );
#endif
int  _Cdecl chmod    (const char *__path, int __amode);
int  _Cdecl chsize   (int __handle, long __size);
int  _CType _close   (int __handle);
int  _CType close    (int __handle);
int  _CType _creat   (const char *__path, int __attribute);
int  _CType creat    (const char *__path, int __amode);
int  _Cdecl creatnew (const char *__path, int __mode); /* DOS 3.0 or later */
int  _Cdecl creattemp(char *__path, int __amode); /* DOS 3.0 or later */
int  _Cdecl dup      (int __handle);
int  _Cdecl dup2     (int __oldhandle, int __newhandle);
int  _Cdecl eof      (int __handle);
long _Cdecl filelength   (int __handle);
int  _Cdecl getftime     (int __handle, struct ftime *__ftimep);
#ifdef __IN_IOCTL
int  _Cdecl ioctl    ();
#else
int  _Cdecl ioctl    (int __handle, int __func, ...);
        /* optional 3rd and 4th args are: void * __argdx, int argcx */
#endif

int  _Cdecl isatty   (int __handle);
int  _Cdecl lock     (int __handle, long __offset, long __length);
int  _Cdecl locking  (int __handle, int __mode, long __length);
long _CType lseek    (int __handle, long __offset, int __fromwhere);
char * _Cdecl mktemp( char *__template );
#ifdef __IN_OPEN
int  _Cdecl open();
#else
int _Cdecl open(const char *__path, int __access,... /*unsigned mode*/);
#endif
int  _CType _open    (const char *__path, int __oflags);
int  _CType read     (int __handle, void *__buf, unsigned __len);
int  _CType _read    (int __handle, void *__buf, unsigned __len);
int  _CType remove   (const char *__path);
int  _CType rename   (const char *__oldname,const char *__newname);
int  _Cdecl setftime (int __handle, struct ftime *__ftimep);
int  _Cdecl setmode  (int __handle, int __amode);

#ifdef __IN_SOPEN
int  _Cdecl sopen();
#else
int  _Cdecl sopen    (const char *__path, int __access, int __shflag,
                      ... /* unsigned mode */);
#endif
long _Cdecl tell     (int __handle);
unsigned _Cdecl umask    (unsigned __cmask);
int  _CType unlink   (const char *__path);
int  _Cdecl unlock   (int __handle, long __offset, long __length);
int  _CType _write   (int __handle, const void *__buf, unsigned __len);
int  _CType write    (int __handle, const void *__buf, unsigned __len);

#ifdef __cplusplus
}
#endif

#endif  /* __IO_H */
