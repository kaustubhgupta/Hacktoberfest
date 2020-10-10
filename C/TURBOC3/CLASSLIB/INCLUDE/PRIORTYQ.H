/*------------------------------------------------------------------------*/
/*                                                                        */
/*  PRIORTYQ.H                                                            */
/*                                                                        */
/*  Copyright Borland International 1991                                  */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __PRIORTYQ_H )
#define __PRIORTYQ_H

#if !defined( __BTREE_H )
#include "Btree.h"
#endif

#if !defined( __SHDDEL_H )
#include <ShdDel.h>
#endif  // __SHDDEL_H

_CLASSDEF(PriorityQueue)

class _CLASSTYPE PriorityQueue :
    public Container,
    public virtual TShouldDelete
{

public:

    int isEmpty() const
        {
        return tree.isEmpty();
        }

    countType getItemsInContainer() const
        {
        return tree.getItemsInContainer();
        }

    void put(Object& o)
        {
        tree.add(o);
        }

    Object& get()
        {
        if( isEmpty() )
            return NOOBJECT;
        else
            {
            Object& obj = tree[0];
            tree.detach( obj ); // does not delete
            return obj;
            }
        }

    Object& peekLeft()
        {
        return (isEmpty()?NOOBJECT:tree[0]);
        }

    void detachLeft( DeleteType dt = NoDelete )
        {
        if( !isEmpty() )
            tree.detach( tree[0], dt );
        }

    void flush( DeleteType dt = DefDelete )
        {
        tree.flush( dt );
        }

    int hasMember( Object& obj ) const
        {
        return tree.hasMember( obj );
        }

    int ownsElements()
        {
        return tree.ownsElements();
        }

    void ownsElements( int del )
        {
        tree.ownsElements( del );
        }

    virtual classType isA() const
        {
        return priorityQueueClass;
        }

    virtual char _FAR *nameOf() const
        {
        return "PriorityQueue";
        }

    virtual ContainerIterator _FAR & initIterator() const
        {
        return tree.initIterator();
        }

private:

    Btree tree;

};

#endif
