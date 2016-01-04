#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <cmath>
#include <map>

#define gcd 						__gcd
#define rbit						__builtin_ffs // returns 1 + index of least significant 1-bit of x
#define lzero 						__builtin_clz // returns number of leading 0-bits of x
#define tzero   					__builtin_ctz // returns number of trailing 0-bits of x
#define	on_bits						__builtin_popcount //returns number of 1-bits of x
#define maX(a,b)                    ( (a) > (b) ? (a) : (b))
#define miN(a,b)                    ( (a) < (b) ? (a) : (b))

#define w(t)						while(t--)
#define c(n)						cin>>n
#define cg(n)						getline(cin, n)
#define cco(n, m)					cout<<n<<" : "<<m<<"\n";					
#define co(n)						cout<<n<<"\n"
#define ss(n)                       scanf("%s",n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)
#define s(n) 						scanf("%d", &n)
#define p(n)						printf("%d",n)
#define sc(n)                       scanf("%c",&n)
#define emptyLine					printf("\n")
#define l(n)						n.length()
#define f(i, n)						for(int i = 0; i < n; i++)

#define pb(n)						push_back(n)
#define mp(x, y)					make_pair(x, y)

using namespace std;

typedef map<int, int>				mpi;
typedef map<char, int>				mpc;
typedef map<string, int>       		mpw;
typedef stack<int>					si;
typedef pair<int, int> 				ii;
typedef vector<ii>					vii;
typedef vector<int>					vi;
typedef long long 					ll;
typedef long int 					li;

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
		default:
			return 0;
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
		string rpn;
		stack<char> operators;
		stack<char> operands;
		int len = l(expression);
		if(len == 0)
			cout<<"\n\n";
		else{
			f(i, len) {
				if(expression[i] == ')') {
					while(1) {
						char operandOne = operands.top();
						operands.pop();
						if(operandOne == '(')
							break;
						char operandTwo = operands.top();
						operands.pop();
						if(operandTwo == '(') {
							rpn.pb(operandOne);
							break;
						}
						char topOperator = operators.top();
							operators.pop();
						rpn.pb(operandTwo);
						rpn.pb(operandOne);
						rpn.pb(topOperator);
					}
				}	
				else {
					int priority = checkOperatorPriority(expression[i]);
					if(priority) {
						int topPriority = checkOperatorPriority(operators.top());
						while(topPriority > priority) {
							char topOperator = operators.top();
							operators.pop();
							char operandOne = operands.top();
							operands.pop();
							char operandTwo = operands.top();
							operands.pop();
							rpn.pb(operandTwo);
							rpn.pb(operandOne);
							rpn.pb(topOperator);
							topPriority = operators.top();
						}
						operators.push(expression[i]);
					}
					else
						operands.push(expression[i]);
				}
			}
		}
	}
	return 0;
}