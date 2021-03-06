#include <bits/stdc++.h>

#define gcd                         __gcd
#define rbit                        __builtin_ffs // returns 1 + index of least significant 1-bit of x
#define lzero                       __builtin_clz // returns number of leading 0-bits of x
#define tzero                       __builtin_ctz // returns number of trailing 0-bits of x
#define on_bits                     __builtin_popcount //returns number of 1-bits of x
#define s(n)                        scanf("%d",&n)
#define p(n)                        printf("%d",n)
#define sc(n)                       scanf("%c",&n)
#define maX(a,b)                    ( (a) > (b) ? (a) : (b))
#define miN(a,b)                    ( (a) < (b) ? (a) : (b))

#define w(t)                        while(t--)
#define c(n)                        cin>>n
#define cg(n)                       getline(cin, n)
#define cco(n, m)                   cout<<n<<" : "<<m<<"\n";                    
#define co(n)                       cout<<n<<"\n"
#define ss(n)                       scanf("%s",n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)

#define pb(n)                       push_back(n)

#define vi                          vector<int>
#define si                          stack<int>
#define mp                          map<int, int>
#define mp_cf                       map<char, int> // char frequency map
#define mp_wf                       map<string , int> // word frequency map
#define l(n)                        n.length()
#define f(n)                        for(int i = 0; i < n; i++)
#define sfi(n)                      scanf("%d", &n)
#define pfi(n)                      printf("%d", n)
#define pfl(n)                      printf("%ld", n)

using namespace std;

int main(){
    freopen("tc.in","r",stdin);
    freopen("tcop.out","w",stdout);
    int K, N;
    scanf("%d%d", &K, &N);
    vector<int> radius;
    f(K) {
        int temp;
        sfi(temp);
        radius.push_back(temp);
    }
    reverse(radius.begin(),radius.end());
    pair<int, int> *cord = new pair<int, int> [N];
    f(N)
        scanf("%d%d", &cord[i].first, &cord[i].second);
    int score = 0;
    f(N) {
        double d = sqrt( ((double)cord[i].first * (double)cord[i].first) + ((double)cord[i].second * (double)cord[i].second) );
        vector<int>::iterator low = lower_bound(radius.begin(), radius.end(), d);
        if(low != radius.end())
            score += (K - (low - radius.begin()));
    }
    printf("%d\n", score);
    return 0;
}