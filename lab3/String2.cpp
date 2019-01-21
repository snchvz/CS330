/*
Andrew Sanchez
File name: String.cpp
Date: 10/11/17
Problem: define functions for user String class in .cpp file
solution: define funcionts using pointers and deferencers to make Strings
Percentage:85
*/

#include <iostream>
#include "String1.h"
#include <cstring>

using namespace std;

String::String()
{
    size = 0;
    buffer = 0; // or NULL
}

String::String(const String & op)
{
    size = op.size;
    buffer = new char[size];
    for (int i = 0; i < size; i++)
	buffer [i] = op.buffer[i];
}

int String::length()
{
    return size;
}

String::~String()
{
    delete [] buffer;
}

String::String(const char * s)
{
    int len = strlen(s);
    buffer = new char[len];
    for (int i = 0; i < len; i++)
        buffer[i] = s[i];
    size = len;
}

char & String::operator[](const unsigned i)
{
    return buffer[i];
}

String String::operator= (const String& op)
{
    delete [] buffer;
    size = op.size;
    buffer = new char[size];
    for (int i = 0; i < size; i++)
        buffer[i] = op.buffer[i]; 
    return *this;
}

String String::operator+= (const String & source)
{
    int temp_size = size + source.size;
    char * temp;
    temp = new char[temp_size];
    int i;

    for (i = 0; i < size; i++)
	temp[i] = buffer[i];
    for (int j = 0; j < source.size; j++)
	    temp[i] = source.buffer[i];
    delete [] buffer;
    size = temp_size;
    buffer = temp;
    return * this;

}

String String::operator+= (const char * s)
{
    int temp_size = strlen(s) + size;
    char * temp;
    temp = new char[temp_size];
    int i;

    for (i = 0; i < size; i++)
	temp[i] = buffer[i];
    for (int j = 0; j < strlen(s); j++, i++)
	temp[i] = s[j];
    delete [] buffer;
    size = temp_size;
    buffer = temp;
    return * this;
}



//friend functions


bool operator!= (const String & s, const String & t)
{
    if (s.size != t.size)
	return true;
    for (int i = 0; i <  s.size and i < t.size; i++){
	    if (s.buffer[i] != t.buffer[i]) 
	        return true;
    }
    return false;
}

bool operator== (const String & s, const String & t)
{
    if (s != t)
        return false;
    return true;
}


