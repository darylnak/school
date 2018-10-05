#ifndef INDEXPAGER_H
  #define INDEXPAGER_H

#include <map>
#include "pager.h"

typedef multimap<int , int, less < int > > IndexPairs;
typedef map< string, int, less < string > > WordKeys;

class IndexPager : Pager
{
  void createWord(const vector<int> &lines,  string *s);
  void createText(IndexPairs &indices, WordKeys &keys);
  void readFile(istream &in, IndexPairs &Indices, WordKeys &keys);
  void readWord(const string &word, IndexPairs &indices, WordKeys &keys, 
                int *count, int lineNum);
public:
  void read(istream &in);
};  // class IndexPager

#endif
