#include <iostream>
#include <cstdio>
#include <priority_queue>
#include <vector>
#include <climits>

#define gcd 						__gcd
#define rbit						__builtin_ffs // returns 1 + index of least significant 1-bit of x
#define lzero 						__builtin_clz // returns number of leading 0-bits of x
#define tzero   					__builtin_ctz // returns number of trailing 0-bits of x
#define	on_bits						__builtin_popcount //returns number of 1-bits of x
#define p(n)						printf("%d",n)
#define sc(n)                       scanf("%c",&n)
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
#define sfi(n) 						scanf("%d", &n)

#define pb(n)						push_back(n)
#define mp(x, y)					make_pair(x, y)

#define si							stack<int>
#define mp 							map<int, int>
#define mp_cf						map<char, int> // char frequency map
#define mp_wf						map<string , int> // word frequency map
#define l(n)						n.length()
#define f(i, n)						for(int i = 0; i < n; i++)

typedef pair<int, int> 				ii
typedef vector<ii>					vii
typedef vector<int>					vi
typedef long long 					ll
typedef long int 					li

using namespace std;

int main(){
	int test;
	sfi(test);
	w(test) {
		int L, S;
		int x, y;
		vii snakes;
		vii ladders;
		sfi(L);
		for(int i = 0; i < L; i++) {
			scanf("%d%d", &x, &y);
			ladders.pb(mp(x,y));
		}
		sfi(S);
		for(int i = 0; i < S; i++) {
			scanf("%d%d", &x, &y);
			snakes.pb(mp(x,y));
		}
		priority_queue < ii, vii, greater<ii> > dkq;
		vi D(100, INT_MAX);
		D[0] = 0; //source
	}
	

	freopen( "input.in", "r", stdin );
	freopen( "output.out", "w", stdout );
	
	return 0;
}