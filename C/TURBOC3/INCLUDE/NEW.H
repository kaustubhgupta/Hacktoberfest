/*  new.h

    Access to operator new() and newhandler()

    Copyright (c) 1990, 1991 by Borland International
    All Rights Reserved.
*/

#if !defined( __NEW_H )
#define __NEW_H

#if !defined( __DEFS_H )
#include <_defs.h>
#endif

#ifndef __cplusplus
#error Must use C++ with new.h
#endif

typedef void (* pvf)();
 
extern void (* _Cdecl _new_handler)();
 
void (* set_new_handler( void (* )() ))();

void * operator new( unsigned );

#endif  /* __NEW_H */

