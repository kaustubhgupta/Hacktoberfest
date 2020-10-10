/*------------------------------------------------------------------------*/
/*                                                                        */
/*  SHDDEL.H                                                              */
/*                                                                        */
/*  Copyright Borland International 1991                                  */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __SHDDEL_H )
#define __SHDDEL_H

#if !defined( ___DEFS_H )
#include <_defs.h>
#endif  // ___DEFS_H

_CLASSDEF(TShouldDelete)

class _CLASSTYPE TShouldDelete
{

public:

    enum DeleteType { NoDelete, DefDelete, Delete };

    TShouldDelete( DeleteType dt = Delete )
        {
        ownsElements( dt );
        }

    int ownsElements()
        {
        return shouldDelete == Delete;
        }

    void ownsElements( int del )
        {
        shouldDelete = (del == 0) ? NoDelete : Delete;
        }

protected:

    int delObj( DeleteType dt )
        {
        return dt == Delete || (dt==DefDelete && shouldDelete==Delete);
        }

private:

    DeleteType shouldDelete;

};

#endif  // __SHDDEL_H

