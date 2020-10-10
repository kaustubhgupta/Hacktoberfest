/*------------------------------------------------------------------------*/
/*                                                                        */
/*  DEQUE.H                                                               */
/*                                                                        */
/*  Copyright Borland International 1991                                  */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __DEQUE_H )
#define __DEQUE_H

#if defined( TEMPLATES )

    #if !defined( __DEQUES_H )
    #include <Deques.h>
    #endif  // __DEQUES_H

    #define Deque   BI_TCDequeAsDoubleList
    #define PDeque  PBI_TCDequeAsDoubleList
    #define RDeque  RBI_TCDequeAsDoubleList
    #define RPDeque RPBI_TCDequeAsDoubleList
    #define PCDeque PCBI_TCDequeAsDoubleList
    #define RCDeque RCBI_TCDequeAsDoubleList

    _CLASSDEF( BI_TCDequeAsDoubleList )

    #define DequeIterator   BI_TCDequeAsDoubleListIterator
    #define PDequeIterator  PBI_TCDequeAsDoubleListIterator
    #define RDequeIterator  RBI_TCDequeAsDoubleListIterator
    #define RPDequeIterator RPBI_TCDequeAsDoubleListIterator
    #define PCDequeIterator PCBI_TCDequeAsDoubleListIterator
    #define RCDequeIterator RCBI_TCDequeAsDoubleListIterator

    _CLASSDEF( BI_TCDequeAsDoubleListIterator )

#else   // TEMPLATES

    #if !defined( __CLSTYPES_H )
    #include <ClsTypes.h>
    #endif  // __CLSTYPES_H

    #if !defined( __CONTAIN_H )
    #include <Contain.h>
    #endif  // __CONTAIN_H

    #if !defined( __DBLLIST_H )
    #include <DblList.h>
    #endif  // __DBLLIST_H

    _CLASSDEF(Deque)

    class _CLASSTYPE Deque : public Container
    {

    public:

        ~Deque()
            {
            flush();
            }

        Object& peekLeft() const
            {
            return theDeque.peekAtHead();
            }

        Object& peekRight() const
            {
            return theDeque.peekAtTail();
            }

        Object& getLeft();
        Object& getRight();

        void putLeft( Object& o )
            {
            theDeque.addAtHead( o ); itemsInContainer++;
            }

        void putRight( Object& o )
            {
            theDeque.addAtTail( o ); itemsInContainer++;
            }

        virtual void flush( DeleteType dt = DefDelete )
            {
            theDeque.flush( dt );
            }

        virtual int isEmpty() const
            {
            return theDeque.isEmpty();
            }

        virtual countType getItemsInContainer() const
            {
            return theDeque.getItemsInContainer();
            }

        virtual ContainerIterator& initIterator() const;

        virtual classType isA() const
            {
            return dequeClass;
            }

        virtual char _FAR *nameOf() const
            {
            return "Deque";
            }

    private:

        DoubleList theDeque;

    };

#endif  // TEMPLATES

#endif  // __DEQUE_H

