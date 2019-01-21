/*
Andrew Sanchez
Filename: main.cpp
Date: 10/8/17
description: Program takes 100 float numbers in an array and calculates average and variance(pop)
solution: Program passes array as parameter for average and variance(pop) functions to return a value
percentage: 90%
*/

#include <iostream>

using namespace std;

double average(float a[], int n)
{
    double average = 0;
    for (int i = 0; i < n; i++){
        average += a[i];
    }
    return (average/n);
}

double variance(float a[], double avg, int n)
{
    double variance = 0;

    for (int i = 0; i < n; i++){
        variance += ((a[i] - avg) * (a[i] - avg));
    }
    return (variance/(n));
}

main ()
{
    float floats[100];
    float number;
    int arrayCheck = 0;
    double mean;

    cout << "enter number: " << endl;
    cin >> number;
    while (!cin.eof() and (arrayCheck <= 100)){
	floats[arrayCheck] = number;
	arrayCheck++;
	cin >> number;
    }

    mean = average(floats, arrayCheck);

    if (arrayCheck == 0)
	cout << "No number entered" << endl;
    else {
        cout << "Average = " << mean << endl;
        cout << "Variance = " << variance(floats, mean, arrayCheck) << endl;
    }
}


    




