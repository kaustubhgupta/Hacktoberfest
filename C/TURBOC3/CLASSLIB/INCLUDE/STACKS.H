/*------------------------------------------------------------------------*/
/*                                                                        */
/*  STACKS.H                                                              */
/*                                                                        */
/*  Copyright Borland International 1991                                  */
/*  All Rights Reserved                                                   */
/*                                                                        */
/*------------------------------------------------------------------------*/

#if !defined( __STACKS_H )
#define __STACKS_H

#if !defined( ___DEFS_H )
#include <_defs.h>
#endif  // ___DEFS_H

#if !defined( __CHECKS_H )
#include <Checks.h>
#endif  // __CHECKS_H

#if !defined( __SHDDEL_H )
#include <ShdDel.h>
#endif  // __SHDDEL_H

#if !defined( __VECTIMP_H )
#include <VectImp.h>
#endif  // __VECTIMP_H

#if !defined( __LISTIMP_H )
#include <ListImp.h>
#endif  // __LISTIMP_H

#if !defined( __CONTAIN_H )
#include <Contain.h>
#endif  // __CONTAIN_H

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class Vect, class T> class BI_StackAsVectorImp              */
/*                                                                        */
/*  Implements the fundamental stack operations, using a vector           */
/*  as the underlying implementation.  The type Vect specifies the        */
/*  form of the vector, either a BI_VectorImp<T0> or a                    */
/*  BI_IVectorImp<T0>.  The type T specifies the type of the              */
/*  objects to be put on the stack.  When using BI_VectorImp<T0>,         */
/*  T should be the same as T0. When using BI_IVectorImp<T0>, T           */
/*  should be of type pointer to T0.  See BI_StackAsVector and            */
/*  BI_IStackAsVector for examples.                                       */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class Vect, class T> class _CLASSTYPE BI_StackAsVectorImp
{

public:

    BI_StackAsVectorImp( unsigned max = DEFAULT_STACK_SIZE ) :
        data(max),
        current(0)
        {
        }

    void push( T t )
        {
        PRECONDITION( current < data.limit() );
        data[current++] = t;
        }

    T pop()
        {
        PRECONDITION( current > 0 );
        return data[--current];
        }

    T top() const
        {
        PRECONDITION( current > 0 );
        return data[current-1];
        }

    int isEmpty() const
        {
        return current == 0;
        }

    int isFull() const
        {
        return current == data.limit();
        }

    int getItemsInContainer() const
        {
        return current;
        }

    void flush( TShouldDelete::DeleteType = TShouldDelete::DefDelete )
        {
        current = 0;
        }

protected:

    Vect data;
    unsigned current;

};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class BI_StackAsVector                             */
/*                                                                        */
/*  Implements a stack of objects of type T, using a vector as            */
/*  the underlying implementation.                                        */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class _CLASSTYPE BI_StackAsVector :
    public BI_StackAsVectorImp<BI_VectorImp<T>,T>
{

public:

    friend class _CLASSTYPE BI_StackAsVectorIterator<T>;

    BI_StackAsVector( unsigned max = DEFAULT_STACK_SIZE ) :
        BI_StackAsVectorImp<BI_VectorImp<T>,T>( max )
        {
        }

    void forEach( void (_FAR *f)(T _FAR &, void _FAR *), void _FAR *args )
        {
        if( !isEmpty() )
            data.forEach( f, args, 0, current );
        }

    T _FAR *firstThat( int (_FAR *f)(const T _FAR &, void _FAR *),
                       void _FAR *args
                     ) const
        {
        if( isEmpty() )
            return 0;
        return data.firstThat( f, args, 0, current );
        }

    T _FAR *lastThat( int (_FAR * f)(const T _FAR &, void _FAR *),
                      void _FAR *args
                    ) const
        {
        if( isEmpty() )
            return 0;
        return data.lastThat( f, args, 0, current );
        }

};

