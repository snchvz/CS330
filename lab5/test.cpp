/*
Andrew Sanchez
test.cpp
11/5/17
problem: small test for user defined List class. No template class used
solution: Test for push_back function of list as well as iterator operator overloads
percentage: 100%
*/

#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    List<int> l;

    cout << *l.begin() << endl;

}
