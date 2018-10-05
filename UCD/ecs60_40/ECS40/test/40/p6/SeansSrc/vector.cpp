// Author: Sean Davis

#include "vector.h"

template <typename T>
Vector<T>::Vector(int sz) : count(0), size(sz) 
{
  array = new T[size];
} // Vector()


template <typename T>
Vector<T>::~Vector()
{
  delete [] array;
}  // ~Vector()


template <typename T>
int Vector<T>::getCount() const
 {
   return count;
 }  // getCount()


template <typename T>
const T& Vector<T>::operator[] (int index) const
{
  return array[index];
}  //operator[] const


template <typename T>
T& Vector<T>::operator[] (int index)
{
  return array[index];
} // non-const operator[]


template <typename T>
int Vector<T>::operator+= (const T& object)
{
  int pos;
  
  if(count == size)
  {
    T *temp = new T[size * 2];
    
    for(int i = 0; i < count; i++)
      temp[i] = array[i];
  
    delete [] array;
    array = temp;
    size *= 2;
  }  // if count == size
  
  for(pos = count - 1; pos >= 0 && object < array[pos]; pos--)
    array[pos + 1] = array[pos];

  array[++pos] = object;  // copy the new day into pos + 1
  count++;
  return pos;
}  // operator+=