template <class T> class _CLASSTYPE BI_StackAsVectorIterator :
    public BI_VectorIteratorImp<T>
{

public:

    BI_StackAsVectorIterator( const BI_StackAsVector<T> _FAR & s ) :
        BI_VectorIteratorImp<T>(s.data,0,s.current)
        {
        }

};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class BI_IStackAsVector                            */
/*                                                                        */
/*  Implements a stack of pointers to objects of type T,                  */
/*  using a vector as the underlying implementation.                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class _CLASSTYPE BI_IStackAsVector :
    public BI_StackAsVectorImp<BI_IVectorImp<T>, T _FAR * >,
    public virtual TShouldDelete
{

public:

    friend class _CLASSTYPE BI_IStackAsVectorIterator<T>;

    BI_IStackAsVector( unsigned max = DEFAULT_STACK_SIZE ) :
        BI_StackAsVectorImp<BI_IVectorImp<T>,T _FAR *>( max )
        {
        }

    ~BI_IStackAsVector()
        {
        flush();
        }

    void push( T _FAR *t )
        {
        BI_StackAsVectorImp<BI_IVectorImp<T>,T _FAR *>::push( t );
        }

    T _FAR *pop()

        {
        return (T _FAR *)BI_StackAsVectorImp<BI_IVectorImp<T>,T _FAR *>::pop();
        }

    T _FAR *top() const
        {
        return (T _FAR *)BI_StackAsVectorImp<BI_IVectorImp<T>,T _FAR *>::top();
        }

    void forEach( void (_FAR *f)(T _FAR &, void _FAR *), void _FAR *args )
        {
        if( !isEmpty() )
            data.forEach( f, args, 0, current );
        }

    T _FAR *firstThat( int (_FAR *f)(const T _FAR &, void _FAR *), void _FAR *args ) const
        {
        if( isEmpty() )
            return 0;
        return data.firstThat( f, args, 0, current );
        }

    T _FAR *lastThat( int (_FAR *f)(const T _FAR &, void _FAR *), void _FAR *args ) const
        {
        if( isEmpty() )
            return 0;
        return data.lastThat( f, args, 0, current );
        }

    void flush( DeleteType dt = DefDelete )
        {
        data.flush( delObj(dt), current );
        BI_StackAsVectorImp<BI_IVectorImp<T>,T _FAR *>::flush();
        }

};

template <class T> class _CLASSTYPE BI_IStackAsVectorIterator :
    public BI_IVectorIteratorImp<T>
{

public:

    BI_IStackAsVectorIterator( const BI_IStackAsVector<T> _FAR & s ) :
        BI_IVectorIteratorImp<T>(s.data,0,s.current)
        {
        }

};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class BI_OStackAsVector                                               */
/*                                                                        */
/*  Implements a stack of pointers to Object,                             */
/*  using a vector as the underlying implementation.                      */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _CLASSTYPE BI_OStackAsVector
{

public:

    friend class _CLASSTYPE BI_OStackAsVectorIterator;

    BI_OStackAsVector( unsigned max = DEFAULT_STACK_SIZE ) :
        ostack( max )
        {
        }


    void push( Object _FAR *t )
        {
        ostack.push( t );
        }

    Object _FAR *pop()
        {
        return (Object _FAR *)(ostack.pop());
        }

    Object _FAR *top() const
        {
        return (Object _FAR *)(ostack.top());
        }

    int isEmpty() const
        {
        return ostack.isEmpty();
        }

    int isFull() const
        {
        return ostack.isFull();
        }

    void forEach( void (_FAR*f)(Object _FAR &, void _FAR*), void _FAR*args )
        {
        ostack.forEach( f, args );
        }

    Object _FAR *firstThat( int (_FAR *f)(const Object _FAR &, void _FAR *),
                            void _FAR *args
                          ) const
        {
        return ostack.firstThat( f, args );
        }

    Object _FAR *lastThat( int (_FAR *f)(const Object _FAR &, void _FAR *),
                           void _FAR *args
                         ) const
        {
        return ostack.lastThat( f, args );
        }

    void flush( TShouldDelete::DeleteType dt )
        {
        ostack.flush( dt );
        }

    int getItemsInContainer() const
        {
        return ostack.getItemsInContainer();
        }

private:

    BI_IStackAsVector<Object> ostack;

};

