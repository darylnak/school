#ifndef BST_H
#define	BST_H


template <typename T>
class BST;

template <typename T>
class BSTNode
{
  T object;
  BSTNode<T> *left;
  BSTNode<T> *right;
  BSTNode(const T &ref, BSTNode <T> *lef, BSTNode<T> *righ);
  friend class BST<T>;
}; // class BSTNode

template <typename T>
class BST 
{
  BSTNode<T> *root;
  void pop(T &object, BSTNode <T> * & node);
  void push(const T &object, BSTNode <T> *node);
public:
  BST();
  void push(const T &object);
  void pop(T &object);
}; // class BST 

#include "BST.cpp"
#endif	// BST_H

