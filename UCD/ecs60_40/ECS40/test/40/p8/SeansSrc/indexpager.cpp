#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iostream>
#include "indexpager.h"

using namespace std;

void IndexPager::createWord(const vector<int> &lines, string *s)
{
  int lastLine = -2;
  bool consecutive = false;
  
  for( vector <int>::const_iterator it = lines.begin(); it != lines.end(); it++)
  {
    if(*it != lastLine)  // if different line number
    {
      if(lastLine == *it - 1)
      {
        consecutive = true;
        lastLine = *it;
      } // if consecutive line numbers
      else // Not consecutive line numbers, so time to write
      {
        if(consecutive)
        {
          *s += "-" + intToString(lastLine) + ", ";
          consecutive = false;
        }  // if last line of consecutive lines
        else // non-consecutive line
          if(lastLine >= 0)
            *s += ", ";

        *s += intToString(*it);
        lastLine = *it;
      }  // else not consecutive line numbers.
    } // if different line number
  } //  for each entry for the word
  
   if(consecutive)  // needed for last entry
      *s += "-" + intToString(lastLine);
}  // createWord()


void IndexPager::createText(IndexPairs &indices, WordKeys &keys)
{
  WordKeys::const_iterator keyIt;
  IndexPairs::const_iterator indexIt, lastIndexIt;
  vector <int> lines;
  string s;

  for(keyIt = keys.begin(); keyIt != keys.end(); keyIt++)
  {
    lines.clear();
    s = keyIt->first + " ";
    lastIndexIt = indices.upper_bound(keyIt->second);

    for(indexIt = indices.lower_bound(keyIt->second); indexIt != lastIndexIt; 
      indexIt++)
      lines.push_back(indexIt->second);

    sort(lines.begin(), lines.end());
    createWord(lines, &s);
    s += ".";
    text.push_back(s);
  } // for each word in keys
} // createText()


void IndexPager::readFile(istream &in, IndexPairs &indices, WordKeys &keys)
{
  int count = 0, lineNum = 0;
  string buf;
  string::iterator start, ptr;
  WordKeys::const_iterator keyIt;

  while(getline(in, buf, '\n'))
  {
    start = buf.begin();

    while(start != buf.end())
    {
      while(start != buf.end() && !isalpha(*start))
        start++;

      ptr = start;

      while(ptr != buf.end() && isalpha(*ptr))
        ptr++;

      if(start != buf.end() && ptr != start)
      {
        string word(start, ptr);
        readWord(word, indices, keys, &count, lineNum);
      } // if a word

      start = ptr;
    } // while more words in the line

    lineNum++;
  }  // while more lines
} // readFile()


void IndexPager::read(istream &in)
{
  IndexPairs indices;
  WordKeys keys;

  readFile(in, indices, keys);
  createText(indices, keys);
}  // read()


void IndexPager::readWord(const string &word, IndexPairs &indices, 
                          WordKeys &keys, int *count, int lineNum)
{
  WordKeys::const_iterator keyIt = keys.find(word);
  int key;

  if(keyIt == keys.end())
   {
     keys.insert(WordKeys::value_type(word, *count));
     key = (*count)++;
   }  // if word not found
   else // else word found
     key = keyIt->second;

   indices.insert(IndexPairs::value_type(key, lineNum));
}  // readWord()

