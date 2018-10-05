#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<string>::iterator fitr;

void candp(vector<string> &vec, ifstream &inf);
void deleteLines(vector<string> &vec, ifstream &inf);
void editFile(char *commands, vector<string> &vec);
void erase(vector<string> &vec, ifstream &inf);
void execCommand(char choice, vector<string> &vec, ifstream &inf);
void find(vector<string> &vec, ifstream &inf);
void insert(vector<string> &vec, ifstream &is);
void move(vector<string> &vec, ifstream &inf);
void readFile(char *fname, vector<string> &vec);
void replace(vector<string> &vec, ifstream &inf);
void writeToFile(char *ofname, vector<string> &vec);

int main(int argc, char **argv)
{
  vector<string> file;
  readFile(*(argv + 1), file);
  editFile(*(argv + 2), file);
  writeToFile(*(argv + 3), file);
} // main()


void candp(vector<string> &vec, ifstream &inf)
{
  int start, end, dest, pos = 0;
  string trash;
  fitr itr;

  inf >> start >> end >> dest;
  end = end - start;

  for (itr = vec.begin(); pos < start; itr++)
    ++pos;

  vec.insert(itr + (dest - start), itr, itr + (end + 1));
  getline(inf, trash);
} // candp() - copy and paste


void deleteLines(vector<string> &vec, ifstream &inf)
{
  fitr begin, stop;
  string line;
  int start, end, count = 0;
  inf >> start;
  inf >> end;

  for (begin = vec.begin(); count < start; begin++)
    ++count;

  count = 0;

  for (stop = begin; count <= (end - start) ; stop++)
    --end;

  vec.erase(begin, stop);
  getline(inf, line); // clear line
} // deleteLines()


void editFile(char *commands, vector<string> &vec)
{
  ifstream inf(commands);
  string line;

  while(getline(inf, line, ' '))
    execCommand(*line.c_str(), vec, inf);

  inf.close();
} // editFile()


void erase(vector<string> &vec, ifstream &inf)
{
  string findstr;
  size_t pos = 0;
  getline(inf, findstr);

  for (fitr itr = vec.begin(); itr != vec.end(); itr++)
  {
    if (!(*itr).compare(findstr)) // delete line if same as findstr
      vec.erase(itr);

    else // delete finstr within the string
      while ((*itr).find(findstr) != string::npos)
        (*itr).erase((*itr).find(findstr), findstr.length());

    ++pos;
  } // go through entire vector
} // erase()


void execCommand(char choice, vector<string> &vec, ifstream &inf)
{
  switch (choice)
  {
    case 'I': insert(vec, inf);
      break;

    case 'R': replace(vec, inf);
      break;

    case 'F': find(vec, inf);
      break;

    case 'D': deleteLines(vec, inf);
      break;

    case 'E': erase(vec, inf);
      break;

    case 'C': candp(vec, inf);
      break;

    case 'M': move(vec, inf);
      break;

    default:
      cout << "Something went wrong while reading the command(s). Exiting..."
           << endl;
      return;
  } // get command
} // execCommand()


void find(vector<string> &vec, ifstream &inf)
{
  string findstr;
  size_t pos = 0;
  getline(inf, findstr);
  cout << findstr << ' ';

  for (fitr itr = vec.begin(); itr != vec.end(); itr++)
  {
    if ((*itr).find(findstr) != string::npos) // npos is sentinel value
      cout << pos << ' ';

    ++pos;
  } // go through entire vector

  cout << endl;
} // find()


void insert(vector<string> &vec, ifstream &inf)
{
  string line;
  fitr itr;
  int lineNum;
  size_t pos;

  inf >> lineNum;
  inf >> pos;
  getline(inf, line, ' ');
  getline(inf, line);

  for (itr = vec.begin(); 0 < lineNum; itr++)
    --lineNum;

  (*itr).insert(pos, line);
} // insert()


void move(vector<string> &vec, ifstream &inf)
{
  int start, end, dest, pos = 0;
  string trash;
  fitr itr;

  inf >> start >> end >> dest;

  for (itr = vec.begin(); pos < start; itr++)
    ++pos;

  pos = end - start;

  vec.insert(itr + (dest - start), itr, itr + (pos + 1));

  // delete copied line(s)

  fitr begin, stop;
  int count = 0;

  if (dest == 0)
    count = -pos - 1;

  for (begin = vec.begin(); count < start; begin++)
    ++count;

  count = 0;

  for (stop = begin; count <= (end - start) ; stop++)
    --end;

  vec.erase(begin, stop);

  getline(inf, trash);
} // move()


void readFile(char *name, vector<string> &vec)
{
  string line;
  ifstream inf(name);

  while (getline(inf, line))
    vec.push_back(line);
} // readFile()


void replace(vector<string> &vec, ifstream &inf)
{
  fitr itr;
  string line;
  int lineNum;
  size_t start;
  size_t end;

  inf >> lineNum;
  inf >> start;
  inf >> end;
  getline(inf, line, ' ');
  getline(inf, line);

  for (itr = vec.begin(); 0 < lineNum; itr++)
    --lineNum;

  (*itr).replace(start, (end - start), line);
} // replace()


void writeToFile(char *ofname, vector<string> &vec)
{
  ofstream of;
  of.open(ofname, ios::app);

  // write all elements of vector to file
  for (fitr itr = vec.begin(); itr != vec.end(); itr++)
    of << *itr << endl;

  of.close();
} // writeToFile()