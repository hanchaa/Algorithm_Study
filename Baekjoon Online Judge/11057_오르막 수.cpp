#include <stdio.h>

int main() {
	int dp[1005][15] = { 0 }, n, sum = 0;

	scanf("%d", &n);

	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= 10007;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		sum += dp[n][i];
		sum %= 10007;
	}

	printf("%d\n", sum);

	return 0;
}