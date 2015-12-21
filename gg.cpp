#include <bits/stdc++.h>
#include <d_map>

#define GREATER 'G'
#define LESS 	'L'
#define f(n)						for(int i = 0; i < n; i++)

using namespace std;

long int getNumAscents(int N, int M) {
	unordered_map <pair<int, int>, int> myMap;
	myMap[make_pair(0, 0)] = 1;
	for(int i = 1; i <= N; i++)
		myMap[make_pair(i, 0)] = 1;
	for(int i = 1; i <= N; i ++) {
		for(int j = 0; j < i; j++) {
			if(myMap.find(make_pair(i, j)) != myMap.end()) {
				myMap[make_pair(i, j)] = (i - j) * myMap[make_pair(i - 1, j - 1)] +
										(j + 1) * myMap[make_pair(i - 1, j)];
			}
		}
	}
}

int main(){
    freopen( "input.in", "r", stdin );
	freopen( "output.out", "w", stdout );
    int N, M;
	long int count = 0;
	scanf("%d%d", &N, &M);
	string S;
	cin>>S;
	int nums[N];
	f(N) 
		nums[i] = i;
	
	int g_count = 0;
	for(auto s: S) {
		if(s == GREATER)
			g_count++;
	}
	long int ascents = getNumAscents(N, g_count);
	do {
		int flag = 0;
		for(int i = 0; i < N - 1; i++) {
			if( !( ((S[i] == GREATER) && (nums[i] > nums[i + 1])) || ((S[i] == LESS) && (nums[i] < nums[i + 1])) ) ) { 
				flag = -1;
				break;
			}
		}
		if(flag == 0)
			count++;
	}while(next_permutation(nums, nums + N));
	printf("%ld", count % (long int)M);
	return 0;
}