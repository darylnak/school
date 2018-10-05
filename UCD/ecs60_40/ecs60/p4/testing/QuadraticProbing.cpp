#include "QuadraticProbing.h"

/*
 * oldLoc == -1 EMPTY
 * oldLoc == -2 DELETED
 */

/**
 * Insert new location into the hash table.
 * REMOVED ---> If the item is already present, then do nothing.
 */
void HashTable::insert(int oldLoc, int newLoc)
{
  int currentPos = oldLoc % currentSize;

  while(array[currentPos].oldLoc >= 0 && array[currentPos].oldLoc != oldLoc)
  {
    ++currentPos;  // Compute ith probe
    if(currentPos >= currentSize)
      currentPos -= currentSize;
  }

  array[currentPos] = HashEntry(oldLoc, newLoc);
}

/**
 * Remove item x from the hash table.
 */
void HashTable::remove(int x)
{
  int currentPos = x % currentSize;

  while(array[currentPos].oldLoc != -1 && array[currentPos].oldLoc != x)
  {
    ++currentPos;  // Compute ith probe
    if(currentPos >= currentSize)
      currentPos -= currentSize;
  }

  if( array[ currentPos ].oldLoc > 0 )
    array[ currentPos ].oldLoc = -2;
}

/**
 * Find item x in the hash table.
 * Return the matching item, or -1, if not found.
 */
int HashTable::find(int x)
{
  int currentPos = x % currentSize;

  while(array[currentPos].oldLoc != -1 && array[currentPos].oldLoc != x)
  {
    ++currentPos;  // Compute ith probe
    if(currentPos >= currentSize)
      currentPos -= currentSize;
  }

  return array[ currentPos ].oldLoc > 0 ? array[ currentPos ].newLoc : -1;
}