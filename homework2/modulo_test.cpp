/*
Kay Zemoudeh
Oct 10, 2017
modulo_test.cpp

this program tests the modulo class written in modulo.h and modulo.cpp
funcionts such as += and -= added through modulo.cpp file to compile with modulo_test file
modified by Andrew Sanchez
Date: 10/17/2017
percentage:80
*/

#include <iostream>
#include <cassert>

#include "modulo.h"

using namespace std;

main()
{
    Modulo o(5,-2), p(5,6);
    cout << "o = " << o << " p = " << p << endl;
    p = p + 7;
    cout << "p = " << p << endl;
    p = p + 15; 
    cout << "p = " << p << endl;
    ++p;
    cout << "p = " << p << endl;
    p++;
    cout << "p = " << p << endl;

    Modulo q(p);
    cout << "q = " << q << endl;
    
    Modulo r(4), s;
    r = 1;
    s = s + r;
    cout << "r = " << r << " s = " << s << endl;
    s = r++;
    cout << "r = " << r << " s = " << s<< endl;
    
    Modulo t(3,2);
    t--;
    t--;
    cout << "t = " << t << endl;
    t--;
    cout << "t = " << t << endl;
   
    Modulo u;
    u = u - t;
    cout << "u = " << u << endl;

    Modulo v(5);
    v -= 3;
    cout << "v = " << v << endl;  
    v += t;
    cout << "v = " << v << endl; 

}

