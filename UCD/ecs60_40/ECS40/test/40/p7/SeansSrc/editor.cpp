// Author: Sean Davis

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

void readText(vector<string> &text, char **argv)
{
  string s;
  ifstream inf(argv[1]);

  while (getline(inf, s))
    text.push_back(s);

  inf.close();
}  // readText()


void insert(ifstream &inf, vector<string> &text)
{
  int line, pos;
  string s;
  inf >> line >> pos;
  inf.get();
  getline(inf, s);
  vector<string>::iterator itr = text.begin();

  for (int i = 0; i < line; i++)
    itr++;

  itr->insert(pos, s, 0, s.length());
}  // insert()

void replace(ifstream &inf, vector<string> &text)
{
  int line, startPos, endPos;
  string s;
  inf >> line >> startPos >> endPos;
  inf.get();
  getline(inf, s);
  vector<string>::iterator itr = text.begin();

  for (int i = 0; i < line; i++)
    itr++;

  itr->replace(startPos, endPos - startPos, s);
}  //  replace()

void find(ifstream &inf, vector<string> &text)
{
  string s;
  inf.get();
  getline(inf, s);
  cout << s << " ";
  vector<string>::iterator itr = text.begin();

  for (int i = 0; itr != text.end(); i++, itr++)
    if (itr->find(s) != string::npos)
      cout << i << " ";

  cout << endl;
}  // find()

void deleteLine(ifstream &inf, vector<string> &text)
{
  int i, startLine, endLine;
  string s;
  inf >> startLine >> endLine;
  getline(inf, s); // eat up '\n'
  vector<string>::iterator itr = text.begin(), itr2;

  for (i = 0; i < startLine; i++)
    itr++;

  for (itr2 = itr; i < endLine; i++)
    itr2++;

  text.erase(itr, ++itr2);
}  // deleteLine()

void erase(ifstream &inf, vector<string> &text)
{
  size_t pos;
  string s;
  inf.get();  // eat up space after E
  getline(inf, s, '\n');

  for (vector<string>::iterator itr = text.begin(); itr != text.end(); itr++)
  {
    while ((pos = itr->find(s)) != string::npos)
    {
      itr->replace(pos, s.length(), "");

      if (itr->length() == 0)
      {
        vector<string>::iterator itr2 = itr;
        text.erase(itr, ++itr2);
      }  // if found pattern
    } // while more found in line
  } //for each line
}  // erase()

void move(ifstream &inf, vector<string> &text)
{
  int i, startLine, endLine, destinationLine;
  string s;
  inf >> startLine >> endLine >> destinationLine;
  getline(inf, s); // eat up '\n'
  vector<string>::iterator itr = text.begin(), itr2, itr3 = text.begin();

  for (i = 0; i < startLine; i++)
    itr++;

  for (itr2 = itr; i <= endLine; i++)
    itr2++;

  for (i = 0; i < destinationLine; i++)
    itr3++;

  vector<string> text2(itr, itr2);
  text.insert(itr3, text2.begin(), text2.end());
  itr = text.begin();

  if (startLine > destinationLine) // moving before original
  {
    int len = endLine - startLine + 1;
    startLine += len;
    endLine += len;
  } // if moving before original

  for (i = 0; i < startLine; i++)
    itr++;

  for (itr2 = itr; i <= endLine; i++)
    itr2++;

  text.erase(itr, itr2);
}  // move()

void copy(ifstream &inf, vector<string> &text)
{
  int i, startLine, endLine, destinationLine;
  string s;
  inf >> startLine >> endLine >> destinationLine;
  getline(inf, s); // eat up '\n'
  vector<string>::iterator itr = text.begin(), itr2, itr3 = text.begin();

  for (i = 0; i < startLine; i++)
    itr++;

  for (itr2 = itr; i <= endLine; i++)
    itr2++;

  for (i = 0; i < destinationLine; i++)
    itr3++;


  vector<string> text2(itr, itr2);
  text.insert(itr3, text2.begin(), text2.end());

}  // copy()


int main(int argc, char** argv)
{
  char command;
  vector<string> text;
  readText(text, argv);
  ifstream inf(argv[2]);

  while (inf >> command)
    switch (command)
    {
      case 'I' : insert(inf, text); break;
      case 'R' : replace(inf, text); break;
      case 'F' : find(inf, text); break;
      case 'D' : deleteLine(inf, text); break;
      case 'E' : erase(inf, text); break;
      case 'M' : move(inf, text); break;
      case 'C' : copy(inf, text); break;
    } // switch

  ofstream outf(argv[3]);

  for (vector<string>::iterator itr = text.begin(); itr != text.end(); itr++)
    outf << *itr << '\n';

  return 0;
} // main()