class _CLASSTYPE BI_OStackAsVectorIterator :
    public BI_IStackAsVectorIterator<Object>
{

public:

    BI_OStackAsVectorIterator( const BI_OStackAsVector _FAR & s ) :
        BI_IStackAsVectorIterator<Object>(s.ostack)
        {
        }

};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class BI_TCStackAsVector                                              */
/*                                                                        */
/*  Implements an Object stack, with the full semantics of                */
/*  the BC 2.0 style stack, using a vector as the underlying              */
/*  implementation.                                                       */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _CLASSTYPE BI_TCStackAsVector : public Container
{

public:

    friend class _CLASSTYPE BI_TCStackAsVectorIterator;

    BI_TCStackAsVector( unsigned lim = DEFAULT_STACK_SIZE ) :
        stk(lim)
        {
        }

    void push( Object _FAR & o )
        {
        stk.push( &o );
        }

    Object _FAR & pop()
        {
        return ptrToRef(stk.pop());
        }

    Object _FAR & top() const
        {
        return ptrToRef(stk.top());
        }

    virtual int isEmpty() const
        {
        return stk.isEmpty();
        }

    virtual countType getItemsInContainer() const
        {
        return stk.getItemsInContainer();
        }

    virtual void flush( DeleteType dt = DefDelete )
        {
        stk.flush( dt );
        }

    virtual ContainerIterator _FAR & initIterator() const;

    virtual classType isA() const
        {
        return stackClass;
        }

    virtual char _FAR *nameOf() const
        {
        return "BI_TCStackAsVector";
        }

    virtual void forEach( iterFuncType f, void _FAR *args )
        {
        stk.forEach( f, args );
        }

    virtual Object _FAR & firstThat( condFuncType f, void _FAR *args ) const
        {
        return ptrToRef(stk.firstThat( f, args ));
        }

    virtual Object _FAR & lastThat( condFuncType f, void _FAR *args ) const
        {
        return ptrToRef(stk.lastThat( f, args ));
        }

private:

    BI_OStackAsVector stk;

};

class _CLASSTYPE BI_TCStackAsVectorIterator : public ContainerIterator
{

public:

    BI_TCStackAsVectorIterator( const BI_TCStackAsVector _FAR & s ) :
        iter(s.stk)
        {
        }

    virtual operator int()
        {
        return int(iter);
        }

    virtual Object _FAR & current()
        {
        return Object::ptrToRef(iter.current());
        }

    virtual Object _FAR & operator ++ ( int )
        {
        return Object::ptrToRef(iter++);
        }

    virtual Object _FAR & operator ++ ()
        {
        return Object::ptrToRef(++iter);
        }

    virtual void restart()
        {
        iter.restart();
        }

private:

    BI_OStackAsVectorIterator iter;

};

