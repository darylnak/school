//
// Created by Daryl on 6/4/17.
//

#ifndef P9_BST_H
#define P9_BST_H

#include <iostream>

template <typename T>
class BSTNode;

template <typename T>
class BST
{
private:
  BSTNode<T> *root;

  // functions

  void push(const T& data, BSTNode<T>* node);
  void pop(T& data, BSTNode<T>*& node);

public:
  BST();
  ~BST();
  void pop(T& var);
  void push(const T& data);
}; // class BST

template <typename T>
class BSTNode
{
  friend class BST<T>;

private:
  T object;
  BSTNode<T>* right;
  BSTNode<T>* left;

 // functions below

  ~BSTNode();
  BSTNode(const T& data, BSTNode<T>* r, BSTNode<T>* l);
}; // class BSTNode

#include "BST.cpp"

#endif //P9_BST_H
