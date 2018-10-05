#include <iostream>
#include <cstdio>
#include "pager.h"

using namespace std;

const string& Pager::IntToString(int num)
{
  static string s;
  char buf[100];
  sprintf(buf, "%d", num);
  s = string(buf);
  return s;
}  // IntToString()

void Pager::ProcessKey(int key)  // f = forward, b = back
{
  if(key == 'f')
  {
    TopLine += 20;
    if(TopLine > (int) Text.size())
      TopLine = Text.size();
    WritePage();
  } // if key is 'f'
  else
    if(key == 'b')
    {
      TopLine -= 20;
      if(TopLine < 0)
        TopLine = 0;
      WritePage();
    } // if key is 'b'
}  // ProcessKey()

void Pager::read(istream &in)
{
  string s;

  while(getline(in, s, '\n'))
    Text.push_back(s);
}  // read()


void Pager::WritePage()
{
  int end = TopLine + 23;

  if(end > (int) Text.size())
    end = Text.size();

  for(int i = TopLine; i < end; i++)
    cout << Text[i] << endl;
} // WritePage()


