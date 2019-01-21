/*
Andrew Sanchez
File name: bubbleSort.cpp
Date: 10/4/17
Problem Description: Program sorts random numbers in order
Solution: program uses Bubble sort function to sort random numbers in order
Percentage:100
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


void bubble_sort(vector<int> &b)
{
    for (int i = (b.size() - 1); i > 0; i--){
        for (int j = 0; j < i; j++){
	    if (b[j] > b[j+1]){
	        swap(b[j], b[j+1]);
	    }
	}
    }
}
main()
{
    cout << "Bubble Sort" << endl;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < v.size(); i++){
	v[i] = rand() % 1000000;
    }
    print(v);
    bubble_sort(v);
    cout << "_________________________________________________________" << endl;
    print(v);
}
