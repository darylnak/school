#include <iostream>
#include "BTree.h"
#include "BTreeNode.h"
#include "LeafNode.h"
#include "InternalNode.h"
using namespace std;

BTree::BTree(int ISize, int LSize):internalSize(ISize), leafSize(LSize)
{
  root = new LeafNode(LSize, NULL, NULL, NULL);
} // BTree::BTree()

// TODO: check proper nodes an recursive calls
void BTree::insert(const int value)
{
  // students must write this

  BTreeNode* check = NULL; // For now, hold return value of an insert
  check = root->insert(value);

  if(check != NULL) // something was split. For now, only leaf
  {
    InternalNode* intrNode = new InternalNode(internalSize, leafSize, NULL, NULL, NULL);
    intrNode->insert(root, check);
    root->setParent(intrNode);
    check->setParent(intrNode);
    root = intrNode;
  }

} // BTree::insert()


void BTree::print()
{
  BTreeNode *BTreeNodePtr;
  Queue<BTreeNode*> queue(1000);

  queue.enqueue(root);
  while(!queue.isEmpty())
  {
    BTreeNodePtr = queue.dequeue();
    BTreeNodePtr->print(queue);
  } // while
} // BTree::print()
