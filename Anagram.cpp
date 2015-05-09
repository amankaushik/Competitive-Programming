#include <bits/stdc++.h>

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
#define cg(n)						getline(cin, n)
#define cco(n, m)					cout<<n<<" : "<<m<<"\n";					
#define co(n)						cout<<n<<"\n"
#define ss(n)                       scanf("%s",n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)

#define pb(n)						push_back(n)

#define vi							vector<int>
#define si							stack<int>
#define mp 							map<int, int>
#define mp_cf						map<char, int> // char frequency map
#define mp_wf						map<string , int> // word frequency map
#define l(n)						n.length()
#define f(i, n)						for(int i = 0; i < n; i++)

using namespace std;

int main(){
	auto tests = 0;
	s(tests);
	string word;
	int alphabets[26];
	w(tests){
		c(word);
        fill(alphabets + 0, alphabets + 26, 0);
		int len = l(word);
		auto count = 0;
		if(len % 2 != 0)
			co("-1");
		else{
            auto n = len / 2;
			f(i, n)
				alphabets[word[i] - 'a']++;
			for(int i = len/2; i < len; i++)
				alphabets[word[i] - 'a']--;
			f(i, 26){
				if(alphabets[i] < 0)
					count += alphabets[i];
			}
			co(count * -1);
		}
	}
	return 0;
}