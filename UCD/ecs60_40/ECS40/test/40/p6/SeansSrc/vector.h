#ifndef VECTOR_H
#define	VECTOR_H

template <typename T>
class Vector 
{
  int count;
  int size;
  T *array;
public:
  Vector(int sz);
  ~Vector();
  int getCount() const;
  const T& operator[] (int index) const;
  T& operator[] (int index);
  int operator+= (const T& object);
}; // class Vector 

#include "vector.cpp"
#endif	// VECTOR_H

