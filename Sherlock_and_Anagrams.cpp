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
	int tests;
	s(tests);
	string word;
	mp_wf my_map;
	int len;
	int count;
	string temp("");
	w(tests){
		c(word);
		my_map.clear();
		count = 0;
		len = l(word);
		f(i, len){
			for(int j = 1; i + j - 1 < len; j++){
				temp = word.substr(i, j);
				sort(temp.begin(), temp.end());
				if(my_map.count(temp) > 0)
					my_map[temp]++;
				else
					my_map[temp] = 1;
			}
		}
		for(mp_wf::iterator itr = my_map.begin(); itr != my_map.end(); itr++){
			if(itr->second > 1){
				count += (itr->second) * (itr->second - 1) / 2;
			}
		}
		co(count);
	}
	return 0;
}