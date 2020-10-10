/*------------------------------------------------------------------------*/
/*                                                                        */
/*  DEQUE.CPP                                                             */
/*                                                                        */
/*  Copyright Borland International 1991                                  */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __DEQUE_H )
#include <Deque.h>
#endif	// __DEQUE_H

#ifndef __IOSTREAM_H
#include <iostream.h>
#endif

Object& Deque::getLeft()
{
    Object& temp = theDeque.peekAtHead();
    if( temp != NOOBJECT )
        {
        theDeque.detachFromHead( temp );
        itemsInContainer--;
        }
    return temp;
}

Object& Deque::getRight()
{
    Object& temp = theDeque.peekAtTail();
    if( temp != NOOBJECT )
        {
        theDeque.detachFromTail( temp );
        itemsInContainer--;
        }
    return temp;
}

ContainerIterator& Deque::initIterator() const
{
    return *((ContainerIterator *)new DoubleListIterator(this->theDeque));
}


