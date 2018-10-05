#include "appt.h"
#include "linkedlist.h"
#include <iostream>


template <typename T>
ListNode<T>::ListNode(T obj, ListNode<T> *n) : object(obj), next(n)
{
}  // ListNode();


template <typename T>
ListNode<T>::~ListNode()
{
  delete object; // may not work
}  // ListNode();


template <typename T>
LinkedList<T>::LinkedList() : head(NULL)
{
} // LinkedList()


template <typename T>
LinkedList<T>::~LinkedList()
{
  for(ListNode<T> *ptr = head; ptr; ptr = head)
  {
    head = ptr->next;
    delete ptr;
  }   // for each ListNode
} // ~LinkedList()


template <typename T>
const T LinkedList<T>::find(const char* subject) const
{
  static ListNode<T> *ptr = NULL;
  
  if(!ptr)
    ptr = head;
  else // had found a match previously, and are in the middle of list
    ptr = ptr->next;
  
  for( ; ptr; ptr = ptr->next)
   if(*ptr->object == subject)
     return ptr->object;

  return NULL;
}  // find()


template <typename T>
LinkedList<T>& LinkedList<T>::operator= (const LinkedList<T> &rhs)
{
  ListNode<T> *ptr2 = NULL;
  
  if(this == &rhs)
    return *this;
  
  for(ListNode<T> *ptr = head; ptr; ptr = head)
  {
    head = ptr->next;
    delete ptr;
  }   // for each ListNode
  
  for(ListNode<T> *ptr = rhs.head; ptr; ptr = ptr->next)
    if(ptr2)
      ptr2 = ptr2->next = new ListNode<T>(ptr->object->clone(), NULL);
    else  // empty list
      ptr2 = head =  new ListNode<T>(ptr->object->clone(), NULL);

  return *this;
}  // operator=


template <typename T>
const T LinkedList<T>::operator[] (int index) const
{
  int i;
  ListNode<T> *ptr;
  
  for(i = 0, ptr = head; ptr && i < index; i++, ptr = ptr->next);
  
  if(i == index && ptr)
    return ptr->object;
  else // not found
    return NULL;
} // const operator[]


template <typename T>
LinkedList<T>& LinkedList<T>::operator+= (T object)
{
  ListNode<T> *ptr, *prev = NULL;
    
  for(ptr = head; ptr && *ptr->object < *object; ptr = ptr->next)
    prev = ptr;

  if(prev) 
    prev->next = new ListNode<T>(object, ptr);
  else  // inserting at front of list.
    head = new ListNode<T>(object, ptr);
  
  return *this;
}  // operator+=


template <typename T>
ostream& operator<< (ostream& os, const LinkedList<T> &list)
{
  for(ListNode<T> *ptr = list.head; ptr; ptr = ptr->next)
    os << *ptr->object << endl;
  
  return os;
} // operator<<()