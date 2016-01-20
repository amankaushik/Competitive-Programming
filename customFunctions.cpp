int getLCSLen(string A, string B, int lenA, int lenB) {
	int len;
	if(lenA == 0 || lenB == 0)
		return 0;
	if(A[lenA - 1] == B[lenB - 1])
		len = 1 + getLCSLen(A, B, lenA - 1, lenB - 1);
	else
		len = (maX(getLCSLen(A, B, lenA - 1, lenB), getLCSLen(A, B, lenA, lenB - 1)));
	return len;
}

int getLCSLenDP(string &A, string &B, int lenA, int lenB) {
	int dp[lenA + 1][lenB + 1];
	for(int i = 0; i <= lenA; i++) {
		for(int j = 0; j <= lenB; j++) {
			if(i == 0 || j == 0)
				dp[i][j] = 0;
			else if(A[i - 1] == B[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = maX(dp[i][j - 1], dp[i - 1][j]);
		}
	}
	return dp[lenA][lenB];
}