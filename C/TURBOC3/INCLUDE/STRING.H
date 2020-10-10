/*  string.h

    Definitions for memory and string functions.

    Copyright (c) 1987, 1991 by Borland International
    All Rights Reserved.
*/

#ifndef __STRING_H
#define __STRING_H

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

#ifndef NULL
#include <_null.h>
#endif

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned size_t;
#endif

#ifdef __cplusplus
extern "C" {
#endif
void * _Cdecl memchr  (const void *__s, int __c, size_t __n);
int         _Cdecl memcmp(const void *__s1,
                          const void *__s2, size_t __n);
void * _Cdecl memcpy(void *__dest, const void *__src,
                          size_t __n);
void * _CType memmove(void *__dest, const void *__src,
                           size_t __n);
void * _CType memset(void *__s, int __c, size_t __n);
char * _CType strcat(char *__dest, const char *__src);
char * _CType strchr(const char *__s, int __c);
int         _CType strcmp(const char *__s1, const char *__s2);
int         _Cdecl strcoll(const char *__s1, const char *__s2);
char * _CType strcpy(char *__dest, const char *__src);
size_t      _Cdecl strcspn(const char *__s1, const char *__s2);
char * _Cdecl strerror(int __errnum);
size_t      _CType strlen(const char *__s);
char * _CType strncat(char *__dest, const char *__src,
               size_t __maxlen);
int         _CType strncmp(const char *__s1, const char *__s2,
               size_t __maxlen);
char * _CType strncpy(char *__dest, const char *__src,
                           size_t __maxlen);
char * _CType strpbrk(const char *__s1, const char *__s2);
char * _CType strrchr(const char *__s, int __c);
size_t      _Cdecl strspn(const char *__s1, const char *__s2);
char * _Cdecl strstr(const char *__s1, const char *__s2);
char * _CType strtok(char *__s1, const char *__s2);
size_t      _Cdecl strxfrm(char *__s1, const char *__s2,
               size_t __n );
char * _Cdecl _strerror(const char *__s);


#if !__STDC__
/* compatibility with other compilers */
#define strcmpi(s1,s2)      stricmp(s1,s2)
#define strncmpi(s1,s2,n)   strnicmp(s1,s2,n)

void * _Cdecl memccpy(void *__dest, const void *__src,
               int __c, size_t __n);
int         _Cdecl memicmp(const void *__s1, const void *__s2,
                           size_t __n);
void        _Cdecl movedata(unsigned __srcseg,unsigned __srcoff,
                            unsigned __dstseg,unsigned __dstoff, size_t __n);
char * _CType stpcpy(char *__dest, const char *__src);
char * _Cdecl _stpcpy(char *__dest, const char *__src);
char * _Cdecl strdup(const char *__s);
int         _CType stricmp(const char *__s1, const char *__s2);
char * _CType strlwr(char *__s);
int         _CType strnicmp(const char *__s1, const char *__s2,
                size_t __maxlen);
char * _Cdecl strnset(char *__s, int __ch, size_t __n);
char * _Cdecl strrev(char *__s);
char * _Cdecl strset(char *__s, int __ch);
char * _CType strupr(char *__s);

void    far * far cdecl _fmemccpy(void far *__dest, const void far *__src,
                int c, size_t __n);
void    far * far cdecl _fmemchr(const void far *__s, int c, size_t __n);
int           far cdecl _fmemcmp(const void far *__s1, const void far *__s2,
                size_t __n);
void    far * far cdecl _fmemcpy(void far *__dest, const void far *__src,
                size_t __n);
int           far cdecl _fmemicmp(const void far *__s1, const void far *__s2,
                size_t __n);
void    far * far cdecl _fmemmove(void far *__dest, const void far *__src,
                size_t __n);
void    far * far cdecl _fmemset(void far *__s, int c, size_t __n);
void          far cdecl _fmovmem(const void far *__src, void far *__dest,
                unsigned __length);
void          far cdecl _fsetmem(void far *__dest,unsigned __length,
                char __value);

char    far * far cdecl _fstrcat(char far *__dest, const char far *__src);
char    far * far cdecl _fstrchr(const char far *__s, int c);
int           far cdecl _fstrcmp(const char far *__s1, const char far *__s2);
char    far * far cdecl _fstrcpy(char far *__dest, const char far *__src);
size_t        far cdecl _fstrcspn(const char far *__s1, const char far *__s2);
char    far * far cdecl _fstrdup(const char far *__s);
int           far cdecl _fstricmp(const char far *__s1, const char far *__s2);
size_t        far cdecl _fstrlen(const char far *__s);
char    far * far cdecl _fstrlwr(char far *__s);
char    far * far cdecl _fstrncat(char far *__dest, const char far *__src,
             size_t maxlen);
int           far cdecl _fstrncmp(const char far *__s1, const char far *__s2,
             size_t maxlen);
char    far * far cdecl _fstrncpy(char far *__dest, const char far *__src,
             size_t maxlen);
int           far cdecl _fstrnicmp(const char far *__s1, const char far *__s2,
              size_t maxlen);
char    far * far cdecl _fstrnset(char far *__s, int ch, size_t __n);
char    far * far cdecl _fstrpbrk(const char far *__s1, const char far *__s2);
char    far * far cdecl _fstrrchr(const char far *__s, int c);
char    far * far cdecl _fstrrev(char far *__s);
char    far * far cdecl _fstrset(char far *__s, int ch);
size_t        far cdecl _fstrspn(const char far *__s1, const char far *__s2);
char    far * far cdecl _fstrstr(const char far *__s1, const char far *__s2);
char    far * far cdecl _fstrtok(char far *__s1, const char far *__s2);
char    far * far cdecl _fstrupr(char far *__s);

#endif  /* ! __STDC__ */

#ifdef __cplusplus
}
#endif

#endif
