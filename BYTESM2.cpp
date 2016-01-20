#include <iostream>
#include <cstdio>
#include <climits>

#define maX(a,b)                    ( (a) > (b) ? (a) : (b))
#define miN(a,b)                    ( (a) < (b) ? (a) : (b))

#define w(t)						while(t--)
#define s(n) 						scanf("%d", &n)
#define p(n)						printf("%d",n)
#define emptyLine					printf("\n")
#define f(i, n)						for(int i = 0; i < n; i++)

using namespace std;

int main(){
	freopen( "aux/input.in", "r", stdin );
	freopen( "aux/output.out", "w", stdout );
	int test;
	s(test);
	w(test) {
		int rows;
		int cols;
		s(rows);
		s(cols);
		int tiles[rows][cols];
		f(i, rows) {
			f(j, cols)
				s(tiles[i][j]);
		}
		int dp[rows][cols];
		for(int j = 0; j < cols; j++)
			dp[0][j] = tiles[0][j];
		for(int i = 1; i < rows; i++) {
			int sum = 0;
			for(int j = 0; j < cols; j++) {
				dp[i][j] = tiles[i][j];
				if(j == 0)
					dp[i][j] += maX(dp[i - 1][j], dp[i - 1][j + 1]);	
				else if(j == cols - 1)
					dp[i][j] += maX(dp[i - 1][j], dp[i - 1][j - 1]);
				else 
					dp[i][j] += maX(maX(dp[i - 1][j], dp[i - 1][j + 1]), dp[i - 1][j - 1]);
			}
		}
		int max = INT_MIN;
		for(int j = 0; j < cols; j++) {
			if(max < dp[rows - 1][j])
				max = dp[rows - 1][j];	
		}
		p(max);
		emptyLine;
	}
	return 0;
}