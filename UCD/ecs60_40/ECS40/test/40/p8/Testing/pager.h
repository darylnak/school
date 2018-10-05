#ifndef PAGER_H
  #define PAGER_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Pager 
{
  int topLine;
  void writePage();
protected:
  vector <string> text;
  const string& intToString(int num);
public:
  Pager():topLine(0){}
  virtual ~Pager(){}
  void processKey(int key);  // f = forward, b = back
  virtual void read(istream &in);
};  // class Pager

#endif

