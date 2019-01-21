/*
Andrew Sanchez
vector_test.cpp
10/24/17
problem: program makes vectors of various datatypes from template class
solution: template class is used to modify vectors and check with assertions
percentage: 40%
*/

#include <iostream>
#include <string>
#include <cassert>
#include "vector.h"



using namespace std;

int main()
{
    Vector<int> v;

    v.reserve(2);
    assert(v.capacity() == 2);

    Vector<string> v1(2);
    assert(v1.capacity() == 2);
    assert(v1.size() == 2);
    assert(v1[0] == "");

    v1[0] = "hi"; // does not compile
    assert(v1[0] == "hi");
}
