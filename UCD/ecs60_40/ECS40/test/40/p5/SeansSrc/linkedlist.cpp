// Author: Sean Davis
#include "appt.h"
#include "linkedlist.h"
#include <iostream>

ListNode::ListNode(Appointment *appt, ListNode *n) : appointment(appt), next(n)
{
}  // ListNode();

ListNode::~ListNode()
{
  delete appointment;
}  // ListNode();


LinkedList::LinkedList() : head(NULL)
{
} // LinkedList()


LinkedList::~LinkedList() 
{
  for(ListNode *ptr = head; ptr; ptr = head)
  {
    head = ptr->next;
    delete ptr;
  }   // for each ListNode
} // ~LinkedList()


const Appointment* LinkedList::find(const char* subject) const
{
  static ListNode *ptr = NULL;
  
  if(!ptr)
    ptr = head;
  else // had found a match previously, and are in the middle of list
    ptr = ptr->next;
  
  for( ; ptr; ptr = ptr->next)
   if(*ptr->appointment == subject)
     return ptr->appointment;

  return NULL;
}  // find()
 

LinkedList& LinkedList::operator= (const LinkedList &rhs)
{
  ListNode *ptr2 = NULL;
  
  if(this == &rhs)
    return *this;
  
  for(ListNode *ptr = head; ptr; ptr = head)
  {
    head = ptr->next;
    delete ptr;
  }   // for each ListNode
  
  for(ListNode *ptr = rhs.head; ptr; ptr = ptr->next)
    if(ptr2)
      ptr2 = ptr2->next 
        = new ListNode(new Appointment(*ptr->appointment), NULL);
    else  // empty list
      ptr2 = head =  new ListNode(new Appointment(*ptr->appointment), NULL);
    
  return *this;
}  // operator=


const Appointment* LinkedList::operator[] (int index) const
{
  int i;
  ListNode *ptr;
  
  for(i = 0, ptr = head; ptr && i < index; i++, ptr = ptr->next);
  
  if(i == index && ptr)
    return ptr->appointment;
  else // not found
    return NULL;
} // const operator[]


Appointment*& LinkedList::operator[] (int index)
{
  int i;
  ListNode *ptr, *prev = NULL;
  
  for(i = 0, ptr = head; ptr && i < index; i++, ptr = ptr->next)
    prev = ptr;
  
  if(i == index && ptr)
    return ptr->appointment;
  
  if(prev)
  {
    prev->next = new ListNode(new Appointment(), ptr);
    return prev->next->appointment;
  }  // if prev not NULL
  else  // insert at fron of list
  {
    head = new ListNode(new Appointment(), ptr);
    return head->appointment;
  } // else a previously empty list
}  // non-const operator[]


LinkedList& LinkedList::operator+= (Appointment *appointment)
{
  ListNode *ptr, *prev = NULL;
    
  for(ptr = head; ptr && *ptr->appointment < *appointment; ptr = ptr->next)
    prev = ptr;
  
  if(prev) 
    prev->next = new ListNode(appointment, ptr);
  else  // inserting at front of list.
    head = new ListNode(appointment, ptr);
  
  return *this;
}  // operator+=

ostream& operator<< (ostream& os, const LinkedList &list)
{
  for(ListNode *ptr = list.head; ptr; ptr = ptr->next)
    os << *ptr->appointment;
  
  return os;
} // operator<<()




