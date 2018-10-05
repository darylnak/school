#ifndef _QUEUEAR_H
#define _QUEUEAR_H

// Queue class -- array implementation
//
// CONSTRUCTION: with or without a capacity; default is 10
//
// ******************PUBLIC OPERATIONS*********************
// void enqueue( x )      --> Insert x
// void dequeue( )        --> Return and remove least recently inserted item
// Object getFront( )     --> Return least recently inserted item
// bool isEmpty( )        --> Return true if empty; else false
// bool isFull( )         --> Return true if full; else false
// void makeEmpty( )      --> Remove all items
// ******************ERRORS********************************
// Overflow and Underflow thrown as needed

template <class Object>
class Queue
{
public:

  int     size;

  Queue(int capacity);

  bool isEmpty( ) const;
  bool isFull( ) const;
  Object* getFront( ) const;

  void makeEmpty( );
  Object* dequeue( );
  void enqueue(Object* x );

private:
  Object** theArray;
  int     currentSize;
  int     front;
  int     back;

  void increment( int & x );
};

#include "QueueAr.cpp"
#endif
