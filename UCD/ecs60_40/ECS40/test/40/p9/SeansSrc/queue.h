#ifndef QUEUE_H
#define	QUEUE_H

#include <stdexcept>

class Whoops
{
  string errorMessage;
public:
  Whoops(const string &str);
  const string& what();
}; // class Whoops



template <typename T>
class Queue 
{
  T* array;
  int frontIndex;
  int backIndex;
  int count;
  int size;
public:
  Queue(int sz);
  void pop(T &object);
  void push(const T &object);
}; // class Queue 


#include "queue.cpp"
#endif	// QUEUE_H

