#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>


#define w(t)						while(t--)
#define s(n)                        scanf("%d", &n)
#define emptyLine					printf("\n")
#define f(i, n)						for(int i = 0; i < n; i++)

#define pb(n)						push_back(n)
#define mp(x, y)					make_pair(x, y)

using namespace std;

typedef pair<int, int> 				ii;
typedef vector<ii>					vii;
typedef vector<int>					vi;
typedef long long 					ll;
typedef long int 					li;

int main(){
	freopen( "aux/input.in", "r", stdin );
	freopen( "aux/output.out", "w", stdout );
	int test;
	s(test);
	w(test) {
		int people;
		int trans;
		scanf("%d%d", &people, &trans);
		unordered_map<string, int> details;
		vector<string> detailsVector;
		f(i, people) {
			string name;
			cin>>name;
			details[name] = 0;
			detailsVector.pb(name);
		}
		f(i, trans) {
			string paidBy;
			cin>>paidBy;
			int amtPaid;
			s(amtPaid);
			int others;
			s(others);
			details[paidBy] += amtPaid;
			int split = amtPaid / (others + 1);
			details[paidBy] -= ((split) + (amtPaid % (others + 1)));
			f(j, others) {
				string oPeople;
				cin>>oPeople;
				details[oPeople] -= split;
			}
		}
		for(auto &val: detailsVector) {
			if(details[val] < 0)
				cout<<val<<" owes "<<(-1) * details[val];
			else if(details[val] > 0)
				cout<<val<<" is owed "<<details[val];
			else
				cout<<val<<" neither owes nor is owed";
			emptyLine;
		}
	}
	return 0;
}