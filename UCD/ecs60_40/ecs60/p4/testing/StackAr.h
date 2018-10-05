#ifndef _STACKAR_H
#define _STACKAR_H

#include "mynew.h"

// StackAr class -- array implementation
//
// CONSTRUCTION: with or without a capacity; default is 10
//
// ******************PUBLIC OPERATIONS*********************
// void push( x )         --> Insert x
// void pop( )            --> Remove most recently inserted item
// Object top( )          --> Return most recently inserted item
// Object topAndPop( )    --> Return and remove most recently inserted item
// bool isEmpty( )        --> Return true if empty; else false
// bool isFull( )         --> Return true if full; else false
// void makeEmpty( )      --> Remove all items
// ********************************************************

template <class Object>
class StackAr
{
public:
  StackAr(short size) : capacity(size)
  {
    topOfStack = -1;
    theArray = new Object[size];
  }

  bool isEmpty( );
  bool isFull( );
  const Object top( );

  void pop( );
  void push(Object x );
  Object topAndPop( );

private:
  Object* theArray;
  short capacity;
  short topOfStack;
};

#include "StackAr.cpp"

#endif
