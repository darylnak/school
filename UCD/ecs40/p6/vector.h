//
// Created by Daryl on 5/16/17.
//

#ifndef P6_VECTOR_H
#define P6_VECTOR_H

#include "day.h"

template <typename T>
class Vector
{
  T* array;
  int count;
  int size;

public:
  Vector(int currSize);
  ~Vector();
  int getCount() const;
  const T& operator[](int index) const;
  T& operator[](int index);
  int operator+= (const T &obj);
}; // class Vector

#include "vector.cpp"

#endif //P6_VECTOR2_H
