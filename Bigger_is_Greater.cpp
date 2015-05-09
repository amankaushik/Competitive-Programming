#include <bits/stdc++.h>

#define pb 							push_back
#define gcd 						__gcd
#define rbit						__builtin_ffs // returns 1 + index of least significant 1-bit of x
#define lzero 						__builtin_clz // returns number of leading 0-bits of x
#define tzero   					__builtin_ctz // returns number of trailing 0-bits of x
#define	on_bits						__builtin_popcount //returns number of 1-bits of x
#define s(n)                        scanf("%d",&n)
#define p(n)						printf("%d",n)
#define sc(n)                       scanf("%c",&n)
#define maX(a,b)                    ( (a) > (b) ? (a) : (b))
#define miN(a,b)                    ( (a) < (b) ? (a) : (b))

#define w(t)						while(t--)
#define c(n)						cin>>n
#define co(n)						cout<<n<<"\n"
#define ss(n)                       scanf("%s",n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)

#define vi							vector<int>
#define si							stack<int>
#define mp 							map<int, int>

using namespace std;

int main(){
	int test;
	s(test);
	string word;
	string default_ans = "no answer";
	bool flag = false;
	w(test){
		c(word);
		flag = next_permutation(word.begin(), word.end());
		if(flag)
			co(word);
		else
			co(default_ans);
	}
	return 0;
}