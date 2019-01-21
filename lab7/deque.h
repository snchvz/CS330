#ifndef DEQUE_H
#define DEQUE_H

/*
Andrew Sanchez
deque.h
date: 11/14/17
problem: create a user defined Deque class
solution: user define deque class uses two vectors for data structure
percentage: 100%
*/

#include <vector>
#include <iostream>

using namespace std;

template<class T> class DequeIterator;

template<class T>
class Deque
{
public:
    typedef DequeIterator<T> iterator;

    Deque(): vecOne(), vecTwo() {}
    Deque(const unsigned int size, const T& initial): vecOne(size/2, initial), vecTwo(size-(size/2),initial) {}
    Deque(const Deque<T> & d): vecOne(d.vecOne), vecTwo(d.vecTwo) {}
    ~Deque() {} //destructors for vecOne and vecTwo are automatically called
		//never call a destructor explicitly
    Deque & operator=(const Deque<T> & d);

    T & operator[](unsigned int);
    T & front();
    T & back();
    bool empty();
    iterator begin();
    iterator end();
    void erase(const iterator &);
    void erase(const iterator &, const iterator &);
    void insert(const iterator &, const T &);
    int size();
    void push_front(const T & value);
    void push_back(const T & value);
    void pop_front();
    void pop_back();
protected:
    vector<T> vecOne;
    vector<T> vecTwo;
};

template<class T>
Deque<T> & Deque<T>::operator=(const Deque<T> & x)    //O(1)
{
    vecOne = x.vecOne;
    vecTwo = x.vecTwo;
    return *this;
}

template<class T>
T & Deque<T>::operator[](unsigned int x)    //O(1)
{
    int n = vecOne.size();
    if (x < n)
	return vecOne [(n-1) - x];
    else return vecTwo [x - n];
}

template<class T>
T & Deque<T>::front()    //O(1)
{
    if (vecOne.empty())
	return vecTwo.front();
    else return vecOne.back();
}

template<class T>
T & Deque<T>::back()    //O(1)
{
    if (vecTwo.empty())
	return vecOne.front();
    else return vecTwo.back();
}

template<class T>
bool Deque<T>::empty()    //O(1)
{
    if (vecOne.empty() and vecTwo.empty())
	return true;
    return false;
}

template<class T>
typename Deque<T>::iterator Deque<T>::begin()    //O(1)
{
    if (empty()){
	cout << "Deque is empty" << endl;
	exit(10);
    } else return iterator(this, 0);
}

template<class T>
typename Deque<T>::iterator Deque<T>::end()    //O(1)
{
    if (empty()){
	cout << "Deque is empty" << endl;
	exit(10);
    } else return iterator(this, (vecOne.size()+vecTwo.size()));
}

template<class T>
void Deque<T>::erase(const iterator & b)    //O(n)
{
    int i = b.index;
    if (i < vecOne.size())
	vecOne.erase(vecOne.begin() + ((vecOne.size() - 1) - i));
    else vecTwo.erase(vecTwo.begin() + (i - vecTwo.size()));
}

template<class T>
void Deque<T>::erase(const iterator & b, const iterator & e)    //O(n^2)
{
    int indexb = b.index;
    int indexe = e.index;
    int n = vecOne.size();

    if (n > indexb and n > indexe){
	for ( ; indexb < indexe; indexb++){
	    vecOne.erase(vecOne.begin() + ((n-1) - indexb));
	}
    } else if (n < indexb and n < indexe){
	for ( ; indexb < indexe; indexb++){
	    vecTwo.erase(vecTwo.begin() + (indexb - n));
	}
    } else {
        for ( ; indexb < n; indexb++){
	    vecOne.erase(vecOne.begin() + ((n-1) - indexb));
	}
	for (indexe -= 1; indexe >= n ; indexe--){
	    vecTwo.erase(vecTwo.begin() + (indexe - n));
	}
    }
}

template<class T>
void Deque<T>::insert(const iterator & itr, const T & value)    //O(n)
{
    int temp = itr.index;
    int n = vecOne.size();
    if (empty() or (itr.index == 0))
	vecOne.push_back(value);
    else if (n > temp){
	temp = ((n-1) - temp);
	vecOne.push_back(0);
	for (int i = n-1; i > temp; i--){
	    vecOne[i] = vecOne[i-1];
	}
	vecOne[temp] = value;
    } else {
	temp = temp - n;
	vecTwo.push_back(0);
	for (int i = vecTwo.size() - 1; i > temp; i--){
	    vecTwo[i] = vecTwo[i-1];
	}
	vecTwo[temp] = value;
    }
}
template<class T>
int Deque<T>::size()    //O(1)
{
    return (vecOne.size() + vecTwo.size());
}

template<class T>
void Deque<T>::push_front(const T & value)    //O(1)
{
    vecOne.push_back(value);
}

template<class T>
void Deque<T>::push_back(const T & value)    //O(1)
{
    vecTwo.push_back(value);
}

template<class T>
void Deque<T>::pop_front()    //O(n)
{
    if(empty()){
	cout << "deque is empty" << endl;
	exit(5);
    } else if (vecOne.empty() < 1){
	vecTwo.erase(vecTwo.begin());
    } else vecOne.pop_back();
}

template<class T>
void Deque<T>::pop_back()   //O(n)
{
    if (empty()){
	cout << "deque is empty" << endl;
	exit(5);
    } else if (vecTwo.empty()){
	vecOne.erase(vecOne.begin());
    } else vecTwo.pop_back();
}
//___________________________________________


template<class T>
class DequeIterator
{
    friend class Deque<T>;
    typedef DequeIterator<T> iterator;
public:
    DequeIterator(): theDeque(0), index(0) {}
    DequeIterator(Deque<T> * d, int i): theDeque(d), index(i) {}
    DequeIterator(const iterator & d): theDeque(d.theDeque), index(d.index){}

    T & operator*();
    iterator & operator++();
    iterator operator++(int);
    iterator & operator--();
    iterator operator--(int);
    bool operator==(const iterator & r);
    bool operator!=(const iterator & r);
    bool operator<(const iterator & r);
    T & operator[](unsigned int i);
    iterator operator=(const iterator & r);
    iterator operator+(int i);
    iterator operator-(int i);
protected:
    Deque<T> * theDeque;
    int index;
};

template<class T>
T & DequeIterator<T>::operator*()  //O(1)
{
    return (*theDeque)[index];
}

template<class T>
DequeIterator<T> & DequeIterator<T>::operator++()  //O(1)
{
    index++;
    return *this;
}

template<class T>
DequeIterator<T> DequeIterator<T>::operator++(int)   //O(1)
{
    iterator temp = *this;
    index++;
    return temp;
}

template<class T>
DequeIterator<T> DequeIterator<T>::operator=(const iterator & r)    //O(1)
{
    theDeque = r.theDeque;
    index = r.index;
    return *this;
}

template<class T>
bool DequeIterator<T>::operator==(const iterator & r)    //O(1)
{
    if (theDeque == r.theDeque and index == r.index)
	return true;
    return false;
}

template<class T>
bool DequeIterator<T>::operator!=(const iterator & r)    //O(1)
{
    if (theDeque != r.theDeque or index != r.index)
	return true;
    return false;
}

template<class T>
DequeIterator<T> DequeIterator<T>::operator+(int i)   //O(1)
{
    index += i;
    return *this;
}

template<class T>
DequeIterator<T> DequeIterator<T>::operator-(int i)   //O(1)
{
    index -= i;
    return *this;
}

#endif














