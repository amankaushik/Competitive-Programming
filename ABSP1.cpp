#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	freopen( "aux/input.in", "r", stdin );
	freopen( "aux/output.out", "w", stdout );
	int test;
	scanf("%d", &test);
	while(test--) {
		int N;
		scanf("%d", &N);
		long int arr[N];
		for(int i = 0; i < N; i++)
			scanf("%ld", &arr[i]);
		long long sum = 0;
		long long prev = 0;
		for(int i = N - 2; i >= 0; i--) {
			prev = prev + (arr[i + 1] - arr[i]) * (N - i - 1);
			sum += (prev);
		}
		printf("%lld\n", sum);
	}
	return 0;
}