//
// Created by Daryl Nakamoto on 10/8/17.
//

#ifndef LONGINT_LONGINT_H
#define LONGINT_LONGINT_H

#include <iostream>
#include <stdlib.h>
#include "StackLi.h"

using namespace std;

class LongInt
{
private:
    StackLi<int> num;

    void push(int n)
    {
        num.push(n);
    }

public:
    LongInt();
    ~LongInt();
    friend ostream& operator<< (ostream& os, LongInt& longint);
    friend istream& operator>> (istream& is, LongInt& longint);
    LongInt& operator+ (LongInt& longint2);
    void print(ostream& os);

};

#endif //LONGINT_LONGINT_H
