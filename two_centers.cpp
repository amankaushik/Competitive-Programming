#include <bits/stdc++.h>
#include <unordered_map>

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
#define ump							unordered_map<int, int>
#define mp_cf						map<char, int> // char frequency map
#define mp_wf						map<string , int> // word frequency map
#define l(n)						n.length()
#define f(n)						for(int i = 0; i < n; i++)
#define sfi(n) 						scanf("%d", &n)
#define pfi(n)						printf("%d", n)
#define pfl(n)						printf("%ld", n)

#define pii                         pair<int, int> 
#define sfp(conn,i)					scanf("%d%d", &conn[i].first, &conn[i].second)		

using namespace std;

int main(){
	freopen("tc.in","r",stdin);
	freopen("tcop.out","w",stdout);
	int nodes;
	sfi(nodes);
	pii *conn = new pii [nodes - 1];
	ump degree;
	f(nodes - 1) 
		sfp(conn,i);
	f(nodes - 1) {
		auto found = degree.find(conn[i].first);
		if(found != degree.end())
			degree[conn[i].first]++;
		else
			degree.insert(make_pair(conn[i].first, 1));
		found = degree.find(conn[i].second);
		if(found != degree.end())
			degree[conn[i].second]++;
		else
			degree.insert(make_pair(conn[i].second, 1));
	}
	pii degree_1, degree_2;
	degree_1.second = INT_MIN, degree_2.second = INT_MIN;
	for(auto ele : degree) {
		if(ele.second > degree_1.second) {
			degree_2.second = degree_1.second;
			degree_2.first = degree_1.first;
			degree_1.second = ele.second;
			degree_1.first = ele.first;
		} 
		else if(ele.second > degree_2.second) {
			degree_2.second = ele.second;
			degree_2.first = ele.first;
		}
	}
	//cout<<degree_1.first<<" "<<degree_1.second<<"\n";
	//cout<<degree_2.first<<" "<<degree_2.second<<"\n";
	if(degree_1.second != degree_2.second) {
		cout<<degree_1.first
	}
	else {

	}

	/*
	f(nodes - 1) 
		printf("%d %d\n", conn[i].first, conn[i].second);
	*/
	return 0;
}