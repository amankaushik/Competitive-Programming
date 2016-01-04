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

const int MAX_FACTORIAL_SIZE = 158;

void printFactorial(int *factorial, int factorialSize) {
	for(int i = MAX_FACTORIAL_SIZE - factorialSize; i < MAX_FACTORIAL_SIZE; i++)
		p(factorial[i]);
	emptyLine;
}

void multiply(int i, int *factorial, int *factorialSize) {
	int carry = 0, aux;
	for(int j = MAX_FACTORIAL_SIZE - 1; j >= MAX_FACTORIAL_SIZE  - *(factorialSize); j--) {
		aux = (factorial[j] * i) + carry;
		factorial[j] = aux % 10;
		carry = aux / 10;
	}
	while(carry) {
		*(factorialSize) += 1;
		factorial[MAX_FACTORIAL_SIZE - *(factorialSize)] = carry % 10;
		carry /= 10;
	}
}

void getFactorial(int num, int *factorial, int *factorialSize) {
	for(int i = 2; i <= num; i++)
		multiply(i, factorial, factorialSize);
}

int main(){
	int test;
	s(test);
	w(test) {
		int num;
		s(num);
		int factorial[MAX_FACTORIAL_SIZE];
		factorial[MAX_FACTORIAL_SIZE - 1] = 1;
		int factorialSize = 1;
		getFactorial(num, factorial, &factorialSize);
		printFactorial(factorial, factorialSize);
	}
	return 0;
}