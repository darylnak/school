// Author: Sean Davis

#include <list>
#include <string>
#include <cassert>
#include "stack.h"


template <typename T>
void Stack<T>::push(const T &object)
{  
  stackList.push_front(object);
} // push()



template <typename T>
void Stack<T>::pop(T &object) 
{
  assert(! stackList.empty());
  
  if(stackList.empty())
    throw string("Stack underflow error.");
  
  object = stackList.front();
  stackList.pop_front();
}  // pop()



