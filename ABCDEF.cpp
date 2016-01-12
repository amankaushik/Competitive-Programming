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

void printMap(unordered_map<int, int> &valMap) {
	for(auto &kv: valMap)
		cout<<kv.first<<" -> "<<kv.second<<"\n";
}
int main(){
	freopen( "aux/input.in", "r", stdin );
	freopen( "aux/output.out", "w", stdout );
	int N;
	s(N);
	int elements[N];
	unordered_map<int ,int> eleMap;

	f(i, N)
		s(elements[i]);
	f(i, N) {
		eleMap[elements[i]] = elements[i];
	}
	sort(elements + 0, elements + N);
	unordered_map<int ,int> valMap;
	
	f(i, N) {
		f(j, N) {
			f(k, N) {
				int val = (elements[i] * elements[j]) + elements[k];
				if(valMap[val])
					valMap[val]++;
				else
					valMap[val] = 1;
			}
		}
	}
	int RHS {0};
	int count {0};
	for(auto &kv: valMap) {
		int subCount = 0;
		f(i, N) {
			if(elements[i]) {
				f(j, N) {
					if(kv.first % elements[i] == 0){
						if(eleMap.find(kv.first / elements[i] - elements[j]) != eleMap.end())
							subCount++;
					}
				}	
			}
		}
		count += subCount * kv.second;
	}
	printf("%d\n", count);
	return 0;
}