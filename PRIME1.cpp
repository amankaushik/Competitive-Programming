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

const int FIRST_PRIME = 3;

void getBasePrimes(li m, li n, vector<li> &primes) {
	int sqrtEnd = (int)sqrt((double)n);
	mpi basePrimes;

	basePrimes[0] = -1;
	basePrimes[1] = -1;
	basePrimes[2] = 1;
	
	for(int i = FIRST_PRIME; i <= sqrtEnd; i += 2)
		basePrimes[i] = 1;
	
	for(auto &kv : basePrimes) {
		if(kv.second == 1) {
			for(int j = kv.first * kv.first; j <= sqrtEnd; j += (2 * kv.first))
				basePrimes[j] = -1;
		}
	}
	for(auto &kv : basePrimes) {
		if(kv.second == 1)
			primes.pb(kv.first);
	}
}

void getIntervalPrimes(li m, li n, vector<li> &primes){
	map<li, int> allPrimes;
	for(li i = m; i <= n; i++)
		allPrimes[i] = 1;
	allPrimes[1] = -1;
	for(auto a : primes) {
		li base = m / a;
		li nearest = a * base;
		for(li i = nearest; i <= n; i += a) {
			allPrimes[i] = -1;
		}
	}
	for(auto &kv : allPrimes) {
		if(kv.second == 1)
			primes.pb(kv.first);
	}
}

int main(){
	//freopen( "input.in", "r", stdin );
	//freopen( "output.out", "w", stdout );
	int test;
	s(test);
	w(test) {
		li m;
		li n;
		scanf("%ld%ld", &m, &n);
		if(n == 1)
			printf("\n");
		else if(n == 2)
			printf("2\n");
		else {
			vector<li> primes;
			getBasePrimes(m, n, primes);
			getIntervalPrimes(m, n, primes);
			for(auto a : primes)
				if(a >= m)
					cout<<a<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}