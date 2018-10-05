#include <iostream>
#include <cmath>
#include "LeafNode.h"
#include "InternalNode.h"
#include "QueueAr.h"

using namespace std;


LeafNode::LeafNode(int LSize, InternalNode *p,
  BTreeNode *left, BTreeNode *right) : BTreeNode(LSize, p, left, right)
{
  values = new int[LSize];
}  // LeafNode()

void LeafNode::adopt(BTreeNode* sibling, int value)
{
  int max = getMax(value);

  if(max < sibling->getMinimum()) // right sibling transfer
  {
    if(value == max)
      sibling->insert(max);
    else
    {
      --count;
      insert(value);
      sibling->insert(max);
    }
  }
  else // we goin left boys
  {
    if(value < getMinimum())
      sibling->insert(value);
    else
    {
      sibling->insert(getMinimum());

      for(int i = 1; i < count; i++) // shift everything up
        values[i - 1] = values[i];

      --count;
      insert(value);
    }
  }

  if(parent) // update THIS parent with new minimums
    parent->resetMinimum();
}

void LeafNode::connectSibs(BTreeNode* newSib)
{
  if(rightSibling)
    rightSibling->setLeftSibling(newSib);

  newSib->setRightSibling(rightSibling); // right of new sibling is right of old
  newSib->setLeftSibling(this); // left of new sibling is old
  setRightSibling(newSib); // set right of old to new
}

int LeafNode::getMax(int value)
{
  if(values[count - 1] > value)
    return values[count - 1];
  else
    return value;
}

int LeafNode::getMinimum()const
{
  if(count > 0)  // should always be the case
    return values[0];
  else
    return 0;

} // LeafNode::getMinimum()

LeafNode* LeafNode::insert(int value)
{
  if(count != leafSize)
  {
    sort(value); // insert value in order if not full

    return NULL; // no split
  }
  else
  {
    if(leftSibling && !isFull(leftSibling))
    {
      adopt(leftSibling, value);

      return NULL;
    }
    else if(rightSibling && !isFull(rightSibling))
    {
      adopt(rightSibling, value);

      return NULL;
    }
    else
      return split(value); // split and insert
  }
}  // LeafNode::insert()

bool LeafNode::isFull(BTreeNode *lfnode)
{
  return lfnode->getCount() == leafSize;
}

void LeafNode::print(Queue <BTreeNode*> &queue)
{
  cout << "Leaf: ";
  for (int i = 0; i < count; i++)
    cout << values[i] << ' ';
  cout << endl;
} // LeafNode::print()

void LeafNode::sort(int value) // insert value in order. Guaranteed to have space
{
  if(count == 0) // insert if empty
    values[0] = value;
  else // not empty
  {
    for (int i = 0; i <= count; i++)
    {
      if (i == count) // insert at end
      {
        values[i] = value;
        break;
      }

      if (value > values[i]) // keep moving while value is greater than value in array
        continue;
      else // move everything down and insert. Array guaranteed to have space.
      {
        for (int j = count - 1; j >= i; j--)
          values[j + 1] = values[j];

        values[i] = value; // insert
        break;
      }
    }
  }

  if(parent) // update parent minimums
    parent->resetMinimum();

  ++count; // increment count
}

LeafNode* LeafNode::split(int value) // split and insert
{
  LeafNode* newLfNode = new LeafNode(leafSize, parent, this, rightSibling);
  int start = 0; // starting position

  if(leafSize % 2 != 0) // create offset if size odd
    ++start;

  // give all elements starting 1 past the middle.
  for (start += (leafSize / 2); start < leafSize; start++)
    newLfNode->sort(values[--count]);

  if (value > values[count - 1]) // give new sibling value and keep middle
      newLfNode->sort(value);
  else // give middle to new sibling and keep value
  {
    newLfNode->insert(values[--count]);
    sort(value);
  }

  connectSibs(newLfNode);

  return newLfNode;
}