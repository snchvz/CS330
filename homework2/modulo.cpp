/*
Kay Zemoudeh
Oct 10, 2017
modulo.cpp

implementation of Modulo  class given in modulo.h

This file implements most of the usual operators for modulo arithmatic such as =, +, -, ++, etc. along with constructors.

modified by: Andrew Sanchez
implemented ostream friend function, post decrement and pre decrement operator functions, += and -= functions
there is also a check for int value to not return < 0.
Date: 10/17/2017
percentage:85
*/

#include <iostream> 
#include <cassert>

#include "modulo.h"

using namespace std;

Modulo::Modulo(): n(2), value(0) {}

Modulo::Modulo(int m): n(m), value(0) {assert (n > 0);}

Modulo::Modulo(const Modulo & op): n(op.n), value(op.value) {}

Modulo::Modulo(int m, int op)
{
    assert (m > 0);
    n = m;
    value = op;

    if (value >= 0)
	value = value % n;
    else
	while (value < 0)
	    value +=n;
}

Modulo & Modulo::operator=(int op)
{
    value = op;
    value %= n;
    return *this;
}

Modulo & Modulo::operator=(const Modulo & op)
{
    value = op.value;
    value %= n;
    return *this;
}

Modulo Modulo::operator+(int op)
{
     Modulo temp = *this;
     temp.value += op;
     temp.value %= temp.n;
     return temp;
}

Modulo Modulo::operator+(const Modulo & op)
{
    Modulo temp = *this;
    temp.value += op.value;
    temp.value %= temp.n;
    return temp;
}

Modulo Modulo::operator-(const Modulo & op)
{
     Modulo temp = *this;
     temp.value -= op.value;
     while (temp.value < 0)
	temp.value += n;
     temp.value %= temp.n;
     return temp;
}

Modulo & Modulo::operator-=(int op)
{
    value -= op;
    while (value < 0)
	value += n;
    value %= n;
    return *this;
}

Modulo & Modulo::operator+=(const Modulo & op)
{
    value += op.value;
    value %= n;
    return *this;
}

// pre increment and decrement

Modulo & Modulo::operator++()
{
    value++;
    value %= n;
    return *this;
}

Modulo & Modulo::operator--()
{
    value--;
    while (value < 0)
	value += n;
    value %= n; 
    return *this;
}

// post increment and decrement

Modulo Modulo::operator++(int)
{
    Modulo temp = *this;
    ++(*this); // calls pre-increment function
    return temp;
}

Modulo Modulo::operator--(int)
{
    Modulo temp = *this;
    --(*this); //call pre-decrement function
    return temp;
}


//friend


ostream & operator<<(ostream & out, const Modulo & s)
{
    out << s.value; 
    return out;
}

