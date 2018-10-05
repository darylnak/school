#include <iostream>
#include <fstream>
#include "CPUTimer.h"
#include "CursorList.h"
#include "dsexceptions.h"
#include "LinkedList.h"
#include "QueueAr.h"
#include "SkipList.h"
#include "StackAr.h"
#include "StackLi.h"
#include "vector.h"

vector<CursorNode <int> > cursorSpace(2500001);

using namespace std;

int getChoice();
void RunList(char filename[]);
void RunCursorList(char filename[]);
void RunStackAr(char filename[]);
void RunStackLi(char filename[]);
void RunQueueAr(char filename[]);
void RunSkipList(char filename[]);

int main()
{

  int choice = 0;
  char filename[80];
  CPUTimer ct;

  cout << "Filename >> ";
  cin >> filename;

  do
  {
    choice = getChoice();
    ct.reset();
    switch (choice)
    {
      case 1: RunList(filename); break;
      case 2: RunCursorList(filename); break;
      case 3: RunStackAr(filename); break;
      case 4: RunStackLi(filename); break;
      case 5: RunQueueAr(filename); break;
      case 6: RunSkipList(filename); break;
    }

      cout << "CPU time: " << ct.cur_CPUTime() << endl;
  } while(choice > 0);

  return 0;
}

int getChoice()
{
  char choice[80];

  while(true)
  {
    cout << endl
         << "      ADT Menu" << endl
         << "0. Quit" << endl
         << "1. LinkedList" << endl
         << "2. CursorList" << endl
         << "3. StackAr" << endl
         << "4. StackLi" << endl
         << "5. QueueAr" << endl
         << "6. SkipList" << endl;
    cout << "Your choice >> ";
    cin >> choice;
    cin.ignore();

    if(isdigit(*choice))
    {
      if (atoi(choice) >= 0 && atoi(choice) <= 6)
        return atoi(choice);
      else
        cout << "Your choice is not between 1 and 6." << endl
             << "Please try again." << endl;
    }
    else
      break;
  }

  return 0;
}

void RunList(char filename[])
{
  char command;
  int value;
  List<int> list;
  ListItr<int> itr;
  ifstream inf;

  inf.open(filename);
  inf.ignore(1000, '\n');

  while(inf >> command >> value)
  {
    if(command == 'i')
    {
      if(list.isEmpty())
      {
        list.insert(value, list.zeroth());
        itr = list.first();
      }
      else
        list.insert(value, itr);
    }
    else
      list.remove(value);
  }

  inf.close();
}

void RunCursorList(char filename[])
{
  char command;
  int value;
  CursorList<int> cursor(cursorSpace);
  CursorListItr<int> itr(cursor);
  ifstream inf;

  inf.open(filename);
  inf.ignore(1000, '\n');

  while(inf >> command >> value)
  {
    if(command == 'i')
    {
      if(cursor.isEmpty())
      {
          cursor.insert(value, cursor.zeroth());
          itr = cursor.first();
      }
      else
      {
        cursor.insert(value, itr);
        itr.advance();
      }
    }
    else
      cursor.remove(value);
  }
}

void RunStackAr(char filename[])
{
  char command;
  int value;
  StackAr<int> stack(2500000);
  ifstream inf;

  inf.open(filename);
  inf.ignore(1000, '\n');

  while(inf >> command >> value)
  {
    if(command == 'i')
      stack.push(value);
    else
      stack.pop();
  }
}

void RunStackLi(char filename[])
{
  char command;
  int value;
  StackLi<int> stack;
  ifstream inf;

  inf.open(filename);
  inf.ignore(1000, '\n');

  while(inf >> command >> value)
  {
    if(command == 'i')
      stack.push(value);
    else
      stack.pop();
  }

}

void RunQueueAr(char filename[])
{
  char command;
  int value;
  Queue<int> queue(2500000);
  ifstream inf;

  inf.open(filename);
  inf.ignore(1000, '\n');

  while(inf >> command >> value)
  {
    if(command == 'i')
      queue.enqueue(value);
    else
      queue.dequeue();
  }
}

void RunSkipList(char filename[])
{
  char command;
  int value;
  SkipList<int> skip(-1, 2500000);
  ifstream inf;

  inf.open(filename);
  inf.ignore(1000, '\n');

  while(inf >> command >> value)
  {
    if(command == 'i')
      skip.insert(value);
    else
      skip.deleteNode(value);
  }
}