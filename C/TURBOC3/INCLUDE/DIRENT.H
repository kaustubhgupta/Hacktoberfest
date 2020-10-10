/*  dirent.h

    Definitions for POSIX directory operations.

    Copyright (c) 1991 by Borland International
    All Rights Reserved.
*/

#ifndef __DIRENT_H
#define __DIRENT_H

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

#ifndef NULL
#include <_null.h>
#endif

/* dirent structure returned by readdir().
 */
struct dirent
{
    char        d_name[13];
};

/* DIR type returned by opendir().  The first two members cannot
 * be separated, because they make up the DOS DTA structure used
 * by findfirst() and findnext().
 */
typedef struct
{
    char          _d_reserved[30];      /* reserved part of DTA */
    struct dirent _d_dirent;            /* filename part of DTA */
    char         *_d_dirname;           /* directory name */
    char          _d_first;             /* first file flag */
    unsigned char _d_magic;             /* magic cookie for verifying handle */
} DIR;

/* Prototypes.
 */
#ifdef __cplusplus
extern "C" {
#endif

DIR           * _Cdecl opendir(char *__dirname);
struct dirent * _Cdecl readdir(DIR *__dir);
int             _Cdecl closedir(DIR *__dir);
void            _Cdecl rewinddir(DIR *__dir);

#ifdef __cplusplus
}
#endif

#endif /* __DIRENT_H */
