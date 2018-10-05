#include <iostream>
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <string>
#include "stack.h"
#include "queue.h"
#include "BST.h"

using namespace std;

int main(int argc, char* argv[])
{
  ifstream inf(argv[1]);
  Stack<int> stack;
  Queue<int> *queue = NULL;
  BST<int> bst;
  int qsize;
  char container;
  char operation;
  int data = 0;
  int line = 1;

  inf >> qsize;

  cout << line++ << " " << "Queue size ";

  try
  {
    queue = new Queue<int>(qsize);
  } // try alloc for stack
  catch (const bad_alloc& err)
  {
    cout << err.what() << " ";
  } // catch bad_alloc

  cout << qsize << endl;

  while(inf >> container >> operation)
  {
    switch (container)
    {
      case 'B':
        switch (operation)
        {
          case 'P':
            try
            {
              bst.pop(data);
              cout << line++ << " " << container
                   << operation << "  " << data << endl;
            } // try pop
            catch (const string& err)
            {
              cout << line++ << " " << container << operation
                   << " " << err << " " << data << endl;
            } // catch string if empty

            break;

          case 'U':
            inf >> data;

            try
            {
              bst.push(data);
              cout << line++ << " " << container
                   << operation << "  " << data << endl;
            } // check for duplicates
            catch (string& err)
            {
              cout << line++ << " " << container << operation
                   << " " << err << " " << data << endl;
            } // cat duplicate

            break;

          default:
            cout << "Something went wrong." << endl;
        } // BST functions

        break;

      case 'Q':
        switch (operation)
        {
          case 'P':
            try
            {
              queue->pop(data);
              cout << line++ << " " << container
                   << operation << "  " << data << endl;
            } // try pop
            catch (const Whoops& err)
            {
              cout << line++ << " " << container << operation
                   << " " << err.what() << " " << data << endl;
            } // catch Whoops if queue empty

            break;

          case 'U':
            inf >> data;

            try
            {
              queue->push(data);
              cout << line++ << " " << container
                   << operation << "  " << data << endl;
            } // try push
            catch (const Whoops& err)
            {
              cout << line++ << " " << container << operation
                   << " " << err.what() << " " << data << endl;
            } // catch Whoops if queue full

            break;

          default:
            cout << "Something went wrong." << endl;
        } // Queue functions

        break;

      case 'S':
        switch (operation)
        {
          case 'P':
            try
            {
              stack.pop(data);
              cout << line++ << " " << container
                   << operation << "  " << data << endl;
            } // try pop
            catch (const string& err)
            {
              cout << line++ << " " << container << operation
                   << " " << err << " " << data << endl;
            } // catch string if stack empty

            break;

          case 'U':
            inf >> data;
            stack.push(data);
            cout << line++ << " " << container
                 << operation << "  " << data << endl;
            break;

          default:
            cout << "Something went wrong." << endl;
        } // Stack functions

        break;
    } // process file
  } // while there is input from file

  inf.close();

  if (queue)
    delete queue;
} // main()