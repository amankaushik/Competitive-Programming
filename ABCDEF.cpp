#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <cmath>
#include <map>
#include <cstdint>
#include <bitset>
#include <unordered_map>

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

int main(){
	freopen( "aux/input.in", "r", stdin );
	freopen( "aux/output.out", "w", stdout );
	int N;
	s(N);
	int elements[N];
	f(i, N){
		s(elements[i]);
	}
	vi LHS;
	vi RHS;
	f(i, N) {
		f(j, N) {
			int val = (elements[i] * elements[j]);
			f(k, N)
				LHS.pb(val + elements[k]);
		}
	}
	sort(LHS.begin(), LHS.end());
	f(i, N) {
		f(j, N) {
			int val = (elements[i] + elements[j]);
			f(k, N)
				if(elements[k])
					RHS.pb(val * elements[k]);
		}
	}
	sort(RHS.begin(), RHS.end());
	int size = LHS.size();
	int low, high ,count = 0;
	f(i, size) {
		low = lower_bound(RHS.begin(), RHS.end(), LHS[i]) - RHS.begin();
        high =upper_bound(RHS.begin(), RHS.end(), LHS[i]) - RHS.begin();
        count += (high - low);
	}
	printf("%d\n", count);
	return 0;
}