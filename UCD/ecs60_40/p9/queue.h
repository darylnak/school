//
// Created by Daryl on 6/4/17.
//

#ifndef P9_QUE_H
#define P9_QUE_H

#include <cassert>
#include <stdexcept>
#include <string>

template <typename T>
class Queue
{
  int capacity;
  int end;
  int front;
  int count;
  T* queue;

public:
  Queue(int cap);
  ~Queue();
  void push(const T& data);
  void pop(T& var);
}; // class Queue


class Whoops
{
  string err;

public:
  Whoops(const string str);
  const string& what() const;
}; // class Whoops

#include "queue.cpp"

#endif //P9_QUE_H
