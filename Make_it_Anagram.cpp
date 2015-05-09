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
	string word_1;
	string word_2;
	int alphabets[26];
	c(word_1);
    c(word_2);
    fill(alphabets + 0, alphabets + 26, 0);
	int len_1 = l(word_1);
	int len_2 = l(word_2);
	auto count = 0;
	f(i, len_1)
		alphabets[word_1[i] - 'a']++;
	f(i, len_2)	
		alphabets[word_2[i] - 'a']--;
	f(i, 26)
		count += abs(alphabets[i]);
	co(count);	
	return 0;
}