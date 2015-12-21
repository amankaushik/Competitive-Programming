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
#define sfi(n) 						scanf("%d", &n)
#define pfi(n)						printf("%d", n)
#define pfl(n)						printf("%ld", n)
#define cg(n)						getline(cin, n)
#define cco(n, m)					cout<<n<<" : "<<m<<"\n";					
#define co(n)						cout<<n<<"\n"
#define sfs(n)                      scanf("%s",n)
#define sfl(n)                      scanf("%lld",&n)
#define sff(n)                      scanf("%lf",&n)

#define pb(n)						push_back(n)

#define vi							vector<int>
#define si							stack<int>
#define mp 							map<int, int>
#define mp_cf						map<char, int> // char frequency map
#define mp_wf						map<string , int> // word frequency map
#define l(n)						n.length()
#define f(i, n)						for(int i = 0; i < n; i++)

using namespace std;

long get_contiguous_sum(int *arr, int size) {
	long curr_sum = arr[0], max_sum = arr[0];
	for(int i = 1; i < size; i++) {
		curr_sum = maX(arr[i], curr_sum + arr[i]);
		max_sum = maX(max_sum, curr_sum);
	}
    return max_sum;
}

long get_n_contiguous_sum(int *arr, int size) {
	long max_sum;
	max_sum = arr[0];
	for(int i = 1; i < size; i++) {
		if(arr[i] >= 0)
			max_sum += arr[i];
		else {
			if(arr[i] > max_sum)
				max_sum = arr[i];
		}
	}
	return max_sum;	
}

int main() {
    int test;
	sfi(test);
	w(test){
		int size;
		sfi(size);
		int arr[size];
		f(i, size) 
			sfi(arr[i]);
		pfi(get_contiguous_sum(arr, size));
        printf(" ");
		pfi(get_n_contiguous_sum(arr, size));
        printf("\n");
	}
	return 0;
}


