#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <cmath>

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
#define f(n)						for(int i = 0; i < n; i++)
#define sfi(n) 						scanf("%d", &n)
#define pfi(n)						printf("%d", n)
#define pfl(n)						printf("%ld", n)

#define pii                         pair<int, int> 
#define sfp(conn,i)					scanf("%d%d", &conn[i].first, &conn[i].second)	

#define ops_1 "left pan: "
#define ops_2 "right pan: "

using namespace std;

int main(){
	freopen("tc.in","r",stdin);
	freopen("tcop.out","w",stdout);
	int tests;
	sfi(tests);
	w(tests) {
		int wt;
		sfi(wt);
		vector< pair<long int, long int> > weights;
		long int sum = 0;
		int i = 0;
		while(sum < (long int)wt) {
			auto temp = (long int)pow((double)3, i);
			sum += temp;
			weights.pb(make_pair(temp, sum));
			i++;
		}
		int len = weights.size();
		if(weights[len - 1].first == (long)wt)
			printf(ops_1 "\n" ops_2 "%ld\n\n", weights[len - 1].first);
		else {
			long int right_total = 0;
			long int left_total = wt;
			string right;
			string left;
			int diff = right_total - left_total;
			for(int i = len - 1; i >= 0; i--) {
				if(diff == 0)
					break;
				else if(diff > 0) {
					left_total += weights[i].first;
					left.append(to_string(weights[i].first));
					left.append(" ");
					diff = right_total - left_total;
				}
				else if(diff < 0 && abs(diff) >= weights[i].second){
					if(abs(diff) > weights[i].second)
						i++;	
					right_total += weights[i].first;
					right.append(to_string(weights[i].first));
					right.append(" ");
					diff = right_total - left_total;
				}
			}
			cout<<ops_1<<left<<"\n";
			cout<<ops_2<<right<<"\n\n";		
		}
	}
	return 0;
}