inline ContainerIterator _FAR & BI_TCStackAsVector::initIterator() const
{
    return *new BI_TCStackAsVectorIterator( *this );
}

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class Stk, class T> class BI_StackAsListImp                 */
/*                                                                        */
/*  Implements the fundamental stack operations, using a stack            */
/*  as the underlying implementation.  The type Stk specifies the         */
/*  form of the stack, either a BI_StackImp<T0> or a                      */
/*  BI_IStackImp<T0>.  The type T specifies the type of the               */
/*  objects to be put on the stack.  When using BI_StackImp<T0>,          */
/*  T should be the same as T0. When using BI_IStackImp<T0>, T            */
/*  should be of type pointer to T0.  See BI_StackAsList and              */
/*  BI_IStackAsList for examples.                                         */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class Stk, class T> class _CLASSTYPE BI_StackAsListImp
{

public:

    BI_StackAsListImp() :
        itemsInContainer(0)
        {
        }

    void push( T t )
        {
        data.add( t );
        itemsInContainer++;
        }

    T pop()
        {
        T t = top();
        data.detach( t, 0 );
        itemsInContainer--;
        return t;
        }

    T top() const
        {
        PRECONDITION( !data.isEmpty() );
        return data.peekHead();
        }

    int isEmpty() const
        {
        return data.isEmpty();
        }

    int isFull() const
        {
        return 0;
        }

    void flush( TShouldDelete::DeleteType = TShouldDelete::DefDelete )
        {
        data.flush( 0 );
        itemsInContainer = 0;
        }

    int getItemsInContainer() const
        {
        return itemsInContainer;
        }

protected:

    Stk data;
    int itemsInContainer;

};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class BI_StackAsList                               */
/*                                                                        */
/*  Implements a stack of objects of type T, using a list as              */
/*  the underlying implementation.                                        */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class _CLASSTYPE BI_StackAsList :
    public BI_StackAsListImp<BI_ListImp<T>,T>
{

public:

    friend class _CLASSTYPE BI_StackAsListIterator<T>;

    void forEach( void (_FAR *f)(T _FAR &, void _FAR *), void _FAR *args )
        {
        data.forEach( f, args );
        }

    T _FAR *firstThat( int (_FAR *f)(const T _FAR &, void _FAR *),
                       void _FAR *args
                     ) const
        {
        return data.firstThat( f, args );
        }

    T _FAR *lastThat( int (_FAR *f)(const T _FAR &, void _FAR *),
                      void _FAR *args
                    ) const
        {
        return data.lastThat( f, args );
        }

};

template <class T> class _CLASSTYPE BI_StackAsListIterator :
    public BI_ListIteratorImp<T>
{

public:

    BI_StackAsListIterator( const BI_StackAsList<T> _FAR & s ) :
        BI_ListIteratorImp<T>(s.data)
        {
        }

};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  template <class T> class BI_IStackAsList                              */
/*                                                                        */
/*  Implements a stack of pointers to objects of type T,                  */
/*  using a linked list as the underlying implementation.                 */
/*                                                                        */
/*------------------------------------------------------------------------*/

template <class T> class _CLASSTYPE BI_IStackAsList :
    public BI_StackAsListImp<BI_IListImp<T>,T _FAR *>,
    public virtual TShouldDelete
{

public:

    friend class _CLASSTYPE BI_IStackAsListIterator<T>;

    ~BI_IStackAsList()
        {
        flush();
        }

    void push( T _FAR *t )
        {
        BI_StackAsListImp<BI_IListImp<T>,T _FAR *>::push( t );
        }

    T _FAR *pop()
        {
        return (T _FAR *)BI_StackAsListImp<BI_IListImp<T>,T _FAR *>::pop();
        }

    T _FAR *top() const
        {
        return (T _FAR *)BI_StackAsListImp<BI_IListImp<T>,T _FAR *>::top();
        }

    void forEach( void (_FAR *f)(T _FAR &, void _FAR *), void _FAR *args )
        {
        data.forEach( f, args );
        }

    T _FAR *firstThat( int (_FAR *f)(const T _FAR &, void _FAR *),
                       void _FAR *args
                     ) const
        {
        return data.firstThat( f, args );
        }

    T _FAR *lastThat( int (_FAR *f)(const T _FAR &, void _FAR *),
                      void _FAR *args
                    ) const
        {
        return data.lastThat( f, args );
        }

    void flush( DeleteType dt = DefDelete )
        { data.flush( delObj(dt) ); }
};

