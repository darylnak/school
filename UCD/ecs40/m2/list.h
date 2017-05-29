#ifndef LIST_H
#define LIST_H

template <typename T>
class ListNode
{
  T *data;
  ListNode<T> *next;
  ListNode<T> *prev;
  ListNode(T *data, ListNode<T> *nex, ListNode<T> *pre);
  friend class List<T>;
}; // class ListNode

template <typename T>
class ListNode
{
  ListNode<T> *head;
public:
  List();
  void insert(T *d); // sorted using Date < operator
  void save(const char *filename);
}; // class List

#endif
