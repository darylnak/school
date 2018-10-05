#include <iostream>
#include "InternalNode.h"

using namespace std;

InternalNode::InternalNode(int ISize, int LSize,
  InternalNode *p, BTreeNode *left, BTreeNode *right) :
  BTreeNode(LSize, p, left, right), internalSize(ISize)
{
  keys = new int[internalSize]; // keys[i] is the minimum of children[i]
  children = new BTreeNode* [ISize];
} // InternalNode::InternalNode()

void InternalNode::adopt(BTreeNode* newSib, int flag)
{
  // if flag 0, left sibling transfer
  if(flag == 0)
  {
    // transfer minimum child to left sibling
    children[0]->setParent((InternalNode*)leftSibling);
    ((InternalNode*)leftSibling)->insert(children[0]);
    ((InternalNode*)leftSibling)->resetMinimum(); // update new parent min
    shiftUp();
    --count;
    insert(newSib);
  }
  else
  {
    if(newSib->getMinimum() > children[count - 1]->getMinimum())// new node adopted by right sib
    {
      newSib->setParent((InternalNode*)rightSibling);
      ((InternalNode*)rightSibling)->insert(newSib);
      ((InternalNode*)rightSibling)->resetMinimum();
    }
    else
    {
      children[count - 1]->setParent((InternalNode*)rightSibling);
      ((InternalNode*)rightSibling)->insert(children[count - 1]);
      ((InternalNode*)rightSibling)->resetMinimum(); // update new parent min
      --count;
      insert(newSib);
    }
  }

  if(parent) // update THIS parent with new minimums
    parent->resetMinimum();
}

void InternalNode::connectSibs(BTreeNode* newSib)
{
  if(rightSibling)
    rightSibling->setLeftSibling(newSib);

  newSib->setRightSibling(rightSibling); // right of new sibling is right of old
  newSib->setLeftSibling(this); // left of new sibling is old
  setRightSibling(newSib); // set right of old to new
}

int InternalNode::getMax(int value)
{
  if(keys[count - 1] > value)
    return keys[count - 1];
  else
    return value;
}

int InternalNode::getMinimum()const
{
  if(count > 0)   // should always be the case
    return children[0]->getMinimum();
  else
    return 0;
} // InternalNode::getMinimum()

InternalNode* InternalNode::insert(int value)
{
  // students must write this
  BTreeNode* check = NULL;

  check = sort(value); // insert value in order if not full

  if(check)
  {
    if(leftSibling && !isFull(leftSibling))
      adopt(check);
    else if(rightSibling && !isFull(rightSibling))
      adopt(check, 1);
    else
      return split(check);
  }

  return NULL; // to avoid warnings for now.
} // InternalNode::insert()

bool InternalNode::isFull(BTreeNode* node)
{
  return node->getCount() == internalSize;
}

void InternalNode::insert(BTreeNode *oldRoot, BTreeNode *node2)
{
  // Node must be the root, and node1

  children[0] = oldRoot;
  children[1] = node2;
  count +=2;
  keys[0] = oldRoot->getMinimum();
  keys[1] = node2->getMinimum();

} // InternalNode::insert()

void InternalNode::insert(BTreeNode *newNode) // from a sibling
{
  for(int i = 0; i <= count; i++)
  {
    if(i == count)
    {
      keys[i] = newNode->getMinimum();
      children[i] = newNode;
      break;
    }

    if(newNode->getMinimum() > keys[i])
      continue;
    else
    {
      for (int j = count - 1; j >= i; j--)
      {
        keys[j + 1] = keys[j];
        children[j + 1] = children[j];
      }

      keys[i] = newNode->getMinimum(); // insert
      children[i] = newNode; // insert
      break;
    }
  }

  ++count;
} // InternalNode::insert()

void InternalNode::print(Queue <BTreeNode*> &queue)
{
  int i;

  cout << "Internal: ";
  for (i = 0; i < count; i++)
    cout << keys[i] << ' ';
  cout << endl;

  for(i = 0; i < count; i++)
    queue.enqueue(children[i]);

} // InternalNode::print()

void InternalNode::resetMinimum()
{
  for(int i = 0; i < count; i++)
    keys[i] = children[i]->getMinimum();

  if(parent)
    parent->resetMinimum();
}

void InternalNode::shiftUp()
{
  for(int i = 1; i < count; i++)
  {
    keys[i - 1] = keys[i];
    children[i - 1] = children[i];
  }
}

BTreeNode* InternalNode::sort(int value) // find where to go next
{
  BTreeNode* check = NULL; // check if parent needs to update itself

  for(int i = 0; i <= count; i++)
  {
    if(i == count)
    {
      check = children[i - 1]->insert(value);

      if(check)
      {
        if (count == internalSize)
          return check;
        else
          insert(check);
      }

      return NULL;
    }

    if(value > keys[i])
      continue;
    else
    {
      if(i - 1 != -1)
        check = children[i - 1]->insert(value);
      else
        check = children[i]->insert(value);

      if(check)
      {
        if (count == internalSize)
          return check;
        else
          insert(check);
      }

      break;
    }
  }

  if(parent)
    parent->resetMinimum();

  return NULL;
}

InternalNode* InternalNode::split(BTreeNode* lfNode)
{
  InternalNode* newIntNode = new InternalNode(internalSize, leafSize, parent, this, rightSibling);

  //LeafNode* newLfNode = new LeafNode(leafSize, parent, this, rightSibling);
  int start = 0; // starting position

  if(internalSize % 2 != 0) // create offset if size odd
    ++start;

  // give all elements starting 1 past the middle.
  for (start += (internalSize / 2); start < internalSize; start++)
  {
    children[--count]->setParent(newIntNode);
    newIntNode->insert(children[count]);
  }

  if(lfNode->getMinimum() > keys[count - 1]) // give new sibling value and keep middle
    newIntNode->insert(lfNode);
  else // give middle to new sibling and keep value
  {
    children[--count]->setParent(newIntNode);
    newIntNode->insert(children[count]);
    insert(lfNode);
  }

  connectSibs(newIntNode);

  return newIntNode;
//  if(internalSize % 2 != 0)
//  {
//    if(lfNode->getMinimum() > keys[count / 2])
//    {
//      lfNode->setParent(newIntNode);
//      newIntNode->insert(lfNode);
//
//      for (int i = (internalSize / 2) + 1; i < internalSize; i++) // move middle to end to new sib
//      {
//        children[--count]->setParent(newIntNode);
//        newIntNode->insert(children[count]);
//      }
//    }
//    else
//    {
//      for(int i = internalSize / 2; i < internalSize; i++) // move middle to end to new sib
//      {
//        children[--count]->setParent(newIntNode);
//        newIntNode->insert(children[count]);
//      }
//
//      insert(lfNode);
//    }
//  }
//  else
//  {
//    if(lfNode->getMinimum() > keys[(count / 2) - 1]) // even internal. start left of middle line
//    {
//      lfNode->setParent(newIntNode);
//      newIntNode->insert(lfNode);
//
//      for(int i = internalSize / 2; i < internalSize; i++)
//      {
//        children[--count]->setParent(newIntNode);
//        newIntNode->insert(children[count]);
//      }
//    }
//    else
//    {
//      for(int i = (internalSize / 2) - 1; i < internalSize; i++)
//      {
//        children[--count]->setParent(newIntNode);
//        newIntNode->insert(children[count]);
//      }
//
//      insert(lfNode);
//    }
//  }
//
//  connectSibs(newIntNode);
//
//  return newIntNode;
}