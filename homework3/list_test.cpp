/*
Andrew sanchez
11/14/17
list_test.cpp
problem: implemented intersect and union functions to create a merged list. function are for ordered or unordered lists
solution: use functions to make a new list using 2 lists that are in order and making a third list that is merged and in ordere, or just unified. unordered lists call merge sort function to sort lists before merging lists
percentage: 100%
*/


#include <iostream>
#include <list>
#include <cstdlib>

using namespace std;

template<class T>    //O(n+m)
list<T> ordered_intersection(const list<T> & a, const list<T> & b)
{
    list<T> t;
    typename list<T>::const_iterator i=a.begin();
    typename list<T>::const_iterator j=b.begin();

    while(i != a.end() and j != b.end()){
	if (*i < *j){
	    t.push_back(*i);
	    i++;
	}else if (*j < *i){
	    t.push_back(*j);
	    j++;
	}else {
	    t.push_back(*i);
	    i++;
	    j++;
	}
    }
    while(i != a.end()){
	t.push_back(*i);
	i++;
    }
    while (j != b.end()){
	t.push_back(*j);
	j++;
    }
    return t;
}

template<class T>    //O(n+m) n = first list, m = second list
list<T> ordered_union(const list<T> & a, const list<T> & b)
{
    list<T> t = a;
    typename list<T>::const_iterator i = b.begin();

    while (i != b.end()){
	t.push_back(*i);
        i++;
    }
    return t;
}
	
template<class T>  //O(nlogn)
void merge(T start, T mid, T stop, int size)
{
    list<typename iterator_traits<T>::value_type> temp(size);
    T i, j, k;

    for(i = start, j = mid, k = temp.begin(); i != mid and j != stop; ){
	if (*i < *j)
	    *k++ = *i++;
	else 
	    *k++ = *j++;
    }

    for ( ; i != mid; )
	*k++ = *i++;
    for ( ; j != stop; )
	*k++ = *j++;

    //copy
    for (i = start, k = temp.begin(); i != stop; i++, k++)
	*i = *k;
}

template<class T>
void ms(T start, T stop, int size)
{
    if (size <= 1)
	return;
    T mid = start;
    for (int i = 0; i < size/2; i++)
	mid++;
    
    ms(start, mid, size/2);
    ms(mid, stop, size - size/2);
    merge(start, mid, stop, size);
}

template<class T>
void ms_list(list<T> & x)
{
    ms(x.begin(), x.end(), x.size());
}

template<class T>    //O(nlogn + mlogm)
list<T> unordered_intersection(list<T> & c, list<T> & d)
{
    ms_list(c);
    ms_list(d);
    list<T> t = ordered_intersection(c,d);
    return t;
}

template<class T>    //O(nlogn + mlogm)
list<T> unordered_union(list<T> & c, list<T> & d)
{
    ms_list(c);
    ms_list(d);
    list<T> t = ordered_union(c, d);
    return t;
}

main()
{
	list<int> myFirst;    //ordered
	list<int> mySecond;    //ordered
	list<int> myThird;    //unordered
	list<int> myFourth;  //unordered

	myFirst.push_back(5);
	myFirst.push_back(7);
	myFirst.push_back(10);
	myFirst.push_back(11);

	mySecond.push_back(1);
	mySecond.push_back(2);
	mySecond.push_back(8);
	mySecond.push_back(9);
	mySecond.push_back(12);
	mySecond.push_back(14);
	mySecond.push_back(15);


	list<int> orderedInter = ordered_intersection(myFirst, mySecond);
	list<int>::iterator it_oi = orderedInter.begin();

	list<int> orderedUnion = ordered_union(myFirst,mySecond);
	list<int>::iterator it_ou = orderedUnion.begin();

	while(it_ou != orderedUnion.end()){
	    cout << *it_ou << endl;
	    it_ou++;
	}

	cout << endl;
	cout << endl;

	while(it_oi != orderedInter.end()){
	    cout << *it_oi << endl;
	    it_oi++;
	}

	myThird.push_back(5);
	myThird.push_back(1);
	myThird.push_back(9);
	myThird.push_back(3);

	myFourth.push_back(2);
	myFourth.push_back(0);
	
	list<int> unInter = unordered_intersection(myThird, myFourth);
	list<int>::iterator it_ui = unInter.begin();

	list<int> unUnion = unordered_union(myThird, myFourth);
	list<int>::iterator it_uu = unUnion.begin();

	cout << endl;

	while(it_ui != unInter.end()){
	    cout << *it_ui << endl;
	    it_ui++;
	}

	cout << endl;
	cout << endl;

	while(it_uu != unUnion.end()){
	    cout << *it_uu << endl;
	    it_uu++;
	}


}
