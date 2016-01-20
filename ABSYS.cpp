#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <cmath>
#include <map>
#include <string>

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
#define sl(n)                       scanf("%ld",&n)
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
	int test;
	s(test);
	string dummy;
	getline(cin, dummy);
	getline(cin, dummy);
	w(test) {
		string exp;
		getline(cin, exp);
		getline(cin, dummy);
		int pos_eq = exp.find('=');
		int pos_plus = exp.find('+');
		string rhs = exp.substr(pos_eq + 2);
		string lhs1  = exp.substr(0, pos_plus - 1);
		string lhs2 = exp.substr(pos_plus + 2, pos_eq - pos_plus - 3);
		if(rhs.find("machula") != string::npos){
			rhs.clear();
			rhs = to_string(stoi(lhs1) + stoi(lhs2));
		}
		else{
			if(lhs1.find("machula") != string::npos) {
				lhs1 = to_string(stoi(rhs) - stoi(lhs2));
			}
			else{
				lhs2 = to_string(stoi(rhs) - stoi(lhs1));	
			}
		}
		cout<<lhs1<<" + "<<lhs2<<" = "<<rhs<<"\n";
	}
	return 0;
}