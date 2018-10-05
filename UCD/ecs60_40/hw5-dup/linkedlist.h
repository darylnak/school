#ifndef LINKEDLIST_H
#define	LINKEDLIST_H

#include <iostream>
#include "appt.h"

class LinkedList;

class ListNode
{
  Appointment *appointment;
  ListNode *next;
  ListNode(Appointment *appt, ListNode *n);
  ~ListNode();
  friend class LinkedList;
  friend ostream& operator<< (ostream& os, const LinkedList &list);
};  // class ListNode


class LinkedList 
{
  ListNode *head;
public:
  LinkedList();
  ~LinkedList();
  const Appointment* find(const char* subject) const;
  LinkedList& operator= (const LinkedList &rhs);
  const Appointment* operator[] (int index) const;
  Appointment*& operator[] (int index);
  LinkedList& operator+= (Appointment *appointment);
  friend ostream& operator<< (ostream& os, const LinkedList &list);
  
}; // class linkedlist 

#endif	// LINKEDLIST_H

