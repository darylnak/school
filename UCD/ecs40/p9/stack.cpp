//
// Created by Daryl on 6/4/17.
//

#include "stack.h"

template <typename T>
void Stack<T>::push(const T& data)
{
  stackList.push_front(data);
}  // push()


template <typename T>
void Stack<T>::pop(T& var)
{
  assert(!stackList.empty());

  if (stackList.empty())
  {
    var = -1;
    throw string("Stack underflow error.");
  } // throw error if stack is empty
  else // pop() is OK
  {
    var = stackList.front();
    stackList.pop_front();
  } // pop() is OK
} // pop()