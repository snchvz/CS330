/*
Andrew Sanchez
hw4_main.cpp
12/3/17
problem: simple test for reverse function, reverse iterators and [] operators
solution: user defined list class uses a reverse function to create a reversed list.
reverse iterators flow from current link to previous link instead of next link. 
[] operator uses a parameter index and dereferences it using an iterator to return a value on the list
Percentage: 100
*/

#include <iostream>
#include "list.h"

using namespace std;

main()
{
    List<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);

    for (int i = 0; i < 4; i++)
        cout << l[i] << endl; 

    cout << "_________________" << endl;

    List<int>::revItr revi = l.rend();
    for (int i = 0; i < 4; i++)
	cout << *revi++ << endl;


    List<int> rev = l.reverse();

    cout << "reverse list" << endl;

    for (int i = 0; i < 4; i++)
	cout << rev[i] << endl; 
    
    cout << "_______________" << endl;

    revi = rev.rend();
 
    for (int i = 0; i < 4; i++)
	cout << *revi++ << endl; 

}
