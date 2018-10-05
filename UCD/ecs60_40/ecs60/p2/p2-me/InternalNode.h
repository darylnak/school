#ifndef InternalNodeH
  #define InternalNodeH

#include "BTreeNode.h"

class InternalNode:public BTreeNode
{
  int internalSize;
  BTreeNode **children;
  int *keys;
public:
  InternalNode(int ISize, int LSize, InternalNode *p, BTreeNode *left, BTreeNode *right);
  void adopt(BTreeNode* newSib, int flag = 0);
  void connectSibs(BTreeNode* newSib);
  int getMax(int value);
  int getMinimum()const;
  InternalNode* insert(int value); // returns pointer to new InternalNode if it splits else NULL
  void insert(BTreeNode *oldRoot, BTreeNode *node2); // if root splits use this
  void insert(BTreeNode *newNode); // from a sibling
  bool isFull(BTreeNode* node);
  void print(Queue <BTreeNode*> &queue);
  void resetMinimum();
  void shiftUp();
  BTreeNode* sort(int value);
  InternalNode* split(BTreeNode* lfNode);
}; // InternalNode class

#endif
