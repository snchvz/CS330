#ifndef SET_H
#define SET_H

/*
Andrew Sanchez
set.h
11/15/17
problem: make a user defined Set class for implementation
solution: User defined Set class uses nodes with a value and three pointers to form a binary tree
percentage: 85%
*/

#include <iostream>

using namespace std;

template<class T> class Set;
template<class T> class Set_iterator;

template<class T>

class Node {
public:
    Node(): value(0), parent(0), leftChild(0), rightChild(0) {}
    Node(const T & x, Node * p, Node * lc, Node * rc):
	value(x), parent (p), leftChild(lc), rightChild(rc) {}
    // here copy constructor and assignment op dont make too much sense! here they are anyways
    Node(const Node & n):
	value(n.value), parent(0), leftChild(0), rightChild(0) {}
    Node & operator=(const Node & n) {value = n.value; return *this;}

    ~Node() {delete leftChild; delete rightChild;} // this is very recursive, delete also calls the destructor
	//of the object is is deleting

    void insert(Node<T> * newNode); //this is a helper func for Set::insert()
    Node * find(const T & x);
protected:
    T value;
    Node * parent;
    Node * leftChild;
    Node * rightChild;

friend class Set<T>;
friend class Set_iterator<T>;
};


template<class T>
void Node<T>::insert(Node<T> * newNode) //O(logn)
{
    if(newNode->value <= value)
	if (leftChild != 0)
	    leftChild -> insert(newNode);
	else {
	    newNode -> parent = this;
	    leftChild = newNode;
	}
    else
	if (rightChild != 0)
	    rightChild -> insert(newNode);
	else {
	    newNode -> parent = this;
	    rightChild = newNode;
	}

}

template<class T>
Node<T> * Node<T>::find(const T & x) //O(logn)
{
    if (x==value)
	return this;
    if (x<value){
	if(leftChild==0)
	    return 0;
	return(leftChild->find(x));
    }
}

//_______________________________________

template<class T>
class Set {
public:
    typedef Set_iterator<T> iterator;

    Set(): root(0), my_size(0) {}

    //the big three
    Set(const Set<T> &);
    ~Set() {delete root;}
    Set operator=(const Set &);

    bool empty() const {return root == 0;}
    unsigned int size() const {return my_size;}
    iterator insert(const T & x); // return an iterator to x if it already exists
	//otherwise insert and return an iterator to x
    void erase(const iterator & it);
    void erase(const T & x) {iterator i = find(x); erase(i);}
    unsigned int count(const T & c) const; //returs 1 or 0 because this is a set
	//not a multi-set
    iterator find(const T & x) const;
    iterator begin() const; //for inorder traversal
    iterator end() const {return iterator(0);}
protected:
    Node<T> * root;
    unsigned int my_size;
};

template<class T>
Set<T>::Set(const Set<T> & op)  // O(n)
{
    root = 0;
    for (iterator i = op.begin(); i != op.end(); ++i)
	insert(*i);
}

template<class T>
Set<T> Set<T>::operator=(const Set<T> & op) //O(n)
{
    delete root;
    root = 0;
    for (iterator i = op.begin(); i != op.end(); ++i)
        insert(*i);
    return *this;
}

template<class T>
void Set<T>::erase(const iterator & it) //O(logn)
{
    if (root != 0 and it != end()) {
	Node<T> * p = it.n;
	Node<T> * left = p -> leftChild;
	Node<T> * right = p -> rightChild;
	if (right != 0) {
	    // left slide
	    Node<T> * left_slide = right;
	    while (left_slide -> leftChild)
	        left_slide = left_slide -> leftChild;
	    // connect the subtrees after left slide
	    left_slide -> leftChild = left;
	    if (left != 0)
		left -> parent = left_slide;
	    // now connect right subtree to bypass p
	    right -> parent = p -> parent;
	    if (p -> parent)
		if (p -> parent -> leftChild == p)
		    p -> parent -> leftChild = right;
	        else p -> parent -> rightChild = right;
	    else // p was root
		root = right;
	} else {
	    if (left == 0) {
		if (p -> parent)
		    if (p -> parent -> leftChild == p)
			p -> parent -> leftChild = 0;
		    else p -> parent -> rightChild = 0;
		else //p was root
		    root = left;
	    }
	}
	p -> leftChild = 0;
	p -> rightChild = 0;
	delete p;
	my_size--;
    }
}

template<class T>
unsigned int Set<T>::count(const T & c) const // O(logn)
{
    int counter = 0;
    if ((*iterator(root->find(c))) != 0){
	counter++;
    	return counter;
    }
    return counter;
}

template<class T>
Set_iterator<T> Set<T>::find(const T & x) const // O(logn)
{
    if (root == 0)
	return iterator(0);
    return iterator(root->find(x));
}

template<class T>
Set_iterator<T> Set<T>::begin() const  //O(logn)
{
    Node<T> * top = root;
    while(top -> parent != 0)
        top = top -> parent;
    return iterator(top);
}

template<class T>
Set_iterator<T> Set<T>::insert(const T & x)  //O(logn)
{
  //  if (count(x) > 0)
//	return iterator(0);
    Node<T> * newNode = new Node<T> (x,0,0,0);

    if (root == 0)
        root = newNode;
    else root -> insert (newNode);
    my_size++;
    return iterator(newNode);

}


//_________________________________

template<class T>
class Set_iterator {
public:
    Set_iterator(): n(0) {}
    Set_iterator(Node<T> * newNode): n(newNode) {}

    bool operator==(Set_iterator it) const {return n==it.n;}
    bool operator!=(Set_iterator it) const {return n!=it.n;}
    Set_iterator & operator++(); //inorder traversal, pre increment
    Set_iterator operator++(int); //inorder traversal, post increment
    T & operator*() {return n->value;}
    Set_iterator & operator=(Set_iterator<T> it) {n=it.n; return *this;}

protected:
    Node<T> * n;
friend class Set<T>;
};

template<class T>
Set_iterator<T> & Set_iterator<T>::operator++() // O(n)
{
    if (n ->leftChild)
	n = n -> leftChild;
    else if (n ->rightChild)
	n = n -> rightChild;
    else {
	Node<T> * child = n;
	n = n -> parent;
	while (n && ((n->rightChild == child) || (n->rightChild == 0))){
	    child = n;
	    n = n->parent;
	}
        if (n && n ->rightChild)
	    n = n -> rightChild;
    }
    return *this;
}

template<class T>
Set_iterator<T> Set_iterator<T>::operator++(int)  //O(n)
{
    Set_iterator<T> clone (*this);
    operator++();
    return clone;
}

//more code for Set_iterator goes here

#endif

