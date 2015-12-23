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

const int MAX_DIFF = 100000;
const int INTERVAL_SIZE = 1000;
const int INTERVAL_RANGE = 2 * INTERVAL_SIZE;
const int FIRST_PRIME = 3;

int main(){
	freopen( "input.in", "r", stdin );
	freopen( "output.out", "w", stdout );
	int test;
	s(test);
	w(test) {
		li m;
		li n;
		scanf("%ld%ld", &m, &n);
		//li base_m = (li)pow((double)m, 0.5);
		if(n < 2)
			printf("EMPTYLINE");
		else if(n == 2)
			printf("%d\n\n", 2);
		else {
			int diff = (n - m) >= 0 ? (n - m) : (- 1) * (n - m);
			vi primes;
			primes.pb(2);
			long start = FIRST_PRIME;
			long end = FIRST_PRIME + INTERVAL_RANGE;
			do {
				if(n < (end))
					end = n;
				long int interval_arr[INTERVAL_SIZE];
				long int offset = 0;
				for(int i = 0; i <= INTERVAL_SIZE; i++) {
					interval_arr[i] = start + offset;
					offset += 2;
				}
				/*
				for(int i = 0; i <= INTERVAL_SIZE; i++)
					printf("%ld ", interval_arr[i]);
				*/
				// Interval created .. check for primes and mark non primes
				start = end + 1;
				end = start + INTERVAL_RANGE;
			}while(n > start);
		}
	}
	return 0;
}