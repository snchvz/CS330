/*
Andrew Sanchez
File name: selectSort.cpp
Date: 10/4/17
Problem Description: Program makes random numbers and puts them in order least to highest
Solution: program makes an array of random numbers and uses function selection sort to order them least to highest
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


void select_sort(vector<int> &b)
{
    for (int i = 0; i < (b.size() - 1); i++){
	for (int j = i + 1; j < b.size(); j++){
	    if (b[i] > b[j]){
	        swap(b[i], b[j]);
	    }
	}
    }
}

main()
{
    cout << "Selection Sort" << endl;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < v.size(); i++){
	v[i] = rand() % 1000000;
    }
    print(v);
    select_sort(v);
    cout << endl;
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
}
