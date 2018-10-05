// Author: Sean Davis 
// Created on May 28, 2017, 11:17 AM

#include <iostream>
#include <fstream>
#include <stdexcept>
#include "stack.h"
#include "queue.h"
#include "BST.h"
using namespace std;


int main(int argc, char** argv) 
{
  Stack<int> stack;
  BST<int> bst;
  Queue<int> *queue;
  char ADT, operation;
  int queueSize, num, lineCount = 1;
  ifstream inf(argv[1]);
  inf >> queueSize;
  inf.ignore(100, '\n');
  cout << lineCount++ << " Queue size ";
  
  try
  {
    queue = new Queue <int> (queueSize);
  } catch (bad_alloc &ba)
  {     
    cout << ba.what() << ' ';
  } // catch 

  cout << queueSize << endl;
  
  while(inf >> ADT >> operation)
  {
    cout << lineCount++ << ' ' << ADT << operation << ' ';
    num = -1;

    if(operation == 'U')
      inf >> num;
  
    inf.ignore(100, '\n');
    
    switch(ADT)
    {
      case 'B' : 
        if(operation == 'P')
        {
          try
          {
             bst.pop(num);
          } catch(string &str) 
          {
            cout << str;
          } // catch string
        } // if a pop()
        else  // a push
        {
          bst.push(num);
        }  // else a push
        
        break;
      case 'Q' :
        if(operation == 'P')
        {
          try
          {
            queue->pop(num);
          } catch(string &str) 
          {
            cout << str;
          } // catch string
        } // if a pop()
        else  // push
        {
          try
          {
            queue->push(num);
          } catch(Whoops &whoops)
          {
            cout << whoops.what();
          }  // catch Whoops
        } // else push

        break;
      case 'S' :
        if(operation == 'P')
        {
          try
          {
            stack.pop(num);
          } catch(string &str) 
          {
            cout << str;
          }  // catch string exception
        }  // if pop()
        else // push
          stack.push(num);
        break;
    }  // switch on ADT
    
    cout << ' ' << num << endl;
  } // while
  
  return 0;
} // main())

