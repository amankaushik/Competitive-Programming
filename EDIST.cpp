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
#include <cstring>

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

int dp[2101][2101];
char A[2101];
char B[2101];
int getEditDisLen(char *A, char *B, int lenA, int lenB) {
	for(int i = 0; i <= lenA; i++) {
		for(int j = 0; j <= lenB; j++) {
			if(i == 0)
				dp[i][j] = j;
			else if(j == 0)
				dp[i][j] = i;
			else if(A[i - 1] == B[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = 1 + miN(miN(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]);
		}
	}
	return dp[lenA][lenB];
}

int main(){
	freopen( "aux/input.in", "r", stdin );
	freopen( "aux/output.out", "w", stdout );
	int test;
	s(test);
	w(test) {
		scanf("%s", A);
		scanf("%s", B);
		int lenA = strlen(A);
		int lenB = strlen(B);
		
		if (lenA > 0 && A[lenA - 1] == '\n')
  			A[lenA - 1] = '\0';
		if (lenB > 0 && B[lenB - 1] == '\n')
  			B[lenB - 1] = '\0';
  		p(getEditDisLen(A, B, lenA, lenB));
		emptyLine;
	}
	return 0;
}