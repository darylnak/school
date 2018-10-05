#ifndef _QUADRATIC_PROBING_H_
#define _QUADRATIC_PROBING_H_

#include "mynew.h"

// MODIFIED
//
// Author: Daryl Nakamoto
// Date:   11/20/17
// Note(s):  Modified heavily for P4.
//
//
// Linear Probing Hash table class
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x
// Hashable find( x )     --> Return item that matches x

class HashEntry
{
public:
  int oldLoc;
  int newLoc;

  HashEntry( int oldLocation = -1, int newLocation = -1) : oldLoc(oldLocation), newLoc(newLocation) { }
};

class HashTable
{
public:
  HashTable(int size) : currentSize(size) { array = new HashEntry[size]; }

  int find(int x);

  void insert(int oldLoc, int newLoc);
  void remove(int x);

private:
  HashEntry* array;
  int currentSize;
};

#endif