/*
Andrew Sanchez
File name: insertSort.cpp
Date: 10/4/17
Problem Description: Program makes random numbers and orders them least to highest
Solution: program uses an array of random numbers and runs them trough insert sort function to order them least to highest
Percentage: 100
*/

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void print(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
}


void insert_sort(vector<int> &b)
{
    for (int i = 0; (i < b.size() - 1); i++){
	for (int j = i + 1; j < b.size(); j++){
	    if (b[i] > b[j]){
	        swap(b[i], b[j]);
	    }
        }
    }
}

main()
{
    cout << "insertion Sort" << endl;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < v.size(); i++){
	v[i] = rand() % 1000000;
    }
    print(v);
    insert_sort(v);
    cout << "_________________________________________________________________________" << endl;
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
}
