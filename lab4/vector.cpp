#ifndef VECTOR_H
#define VECTOR_H

/*
Andrew Sanchez
Date: 10/18/17
Filename: vector.h
Problem:
solution:
Percentage:
*/

//vector.h

using namespace std;

template <class T>
class Vector
{
public:
    typedef T * iterator;

    Vector();
    Vector(unsigned int size);
    Vector(unsigned int size, const T & initial);
    Vector(const Vector<T> & v);	// copy constructor
    ~Vector();

    unsigned int capacity() const;	//return capacity of vector (in elements)
    unsigned int size() const;		//return the number of elements in the vector
    bool empty() const;			
   
    iterator begin();			//return an iterator pointing to the first element
    iterator end();			//return an iterator pointing to one past the last element
    T & front();			//return a reference to the first element
    T & back();				//return a reference to the last element
    void push_back(const T & value);	//add a new element 
    void pop_back();			//remove the last element
    
    void reserve(unsigned int capacity);	//adjust capacity
    void resize(unsigned int size);		//adjust size

    T & operator[](unsigned int index);		//return reference to numbered element
    Vector<T> operator=(const Vector<T> &);

private:
    unsigned int my_size;
    unsigned int my_capacity;
    T * buffer;
};

template <class T>
Vector<T>::Vector()
{
    my_size = 0;
    my_capacity = 0;
    buffer = 0;
}

template <class T>
typename Vector<T>::iterator Vector<T>::begin()
{
    return buffer;
}






#endif
