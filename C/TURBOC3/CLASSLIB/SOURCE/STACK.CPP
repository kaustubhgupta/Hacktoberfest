/*------------------------------------------------------------------------*/
/*                                                                        */
/*  STACK.CPP                                                             */
/*                                                                        */
/*  Copyright Borland International 1991                                  */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __STACK_H )
#include <Stack.h>
#endif	// __STACK_H

#ifndef __IOSTREAM_H
#include <iostream.h>
#endif

void Stack::push( Object& toPush )
{
    theStack.add( toPush );
    itemsInContainer++;
}

Object& Stack::pop()
{
    Object& temp = theStack.peekHead();
    theStack.detach( temp );
    if( temp != NOOBJECT )
        itemsInContainer--;
    return temp;
}

ContainerIterator& Stack::initIterator() const
{
    return *( (ContainerIterator *)new ListIterator( this->theStack ) );
}

