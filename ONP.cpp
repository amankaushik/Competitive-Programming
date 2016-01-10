#include <iostream>
#include <cstdio>
#include <string>
#include <stack>


#define w(t)						while(t--)
#define s(n) 						scanf("%d", &n)
#define emptyLine					printf("\n")
#define f(i, n)						for(int i = 0; i < n; i++)

#define pb(n)						push_back(n)

using namespace std;

int checkOperatorPriority(char ch) {
	switch(ch) {
		case '+':
			return 1;
		case '-':
			return 2;
		case '*':
			return 3;
		case '/':
			return 4;
		case '^':
			return 5;
		case '(':
			return -1;
	}
}

int main(){
	freopen( "input.in", "r", stdin );
	freopen( "output.out", "w", stdout );
	int test;
	s(test);
	w(test) {
		string expression;
		cin>>expression;
		string rpn = "";
		stack<char> operators;
		int len = expression.length();
		if(len == 0)
			emptyLine;
		else{
			f(i, len) {
				if(expression[i] == ')') {
					while(operators.top() != '(') {
							rpn.pb(operators.top());
							operators.pop();
						}
						operators.pop();
				}
				else if(expression[i] == '(')
					operators.push(expression[i]);
				else if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^') {
					int priority = checkOperatorPriority(expression[i]);
					while(!operators.empty() && (checkOperatorPriority(operators.top()) > priority)) {
								rpn.pb(operators.top());
								operators.pop();
							}
						operators.push(expression[i]);
				}
				else
					rpn.pb(expression[i]);
			}
			while(!operators.empty()) {
				rpn.pb(operators.top());
				operators.pop();
			}
			cout<<rpn;
		}
		emptyLine;
	}
	return 0;
}