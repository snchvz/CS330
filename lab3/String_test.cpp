/*
Andrew Sanchez
file name: String_test.cpp
date: 10/11/17
problem: implement user String class in .h file to create Strings
solution: user strings created with defined string functions in .cpp file
percentage:80
*/

#include <iostream>
#include <cassert>
#include "String1.h"

using namespace std;

int main()
{
    String s1; // s1 == ""
    assert(s1.length() == 0);

    String s2("hi"); //s2 == "hi"
    assert(s2.length() == 2);

    String s3(s2); // s3 == "hi"
    assert(s3.length() == 2);
    assert(s3[0] == 'h');
    assert(s3[1] == 'i');

    s1 = s2; // s1 == "hi"
    assert(s1 == s2);

    s3 = "bye"; // s3 == "bye"
    assert(s3.length() == 3);
    assert(s3[0] == 'b');
    assert(s3[1] == 'y');
    assert(s3[2] == 'e');
    
    s1 += "re"; // s1 == "hire"
    assert(s1.length() == 4);
    assert(s1 == "hire");

    s1 += "d"; // S1 == "hired"
    assert(not (s1 == "hire"));

    cout << "SUCCESS" << endl;
}

