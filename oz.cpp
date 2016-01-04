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
	int tests;
	s(tests);
	w(tests){
		int N;
		s(N);
		int nums[N];
		f(i, N)
			s(nums[i]);
		sort(nums + 0, nums + N);
		int M = N-1;
		int diff_nums[M];
		map<int, vector<int> > my_map;
		for(int i = 1; i < N; i++)
			diff_nums[i - 1] = (nums[i] - nums[i - 1]);
		int sum = 0;
		f(i, M)
			sum += diff_nums[i];
		if(sum == M){
			if(M % 2 == 0)
				co(M / 2);
			else
				co(M / 2 + 1);
		}
		else{
			vector<int> temp;
			temp.pb(diff_nums[0]);
			temp.pb(-1);
			my_map[nums[0]] = temp;
			temp.clear();
			temp.pb(diff_nums[M - 1]);
			temp.pb(-2);
			my_map[nums[N - 1]] = temp;
			//cco(temp[0], temp[1]);
			for(int i = 1; i < M; i++){
				vector<int> temp;
				temp.pb(diff_nums[i -1]);
				temp.pb(diff_nums[i]);
				if(temp[0] != 1 && temp[1] != 1)
					continue;
				my_map[nums[i]] = temp;
			}
			map<int, vector<int> >::iterator itr;
			map<int, vector<int> >::iterator itr2;
			for(itr = my_map.begin(); itr != my_map.end(); itr++)
				cco(itr->first, itr->second[0]);
			int count = 0;
			int ele = 0;
			count += N - my_map.size();
			if((N - count) %  2 == 0)
				count += (N - count) / 2;
			else
				count += (N - count) / 2 + 1;
			co(count);
		}
	}
	return 0;
}