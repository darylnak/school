// Author: Sean Davis

#include <cassert>
#include <string>
#include "BST.h"


template <typename T>
BSTNode<T>::BSTNode(const T &obj, BSTNode <T> *lef, BSTNode<T> *righ) :
  object(obj), left(lef), right(righ)
{
}  // BSTNode()


template <typename T>
BST<T>::BST() : root(NULL)
{
} // BST()


template <typename T>
void BST<T>::pop(T &object) 
{
  assert(root != NULL);
  
  if(root == NULL)
    throw string("BST underflow error.");
  
  pop(object, root);
  
}  // pop()


template <typename T>
void BST<T>::pop(T &object, BSTNode <T> * & node)
{
  if(node->left)
    pop(object, node->left);
  else // node->left is NULL
  {
    object = node->object;
    BSTNode<T> *ptr = node;
    
    if(node->right)
      node = node->right;
    else  // no right child
      node = NULL;

    delete ptr;
  }  // if object less than node's
} // pop()


template <typename T>
void BST<T>::push(const T &object)
{
  if(root)
    push(object, root);
  else // no root
    root  = new BSTNode<T>(object, NULL, NULL);
} // push()


template <typename T>
void BST<T>::push(const T &object, BSTNode <T> *node)
{
  if(object < node->object)
  {
    if(node->left)
      push(object, node->left);
    else // no node->left
      node->left = new BSTNode<T>(object, NULL, NULL);
  }  // if object less than node's
  else // object >= node->object
    if(object > node->object)
    {
      if(node->right)
        push(object, node->right);
      else // no node->right
        node->right = new BSTNode<T>(object, NULL, NULL);
    } // if object greater than node's
    else // duplicate value;
      cout << "duplicate";
} // push()





