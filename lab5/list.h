#ifndef LIST_H
#define LIST_H

/*
Andrew Sanch3z
list.h
10/25/17
Problem: User defined List with template class T. Definitions and initializations
Solution: User List class implemented using pointers to link elements of class one after the other.
90%
Percentage: 
*/

#include <algorithm>
#include <iostream>

using namespace std;

//forward declaration of classes defined in this header
template<class T> class Link;
template<class T> class List_iterator;

template<class T>
class List
{
public:
    typedef List_iterator<T> iterator;

    List();
    List(const List<T> & l);
    ~List();

    bool empty() const;
    unsigned int size() const;
    T & back() const;
    T & front() const;
    void push_front(const T & x);
    void push_back(const T & x);
    void pop_front();
    void pop_back();
    iterator begin() const;
    iterator end() const;
    void insert(iterator pos, const T & x); //insert x before pos
    void erase(iterator & pos); //pos must be valid after erase() returns
    List<T> operator=(const List<T> & l);

protected:
    Link<T> * first_link;
    Link<T> * last_link;
    unsigned int my_size;
};

//Definitions

template<class T>
List<T>::List()		//O(1)
{
    first_link = 0;
    last_link = 0;
    my_size = 0;
}

template<class T>
List<T>::List(const List & l)		// O(n)
{
    first_link = 0;
    last_link = 0;
    my_size = 0;
    for(Link<T> * current = l.first_link; current != 0; current = current -> next_link)
        push_back(current -> value);
}

template<class T>
List<T>::~List<T>()		// O(n)
{
    Link<T> * first = first_link;
    while(first != 0){
	Link<T> * next = first -> next_link;
	delete first;
	first = next;
    }
}

template<class T>
bool List<T>::empty() const		// O(1)
{
    if (size() == 0)
	return true;
    return false;
}

template<class T>
unsigned int List<T>::size() const	// O(1)
{
    return my_size;
}

template<class T>
T & List<T>::back() const		// O(1)
{
	return *(end());
}

template<class T> 
T & List<T>::front() const		// O(1)
{
	return *(begin());
}

template<class T>
void List<T>::push_front(const T & x)	// O(1)
{
    Link<T> * new_link = new Link<T>(x);
    if (empty())
	first_link = last_link = new_link;
    else {
    	new_link -> next_link = first_link;
    	first_link -> prev_link = new_link;
    	first_link = new_link;
    }
    my_size++;
}

template<class T>
void List<T>::push_back(const T & x)	//O(1)
{
    Link<T> * new_link = new Link<T>(x);
    if(empty()){
	first_link = last_link = new_link;
	my_size++;
    }else{
    last_link -> next_link = new_link;
    new_link -> prev_link = last_link;
    last_link = new_link;
    my_size++;
    }
} 

template<class T>
void List<T>::pop_front()	//O(1)
{
    if (empty()){
	cout << "list is empty" << endl;
	exit(20);
    }
    if (my_size == 1){
	last_link = 0;
	first_link = 0;
	my_size = 0;
    } else {
	Link<T> * temp_link = first_link;
	first_link = first_link -> next_link;
	first_link -> prev_link = 0;
	if (first_link -> next_link == 0)
	    last_link = first_link; 
	delete temp_link;
	my_size--;
    }	
}	


template<class T>
void List<T>::pop_back()	// O(1)
{
    if (empty()){
	cout << "list is empty" << endl;
	exit(10);
    } else if (my_size == 1){
	last_link = 0;
	first_link = 0;
	my_size = 0;
    } else {
	Link<T> * new_link = last_link;
	last_link = last_link -> prev_link;
	last_link -> next_link = 0;
	delete new_link;
	--my_size;
    }
}

template<class T>
typename List<T>::iterator List<T>::begin() const	//O(1)
{
    return iterator(first_link);
}

template<class T>
typename List<T>::iterator List<T>::end() const		//O(1)
{
    return iterator(last_link);
}

template<class T>
void List<T>::insert(iterator pos, const T & x)		//O(1)
{
    Link<T> * new_link = new Link<T>(x);
    Link<T> * current = pos.current_link;
    if(current == first_link){
	first_link -> prev_link = new_link;
        new_link -> next_link = first_link;
	first_link = new_link;
	return;
    }

    new_link -> next_link = current;
    new_link -> prev_link = current -> prev_link;   
    current -> prev_link = new_link;
    current = new_link -> prev_link;
    if (current != 0)
	current -> next_link = new_link;
    my_size++;
}

template<class T>
void List<T>::erase(iterator & pos)	//O(1)
{
    Link<T> * temp = pos.current_link;
    if (empty()){
	cout << "list is empty" << endl;
        return;
    } else {
	if (temp == first_link){
	    pop_front();
	    return;
	} else if (temp == last_link){
	    pop_back();
	    return;
	} else {
	    temp->prev_link->next_link = temp->next_link;
	    temp->next_link->prev_link = temp->prev_link;
	    delete temp;
	    my_size--;
	}
    }
}

template<class T>
List<T> List<T>::operator=(const List<T> & x)	//O(1)
{	
    if(this == x)
	return *this;
    else
	this = Link<T> (x);
    return *this;
}
    
      
//___________________________________________________________

template<class T>
class Link
{
private:
    Link(const T & x): value(x), next_link(0), prev_link(0) {}

    T value;
    Link<T> * next_link;
    Link<T> * prev_link;

    friend class List<T>;
    friend class List_iterator<T>;
};

template<class T> class List_iterator
{
public:
    typedef List_iterator<T> iterator;
    
    List_iterator(Link<T> * source_link): current_link(source_link) {}
    List_iterator(): current_link(0) {}
    List_iterator(List_iterator<T> * source_iterator): current_link(source_iterator.current_link) {}

    T & operator*(); //dereferencing operator
    iterator operator=(const iterator & rhs);
    bool operator==(const iterator & rhs) const;
    bool operator!=(const iterator & rhs) const;
    iterator & operator++(); // pre-increment, ex.++it
    iterator operator++(int); // post increment, ex. it++
    iterator & operator--(); //pre-decrement
    iterator operator--(int); //post_decrement

protected:
    Link<T> * current_link;
    
    friend class List<T>;
};

template<class T>
T & List_iterator<T>::operator*()	//O(1)
{
    return current_link -> value;
}

template<class T>
List_iterator<T> List_iterator<T>::operator=(const iterator & rhs)	//O(1)
{
    current_link = rhs.current_link;
    return *this;
}

template<class T>
List_iterator<T> & List_iterator<T>::operator++() // pre increment	//O(1)
{
    current_link = current_link -> next_link;
    return *this;
}

template<class T>
bool List_iterator<T>::operator!=(const iterator & rhs) const		//O(1)
{
    if (current_link != rhs.current_link)
	return true;
    else return false;
}   

template<class T>
List_iterator<T> List_iterator<T>::operator++(int)	//O(1)
{
    Link<T> * temp = current_link;
    current_link = current_link->next_link;
    return iterator(temp);
}











#endif


