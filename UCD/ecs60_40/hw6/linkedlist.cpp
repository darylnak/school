#include <iostream>
#include "linkedlist.h"

LinkedList& LinkedList::operator=(const LinkedList &rhs)
{
  ListNode *tail = NULL;

  if (this != &rhs)
  {
    if (head) // clear LHS - getting rid of nodes, but keeping list
      for (ListNode *curr = head; curr; curr = head)
      {
        head = curr->next;

        delete curr;
      } // if LHS is not empty

    for (ListNode *curr = rhs.head; curr; curr = curr->next)
    {
      if (!head)
      {
        head = new ListNode(new Appointment(*curr->appt), NULL);
        tail = head;
      } // if list is empty

      // list not empty
      else // the list is not empty
      {
        tail = tail->next = new ListNode(new Appointment(*curr->appt), NULL);
      } // else not empty
    } // go through lis
  } // if lhs != rhs

  return *this;
} // operator=()

std::ostream&operator<<(std::ostream &os, const LinkedList &list)
{
  for (ListNode *curr = list.head; curr; curr = curr->next)
    os << *curr->appt;

  return os;
} // operator<<()

LinkedList::LinkedList() : head(NULL)
{
} // LinkedList() constructor

LinkedList::~LinkedList()
{
  for (ListNode *curr = head; curr; curr = head)
  {
    head = curr->next;
    delete curr;
  } // delete nodes from list
} // ~LinkedList() destructor

Appointment* LinkedList::find(const char *subject) const
{
  static ListNode *curr;
  ListNode *temp;

  if (!curr)
    curr = head;

  if (curr == (ListNode*) 1)
  {
    curr = NULL;
    return NULL;
  } // if end of list

  for (curr; curr; curr = curr->next)
    if (*curr->appt == subject)
    {
      temp = curr;
      curr = curr->next;

      if (!curr)
        curr = (ListNode*) 1;

      return temp->appt;
    } // check for found subject and if end of list

  return NULL;
} // find()

ListNode::ListNode(Appointment *app, ListNode *next) : appt(app), next(next)
{
} // ListNode() constructor

ListNode::~ListNode()
{
  delete appt;
} // ~ListNode() destructor


LinkedList& LinkedList::operator+=(Appointment *app)
{
  ListNode *curr, *prev = NULL;

  if (!head)
  {
    curr = new ListNode(app, NULL);
    head = curr;

    return *this;
  } // if head is NULL

  for (curr = head; curr && *curr->appt < *app; curr = curr->next)
    prev = curr;

  if (!prev)
  {
    prev = new ListNode(app, head);
    head = prev;

    return *this;
  } // If need to append to front

  prev->next = new ListNode(app, curr);


  return *this;
} // operator+=()

const Appointment* LinkedList::operator[](int index) const
{
  ListNode *curr = head;

  for (int i = 0; curr && i < index; i++)
    curr = curr->next;

  return curr->appt;
} // operator[]() const

Appointment*& LinkedList::operator[](int index)
{
  int i;
  ListNode *curr = head, *prev;

  for (i = 0; curr && i < index; i++)
  {
    prev = curr;
    curr = curr->next;
  } // get index

  if ((index - i) > 0)
  {
    ListNode *newNode = new ListNode(new Appointment, NULL);
    curr->next = newNode;

    return newNode->appt;
  } // if out of bounds, create new node

  if (!curr && i == 0)
  {
    curr = new ListNode(new Appointment, NULL);
    head = curr;
    return curr->appt;
  } // append to beggining

  if (!curr) {
    curr = new ListNode(new Appointment, NULL);
    prev->next = curr;
  } // end

  return curr->appt;
} // operator[]()