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

int isEven(int x) {
	while(x > 0)
		x -= 2;
	if(x == 0)
		return x;
	else
		return -1;
}

int main(){
	freopen( "input.in", "r", stdin );
	freopen( "output.out", "w", stdout );
	int test;
	s(test);
	w(test) {
		int x, y;
		s(x);
		s(y);
		if((x % 2 == 0) && (y % 2 == 0)) {
			if((x == y) || (x - y) == 2) {
				printf("%d\n", (x + y));
			}
			else
				printf("No Number\n");
		}
		else if(x % 2 != 0 && y % 2 != 0) {
			if((x == y) || (x - y) == 2) {
				printf("%d\n", (x + y) - 1);
			}
			else
				printf("No Number\n");	
		}
		else
			printf("No Number\n");
	}
	return 0;
}