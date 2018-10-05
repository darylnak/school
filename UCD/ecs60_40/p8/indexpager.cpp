#include "indexpager.h"


IndexPager::~IndexPager()
{

} // ~IndexPager()


void IndexPager::read(istream& is)
{
  string line;
  currValue = 0;
  currLine = 0;

  while(getline(is, line))
  {
    createMaps(line);
    ++currLine;
  } // get all lines and create the maps

  createStrings();
} // read()

// get words from line
void IndexPager::createMaps(string& line)
{
  string key;

  for (size_t i = 0; i < line.length() + 1; i++)
  {
    // if there is a word to process
    if ((i != line.length()) && isalpha(line.at(i)))
      key.push_back(line.at(i));
    else // insert word into multi-map with it's current line number. ID in map
    {
      if (key.length() != 0)
      {
        if (keys.find(key) == keys.end())
        {
          keys.insert(WordKey::value_type(key, currValue++));
          map.insert(KeyMap::value_type(keys.find(key)->second, currLine));
        } // if first occurrence of word, insert into map and multi-map
        else // not first occurrence of word. Insert into multi-map
        {
            map.insert(KeyMap::value_type(keys.find(key)->second, currLine));
          // else, found duplicate on current line. Move on.
        } // not first occurrence of word. Insert into multi-map
      } // check if valid word

      key.clear();
    } // insert word into multi-map with it's current line number. ID in map
  } // process the line and insert words and data into appropriate maps
} // createMaps()


void IndexPager::createStrings()
{
  string line; // line to be inserted into vector<string> text

  for (WordKey::const_iterator itr = keys.begin(); itr != keys.end(); itr++)
  {
    vector<int> linenums; // used to sort multi-map

    for (KeyMap::const_iterator kitr = map.lower_bound(itr->second);
         kitr != map.upper_bound(itr->second); kitr++) // get line num of key
      linenums.push_back(kitr->second); // put line numbers in vectors to sort

    sort(linenums.begin(), linenums.end()); // sort line numbers
    line.append(itr->first + " ");
    createLines(linenums, line);
    line.append(".");
    text.push_back(line);
    line.clear();
  } // go through all keys
} // createStrings()


void IndexPager::createLines(const vector<int>& vec, string& line)
{
  int last = -2;
  bool consecutive = false;

  for (vector<int>::const_iterator itr = vec.begin(); itr != vec.end(); itr++)
  {
    if (*itr != last)
    {
      if (*itr == last + 1)
      {
        consecutive = true;
        last = *itr;
      } // if consecutive
      else // processes string
      {
        if (consecutive)
        {
          line.append("-");
          line.append(intToString(last));
          line.append(", ");
          consecutive = false;
        } // create consecutive line
        else // not consecutive
        {
          if (last >= 0)
            line.append(", ");
        } // not consecutive. Check if you need to add ", "

        line.append(intToString(*itr));
        last = *itr;
      } // process string
    } // ignore duplicate entries in map
  } // go through each line number

  if (consecutive)
    line.append("-" + intToString(last));
} // createLines()