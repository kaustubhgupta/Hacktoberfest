/*------------------------------------------------------------------------*/
/*                                                                        */
/*  STACK.H                                                               */
/*                                                                        */
/*  Copyright Borland International 1991                                  */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __STACK_H )
#define __STACK_H

#if defined( TEMPLATES )

    #if !defined( __STACKS_H )
    #include <Stacks.h>
    #endif  // __STACKS_H

    #define Stack   BI_TCStackAsList
    #define PStack  PBI_TCStackAsList
    #define RStack  RBI_TCStackAsList
    #define RPStack RPBI_TCStackAsList
    #define PCStack PCBI_TCStackAsList
    #define RCStack RCBI_TCStackAsList

    _CLASSDEF( BI_TCStackAsList )

    #define StackIterator   BI_TCStackAsListIterator
    #define PStackIterator  PBI_TCStackAsListIterator
    #define RStackIterator  RBI_TCStackAsListIterator
    #define RPStackIterator RPBI_TCStackAsListIterator
    #define PCStackIterator PCBI_TCStackAsListIterator
    #define RCStackIterator RCBI_TCStackAsListIterator

    _CLASSDEF( BI_TCStackAsListIterator )

#else   // TEMPLATES

    #if !defined( __CLSTYPES_H )
    #include <ClsTypes.h>
    #endif  // __CLSTYPES_H

    #if !defined( __CONTAIN_H )
    #include <Contain.h>
    #endif  // __CONTAIN_H

    #if !defined( __LIST_H )
    #include <List.h>
    #endif  // __LIST_H

    _CLASSDEF(Stack)

    class _CLASSTYPE Stack : public Container
    {

    public:

        void push( Object _FAR & );
        Object _FAR & pop();
        Object _FAR & top() const
            {
            return theStack.peekHead();
            }

        virtual int isEmpty() const
            {
            return theStack.isEmpty();
            }

        virtual countType getItemsInContainer() const
            {
            return theStack.getItemsInContainer();
            }

        virtual void flush( DeleteType dt = DefDelete )
            {
            theStack.flush( dt );
            }

        virtual ContainerIterator _FAR & initIterator() const;

        virtual classType isA() const
            {
            return stackClass;
            }

        virtual char _FAR *nameOf() const
            {
            return "Stack";
            }

    private:

        List theStack;

    };

#endif  // TEMPLATES

#endif  // __STACK_H

