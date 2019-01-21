#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

/*
Andrew Sanchez
priority_queue.h
11/22/17
problem: make a user defined priority queue class
solution: user defined priority queue class uses a vector from largest to smallest value
percentage: 100%
*/

#include <vector>

using namespace std;

template <class T> 
class Priority_queue {
public:
   Priority_queue() : c() { } //O(1)
   Priority_queue(const Priority_queue & p): c(p.c) { } //O(n)
   Priority_queue & operator=(const Priority_queue & p) { c = p.c; return *this; } //O(n)
   // vector destructor is automatically called when an obj of type Priority_queue is destroyed

   bool empty() { return c.empty(); }
   unsigned int size() { return c.size(); }
   void push(const T & x);
   void pop(); 
   T & top() { return c.front(); }
private:
   vector<T> c;
};

template<class T>
void Priority_queue<T>::push(const T & x)  //O(logn)
{
    c.push_back(x);
    unsigned int n = c.size()-1;    //location to start with
    unsigned int parent = (n-1)/2;

    while(n > 0 and c[parent] < c[n]){
	swap(c[n],c[parent]);
	n = parent;
	parent = ((n-1)/2);
    }
}

template<class T>
void Priority_queue<T>::pop() //O(logn)
{
    if (empty())
	return;
    c[0] = c.back();
    c.pop_back();
    unsigned int n = 0;
    unsigned int lc = 1;
    unsigned int rc = 2;
    
    while(lc <= c.size()){
	unsigned int largest = lc;
	if (rc < c.size() and c[lc] < c[rc]){
	    largest = rc;
	    swap(c[n], c[rc]);
	    lc = 2*largest+1;
	    rc = lc+1;
	    n = largest;
	} else {
	    largest = lc;
	    swap(c[n], c[lc]);
	    lc = 2*largest+1;
	    rc = lc+1;
	    n = largest;
	}
    }
}



//____________________________________

#endif
