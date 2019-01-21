/*
andrew Sanchez
test.cpp
11/22/17
problem: simple test for user defined priority queue
solution: user defined priority queue from priority_queue.h
percentage: 100%
*/

#include <iostream>
#include <cassert>

#include "priority_queue.h"

using namespace std;

int main()
{
    Priority_queue<int> p, q, pq;

    int x;
    while(cin >> x)
	p.push(x);

    pq = q = p;

    while(!pq.empty()){
	cout << pq.top() << " ";
	pq.pop();
    }
    cout << endl;
}
