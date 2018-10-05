#ifndef STACK_H
#define	STACK_H

#include <list>
using namespace std;

template <typename T>
class Stack 
{
  list <T> stackList;
public:
  void push(const T &object);
  void pop(T &object);
}; // class stack 


#include "stack.cpp"
#endif	// STACK_H

