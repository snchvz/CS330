#ifndef VECTOR_H
#define VECTOR_H

/*
Andrew Sanchez
Date: 10/18/17
Filename: vector.h
Problem: Create Vector class template T to use in main
solution: Vector template class definitions given on same file. uses constructors using pointers and operator overload functions to modify vectors
Percentage: 75
*/

// Vector.h

using namespace std;

template <class T>
class Vector
{
public:

   typedef T * iterator;

   Vector();
   Vector(unsigned int size);
   Vector(unsigned int size, const T & initial);
   Vector(const Vector<T> & v);           // copy constructor
   ~Vector();

   unsigned int capacity() const;         // return capacity of vector (in elements)
   unsigned int size() const;             // return the number of elements in the vector
   bool empty() const;

   iterator begin();                      // return an iterator pointing to the first element
   iterator end();                        // return an iterator pointing to one past the last element
   T & front();                           // return a reference to the first element
   T & back();                            // return a reference to the last element
   void push_back(const T & value);       // add a new element
   void pop_back();                       // remove the last element

   void reserve(unsigned int capacity);   // adjust capacity
   void resize(unsigned int size);        // adjust size

   T & operator[](unsigned int index);    // return reference to numbered element
   Vector<T>& operator=(const Vector<T> & s);
   Vector<T>& operator=(const T & value);

private:
   unsigned int my_size;
   unsigned int my_capacity;
   T * buffer;
};

// Two sample methods follow

template <class T>
Vector<T>::Vector()
{
	my_size = 0;
	my_capacity = 0;
	buffer = 0;
}

template <class T>
// This line doesn't compile: Vector<T>::iterator Vector<T>::begin()
// This line compiles:        T * Vector<T>::begin()
// But the follwoing line is the better solution:
typename Vector<T>::iterator Vector<T>::begin()
{
    return buffer;
}

template<class T>
Vector<T>::Vector(unsigned int size, const T & initial)
{
    buffer = new T[size];
    for (int i = 0; i < size; i++)
	buffer[i] = initial;
}
template<class T>
Vector<T>::Vector(const Vector<T> & v)
{
    buffer = new T[v.size];
    for (int i = 0; i < size; i++)
	buffer[i] = v.buffer[i];
}

template<class T> 
typename Vector<T>::iterator Vector<T>::end()
{
    int i = capacity;
    return buffer[i];
}

template<class T>
Vector<T>::~Vector()
{
    delete[] buffer;
    buffer = 0;
}

template<class T>
void Vector<T>::reserve(unsigned int capacity)
{
    my_capacity += capacity;
}

template<class T>
void Vector<T>::resize(unsigned int size)
{
    my_size += size;
}

template<class T>
T & Vector<T>::front()
{
    return buffer;
}

template<class T>
T & Vector<T>::back()
{
    int i = capacity;
    return buffer[i];
}

template<class T>
unsigned int Vector<T>::capacity() const
{
    return my_capacity;
}

template<class T>
Vector<T>::Vector(unsigned int size)
{
    my_size = size;
    my_capacity = size;
    buffer = 0;
}

template<class T>
T & Vector<T>::operator[](unsigned int index)
{
    return buffer[index];
}

template<class T>
Vector<T> & Vector<T>::operator=(const Vector<T> & s)
{
    if (my_size != s.size)
	my_size = s.size;
    for(int i = 0; i < my_size; i++)
	buffer[i] = s.buffer[i];
    return *this;
}


template<class T> 
Vector<T> & Vector<T>::operator=(const T & value)
{
    buffer[0] = value;
    return *this;
}


#endif



