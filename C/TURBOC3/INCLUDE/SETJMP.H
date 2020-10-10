/*  setjmp.h

    Defines typedef and functions for setjmp/longjmp.

    Copyright (c) 1987, 1991 by Borland International
    All Rights Reserved.
*/

#ifndef __SETJMP_H
#define __SETJMP_H

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

typedef struct __jmp_buf {
    unsigned    j_sp;
    unsigned    j_ss;
    unsigned    j_flag;
    unsigned    j_cs;
    unsigned    j_ip;
    unsigned    j_bp;
    unsigned    j_di;
    unsigned    j_es;
    unsigned    j_si;
    unsigned    j_ds;
}   jmp_buf[1];

#ifdef __cplusplus
extern "C" {
#endif

void    _CType longjmp(jmp_buf __jmpb, int __retval);
int     _CType setjmp(jmp_buf __jmpb);

#ifdef __cplusplus
}
#endif

#endif

