#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "appt.h"

using namespace std;

class LinkedList;

class ListNode
{
  friend class LinkedList;
  friend ostream&operator<<(ostream &os, const LinkedList &list);

private:
  Appointment *appt;
  ListNode *next;
  ListNode(Appointment *app, ListNode *next);
  ~ListNode();
}; // class ListNode

class LinkedList
{
private:
  ListNode *head;

public:
  LinkedList();
  ~LinkedList();
  friend ostream&operator<<(ostream &os, const LinkedList &list);
  Appointment* find(const char *subject) const;
  LinkedList& operator=(const LinkedList &rhs);
  LinkedList& operator+=(Appointment *app);
  const Appointment* operator[](int index) const;
  Appointment*& operator[](int index);
}; // class LinkedList

#endif
