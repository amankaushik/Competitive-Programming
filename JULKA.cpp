#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <cmath>
#include <map>

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
#define sl(n)                       scanf("%lld",&n)
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

const int N = 101;

void subtract(string &totalApples, string moreKlaudia) {
	int lenTotal = totalApples.length();
	int lenKlaudia = moreKlaudia.length();
	int subRange = lenKlaudia;
	int i = lenTotal - 1;
	int j = lenKlaudia - 1;
	while(subRange--) {
		int m, n;
		n = moreKlaudia[j] - '0';
		if(totalApples[i] == '*') {
			totalApples[i] = 10 - 1 - n + '0';
			int carry = totalApples[i - 1] - '0';
			if(carry > 0)
				totalApples[i - 1] = carry - 1 + '0'; 
			else
				totalApples[i - 1] = '*';
		}
		else {
			m = totalApples[i] - '0';
			if(m >= n)
				totalApples[i] = m - n + '0';
			else {
				totalApples[i] = 10 + m - n + '0';
				int carry = totalApples[i - 1] - '0';
				if(carry > 0){
					totalApples[i - 1] = carry - 1 + '0'; 
				}
				else
					totalApples[i - 1] = '*';
			}
		}
		i--;
		j--;
	}
	//cout<<"sub1: "<<totalApples<<"\n";
	for(int k = i; k >=0; k--) {
		if(totalApples[k] == '*') {
			totalApples[k] = 9 + '0';
			if(totalApples[k - 1] - '0' > 0){
				int temp = totalApples[k - 1] - '0';
				totalApples[k - 1] = temp - 1 + '0';
			}
			else
				totalApples[k - 1] = '*';
		}
	}
	//cout<<"sub2: "<<totalApples<<"\n";
	int count = 0;
	for(int i = 0; i < lenTotal; i++) {
		int m = totalApples[i] - '0'; 
		if(m >= 1 && m <= 9)
			break;
		count++;
	}
	//cout<<"count: "<<count<<"\n";
	if(count)
		totalApples.erase(0, count);
}

void divideBy2(string &totalApples) {
	int lenTotal = totalApples.length();
	int m, carry = 0;
	for(int i = 0; i < lenTotal; i++) {
		m = totalApples[i] - '0'; 
		/*
		if(m == 0 && carry != 0) {
			m = carry * 10;
			totalApples[i] = (m / 2) + '0';
		}
		*/
		if(m == 1){
				m = (10 * m) + (totalApples[i + 1] - '0');
				totalApples[i] = '0';
				totalApples[i + 1] = (m / 2) + '0';
				i++;
			}
		else {
			m += carry * 10;
			totalApples[i] = (m / 2) + '0';
		}
		carry = m % 2;
	}
	int count = 0;
	for(int i = 0; i < lenTotal; i++) {
		int m = totalApples[i] - '0'; 
		if(m >= 1 && m <= 9)
			break;
		count++;
	}
	if(count)
		totalApples.erase(0, count);
}

int main(){
	freopen( "input.in", "r", stdin );
	freopen( "output.out", "w", stdout );
	int test = 7;
	w(test) {
		string totalApples;
		cin>>totalApples;
		
		string moreKlaudia;
		cin>>moreKlaudia;
		
		string total(totalApples);
		subtract(totalApples, moreKlaudia);
		//cout<<"1: "<<totalApples<<"\n";
		divideBy2(totalApples);
		//cout<<"2: "<<totalApples<<"\n";
		string applesNat(totalApples);
		subtract(total, applesNat);
		//cout<<"3: "<<total<<"\n";
		string applesKla(total);
		if(moreKlaudia.compare("0") == 0 && totalApples.compare("0") != 0){
			if(!applesNat.empty())
				cout<<applesNat<<"\n";
			else
				cout<<"0\n";
			if(!applesKla.empty())
				cout<<applesKla<<"\n";
			else
				cout<<"0\n";
		}
		else{
			if(!applesKla.empty())
				cout<<applesKla<<"\n";
			else
				cout<<"0\n";
			if(!applesNat.empty())
				cout<<applesNat<<"\n";
			else
				cout<<"0\n";	
		}
	}
	return 0;
}