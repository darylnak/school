#include <iostream>
#include <cstdio>
#include "pager.h"

using namespace std;

const string& Pager::intToString(int num)
{
  static string s;
  char buf[100];
  sprintf(buf, "%d", num);
  s = string(buf);
  return s;
}  // intToString()


void Pager::processKey(int key)  // f = forward, b = back
{
  if(key == 'f')
  {
    topLine += 20;

    if(topLine > (int) text.size())
      topLine = text.size();
    writePage();
  } // if key is 'f'
  else // not 'f'
    if(key == 'b')
    {
      topLine -= 20;

      if(topLine < 0)
        topLine = 0;

      writePage();
    } // if key is 'b'
}  // processKey()


void Pager::read(istream &in)
{
  string s;

  while(getline(in, s, '\n'))
    text.push_back(s);
}  // read()


void Pager::writePage()
{
  int end = topLine + 23;

  if(end > (int) text.size())
    end = text.size();

  for(int i = topLine; i < end; i++)
    cout << text[i] << endl;
} // writePage()


