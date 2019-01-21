/*
Andrew Sanchez
set_test.cpp
11/21/17
problem: use a user defined Set class and test its funcionts
solution: program uses user defined set class to test functions. Set class is made of Nodes with value, and 3 pointers. Formed iin a binary tree
percentage: 50%
*/

#include <iostream>
#include <cassert>
#include "set.h"

using namespace std;

main()
{
    Set<int> s;

    assert(s.size() == 0);
    assert(s.empty());
    
    s.insert(10);

    Set<int>::iterator iter = s.begin();
    assert(*iter == 10);

    s.insert(6);

    assert(s.count(6) == 1);
    assert(s.count(10) == 1);
//    assert(s.count(12) == 0); seg fault    
    
    iter = s.begin();
    assert(*iter == 10);
    ++iter;
    assert(*iter == 6);
    ++iter;
    assert(iter == s.end());

    s.insert(7);
    s.insert(9);
    s.insert(8);
    s.insert(11);
    iter = s.begin();
    assert(*iter == 6);

    




}
