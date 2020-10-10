/*  dir.h

    Defines structures, macros, and functions for dealing with
    directories and pathnames.

    Copyright (c) 1987, 1991 by Borland International
    All Rights Reserved.
*/

#if !defined( __DIR_H )
#define __DIR_H

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

#ifndef _FFBLK_DEF
#define _FFBLK_DEF
struct  ffblk   {
    char        ff_reserved[21];
    char        ff_attrib;
    unsigned    ff_ftime;
    unsigned    ff_fdate;
    long        ff_fsize;
    char        ff_name[13];
};
#endif

#define WILDCARDS 0x01
#define EXTENSION 0x02
#define FILENAME  0x04
#define DIRECTORY 0x08
#define DRIVE     0x10

#define MAXPATH   80
#define MAXDRIVE  3
#define MAXDIR    66
#define MAXFILE   9
#define MAXEXT    5

#ifdef __cplusplus
extern "C" {
#endif

int     _CType chdir(const char *__path);
int     _CType findfirst(const char *__path, 
                            struct ffblk *__ffblk, 
                            int __attrib );
int     _CType findnext(struct ffblk *__ffblk);
void    _CType fnmerge(char *__path,
                            const char *__drive,
                            const char *__dir,
                            const char *__name,
                            const char *__ext);
int     _CType _fnsplit(const char *__path,
                            char *__drive,
                            char *__dir,
                            char *__name,
                            char *__ext);
int     _CType fnsplit(const char *__path,
                            char *__drive,
                            char *__dir,
                            char *__name,
                            char *__ext);
int     _Cdecl getcurdir(int __drive, char *__directory);
char *  _Cdecl getcwd(char *__buf, int __buflen);
int     _Cdecl getdisk(void);
int     _Cdecl mkdir(const char *__path);
char *  _Cdecl mktemp(char *__template);
int     _Cdecl rmdir(const char *__path);
char *  _CType searchpath(const char *__file);
int     _Cdecl setdisk(int __drive);
#ifdef __cplusplus
}
#endif

#endif  /* __DIR_H */

