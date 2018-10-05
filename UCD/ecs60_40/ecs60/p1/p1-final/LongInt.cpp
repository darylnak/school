//
// Created by Daryl Nakamoto on 10/9/17.
//

#include "LongInt.h"

LongInt::LongInt()
{ }

LongInt::~LongInt()
{ }

ostream& operator<< (ostream& os, LongInt& longint)
{
    while(!longint.num.isEmpty())
    {
        os << longint.num.top();
        longint.num.pop();
    }

    return os;
}

istream& operator>> (istream& is, LongInt& longint)
{
    char in;

    while(true)
    {
        in = is.get();

        if(isdigit(in))
            longint.num.push(atoi(&in));
        else
            break;
    }

    return is;
}

LongInt& LongInt::operator+ (LongInt& longint2)
{
    int carry = 0;
    StackLi<int> result;

    while(!this->num.isEmpty())
    {
        if(!longint2.num.isEmpty())
        {
            int temp = this->num.top() + longint2.num.top() + carry;

            if (temp >= 10)
            {
                carry = 1;
                result.push(temp % 10);
                this->num.pop();
                longint2.num.pop();
            }
            else
            {
                carry = 0;
                result.push(temp);
                this->num.pop();
                longint2.num.pop();
            }
        }

        else
        {
            if(carry + this->num.top() >= 10)
            {
                result.push((carry + this->num.top()) % 10);
                carry = 1;
                this->num.pop();
            }
            else
            {
                result.push(carry + this->num.top());
                this->num.pop();
                carry = 0;
            }
        }
    }

    if(!longint2.num.isEmpty())
    {
        while(!longint2.num.isEmpty())
        {
            if(!longint2.num.isEmpty())
            {
                int temp = longint2.num.top() + carry;

                if (temp >= 10)
                {
                    carry = 1;
                    result.push(temp % 10);
                    longint2.num.pop();
                }
                else
                {
                    carry = 0;
                    result.push(temp);
                    longint2.num.pop();
                }
            }

            else
            {
                result.push(carry + this->num.top());
                this->num.pop();
            }
        }
    }

    if(carry != 0)
    {
        result.push(carry);
    }
    num = result;

    return *this;
}