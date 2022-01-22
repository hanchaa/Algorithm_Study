#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define N 1520
#define MOD 1000000007

int main() {
	int dp[N][3] = { 0 }, n;
	dp[2][0] = 1;
	dp[2][1] = 1;

	scanf("%d", &n);

	for (int i = 2; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			dp[i + 1][(j + 1) % 3] += dp[i][j];
			dp[i + 1][(j + 5) % 3] += dp[i][j];
		}

		dp[i + 1][0] %= MOD;
		dp[i + 1][1] %= MOD;
		dp[i + 1][2] %= MOD;
	}

	printf("%d", dp[n][0]);

	return 0;
}