#ifndef STRING_H
#define STRING_H

/*
Andrew Sanchez
File name: String.h
Date: 10/11/17
Problem: make user defined String class initialized in header file
Solution: initialize user String class in header file
Percentage: 100
*/

#include <iostream>

using namespace std;

class String {
    int size;
    char *buffer;
public:
    String();
    String(const String &);
    String(const char *);
    ~String();

    int length();
    char & operator[] (const unsigned);
    String operator= (const String &);
    String operator+= (const String &);
    String operator+= (const char *);
    friend bool operator!= (const String &, const String &);
    friend bool operator== (const String &, const String &);








};

#endif
