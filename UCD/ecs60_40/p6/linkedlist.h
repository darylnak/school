#ifndef LINKEDLIST_H
#define	LINKEDLIST_H

#include <iostream>
#include "appt.h"

template <typename T>
class LinkedList;

template <typename T>
ostream& operator<< (ostream& os, const LinkedList<T> &list);

template <typename T>
class ListNode
{
  T object;
  ListNode<T> *next;
  ListNode(T object, ListNode<T> *n);
  ~ListNode();
  friend class LinkedList<T>;
  friend ostream& operator<< <T> (ostream& os, const LinkedList<T> &list);
};  // class ListNode

template <typename T>
class LinkedList 
{
  ListNode<T> *head;
public:
  LinkedList();
  ~LinkedList();
  const T find(const char* subject) const;
  LinkedList<T>& operator= (const LinkedList<T> &rhs);
  const T operator[] (int index) const;
  //T& operator[] (int index);
  LinkedList<T>& operator+= (T object);
  friend ostream& operator<< <T> (ostream& os, const LinkedList<T> &list);
  
}; // class linkedlist 

#include "linkedlist.cpp"

#endif	// LINKEDLIST_H

