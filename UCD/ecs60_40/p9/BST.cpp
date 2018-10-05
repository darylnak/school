//
// Created by Daryl on 6/4/17.
//

#include "BST.h"

template <typename T>
BST<T>::BST() : root(NULL)
{

} // BST()


template <typename T>
BST<T>::~BST()
{
  T temp;

  while (root)
  {
    pop(temp);
  } // go through tree and delete
} // ~BST()


template <typename T>
BSTNode<T>::BSTNode(const T& data, BSTNode<T>* r, BSTNode<T>* l) :
object(data), right(r), left(l)
{

} // BSTNode()


template <typename T>
BSTNode<T>::~BSTNode()
{

} // ~BSTNode()


template <typename T>
void BST<T>::pop(T& var)
{
  assert (root);

  if (!root)
  {
    var = -1;
    throw string("BST underflow error.");
  } // root is empty
  else // start popping
  {
    if (!root->left)
    {
      BSTNode<T> *temp = root;
      var = temp->object;
      root = root->right;
      delete temp;
    } // if root has no left child
    else // find min and pop
      pop(var, root);
  } // start popping
} // pop()


template <typename T>
void BST<T>::pop(T& data, BSTNode<T>*& node)
{
  if (!node->left->left && node->left->right)
  {
    BSTNode<T> *temp = node->left;
    data = temp->object;
    node->left = node->left->right;
    delete temp;
  } // if only left child with right child
  else // don't need to worry about right child
  {
    if (node->left->left) // recursive call
      pop(data, node->left);
    else // delete node
    {
      data = node->left->object;
      delete node->left;
      node->left = NULL;
    } // delete node
  } // don't need to worry about right child
} // pop()


template <typename T>
void BST<T>::push(const T& data)
{
  if (!root) // first push
    root = new BSTNode<T>(data, NULL, NULL);
  else // recursive call to push
    push(data, root);
} // push()


template <typename T>
void BST<T>::push(const T& data, BSTNode<T>* node)
{
  if (data == node->object)
    throw string("duplicate");

  if (data < node->object)
  {
    if (!node->left) // No left. Insert data
      node->left = new BSTNode<T>(data, NULL, NULL);
    else // push if left is occupied
      push(data, node->left);
  } // go left
  else // go right
  {
    if (!node->right) // No right. Insert data
      node->right = new BSTNode<T>(data, NULL, NULL);
    else // push if right is occupied
      push(data, node->right);
  } // go right
} // push()