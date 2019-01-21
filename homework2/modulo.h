#ifndef MODULO_H
#define MODULO_H

/*
Kay Zemoudeh
Oct 10, 2017
Modulo.h

A simple modulo n arithmetic class.
An instance of this class is a modulo n object where n > 0.

Modified by: Andrew Sanchez
Date: 10/17/2017
percentage:100
*/

#include <iostream>

using namespace std;

class Modulo {
    int n;
    int value;
public:
    Modulo();			//default constructor, mod 2 binary;
    Modulo(int m);		//mod m object
    Modulo(const Modulo & OP);	//copy constructor
    Modulo(int m, int op);	// mod m, int op

    Modulo & operator=(int);
    Modulo & operator=(const Modulo &);

    Modulo operator+(int);
    Modulo operator+(const Modulo &);
    Modulo & operator++();	//pre-increment
    Modulo operator++(int);	//post_increment

    Modulo operator-(int);
    Modulo operator-(const Modulo &);
    Modulo &  operator--();	//pre-decrement
    Modulo operator--(int);	//post-decrement

    Modulo & operator+=(int);
    Modulo & operator+=(const Modulo &);
    Modulo & operator-=(int);
    Modulo & operator-=(const Modulo &);

    friend ostream& operator<<(ostream &, const Modulo &);
};	//Modulo

#endif
