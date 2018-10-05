#ifndef LeafNodeH
#define LeafNodeH

#include "BTreeNode.h"

class LeafNode:public BTreeNode
{
  int *values;
public:
  LeafNode(int LSize, InternalNode *p, BTreeNode *left, BTreeNode *right);
  void adopt(BTreeNode* sibling, int value);
  void connectSibs(BTreeNode* newSib);
  int getMax(int value);
  int getMinimum() const;
  LeafNode* insert(int value); // returns pointer to new Leaf if splits, else NULL
  bool isFull(BTreeNode *lfnode);
  void print(Queue <BTreeNode*> &queue);
  void sort(int value);
  LeafNode* split(int value);
}; //LeafNode class

#endif
