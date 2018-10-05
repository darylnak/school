//
// Created by Daryl on 6/4/17.
//

#ifndef P9_STACK_H
#define P9_STACK_H

#include <exception>
#include <cassert>
#include <list>

using namespace std;

template <typename T>
class Stack
{
  list<T> stackList;

public:
  void push(const T& data);
  void pop(T& var);
}; // class Stack

#include "stack.cpp"

#endif //P9_STACK_H
