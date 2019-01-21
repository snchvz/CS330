#include <iostream>
#include <vector>
#include "deque.h"

using namespace std;

int main()
{
    Deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_back(40);

    d.push_front(1);   
    d.push_front(2);   
    d.push_front(3);   
    d.push_front(4); 

    cout << d[1] << endl;
}   
