//
// Created by Daryl on 5/16/17.
//

#include "vector.h"

template <typename T>
Vector<T>::Vector(int currSize) :
array(new T[currSize]), count(0), size(currSize)
{
} // Vector()

template <typename T>
Vector<T>::~Vector()
{
  delete [] array;
} // ~Vector()

template <typename T>
int Vector<T>::getCount() const
{
  return count;
} // getCount()

template <typename T>
const T& Vector<T>::operator[](int index) const
{
  return array[index];
} // operator[]()

template <typename T>
T& Vector<T>::operator[](int index)
{
  return array[index];
} // operator[]()

template <typename T>
int Vector<T>::operator+= (const T &obj)
{
  // findDate
  int pos;

  for(pos = 0; pos < count && !(obj == array[pos]); pos++);

  if(pos == count) // not found
  {
    if(count == size)
    {
      T* temp = new T[size * 2];

      for(int i = 0; i < count; i++)
        temp[i] = array[i];

      delete [] array;
      array = temp;
      size *= 2;
    } // insert day into vector

    for(pos = count - 1; pos >= 0 && obj < array[pos]; pos--)
      array[pos + 1] = array[pos];

    array[++pos] = obj;  // copy the new day into pos + 1
    count++;
  } // if not found

  return pos;
} // operator+=()
