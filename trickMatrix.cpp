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

bool isPerfectCube(long long n) {
    long long checkRoot = (long long)round(cbrt((long double) n));
    return n == checkRoot * checkRoot * checkRoot;
}

int calcCubeMat(long long **grid, int N, int sK) {
	int size = N + 1;
	long long dp[N][N];
	f(i, N){
		f(j, N){
			if(!i)
				dp[i][j] = grid[i][j];
			else
				dp[i][j] = grid[i][j] + dp[i - 1][j];
		}
	}
	long long cubeSum = 0;
	int  count = 0;
	for(int i = 0; i < N; i++) {
		for(int j = i; j < N; j++) {
			if(i > 0)
				cubeSum = dp[j][0] - dp[i - 1][0];	
			else
				cubeSum = dp[j][0];
			int k = 1;
			for(k = 1; k < N; k++)
				if(i > 0)
					cubeSum += dp[j][k] - dp[i - 1][0];
				else
					cubeSum += dp[j][k];
			if(isPerfectCube(cubeSum)) {
				if(i - j == sK - 1)
					count++;
			}
			cubeSum = 0;
		}
	}
	return count;
}

int main(){
	freopen( "aux/input.in", "r", stdin );
	freopen( "aux/output.out", "w", stdout );
	int N, K;
	s(N);
	s(K);
	long long **grid;
	grid = new long long *[N];
	f(i, N)
		grid[i] = new long long[N];
	f(i, N){
		f(j, N)
			scanf("%lld", &grid[i][j]);
	}
	p(calcCubeMat(grid, N, K));
	return 0;
}