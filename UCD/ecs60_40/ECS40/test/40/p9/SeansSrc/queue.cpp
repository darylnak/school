// Author: Sean Davis
#include <cassert>
#include <stdexcept>
#include "queue.h"


Whoops::Whoops(const string &str) : errorMessage(str)
{
} // Whoops

  
const string& Whoops::what()
{
  return errorMessage;
}  // what()


template <typename T>
Queue<T>::Queue(int sz) : frontIndex(0), backIndex(0), count(0), size(sz)
{
  assert(size >= 0);
  
  if(size < 0)
    throw bad_alloc();
  
  array = new T[size];
} // Queue()


template <typename T>
void Queue<T>::pop(T &object)
{
  assert(count > 0);
  
  if(count == 0)
    throw string("Queue underflow error.");
  
  object = array[frontIndex++];
  frontIndex %= size;
  count--;
  
}  // pop()


template <typename T>
void Queue<T>::push(const T &object)
{
  assert(count < size);
  
  if(count == size)
    throw Whoops("Queue overflow error.");
  
  array[backIndex++] = object;
  backIndex %= size;
  count++;
} // push()