template <class T> class _CLASSTYPE BI_IStackAsListIterator :
    public BI_IListIteratorImp<T>
{

public:

    BI_IStackAsListIterator( const BI_IStackAsList<T> _FAR & s ) :
        BI_IListIteratorImp<T>(s.data)
        {
        }

};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class BI_OStackAsList                                                 */
/*                                                                        */
/*  Implements a stack of pointers to Object,                             */
/*  using a list as the underlying implementation.                        */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _CLASSTYPE BI_OStackAsList
{

public:

    friend class _CLASSTYPE BI_OStackAsListIterator;

    void push( Object _FAR *t )
        {
        ostack.push( t );
        }

    Object _FAR *pop()
        {
        return (Object _FAR *)(ostack.pop());
        }

    Object _FAR *top() const
        {
        return (Object _FAR *)(ostack.top());
        }

    int isEmpty() const
        {
        return ostack.isEmpty();
        }

    int isFull() const
        {
        return ostack.isFull();
        }

    void forEach( void (_FAR*f)(Object _FAR &, void _FAR*), void _FAR*args )
        {
        ostack.forEach( f, args );
        }

    Object _FAR *firstThat( int (_FAR *f)(const Object _FAR &, void _FAR *),
                            void _FAR *args
                          ) const
        {
        return ostack.firstThat( f, args );
        }

    Object _FAR *lastThat( int (_FAR *f)(const Object _FAR &, void _FAR *),
                           void _FAR *args
                         ) const
        {
        return ostack.lastThat( f, args );
        }

    void flush( TShouldDelete::DeleteType dt = TShouldDelete::DefDelete )
        {
        ostack.flush( dt );
        }

    int getItemsInContainer() const
        {
        return ostack.getItemsInContainer();
        }

private:

    BI_IStackAsList<Object> ostack;

};

class _CLASSTYPE BI_OStackAsListIterator :
    public BI_IStackAsListIterator<Object>
{

public:

    BI_OStackAsListIterator( const BI_OStackAsList _FAR & s ) :
        BI_IStackAsListIterator<Object>(s.ostack)
        {
        }

};

/*------------------------------------------------------------------------*/
/*                                                                        */
/*  class BI_TCStackAsList                                                */
/*                                                                        */
/*  Implements an Object stack, with the full semantics of                */
/*  the BC 2.0 style stack, using a list as the underlying                */
/*  implementation.                                                       */
/*                                                                        */
/*------------------------------------------------------------------------*/

class _CLASSTYPE BI_TCStackAsList : public Container
{

public:

    friend class _CLASSTYPE BI_TCStackAsListIterator;

    void push( Object _FAR & o )
        {
        stk.push( &o );
        }

    Object _FAR & pop()
        {
        return ptrToRef(stk.pop());
        }

    Object _FAR & top() const
        {
        return ptrToRef(stk.top());
        }

    virtual int isEmpty() const
        {
        return stk.isEmpty();
        }

    virtual countType getItemsInContainer() const
        {
        return stk.getItemsInContainer();
        }

    virtual void flush( DeleteType dt = DefDelete )
        {
        stk.flush( dt );
        }

    virtual ContainerIterator _FAR & initIterator() const;

    virtual classType isA() const
        {
        return stackClass;
        }

    virtual char _FAR * nameOf() const
        {
        return "BI_TCStackAsList";
        }

    virtual void forEach( iterFuncType f, void _FAR *args )
        {
        stk.forEach( f, args );
        }

    virtual Object _FAR & firstThat( condFuncType f, void _FAR *args ) const
        {
        return ptrToRef(stk.firstThat( f, args ));
        }

    virtual Object _FAR & lastThat( condFuncType f, void _FAR *args ) const
        {
        return ptrToRef(stk.lastThat( f, args ));
        }

private:

    BI_OStackAsList stk;

};

class _CLASSTYPE BI_TCStackAsListIterator : public ContainerIterator
{

public:

    BI_TCStackAsListIterator( const BI_TCStackAsList _FAR & s ) :
        iter(s.stk)
        {
        }

    virtual operator int()
        {
        return int(iter);
        }

    virtual Object _FAR & current()
        {
        return Object::ptrToRef(iter.current());
        }

    virtual Object _FAR & operator ++ ( int )
        {
        return Object::ptrToRef(iter++);
        }

    virtual Object _FAR & operator ++ ()
        {
        return Object::ptrToRef(++iter);
        }

    virtual void restart()
        {
        iter.restart();
        }

private:

    BI_OStackAsListIterator iter;

};

inline ContainerIterator _FAR & BI_TCStackAsList::initIterator() const
{
    return *new BI_TCStackAsListIterator( *this );
}

#endif  // __STACKS_H

