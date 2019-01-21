/*
Andrew Sanchez
file name: main.cpp
Date: 9/27/19
problem description: make an algorithm of infix expressions and convert to postfix
solution: uses stack and stack functions to determin postfix expression with an infix expression input
Percentage: 75%
*/

#include <iostream>
#include <stack>

using namespace std;

int prec(char in)
{
    switch (in){
        case '(': return 0 ;
	case '+': return 1;
	case '-': return 1;
	case '*': return 2;
	case '/': return 2;
	default: return 2;
    }
}

main()
{
    stack<char> operators;
    char nextc;

    cin >> nextc;
    cout << endl;
    while (!cin.eof()){
        if ((nextc >= 48) and (nextc <= 57)){
	    cout << nextc;
	} else {
	       	if (nextc == '('){
		    operators.push(nextc);
		} else if (nextc == ')'){
	            while (!operators.empty() and (operators.top() != '(')){
		        cout << operators.top();
		        operators.pop();
		    }
		    if (!operators.empty()){
		        operators.pop();
		    } else cout << "no matching ')'";
                } else if ((nextc == '*') or (nextc == '/') or (nextc == '+') or (nextc == '-')){
	            if ((operators.empty()) or (prec(operators.top()) < prec(nextc))){
		        operators.push(nextc);
	   	    } else // (prec(operators.top()) >= prec(nextc))
		        while (!operators.empty() and (prec(operators.top()) >= prec(nextc))){
		            cout << operators.top();
	    		    operators.pop();
	 	        }
		        operators.push(nextc);
	        } else cout << "error" << endl;

        }
	cin >> nextc;
    }
    while(!operators.empty()){
        cout << operators.top();
        operators.pop();
    }

}

// time complexity O(n^2)
