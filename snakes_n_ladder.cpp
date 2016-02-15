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
#include <queue>
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

#define V 101
#define DICE 6

int main() {
	int test;
	s(test);
	w(test) {
		int L, S;
		s(L);
		vector<vii > edges(V);
		ii edge;
		f(i, L) {
			scanf("%d%d", &edge.first, &edge.second);
			edges[edge.first].pb(mp(0, edge.second));
		}
		s(S);
		f(i, S) {
			scanf("%d%d", &edge.first, &edge.second);
			edges[edge.first].pb(mp(0, edge.second));
		}
		for(int v = 1; v < V; v++) {
			for(int i = 1; i <= DICE; i++) {
				if(i + v >= V)
					break;
				else
					edges[v].pb(mp(1, v + i));
			}
		}
		priority_queue<ii, vii, greater<ii > > Q;
		vi distTo(V, INT_MAX), edgeTo(V, -1);
		Q.push(mp(0, 1));
		distTo[1] = 0;
		while(!Q.empty()) {
			ii p = Q.top();
			if(p.second == 100)
				break;
			Q.pop();
			int here = p.second;
			for(vii::iterator it = edges[here].begin(); it != edges[here].end(); it++) {
				if(distTo[here] + it->first < distTo[it->second]) {
					distTo[it->second] = distTo[here] + it->first;
					edgeTo[it->second] = here;
					Q.push(mp(distTo[it->second], it->second));
				}
			}
		}
		p(distTo[100]);
		emptyLine;
	}
	return 0;
}

#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
 
const int INF = 2000000000;
typedef pair<int,int> PII;
 
#define V 101
#define min(x, y) (x<y?x:y)
#define max(x, y) (x>y?x:y)
 
int main(){
    int T, L, S;
    scanf("%d", &T);
     
    for(int t = 0; t<T; t++){ 
        priority_queue<PII, vector<PII>, greater<PII> > Q;
        vector<int> distTo(V, INF), edgeTo(V, -1);
        // Source Vertex Entry
        Q.push(make_pair (0, 1));
        distTo[1] = 0;
        while(!Q.empty()){
            PII p = Q.top();
            // Sink Vertex Check
            if (p.second == 100) break;
            Q.pop();
            int here = p.second;
            for (vector<PII>::iterator it=edges[here].begin(); 
                    it!=edges[here].end(); it++){
                if (distTo[here] + it->first < distTo[it->second]){
                    distTo[it->second] = distTo[here] + it->first;
                    edgeTo[it->second] = here;
                    Q.push (make_pair (distTo[it->second], it->second));
                }
            }
        }
        printf("%d\n", distTo[100]);
    }
 
    return 0;
}