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

bool breakingCondition(int term1, int term2, int term3) {
	return (term1 == 0 && term2 == 0 && term3 == 0) ? true : false;
}

const string OP1 = "AP";
const string OP2 = "GP";

int main(){
	freopen( "input.in", "r", stdin );
	freopen( "output.out", "w", stdout );
	while(1) {
		int term1, term2, term3;
		scanf("%d%d%d", &term1, &term2, &term3);

		if(breakingCondition(term1, term2, term3))
			break;
		
		if((term2 - term1) == (term3 - term2))
			cout<<OP1<<" "<<(term3 + (term3 - term2))<<"\n";
		else
			cout<<OP2<<" "<<(term3 * (term3 / term2))<<"\n";	
	}
	return 0;
}