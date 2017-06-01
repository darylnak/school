#ifndef INDEX_PAGER_H
#define INDEX_PAGER_H

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "pager.h"

using namespace std;
typedef map<string, int> WordKey;
typedef multimap<int, int> KeyMap;

class IndexPager : public Pager
{
  WordKey keys;
  KeyMap map;
  int currValue;
  int currLine;
public:
  ~IndexPager();
  void read(istream& is);
  void createMaps(string& line);
  void createStrings();
  void createLines(vector<int>& vec, string& line);
}; // class IndexPager

#endif