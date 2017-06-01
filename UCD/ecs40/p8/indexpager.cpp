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
          key.clear();
        } // if first occurrence of word, insert into map and multi-map
        else // not first occurrence of word. Insert into multi-map
        {
          if (map.find(keys.find(key)->second)->second != currLine)
          {
            map.insert(KeyMap::value_type(keys.find(key)->second, currLine));
            key.clear();
          } // make sure only one instance of word per line in multi-map
          else // found duplicate on current line. Move on.
            key.clear();
        } // not first occurrence of word. Insert into multi-map
      } // check if valid word
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
    text.push_back(line);
    line.clear();
  } // go through all keys
} // createStrings()


void IndexPager::createLines(vector<int>& vec, string& line)
{
  int start = *vec.begin(), end = -1, offset = 0;

  for (vector<int>::const_iterator itr = vec.begin();
       itr != vec.end() + 1; itr++)
  {
    if (*itr == start + offset && itr != vec.end())
    {
      end = *itr;
      ++offset;
    } // check if line numbers are n+1 and not reading at end of vector
    else // not n+1
    {
      if ((end != -1) && (end != start))
      {
        line.append(intToString(start) + "-" + intToString(end));
      }
        // if there existed numbers in n+1 order, display with dash
        // must be difference of at least 1
      else // else, there were no numbers in n+1 order
        line.append(intToString(start));

      if (itr != vec.end()) // check if not at end of vector
        line.append(", ");
      else // reached end of vector
        line.append(".");

      start = *itr; // set start to next line number. Soft reset.
      offset = 1; // reset offset
      end = -1;
    } // reached a non-sequential line number
  } // for each line number of the word. Format display of line number(s)
} // createLines()