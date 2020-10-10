/*  time.h

    Struct and function declarations for dealing with time.

    Copyright (c) 1987, 1991 by Borland International
    All Rights Reserved.
*/

#ifndef __TIME_H
#define __TIME_H

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

#ifndef _SIZE_T
#define _SIZE_T
typedef unsigned size_t;
#endif

#ifndef  _TIME_T
#define  _TIME_T
typedef long time_t;
#endif

#ifndef  _CLOCK_T
#define  _CLOCK_T
typedef long clock_t;


#define CLOCKS_PER_SEC 18.2
#define CLK_TCK        18.2

#endif  /* _TIME_T */

struct tm
{
  int   tm_sec;
  int   tm_min;
  int   tm_hour;
  int   tm_mday;
  int   tm_mon;
  int   tm_year;
  int   tm_wday;
  int   tm_yday;
  int   tm_isdst;
};

#ifdef __cplusplus
extern "C" {
#endif
char *     _Cdecl asctime(const struct tm *__tblock);
char *     _Cdecl ctime(const time_t *__time);
double      _Cdecl difftime(time_t __time2, time_t __time1);
struct tm * _Cdecl gmtime(const time_t *__timer);
struct tm * _Cdecl localtime(const time_t *__timer);
time_t      _Cdecl time(time_t *__timer);
time_t      _Cdecl mktime(struct tm *__timeptr);
clock_t     _Cdecl clock(void);
size_t      _Cdecl strftime(char *__s, size_t __maxsize,
                        const char *__fmt, const struct tm *__t);

#if !__STDC__

extern int  _Cdecl  daylight;
extern long _Cdecl  timezone;
extern char * const _Cdecl tzname[2];

int         _Cdecl  stime(time_t *__tp);
void        _Cdecl  tzset(void);
char * _Cdecl  _strdate(char *datestr);
char * _Cdecl  _strtime(char *timestr);
#endif

#ifdef __cplusplus
}
#endif

#endif
