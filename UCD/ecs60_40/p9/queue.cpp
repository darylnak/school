//
// Created by Daryl on 6/4/17.
//

#include "queue.h"

template <typename T>
Queue<T>::Queue(int cap) :
capacity(cap), end(0), front(0), count(0)
{
  assert(capacity > 0);

  if (capacity <= 0) // invalid capacity
    throw bad_alloc();
  else // valid capacity
    queue = new T[capacity];
} // Queue()


template <typename T>
Queue<T>::~Queue()
{
  delete [] queue;
} // ~Queue()


template <typename T>
void Queue<T>::push(const T& data)
{
  assert(count < capacity);

  if (count >= capacity) // queue full
    throw Whoops("Queue overflow error.");
  else // push data
  {
    ++count;
    queue[end] = data;

    if (++end == capacity) // reset end to beginning
      end = 0;
  } // push data
} // push()


template <typename T>
void Queue<T>::pop(T& var)
{
  assert(count > 0);

  if (count == 0)
  {
    var = -1;
    throw Whoops("Queue underflow error.");
  } // queue empty
  else // pop data
  {
    --count;
    var = queue[front];

    if (++front == capacity) // reset front to front (0)
      front = 0;
  } // pop data
} // pop()

Whoops::Whoops(const string str)
{
  err = str;
} // Whoops()

const string& Whoops::what() const
{
  return err;
} // what()